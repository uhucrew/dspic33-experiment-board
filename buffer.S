    .include "xc.inc"
    .include "defines.h"

    .text

    //copy buffer to buffer
    //void buffer_copy(uint16_t length, uint16_t *buffer, uint16_t *outbuffer);
    .global	_buffer_copy
_buffer_copy:
    SUB		#1, W0
    REPEAT	W0
    MOV		[W1++], [W2++]
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
    //left high word
    MOV		[W3++], [W4++]
    //left low word
    BTSC	W2, #0
    MOV		[W3++], [W4++]
    BTSS	W2, #0
    CLR		[W4++]
    //right high word
    MOV		[W3++], [W4++]
    //right low word
    BTSC	W2, #0
    MOV		[W3++], [W4++]
    BTSS	W2, #0
    CLR		[W4++]
    //da buffer end reached?
    CPSNE	W5, W4
    //reset output buffer pointer
    MOV		#_spi_da_buffer_0, W4
convert_samplerate_end:
    ADD		W1, W3, W3
    MOV		W4, _spi_da_ptr
    POP		W5
    POP		W4
    RETURN



    .end
