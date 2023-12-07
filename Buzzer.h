/*
 * Buzzer.h
 *
 *  Created on: Dec 1, 2023
 *      Author: user
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#include "stm32f103x8_gpio_driver.h"

void Buzzer_Init(GPIO_TypeDef *GPIOx , GPIO_PinConfig_t* PinConfig);

void Buzzer_ON(GPIO_TypeDef *GPIOx , uint16_t PinNumber);

void Buzzer_OFF(GPIO_TypeDef *GPIOx , uint16_t PinNumber);

#endif /* BUZZER_H_ */
