/*
 * LM35.h
 *
 *  Created on: Nov 30, 2023
 *      Author: user
 */

#ifndef LM35_H_
#define LM35_H_

#include "adc.h"
#include "stm32f103x8_gpio_driver.h"


void Init_temp(void);


uint16_t Read_Temp(uint8_t channel_num);

#endif /* LM35_H_ */
