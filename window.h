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
#include "defines.h"
#include "fft.h"
#include "spi_x.h"


#define	DIRICHLET_WINDOW        0
#define	HAMMING_WINDOW          1
#define	BLACKMAN_WINDOW         2
#define	BLACKMAN_HARRIS_WINDOW  3
#define	GAUSS_WINDOW            4
#define	KAISER_WINDOW           5
#define	BARTLETT_WINDOW         6
#define	FLAT_TOP_WINDOW         7



void apply_window(uint16_t points, fractional *buffer, __eds__ fractcomplex *outbuffer);


__prog__ extern fractional dirichlet_window[FFT_POINTS] __attribute__((space(prog)));
__prog__ extern fractional hamming_window[FFT_POINTS] __attribute__((space(prog)));
__prog__ extern fractional blackman_window[FFT_POINTS] __attribute__((space(prog)));
__prog__ extern fractional blackman_harris_window[FFT_POINTS] __attribute__((space(prog)));
__prog__ extern fractional gauss_window[FFT_POINTS] __attribute__((space(prog)));
__prog__ extern fractional kaiser_window[FFT_POINTS] __attribute__((space(prog)));
__prog__ extern fractional bartlett_window[FFT_POINTS] __attribute__((space(prog)));
__prog__ extern fractional flat_top_window[FFT_POINTS] __attribute__((space(prog)));

extern fractional window_fn_buffer[FFT_POINTS] __attribute__((aligned(FFT_POINTS<<1),space(ymemory),address(YMEM_BASE_WIN)));
extern fractional *window_fn_buffer_ptr;


void setup_window_fn_buffer(__eds__ fractional *window_fn_buffer, __prog__ fractional *window_function_data);



#ifdef	__cplusplus
}
#endif

#endif	/* WINDOW_H */

