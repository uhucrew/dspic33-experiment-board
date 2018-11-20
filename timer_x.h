/* 
 * File:   timer.h
 * Author: main
 *
 * Created on 19. September 2018, 22:24
 */

#ifndef TIMER_H
#define	TIMER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdbool.h>

void timer1_init();
void timer2_init();
void timer3_init();
uint64_t running_time();
bool wait_us_for_register_bits(volatile uint16_t *reg, uint16_t bitmask, bool desired_state, uint32_t max_wait_us);
void timer_delay_us(uint32_t us);
void timer_delay_ms(uint32_t ms);


#ifdef	__cplusplus
}
#endif

#endif	/* TIMER_H */

