    .include "xc.inc"

    .text


    //void apply_window(uint16_t points, fractional *buffer, fractional *outbuffer);
    //W0: points, W1: *buffer, W2: *outbuffer
    .global _apply_window

_apply_window:
    //save registers
    PUSH	W4				    //save registers
    PUSH	W5
    PUSH	W8
    PUSH	W10
    MOV		W1, W8				    //load pointers to working registers
    MOV		#_window_fn_buffer, W10
    CLR		A, [W8]+=2, W4, [W10], W5	    //clear ACC A and preload data from buffers
    LSR		W0, W0				    //loop #points/2
    SUB		#1, W0
    DO		W0, apply_window_end
    MPY		W4*W5, A, [W8]+=2, W4, [W10]+=2, W5 //multiply, preload and inc pointers
    MOV		ACCAH, W0			    //save result
    MOV		W0, [W2]
    INC2	W2, W2				    //inc result pointer
    MPY		W4*W5, A, [W8]+=2, W4, [W10], W5    //multiply, preload and inc pointers
    MOV		ACCAH, W0			    //save result
apply_window_end:
    MOV		W0, [W2++]			    //store and inc result pointer
    POP		W10				    //restore registers
    POP		W8
    POP		W5
    POP		W4
    RETURN



    .end
