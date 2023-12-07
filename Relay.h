/*
 * Relay.h
 *
 *  Created on: Dec 1, 2023
 *      Author: user
 */

#ifndef RELAY_H_
#define RELAY_H_

#include "stm32f103x8_gpio_driver.h"

void Relay_Init(GPIO_TypeDef *GPIOx , GPIO_PinConfig_t* PinConfig);

void Relay_ON(GPIO_TypeDef *GPIOx , uint16_t PinNumber);

void Relay_OFF(GPIO_TypeDef *GPIOx , uint16_t PinNumber);


#endif /* RELAY_H_ */
