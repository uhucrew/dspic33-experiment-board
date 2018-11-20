/*******************************************************************************
 * File:        main.c
 * Project:     SP18 - I2C OLED Display
 * Author:      Nicolas Pannwitz
 * Version:     siehe main.h
 * Web:         http://pic-projekte.de
 ******************************************************************************/

#include <xc.h>
#include <stdlib.h>
#include <stdint.h>
#include "main.h"
#include "lcd.h"
#include "peri.h"
#include "bmp.h"

#pragma config FOSC = INTIO67       // Internal oscillator block
#pragma config PWRTEN = ON          // Power up timer enabled
#pragma config BOREN = OFF          // Brown-out Reset disabled
#pragma config WDTEN = OFF          // Watch dog timer is always disabled
#pragma config MCLRE = EXTMCLR      // MCLR enabled
#pragma config LVP = OFF            // Single-Supply ICSP disabled

/*********************************************************************
 * Diverse Einstellungen zum PIC (IO, Takt, ...)
 */

void initPIC(void)
{
    TRISA = 0x00;
    TRISB = 0x01;                   // RB0:Input (PB)
    TRISC = 0x38;                   // RC3,RC4,RC6:Input (AN16)

    ANSELA = 0x00;                  // All digital
    ANSELB = 0x00;                  // ...
    ANSELC = 0x20;                  // AN16 on

    OSCCON2bits.MFIOSEL = 0;        // 111: 16 MHz
    OSCCONbits.IRCF2 = 1;           // 110:  8 MHz
    OSCCONbits.IRCF1 = 0;           // 101:  4 MHz
    OSCCONbits.IRCF0 = 0;           // 100:  2 MHz <-- aktiv
}

/*********************************************************************
 * Main Routine
 */

void main (void)
{    
    initPIC();
    initI2C();
    lcd_init();

    /*Shut OFF the LCD-Backlight*/
    LATCbits.LC2 = 1;

    /*Etwas Text in den Framebuffer schreiben*/
    fb_draw_string_big(44,0,"OLED");
    fb_draw_string_big(0,2,"Typ:  SSD1306");
    fb_draw_string_big(0,4,"Size: 128x84");
    fb_draw_string(15,7,"http://pic-projekte.de/");

    /*Den Framebuffer zur Anzeige bringen*/
    //fb_show();
    
    /**/
    fb_show_bmp(bmp_running_men);
    
    /*Endlosschleife*/
    while(1)
    {
    }
}
