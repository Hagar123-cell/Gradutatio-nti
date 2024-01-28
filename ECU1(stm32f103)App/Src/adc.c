/*
 * adc.c
 *
 *  Created on: Nov 30, 2023
 *      Author: user
 */


#include <stdint.h>

#include "STM32F103X8.h"
#include "adc.h"


// Function to initialize ADC
void adc_init() {
	//    ADC1->CR2 &= ~(1 << 0);

	// Enable ADC1 clock
	RCC->APB2ENR |= (1 << 9);


	// Configure ADC1 in continuous mode, and set sample time
	ADC1->CR1 |= (1 << 8);   // Scan mode
	ADC1->CR2 |= (1 << 1);   // Continuous conversion mode
	ADC1->SQR1 &= 0xFF0FFFFF; // 1 conversion
	//    ADC1->SQR1 |= 0x00200000;
	ADC1->SMPR2 |= (5 << 0); // Set sample time to 55.5 cycles

	// Enable ADC1
}

// Function to read ADC value
uint16_t adc_read(ADC_Channel channel_num)
{
	ADC1->CR2 |= (1 << 0);

	ADC1->SQR3 =(ADC1->SQR3 & 0xFFFFFFF0)|(channel_num & 0x0000000F);         // Select channel number

	ADC1->CR2 |= (1 << 0);

	// Start ADC conversion
	ADC1->CR2 |= (1 << 22);

	// Wait for conversion to complete
	while (!(ADC1->SR & (1 << 1)));

	// Read ADC value
	uint16_t adc_value = ADC1->DR;
	ADC1->CR2 &=~ (1 << 0);


	return adc_value;
}
