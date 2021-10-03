#include <stdbool.h>

#include "i2c_x.h"
#include "i2c_misc.h"


void I2C_enable_analog(bool enable) {
    LATBbits.LATB9 = enable ? 1 : 0;
}


bool MAX5387_set_volume(uint8_t devaddr, uint8_t vol) {
    bool result;

    I2C_enable_analog(true);
    if (I2C2_start(I2C_WAIT_US_DEFAULT) &&
        I2C2_dev_access(devaddr | I2C_WRITE, I2C_WAIT_US_DEFAULT) &&
        I2C2_write(I2C_MAX5387_REG_AB, I2C_ACK, I2C_WAIT_US_DEFAULT) &&
        I2C2_write(vol, I2C_ACK, I2C_WAIT_US_DEFAULT) )
    {
        result = true;
    }
    else {
        result = false;
    }

    I2C2_stop(I2C_WAIT_US_LONG);
    I2C_enable_analog(false);
    return result;
}

//functions for ADG715 8 SPST switch

bool ADG715_get_switches(uint8_t devaddr, uint8_t *switches_val) {
    bool result;

    I2C_enable_analog(true);
    if (I2C2_start(I2C_WAIT_US_DEFAULT) &&
        I2C2_dev_access(devaddr, I2C_WAIT_US_DEFAULT) &&
        I2C2_read(switches_val, I2C_ACK, I2C_WAIT_US_DEFAULT) )
    {
        result = true;
    }
    else {
        result = false;
    }

    I2C2_stop(I2C_WAIT_US_LONG);
    I2C_enable_analog(false);
    return result;
}

bool ADG715_set_switches(uint8_t devaddr, uint8_t switches_val) {
    bool result;

    I2C_enable_analog(true);
    if (I2C2_start(I2C_WAIT_US_DEFAULT) &&
        I2C2_dev_access(devaddr | I2C_WRITE, I2C_WAIT_US_DEFAULT) &&
        I2C2_write(switches_val, I2C_ACK, I2C_WAIT_US_DEFAULT) )
    {
        result = true;
    }
    else {
        result = false;
    }

    I2C2_stop(I2C_WAIT_US_LONG);
    I2C_enable_analog(false);
    return result;
}

bool ADG715_get_switch(uint8_t devaddr, uint8_t switch_num, bool *switch_val) {
    bool result;
    uint8_t switch_tmp;

    if (switch_num > 7) return false;

    result = ADG715_get_switches(devaddr, &switch_tmp);
    *switch_val = switch_tmp & (1 << switch_num);

    return result;
}

bool ADG715_set_switch(uint8_t devaddr, uint8_t switch_num, bool switch_val) {
    bool result;
    uint8_t switch_tmp;

    if (switch_num > 7) return false;

    result = ADG715_get_switches(devaddr, &switch_tmp);
    switch_tmp &= ~(1 << switch_num);
    switch_tmp |=  (1 << switch_num);

    return result | ADG715_set_switches(devaddr, switch_tmp);
}

bool ADG715_switch_line_in(uint8_t devaddr) {
    return ADG715_set_switches(devaddr, 0b10000001);
}

bool ADG715_switch_mic_in(uint8_t devaddr) {
    return ADG715_set_switches(devaddr, 0b01000010);
}

bool ADG715_switch_memsmic_in(uint8_t devaddr) {
    return ADG715_set_switches(devaddr, 0b00100100);
}

bool ADG715_switch_gnd(uint8_t devaddr) {
    return ADG715_set_switches(devaddr, 0b00011000);
}


// functions for AD5254 4x potentiometer

bool AD5254_set_pot(uint8_t devaddr, uint8_t pot_num, uint8_t *pot_val, uint8_t pot_count) {
    bool result;
    uint8_t i;

    I2C_enable_analog(true);
    if (I2C2_start(I2C_WAIT_US_DEFAULT) &&
        I2C2_dev_access(devaddr | I2C_WRITE, I2C_WAIT_US_DEFAULT) &&
        I2C2_write(pot_num & 0xf, I2C_ACK, I2C_WAIT_US_DEFAULT) )
    {
        result = true;
    }
    else {
        result = false;
    }
    for (i = 0; i < pot_count % 4; i++) {
        result &= I2C2_write(pot_val[i], I2C_ACK, I2C_WAIT_US_DEFAULT);
    }

    I2C2_stop(I2C_WAIT_US_LONG);
    I2C_enable_analog(false);
    return result;
}

bool AD5254_get_pot(uint8_t devaddr, uint8_t pot_num, uint8_t *pot_val, uint8_t pot_count) {
    bool result;
    uint8_t i;

    I2C_enable_analog(true);
    if (I2C2_start(I2C_WAIT_US_DEFAULT) &&
        I2C2_dev_access(devaddr, I2C_WAIT_US_DEFAULT) &&
        I2C2_write((pot_num & 0xf) | 0x20, I2C_ACK, I2C_WAIT_US_DEFAULT) &&
        I2C2_rep_start(I2C_WAIT_US_DEFAULT) &&
        I2C2_dev_access(devaddr, I2C_WAIT_US_DEFAULT) )
    {
        result = true;
    }
    else {
        result = false;
    }
    for (i = 0; i < pot_count % 16; i++) {
        result &= I2C2_read(&pot_val[i], I2C_ACK, I2C_WAIT_US_DEFAULT);
    }

    I2C2_stop(I2C_WAIT_US_LONG);
    I2C_enable_analog(false);
    return result;
}

bool AD5254_set_mics(uint8_t devaddr, uint8_t first_mic, int32_t *pot_val) {
    uint8_t pot_tmp[2];
    uint8_t i;

    for (i = 0; i < 2; i++) {
        pot_tmp[i] = (uint8_t)(255 - pot_val[i]);
    }
    return AD5254_set_pot(devaddr, first_mic, pot_tmp, 2);
}

bool AD5254_set_mic_vol(uint8_t devaddr, int32_t *pot_val) {
    return AD5254_set_mics(devaddr, 0, pot_val);
}

bool AD5254_set_mems_mic_vol(uint8_t devaddr, int32_t *pot_val) {
    return AD5254_set_mics(devaddr, 2, pot_val);
}

bool AD5254_get_mics(uint8_t devaddr, uint8_t first_mic, int32_t *pot_val) {
    uint8_t pot_tmp[2];
    bool result;
    uint8_t i;

    result = AD5254_get_pot(devaddr, first_mic, pot_tmp, 2);
    for (i = 0; i < 2; i++) {
        pot_val[i] = (int32_t)(255 - pot_tmp[i]);
    }

    return result;
}

bool AD5254_get_mic_vol(uint8_t devaddr, int32_t *pot_val) {
    return AD5254_get_mics(devaddr, 0, pot_val);
}

bool AD5254_get_mems_mic_vol(uint8_t devaddr, int32_t *pot_val) {
    return AD5254_get_mics(devaddr, 2, pot_val);
}

//store RDAC or user data to EEMEM
//pot_num 0..3: RDAC 0..3   pot_num 4..15: user data
bool AD5254_store(uint8_t devaddr, uint8_t pot_num, uint8_t *pot_val, uint8_t pot_count) {
    bool result;
    uint8_t i;

    I2C_enable_analog(true);
    if (I2C2_start(I2C_WAIT_US_DEFAULT) &&
        I2C2_dev_access(devaddr | I2C_WRITE, I2C_WAIT_US_DEFAULT) &&
        I2C2_write((pot_num & 0xf) | 0x20, I2C_ACK, I2C_WAIT_US_DEFAULT) &&
        I2C2_rep_start(I2C_WAIT_US_DEFAULT) &&
        I2C2_dev_access(devaddr, I2C_WAIT_US_DEFAULT) )
    {
        result = true;
    }
    else {
        result = false;
    }
    for (i = 0; i < pot_count % 16; i++) {
        result &= I2C2_write(pot_val[i], I2C_ACK, I2C_WAIT_US_DEFAULT);
    }

    I2C2_stop(I2C_WAIT_US_LONG);
    I2C_enable_analog(false);
    return result;
}

//save RDAC setting in EEMEM
bool AD5254_save(uint8_t devaddr, uint8_t pot_num, uint8_t pot_count) {
    bool result;
    uint8_t i;

    I2C_enable_analog(true);
    if (I2C2_start(I2C_WAIT_US_DEFAULT) &&
        I2C2_dev_access(devaddr, I2C_WAIT_US_DEFAULT) )
    {
        result = true;
    }
    else {
        result = false;
    }
    for (i = 0; i < pot_count % 4; i++) {
        result &= I2C2_write(0x80 | 0x10 | pot_num % 4, I2C_ACK, I2C_WAIT_US_LONG);
    }

    I2C2_stop(I2C_WAIT_US_LONG);
    I2C_enable_analog(false);
    return result;
}

//restore all RDACs from EEMEM
bool AD5254_restore(uint8_t devaddr) {
    bool result;

    I2C_enable_analog(true);
    if (I2C2_start(I2C_WAIT_US_DEFAULT) &&
        I2C2_dev_access(devaddr, I2C_WAIT_US_DEFAULT) &&
        I2C2_write(0x80 | 0x38, I2C_ACK, I2C_WAIT_US_DEFAULT) )
    {
        result = true;
    }
    else {
        result = false;
    }

    I2C2_stop(I2C_WAIT_US_LONG);
    I2C_enable_analog(false);
    return result;
}
