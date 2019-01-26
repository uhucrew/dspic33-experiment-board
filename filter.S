    .include "xc.inc"
    .include "defines.h"

    .text

    //void filter_iir(uint16_t length, uint16_t input32bit, uint16_t taps, fractional *buffer, fractional *states, const fractional *coefficients);
    //W0: length (number of samples)
    //W1: 0 = 16bit input, 1 = 32bit input
    //W2: number of taps
    //W3: pointer to samples buffer
    //W4: pointer to states buffer
    //W5: pointer to filter coefficients
    .global	_filter_iir
_filter_iir:
    PUSH	W8				    //save registers
    PUSH	W9
    PUSH	W10
    PUSH	W13
    SUB		#1, W2				    //loop #taps
    MOV		W3, W9				    //load samples pointer to working registers
    SL		W0, W0				    //two bytes per sample
    ADD		W0, W3, W3			    //calculate end address
    BTSC	W1, #0				    //for 32bit input double length
    ADD		W0, W3, W3
filter_iir_loop:
    BTSS	W9, #1				    //reload states poiter after 2nd channel
    MOV		W4, W8				    //load states (u1/u2) pointer to working registers
    MOV		W5, W10				    //load coefficients (b0, b1, -a1, b2, -a2) pointer to working registers
    CLR		A, [W9], W6, [W10]+=2, W7	    //clear ACC A and preload data (x -> W6, b0 -> W7) from buffers
  DO		W2, filter_iir_end		    //loop number of taps
    LAC		[W8++], A				    //u1 -> ACC A, point to u2
    MAC		W6 * W7, A, [W9], W6, [W10]+=2, W7	    //A = x * b0 + u1 multiply, preload and inc pointers, x -> W6, b1 -> W7
    LAC		[W8--], B				    //u2 -> ACC B, point to u1
    MAC		W6 * W7, B, [W9], W6, [W10]+=2, W7          //B = x * b1 + u2 multiply, preload and inc pointers, x -> W6, -a1 -> W7
    SAC		A, W6					    //A = y -> W6
    MAC		W6 * W7, B, [W9], W6, [W10]+=2, W7	    //B = y * a1 + x * b1 + u2, preload and inc pointers, x -> W6, b2 -> W7
    SAC		B, [W8++]				    //store B -> u1
    MPY		W6 * W7, B, [W9], W6, [W10]+=2, W7	    //B = x * b2, preload and inc pointers, x -> W6, -a2 -> W7
    SAC		A, W6					    //A = y -> W6
    SAC		A, [W9]					    //store y -> sample
    MAC		W6 * W7, B, [W9], W6, [W10]+=2, W7	    //B = y * a2 + x * b2, preload and inc pointers, x -> W6, b2 -> W7
filter_iir_end:
    SAC		B, [W8++]				    //store B -> u2
    INC2	W9, W9				    //next sample
    CPSEQ	W9, W3				    //buffer end reached?
    BRA		filter_iir_loop
    POP		W13				    //restore registers
    POP		W10
    POP		W9
    POP		W8
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