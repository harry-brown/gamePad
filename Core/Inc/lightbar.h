/*
 * lightbar.h
 *
 *  Created on: Nov 2, 2020
 *      Author: harry
 */

#ifndef SRC_LIGHTBAR_H_
#define SRC_LIGHTBAR_H_

#include "stdint.h"
#include "stm32f4xx_hal.h"

void lightbar_update(void);
void lightbar_getStatus(uint16_t* status);
void lightbar_set(uint16_t status);
void lightbar_enable(uint16_t bitsOn);
void lightbar_disable(uint16_t bitsOff);
void lightbar_mask(uint16_t bitMask);

#endif /* SRC_LIGHTBAR_H_ */
