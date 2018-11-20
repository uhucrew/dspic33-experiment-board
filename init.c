#include <xc.h>
#include <p33EP512MC202.h>


void osc_init() {
    //set clock for ~140MHz / 70MIPS
    //24.576 / 4 = 6.144 * 46 = 282.624 / 2 = 141.312MHz
    PLLFBD = 44;                        // pll multiplier (M) 44 = *46
    CLKDIVbits.PLLPRE = 2;              // PLLPRE (N2) 2 = /4
    CLKDIVbits.PLLPOST = 0;             // PLLPOST (N1) 0 = /2
    CLKDIVbits.DOZE = 0;

    // Disable Watch Dog Timer
    RCONbits.SWDTEN = 0;

    //clock switching to activate PLL
    __builtin_write_OSCCONH( 0x03 );    //switch clock to primary oscillator

    //oscillator with PLL (NOSC=0b011)
    __builtin_write_OSCCONL( 0x01 );    //start clock switching

    while( OSCCONbits.COSC != 0b011 );
    while(!OSCCONbits.LOCK);            //wait for PLL lock
}
