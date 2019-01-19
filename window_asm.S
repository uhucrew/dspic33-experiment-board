    .include "xc.inc"

    .text


    //void apply_window(uint16_t points, fractional *buffer, fractional *outbuffer);
    //W0: points, W1: *buffer, W2: *outbuffer
    .global _apply_window

_apply_window:
    //save registers
    PUSH	W4
    PUSH	W5
    PUSH	W8
    PUSH	W10
    //load pointers to working registers
    MOV		W1, W8
    MOV		#_window_fn_buffer, W10
    //clear ACC A and preload data from buffers
    CLR		A, [W8]+=2, W4, [W10], W5
    //loop #points
    SUB		#1, W0
    DO		W0, apply_window_end
    //multiply, preload and inc pointers
    MPY		W4*W5, A, [W8]+=2, W4, [W10]+=2, W5
    //save result
    MOV		ACCAH, W0
    MOV		W0, [W2]
    //inc result pointer
    INC2	W2, W2
    //multiply, preload and inc pointers
    MPY		W4*W5, A, [W8]+=2, W4, [W10], W5
    //save result
    MOV		ACCAH, W0
    MOV		W0, [W2]
apply_window_end:
    //inc result pointer
    INC2	W2, W2
    //restore registers
    POP		W10
    POP		W8
    POP		W5
    POP		W4
    RETURN



    .end
