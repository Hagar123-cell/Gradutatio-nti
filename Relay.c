/*
 * Relay.c
 *
 *  Created on: Dec 1, 2023
 *      Author: user
 */

#include "Relay.h"

void Relay_Init(GPIO_TypeDef *GPIOx , GPIO_PinConfig_t* PinConfig)
{
	MCAL_GPIO_Init(GPIOx,PinConfig);

}

void Relay_ON(GPIO_TypeDef *GPIOx , uint16_t PinNumber)
{
	MCAL_GPIO_WritePin(GPIOx, PinNumber, 1);

}

void Relay_OFF(GPIO_TypeDef *GPIOx , uint16_t PinNumber)
{
	MCAL_GPIO_WritePin(GPIOx, PinNumber, 0);

}
