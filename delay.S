    .include "xc.inc"
    .include "defines.h"

    .text

/*#define DELAY_105uS asm volatile ("REPEAT, #4201"); Nop(); // 105uS delay*/
    .global _delay_us
_delay_us:
    nop
    return

    .global _delay_ms
_delay_ms:
    repeat  #FCY_US
    nop
    ;call    _delay_us
    return

    .end

//    dec     w0,w0
//   bra     NZ,delay_us
