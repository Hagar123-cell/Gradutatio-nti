/*
 * Rain_Sensor.c
 *
 *  Created on: Dec 5, 2023
 *      Author: user
 */

#include "Rain_Sensor.h"

void Init_Rain(void)
{
	GPIO_PinConfig_t PIN_Rain;
	PIN_Rain.GPIO_MODE = GPIO_MODE_ANALOG;
	PIN_Rain.GPIO_Output_Speed = GPIO_SPEED_10M;
	PIN_Rain.GPIO_PinNumber = GPIO_PIN_2;
	MCAL_GPIO_Init(GPIOA,&PIN_Rain);

	adc_init();

}
uint16_t Read_Rain(uint8_t channel_num)
{
	uint16_t digital_value;
	uint16_t percentage;
	digital_value=	adc_read(channel_num);
	percentage=(digital_value*100/ADC_MAXIMUM_VALUE);

	return percentage;
}

