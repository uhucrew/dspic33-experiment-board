/* 
 * File:   lp100_4taps_iir.h
 * Author: main
 *
 * Created on 20. Januar 2019, 14:32
 */

#ifndef LP100_4TAPS_IIR_H
#define	LP100_4TAPS_IIR_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <dsp.h>

#include "defines.h"
#include "fft.h"
#include "window.h"

#define LP100_4TAPS_TAPS    4

const fractional lp100_4taps_coefficients[LP100_4TAPS_TAPS * 5] __attribute__((space(ymemory),address(YMEM_BASE + sizeof(fft_buffer) + sizeof(window_fn_buffer)))) = {
	Q15(1.7035720716E-03),      	//b0
    Q15(3.4071441431E-03),          //b1
    Q15(1.8378208097E+00 / 2),      //-a1
    Q15(1.7035720716E-03),          //b2
    Q15(-8.4463509641E-01),         //-a2

    Q15(1.7239605463E-03),          //b0
    Q15(3.4479210926E-03),          //b1
    Q15(1.8598158268E+00 / 2),      //-a1
    Q15(1.7239605463E-03),          //b2
    Q15(-8.6671166691E-01),         //-a2

    Q15(1.7629461977E-03),          //b0
    Q15(3.5258923955E-03),          //b1
    Q15(1.9018737841E+00 / 2),      //-a1
    Q15(1.7629461977E-03),          //b2
    Q15(-9.0892556695E-01),         //-a2

    Q15(1.8166201990E-03),          //b0
    Q15(3.6332403979E-03),          //b1
    Q15(1.9597787243E+00 / 2),      //-a1
    Q15(1.8166201990E-03),          //b2
    Q15(-9.6704520762E-01)          //-a2
};

//iir filter states for both channels, two states per tap, two channels
static fractional lp100_4taps_states[LP100_4TAPS_TAPS * 2 * 2] __attribute__((space(xmemory))) = {
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0
};



#ifdef	__cplusplus
}
#endif

#endif	/* LP100_4TAPS_IIR_H */
