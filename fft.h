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

#define FFT_NUM_BINS                128


extern fractcomplex twiddle_factors[FFT_POINTS / 2] __attribute__((aligned(FFT_POINTS<<1),space(xmemory)));
extern fractcomplex fft_buffer[FFT_POINTS] __attribute__((aligned(FFT_POINTS<<2),space(ymemory),address(YMEM_BASE)));
extern uint16_t fft_bin_buffer[FFT_NUM_BINS] __attribute__((aligned(FFT_NUM_BINS)));
extern fractional fft_bins[FFT_POINTS] __attribute__((aligned(FFT_POINTS<<1)));


void fft_init();
void fft_compute();
void fft_build_bins();



#ifdef	__cplusplus
}
#endif

#endif	/* FFT_H */
