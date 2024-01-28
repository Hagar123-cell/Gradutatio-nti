/*
 * LM35.c
 *
 *  Created on: Nov 30, 2023
 *      Author: user
 */

#include "LM35.h"
#include <stdint.h>


void Init_temp(void)
{
	GPIO_PinConfig_t PIN_temp;
	PIN_temp.GPIO_MODE = GPIO_MODE_ANALOG;
	PIN_temp.GPIO_Output_Speed = GPIO_SPEED_10M;
	PIN_temp.GPIO_PinNumber = GPIO_PIN_0;
	MCAL_GPIO_Init(GPIOA,&PIN_temp);

	adc_init();

}
uint8_t Read_Temp(uint8_t channel_num)
{
	uint16_t digital_value;
	float Temp;
	digital_value=	adc_read(channel_num);

	//Temp = (((uint32_t)digital_value*5.0*150)/(ADC_MAXIMUM_VALUE*2.4));
	Temp = (float)(digital_value * 330 / 4095);
	//	Temp = (uint16_t)(((float)digital_value / ADC_MAXIMUM_VALUE));

	//	temp=(float32)((digital_value*((float32)ADC_REF_VOLT_VALUE/(float32)ADC_MAXIMUM_VALUE)))*1000;
	//	Temp = temp / 10;
	return Temp;
}
