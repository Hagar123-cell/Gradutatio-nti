/*
 * File Name --> Delay.c
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> LIB
 * Brief	 --> Implementation for Delay functions.
 * */


/*
==================================================
  Start Section --> File Includes
==================================================
*/
#include "Delay.h"
#include "SYSTICK.h"

/*
==================================================
  End   Section --> File Includes
==================================================
*/

/*
==================================================
  Start Section --> Implementation
==================================================
*/
static uint32_t StaticGlobal_Ticks_u32 = 0;

#if (CONFIG_USE_RTOS==CONFIG_NO_RTOS)

void SysTick_Handler(void){
	StaticGlobal_Ticks_u32++;
}
#endif

uint32_t SYSTICK_GetCurrentTicks_u32(void){
	return StaticGlobal_Ticks_u32;
}


f32 SYSTICK_GetPreciseCurrentTicksInMilliSeconds_f32(void){
	return (f32)(SYSTICK_GetCurrentTicks_u32()/CONFIG_TICK_TIME_IN_MilliSeconds) + (f32)(SYSTICK->CVR)/((f32)SYSTICK->RVR);
}

void Delay_DelayInMilliSecondsBlocking_v(uint32_t Arg_DelayValueInMilliSeconds_u32){
	f32 Local_PreciseDelayValue;
	Local_PreciseDelayValue = SYSTICK_GetPreciseCurrentTicksInMilliSeconds_f32()+(f32)Arg_DelayValueInMilliSeconds_u32;
	f32 Local_PreciseTickValue;
	while (1){
		Local_PreciseTickValue = SYSTICK_GetPreciseCurrentTicksInMilliSeconds_f32();
		if (Local_PreciseTickValue > Local_PreciseDelayValue){
			break;
		}
	}
}

void Delay_DelayInSecondsBlocking_v(uint32_t Arg_DelayValueInSeconds_u32, uint32_t Arg_DelayValueInMilliSeconds_u32){
	if (0 != Arg_DelayValueInMilliSeconds_u32){
		Delay_DelayInMilliSecondsBlocking_v(Arg_DelayValueInMilliSeconds_u32);
	}
	for (uint32_t Local_i_u32 = 0; Local_i_u32 <Arg_DelayValueInSeconds_u32; Local_i_u32++){
		Delay_DelayInMilliSecondsBlocking_v(1000);
	}
}

/*
==================================================
  End   Section --> Implementation
==================================================
*/
