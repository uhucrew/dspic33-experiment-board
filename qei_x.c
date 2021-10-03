#include <stdbool.h>
#include <xc.h>
#include <p33EP512MC202.h>

#include "defines.h"
#include "qei_x.h"
#include "pps.h"
#include "cni.h"


uint32_t qei_cnt = 0;
uint8_t qei_push_cnt = 0;

uint16_t qei_pb_fn() {
    qei_cnt = ((uint32_t)POS1CNTH<<16) + POS1CNTL;
    qei_push_cnt++;
    return 0;
}

void QEI_init() {
    //disable qei
    _QEIEN = 0;

    //attach RPI46/47 to QEI module
    _QEA1R = _RPI47;
    _QEB1R = _RPI46;

    //continue while sleep
    _QEISIDL = 0;
    POS1CNTH = 0;                // Reset position counter
    POS1CNTL = 0;                // Reset position counter
    _QEIEN = 1;

    //disable CN interrupts
    _CNIE = 0;
    rb13_cn_fn = qei_pb_fn;
    //enable int on RB13
    CNENBbits.CNIEB13 = 1;
    //enable CN interrupts
    _CNIE = 1;
    //clear interrupt flag
    _CNIF = 0;

}
