/* 
 * File:   i2c.h
 * Author: main
 *
 * Created on 17. September 2018, 21:42
 */

#ifndef I2C_H
#define	I2C_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <xc.h>

//1ms timeout for I2C transactions
#define I2C_TIMEOUT         1

#define I2C_READ            1
#define I2C_WRITE           0
#define I2C_ACK             0
#define I2C_NACK            1
#define I2C_WAIT_US_DEFAULT 1000000
#define I2C_WAIT_US_LONG    5000000


void I2C2_init(void);
uint8_t I2C2_idle(uint32_t max_wait_us);
uint8_t I2C2_start(uint32_t max_wait_us);
uint8_t I2C2_rep_start(uint32_t max_wait_us);
uint8_t I2C2_stop(uint32_t max_wait_us);
uint8_t I2C2_dev_access(uint8_t device_addr, uint32_t max_wait_us);
uint8_t I2C2_write(uint8_t data, bool acknowledge, uint32_t max_wait_us);
uint8_t I2C2_read(uint8_t *data, bool acknowledge, uint32_t max_wait_us);


#ifdef	__cplusplus
}
#endif

#endif	/* I2C_H */

