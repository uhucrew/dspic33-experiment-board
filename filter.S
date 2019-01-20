    .include "xc.inc"
    .include "defines.h"

    .text

    //void filter_iir(uint16_t length, uint16_t input32bit, fractional *buffer, const fractional *coefficients, fractional *states);
    .global	_filter_iir
_filter_iir:
    PUSH	W4				    //save registers
    PUSH	W5
    PUSH	W8
    PUSH	W10
    MOV		W3, W8				    //load pointers to working registers
    MOV		W4, W10
    CLR		A, [W8], W4, [W10], W5		    //clear ACC A and preload data from buffers
    LSR		W0, W0				    //loop #points/2
    SUB		#1, W0
    DO		W0, filter_iir_end
    //MPY		W4*W5, A, [W8]+=2, W4, [W10]+=2, W5 //multiply, preload and inc pointers
    NOP
filter_iir_end:
    NOP
    POP		W10				    //restore registers
    POP		W8
    POP		W5
    POP		W4
    RETURN
/*
    lp100_4taps_coefficients
    lp100_4taps_states
        
;Parameter:
;       numtap:         Anzahl der Stufen
;       koeffaddr:      Adresse der Adresse der Filterkoeffizienten
;       sampaddr:       Adresse der zeitverz<94>gerten Samples
;       input:          Datenregister mit input-sample R0 oder R1 (mpyf3!)
;       output:         Datenregister f<81>r output-sample R2 oder R3 (addf3!)
;equations:     y := x*b0 + u1
;               u1:= x*b1 + y*a1 + u2
;               u2:= x*b2 + y*a2
;
;uses:  RC,ST,AR0,AR1,R3,R4,R5

iir     .macro  numtap,koeffaddr,sampaddr,inoutput

        ldi     koeffaddr,AR0           ;koeffizientenadresse nach AR0 laden
        ldi     sampaddr,AR1            ;sampleadresse nach AR1

        ldi     numtap-1,RC             ;repeatcounter
        
      rptb endiir                       ;repeat numtap-1 times

        mpyf3   inoutput,*AR0++(1),R5   ;x*b0 -> R5
        addf3   R5,*AR1,R3              ;x*b0 + u1 -> R3 (y)
        
        mpyf3   inoutput,*AR0++(1),R5   ;x*b1 -> R5
        mpyf3   R3,*AR0++(1),R4         ;y*a1 -> R4
        addf    R5,R4                   ;x*b1 + y*a1 -> R4
        addf    *+AR1(1),R4             ;x*b1 + y*a1 + u2 -> R4
        stf     R4,*AR1++(1)            ;R4 -> u1

        mpyf3   inoutput,*AR0++(1),R5   ;x*b2 -> R5
        mpyf3   R3,*AR0++(1),R4         ;y*a2 -> R4
        addf    R5,R4                   ;x*b2 + y*a2 -> R4
        stf     R4,*AR1++(1)            ;R4 -> u2
        pushf   R3                      ;y sichern
        popf    inoutput                ;y -> inoutput

endiir:  
        nop                             ;letzter rptb befehl
        .endm
*/

    .end