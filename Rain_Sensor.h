/*
 * Rain_Sensor.h
 *
 *  Created on: Dec 5, 2023
 *      Author: user
 */

#ifndef RAIN_SENSOR_H_
#define RAIN_SENSOR_H_

#include "adc.h"
#include "stm32f103x8_gpio_driver.h"

void Init_Rain(void);


uint16_t Read_Rain(uint8_t channel_num);




#endif /* RAIN_SENSOR_H_ */
