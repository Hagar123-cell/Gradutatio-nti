/*
 * DC_MOTOR.h
 *
 *  Created on: Nov 9, 2023
 *      Author: OMR
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_


#include <stdint.h>

typedef enum
{stop, clkWise, antiClkWise}DcMotor_State;

/*
 *Description
 *The Function responsible for setup the direction for the two motor pins through the GPIO driver.
 *Stop the DC-Motor at the beginning through the GPIO driver.
*/
void DcMotor1_Init(void);

/*
 *Description:
 *The function responsible for rotate the DC Motor CW/ or A-CW or
 *stop the motor based on the state input state value.
 *Send the required duty cycle to the PWM driver based on the required speed value
 */
void DC_MOTOR1_setSpeed(uint32_t duty, DcMotor_State state);


void DcMotor2_Init(void);


void DC_MOTOR2_setSpeed(uint32_t duty, DcMotor_State state);

#endif /* DC_MOTOR_H_ */
