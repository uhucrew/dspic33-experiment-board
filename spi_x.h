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

    
//samplerate test frames
#define     SR_TEST_FRAMES          10000
#define     SPI_DA_SKIP_FIRST       2

#define     SPI_DA_BUFFER_SIZE      2048

#define     SPI_AD_BUFFER_SIZE      1024

#define     INPUT_SAMPLERATE        192
#define     OUTPUT_SAMPLERATE       48
#define     SAMPLERATE_RATIO        INPUT_SAMPLERATE / OUTPUT_SAMPLERATE


extern uint16_t spi_da_buffer_0[SPI_DA_BUFFER_SIZE] __attribute__((aligned(SPI_DA_BUFFER_SIZE)));
extern uint16_t spi_da_buffer_1[SPI_DA_BUFFER_SIZE] __attribute__((aligned(SPI_DA_BUFFER_SIZE)));
__eds__ extern uint16_t spi_ad_buffer_0[SPI_AD_BUFFER_SIZE] __attribute__((aligned(SPI_AD_BUFFER_SIZE),space(eds)));
__eds__ extern uint16_t spi_ad_buffer_1[SPI_AD_BUFFER_SIZE] __attribute__((aligned(SPI_AD_BUFFER_SIZE),space(eds)));
extern volatile bool spi_da_buffer_empty[2];
extern volatile bool spi_ad_buffer_full[2];


void SPI1_init();
void SPI2_init();


#ifdef	__cplusplus
}
#endif

#endif	/* SPI_X_H */
