    .include "xc.inc"

    //keep in sync with sine.h
    .equ SINE_POINTS,               2048
    .equ SINE_POINTS_2N,            11
    .equ PHASE_ACCU_SHIFT,          (32 - SINE_POINTS_2N)
    .equ PHASE_ACCU_SHIFT_HIGH,     (16 - SINE_POINTS_2N)

    .text

/*
    if (scale == 0) {
        for (i = 0; i < len; i += 2) {
            fractional sine_table_value = sine_table[(uint16_t)(phase_accu>>PHASE_ACCU_SHIFT)];
            dsp_accA = __builtin_mpy(buffer[i], sine_table_value, NULL, NULL, 0, NULL, NULL, 0); 
            buffer[i] = __builtin_sac(dsp_accA, 0);
            dsp_accA = __builtin_mpy(buffer[i+1], sine_table_value, NULL, NULL, 0, NULL, NULL, 0); 
            buffer[i+1] = __builtin_sac(dsp_accA, 0);
            phase_accu += phase_jump;
        }
    }
    else {
        for (i = 0; i < len; i += 2) {
            fractional sine_table_value = sine_table[(uint16_t)(phase_accu>>PHASE_ACCU_SHIFT)];
            dsp_accA = __builtin_mpy(scale, sine_table_value, NULL, NULL, 0, NULL, NULL, 0); 
            fractional sine_table_value_scaled = __builtin_sac(dsp_accA, 0);
            dsp_accA = __builtin_mpy(buffer[i], sine_table_value_scaled, NULL, NULL, 0, NULL, NULL, 0); 
            buffer[i] = __builtin_sac(dsp_accA, 0);
            dsp_accA = __builtin_mpy(buffer[i+1], sine_table_value_scaled, NULL, NULL, 0, NULL, NULL, 0); 
            buffer[i+1] = __builtin_sac(dsp_accA, 0);
            phase_accu += phase_jump;
        }
    }
*/

    //void buffer_multiply_sine(uint16_t len, fractional *buffer, bool mono, uint32_t *phase_jump, fractional scale, uint32_t *phase_accu);
    //W0: buffer size
    //W1: *buffer
    //W2: mono
    //W3: *phase_jump
    //W4: scale
    //W5: *phase_accu

    .global _buffer_multiply_sine_asm

_buffer_multiply_sine_asm:
    PUSH	W6					//save registers
    PUSH	W7
    PUSH	W8
    PUSH	W9
    PUSH	W10
    PUSH	W11
    PUSH	W12

    MOV		[W3++], W9				//load phase jump low
    MOV		[W3--], W10				//load phase jump high
    MOV		W1, W8					//load input pointer
    MOV		W1, W3					//load output pointer
    MOV		[W5++], W7				//load phase accu low
    MOV		[W5--], W1				//load phase accu high
    PUSH	W5
    MOV		#_sine_table, W11			//sine_table eds offset
    LSR		W1, #PHASE_ACCU_SHIFT_HIGH, W12		//shift to get sine table offset
    SL		W12, W12				//two bytes per index
    CLR		A, [W8]+=2, W5, [W11+W12], W6		//clear ACC A and preload data from buffers
    SUB		#1, W0					//loop #len
    BTSC	W2, #0
    BRA		buffer_multiply_sine_mono
    LSR		W0, #1, W0				//loop for half length (two channels per loop)
  DO		W0, buffer_multiply_sine_stereo_end
    ADD		W9, W7, W7				//add 32bit phase_accu low 16bit
    ADDC	W10, W1, W1				//add 32bit phase_accu high 16bit
    LSR		W1, #PHASE_ACCU_SHIFT_HIGH, W12		//shift to get sine table offset
    SL		W12, W12				//two bytes per index
    MPY		W5 * W6, A				//multiply left channel with sine
    MOV		ACCAH, W5				//load temporary result
    MPY		W4 * W5, A, [W8]+=2, W5			//multiply with scale factor, preload next channel
    MOV		ACCAH, W0				//save result
    MOV		W0, [W3++]				//store at result pointer
    MPY		W5 * W6, A				//multiply left channel with sine
    MOV		ACCAH, W5				//load temporary result
    MPY		W4 * W5, A, [W8]+=2, W5, [W11+W12], W6	//multiply with scale factor, preload next channel and sine
    MOV		ACCAH, W0				//save result
buffer_multiply_sine_stereo_end:
    MOV		W0, [W3++]				//store at result pointer
    BRA		buffer_multiply_sine_exit

buffer_multiply_sine_mono:
  DO		W0, buffer_multiply_sine_mono_end
    ADD		W9, W7, W7				//add 32bit phase_accu low 16bit
    ADDC	W10, W1, W1				//add 32bit phase_accu high 16bit
    LSR		W1, #PHASE_ACCU_SHIFT_HIGH, W12		//shift to get sine table offset
    SL		W12, W12				//two bytes per index
    MPY		W5 * W6, A				//multiply left channel with sine
    MOV		ACCAH, W5				//load temporary result
    MPY		W4 * W5, A, [W8]+=2, W5, [W11+W12], W6	//multiply with scale factor, preload next channel and sine
    MOV		ACCAH, W0				//save result
buffer_multiply_sine_mono_end:
    MOV		W0, [W3++]				//store at result pointer

buffer_multiply_sine_exit:
    POP		W5
    MOV		W7, [W5++]				//save phase accu low
    MOV		W1, [W5--]				//save phase accu high
    POP		W12					//restore registers
    POP		W11
    POP		W10
    POP		W9
    POP		W8
    POP		W7
    POP		W6
    RETURN


    .global _buffer_put_sine_asm

_buffer_put_sine_asm:
    PUSH	W6					//save registers
    PUSH	W7
    PUSH	W8
    PUSH	W9
    PUSH	W10
    PUSH	W11
    PUSH	W12

    MOV		[W5++], W7				//load phase accu low
    MOV		[W5--], W8				//load phase accu high
    MOV		[W3++], W9				//load phase jump low
    MOV		[W3--], W10				//load phase jump high
    MOV		#_sine_table, W11			//sine_table eds offset
    LSR		W8, #PHASE_ACCU_SHIFT_HIGH, W12		//shift to get sine table offset
    SL		W12, W12				//two bytes per index
    CLR		A, [W11+W12], W6			//clear ACC A and preload data from buffers
    SUB		#1, W0					//loop #len
    BTSC	W2, #0
    BRA		buffer_put_sine_mono
    LSR		W0, #1, W0				//loop for half length (two channels per loop)
  DO		W0, buffer_put_sine_stereo_end
    ADD		W9, W7, W7				//add 32bit phase_accu low 16bit
    ADDC	W10, W8, W8				//add 32bit phase_accu high 16bit
    LSR		W8, #PHASE_ACCU_SHIFT_HIGH, W12		//shift to get sine table offset
    SL		W12, W12				//two bytes per index
    MPY		W4 * W6, A, [W11+W12], W6		//multiply left channel with scale value, preload
    MOV		ACCAH, W0				//save result
    MOV		W0, [W1++]				//store at result pointer
buffer_put_sine_stereo_end:
    MOV		W0, [W1++]				//second channel
    BRA		buffer_put_sine_exit

buffer_put_sine_mono:
  DO		W0, buffer_put_sine_mono_end
    LSR		W8, #PHASE_ACCU_SHIFT_HIGH, W12		//shift to get sine table offset
    SL		W12, W12				//two bytes per index
    MPY		W4 * W6, A, [W11+W12], W6		//multiply left channel with scale value, preload
    MOV		ACCAH, W0				//save result
    MOV		W0, [W1++]				//store at result pointer
    ADD		W9, W7, W7				//add 32bit phase_accu low 16bit
buffer_put_sine_mono_end:
    ADDC	W10, W8, W8				//add 32bit phase_accu high 16bit, reset pointer

buffer_put_sine_exit:
    MOV		W7, [W5++]				//save phase accu low
    MOV		W8, [W5--]				//save phase accu high
    POP		W12					//restore registers
    POP		W11
    POP		W10
    POP		W9
    POP		W8
    POP		W7
    POP		W6
    RETURN



    .end
