/* 
 * File:   defines.h
 * Author: main
 *
 * Created on 17. September 2018, 21:53
 */

#ifndef DEFINES_H
#define	DEFINES_H


#ifdef __C30__
    #define YMEM_BASE   0x9000              //base address of ymemory
    #define CRYSTAL     24576000            //crystal with 24.576 MHz
    #define PLLFBD_DEF  44                  //pll multiplier (M) 44 = *46
    #define PLLPRE_DEF  2                   //pll prescaler  (N2) 2 = /4
    #define PLLPOST_DEF 0                   //pll postscaler (N1) 0 = /2
    #define FOSC        CRYSTAL / (PLLPRE_DEF + 2) * (PLLFBD_DEF + 2) / (PLLPOST_DEF + 2)
    #define FCY         FOSC / 2
    #define I2CBAUD     800000
    #define I2CBRG_DEF  ((uint16_t)((16.0 / (double)I2CBAUD - 16.0 * 120E-09) * FCY) >> 4) - 2
#else
    .equ CRYSTAL,       24576000            ;crystal with 24.576 MHz
    .equ PLLFBD_DEF,    44                  ;pll multiplier (M) 44 = *46
    .equ PLLPRE_DEF,    2                   ;pll prescaler  (N2) 2 = /4
    .equ PLLPOST_DEF,   0                   ;pll postscaler (N1) 0 = /2
    .equ FOSC,          CRYSTAL / (PLLPRE_DEF + 2) * (PLLFBD_DEF + 2) / (PLLPOST_DEF + 2)
    .equ FCY,           FOSC / 2
    .equ FCY_US,        FCY / 1000000
    .equ FCY_MS,        FCY / 1000          ;70656000 cycles/s -> 4416 * 16000 cycles/s FCY_LOOP
#endif


#endif	/* DEFINES_H */

