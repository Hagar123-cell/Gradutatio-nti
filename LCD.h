/*
 * Lcd.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Ahmed Yasser
 */

#ifndef LCD_H_
#define LCD_H_
#include "stm32f103x8_gpio_driver.h"

#define GET_BIT(register_name,bit_no)  			((register_name & (1<<bit_no)) >>bit_no)


//////////////////////////////////////////////////////////////////////
///////////////////////// DEFINING LCD Port////////////////////////////////
//////////////////////////////////////////////////////////////////////
#define		LCD_CONTROL_PORT		GPIOA
#define		LCD_DATA_PORT			GPIOB


#define _8_BIT_MODE                   8
#define _4_BIT_MODE                   4

//////////////////////////////////////////////////////////////////////
///////////////////////// Configure Mode DEFINING LCD MODE////////////////////////////////
//////////////////////////////////////////////////////////////////////

#define MODE 						_4_BIT_MODE



//////////////////////////////////////////////////////////////////////
///////////////////////// DEFINING LCD PINS////////////////////////////////
//////////////////////////////////////////////////////////////////////
#define		LCD_RS_PIN				GPIO_PIN_5
#define		LCD_EN_PIN				GPIO_PIN_4
#define		LCD_D4_PIN				GPIO_PIN_5
#define		LCD_D5_PIN				GPIO_PIN_6
#define		LCD_D6_PIN				GPIO_PIN_7
#define		LCD_D7_PIN				GPIO_PIN_8
//////////////////////////////////////////////////////////////////////
///////////////////////// DEFINING LCD Port////////////////////////////////
//////////////////////////////////////////////////////////////////////
#define		LCD_CONTROL_PORT		GPIOA
#define		LCD_DATA_PORT			GPIOB


/*Initialization Modes Commands*/
#define LCD_MODE_1LINE_8BITS          0x30
#define LCD_MODE_2LINES_8BITS         0x38
#define LCD_MODE_1LINE_4BITS          0x20
#define LCD_MODE_2LINES_4BITS         0x28
#define LCD_MODE_2LINES_4BITS_INIT1   0x33
#define LCD_MODE_2LINES_4BITS_INIT2   0x32



/*LCD Commands*/
#define LCD_CLEAR_DISPLAY_SCREEN              0x01
#define LCD_RETURN_HOME                       0x02
#define LCD_SHIFT_CURSOR_TO_LEFT              0x04
#define LCD_SHIFT_DISPLAY_RIGHT               0x05
#define LCD_SHIFT_CURSOR_TO_RIGHT             0x06
#define LCD_SHIFT_DISPLAY_LEFT                0x07
#define LCD_DISPLAY_OFF_CURSOR_OFF            0x08
#define LCD_DISPLAY_OFF_CURSOR_ON             0x0A
#define LCD_DISPLAY_ON_CURSOR_OFF             0x0C
#define LCD_DISPLAY_ON_CURSOR_ON              0x0E
#define LCD_SHIFT_CURSOR_POSITION_TO_LEFT     0x10
#define LCD_SHIFT_CURSOR_POSITION_TO_RIGHT    0x14
#define LCD_SHIFT_ENTIRE_DISPLAY_TO_LEFT      0x18
#define LCD_SHIFT_ENTIRE_DISPLAY_TO_RIGHT     0x1C


#define LCD_R0_COMMAND                0x80
#define LCD_R1_COMMAND                0xC0
#define LCD_R2_COMMAND                0x94
#define LCD_R3_COMMAND                0xD4
////////////////////////////////////////////////////////

void delay_ms(uint32_t time);


void H_LCD_void_IniT (void);
void H_LCD_void_sendCommand (uint8_t copy_u8command);
void H_LCD_void_sendData(uint8_t copy_u8data);
void H_LCD_void_sendString(const uint8_t *pstr);
void H_LCD_void_gotoXY(uint8_t copy_u8Row, uint8_t copy_u8Col);
void H_Lcd_Void_Clear(void) ;
void LCD_DisplayCustomChar(uint8_t charCode);
void LCD_CreateCustomChar(const uint8_t *ArrPattern, uint8_t charCode) ;
void H_LCD_int_to_string(int data);

//void H_LCD_void_sendIntNum(signed int copy_s32Num);
#endif /* LCD_H_ */
