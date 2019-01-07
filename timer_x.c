#include <stdbool.h>
#include <xc.h>

#include "timer_x.h"
#include "delay.h"

//1ms timer
void timer1_init() {
    //disable timer
    T1CONbits.TON = 0;
    //internal instruction cycle clock select
    T1CONbits.TCS = 0;
    //disable gated timer mode
    T1CONbits.TGATE = 0;
    //prescaler /64
    T1CONbits.TCKPS = 0b10;
    //clear timer
    TMR1 = 0;
    //period = cycle / prescaler / 1ms
    PR1 = FCY / 64 / 1000;
    //timer 1 interrupt priority
    _T1IP = 3;
    //clear interrupt flag
    _T1IF = 0;
    //enable interrupt
    _T1IE = 1;
    //start timer
    T1CONbits.TON = 1;
}

volatile uint16_t timer_ms_rtc = 0;
volatile uint16_t timer_s_rtc = 0;
volatile uint16_t timer_m_rtc = 0;
volatile uint16_t timer_h_rtc = 0;
volatile uint16_t timer_d_rtc = 0;
volatile uint32_t timer_ms = 0;
void __attribute__((__interrupt__, auto_psv)) _T1Interrupt(void)
{
    timer_ms++;
    if (++timer_ms_rtc == 1000) {
        timer_ms_rtc = 0;
        if (++timer_s_rtc == 60) {
            timer_s_rtc = 0;
            if (++timer_m_rtc == 60) {
                timer_m_rtc = 0;
                if (++timer_h_rtc == 24) {
                    timer_d_rtc++;
                }
            }
        }
    }

    //clear interrupt flag
    _T1IF = 0;
}

//nearly exact 100 * 10us timer
void timer2_init() {
    //disable timer
    T2CONbits.TON = 0;
    //internal instruction cycle clock select
    T2CONbits.TCS = 0;
    //disable gated timer mode
    T2CONbits.TGATE = 0;
    //prescaler /1
    T2CONbits.TCKPS = 0b00;
    //clear timer
    TMR2 = 0;
    //period = cycle / prescaler / 10us
    PR2 = timer2_reload;
    //timer 2 interrupt priority
    _T2IP = 4;
    //clear interrupt flag
    _T2IF = 0;
    //enable interrupt
    _T2IE = 1;
    //start timer
    T2CONbits.TON = 1;
}

volatile uint16_t timer_10us = 0;
void __attribute__((__interrupt__, auto_psv)) _T2Interrupt(void)
{
    timer_10us++;

    //clear interrupt flag
    _T2IF = 0;
}


//rtc ms timer since start
uint64_t running_time() {
    return   (uint64_t)timer_d_rtc * 86400000
           + (uint32_t)timer_h_rtc * 3600000
           + timer_m_rtc * 60000
           + timer_s_rtc * 1000
           + timer_ms_rtc;
}


bool wait_us_for_register_bits(volatile uint16_t *reg, uint16_t bitmask, bool desired_state, uint32_t max_wait_us) {
    if (max_wait_us == 0) {
        if ((*reg & bitmask) == 0 && desired_state == false) return true;
        if ((*reg & bitmask) == bitmask && desired_state == true) return true;
        return false;
    }
    volatile uint32_t start_timer_10us = timer_10us;

    while (1) {
        if ((*reg & bitmask) == 0 && desired_state == false) return true;
        if ((*reg & bitmask) == bitmask && desired_state == true) return true;
        if ((uint32_t)((int32_t)(timer_10us - start_timer_10us) * 10) >= max_wait_us) return false;
    }
}

void timer_delay_us(uint32_t us) {
    volatile uint32_t start_timer_10us = timer_10us;
    while ((uint32_t)((int32_t)(timer_10us - start_timer_10us) * 10) < us);
}

void timer_delay_ms(uint32_t ms) {
    volatile uint32_t start_timer_ms = timer_ms;
    while ((uint32_t)((int32_t)(timer_ms - start_timer_ms)) < ms);
}


static uint16_t timer3_reload = (uint16_t)(FCY / 1 / 20000);
//workqueue timer ~50us
void timer3_init() {
    //disable timer
    T3CONbits.TON = 0;
    //internal instruction cycle clock select
    T3CONbits.TCS = 0;
    //disable gated timer mode
    T3CONbits.TGATE = 0;
    //prescaler /1
    T3CONbits.TCKPS = 0b00;
    //clear timer
    TMR3 = 0;
    //period = cycle / prescaler / 10us
    PR3 = timer3_reload;
    //timer 3 interrupt priority
    _T3IP = 1;
    //clear interrupt flag
    _T3IF = 0;
    //enable interrupt
    _T3IE = 1;
    //start timer
    T3CONbits.TON = 1;
}
