/* 
 * File:   i2c_eep.h
 * Author: main
 *
 * Created on 17. September 2018, 22:19
 */

#ifndef I2C_EEP_H
#define	I2C_EEP_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
#include "i2c_x.h"


//Wichtig fuer Schreibzyklus-Acknowledge-Polling
#define EEP_MAX_ITER    200
#define PAGE_SIZE		64
#define EE_SIZE			32768
#define EE_SIZE_BIT9	512


#define  I2C_ADDR_24LC256       0xA0
#define  I2C_ADDR_FM24CL04      0xA4


uint16_t ee_read_bytes(uint8_t devaddr, uint16_t eeaddr, uint16_t len, uint8_t *buf, bool bit9);
uint16_t ee_write_bytes(uint8_t devaddr, uint16_t eeaddr, uint16_t len, uint8_t *buf, bool bit9);



#ifdef	__cplusplus
}
#endif

#endif	/* I2C_EEP_H */

