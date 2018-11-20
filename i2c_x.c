#include <stdbool.h>
#include <xc.h>
#include <p33EP512MC202.h>

#include "defines.h"
#include "timer_x.h"
#include "i2c_x.h"


void I2C2_init(void)
{
    //disable I2C to use outputs for bitbang
    I2C2CONbits.I2CEN = 0;
    //RB5/RB6 = 1, output with open drain
    _LATB5 = 1;
    _LATB6 = 1;
    _TRISB5 = 0;
    _TRISB6 = 0;
    _ODCB5 = 1;
    _ODCB6 = 1;

    uint8_t i;
    //send 10 clock pulses
    for (i = 0; i < 10; i++) {
        LATBbits.LATB6 = 0;
        timer_delay_us(10);
        LATBbits.LATB6 = 1;
        timer_delay_us(10);
    }
    _TRISB5 = 1;
    _TRISB6 = 1;

    I2C2BRG = (uint16_t)I2CBRG_DEF;
    I2C2CONbits.DISSLW = 1;
    //Enable I2C2 module
    I2C2CONbits.I2CEN = 1;
}

uint8_t I2C2_idle(uint32_t max_wait_us)
{
    //wait for finished master operation
    wait_us_for_register_bits(&I2C2STAT, _I2C2STAT_TRSTAT_MASK, false, max_wait_us);
    return wait_us_for_register_bits(&I2C2CON,
        _I2C2CON_SEN_MASK || _I2C2CON_RSEN_MASK || _I2C2CON_PEN_MASK || _I2C2CON_RCEN_MASK || _I2C2CON_ACKEN_MASK,
        false, max_wait_us);
}

uint8_t I2C2_start(uint32_t max_wait_us)
{
    I2C2CONbits.SEN = 1;
    return wait_us_for_register_bits(&I2C2CON, _I2C2CON_SEN_MASK, false, max_wait_us);
}

uint8_t I2C2_rep_start(uint32_t max_wait_us)
{
    I2C2CONbits.RSEN = 1;
    return wait_us_for_register_bits(&I2C2CON, _I2C2CON_RSEN_MASK, false, max_wait_us);
}

uint8_t I2C2_stop(uint32_t max_wait_us)
{
    I2C2CONbits.PEN = 1;
    I2C2CONbits.RCEN = 0;
    return I2C2_idle(max_wait_us);
}

uint8_t I2C2_dev_access(uint8_t device_addr, uint32_t max_wait_us)
{
    return I2C2_write(device_addr, I2C_ACK, max_wait_us);
}

uint8_t I2C2_write(uint8_t data, bool acknowledge, uint32_t max_wait_us)
{
    I2C2TRN = data;
    wait_us_for_register_bits(&I2C2STAT, _I2C2STAT_TRSTAT_MASK, false, max_wait_us);
    //wait 20us for bus idle
    I2C2_idle(20);
    //return true if ACKSTAT is expected acknowledge
    return I2C2STATbits.ACKSTAT == acknowledge ? 1 : 0;
}

uint8_t I2C2_read(uint8_t *data, bool acknowledge, uint32_t max_wait_us)
{
    I2C2CONbits.RCEN = 1;
    wait_us_for_register_bits(&I2C2CON, _I2C2CON_RCEN_MASK, false, max_wait_us);
    wait_us_for_register_bits(&I2C2STAT, _I2C2STAT_RBF_MASK, true, max_wait_us);
    //clear overflow error
    I2C2STATbits.I2COV = 0;
    *data = I2C2RCV;

    I2C2CONbits.ACKDT = acknowledge;
    I2C2CONbits.ACKEN = 1;
    //wait for finished ACK cycle
    wait_us_for_register_bits(&I2C2CON, _I2C2CON_ACKEN_MASK, false, max_wait_us);
    //wait for finished master operation
    wait_us_for_register_bits(&I2C2STAT, _I2C2STAT_TRSTAT_MASK, false, max_wait_us);
    //wait 20us for bus idle
    I2C2_idle(20);
    return 1;
}
