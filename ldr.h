/*
 * ldr.h
 *
 *  Created on: Dec 3, 2023
 *      Author: user
 */

#ifndef LDR_H_
#define LDR_H_

#include "adc.h"
#include "stm32f103x8_gpio_driver.h"


void Init_ldr(void);


uint16_t Read_ldr(uint8_t channel_num);

#endif /* LDR_H_ */
