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

#include "spi_x.h"


//keep in sync with SPI_AD_BUFFER_SIZE
#define FFT_POINTS              1024


#define	RECTANGLE_WINDOW        0
#define	HAMMING_WINDOW          1
#define	BLACKMAN_WINDOW         2
#define	BLACKMAN_HARRIS_WINDOW  3
#define	GAUSS_WINDOW            4



#ifdef SPIBUF_IN_EDS
extern void apply_window(uint16_t points, uint16_t *window_fn_buffer, __eds__ uint16_t *buffer, uint16_t *outbuffer);
#else
extern void apply_window(uint16_t points, uint16_t *window_fn_buffer, uint16_t *buffer, uint16_t *outbuffer);
#endif

__prog__ extern uint16_t rectangle_window[FFT_POINTS] __attribute__((space(auto_psv)));
__prog__ extern uint16_t hamming_window[FFT_POINTS] __attribute__((space(auto_psv)));
__prog__ extern uint16_t blackman_window[FFT_POINTS] __attribute__((space(auto_psv)));
__prog__ extern uint16_t blackman_harris_window[FFT_POINTS] __attribute__((space(auto_psv)));
__prog__ extern uint16_t gauss_window[FFT_POINTS] __attribute__((space(auto_psv)));

static uint16_t window_fn_buffer[FFT_POINTS] __attribute__((space(ymemory),eds));

static void setup_window_fn_buffer(__prog__ uint16_t *window_function_data) {
    static uint16_t i;

    for (i = 0; i < FFT_POINTS; i++) {
        window_fn_buffer[i] = window_function_data[i];
    }
}


#ifdef	__cplusplus
}
#endif

#endif	/* FFT_H */
