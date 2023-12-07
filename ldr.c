/*
 * ldr.c
 *
 *  Created on: Dec 3, 2023
 *      Author: user
 */

#include "ldr.h"
#include <stdint.h>


void Init_ldr(void)
{
	GPIO_PinConfig_t PIN_ldr;
	PIN_ldr.GPIO_MODE = GPIO_MODE_ANALOG;
	PIN_ldr.GPIO_Output_Speed = GPIO_SPEED_10M;
	PIN_ldr.GPIO_PinNumber = GPIO_PIN_1;
	MCAL_GPIO_Init(GPIOA,&PIN_ldr);

	adc_init();

}
uint16_t Read_ldr(uint8_t channel_num)
{
	uint16_t digital_value;
	uint16_t percentage;
	digital_value=	adc_read(channel_num);
	percentage=100-(digital_value*100/ADC_MAXIMUM_VALUE);


	return percentage;
}
