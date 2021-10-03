/* 
 * File:   timer.h
 * Author: main
 *
 * Created on 19. September 2018, 22:24
 */

#ifndef TIMER_X_H
#define	TIMER_X_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include "defines.h"


static const uint16_t timer2_reload = (uint16_t)(FCY / 1 / 100000);
//static const uint16_t timer2_gap = (uint16_t)((uint32_t)(FCY / 1 / 1000) - 99 * (uint16_t)(FCY / 1 / 100000));

void timer1_init();
void timer2_init();
void timer3_init();
uint64_t running_time();
uint32_t timer_ms_counter();
bool wait_us_for_register_bits(volatile uint16_t *reg, uint16_t bitmask, bool desired_state, uint32_t max_wait_us);
void timer_delay_us(uint32_t us);
void timer_delay_ms(uint32_t ms);



#ifdef	__cplusplus
}
#endif

#endif	/* TIMER_X_H */

