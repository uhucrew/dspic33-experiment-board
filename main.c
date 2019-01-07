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


uint64_t processing_time = 0;

//working tasks timer interrupt, save psv and working registers
void __attribute__((__interrupt__, auto_psv, shadow)) _T3Interrupt(void) {
    uint64_t start_processing_time = running_time();
    static uint16_t i;
    static uint16_t da_ptr = 0;

    //copy AD input buffer to output buffer
    //convert samplerate and 16 bit input to 32(24) bit output
    //sum up volume to be displayed in main loop
    if (spi_ad_buffer_full[0]) {
        //use half buffer size as number of points (for stereo)
        //apply_window(SPI_AD_BUFFER_SIZE>>1, spi_ad_buffer_0, spi_ad_buffer_0, window_fn_buffer);
        for (i = 0; i < SPI_AD_BUFFER_SIZE; i += 2 * SAMPLERATE_RATIO) {
            spi_da_buffer_0[da_ptr++] = spi_ad_buffer_0[i];
            spi_da_buffer_0[da_ptr++] = 0;
            spi_da_buffer_0[da_ptr++] = spi_ad_buffer_0[i+1];
            spi_da_buffer_0[da_ptr++] = 0;
            if (da_ptr >= SPI_DA_BUFFER_SIZE<<1) {
                da_ptr = 0;
            }
        }
        spi_ad_buffer_full[0] = false;
    }
    if (spi_ad_buffer_full[1]) {
        //use half buffer size as number of points (for stereo)
        //apply_window(SPI_AD_BUFFER_SIZE>>1, spi_ad_buffer_1, spi_ad_buffer_1, window_fn_buffer);
        for (i = 0; i < SPI_AD_BUFFER_SIZE; i += 2 * SAMPLERATE_RATIO) {
            spi_da_buffer_0[da_ptr++] = spi_ad_buffer_1[i];
            spi_da_buffer_0[da_ptr++] = 0;
            spi_da_buffer_0[da_ptr++] = spi_ad_buffer_1[i+1];
            spi_da_buffer_0[da_ptr++] = 0;
            if (da_ptr >= SPI_DA_BUFFER_SIZE<<1) {
                da_ptr = 0;
            }
        }
        spi_ad_buffer_full[1] = false;
    }

    processing_time += running_time() - start_processing_time;
    //clear interrupt flag
    _T3IF = 0;
}





int main(int argc, char** argv) {
    //start system clocks
    osc_init();
    //start timers before any other peripherals
    timer1_init();
    timer2_init();
    //start I2C to output debug info to display
    I2C2_init();
    //mute before SPI init
    set_volume(I2C_ADDR_MAX5387, 0);
    lcd_init();
    fb_clear();
    fb_show();
    //initialize rotary encoder
    QEI_init();
    //initialize dds variables
    set_dds_step(48, 55.0, 880.0);

    setup_window_fn_buffer(window_fn_buffer, hamming_window);

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

    static const char empty_line[] = "                                ";
    static uint8_t status = 1;
    static uint16_t ms_per_loop = 0;
    static int32_t qei_diff, qei_last = 0, volume = 128, loop_count = 0;
    static bool menu_active = false;
    uint64_t last_running_time = running_time();

    set_volume(I2C_ADDR_MAX5387, volume);
    
    //main loop manage menu
    while (1) {
        fb_clear();
        fb_drawPixel(127, 63, status);

        qei_diff = qei_last - (int32_t)(((uint32_t)POS1CNTH<<16) + POS1CNTL);
        //process menu if qei_diff reaches next detent -> +2
        if (abs(qei_diff) > 1) {
            qei_last = (((uint32_t)POS1CNTH<<16) + POS1CNTL);
            //two steps per detent
            qei_diff /= 2;
            if (!menu_active) {
                //FIXME: add acceleration
                volume -= qei_diff;
                if (volume < 0) volume = 0;
                if (volume > 255) volume = 255;
                set_volume(I2C_ADDR_MAX5387, (uint8_t)volume);
            }
        }

        if (++loop_count % 10 == 0) {
            ms_per_loop = (uint16_t)((running_time() - last_running_time) / 10);
            last_running_time = running_time();
        }

        if (!menu_active) {
            snprintf(lcd_string_buffer, sizeof(lcd_string_buffer), "VOLUME:  %ld", volume);
            fb_draw_string (0, 0, empty_line);
            fb_draw_string (0, 0, lcd_string_buffer);
        }
        else {
            snprintf(lcd_string_buffer, sizeof(lcd_string_buffer), "POS1CNT:  %ld", ((uint32_t)POS1CNTH<<16) + POS1CNTL);
            fb_draw_string (0, 0, empty_line);
            fb_draw_string (0, 0, lcd_string_buffer);
        }
        snprintf(lcd_string_buffer, sizeof(lcd_string_buffer), "ms/loop: %u", ms_per_loop);
        fb_draw_string (0, 1, empty_line);
        fb_draw_string (0, 1, lcd_string_buffer);
        snprintf(lcd_string_buffer, sizeof(lcd_string_buffer), "pct cpu: %u", (uint16_t)((processing_time * 100) / last_running_time));
        fb_draw_string (0, 2, empty_line);
        fb_draw_string (0, 2, lcd_string_buffer);
        fb_show();

        status = status ^ 1;
    }

    return EXIT_SUCCESS;
}
