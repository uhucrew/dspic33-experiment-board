#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <xc.h>
#include <dsp.h>

#include "cni.h"
#include "spi_x.h"
#include "timer_x.h"
#include "sine.h"
#include "SSD1306/lcd.h"
#include "pps.h"
#include "window.h"
#include "buffer.h"
#include "filter.h"
#include "lp100_4taps_iir.h"
#include "fft.h"



const uint16_t spi_da_buffer_end = (uint16_t)&spi_da_buffer_0 + (SPI_DA_BUFFER_SIZE<<2);
static uint16_t spi_da_dummy_read;
static uint16_t spi_ad_command = 0b1101000000000000;
fractional *spi_da_ptr = spi_da_buffer_0;
volatile uint64_t processing_time = 0;


#ifdef SPIBUF_IN_EDS
//buffer for A/D data in extended data space to save near memory
__eds__ fractional spi_ad_buffer_0[SPI_AD_BUFFER_SIZE] __attribute__((aligned(SPI_AD_BUFFER_SIZE),space(xmemory),eds));
__eds__ fractional spi_ad_buffer_1[SPI_AD_BUFFER_SIZE] __attribute__((aligned(SPI_AD_BUFFER_SIZE),space(xmemory),eds));
//buffer for D/A data
__eds__ fractional spi_da_buffer_0[SPI_DA_BUFFER_SIZE] __attribute__((aligned(SPI_DA_BUFFER_SIZE),space(xmemory),eds));
__eds__ fractional spi_da_buffer_1[SPI_DA_BUFFER_SIZE] __attribute__((aligned(SPI_DA_BUFFER_SIZE),space(xmemory),eds));
#else
fractional spi_ad_buffer_0[SPI_AD_BUFFER_SIZE] __attribute__((aligned(SPI_AD_BUFFER_SIZE),space(xmemory)));
fractional spi_ad_buffer_1[SPI_AD_BUFFER_SIZE] __attribute__((aligned(SPI_AD_BUFFER_SIZE),space(xmemory)));
fractional spi_da_buffer_0[SPI_DA_BUFFER_SIZE] __attribute__((aligned(SPI_DA_BUFFER_SIZE),space(xmemory)));
fractional spi_da_buffer_1[SPI_DA_BUFFER_SIZE] __attribute__((aligned(SPI_DA_BUFFER_SIZE),space(xmemory)));
#endif
volatile bool spi_ad_buffer_full[2] = { false, false };
volatile bool spi_da_buffer_empty[2] = { true, true };

#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"
void SPI1_DMA0STA_set() {
    DMA0STAL = (uint16_t) &spi_da_buffer_0;
    DMA0STAH = 0;
    DMA0STBL = (uint16_t) &spi_da_buffer_1;
    DMA0STBH = 0;
}
#pragma GCC diagnostic warning "-Wpointer-to-int-cast"

void SPI1_init() {
    //RA3 (RUN) output
    _TRISA3 = 0;
    //stop clocks
    _LATA3 = 1;
    //stop SPI
    SPI1STATbits.SPIEN = 0;

    //clear interrupt flag
    _SPI1IF = 0;
    //disable interrupt
    _SPI1IE = 0;

    // SPI1CON1 register bits
    SPI1CON1bits.DISSCK = 0;
    SPI1CON1bits.DISSDO = 0;
    SPI1CON1bits.MODE16 = 1;
    SPI1CON1bits.SMP = 0;
    SPI1CON1bits.CKE = 1;
    SPI1CON1bits.CKP = 0;
    SPI1CON1bits.SSEN = 0;
    SPI1CON1bits.MSTEN = 0;
    SPI1CON2bits.SPIFSD = 1;
    SPI1CON2bits.FRMEN = 0;
    SPI1CON2bits.FRMPOL = 0;
    SPI1CON2bits.FRMDLY = 0;
    SPI1STATbits.SPIROV = 0;
    SPI1STATbits.SISEL = 0b100;
    SPI1STATbits.SPIEN = 1;

    //clear interrupt flag
    _SPI1IF = 0;
    //don't enable interrupt with DMA
    //_SPI1IE = 1;
    //clear error interrupt flag
    _SPI1EIF = 0;
    //enable error interrupt
    _SPI1EIE = 1;

    //DMA0 to write to DA converter
    DMA0CONbits.SIZE = 0;
    DMA0CONbits.DIR = 1;
    //continuous ping pong mode
    DMA0CONbits.MODE = 0b10;
    DMA0CNT = SPI_DA_BUFFER_SIZE - 1;
    //0b0000000000001010 = SPI1 – Transfer Done
    DMA0REQ = 0b0000000000001010;
    SPI1_DMA0STA_set();
    DMA0PAD = (uint16_t) &SPI1BUF;
    _DMA0IP = 2;
    _DMA0IF = 0;
    _DMA0IE = 1;

    //DMA1 for dummy reads
    DMA1CONbits.SIZE = 0;
    DMA1CONbits.DIR = 0;
    //continuous no ping pong
    DMA1CONbits.MODE = 0b00;
    DMA1CNT = 0;
    //0b0000000000001010 = SPI1 – Transfer Done
    DMA1REQ = 0b0000000000001010;
    DMA1STAL = (uint16_t) &spi_da_dummy_read;
    DMA1STAH = 0;
    DMA1STBL = 0;
    DMA1STBH = 0;
    DMA1PAD = (uint16_t) &SPI1BUF;
    _DMA1IP = 2;
    _DMA1IF = 0;
    _DMA1IE = 0;

    DMA0CONbits.CHEN = 1;
    DMA1CONbits.CHEN = 1;
    DMA0REQbits.FORCE = 1;

    //start clocks
    _LATA3 = 0;
}

void __attribute__((__interrupt__, auto_psv)) _DMA0Interrupt(void) {
    if (_PPST0 == 1) {
        spi_da_buffer_empty[0] = true;
    } else {
        spi_da_buffer_empty[1] = true;
    }

    _DMA0IF = 0;
}

void __attribute__((__interrupt__, auto_psv)) _DMA1Interrupt(void) {
    _DMA1IF = 0;
}

volatile static uint32_t spi1_errors = 0;

void __attribute__((interrupt, auto_psv)) _SPI1ErrInterrupt(void) {
    spi1_errors++;
    if (SPI1STATbits.SPIROV == 1) {
        SPI1STATbits.SPIROV = 0;
    }

    _SPI1EIF = 0;
}

#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"
void SPI2_DMA2STA_set() {
    DMA2STAL = (uint16_t) &spi_ad_buffer_0;
    DMA2STAH = 0;
    DMA2STBL = (uint16_t) &spi_ad_buffer_1;
    DMA2STBH = 0;
}
#pragma GCC diagnostic warning "-Wpointer-to-int-cast"

void SPI2_init() {
    //stop SPI
    SPI2STATbits.SPIEN = 0;
    //disable interrupt
    _SPI2IE = 0;
    //clear interrupt flag
    _SPI2IF = 0;

    //stop /CONVST until SPI2 is initialized
    //RA1 disable analog function
    _ANSA1 = 0;
    //set /CONVST (or with inverted /SS) to high
    _LATA1 = 1;
    //set as output
    _TRISA1 = 0;

    //PPS connect SPI function with I/O pins
    _SDI2R = _RPI44;
    _SCK2R = _RP42;
    _SS2R = _RP36;
    _RP43R = _SDO2;
    _RP42R = _SCK2;

    // SPI2CON1 register bits
    SPI2CON1bits.DISSCK = 0;
    SPI2CON1bits.DISSDO = 0;
    SPI2CON1bits.MODE16 = 1;
    SPI2CON1bits.SMP = 0;
    SPI2CON1bits.CKE = 0;
    SPI2CON1bits.CKP = 0;
    SPI2CON1bits.SSEN = 0;
    SPI2CON1bits.MSTEN = 0;
    SPI2CON2bits.SPIFSD = 1;
    SPI2CON2bits.FRMEN = 1;
    SPI2CON2bits.FRMPOL = 1;
    SPI2CON2bits.FRMDLY = 0;
    SPI2STATbits.SPIROV = 0;
    SPI2STATbits.SISEL = 0b100;

    //configure AD converter, write CFR
    SPI2BUF = 0b1110111011111101;
    SPI2STATbits.SPIEN = 1;

    //clear interrupt flag
    _SPI2IF = 0;
    //don't enable interrupt with DMA
    //_SPI2IE = 1;
    //clear error interrupt flag
    _SPI2EIF = 0;
    //enable error interrupt
    _SPI2EIE = 1;

    //DMA2 to read to AD converter
    DMA2CONbits.SIZE = 0;
    DMA2CONbits.DIR = 0;
    //continuous ping pong mode
    DMA2CONbits.MODE = 0b10;
    DMA2CNT = SPI_AD_BUFFER_SIZE - 1;
    //0b0000000000100001 = SPI2 - Transfer Done
    DMA2REQ = 0b0000000000100001;
    SPI2_DMA2STA_set();
    DMA2PAD = (uint16_t) &SPI2BUF;
    _DMA2IP = 1;
    _DMA2IF = 0;
    _DMA2IE = 1;

    //DMA3 for command writes
    DMA3CONbits.SIZE = 0;
    DMA3CONbits.DIR = 1;
    //continuous no ping pong
    DMA3CONbits.MODE = 0b00;
    DMA3CNT = 0;
    //0b0000000000100001 = SPI2 - Transfer Done
    DMA3REQ = 0b0000000000100001;
    DMA3STAL = (uint16_t) &spi_ad_command;
    DMA3STAH = 0;
    DMA3STBL = 0;
    DMA3STBH = 0;
    DMA3PAD = (uint16_t) &SPI2BUF;
    _DMA3IP = 2;
    _DMA3IF = 0;
    _DMA3IE = 0;

    DMA2CONbits.CHEN = 1;
    DMA3CONbits.CHEN = 1;

    timer_delay_us(50);
    //enable /CONVST (or with inverted /SS)
    _LATA1 = 0;
}


void __attribute__((__interrupt__, auto_psv)) _DMA2Interrupt(void) {
    uint64_t start_processing_time = running_time();
    uint16_t i;

    _DMA2IF = 0;
    if (_PPST2 == 1) {
        spi_ad_buffer_full[0] = true;
        convert_samplerate(SPI_AD_BUFFER_SIZE, SAMPLERATE_RATIO, 0, spi_ad_buffer_0);
        apply_window(SPI_AD_BUFFER_SIZE, spi_ad_buffer_0, spi_ad_buffer_0);
        //filter_iir(SPI_AD_BUFFER_SIZE, 0, LP100_4TAPS_TAPS, spi_ad_buffer_0, lp100_4taps_states, lp100_4taps_coefficients);
        //buffer_copy_ad_fractcomplex(SPI_AD_BUFFER_SIZE, spi_ad_buffer_0, fft_buffer);
        for (i = 0; i < FFT_POINTS; i++) {
            fft_buffer[i].real = spi_ad_buffer_0[i]>>1;
            fft_buffer[i].imag = 0;
        }

        fft_compute();
        //buffer_copy_offset_sum(FFT_NUM_BINS, FFT_POINTS / FFT_NUM_BINS, (fractional *)fft_buffer, (fractional *)fft_bin_buffer);
        //fft_build_bins();
        spi_ad_buffer_full[0] = false;
    } else {
        spi_ad_buffer_full[1] = true;
        convert_samplerate(SPI_AD_BUFFER_SIZE, SAMPLERATE_RATIO, 0, spi_ad_buffer_1);
        apply_window(SPI_AD_BUFFER_SIZE, spi_ad_buffer_1, spi_ad_buffer_1);
        //filter_iir(SPI_AD_BUFFER_SIZE, 0, LP100_4TAPS_TAPS, spi_ad_buffer_1, lp100_4taps_states, lp100_4taps_coefficients);
        //buffer_copy_ad_fractcomplex(SPI_AD_BUFFER_SIZE, spi_ad_buffer_1, fft_buffer);
        for (i = 0; i < FFT_POINTS; i++) {
            fft_buffer[i].real = spi_ad_buffer_1[i]>>1;
            fft_buffer[i].imag = 0;
        }

        fft_compute();
        //buffer_copy_offset_sum(FFT_NUM_BINS, FFT_POINTS / FFT_NUM_BINS, (fractional *)fft_buffer, (fractional *)fft_bin_buffer);
        //fft_build_bins();
        spi_ad_buffer_full[1] = false;
    }

    processing_time += running_time() - start_processing_time;
    return;
}

void __attribute__((__interrupt__, auto_psv)) _DMA3Interrupt(void) {
    _DMA3IF = 0;
}


volatile static uint32_t spi2_errors = 0;

void __attribute__((interrupt, auto_psv)) _SPI2ErrInterrupt(void) {
    spi2_errors++;
    if (SPI2STATbits.SPIROV == 1) {
        SPI2STATbits.SPIROV = 0;
    }

    _SPI2EIF = 0;
}
