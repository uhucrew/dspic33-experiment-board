    .include "xc.inc"

    .text

    //copy buffer to buffer
    //void buffer_copy(uint16_t length, uint16_t *buffer, uint16_t *outbuffer);
    .global	_buffer_copy
_buffer_copy:
    SUB		#1, W0
    DO		W0, buffer_copy_end
    MOV		[W1], [W2]
    INC2	W1, W1
buffer_copy_end:
    INC2	W2, W2
    RETURN


    //copy buffer to buffer
    //void convert_samplerate(uint16_t length, uint16_t samplerate_ratio, uint16_t *buffer, uint16_t *outbuffer);
    .global	_convert_samplerate
_convert_samplerate:
    SL		W1, W1
    SUB		#1, W1
    SUB		#1, W0
    DO		W0, convert_samplerate_end
    MOV		[W2++], [W3++]
    CLR		[W3++]
    MOV		[W2], [W3++]
    CLR		[W3++]
convert_samplerate_end:
    ADD		W1, W2, W2
    RETURN
