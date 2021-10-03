/* 
 * File:   sine.h
 * Author: main
 *
 * Created on 6. Oktober 2018, 15:14
 */

#ifndef SINE_H
#define	SINE_H


#ifdef	__cplusplus
extern "C" {
#endif


#include <stdbool.h>
#include <dsp.h>
#include "defines.h"


#ifndef PI
#define PI                      3.1428571428571428571428571428571
#endif

#define SINE_TABLE_TYPE         fractional
#define SINE_POINTS             2048
#define SINE_POINTS_2N          11
#define PHASE_ACCU_SHIFT        (32 - SINE_POINTS_2N)
#define PHASE_ACCU_SHIFT_HIGH   (16 - SINE_POINTS_2N)

#define MIXER_FACTOR            500

__eds__ extern SINE_TABLE_TYPE sine_table[SINE_POINTS] __attribute__((aligned(SINE_POINTS<<1),space(ymemory),eds,address(YMEM_BASE_SINE)));

void sine_lookup_table_init();
uint32_t calculate_phase_jump(uint32_t frequency, bool mono);

void buffer_add_sine(uint16_t len, fractional *buffer, bool mono, uint32_t *phase_jump, fractional scale, uint32_t *phase_accu);
void buffer_put_sine(uint16_t len, fractional *buffer, bool mono, uint32_t *phase_jump, fractional scale, uint32_t *phase_accu);
void buffer_multiply_sine(uint16_t len, fractional *buffer, bool mono, uint32_t *phase_jump, fractional scale, uint32_t *phase_accu);
void buffer_multiply_sine_asm(uint16_t len, fractional *buffer, bool mono, uint32_t *phase_jump, fractional scale, uint32_t *phase_accu);



#ifdef	__cplusplus
}
#endif

#endif	/* SINE_H */
