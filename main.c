/* 
 * File:   main.c
 * Author: main
 *
 * Created on 7. September 2018, 00:49
 */

// DSPIC33EP512MC202 Configuration Bit Settings
// FICD
#pragma config ICS = PGD1               // ICD Communication Channel Select bits (Communicate on PGEC1 and PGED1)
#pragma config JTAGEN = OFF             // JTAG Enable bit (JTAG is disabled)

// FPOR
#pragma config ALTI2C1 = OFF            // Alternate I2C1 pins (I2C1 mapped to SDA1/SCL1 pins)
#pragma config ALTI2C2 = ON             // Alternate I2C2 pins (I2C2 mapped to ASDA2/ASCL2 pins)
#pragma config WDTWIN = WIN25           // Watchdog Window Select bits (WDT Window is 25% of WDT period)

// FWDT
#pragma config WDTPOST = PS32768        // Watchdog Timer Postscaler bits (1:32,768)
#pragma config WDTPRE = PR128           // Watchdog Timer Prescaler bit (1:128)
#pragma config PLLKEN = ON              // PLL Lock Enable bit (Clock switch to PLL source will wait until the PLL lock signal is valid.)
#pragma config WINDIS = OFF             // Watchdog Timer Window Enable bit (Watchdog Timer in Non-Window mode)
#pragma config FWDTEN = OFF             // Watchdog Timer Enable bit (Watchdog timer always enabled)

// FOSC
#pragma config POSCMD = EC              // Primary Oscillator Mode Select bits (EC (External Clock) Mode)
#pragma config OSCIOFNC = ON            // OSC2 Pin Function bit (OSC2 is general purpose digital I/O pin)
#pragma config IOL1WAY = OFF            // Peripheral pin select configuration (Allow multiple reconfigurations)
#pragma config FCKSM = CSECMD           // Clock Switching Mode bits (Clock switching is enabled,Fail-safe Clock Monitor is disabled)

// FOSCSEL
#pragma config FNOSC = FRCDIVN          // Oscillator Source Selection (Internal Fast RC (FRC) Oscillator with postscaler)
#pragma config PWMLOCK = ON             // PWM Lock Enable bit (Certain PWM registers may only be written after key sequence)
#pragma config IESO = ON                // Two-speed Oscillator Start-up Enable bit (Start up device with FRC, then switch to user-selected oscillator source)

// FGS
#pragma config GWRP = OFF               // General Segment Write-Protect bit (General Segment may be written)
#pragma config GCP = OFF                // General Segment Code-Protect bit (General Segment Code protect is Disabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <p33EP512MC202.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "init.h"
#include "sine.h"
#include "timer_x.h"
#include "delay.h"
#include "i2c_x.h"
#include "i2c_eep.h"
#include "i2c_misc.h"
#include "SSD1306/lcd.h"
#include "spi_x.h"
#include "qei_x.h"
#include "fft.h"
#include "window.h"
#include "buffer.h"
#include "display.h"

static volatile uint32_t mix_display_timer = 0;
static volatile uint32_t menu_timer = 0;
static volatile uint32_t fft_max_timer = 0;

//working tasks timer interrupt, save psv and working registers
void __attribute__((__interrupt__, auto_psv, shadow)) _T3Interrupt(void) {
    if (menu_timer) menu_timer--;
    if (mix_display_timer) mix_display_timer--;
    if (fft_max_timer) fft_max_timer--;
    _T3IF = 0;
}


uint16_t frequency_marker(uint32_t frequency, bool mono) {
    if (mono) {
        return (uint16_t)((float)frequency / ((INPUT_SAMPLERATE_MONO / 2.0) / 128.0) + 0.5);
    }
    else {
        return (uint16_t)((float)frequency / ((INPUT_SAMPLERATE / 2.0) / 128.0) + 0.5);
    }
}


int main(int argc, char** argv) {
    //start system clocks
    osc_init();
    //start timers before any other peripherals
    timer1_init();
    timer2_init();
    //set RB9 I2C analog off as output
    TRISBbits.TRISB9 = 0;
    //start I2C to output debug info to display
    I2C2_init();
    //mute before SPI init
    MAX5387_set_volume(I2C_ADDR_MAX5387, 0);
    lcd_init();
    fb_clear();
    fb_show();
    //initialize rotary encoder
    QEI_init();

    //init fft
    setup_window_fn_buffer(window_fn_buffer, blackman_harris_window);
    fft_init();
    ifft_init();

    //init sine DDS
    sine_lookup_table_init();

    //start AD/DA converter and read/send data continuously
    SPI1_init();
    SPI2_init();
    //start timer for working tasks (check buffers and process data)
    timer3_init();

/*
    uint16_t num_read;
    static uint8_t i2c_buffer[256];
    num_read = ee_read_bytes(I2C_ADDR_FM24CL04, 0, sizeof(i2c_buffer), i2c_buffer, true);
    num_read = ee_read_bytes(I2C_ADDR_FM24CL04, 256, sizeof(i2c_buffer), i2c_buffer, true);
    num_read = ee_write_bytes(I2C_ADDR_24LC256, 0, sizeof(i2c_buffer), i2c_buffer, false);
    num_read = ee_read_bytes(I2C_ADDR_24LC256, 0, sizeof(i2c_buffer), i2c_buffer, false);
*/

    static char lcd_string_buffer[128];
    static uint8_t status;
    static uint16_t i;
    static uint16_t ms_per_loop = 0;
    static int32_t qei_diff;
    static int32_t qei_last = 0;
    static int32_t volume = 64;
    static int32_t loop_count = 0;
    static uint8_t menu_state = 0;
    static uint8_t menu_state_max = 6;
    uint64_t last_running_time = running_time();
    static int8_t input_state = 0;
    static int8_t input_state_max = 4;
    const char * const inputs[] = { "LINE", "MIC", "MEMS", "GND" };
    const char * const inputs_short[] = { "line", "mic", "mems", "GND" };
    static int8_t window_state = 1;
#ifndef __DEBUG
    static int8_t window_state_max = 8;
#else
    static int8_t window_state_max = 2;
#endif
    const char * const windows[] = { "Bartlett", "Blackman-Harris", "Blackman", "Dirichlet", "Flat-Top", "Gauss", "Hamming", "Kaiser" };
    static int32_t mic_vol[2] = { 223, 223 };
    static int32_t mems_mic_vol[2] = { 223, 223 };
    static uint32_t fft_max_display = 0;
    //mixer frequency in kHz
    static int32_t mixer_frequency = 20000 / MIXER_FACTOR;
    phase_jump_mixer = calculate_phase_jump(mixer_frequency * MIXER_FACTOR, mono);
    uint16_t f_marker = frequency_marker(mixer_frequency * MIXER_FACTOR, mono);

    ADG715_switch_line_in(I2C_ADDR_ADG715);
    MAX5387_set_volume(I2C_ADDR_MAX5387, volume);
    AD5254_set_mic_vol(I2C_ADDR_AD5254, mic_vol);
    AD5254_set_mems_mic_vol(I2C_ADDR_AD5254, mems_mic_vol);

    //main loop manage menu
    while (1) {
        fb_draw_pixel(126, 63, ((status >> 3) & 1) ^ 1);
        fb_draw_pixel(127, 63, ((status >> 3) & 1));

        //reset menu after timout
        if (menu_timer == 0) menu_state = 0;

        if (qei_push_cnt) {
            menu_timer = 100000;
            menu_state += qei_push_cnt;
            qei_push_cnt = 0;
            menu_state %= menu_state_max;
        }
        qei_diff = qei_last - (int32_t)(((uint32_t)POS1CNTH<<16) + POS1CNTL);
        //process menu if qei_diff reaches next detent -> +2
        if (abs(qei_diff) > 1) {
            menu_timer = 100000;
            qei_last = (((uint32_t)POS1CNTH<<16) + POS1CNTL);
            //two steps per detent
            qei_diff /= 2;
            switch(menu_state) {
            case 0:
                //FIXME: add acceleration
                mixer_frequency -= qei_diff;
                if (mixer_frequency < 0) mixer_frequency = 0;
                if (mono) {
                    if (mixer_frequency * MIXER_FACTOR > INPUT_SAMPLERATE_MONO / 2) mixer_frequency = (INPUT_SAMPLERATE_MONO / 2) / MIXER_FACTOR;
                }
                else {
                    if (mixer_frequency * MIXER_FACTOR > INPUT_SAMPLERATE / 2) mixer_frequency = (INPUT_SAMPLERATE / 2) / MIXER_FACTOR;
                }
                phase_jump_mixer = calculate_phase_jump(mixer_frequency * MIXER_FACTOR, mono);
                f_marker = frequency_marker(mixer_frequency * MIXER_FACTOR, mono);
                mix_display_timer = 20000;
                break;
            case 1:
                //FIXME: add acceleration
                volume -= qei_diff;
                if (volume < 0) volume = 0;
                if (volume > 255) volume = 255;
                MAX5387_set_volume(I2C_ADDR_MAX5387, (uint8_t)volume);
                break;
            case 2:
                //choose input: 
                input_state -= qei_diff;
                while (input_state < 0) input_state += input_state_max;
                while (input_state >= input_state_max) input_state -= input_state_max;
                switch(input_state) {
                case 0:
                    ADG715_switch_line_in(I2C_ADDR_ADG715);
                    break;
                case 1:
                    ADG715_switch_mic_in(I2C_ADDR_ADG715);
                    break;
                case 2:
                    ADG715_switch_memsmic_in(I2C_ADDR_ADG715);
                    break;
                case 3:
                    ADG715_switch_gnd(I2C_ADDR_ADG715);
                    break;
                }
                break;
            case 3:
                for (i = 0; i < 2; i++) {
                    mic_vol[i] -= qei_diff;
                    if (mic_vol[i] < 0) mic_vol[i] = 0;
                    if (mic_vol[i] > 255) mic_vol[i] = 255;
                }
                AD5254_set_mic_vol(I2C_ADDR_AD5254, mic_vol);
                break;
            case 4:
                for (i = 0; i < 2; i++) {
                    mems_mic_vol[i] -= qei_diff;
                    if (mems_mic_vol[i] < 0) mems_mic_vol[i] = 0;
                    if (mems_mic_vol[i] > 255) mems_mic_vol[i] = 255;
                }
                AD5254_set_mems_mic_vol(I2C_ADDR_AD5254, mems_mic_vol);
                break;
            case 5:
                //choose fft window: 
                window_state -= qei_diff;
                while (window_state < 0) window_state += window_state_max;
                while (window_state >= window_state_max) window_state -= window_state_max;
                switch(window_state) {
                case 0:
                    setup_window_fn_buffer(window_fn_buffer, bartlett_window);
                    break;
                case 1:
                    setup_window_fn_buffer(window_fn_buffer, blackman_harris_window);
                    break;
//in debug build large const storage leads to debugger stop
#ifndef __DEBUG
                case 2:
                    setup_window_fn_buffer(window_fn_buffer, blackman_window);
                    break;
                case 3:
                    setup_window_fn_buffer(window_fn_buffer, dirichlet_window);
                    break;
                case 4:
                    setup_window_fn_buffer(window_fn_buffer, flat_top_window);
                    break;
                case 5:
                    setup_window_fn_buffer(window_fn_buffer, gauss_window);
                    break;
                case 6:
                    setup_window_fn_buffer(window_fn_buffer, hamming_window);
                    break;
                case 7:
                    setup_window_fn_buffer(window_fn_buffer, kaiser_window);
                    break;
#endif
                }
                break;
            }
        }

        if (++loop_count % 10 == 0) {
            ms_per_loop = (uint16_t)((running_time() - last_running_time) / 10);
            last_running_time = running_time();
        }

        if (fft_max_frequency > fft_max_display) {
            fft_max_display = fft_max_frequency;
            fft_max_timer = 20000;
        }
        else if (!fft_max_timer) {
            fft_max_display = fft_max_frequency;
        }

        fb_clear_line (0);
        fb_clear_line (1);
        switch(menu_state) {
        case 0:
            if (mix_display_timer) {
                snprintf(lcd_string_buffer, sizeof(lcd_string_buffer), "MIX:");
                fb_draw_string_big(0, 0, lcd_string_buffer);
                snprintf(lcd_string_buffer, sizeof(lcd_string_buffer), "%ld", mixer_frequency * MIXER_FACTOR);
                fb_draw_string_big(48, 0, lcd_string_buffer);
                snprintf(lcd_string_buffer, sizeof(lcd_string_buffer), "Hz");
                fb_draw_string(119, 1, lcd_string_buffer);
            } else {
                snprintf(lcd_string_buffer, sizeof(lcd_string_buffer), "MAX:");
                fb_draw_string_big(0, 0, lcd_string_buffer);
                snprintf(lcd_string_buffer, sizeof(lcd_string_buffer), "%ld", fft_max_display);
                fb_draw_string_big(48, 0, lcd_string_buffer);
                snprintf(lcd_string_buffer, sizeof(lcd_string_buffer), "Hz");
                fb_draw_string(119, 1, lcd_string_buffer);
            }
            break;
        case 1:
            snprintf(lcd_string_buffer, sizeof(lcd_string_buffer), "VOLUME: %ld", volume);
            fb_draw_string_big(0, 0, lcd_string_buffer);
            break;
        case 2:
            snprintf(lcd_string_buffer, sizeof(lcd_string_buffer), "INPUT: %s", inputs[input_state]);
            fb_draw_string_big(0, 0, lcd_string_buffer);
            break;
        case 3:
            snprintf(lcd_string_buffer, sizeof(lcd_string_buffer), "MIC VOL: %ld", mic_vol[0]);
            fb_draw_string_big(0, 0, lcd_string_buffer);
            break;
        case 4:
            snprintf(lcd_string_buffer, sizeof(lcd_string_buffer), "MEMS VOL:");
            fb_draw_string_big(0, 0, lcd_string_buffer);
            snprintf(lcd_string_buffer, sizeof(lcd_string_buffer), "%ld", mems_mic_vol[0]);
            fb_draw_string_big(96, 0, lcd_string_buffer);
            break;
        case 5:
            snprintf(lcd_string_buffer, sizeof(lcd_string_buffer), "WIN:");
            fb_draw_string_big(0, 0, lcd_string_buffer);
            snprintf(lcd_string_buffer, sizeof(lcd_string_buffer), "%s", windows[window_state]);
            fb_draw_string(64, 0, lcd_string_buffer);
            break;
        }

        uint16_t pctcpu = (uint16_t)((processing_time * 100) / last_running_time);
        fb_clear_line (2);
        snprintf(lcd_string_buffer, sizeof(lcd_string_buffer), "%03u%%" , pctcpu);
        fb_draw_string(0, 2, lcd_string_buffer);
        snprintf(lcd_string_buffer, sizeof(lcd_string_buffer), "%ums" , ms_per_loop);
        fb_draw_string(20, 2, lcd_string_buffer);
        snprintf(lcd_string_buffer, sizeof(lcd_string_buffer), "%s" , inputs_short[input_state]);
        fb_draw_string(41, 2, lcd_string_buffer);
        snprintf(lcd_string_buffer, sizeof(lcd_string_buffer), "%s" , windows[window_state]);
        fb_draw_string(64, 2, lcd_string_buffer);

        uint16_t i;
        int16_t l;
        for (i = 0; i < FFT_NUM_BINS; i++) {
            l = fft_bin_buffer[i];
            if (status % 0x80 == 0) {
                fb_draw_v_line(i, 32, i >= 126 ? 31 : 32, 0);
            }
            if (l == 0) continue;
            if (l > 32) l = 32;
            fb_draw_v_line(i, 64 - l, i >= 126 ? l - 1 : l, 1);
        }
        
        show_fft_range(f_marker - 16, f_marker);

        fb_show();

        status++;
    }

    return EXIT_SUCCESS;
}
