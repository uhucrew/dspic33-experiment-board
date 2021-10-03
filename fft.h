/* 
 * File:   fft.h
 * Author: main
 *
 * Created on 28. Dezember 2018, 15:14
 */

#ifndef FFT_H
#define	FFT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <dsp.h>

#include "defines.h"


//keep in sync with fft implementation
//keep in sync with SPI_AD_BUFFER_SIZE/2
#define FFT_POINTS              1024
//LOG2(FFT_POINTS)
#define FFT_BITS                10

#define FFT_MAX_FREQUENCIES     8

#define FFT_NUM_BINS            128

#define IFFT_POINTS             256
//LOG2(FFT_POINTS)
#define IFFT_BITS               8

extern fractcomplex twiddle_factors[FFT_POINTS>>1] __attribute__((aligned(FFT_POINTS<<1),space(xmemory)));
extern fractcomplex fft_buffer[FFT_POINTS] __attribute__((aligned(FFT_POINTS<<2),space(ymemory),address(YMEM_BASE_FFT)));
extern uint16_t fft_bin_buffer[FFT_NUM_BINS] __attribute__((aligned(FFT_NUM_BINS),space(xmemory)));
extern fractional fft_bins[FFT_POINTS] __attribute__((aligned(FFT_POINTS<<1),space(xmemory)));
extern volatile uint32_t fft_max_frequency;

extern fractcomplex twiddle_factors_ifft[IFFT_POINTS>>1] __attribute__((aligned(IFFT_POINTS<<1),space(xmemory)));
extern fractcomplex ifft_buffer[IFFT_POINTS] __attribute__((aligned(IFFT_POINTS<<2),space(ymemory),address(YMEM_BASE_IFFT)));
extern fractional ifft_bins[IFFT_POINTS] __attribute__((aligned(IFFT_POINTS<<1),space(xmemory)));


register int dsp_accA asm("A"); 


void fft_init();
uint32_t fft_compute();
void fft_build_bins();

void ifft_init();
void ifft_compute();
void ifft_fill_buffer(int16_t fft_bins_start);
void ifft_output_buffer();


#ifdef	__cplusplus
}
#endif

#endif	/* FFT_H */
