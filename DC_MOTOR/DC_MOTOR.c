/*
 * DC_MOTOR.c
 *
 *  Created on: Nov 9, 2023
 *      Author: OMR
 */


#include"DC_MOTOR.h"
#include"STM32F103x8.h"
#include"TIMERx_interface.h"
#include"stm32f103x8_gpio_driver.h"

void DcMotor_Init(void)
{
	/*enable GPIOA clk*/
	RCC_GPIOA_CLK_EN();
	//RCC_GPIOB_CLK_EN();

	/*enable timer3 clk*/
	RCC_TIMER3_CLK_EN();

	/*SET IN1 & IN2 OF DC_MOTOR AS OUTPUT PINS FROM MC*/
	GPIO_PinConfig_t cfg1 = {GPIO_PIN_4, GPIO_MODE_OUTPUT_PP, GPIO_SPEED_2M};
	MCAL_GPIO_Init(GPIOA, &cfg1);

	GPIO_PinConfig_t cfg2 = {GPIO_PIN_, GPIO_MODE_OUTPUT_PP, GPIO_SPEED_2M};
	MCAL_GPIO_Init(GPIOA, &cfg2);

	/*SET PWM PIN AS OUTPUT*/
	GPIO_PinConfig_t cfg = {GPIO_PIN_6, GPIO_MODE_OUTPUT_AF_PP, GPIO_SPEED_2M};
	MCAL_GPIO_Init(GPIOA, &cfg);


	/*STOP DC_MOTOR INITIALY*/
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);


	/*init timer3*/
	MTIMERx_voidInit();
	MTIMERx_voidPWMSetup(3, 1);

}
void DC_MOTOR_setSpeed(u32 duty, DcMotor_State state)
{
	/*adjust the state of the rotation of motor(clkwise/ anti clkwise/ stop)*/
    if(state == clkWise)
	{
		MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);
		MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);

	}
	else if(state == antiClkWise)
	{
		MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
		MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);

	}
	/*send the required speed to pwm to generate the wave on the enable pin of the motor*/
	MTIMERx_voidSetPWMDuty(3, 1, duty);

}
