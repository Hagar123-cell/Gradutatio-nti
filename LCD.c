/*
 * Lcd.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Ahmed Yasser
 */
#include "LCD.h"
#include "stdlib.h"

void delay_ms(uint32_t time) {
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++)
			;
}

static void latchbyte(uint8_t copy_u8Byte)
{
#if(MODE == _8_BIT_MODE)
	{

		MCAL_GPIO_WritePin(LCD_CONTROL_PORT, LCD_EN_PIN, LOGIC_LOW);

		delay_ms(10);
		MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D0_PIN, GET_BIT(copy_u8Byte,0));
		MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D1_PIN, GET_BIT(copy_u8Byte,1));
		MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D2_PIN, GET_BIT(copy_u8Byte,2));
		MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D3_PIN, GET_BIT(copy_u8Byte,3));
		MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D4_PIN, GET_BIT(copy_u8Byte,4));
		MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D5_PIN, GET_BIT(copy_u8Byte,5));
		MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D6_PIN, GET_BIT(copy_u8Byte,6));
		MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D7_PIN, GET_BIT(copy_u8Byte,7));
		MCAL_GPIO_WritePin(LCD_CONTROL_PORT, LCD_EN_PIN, HIGH);
		MCAL_GPIO_WritePin(LCD_CONTROL_PORT, LCD_EN_PIN, LOGIC_LOW);
		delay_ms(50);

	}
#elif(MODE == _4_BIT_MODE)
	{
		MCAL_GPIO_WritePin(LCD_CONTROL_PORT, LCD_EN_PIN, GPIO_PIN_RESET);

		delay_ms(10);
		MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D4_PIN, GET_BIT(copy_u8Byte,4));
		MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D5_PIN, GET_BIT(copy_u8Byte,5));
		MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D6_PIN, GET_BIT(copy_u8Byte,6));
		MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D7_PIN, GET_BIT(copy_u8Byte,7));
		MCAL_GPIO_WritePin(LCD_CONTROL_PORT, LCD_EN_PIN, GPIO_PIN_SET);
		delay_ms(10);
		MCAL_GPIO_WritePin(LCD_CONTROL_PORT, LCD_EN_PIN, GPIO_PIN_RESET);
		delay_ms(10);
		MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D4_PIN, GET_BIT(copy_u8Byte,0));
		MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D5_PIN, GET_BIT(copy_u8Byte,1));
		MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D6_PIN, GET_BIT(copy_u8Byte,2));
		MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D7_PIN, GET_BIT(copy_u8Byte,3));
		MCAL_GPIO_WritePin(LCD_CONTROL_PORT, LCD_EN_PIN, GPIO_PIN_SET);
		delay_ms(10);
		MCAL_GPIO_WritePin(LCD_CONTROL_PORT, LCD_EN_PIN, GPIO_PIN_RESET);
		delay_ms(50);

	}
#endif
}



/*Initialization of LCD with the required mode and configuration*/
void H_LCD_void_IniT (void)
{
	/*Configure the direction of RS and E pins as o/p pins*/
	delay_ms(30);
	GPIO_PinConfig_t PIN_RS;
	PIN_RS.GPIO_MODE=GPIO_MODE_OUTPUT_PP;
	PIN_RS.GPIO_Output_Speed=GPIO_SPEED_10M;
	PIN_RS.GPIO_PinNumber=LCD_RS_PIN;

	MCAL_GPIO_Init(LCD_CONTROL_PORT, &PIN_RS);

	GPIO_PinConfig_t PIN_EN;
	PIN_EN.GPIO_MODE=GPIO_MODE_OUTPUT_PP;
	PIN_EN.GPIO_Output_Speed=GPIO_SPEED_10M;
	PIN_EN.GPIO_PinNumber=LCD_EN_PIN;

	MCAL_GPIO_Init(LCD_CONTROL_PORT, &PIN_EN);


	/*LCD power ON delay is always 15 ms*/
	delay_ms(20);
#if(MODE == _4_BIT_MODE)
	{
		GPIO_PinConfig_t PIN_D4;
		PIN_D4.GPIO_MODE=GPIO_MODE_OUTPUT_PP;
		PIN_D4.GPIO_Output_Speed=GPIO_SPEED_10M;
		PIN_D4.GPIO_PinNumber=LCD_D4_PIN;














		MCAL_GPIO_Init(LCD_DATA_PORT, &PIN_D4);

		GPIO_PinConfig_t PIN_D5;
		PIN_D5.GPIO_MODE=GPIO_MODE_OUTPUT_PP;
		PIN_D5.GPIO_Output_Speed=GPIO_SPEED_10M;
		PIN_D5.GPIO_PinNumber=LCD_D5_PIN;
		MCAL_GPIO_Init(LCD_DATA_PORT, &PIN_D5);

		GPIO_PinConfig_t PIN_D6;
		PIN_D6.GPIO_MODE=GPIO_MODE_OUTPUT_PP;
		PIN_D6.GPIO_Output_Speed=GPIO_SPEED_10M;
		PIN_D6.GPIO_PinNumber=LCD_D6_PIN;
		MCAL_GPIO_Init(LCD_DATA_PORT, &PIN_D6);

		GPIO_PinConfig_t PIN_D7;
		PIN_D7.GPIO_MODE=GPIO_MODE_OUTPUT_PP;
		PIN_D7.GPIO_Output_Speed=GPIO_SPEED_10M;
		PIN_D7.GPIO_PinNumber=LCD_D7_PIN;
		MCAL_GPIO_Init(LCD_DATA_PORT, &PIN_D7);

		/*Send initialization commands for 4 bit mode*/
		H_LCD_void_sendCommand(LCD_MODE_2LINES_4BITS_INIT1);
		H_LCD_void_sendCommand(LCD_MODE_2LINES_4BITS_INIT2);

		/*choose the mode of operation of LCD*/
		H_LCD_void_sendCommand(LCD_MODE_2LINES_4BITS);
	}
#elif (LCD_DATA_BITS_MODE == 8)
	{
		/*Configure the data port as o/p port*/
		GPIO_setupPortDirection(LCD_DATA_BUS_PORT,PORT_OUTPUT);

		/*choose the mode of operation of LCD*/
		H_LCD_void_sendCommand(LCD_MODE_2LINES_8BITS);
	}
#endif

	/*Send initialization display commands*/
	H_LCD_void_sendCommand(LCD_DISPLAY_ON_CURSOR_OFF);
	H_LCD_void_sendCommand(LCD_CLEAR_DISPLAY_SCREEN);
}




/*Send the required command to the LCD*/
void H_LCD_void_sendCommand (uint8_t copy_u8command)
{
	/*RS = 0 for sending command*/
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT, LCD_RS_PIN, GPIO_PIN_RESET);
	delay_ms(1);
	latchbyte(copy_u8command);
}


/*Display the required character on the LCD*/
void H_LCD_void_sendData(uint8_t copy_u8data)
{
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT, LCD_RS_PIN,GPIO_PIN_SET );
	latchbyte(copy_u8data);

}

/*Display the required string on the lCD*/
void H_LCD_void_sendString(const uint8_t *pstr)
{
	while (*(pstr)!= NULL)
	{
		H_LCD_void_sendData(*pstr);
		pstr++;
	}
}


void H_LCD_int_to_string(int data)
{
	char buff[16]; /*array to hold the ASCII result of each number*/
	itoa(data,buff,10); /*itoa c function to convert the integer data to corresponding ASCII vale, 10 --> base 10 for decimal*/
	H_LCD_void_sendString(buff);
}

void H_LCD_void_gotoXY(uint8_t copy_u8Row, uint8_t copy_u8Col)
{
	uint8_t Local_U8_Arr [4] = {LCD_R0_COMMAND , LCD_R1_COMMAND , LCD_R2_COMMAND , LCD_R3_COMMAND};
	H_LCD_void_sendCommand(Local_U8_Arr[copy_u8Row] + copy_u8Col);
}


void H_Lcd_Void_Clear()
{
	H_LCD_void_sendCommand(LCD_CLEAR_DISPLAY_SCREEN);
}
