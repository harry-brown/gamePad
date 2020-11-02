/*
 * buttons.h
 *
 *  Created on: 2 Nov 2020
 *      Author: harry
 */

#ifndef INC_BUTTONS_H_
#define INC_BUTTONS_H_

#include "stdint.h"
#include "stm32f4xx_hal.h"

#define DEBOUNCE 3

#define max(a,b) ( a > b ? a : b )
#define min(a,b) ( a > b ? b : a )

void lightbar_update(void);
void lightbar_getStatus(uint16_t* status);

#endif /* INC_BUTTONS_H_ */
