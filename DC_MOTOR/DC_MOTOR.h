/*
 * DC_MOTOR.h
 *
 *  Created on: Nov 9, 2023
 *      Author: OMR
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include"STD_TYPES.h"


typedef enum
{stop, clkWise, antiClkWise}DcMotor_State;

/*
 *Description
 *The Function responsible for setup the direction for the two motor pins through the GPIO driver.
 *Stop the DC-Motor at the beginning through the GPIO driver.
*/
void DcMotor_Init(void);

/*
 *Description:
 *The function responsible for rotate the DC Motor CW/ or A-CW or
 *stop the motor based on the state input state value.
 *Send the required duty cycle to the PWM driver based on the required speed value
 */
void DC_MOTOR_setSpeed(u32 duty, DcMotor_State state);
#endif /* DC_MOTOR_H_ */
