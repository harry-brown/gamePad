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

enum button {
	buttonA,
	buttonX,
	buttonB,
	buttonY,
	buttonP,
	buttonM,
	buttonR,
	buttonU,
	buttonD,
	buttonL
};

void buttons_update(void);
void buttons_getStatus(uint16_t* status);
void buttons_getChanged(uint16_t* status);
void buttons_process(void);

#endif /* INC_BUTTONS_H_ */
