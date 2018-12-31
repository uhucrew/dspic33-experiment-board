    .include "xc.inc"

    .text

    //copy buffer to buffer
    //extern void buffer_copy(uint16_t *buffer, uint16_t *outbuffer);
    .global	_buffer_copy
_buffer_copy:
    RETURN