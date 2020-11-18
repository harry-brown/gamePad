/*
 * buttons.c
 *
 *  Created on: 2 Nov 2020
 *      Author: harry
 */

#include "buttons.h"

uint16_t rawButtonStatus = 0;
uint16_t debouncedButtonStatus = 0;
uint16_t lastDebouncedButtonStatus = 0;
uint16_t buttonChange = 0;
uint16_t buttonBuffer = 0;

uint8_t debounceArray[10] = {0};
uint8_t longPressArray[10] = {0};

void buttons_update(void)
{
	rawButtonStatus = ~((GPIOA->IDR & (GPIO_PIN_7 | GPIO_PIN_6 | GPIO_PIN_5 | GPIO_PIN_4)) << 2) &
			  	  	  ~((GPIOA->IDR & (GPIO_PIN_1)) << 4) &
					  ~((GPIOB->IDR & (GPIO_PIN_9 | GPIO_PIN_8 | GPIO_PIN_7 | GPIO_PIN_6 | GPIO_PIN_5)) >> 5);

	for (int i = 0; i < 10; i++)
	{
		debounceArray[i] = (rawButtonStatus & (1 << i) ? min(debounceArray[i] + 1, DEBOUNCE + 1) : 0);
		debouncedButtonStatus |= (debounceArray[i] > DEBOUNCE ? 1 << i : 0);
		debouncedButtonStatus &= (debounceArray[i] == 0 ? ~(1 << i) : ~0);
	}

	buttonBuffer |= debouncedButtonStatus;

	buttonChange = debouncedButtonStatus ^ lastDebouncedButtonStatus;
	lastDebouncedButtonStatus = debouncedButtonStatus;
}

void buttons_getStatus(uint16_t* status)
{
	*status = debouncedButtonStatus;
}

void buttons_getChanged(uint16_t* status)
{
	static uint16_t lastReportedStatus = 0;

	*status = buttonBuffer ^ lastReportedStatus;

	buttonBuffer = 0;
	lastReportedStatus = debouncedButtonStatus;
}

void buttons_process(void)
{
	if (buttonChange)
	{
		if (buttonChange & (1 << 9))
		{
			//LEFT
		}
		if (buttonChange & (1 << 9))
		{
			//LEFT
		}
	}
}

