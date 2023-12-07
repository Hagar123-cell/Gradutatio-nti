/*
 * adc.h
 *
 *  Created on: Nov 30, 2023
 *      Author: user
 */

#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>

#define ADC_MAXIMUM_VALUE 4095

typedef enum
{
	CH_0,CH_1,CH_2
}ADC_Channel;
// Register structure for ADC (Analog to Digital Converter) peripheral
typedef struct {
    volatile uint32_t SR;
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t SMPR1;
    volatile uint32_t SMPR2;
    volatile uint32_t JOFR1;
    volatile uint32_t JOFR2;
    volatile uint32_t JOFR3;
    volatile uint32_t JOFR4;
    volatile uint32_t HTR;
    volatile uint32_t LTR;
    volatile uint32_t SQR1;
    volatile uint32_t SQR2;
    volatile uint32_t SQR3;
    volatile uint32_t JSQR;
    volatile uint32_t JDR1;
    volatile uint32_t JDR2;
    volatile uint32_t JDR3;
    volatile uint32_t JDR4;
    volatile uint32_t DR;
} ADC_TypeDef;

// Memory-mapped register addresses for RCC and ADC peripherals
#define RCC_BASE_ADDR   0x40021000
// Memory-mapped register addresses for ADC1 on STM32F103C6
#define ADC1_BASE_ADDR  0x40012400
#define ADC1_SR_OFFSET  0x00
#define ADC1_CR1_OFFSET 0x04
#define ADC1_CR2_OFFSET 0x08
#define ADC1_DR_OFFSET  0x4C


// ADC peripheral instance
#define ADC1            ((ADC_TypeDef*) ADC1_BASE_ADDR)


void adc_init();

uint16_t adc_read(ADC_Channel channel_num);


#endif /* ADC_H_ */
