#include <stdbool.h>
#include <xc.h>
#include <p33EP512MC202.h>

#include "cni.h"


volatile static uint16_t cna_last = 0;
volatile static uint16_t cnb_last = 0;


uint16_t empty_fn() {
    return 0;
}


uint16_t (*ra00_cn_fn)() = &empty_fn;
//uint16_t (*ra01_cn_fn)() = empty_fn;
//uint16_t (*ra02_cn_fn)() = empty_fn;
//uint16_t (*ra03_cn_fn)() = empty_fn;
//uint16_t (*ra04_cn_fn)() = empty_fn;
//uint16_t (*ra05_cn_fn)() = empty_fn;
//uint16_t (*ra06_cn_fn)() = empty_fn;
//uint16_t (*ra07_cn_fn)() = empty_fn;
//uint16_t (*ra08_cn_fn)() = empty_fn;
//uint16_t (*ra09_cn_fn)() = empty_fn;
//uint16_t (*ra10_cn_fn)() = empty_fn;
//uint16_t (*ra11_cn_fn)() = empty_fn;
//uint16_t (*ra12_cn_fn)() = empty_fn;
//uint16_t (*ra13_cn_fn)() = empty_fn;
//uint16_t (*ra14_cn_fn)() = empty_fn;
//uint16_t (*ra15_cn_fn)() = empty_fn;

uint16_t (*rb00_cn_fn)() = &empty_fn;
//uint16_t (*rb01_cn_fn)() = empty_fn;
//uint16_t (*rb02_cn_fn)() = empty_fn;
//uint16_t (*rb03_cn_fn)() = empty_fn;
//uint16_t (*rb04_cn_fn)() = empty_fn;
//uint16_t (*rb05_cn_fn)() = empty_fn;
//uint16_t (*rb06_cn_fn)() = empty_fn;
//uint16_t (*rb07_cn_fn)() = empty_fn;
//uint16_t (*rb08_cn_fn)() = empty_fn;
//uint16_t (*rb09_cn_fn)() = empty_fn;
//uint16_t (*rb10_cn_fn)() = empty_fn;
//uint16_t (*rb11_cn_fn)() = empty_fn;
//uint16_t (*rb12_cn_fn)() = empty_fn;
uint16_t (*rb13_cn_fn)() = empty_fn;
//uint16_t (*rb14_cn_fn)() = empty_fn;
//uint16_t (*rb15_cn_fn)() = empty_fn;


void __attribute__((__interrupt__, no_auto_psv)) _CNInterrupt(void)
{
    if (CNENA) {
        uint16_t porta_x = PORTA;
        uint16_t cna_change = (cna_last ^ porta_x) & CNENA;
        cna_last = porta_x;

        //RAXX CN interrupt routines
        if (cna_change & 0x0001) {
            (*ra00_cn_fn)();
        }
/*
        if (cna_change & 0x0002) {
            (*ra01_cn_fn)();
        }
        if (cna_change & 0x0004) {
            (*ra02_cn_fn)();
        }
        if (cna_change & 0x0008) {
            (*ra03_cn_fn)();
        }
        if (cna_change & 0x0010) {
            (*ra04_cn_fn)();
        }
        if (cna_change & 0x0020) {
            (*ra05_cn_fn)();
        }
        if (cna_change & 0x0040) {
            (*ra06_cn_fn)();
        }
        if (cna_change & 0x0080) {
            (*ra07_cn_fn)();
        }
        if (cna_change & 0x0100) {
            (*ra08_cn_fn)();
        }
        if (cna_change & 0x0200) {
            (*ra09_cn_fn)();
        }
        if (cna_change & 0x0400) {
            (*ra10_cn_fn)();
        }
        if (cna_change & 0x0800) {
            (*ra11_cn_fn)();
        }
        if (cna_change & 0x1000) {
            (*ra12_cn_fn)();
        }
        if (cna_change & 0x2000) {
            (*ra13_cn_fn)();
        }
        if (cna_change & 0x4000) {
            (*ra14_cn_fn)();
        }
        if (cna_change & 0x8000) {
            (*ra15_cn_fn)();
        }
*/
    }
    if (CNENB) {
        uint16_t portb_x = PORTB;
        uint16_t cnb_change = (cnb_last ^ portb_x) & CNENB;
        cnb_last = portb_x;

        //RBXX CN interrupt routines
        if (cnb_change & 0x0001) {
            (*rb00_cn_fn)();
        }
/*
        if (cnb_change & 0x0002) {
            (*rb01_cn_fn)();
        }
        if (cnb_change & 0x0004) {
            (*rb02_cn_fn)();
        }
        if (cnb_change & 0x0008) {
            (*rb03_cn_fn)();
        }
        if (cnb_change & 0x0010) {
            (*rb04_cn_fn)();
        }
        if (cnb_change & 0x0020) {
            (*rb05_cn_fn)();
        }
        if (cnb_change & 0x0040) {
            (*rb06_cn_fn)();
        }
        if (cnb_change & 0x0080) {
            (*rb07_cn_fn)();
        }
        if (cnb_change & 0x0100) {
            (*rb08_cn_fn)();
        }
        if (cnb_change & 0x0200) {
            (*rb09_cn_fn)();
        }
        if (cnb_change & 0x0400) {
            (*rb10_cn_fn)();
        }
        if (cnb_change & 0x0800) {
            (*rb11_cn_fn)();
        }
        if (cnb_change & 0x1000) {
            (*rb12_cn_fn)();
        }
*/
         if (cnb_change & 0x2000) {
            (*rb13_cn_fn)();
        }
/*
        if (cnb_change & 0x4000) {
            (*rb14_cn_fn)();
        }
        if (cnb_change & 0x8000) {
            (*rb15_cn_fn)();
        }
*/
    }

    _CNIF = 0;
}  
