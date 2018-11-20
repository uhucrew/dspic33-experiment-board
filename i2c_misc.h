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


#define  I2C_ADDR_MAX5387       0x50
#define  I2C_MAX5387_REG_A      0x11
#define  I2C_MAX5387_REG_B      0x12
#define  I2C_MAX5387_REG_AB     0x13


bool set_volume(uint8_t devaddr, uint8_t vol);



#ifdef	__cplusplus
}
#endif

#endif	/* I2C_MISC_H */

