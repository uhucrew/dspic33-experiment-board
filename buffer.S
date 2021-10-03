    .include "xc.inc"
    .include "defines.h"

    .text

    //copy buffer to buffer
    //void buffer_copy(uint16_t length, uint16_t *buffer, uint16_t *outbuffer);
    .global	_buffer_copy
_buffer_copy:
    PUSH	W3
    SUB		#1, W0
  DO		W0, buffer_copy_end
    MOV		[W1++], W3
buffer_copy_end:
    MOV		W3, [W2++]
    POP		W3
    RETURN

    //copy buffer to buffer, increment pointer by offset
    //void buffer_copy_offset(uint16_t length, uint16_t offset, uint16_t *buffer, uint16_t *outbuffer);
    .global	_buffer_copy_offset
_buffer_copy_offset:
    SUB		#1, W0
  DO		W0, buffer_copy_offset_loop
    MOV		[W2], [W3++]
buffer_copy_offset_loop:
    ADD		W1, W2, W2
    RETURN

    //copy buffer to buffer, increment pointer by offset
    //void buffer_copy_offset(uint16_t length, uint16_t offset, uint16_t *buffer, uint16_t *outbuffer);
    .global	_buffer_copy_offset_sum
_buffer_copy_offset_sum:
    PUSH	W4				    //save registers
    PUSH	W5
    PUSH	W8
    PUSH	W10
    MOV		W2, W10
    SUB		#1, W0
  DO		W0, buffer_copy_offset_sum_loop
    MOVSAC	A, [W8], W4, [W10], W5		    //clear ACC A and preload data from buffers
    MOV		W5, [W3++]
buffer_copy_offset_sum_loop:
    ADD		W1, W10, W10
    POP		W10				    //restore registers
    POP		W8
    POP		W5
    POP		W4
    RETURN


    //copy ad buffer to fractional buffer for fft
    //void buffer_copy_ad_fractional(uint16_t length, fractional *buffer, fractional *outbuffer, bool mono);
    .global	_buffer_copy_ad_fractional
_buffer_copy_ad_fractional:
    PUSH	W4				    //save registers
    PUSH	W5
    PUSH	W6
    PUSH	W7
    MOV		#0x3FFF, W4
    MOV		#0xC000, W5
    SUB		#1, W0
  DO		W0, buffer_copy_ad_fractional_loop
    BTSC	[W1], #0xE
    AND		W4, [W1++], W6
    BTSS	[W1], #0xE
    IOR		W5, [W1++], W6
    CP0.B	W3				    //mono? 00 -> false -> add 2 samples and div /2
    BRA		NZ, buffer_copy_ad_fractional_loop
    BTSC	[W1], #0xE
    AND		W4, [W1++], W7
    BTSS	[W1], #0xE
    IOR		W5, [W1++], W7
    ADD		W6, W7, [W2]
    ASR		[W2], W6
buffer_copy_ad_fractional_loop:
    MOV		W6, [W2++]
    POP		W7
    POP		W6
    POP		W5
    POP		W4
    RETURN



    //copy buffer to buffer
    //void convert_samplerate(uint16_t length, uint16_t samplerate_ratio, uint16_t input32bit, uint16_t *buffer);
    .global	_convert_samplerate
_convert_samplerate:
    PUSH	W4				    //save registers
    PUSH	W5
    SL		W1, W1				    //calculate offset of input pointer per loop
    MOV		W0, W4				    //save length
    MOV		W1, W5				    //save samplerate_ratio
    REPEAT	#17				    //needed for DIV
    DIV.U	W4, W5				    //calculate number of loops
    SUB		#1, W0				    //loop W0 times
    MOV		W5, W1				    //restore samplerate_ratio
    SL		W1, W1				    //calculate offset of input pointer per loop
    SUB		#4, W1
    BTSC	W2, #0				    //if 32bit input, decrease offset by 2
    SUB		#4, W1
    MOV		_spi_da_ptr, W4			    //restore current output pointer
    MOV		_spi_da_buffer_end, W5		    //load buffer end address for compare
  DO		W0, convert_samplerate_end
    MOV		[W3++], [W4++]			    //left high word
    BTSC	W2, #0				    //left low word
    MOV		[W3++], [W4++]
    BTSS	W2, #0
    CLR		[W4++]
    MOV		[W3++], [W4++]			    //right high word
    BTSC	W2, #0				    //right low word
    MOV		[W3++], [W4++]
    BTSS	W2, #0
    CLR		[W4++]
    CPSNE	W5, W4				    //da buffer end reached?
    MOV		#_spi_da_buffer_0, W4		    //reset output buffer pointer
convert_samplerate_end:
    ADD		W1, W3, W3
    MOV		W4, _spi_da_ptr
    POP		W5
    POP		W4
    RETURN


    //scale buffer inplace
    //void scale_buffer(uint16_t length, fractional *buffer, fractional ad_max_factor);
    .global	_scale_buffer
_scale_buffer:
    PUSH	W4				    //save registers
    PUSH	W5
    PUSH	W8
    MOV		W1, W8				    //load pointers to working registers
    MOV		W2, W5				    //load factor
    CLR		A, [W8]+=2, W4			    //clear ACC A and preload data from buffer
    SUB		#1, W0				    //loop W0 times
  DO		W0, scale_buffer_end
    MPY		W4 * W5, A, [W8]+=2, W4		    //multiply, preload and inc pointers
    MOV		ACCAL, W0			    //save result
scale_buffer_end:
    MOV		W0, [W1++]			    //store at result pointer
    POP		W8
    POP		W5
    POP		W4
    RETURN


    .end
