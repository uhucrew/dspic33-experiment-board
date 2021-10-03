/* 
 * File:   i2c_eep.h
 * Author: main
 *
 * Created on 17. September 2018, 22:19
 */

#ifndef I2C_MISC_H
#define	I2C_MISC_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
#include "i2c_x.h"


//addresses and functions for MAX5387
#define  I2C_ADDR_MAX5387       0x50
#define  I2C_MAX5387_REG_A      0x11
#define  I2C_MAX5387_REG_B      0x12
#define  I2C_MAX5387_REG_AB     0x13

void I2C_enable_analog(bool enable);

bool MAX5387_set_volume(uint8_t devaddr, uint8_t vol);

//addresses and functions for ADG715
#define  I2C_ADDR_ADG715        0x90

bool ADG715_get_switches(uint8_t devaddr, uint8_t *switches_val);
bool ADG715_set_switches(uint8_t devaddr, uint8_t switches_val);
bool ADG715_get_switch(uint8_t devaddr, uint8_t switch_num, bool *switch_val);
bool ADG715_set_switch(uint8_t devaddr, uint8_t switch_num, bool switch_val);
bool ADG715_switch_line_in(uint8_t devaddr);
bool ADG715_switch_mic_in(uint8_t devaddr);
bool ADG715_switch_memsmic_in(uint8_t devaddr);
bool ADG715_switch_gnd(uint8_t devaddr);


//addresses and functions for AD5254 4x potentiometer
#define  I2C_ADDR_AD5254        0x58

bool AD5254_set_pot(uint8_t devaddr, uint8_t pot_num, uint8_t *pot_val, uint8_t pot_count);
bool AD5254_get_pot(uint8_t devaddr, uint8_t pot_num, uint8_t *pot_val, uint8_t pot_count);
bool AD5254_set_mics(uint8_t devaddr, uint8_t first_mic, int32_t *pot_val);
bool AD5254_set_mic_vol(uint8_t devaddr, int32_t *pot_val);
bool AD5254_set_mems_mic_vol(uint8_t devaddr, int32_t *pot_val);
bool AD5254_get_mics(uint8_t devaddr, uint8_t first_mic, int32_t *pot_val);
bool AD5254_get_mic_vol(uint8_t devaddr, int32_t *pot_val);
bool AD5254_get_mems_mic_vol(uint8_t devaddr, int32_t *pot_val);
bool AD5254_store(uint8_t devaddr, uint8_t pot_num, uint8_t *pot_val, uint8_t pot_count);
bool AD5254_save(uint8_t devaddr, uint8_t pot_num, uint8_t pot_count);
bool AD5254_restore(uint8_t devaddr);


#ifdef	__cplusplus
}
#endif

#endif	/* I2C_MISC_H */

