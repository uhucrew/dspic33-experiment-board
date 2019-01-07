/* 
 * File:   window.h
 * Author: main
 *
 * Created on 6. Januar 2019, 15:34
 */



#ifndef WINDOW_H
#define	WINDOW_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <dsp.h>
#include "spi_x.h"


//keep in sync with fft implementation
//keep in sync with SPI_AD_BUFFER_SIZE/2
#define FFT_POINTS              1024

#define	RECTANGLE_WINDOW        0
#define	HAMMING_WINDOW          1
#define	BLACKMAN_WINDOW         2
#define	BLACKMAN_HARRIS_WINDOW  3
#define	GAUSS_WINDOW            4



#ifdef SPIBUF_IN_EDS
void apply_window(uint16_t points, __eds__ fractional *buffer, __eds__ fractional *outbuffer, __eds__ fractional *window_fn_buffer_ptr);
#else
void apply_window(uint16_t points, fractional *buffer, fractional *outbuffer, fractional *window_fn_buffer_ptr);
#endif

__prog__ extern fractional rectangle_window[FFT_POINTS] __attribute__((space(auto_psv)));
__prog__ extern fractional hamming_window[FFT_POINTS] __attribute__((space(auto_psv)));
__prog__ extern fractional blackman_window[FFT_POINTS] __attribute__((space(auto_psv)));
__prog__ extern fractional blackman_harris_window[FFT_POINTS] __attribute__((space(auto_psv)));
__prog__ extern fractional gauss_window[FFT_POINTS] __attribute__((space(auto_psv)));

extern fractional window_fn_buffer[FFT_POINTS] __attribute__((space(ymemory),address(0xc000)));

void setup_window_fn_buffer(__eds__ fractional *window_fn_buffer, __prog__ fractional *window_function_data);



#ifdef	__cplusplus
}
#endif

#endif	/* WINDOW_H */

