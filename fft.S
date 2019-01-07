    .include "xc.inc"

    .text

    //apply window function to buffer
    .global	_apply_window_x
_apply_window:
    RETURN
    //W0: number of points
    //W1: pointer to buffer with data
    //W2: pointer to output buffer
    //W5:W4: pointer to window function
    //W7:W6: result regsiter
    //W3: temporary working register for data
    SUB		#1, W0
    DO		W0, apply_window_end
    MOV		[W2++], W3
    MUL.SU	W6, [W1], W4
    MOV		W5, [W3++]
    MOV		[W2++], W6
    MUL.SU	W6, [W1++], W4
apply_window_end:
    MOV		W5, [W3++]
    RETURN



/*
    .global	_apply_window
_apply_window:
    SUB		#1, W0
    //prefetch registers
    MOV		W2, W8
    MOV		W1, W10
    MOV		W3, W13
    CLR		A, [W8], W5, [W10], W6
    MAC		W5 * W6, B, [W8]+=2, W5, [W10], W6
    DO		W0, apply_window_end
    MAC		W5 * W6, A, [W8]+=2, W5, [W10],    W6, [W13]+=2
    MAC		W5 * W6, B, [W8]+=2, W5, [W10]+=2, W6, [W13]+=2
    CLR		A
    CLR		B
apply_window_end:
    NOP
    RETURN
*/


    .end
