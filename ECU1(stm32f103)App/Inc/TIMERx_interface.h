

#ifndef MCAL_TIMERX_TIMERX_INTERFACE_H_
#define MCAL_TIMERX_TIMERX_INTERFACE_H_

#include <stdint.h>
typedef enum
{
    RISING_EDGE = 0,
    FALLING_EDGE
}Trigger_Type;

typedef void (*timer_callback_t)(void);


#define TIMER2 2
#define TIMER3 3
#define TIMER4 4
#define TIMER5 5

#define CH1 1
#define CH2 2
#define CH3 3
#define CH4 4
void MTIMERx_voidInit(void);


void MTIMERx_voidPWMSetup(uint8_t copy_u8TimerID, uint8_t copy_u8ChannelID);

void MTIMERx_voidSetPWMDuty(uint8_t copy_u8TimerID, uint8_t copy_u8ChannelID, uint32_t copy_u32Duty);

void MTIMERx_voidInputCaptureSetup(uint8_t copy_u8TimerID, uint8_t copy_u8ChannelID);

void MTIMERx_voidStartTimer(uint8_t copy_u8TimerID);

void MTIMERx_voidStopTimer(uint8_t copy_u8TimerID);

void MTIMERx_voidGetInputCaptureCounter(uint8_t copy_u8TimerID, uint8_t copy_u8ChannelID, uint32_t *ptr_Counts);



void MTIMERx_voidSetInputCaptureTrigger(uint8_t copy_u8TimerID, uint8_t copy_u8ChannelID, uint8_t copy_u8ICTrigger);

void MTIMERx_voidInputCaptureCallback(uint8_t copy_u8TimerID, uint8_t copy_u8ChannelID, timer_callback_t ptr);


#endif /* MCAL_TIMERX_TIMERX_INTERFACE_H_ */
