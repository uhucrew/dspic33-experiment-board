/* 
 * File:   filter.h
 * Author: main
 *
 * Created on 20. Januar 2019, 15:08
 */

#ifndef FILTER_H
#define	FILTER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include    <dsp.h>

void filter_iir(uint16_t length, uint16_t input32bit, uint16_t taps, fractional *buffer, fractional *states, const fractional *coefficients);

#ifdef	__cplusplus
}
#endif

#endif	/* FILTER_H */

