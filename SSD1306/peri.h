/*******************************************************************************
 * File:        peri.h
 * Project:     SP18 - I2C OLED Display
 * Author:      Nicolas Pannwitz
 * Version:     
 * Web:         http://pic-projekte.de
 ******************************************************************************/

#ifndef PERI_H
#define	PERI_H

#include <stdint.h>

/*******************************************************************************
 * Prototypen
 */

void initI2C(void);
void startI2C(void);
void restartI2C(void);
void stopI2C(void);
void idleI2C(void);
uint8_t sendI2C(uint8_t byte);
uint8_t reciveI2C_nack(void);
uint8_t reciveI2C_ack(void);
void waitI2C(void);

#endif	/* PERI_H */