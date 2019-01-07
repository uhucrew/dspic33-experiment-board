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

//size for both channels
#define     SPI_AD_BUFFER_SIZE      2048

#define     INPUT_SAMPLERATE        192
#define     OUTPUT_SAMPLERATE       48
#define     SAMPLERATE_RATIO        INPUT_SAMPLERATE / OUTPUT_SAMPLERATE


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


void SPI1_init();
void SPI2_init();


#ifdef	__cplusplus
}
#endif

#endif	/* SPI_X_H */
