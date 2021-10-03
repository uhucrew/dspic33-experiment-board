/* 
 * File:   spi_x.h
 * Author: main
 *
 * Created on 28. September 2018, 19:25
 */

#ifndef SPI_X_H
#define	SPI_X_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <dsp.h>


//#define SPIBUF_IN_EDS


    
//samplerate test frames
#define     SR_TEST_FRAMES          10000
#define     SPI_DA_SKIP_FIRST       2

//size for both channels
#define     SPI_DA_BUFFER_SIZE      2048

//size for both channels, must be 2 times fft window length
#define     SPI_AD_BUFFER_SIZE      2048

#define     INPUT_SAMPLERATE        192000ULL
#define     INPUT_SAMPLERATE_MONO   384000ULL
#define     OUTPUT_SAMPLERATE       48000ULL
#define     SAMPLERATE_RATIO        INPUT_SAMPLERATE / OUTPUT_SAMPLERATE
#define     FREQ_POINT_STEP         (INPUT_SAMPLERATE * 10) / FFT_POINTS
#define     FREQ_POINT_STEP_MONO    (INPUT_SAMPLERATE_MONO * 10) / FFT_POINTS
#define     BUFFER_RATIO            SPI_AD_BUFFER_SIZE / SPI_DA_BUFFER_SIZE
#if         BUFFER_RATIO > SAMPLERATE_RATIO
#warning    samplerate ratio larger than buffer ratio, samples will be lost while translating samplerates
#endif


#ifdef SPIBUF_IN_EDS
__eds__ extern fractional spi_ad_buffer_0[SPI_AD_BUFFER_SIZE] __attribute__((aligned(SPI_AD_BUFFER_SIZE),space(xmemory),eds));
__eds__ extern fractional spi_ad_buffer_1[SPI_AD_BUFFER_SIZE] __attribute__((aligned(SPI_AD_BUFFER_SIZE),space(xmemory),eds));
__eds__ extern fractional spi_da_buffer_0[SPI_DA_BUFFER_SIZE] __attribute__((aligned(SPI_DA_BUFFER_SIZE),space(xmemory),eds));
__eds__ extern fractional spi_da_buffer_1[SPI_DA_BUFFER_SIZE] __attribute__((aligned(SPI_DA_BUFFER_SIZE),space(xmemory),eds));
#else
extern fractional spi_ad_buffer_0[SPI_AD_BUFFER_SIZE] __attribute__((aligned(SPI_AD_BUFFER_SIZE),space(xmemory)));
extern fractional spi_ad_buffer_1[SPI_AD_BUFFER_SIZE] __attribute__((aligned(SPI_AD_BUFFER_SIZE),space(xmemory)));
extern fractional spi_da_buffer_0[SPI_DA_BUFFER_SIZE] __attribute__((aligned(SPI_DA_BUFFER_SIZE),space(xmemory)));
extern fractional spi_da_buffer_1[SPI_DA_BUFFER_SIZE] __attribute__((aligned(SPI_DA_BUFFER_SIZE),space(xmemory)));
#endif
extern volatile bool spi_ad_buffer_full[2];
extern volatile bool spi_da_buffer_empty[2];

extern volatile uint64_t processing_time;

extern bool mono;

extern uint32_t phase_jump_mixer;

void SPI1_init();
void SPI2_init();


#ifdef	__cplusplus
}
#endif

#endif	/* SPI_X_H */
