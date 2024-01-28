/*
 * STM32F103x8.h
 *
 *  Created on: Apr 14, 2021
 *      Author: Keroles Shenouda
 *      Mastering Embedded System Online Diploma
 */

#ifndef STM32F103X8_H_
#define STM32F103X8_H_

//-----------------------------
//Includes
//-----------------------------

#include "stdlib.h"
#include <stdint.h>


//-----------------------------
//Base addresses for Memories
//-----------------------------
#define FLASH_Memory_BASE            					0x08000000UL
#define System_Memory_BASE            					0x1FFFF000UL
#define SRAM_BASE            							0x20000000UL

#define Peripherals_BASE            					0x40000000UL

#define Cortex_M3_Internal_Peripherals_BASE            	0xE0000000UL
//NVIC register map
#define NVIC_Base					(0xE000E100UL)
#define NVIC_ISER0					*(volatile uint32_t *) (NVIC_Base + 0x0 )
#define NVIC_ISER1					*(volatile uint32_t *)(NVIC_Base + 0x4)
#define NVIC_ISER2					*(volatile uint32_t *)(NVIC_Base + 0x8)
#define NVIC_ICER0					*(volatile uint32_t *)(NVIC_Base + 0x80)
#define NVIC_ICER1					*(volatile uint32_t *)(NVIC_Base + 0x84)
#define NVIC_ICER2					*(volatile uint32_t *)(NVIC_Base + 0x88)
//-----------------------------
//Base addresses for AHB Peripherals
//-----------------------------
#define RCC_BASE              (Peripherals_BASE + 0x00021000UL)

//-----------------------------
//Base addresses for APB2 Peripherals
//-----------------------------

//GPIO
//A,B fully included in LQFP48 Package
#define GPIOA_BASE            (Peripherals_BASE + 0x00010800UL)
#define GPIOB_BASE            (Peripherals_BASE + 0x00010C00UL)
//C,D Partial  included in LQFP48 Package
#define GPIOC_BASE            (Peripherals_BASE + 0x00011000UL)
#define GPIOD_BASE            (Peripherals_BASE + 0x00011400UL)
//EP not  included in LQFP48 Package
#define GPIOE_BASE            (Peripherals_BASE + 0x00011800UL)
//-------

#define AFIO_BASE             (Peripherals_BASE + 0x00010000UL)
#define EXTI_BASE             (Peripherals_BASE + 0x00010400UL)

#define USART1_BASE             (Peripherals_BASE + 0x00013800UL)


#define SPI1_BASE             (Peripherals_BASE + 0x00013000UL)


#define I2C1_BASE             (0x40005400UL)
#define I2C2_BASE             (0x40005800UL)

//-----------------------------
//Base addresses for APB1 Peripherals
//-----------------------------
#define USART2_BASE             (Peripherals_BASE + 0x00004400UL)
#define USART3_BASE             (Peripherals_BASE + 0x00004800UL)

#define SPI2_BASE             (Peripherals_BASE + 0x00003800UL)

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: GPIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
} GPIO_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: RCC
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t AHBSTR;
	volatile uint32_t CFGR2;

} RCC_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: EXTI
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
} EXTI_TypeDef;


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: AFIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR[4];
	uint32_t RESERVED0;
	volatile uint32_t MAPR2;
} AFIO_TypeDef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: USART
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t BRR;
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t CR3;
	volatile uint32_t GTPR;
} USART_TypeDef;


typedef struct
{
	volatile uint32_t SPI_CR1;
	volatile uint32_t SPI_CR2;
	volatile uint32_t SPI_SR;
	volatile uint32_t SPI_DR;
	volatile uint32_t SPI_CRCPR;
	volatile uint32_t SPI_RXCRCR;
	volatile uint32_t SPI_TXCRCR;
	volatile uint32_t SPI_I2SCFGR;
	volatile uint32_t SPI_I2SPR ;

} SPI_TypeDef;

typedef struct
{
	  volatile uint32_t CR1;
	  volatile uint32_t CR2;
	  volatile uint32_t OAR1;
	  volatile uint32_t OAR2;
	  volatile uint32_t DR;
	  volatile uint32_t SR1;
	  volatile uint32_t SR2;
	  volatile uint32_t CCR;
	  volatile uint32_t TRISE;

} I2C_TypeDef;

/**
  * @brief Controller Area Network TxMailBox
  */

typedef struct
{
  volatile uint32_t TIR;
  volatile uint32_t TDTR;
  volatile uint32_t TDLR;
  volatile uint32_t TDHR;
} CAN_TxMailBox_TypeDef;

/**
  * @brief Controller Area Network FIFOMailBox
  */

typedef struct
{
  volatile uint32_t RIR;
  volatile uint32_t RDTR;
  volatile uint32_t RDLR;
  volatile uint32_t RDHR;
} CAN_FIFOMailBox_TypeDef;

/**
  * @brief Controller Area Network FilterRegister
  */

typedef struct
{
  volatile uint32_t FR1;
  volatile uint32_t FR2;
} CAN_FilterRegister_TypeDef;

/**
  * @brief Controller Area Network
  */

typedef struct
{
  volatile uint32_t MCR;
  volatile uint32_t MSR;
  volatile uint32_t TSR;
  volatile uint32_t RF0R;
  volatile uint32_t RF1R;
  volatile uint32_t IER;
  volatile uint32_t ESR;
  volatile uint32_t BTR;
  uint32_t  RESERVED0[88];
  CAN_TxMailBox_TypeDef sTxMailBox[3];
  CAN_FIFOMailBox_TypeDef sFIFOMailBox[2];
  uint32_t  RESERVED1[12];
  volatile uint32_t FMR;
  volatile uint32_t FM1R;
  uint32_t  RESERVED2;
  volatile uint32_t FS1R;
  uint32_t  RESERVED3;
  volatile uint32_t FFA1R;
  uint32_t  RESERVED4;
  volatile uint32_t FA1R;
  uint32_t  RESERVED5[8];
  CAN_FilterRegister_TypeDef sFilterRegister[14];
} CAN_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*

#define GPIOA               ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD               ((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE               ((GPIO_TypeDef *)GPIOE_BASE)


#define RCC                 ((RCC_TypeDef *)RCC_BASE)

#define AFIO                ((AFIO_TypeDef *)AFIO_BASE)
#define EXTI                ((EXTI_TypeDef *)EXTI_BASE)

#define USART1                ((USART_TypeDef *)USART1_BASE)
#define USART2                ((USART_TypeDef *)USART2_BASE)
#define USART3                ((USART_TypeDef *)USART3_BASE)


#define SPI1                ((SPI_TypeDef *)SPI1_BASE)
#define SPI2                ((SPI_TypeDef *)SPI2_BASE)


#define I2C1                ((I2C_TypeDef *)I2C1_BASE)
#define I2C2                ((I2C_TypeDef *)I2C2_BASE)


#define CAN1				 ((CAN_TypeDef *)0x40006400)
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define RCC_ADC_CLK_EN()	( RCC->APB2ENR |= (1<<9) )

//Enable clock GPIOA
#define RCC_GPIOA_CLK_EN()	( RCC->APB2ENR |= (1<<2) )
//Enable clock GPIOB
#define RCC_GPIOB_CLK_EN()	( RCC->APB2ENR |= (1<<3) )
#define RCC_GPIOC_CLK_EN()	( RCC->APB2ENR |= (1<<4) )
#define RCC_GPIOD_CLK_EN()	( RCC->APB2ENR |= (1<<5) )
#define RCC_GPIOE_CLK_EN()	( RCC->APB2ENR |= (1<<6) )

#define RCC_AFIO_CLK_EN()	( RCC->APB2ENR |= (1<<0) )

#define RCC_USART1_CLK_EN()	( RCC->APB2ENR |= (1<<14) )
#define RCC_USART2_CLK_EN()	( RCC->APB1ENR |= (1<<17) )
#define RCC_USART3_CLK_EN()	( RCC->APB1ENR |= (1<<18) )

#define RCC_SPI1_CLK_EN()	( RCC->APB2ENR |= (1<<12) )
#define RCC_SPI2_CLK_EN()	( RCC->APB1ENR |= (1<<14) )

#define RCC_I2C1_CLK_EN()	(RCC->APB1ENR |= 1<<21)
#define RCC_I2C2_CLK_EN()	(RCC->APB1ENR |= 1<<22)

//RCC_Reset
#define RCC_USART1_Reset()	( RCC->APB2RSTR |= (1<<14) )
#define RCC_USART2_Reset()	( RCC->APB1RSTR |= (1<<17) )
#define RCC_USART3_Reset()	( RCC->APB1RSTR |= (1<<18) )

#define RCC_SPI1_Reset()	( RCC->APB2RSTR |= (1<<12) )
#define RCC_SPI2_Reset()	( RCC->APB1RSTR |= (1<<14) )


#define RCC_TIMER3_CLK_EN() (RCC->APB1ENR |= 1<<1)

#define RCC_I2C1_Reset()	(RCC->APB1RSTR |= 1<<21)
#define RCC_I2C2_Reset()	(RCC->APB1RSTR |= 1<<22)


//-*-*-*-*-*-*-*-*-*-*-*-
//IVT
//-*-*-*-*-*-*-*-*-*-*-*
//EXTI
#define 	EXTI0_IRQ			6
#define 	EXTI1_IRQ			7
#define 	EXTI2_IRQ			8
#define 	EXTI3_IRQ			9
#define 	EXTI4_IRQ			10
#define 	EXTI5_IRQ			23
#define 	EXTI6_IRQ			23
#define 	EXTI7_IRQ			23
#define 	EXTI8_IRQ			23
#define 	EXTI9_IRQ			23
#define 	EXTI10_IRQ			40
#define 	EXTI11_IRQ			40
#define 	EXTI12_IRQ			40
#define 	EXTI13_IRQ			40
#define 	EXTI14_IRQ			40
#define 	EXTI15_IRQ			40

#define 	USART1_IRQ			37
#define 	USART2_IRQ			38
#define 	USART3_IRQ			39

#define 	SPI1_IRQ			35
#define 	SPI2_IRQ			36




#define 	I2C1_EV_IRQ			31
#define 	I2C1_ER_IRQ			32
#define 	I2C2_EV_IRQ			33
#define 	I2C2_ER_IRQ			34


//-*-*-*-*-*-*-*-*-*-*-*-
//NVIC IRQ enable/Disable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define NVIC_IRQ6_EXTI0_Enable  	    (NVIC_ISER0 |= 1<<6)
#define NVIC_IRQ7_EXTI1_Enable   		(NVIC_ISER0 |= 1<<7)
#define NVIC_IRQ8_EXTI2_Enable   		(NVIC_ISER0 |= 1<<8)
#define NVIC_IRQ9_EXTI3_Enable   		(NVIC_ISER0 |= 1<<9)
#define NVIC_IRQ10_EXTI4_Enable   		(NVIC_ISER0 |= 1<<10)
#define NVIC_IRQ23_EXTI5_9_Enable   	(NVIC_ISER0 |= 1<<23)
#define NVIC_IRQ40_EXTI10_15_Enable   	(NVIC_ISER1 |= 1<<8) //40-32 = 8

#define NVIC_IRQ6_EXTI0_Disable  	    (NVIC_ICER0 |= 1<<6)
#define NVIC_IRQ7_EXTI1_Disable   		(NVIC_ICER0 |= 1<<7)
#define NVIC_IRQ8_EXTI2_Disable   		(NVIC_ICER0 |= 1<<8)
#define NVIC_IRQ9_EXTI3_Disable   		(NVIC_ICER0 |= 1<<9)
#define NVIC_IRQ10_EXTI4_Disable   		(NVIC_ICER0 |= 1<<10)
#define NVIC_IRQ23_EXTI5_9_Disable   	(NVIC_ICER0 |= 1<<23)
#define NVIC_IRQ40_EXTI10_15_Disable   	(NVIC_ICER1 |= 1<<8) //40-32 = 8


//USART
#define NVIC_IRQ37_USART1_Enable   	(NVIC_ISER1 |= 1<<( USART1_IRQ - 32 )) //IRQ-32
#define NVIC_IRQ38_USART2_Enable   	(NVIC_ISER1 |= 1<<( USART2_IRQ - 32 )) //IRQ-32
#define NVIC_IRQ39_USART3_Enable   	(NVIC_ISER1 |= 1<<( USART3_IRQ - 32 )) //IRQ-32

#define NVIC_IRQ37_USART1_Disable   	(NVIC_ICER1 |= 1<<( USART1_IRQ- 32 )) //IRQ-32
#define NVIC_IRQ38_USART2_Disable   	(NVIC_ICER1 |= 1<<( USART2_IRQ- 32 )) //IRQ-32
#define NVIC_IRQ39_USART3_Disable   	(NVIC_ICER1 |= 1<<( USART3_IRQ- 32 )) //IRQ-32


#define NVIC_IRQ35_SPI1_Enable   	(NVIC_ISER1 |= 1<<( SPI1_IRQ - 32 )) //NVIC_ISER1 35-32
#define NVIC_IRQ36_SPI2_Enable   	(NVIC_ISER1 |= 1<<( SPI2_IRQ - 32 )) //NVIC_ISER1 36-32

#define NVIC_IRQ35_SPI1_Disable   	(NVIC_ICER1 |= 1<<( SPI1_IRQ- 32 )) //NVIC_ISER1 35-32
#define NVIC_IRQ36_SPI2_Disable   	(NVIC_ICER1 |= 1<<( SPI2_IRQ- 32 )) //NVIC_ISER1 36-32

#define NVIC_IRQ31_I2C1_EV_Enable   	(NVIC_ISER0 |= 1<<( I2C1_EV_IRQ )) //NVIC_ISER0
#define NVIC_IRQ32_I2C1_ER_Enable   	(NVIC_ISER1 |= 1<<( I2C1_ER_IRQ - 32 )) //NVIC_ISER1 32-32
#define NVIC_IRQ33_I2C2_EV_Enable   	(NVIC_ISER1 |= 1<<( I2C2_EV_IRQ - 32 )) //NVIC_ISER1 33-32
#define NVIC_IRQ34_I2C2_ER_Enable   	(NVIC_ISER1 |= 1<<( I2C2_ER_IRQ - 32 )) //NVIC_ISER1 34-32


#define NVIC_IRQ31_I2C1_EV_Disable   	(NVIC_ICER0 |= 1<<( I2C1_EV_IRQ )) //NVIC_ICER1 //31
#define NVIC_IRQ32_I2C1_ER_Disable   	(NVIC_ICER1 |= 1<<( I2C1_ER_IRQ - 32 )) //NVIC_ICER1 32-32
#define NVIC_IRQ33_I2C2_EV_Disable   	(NVIC_ICER1 |= 1<<( I2C2_EV_IRQ - 32 )) //NVIC_ICER1 33-32
#define NVIC_IRQ34_I2C2_ER_Disable   	(NVIC_ICER1 |= 1<<( I2C2_ER_IRQ - 32 )) //NVIC_ICER1 34-32

/********************************************************/
/********************************************************/
/********************************************************/
/*******************  Bit definition  ********************/
/********************************************************/
/********************************************************/



/*******************  Bit definition for I2C_CR1 register  ********************/
#define I2C_CR1_PE_Pos                      (0U)
#define I2C_CR1_PE_Msk                      (0x1UL << I2C_CR1_PE_Pos)           /*!< 0x00000001 */
#define I2C_CR1_PE                          I2C_CR1_PE_Msk                     /*!< Peripheral Enable */
#define I2C_CR1_SMBUS_Pos                   (1U)
#define I2C_CR1_SMBUS_Msk                   (0x1UL << I2C_CR1_SMBUS_Pos)        /*!< 0x00000002 */
#define I2C_CR1_SMBUS                       I2C_CR1_SMBUS_Msk                  /*!< SMBus Mode */
#define I2C_CR1_SMBTYPE_Pos                 (3U)
#define I2C_CR1_SMBTYPE_Msk                 (0x1UL << I2C_CR1_SMBTYPE_Pos)      /*!< 0x00000008 */
#define I2C_CR1_SMBTYPE                     I2C_CR1_SMBTYPE_Msk                /*!< SMBus Type */
#define I2C_CR1_ENARP_Pos                   (4U)
#define I2C_CR1_ENARP_Msk                   (0x1UL << I2C_CR1_ENARP_Pos)        /*!< 0x00000010 */
#define I2C_CR1_ENARP                       I2C_CR1_ENARP_Msk                  /*!< ARP Enable */
#define I2C_CR1_ENPEC_Pos                   (5U)
#define I2C_CR1_ENPEC_Msk                   (0x1UL << I2C_CR1_ENPEC_Pos)        /*!< 0x00000020 */
#define I2C_CR1_ENPEC                       I2C_CR1_ENPEC_Msk                  /*!< PEC Enable */
#define I2C_CR1_ENGC_Pos                    (6U)
#define I2C_CR1_ENGC_Msk                    (0x1UL << I2C_CR1_ENGC_Pos)         /*!< 0x00000040 */
#define I2C_CR1_ENGC                        I2C_CR1_ENGC_Msk                   /*!< General Call Enable */
#define I2C_CR1_NOSTRETCH_Pos               (7U)
#define I2C_CR1_NOSTRETCH_Msk               (0x1UL << I2C_CR1_NOSTRETCH_Pos)    /*!< 0x00000080 */
#define I2C_CR1_NOSTRETCH                   I2C_CR1_NOSTRETCH_Msk              /*!< Clock Stretching Disable (Slave mode) */
#define I2C_CR1_START_Pos                   (8U)
#define I2C_CR1_START_Msk                   (0x1UL << I2C_CR1_START_Pos)        /*!< 0x00000100 */
#define I2C_CR1_START                       I2C_CR1_START_Msk                  /*!< Start Generation */
#define I2C_CR1_STOP_Pos                    (9U)
#define I2C_CR1_STOP_Msk                    (0x1UL << I2C_CR1_STOP_Pos)         /*!< 0x00000200 */
#define I2C_CR1_STOP                        I2C_CR1_STOP_Msk                   /*!< Stop Generation */
#define I2C_CR1_ACK_Pos                     (10U)
#define I2C_CR1_ACK_Msk                     (0x1UL << I2C_CR1_ACK_Pos)          /*!< 0x00000400 */
#define I2C_CR1_ACK                         I2C_CR1_ACK_Msk                    /*!< Acknowledge Enable */
#define I2C_CR1_POS_Pos                     (11U)
#define I2C_CR1_POS_Msk                     (0x1UL << I2C_CR1_POS_Pos)          /*!< 0x00000800 */
#define I2C_CR1_POS                         I2C_CR1_POS_Msk                    /*!< Acknowledge/PEC Position (for data reception) */
#define I2C_CR1_PEC_Pos                     (12U)
#define I2C_CR1_PEC_Msk                     (0x1UL << I2C_CR1_PEC_Pos)          /*!< 0x00001000 */
#define I2C_CR1_PEC                         I2C_CR1_PEC_Msk                    /*!< Packet Error Checking */
#define I2C_CR1_ALERT_Pos                   (13U)
#define I2C_CR1_ALERT_Msk                   (0x1UL << I2C_CR1_ALERT_Pos)        /*!< 0x00002000 */
#define I2C_CR1_ALERT                       I2C_CR1_ALERT_Msk                  /*!< SMBus Alert */
#define I2C_CR1_SWRST_Pos                   (15U)
#define I2C_CR1_SWRST_Msk                   (0x1UL << I2C_CR1_SWRST_Pos)        /*!< 0x00008000 */
#define I2C_CR1_SWRST                       I2C_CR1_SWRST_Msk                  /*!< Software Reset */
/*******************  Bit definition for I2C_CR2 register  ********************/
#define I2C_CR2_FREQ_Pos                    (0U)
#define I2C_CR2_FREQ_Msk                    (0x3FUL << I2C_CR2_FREQ_Pos)        /*!< 0x0000003F */
#define I2C_CR2_FREQ                        I2C_CR2_FREQ_Msk                   /*!< FREQ[5:0] bits (Peripheral Clock Frequency) */
#define I2C_CR2_ITERREN_Pos                 (8U)
#define I2C_CR2_ITERREN_Msk                 (0x1UL << I2C_CR2_ITERREN_Pos)      /*!< 0x00000100 */
#define I2C_CR2_ITERREN                     I2C_CR2_ITERREN_Msk                /*!< Error Interrupt Enable */
#define I2C_CR2_ITEVTEN_Pos                 (9U)
#define I2C_CR2_ITEVTEN_Msk                 (0x1UL << I2C_CR2_ITEVTEN_Pos)      /*!< 0x00000200 */
#define I2C_CR2_ITEVTEN                     I2C_CR2_ITEVTEN_Msk                /*!< Event Interrupt Enable */
#define I2C_CR2_ITBUFEN_Pos                 (10U)
#define I2C_CR2_ITBUFEN_Msk                 (0x1UL << I2C_CR2_ITBUFEN_Pos)      /*!< 0x00000400 */
#define I2C_CR2_ITBUFEN                     I2C_CR2_ITBUFEN_Msk                /*!< Buffer Interrupt Enable */
#define I2C_CR2_DMAEN_Pos                   (11U)
#define I2C_CR2_DMAEN_Msk                   (0x1UL << I2C_CR2_DMAEN_Pos)        /*!< 0x00000800 */
#define I2C_CR2_DMAEN                       I2C_CR2_DMAEN_Msk                  /*!< DMA Requests Enable */
#define I2C_CR2_LAST_Pos                    (12U)
#define I2C_CR2_LAST_Msk                    (0x1UL << I2C_CR2_LAST_Pos)         /*!< 0x00001000 */
#define I2C_CR2_LAST                        I2C_CR2_LAST_Msk                   /*!< DMA Last Transfer */
/*******************  Bit definition for I2C_OAR2 register  *******************/
#define I2C_OAR2_ENDUAL_Pos                 (0U)
#define I2C_OAR2_ENDUAL_Msk                 (0x1UL << I2C_OAR2_ENDUAL_Pos)      /*!< 0x00000001 */
#define I2C_OAR2_ENDUAL                     I2C_OAR2_ENDUAL_Msk                /*!< Dual addressing mode enable */
#define I2C_OAR2_ADD2_Pos                   (1U)
/*******************  Bit definition for I2C_SR1 register  ********************/
#define I2C_SR1_SB_Pos                      (0U)
#define I2C_SR1_SB_Msk                      (0x1UL << I2C_SR1_SB_Pos)           /*!< 0x00000001 */
#define I2C_SR1_SB                          I2C_SR1_SB_Msk                     /*!< Start Bit (Master mode) */
#define I2C_SR1_ADDR_Pos                    (1U)
#define I2C_SR1_ADDR_Msk                    (0x1UL << I2C_SR1_ADDR_Pos)         /*!< 0x00000002 */
#define I2C_SR1_ADDR                        I2C_SR1_ADDR_Msk                   /*!< Address sent (master mode)/matched (slave mode) */
#define I2C_SR1_BTF_Pos                     (2U)
#define I2C_SR1_BTF_Msk                     (0x1UL << I2C_SR1_BTF_Pos)          /*!< 0x00000004 */
#define I2C_SR1_BTF                         I2C_SR1_BTF_Msk                    /*!< Byte Transfer Finished */
#define I2C_SR1_ADD10_Pos                   (3U)
#define I2C_SR1_ADD10_Msk                   (0x1UL << I2C_SR1_ADD10_Pos)        /*!< 0x00000008 */
#define I2C_SR1_ADD10                       I2C_SR1_ADD10_Msk                  /*!< 10-bit header sent (Master mode) */
#define I2C_SR1_STOPF_Pos                   (4U)
#define I2C_SR1_STOPF_Msk                   (0x1UL << I2C_SR1_STOPF_Pos)        /*!< 0x00000010 */
#define I2C_SR1_STOPF                       I2C_SR1_STOPF_Msk                  /*!< Stop detection (Slave mode) */
#define I2C_SR1_RXNE_Pos                    (6U)
#define I2C_SR1_RXNE_Msk                    (0x1UL << I2C_SR1_RXNE_Pos)         /*!< 0x00000040 */
#define I2C_SR1_RXNE                        I2C_SR1_RXNE_Msk                   /*!< Data Register not Empty (receivers) */
#define I2C_SR1_TXE_Pos                     (7U)
#define I2C_SR1_TXE_Msk                     (0x1UL << I2C_SR1_TXE_Pos)          /*!< 0x00000080 */
#define I2C_SR1_TXE                         I2C_SR1_TXE_Msk                    /*!< Data Register Empty (transmitters) */
#define I2C_SR1_BERR_Pos                    (8U)
#define I2C_SR1_BERR_Msk                    (0x1UL << I2C_SR1_BERR_Pos)         /*!< 0x00000100 */
#define I2C_SR1_BERR                        I2C_SR1_BERR_Msk                   /*!< Bus Error */
#define I2C_SR1_ARLO_Pos                    (9U)
#define I2C_SR1_ARLO_Msk                    (0x1UL << I2C_SR1_ARLO_Pos)         /*!< 0x00000200 */
#define I2C_SR1_ARLO                        I2C_SR1_ARLO_Msk                   /*!< Arbitration Lost (master mode) */
#define I2C_SR1_AF_Pos                      (10U)
#define I2C_SR1_AF_Msk                      (0x1UL << I2C_SR1_AF_Pos)           /*!< 0x00000400 */
#define I2C_SR1_AF                          I2C_SR1_AF_Msk                     /*!< Acknowledge Failure */
#define I2C_SR1_OVR_Pos                     (11U)
#define I2C_SR1_OVR_Msk                     (0x1UL << I2C_SR1_OVR_Pos)          /*!< 0x00000800 */
#define I2C_SR1_OVR                         I2C_SR1_OVR_Msk                    /*!< Overrun/Underrun */
#define I2C_SR1_PECERR_Pos                  (12U)
#define I2C_SR1_PECERR_Msk                  (0x1UL << I2C_SR1_PECERR_Pos)       /*!< 0x00001000 */
#define I2C_SR1_PECERR                      I2C_SR1_PECERR_Msk                 /*!< PEC Error in reception */
#define I2C_SR1_TIMEOUT_Pos                 (14U)
#define I2C_SR1_TIMEOUT_Msk                 (0x1UL << I2C_SR1_TIMEOUT_Pos)      /*!< 0x00004000 */
#define I2C_SR1_TIMEOUT                     I2C_SR1_TIMEOUT_Msk                /*!< Timeout or Tlow Error */
#define I2C_SR1_SMBALERT_Pos                (15U)
#define I2C_SR1_SMBALERT_Msk                (0x1UL << I2C_SR1_SMBALERT_Pos)     /*!< 0x00008000 */
#define I2C_SR1_SMBALERT                    I2C_SR1_SMBALERT_Msk               /*!< SMBus Alert */

/*******************  Bit definition for I2C_SR2 register  ********************/
#define I2C_SR2_MSL_Pos                     (0U)
#define I2C_SR2_MSL_Msk                     (0x1UL << I2C_SR2_MSL_Pos)          /*!< 0x00000001 */
#define I2C_SR2_MSL                         I2C_SR2_MSL_Msk                    /*!< Master/Slave */
#define I2C_SR2_BUSY_Pos                    (1U)
#define I2C_SR2_BUSY_Msk                    (0x1UL << I2C_SR2_BUSY_Pos)         /*!< 0x00000002 */
#define I2C_SR2_BUSY                        I2C_SR2_BUSY_Msk                   /*!< Bus Busy */
#define I2C_SR2_TRA_Pos                     (2U)
#define I2C_SR2_TRA_Msk                     (0x1UL << I2C_SR2_TRA_Pos)          /*!< 0x00000004 */
#define I2C_SR2_TRA                         I2C_SR2_TRA_Msk                    /*!< Transmitter/Receiver */
#define I2C_SR2_GENCALL_Pos                 (4U)
#define I2C_SR2_GENCALL_Msk                 (0x1UL << I2C_SR2_GENCALL_Pos)      /*!< 0x00000010 */
#define I2C_SR2_GENCALL                     I2C_SR2_GENCALL_Msk                /*!< General Call Address (Slave mode) */
#define I2C_SR2_SMBDEFAULT_Pos              (5U)
#define I2C_SR2_SMBDEFAULT_Msk              (0x1UL << I2C_SR2_SMBDEFAULT_Pos)   /*!< 0x00000020 */
#define I2C_SR2_SMBDEFAULT                  I2C_SR2_SMBDEFAULT_Msk             /*!< SMBus Device Default Address (Slave mode) */
#define I2C_SR2_SMBHOST_Pos                 (6U)
#define I2C_SR2_SMBHOST_Msk                 (0x1UL << I2C_SR2_SMBHOST_Pos)      /*!< 0x00000040 */
#define I2C_SR2_SMBHOST                     I2C_SR2_SMBHOST_Msk                /*!< SMBus Host Header (Slave mode) */
#define I2C_SR2_DUALF_Pos                   (7U)
#define I2C_SR2_DUALF_Msk                   (0x1UL << I2C_SR2_DUALF_Pos)        /*!< 0x00000080 */
#define I2C_SR2_DUALF                       I2C_SR2_DUALF_Msk                  /*!< Dual Flag (Slave mode) */
#define I2C_SR2_PEC_Pos                     (8U)
#define I2C_SR2_PEC_Msk                     (0xFFUL << I2C_SR2_PEC_Pos)         /*!< 0x0000FF00 */
#define I2C_SR2_PEC                         I2C_SR2_PEC_Msk                    /*!< Packet Error Checking Register */




/******************************************************************************/
/*                                                                            */
/*                General Purpose and Alternate Function I/O                  */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for GPIO_CRL register  *******************/
#define GPIO_CRL_MODE_Pos                    (0U)
#define GPIO_CRL_MODE_Msk                    (0x33333333UL << GPIO_CRL_MODE_Pos) /*!< 0x33333333 */
#define GPIO_CRL_MODE                        GPIO_CRL_MODE_Msk                 /*!< Port x mode bits */

#define GPIO_CRL_MODE0_Pos                   (0U)
#define GPIO_CRL_MODE0_Msk                   (0x3UL << GPIO_CRL_MODE0_Pos)      /*!< 0x00000003 */
#define GPIO_CRL_MODE0                       GPIO_CRL_MODE0_Msk                /*!< MODE0[1:0] bits (Port x mode bits, pin 0) */
#define GPIO_CRL_MODE0_0                     (0x1UL << GPIO_CRL_MODE0_Pos)      /*!< 0x00000001 */
#define GPIO_CRL_MODE0_1                     (0x2UL << GPIO_CRL_MODE0_Pos)      /*!< 0x00000002 */

#define GPIO_CRL_MODE1_Pos                   (4U)
#define GPIO_CRL_MODE1_Msk                   (0x3UL << GPIO_CRL_MODE1_Pos)      /*!< 0x00000030 */
#define GPIO_CRL_MODE1                       GPIO_CRL_MODE1_Msk                /*!< MODE1[1:0] bits (Port x mode bits, pin 1) */
#define GPIO_CRL_MODE1_0                     (0x1UL << GPIO_CRL_MODE1_Pos)      /*!< 0x00000010 */
#define GPIO_CRL_MODE1_1                     (0x2UL << GPIO_CRL_MODE1_Pos)      /*!< 0x00000020 */

#define GPIO_CRL_MODE2_Pos                   (8U)
#define GPIO_CRL_MODE2_Msk                   (0x3UL << GPIO_CRL_MODE2_Pos)      /*!< 0x00000300 */
#define GPIO_CRL_MODE2                       GPIO_CRL_MODE2_Msk                /*!< MODE2[1:0] bits (Port x mode bits, pin 2) */
#define GPIO_CRL_MODE2_0                     (0x1UL << GPIO_CRL_MODE2_Pos)      /*!< 0x00000100 */
#define GPIO_CRL_MODE2_1                     (0x2UL << GPIO_CRL_MODE2_Pos)      /*!< 0x00000200 */

#define GPIO_CRL_MODE3_Pos                   (12U)
#define GPIO_CRL_MODE3_Msk                   (0x3UL << GPIO_CRL_MODE3_Pos)      /*!< 0x00003000 */
#define GPIO_CRL_MODE3                       GPIO_CRL_MODE3_Msk                /*!< MODE3[1:0] bits (Port x mode bits, pin 3) */
#define GPIO_CRL_MODE3_0                     (0x1UL << GPIO_CRL_MODE3_Pos)      /*!< 0x00001000 */
#define GPIO_CRL_MODE3_1                     (0x2UL << GPIO_CRL_MODE3_Pos)      /*!< 0x00002000 */

#define GPIO_CRL_MODE4_Pos                   (16U)
#define GPIO_CRL_MODE4_Msk                   (0x3UL << GPIO_CRL_MODE4_Pos)      /*!< 0x00030000 */
#define GPIO_CRL_MODE4                       GPIO_CRL_MODE4_Msk                /*!< MODE4[1:0] bits (Port x mode bits, pin 4) */
#define GPIO_CRL_MODE4_0                     (0x1UL << GPIO_CRL_MODE4_Pos)      /*!< 0x00010000 */
#define GPIO_CRL_MODE4_1                     (0x2UL << GPIO_CRL_MODE4_Pos)      /*!< 0x00020000 */

#define GPIO_CRL_MODE5_Pos                   (20U)
#define GPIO_CRL_MODE5_Msk                   (0x3UL << GPIO_CRL_MODE5_Pos)      /*!< 0x00300000 */
#define GPIO_CRL_MODE5                       GPIO_CRL_MODE5_Msk                /*!< MODE5[1:0] bits (Port x mode bits, pin 5) */
#define GPIO_CRL_MODE5_0                     (0x1UL << GPIO_CRL_MODE5_Pos)      /*!< 0x00100000 */
#define GPIO_CRL_MODE5_1                     (0x2UL << GPIO_CRL_MODE5_Pos)      /*!< 0x00200000 */

#define GPIO_CRL_MODE6_Pos                   (24U)
#define GPIO_CRL_MODE6_Msk                   (0x3UL << GPIO_CRL_MODE6_Pos)      /*!< 0x03000000 */
#define GPIO_CRL_MODE6                       GPIO_CRL_MODE6_Msk                /*!< MODE6[1:0] bits (Port x mode bits, pin 6) */
#define GPIO_CRL_MODE6_0                     (0x1UL << GPIO_CRL_MODE6_Pos)      /*!< 0x01000000 */
#define GPIO_CRL_MODE6_1                     (0x2UL << GPIO_CRL_MODE6_Pos)      /*!< 0x02000000 */

#define GPIO_CRL_MODE7_Pos                   (28U)
#define GPIO_CRL_MODE7_Msk                   (0x3UL << GPIO_CRL_MODE7_Pos)      /*!< 0x30000000 */
#define GPIO_CRL_MODE7                       GPIO_CRL_MODE7_Msk                /*!< MODE7[1:0] bits (Port x mode bits, pin 7) */
#define GPIO_CRL_MODE7_0                     (0x1UL << GPIO_CRL_MODE7_Pos)      /*!< 0x10000000 */
#define GPIO_CRL_MODE7_1                     (0x2UL << GPIO_CRL_MODE7_Pos)      /*!< 0x20000000 */

#define GPIO_CRL_CNF_Pos                     (2U)
#define GPIO_CRL_CNF_Msk                     (0x33333333UL << GPIO_CRL_CNF_Pos) /*!< 0xCCCCCCCC */
#define GPIO_CRL_CNF                         GPIO_CRL_CNF_Msk                  /*!< Port x configuration bits */

#define GPIO_CRL_CNF0_Pos                    (2U)
#define GPIO_CRL_CNF0_Msk                    (0x3UL << GPIO_CRL_CNF0_Pos)       /*!< 0x0000000C */
#define GPIO_CRL_CNF0                        GPIO_CRL_CNF0_Msk                 /*!< CNF0[1:0] bits (Port x configuration bits, pin 0) */
#define GPIO_CRL_CNF0_0                      (0x1UL << GPIO_CRL_CNF0_Pos)       /*!< 0x00000004 */
#define GPIO_CRL_CNF0_1                      (0x2UL << GPIO_CRL_CNF0_Pos)       /*!< 0x00000008 */

#define GPIO_CRL_CNF1_Pos                    (6U)
#define GPIO_CRL_CNF1_Msk                    (0x3UL << GPIO_CRL_CNF1_Pos)       /*!< 0x000000C0 */
#define GPIO_CRL_CNF1                        GPIO_CRL_CNF1_Msk                 /*!< CNF1[1:0] bits (Port x configuration bits, pin 1) */
#define GPIO_CRL_CNF1_0                      (0x1UL << GPIO_CRL_CNF1_Pos)       /*!< 0x00000040 */
#define GPIO_CRL_CNF1_1                      (0x2UL << GPIO_CRL_CNF1_Pos)       /*!< 0x00000080 */

#define GPIO_CRL_CNF2_Pos                    (10U)
#define GPIO_CRL_CNF2_Msk                    (0x3UL << GPIO_CRL_CNF2_Pos)       /*!< 0x00000C00 */
#define GPIO_CRL_CNF2                        GPIO_CRL_CNF2_Msk                 /*!< CNF2[1:0] bits (Port x configuration bits, pin 2) */
#define GPIO_CRL_CNF2_0                      (0x1UL << GPIO_CRL_CNF2_Pos)       /*!< 0x00000400 */
#define GPIO_CRL_CNF2_1                      (0x2UL << GPIO_CRL_CNF2_Pos)       /*!< 0x00000800 */

#define GPIO_CRL_CNF3_Pos                    (14U)
#define GPIO_CRL_CNF3_Msk                    (0x3UL << GPIO_CRL_CNF3_Pos)       /*!< 0x0000C000 */
#define GPIO_CRL_CNF3                        GPIO_CRL_CNF3_Msk                 /*!< CNF3[1:0] bits (Port x configuration bits, pin 3) */
#define GPIO_CRL_CNF3_0                      (0x1UL << GPIO_CRL_CNF3_Pos)       /*!< 0x00004000 */
#define GPIO_CRL_CNF3_1                      (0x2UL << GPIO_CRL_CNF3_Pos)       /*!< 0x00008000 */

#define GPIO_CRL_CNF4_Pos                    (18U)
#define GPIO_CRL_CNF4_Msk                    (0x3UL << GPIO_CRL_CNF4_Pos)       /*!< 0x000C0000 */
#define GPIO_CRL_CNF4                        GPIO_CRL_CNF4_Msk                 /*!< CNF4[1:0] bits (Port x configuration bits, pin 4) */
#define GPIO_CRL_CNF4_0                      (0x1UL << GPIO_CRL_CNF4_Pos)       /*!< 0x00040000 */
#define GPIO_CRL_CNF4_1                      (0x2UL << GPIO_CRL_CNF4_Pos)       /*!< 0x00080000 */

#define GPIO_CRL_CNF5_Pos                    (22U)
#define GPIO_CRL_CNF5_Msk                    (0x3UL << GPIO_CRL_CNF5_Pos)       /*!< 0x00C00000 */
#define GPIO_CRL_CNF5                        GPIO_CRL_CNF5_Msk                 /*!< CNF5[1:0] bits (Port x configuration bits, pin 5) */
#define GPIO_CRL_CNF5_0                      (0x1UL << GPIO_CRL_CNF5_Pos)       /*!< 0x00400000 */
#define GPIO_CRL_CNF5_1                      (0x2UL << GPIO_CRL_CNF5_Pos)       /*!< 0x00800000 */

#define GPIO_CRL_CNF6_Pos                    (26U)
#define GPIO_CRL_CNF6_Msk                    (0x3UL << GPIO_CRL_CNF6_Pos)       /*!< 0x0C000000 */
#define GPIO_CRL_CNF6                        GPIO_CRL_CNF6_Msk                 /*!< CNF6[1:0] bits (Port x configuration bits, pin 6) */
#define GPIO_CRL_CNF6_0                      (0x1UL << GPIO_CRL_CNF6_Pos)       /*!< 0x04000000 */
#define GPIO_CRL_CNF6_1                      (0x2UL << GPIO_CRL_CNF6_Pos)       /*!< 0x08000000 */

#define GPIO_CRL_CNF7_Pos                    (30U)
#define GPIO_CRL_CNF7_Msk                    (0x3UL << GPIO_CRL_CNF7_Pos)       /*!< 0xC0000000 */
#define GPIO_CRL_CNF7                        GPIO_CRL_CNF7_Msk                 /*!< CNF7[1:0] bits (Port x configuration bits, pin 7) */
#define GPIO_CRL_CNF7_0                      (0x1UL << GPIO_CRL_CNF7_Pos)       /*!< 0x40000000 */
#define GPIO_CRL_CNF7_1                      (0x2UL << GPIO_CRL_CNF7_Pos)       /*!< 0x80000000 */

/*******************  Bit definition for GPIO_CRH register  *******************/
#define GPIO_CRH_MODE_Pos                    (0U)
#define GPIO_CRH_MODE_Msk                    (0x33333333UL << GPIO_CRH_MODE_Pos) /*!< 0x33333333 */
#define GPIO_CRH_MODE                        GPIO_CRH_MODE_Msk                 /*!< Port x mode bits */

#define GPIO_CRH_MODE8_Pos                   (0U)
#define GPIO_CRH_MODE8_Msk                   (0x3UL << GPIO_CRH_MODE8_Pos)      /*!< 0x00000003 */
#define GPIO_CRH_MODE8                       GPIO_CRH_MODE8_Msk                /*!< MODE8[1:0] bits (Port x mode bits, pin 8) */
#define GPIO_CRH_MODE8_0                     (0x1UL << GPIO_CRH_MODE8_Pos)      /*!< 0x00000001 */
#define GPIO_CRH_MODE8_1                     (0x2UL << GPIO_CRH_MODE8_Pos)      /*!< 0x00000002 */

#define GPIO_CRH_MODE9_Pos                   (4U)
#define GPIO_CRH_MODE9_Msk                   (0x3UL << GPIO_CRH_MODE9_Pos)      /*!< 0x00000030 */
#define GPIO_CRH_MODE9                       GPIO_CRH_MODE9_Msk                /*!< MODE9[1:0] bits (Port x mode bits, pin 9) */
#define GPIO_CRH_MODE9_0                     (0x1UL << GPIO_CRH_MODE9_Pos)      /*!< 0x00000010 */
#define GPIO_CRH_MODE9_1                     (0x2UL << GPIO_CRH_MODE9_Pos)      /*!< 0x00000020 */

#define GPIO_CRH_MODE10_Pos                  (8U)
#define GPIO_CRH_MODE10_Msk                  (0x3UL << GPIO_CRH_MODE10_Pos)     /*!< 0x00000300 */
#define GPIO_CRH_MODE10                      GPIO_CRH_MODE10_Msk               /*!< MODE10[1:0] bits (Port x mode bits, pin 10) */
#define GPIO_CRH_MODE10_0                    (0x1UL << GPIO_CRH_MODE10_Pos)     /*!< 0x00000100 */
#define GPIO_CRH_MODE10_1                    (0x2UL << GPIO_CRH_MODE10_Pos)     /*!< 0x00000200 */

#define GPIO_CRH_MODE11_Pos                  (12U)
#define GPIO_CRH_MODE11_Msk                  (0x3UL << GPIO_CRH_MODE11_Pos)     /*!< 0x00003000 */
#define GPIO_CRH_MODE11                      GPIO_CRH_MODE11_Msk               /*!< MODE11[1:0] bits (Port x mode bits, pin 11) */
#define GPIO_CRH_MODE11_0                    (0x1UL << GPIO_CRH_MODE11_Pos)     /*!< 0x00001000 */
#define GPIO_CRH_MODE11_1                    (0x2UL << GPIO_CRH_MODE11_Pos)     /*!< 0x00002000 */

#define GPIO_CRH_MODE12_Pos                  (16U)
#define GPIO_CRH_MODE12_Msk                  (0x3UL << GPIO_CRH_MODE12_Pos)     /*!< 0x00030000 */
#define GPIO_CRH_MODE12                      GPIO_CRH_MODE12_Msk               /*!< MODE12[1:0] bits (Port x mode bits, pin 12) */
#define GPIO_CRH_MODE12_0                    (0x1UL << GPIO_CRH_MODE12_Pos)     /*!< 0x00010000 */
#define GPIO_CRH_MODE12_1                    (0x2UL << GPIO_CRH_MODE12_Pos)     /*!< 0x00020000 */

#define GPIO_CRH_MODE13_Pos                  (20U)
#define GPIO_CRH_MODE13_Msk                  (0x3UL << GPIO_CRH_MODE13_Pos)     /*!< 0x00300000 */
#define GPIO_CRH_MODE13                      GPIO_CRH_MODE13_Msk               /*!< MODE13[1:0] bits (Port x mode bits, pin 13) */
#define GPIO_CRH_MODE13_0                    (0x1UL << GPIO_CRH_MODE13_Pos)     /*!< 0x00100000 */
#define GPIO_CRH_MODE13_1                    (0x2UL << GPIO_CRH_MODE13_Pos)     /*!< 0x00200000 */

#define GPIO_CRH_MODE14_Pos                  (24U)
#define GPIO_CRH_MODE14_Msk                  (0x3UL << GPIO_CRH_MODE14_Pos)     /*!< 0x03000000 */
#define GPIO_CRH_MODE14                      GPIO_CRH_MODE14_Msk               /*!< MODE14[1:0] bits (Port x mode bits, pin 14) */
#define GPIO_CRH_MODE14_0                    (0x1UL << GPIO_CRH_MODE14_Pos)     /*!< 0x01000000 */
#define GPIO_CRH_MODE14_1                    (0x2UL << GPIO_CRH_MODE14_Pos)     /*!< 0x02000000 */

#define GPIO_CRH_MODE15_Pos                  (28U)
#define GPIO_CRH_MODE15_Msk                  (0x3UL << GPIO_CRH_MODE15_Pos)     /*!< 0x30000000 */
#define GPIO_CRH_MODE15                      GPIO_CRH_MODE15_Msk               /*!< MODE15[1:0] bits (Port x mode bits, pin 15) */
#define GPIO_CRH_MODE15_0                    (0x1UL << GPIO_CRH_MODE15_Pos)     /*!< 0x10000000 */
#define GPIO_CRH_MODE15_1                    (0x2UL << GPIO_CRH_MODE15_Pos)     /*!< 0x20000000 */

#define GPIO_CRH_CNF_Pos                     (2U)
#define GPIO_CRH_CNF_Msk                     (0x33333333UL << GPIO_CRH_CNF_Pos) /*!< 0xCCCCCCCC */
#define GPIO_CRH_CNF                         GPIO_CRH_CNF_Msk                  /*!< Port x configuration bits */

#define GPIO_CRH_CNF8_Pos                    (2U)
#define GPIO_CRH_CNF8_Msk                    (0x3UL << GPIO_CRH_CNF8_Pos)       /*!< 0x0000000C */
#define GPIO_CRH_CNF8                        GPIO_CRH_CNF8_Msk                 /*!< CNF8[1:0] bits (Port x configuration bits, pin 8) */
#define GPIO_CRH_CNF8_0                      (0x1UL << GPIO_CRH_CNF8_Pos)       /*!< 0x00000004 */
#define GPIO_CRH_CNF8_1                      (0x2UL << GPIO_CRH_CNF8_Pos)       /*!< 0x00000008 */

#define GPIO_CRH_CNF9_Pos                    (6U)
#define GPIO_CRH_CNF9_Msk                    (0x3UL << GPIO_CRH_CNF9_Pos)       /*!< 0x000000C0 */
#define GPIO_CRH_CNF9                        GPIO_CRH_CNF9_Msk                 /*!< CNF9[1:0] bits (Port x configuration bits, pin 9) */
#define GPIO_CRH_CNF9_0                      (0x1UL << GPIO_CRH_CNF9_Pos)       /*!< 0x00000040 */
#define GPIO_CRH_CNF9_1                      (0x2UL << GPIO_CRH_CNF9_Pos)       /*!< 0x00000080 */

#define GPIO_CRH_CNF10_Pos                   (10U)
#define GPIO_CRH_CNF10_Msk                   (0x3UL << GPIO_CRH_CNF10_Pos)      /*!< 0x00000C00 */
#define GPIO_CRH_CNF10                       GPIO_CRH_CNF10_Msk                /*!< CNF10[1:0] bits (Port x configuration bits, pin 10) */
#define GPIO_CRH_CNF10_0                     (0x1UL << GPIO_CRH_CNF10_Pos)      /*!< 0x00000400 */
#define GPIO_CRH_CNF10_1                     (0x2UL << GPIO_CRH_CNF10_Pos)      /*!< 0x00000800 */

#define GPIO_CRH_CNF11_Pos                   (14U)
#define GPIO_CRH_CNF11_Msk                   (0x3UL << GPIO_CRH_CNF11_Pos)      /*!< 0x0000C000 */
#define GPIO_CRH_CNF11                       GPIO_CRH_CNF11_Msk                /*!< CNF11[1:0] bits (Port x configuration bits, pin 11) */
#define GPIO_CRH_CNF11_0                     (0x1UL << GPIO_CRH_CNF11_Pos)      /*!< 0x00004000 */
#define GPIO_CRH_CNF11_1                     (0x2UL << GPIO_CRH_CNF11_Pos)      /*!< 0x00008000 */

#define GPIO_CRH_CNF12_Pos                   (18U)
#define GPIO_CRH_CNF12_Msk                   (0x3UL << GPIO_CRH_CNF12_Pos)      /*!< 0x000C0000 */
#define GPIO_CRH_CNF12                       GPIO_CRH_CNF12_Msk                /*!< CNF12[1:0] bits (Port x configuration bits, pin 12) */
#define GPIO_CRH_CNF12_0                     (0x1UL << GPIO_CRH_CNF12_Pos)      /*!< 0x00040000 */
#define GPIO_CRH_CNF12_1                     (0x2UL << GPIO_CRH_CNF12_Pos)      /*!< 0x00080000 */

#define GPIO_CRH_CNF13_Pos                   (22U)
#define GPIO_CRH_CNF13_Msk                   (0x3UL << GPIO_CRH_CNF13_Pos)      /*!< 0x00C00000 */
#define GPIO_CRH_CNF13                       GPIO_CRH_CNF13_Msk                /*!< CNF13[1:0] bits (Port x configuration bits, pin 13) */
#define GPIO_CRH_CNF13_0                     (0x1UL << GPIO_CRH_CNF13_Pos)      /*!< 0x00400000 */
#define GPIO_CRH_CNF13_1                     (0x2UL << GPIO_CRH_CNF13_Pos)      /*!< 0x00800000 */

#define GPIO_CRH_CNF14_Pos                   (26U)
#define GPIO_CRH_CNF14_Msk                   (0x3UL << GPIO_CRH_CNF14_Pos)      /*!< 0x0C000000 */
#define GPIO_CRH_CNF14                       GPIO_CRH_CNF14_Msk                /*!< CNF14[1:0] bits (Port x configuration bits, pin 14) */
#define GPIO_CRH_CNF14_0                     (0x1UL << GPIO_CRH_CNF14_Pos)      /*!< 0x04000000 */
#define GPIO_CRH_CNF14_1                     (0x2UL << GPIO_CRH_CNF14_Pos)      /*!< 0x08000000 */

#define GPIO_CRH_CNF15_Pos                   (30U)
#define GPIO_CRH_CNF15_Msk                   (0x3UL << GPIO_CRH_CNF15_Pos)      /*!< 0xC0000000 */
#define GPIO_CRH_CNF15                       GPIO_CRH_CNF15_Msk                /*!< CNF15[1:0] bits (Port x configuration bits, pin 15) */
#define GPIO_CRH_CNF15_0                     (0x1UL << GPIO_CRH_CNF15_Pos)      /*!< 0x40000000 */
#define GPIO_CRH_CNF15_1                     (0x2UL << GPIO_CRH_CNF15_Pos)      /*!< 0x80000000 */

/*!<******************  Bit definition for GPIO_IDR register  *******************/
#define GPIO_IDR_IDR0_Pos                    (0U)
#define GPIO_IDR_IDR0_Msk                    (0x1UL << GPIO_IDR_IDR0_Pos)       /*!< 0x00000001 */
#define GPIO_IDR_IDR0                        GPIO_IDR_IDR0_Msk                 /*!< Port input data, bit 0 */
#define GPIO_IDR_IDR1_Pos                    (1U)
#define GPIO_IDR_IDR1_Msk                    (0x1UL << GPIO_IDR_IDR1_Pos)       /*!< 0x00000002 */
#define GPIO_IDR_IDR1                        GPIO_IDR_IDR1_Msk                 /*!< Port input data, bit 1 */
#define GPIO_IDR_IDR2_Pos                    (2U)
#define GPIO_IDR_IDR2_Msk                    (0x1UL << GPIO_IDR_IDR2_Pos)       /*!< 0x00000004 */
#define GPIO_IDR_IDR2                        GPIO_IDR_IDR2_Msk                 /*!< Port input data, bit 2 */
#define GPIO_IDR_IDR3_Pos                    (3U)
#define GPIO_IDR_IDR3_Msk                    (0x1UL << GPIO_IDR_IDR3_Pos)       /*!< 0x00000008 */
#define GPIO_IDR_IDR3                        GPIO_IDR_IDR3_Msk                 /*!< Port input data, bit 3 */
#define GPIO_IDR_IDR4_Pos                    (4U)
#define GPIO_IDR_IDR4_Msk                    (0x1UL << GPIO_IDR_IDR4_Pos)       /*!< 0x00000010 */
#define GPIO_IDR_IDR4                        GPIO_IDR_IDR4_Msk                 /*!< Port input data, bit 4 */
#define GPIO_IDR_IDR5_Pos                    (5U)
#define GPIO_IDR_IDR5_Msk                    (0x1UL << GPIO_IDR_IDR5_Pos)       /*!< 0x00000020 */
#define GPIO_IDR_IDR5                        GPIO_IDR_IDR5_Msk                 /*!< Port input data, bit 5 */
#define GPIO_IDR_IDR6_Pos                    (6U)
#define GPIO_IDR_IDR6_Msk                    (0x1UL << GPIO_IDR_IDR6_Pos)       /*!< 0x00000040 */
#define GPIO_IDR_IDR6                        GPIO_IDR_IDR6_Msk                 /*!< Port input data, bit 6 */
#define GPIO_IDR_IDR7_Pos                    (7U)
#define GPIO_IDR_IDR7_Msk                    (0x1UL << GPIO_IDR_IDR7_Pos)       /*!< 0x00000080 */
#define GPIO_IDR_IDR7                        GPIO_IDR_IDR7_Msk                 /*!< Port input data, bit 7 */
#define GPIO_IDR_IDR8_Pos                    (8U)
#define GPIO_IDR_IDR8_Msk                    (0x1UL << GPIO_IDR_IDR8_Pos)       /*!< 0x00000100 */
#define GPIO_IDR_IDR8                        GPIO_IDR_IDR8_Msk                 /*!< Port input data, bit 8 */
#define GPIO_IDR_IDR9_Pos                    (9U)
#define GPIO_IDR_IDR9_Msk                    (0x1UL << GPIO_IDR_IDR9_Pos)       /*!< 0x00000200 */
#define GPIO_IDR_IDR9                        GPIO_IDR_IDR9_Msk                 /*!< Port input data, bit 9 */
#define GPIO_IDR_IDR10_Pos                   (10U)
#define GPIO_IDR_IDR10_Msk                   (0x1UL << GPIO_IDR_IDR10_Pos)      /*!< 0x00000400 */
#define GPIO_IDR_IDR10                       GPIO_IDR_IDR10_Msk                /*!< Port input data, bit 10 */
#define GPIO_IDR_IDR11_Pos                   (11U)
#define GPIO_IDR_IDR11_Msk                   (0x1UL << GPIO_IDR_IDR11_Pos)      /*!< 0x00000800 */
#define GPIO_IDR_IDR11                       GPIO_IDR_IDR11_Msk                /*!< Port input data, bit 11 */
#define GPIO_IDR_IDR12_Pos                   (12U)
#define GPIO_IDR_IDR12_Msk                   (0x1UL << GPIO_IDR_IDR12_Pos)      /*!< 0x00001000 */
#define GPIO_IDR_IDR12                       GPIO_IDR_IDR12_Msk                /*!< Port input data, bit 12 */
#define GPIO_IDR_IDR13_Pos                   (13U)
#define GPIO_IDR_IDR13_Msk                   (0x1UL << GPIO_IDR_IDR13_Pos)      /*!< 0x00002000 */
#define GPIO_IDR_IDR13                       GPIO_IDR_IDR13_Msk                /*!< Port input data, bit 13 */
#define GPIO_IDR_IDR14_Pos                   (14U)
#define GPIO_IDR_IDR14_Msk                   (0x1UL << GPIO_IDR_IDR14_Pos)      /*!< 0x00004000 */
#define GPIO_IDR_IDR14                       GPIO_IDR_IDR14_Msk                /*!< Port input data, bit 14 */
#define GPIO_IDR_IDR15_Pos                   (15U)
#define GPIO_IDR_IDR15_Msk                   (0x1UL << GPIO_IDR_IDR15_Pos)      /*!< 0x00008000 */
#define GPIO_IDR_IDR15                       GPIO_IDR_IDR15_Msk                /*!< Port input data, bit 15 */

/*******************  Bit definition for GPIO_ODR register  *******************/
#define GPIO_ODR_ODR0_Pos                    (0U)
#define GPIO_ODR_ODR0_Msk                    (0x1UL << GPIO_ODR_ODR0_Pos)       /*!< 0x00000001 */
#define GPIO_ODR_ODR0                        GPIO_ODR_ODR0_Msk                 /*!< Port output data, bit 0 */
#define GPIO_ODR_ODR1_Pos                    (1U)
#define GPIO_ODR_ODR1_Msk                    (0x1UL << GPIO_ODR_ODR1_Pos)       /*!< 0x00000002 */
#define GPIO_ODR_ODR1                        GPIO_ODR_ODR1_Msk                 /*!< Port output data, bit 1 */
#define GPIO_ODR_ODR2_Pos                    (2U)
#define GPIO_ODR_ODR2_Msk                    (0x1UL << GPIO_ODR_ODR2_Pos)       /*!< 0x00000004 */
#define GPIO_ODR_ODR2                        GPIO_ODR_ODR2_Msk                 /*!< Port output data, bit 2 */
#define GPIO_ODR_ODR3_Pos                    (3U)
#define GPIO_ODR_ODR3_Msk                    (0x1UL << GPIO_ODR_ODR3_Pos)       /*!< 0x00000008 */
#define GPIO_ODR_ODR3                        GPIO_ODR_ODR3_Msk                 /*!< Port output data, bit 3 */
#define GPIO_ODR_ODR4_Pos                    (4U)
#define GPIO_ODR_ODR4_Msk                    (0x1UL << GPIO_ODR_ODR4_Pos)       /*!< 0x00000010 */
#define GPIO_ODR_ODR4                        GPIO_ODR_ODR4_Msk                 /*!< Port output data, bit 4 */
#define GPIO_ODR_ODR5_Pos                    (5U)
#define GPIO_ODR_ODR5_Msk                    (0x1UL << GPIO_ODR_ODR5_Pos)       /*!< 0x00000020 */
#define GPIO_ODR_ODR5                        GPIO_ODR_ODR5_Msk                 /*!< Port output data, bit 5 */
#define GPIO_ODR_ODR6_Pos                    (6U)
#define GPIO_ODR_ODR6_Msk                    (0x1UL << GPIO_ODR_ODR6_Pos)       /*!< 0x00000040 */
#define GPIO_ODR_ODR6                        GPIO_ODR_ODR6_Msk                 /*!< Port output data, bit 6 */
#define GPIO_ODR_ODR7_Pos                    (7U)
#define GPIO_ODR_ODR7_Msk                    (0x1UL << GPIO_ODR_ODR7_Pos)       /*!< 0x00000080 */
#define GPIO_ODR_ODR7                        GPIO_ODR_ODR7_Msk                 /*!< Port output data, bit 7 */
#define GPIO_ODR_ODR8_Pos                    (8U)
#define GPIO_ODR_ODR8_Msk                    (0x1UL << GPIO_ODR_ODR8_Pos)       /*!< 0x00000100 */
#define GPIO_ODR_ODR8                        GPIO_ODR_ODR8_Msk                 /*!< Port output data, bit 8 */
#define GPIO_ODR_ODR9_Pos                    (9U)
#define GPIO_ODR_ODR9_Msk                    (0x1UL << GPIO_ODR_ODR9_Pos)       /*!< 0x00000200 */
#define GPIO_ODR_ODR9                        GPIO_ODR_ODR9_Msk                 /*!< Port output data, bit 9 */
#define GPIO_ODR_ODR10_Pos                   (10U)
#define GPIO_ODR_ODR10_Msk                   (0x1UL << GPIO_ODR_ODR10_Pos)      /*!< 0x00000400 */
#define GPIO_ODR_ODR10                       GPIO_ODR_ODR10_Msk                /*!< Port output data, bit 10 */
#define GPIO_ODR_ODR11_Pos                   (11U)
#define GPIO_ODR_ODR11_Msk                   (0x1UL << GPIO_ODR_ODR11_Pos)      /*!< 0x00000800 */
#define GPIO_ODR_ODR11                       GPIO_ODR_ODR11_Msk                /*!< Port output data, bit 11 */
#define GPIO_ODR_ODR12_Pos                   (12U)
#define GPIO_ODR_ODR12_Msk                   (0x1UL << GPIO_ODR_ODR12_Pos)      /*!< 0x00001000 */
#define GPIO_ODR_ODR12                       GPIO_ODR_ODR12_Msk                /*!< Port output data, bit 12 */
#define GPIO_ODR_ODR13_Pos                   (13U)
#define GPIO_ODR_ODR13_Msk                   (0x1UL << GPIO_ODR_ODR13_Pos)      /*!< 0x00002000 */
#define GPIO_ODR_ODR13                       GPIO_ODR_ODR13_Msk                /*!< Port output data, bit 13 */
#define GPIO_ODR_ODR14_Pos                   (14U)
#define GPIO_ODR_ODR14_Msk                   (0x1UL << GPIO_ODR_ODR14_Pos)      /*!< 0x00004000 */
#define GPIO_ODR_ODR14                       GPIO_ODR_ODR14_Msk                /*!< Port output data, bit 14 */
#define GPIO_ODR_ODR15_Pos                   (15U)
#define GPIO_ODR_ODR15_Msk                   (0x1UL << GPIO_ODR_ODR15_Pos)      /*!< 0x00008000 */
#define GPIO_ODR_ODR15                       GPIO_ODR_ODR15_Msk                /*!< Port output data, bit 15 */

/******************  Bit definition for GPIO_BSRR register  *******************/
#define GPIO_BSRR_BS0_Pos                    (0U)
#define GPIO_BSRR_BS0_Msk                    (0x1UL << GPIO_BSRR_BS0_Pos)       /*!< 0x00000001 */
#define GPIO_BSRR_BS0                        GPIO_BSRR_BS0_Msk                 /*!< Port x Set bit 0 */
#define GPIO_BSRR_BS1_Pos                    (1U)
#define GPIO_BSRR_BS1_Msk                    (0x1UL << GPIO_BSRR_BS1_Pos)       /*!< 0x00000002 */
#define GPIO_BSRR_BS1                        GPIO_BSRR_BS1_Msk                 /*!< Port x Set bit 1 */
#define GPIO_BSRR_BS2_Pos                    (2U)
#define GPIO_BSRR_BS2_Msk                    (0x1UL << GPIO_BSRR_BS2_Pos)       /*!< 0x00000004 */
#define GPIO_BSRR_BS2                        GPIO_BSRR_BS2_Msk                 /*!< Port x Set bit 2 */
#define GPIO_BSRR_BS3_Pos                    (3U)
#define GPIO_BSRR_BS3_Msk                    (0x1UL << GPIO_BSRR_BS3_Pos)       /*!< 0x00000008 */
#define GPIO_BSRR_BS3                        GPIO_BSRR_BS3_Msk                 /*!< Port x Set bit 3 */
#define GPIO_BSRR_BS4_Pos                    (4U)
#define GPIO_BSRR_BS4_Msk                    (0x1UL << GPIO_BSRR_BS4_Pos)       /*!< 0x00000010 */
#define GPIO_BSRR_BS4                        GPIO_BSRR_BS4_Msk                 /*!< Port x Set bit 4 */
#define GPIO_BSRR_BS5_Pos                    (5U)
#define GPIO_BSRR_BS5_Msk                    (0x1UL << GPIO_BSRR_BS5_Pos)       /*!< 0x00000020 */
#define GPIO_BSRR_BS5                        GPIO_BSRR_BS5_Msk                 /*!< Port x Set bit 5 */
#define GPIO_BSRR_BS6_Pos                    (6U)
#define GPIO_BSRR_BS6_Msk                    (0x1UL << GPIO_BSRR_BS6_Pos)       /*!< 0x00000040 */
#define GPIO_BSRR_BS6                        GPIO_BSRR_BS6_Msk                 /*!< Port x Set bit 6 */
#define GPIO_BSRR_BS7_Pos                    (7U)
#define GPIO_BSRR_BS7_Msk                    (0x1UL << GPIO_BSRR_BS7_Pos)       /*!< 0x00000080 */
#define GPIO_BSRR_BS7                        GPIO_BSRR_BS7_Msk                 /*!< Port x Set bit 7 */
#define GPIO_BSRR_BS8_Pos                    (8U)
#define GPIO_BSRR_BS8_Msk                    (0x1UL << GPIO_BSRR_BS8_Pos)       /*!< 0x00000100 */
#define GPIO_BSRR_BS8                        GPIO_BSRR_BS8_Msk                 /*!< Port x Set bit 8 */
#define GPIO_BSRR_BS9_Pos                    (9U)
#define GPIO_BSRR_BS9_Msk                    (0x1UL << GPIO_BSRR_BS9_Pos)       /*!< 0x00000200 */
#define GPIO_BSRR_BS9                        GPIO_BSRR_BS9_Msk                 /*!< Port x Set bit 9 */
#define GPIO_BSRR_BS10_Pos                   (10U)
#define GPIO_BSRR_BS10_Msk                   (0x1UL << GPIO_BSRR_BS10_Pos)      /*!< 0x00000400 */
#define GPIO_BSRR_BS10                       GPIO_BSRR_BS10_Msk                /*!< Port x Set bit 10 */
#define GPIO_BSRR_BS11_Pos                   (11U)
#define GPIO_BSRR_BS11_Msk                   (0x1UL << GPIO_BSRR_BS11_Pos)      /*!< 0x00000800 */
#define GPIO_BSRR_BS11                       GPIO_BSRR_BS11_Msk                /*!< Port x Set bit 11 */
#define GPIO_BSRR_BS12_Pos                   (12U)
#define GPIO_BSRR_BS12_Msk                   (0x1UL << GPIO_BSRR_BS12_Pos)      /*!< 0x00001000 */
#define GPIO_BSRR_BS12                       GPIO_BSRR_BS12_Msk                /*!< Port x Set bit 12 */
#define GPIO_BSRR_BS13_Pos                   (13U)
#define GPIO_BSRR_BS13_Msk                   (0x1UL << GPIO_BSRR_BS13_Pos)      /*!< 0x00002000 */
#define GPIO_BSRR_BS13                       GPIO_BSRR_BS13_Msk                /*!< Port x Set bit 13 */
#define GPIO_BSRR_BS14_Pos                   (14U)
#define GPIO_BSRR_BS14_Msk                   (0x1UL << GPIO_BSRR_BS14_Pos)      /*!< 0x00004000 */
#define GPIO_BSRR_BS14                       GPIO_BSRR_BS14_Msk                /*!< Port x Set bit 14 */
#define GPIO_BSRR_BS15_Pos                   (15U)
#define GPIO_BSRR_BS15_Msk                   (0x1UL << GPIO_BSRR_BS15_Pos)      /*!< 0x00008000 */
#define GPIO_BSRR_BS15                       GPIO_BSRR_BS15_Msk                /*!< Port x Set bit 15 */

#define GPIO_BSRR_BR0_Pos                    (16U)
#define GPIO_BSRR_BR0_Msk                    (0x1UL << GPIO_BSRR_BR0_Pos)       /*!< 0x00010000 */
#define GPIO_BSRR_BR0                        GPIO_BSRR_BR0_Msk                 /*!< Port x Reset bit 0 */
#define GPIO_BSRR_BR1_Pos                    (17U)
#define GPIO_BSRR_BR1_Msk                    (0x1UL << GPIO_BSRR_BR1_Pos)       /*!< 0x00020000 */
#define GPIO_BSRR_BR1                        GPIO_BSRR_BR1_Msk                 /*!< Port x Reset bit 1 */
#define GPIO_BSRR_BR2_Pos                    (18U)
#define GPIO_BSRR_BR2_Msk                    (0x1UL << GPIO_BSRR_BR2_Pos)       /*!< 0x00040000 */
#define GPIO_BSRR_BR2                        GPIO_BSRR_BR2_Msk                 /*!< Port x Reset bit 2 */
#define GPIO_BSRR_BR3_Pos                    (19U)
#define GPIO_BSRR_BR3_Msk                    (0x1UL << GPIO_BSRR_BR3_Pos)       /*!< 0x00080000 */
#define GPIO_BSRR_BR3                        GPIO_BSRR_BR3_Msk                 /*!< Port x Reset bit 3 */
#define GPIO_BSRR_BR4_Pos                    (20U)
#define GPIO_BSRR_BR4_Msk                    (0x1UL << GPIO_BSRR_BR4_Pos)       /*!< 0x00100000 */
#define GPIO_BSRR_BR4                        GPIO_BSRR_BR4_Msk                 /*!< Port x Reset bit 4 */
#define GPIO_BSRR_BR5_Pos                    (21U)
#define GPIO_BSRR_BR5_Msk                    (0x1UL << GPIO_BSRR_BR5_Pos)       /*!< 0x00200000 */
#define GPIO_BSRR_BR5                        GPIO_BSRR_BR5_Msk                 /*!< Port x Reset bit 5 */
#define GPIO_BSRR_BR6_Pos                    (22U)
#define GPIO_BSRR_BR6_Msk                    (0x1UL << GPIO_BSRR_BR6_Pos)       /*!< 0x00400000 */
#define GPIO_BSRR_BR6                        GPIO_BSRR_BR6_Msk                 /*!< Port x Reset bit 6 */
#define GPIO_BSRR_BR7_Pos                    (23U)
#define GPIO_BSRR_BR7_Msk                    (0x1UL << GPIO_BSRR_BR7_Pos)       /*!< 0x00800000 */
#define GPIO_BSRR_BR7                        GPIO_BSRR_BR7_Msk                 /*!< Port x Reset bit 7 */
#define GPIO_BSRR_BR8_Pos                    (24U)
#define GPIO_BSRR_BR8_Msk                    (0x1UL << GPIO_BSRR_BR8_Pos)       /*!< 0x01000000 */
#define GPIO_BSRR_BR8                        GPIO_BSRR_BR8_Msk                 /*!< Port x Reset bit 8 */
#define GPIO_BSRR_BR9_Pos                    (25U)
#define GPIO_BSRR_BR9_Msk                    (0x1UL << GPIO_BSRR_BR9_Pos)       /*!< 0x02000000 */
#define GPIO_BSRR_BR9                        GPIO_BSRR_BR9_Msk                 /*!< Port x Reset bit 9 */
#define GPIO_BSRR_BR10_Pos                   (26U)
#define GPIO_BSRR_BR10_Msk                   (0x1UL << GPIO_BSRR_BR10_Pos)      /*!< 0x04000000 */
#define GPIO_BSRR_BR10                       GPIO_BSRR_BR10_Msk                /*!< Port x Reset bit 10 */
#define GPIO_BSRR_BR11_Pos                   (27U)
#define GPIO_BSRR_BR11_Msk                   (0x1UL << GPIO_BSRR_BR11_Pos)      /*!< 0x08000000 */
#define GPIO_BSRR_BR11                       GPIO_BSRR_BR11_Msk                /*!< Port x Reset bit 11 */
#define GPIO_BSRR_BR12_Pos                   (28U)
#define GPIO_BSRR_BR12_Msk                   (0x1UL << GPIO_BSRR_BR12_Pos)      /*!< 0x10000000 */
#define GPIO_BSRR_BR12                       GPIO_BSRR_BR12_Msk                /*!< Port x Reset bit 12 */
#define GPIO_BSRR_BR13_Pos                   (29U)
#define GPIO_BSRR_BR13_Msk                   (0x1UL << GPIO_BSRR_BR13_Pos)      /*!< 0x20000000 */
#define GPIO_BSRR_BR13                       GPIO_BSRR_BR13_Msk                /*!< Port x Reset bit 13 */
#define GPIO_BSRR_BR14_Pos                   (30U)
#define GPIO_BSRR_BR14_Msk                   (0x1UL << GPIO_BSRR_BR14_Pos)      /*!< 0x40000000 */
#define GPIO_BSRR_BR14                       GPIO_BSRR_BR14_Msk                /*!< Port x Reset bit 14 */
#define GPIO_BSRR_BR15_Pos                   (31U)
#define GPIO_BSRR_BR15_Msk                   (0x1UL << GPIO_BSRR_BR15_Pos)      /*!< 0x80000000 */
#define GPIO_BSRR_BR15                       GPIO_BSRR_BR15_Msk                /*!< Port x Reset bit 15 */

/*******************  Bit definition for GPIO_BRR register  *******************/
#define GPIO_BRR_BR0_Pos                     (0U)
#define GPIO_BRR_BR0_Msk                     (0x1UL << GPIO_BRR_BR0_Pos)        /*!< 0x00000001 */
#define GPIO_BRR_BR0                         GPIO_BRR_BR0_Msk                  /*!< Port x Reset bit 0 */
#define GPIO_BRR_BR1_Pos                     (1U)
#define GPIO_BRR_BR1_Msk                     (0x1UL << GPIO_BRR_BR1_Pos)        /*!< 0x00000002 */
#define GPIO_BRR_BR1                         GPIO_BRR_BR1_Msk                  /*!< Port x Reset bit 1 */
#define GPIO_BRR_BR2_Pos                     (2U)
#define GPIO_BRR_BR2_Msk                     (0x1UL << GPIO_BRR_BR2_Pos)        /*!< 0x00000004 */
#define GPIO_BRR_BR2                         GPIO_BRR_BR2_Msk                  /*!< Port x Reset bit 2 */
#define GPIO_BRR_BR3_Pos                     (3U)
#define GPIO_BRR_BR3_Msk                     (0x1UL << GPIO_BRR_BR3_Pos)        /*!< 0x00000008 */
#define GPIO_BRR_BR3                         GPIO_BRR_BR3_Msk                  /*!< Port x Reset bit 3 */
#define GPIO_BRR_BR4_Pos                     (4U)
#define GPIO_BRR_BR4_Msk                     (0x1UL << GPIO_BRR_BR4_Pos)        /*!< 0x00000010 */
#define GPIO_BRR_BR4                         GPIO_BRR_BR4_Msk                  /*!< Port x Reset bit 4 */
#define GPIO_BRR_BR5_Pos                     (5U)
#define GPIO_BRR_BR5_Msk                     (0x1UL << GPIO_BRR_BR5_Pos)        /*!< 0x00000020 */
#define GPIO_BRR_BR5                         GPIO_BRR_BR5_Msk                  /*!< Port x Reset bit 5 */
#define GPIO_BRR_BR6_Pos                     (6U)
#define GPIO_BRR_BR6_Msk                     (0x1UL << GPIO_BRR_BR6_Pos)        /*!< 0x00000040 */
#define GPIO_BRR_BR6                         GPIO_BRR_BR6_Msk                  /*!< Port x Reset bit 6 */
#define GPIO_BRR_BR7_Pos                     (7U)
#define GPIO_BRR_BR7_Msk                     (0x1UL << GPIO_BRR_BR7_Pos)        /*!< 0x00000080 */
#define GPIO_BRR_BR7                         GPIO_BRR_BR7_Msk                  /*!< Port x Reset bit 7 */
#define GPIO_BRR_BR8_Pos                     (8U)
#define GPIO_BRR_BR8_Msk                     (0x1UL << GPIO_BRR_BR8_Pos)        /*!< 0x00000100 */
#define GPIO_BRR_BR8                         GPIO_BRR_BR8_Msk                  /*!< Port x Reset bit 8 */
#define GPIO_BRR_BR9_Pos                     (9U)
#define GPIO_BRR_BR9_Msk                     (0x1UL << GPIO_BRR_BR9_Pos)        /*!< 0x00000200 */
#define GPIO_BRR_BR9                         GPIO_BRR_BR9_Msk                  /*!< Port x Reset bit 9 */
#define GPIO_BRR_BR10_Pos                    (10U)
#define GPIO_BRR_BR10_Msk                    (0x1UL << GPIO_BRR_BR10_Pos)       /*!< 0x00000400 */
#define GPIO_BRR_BR10                        GPIO_BRR_BR10_Msk                 /*!< Port x Reset bit 10 */
#define GPIO_BRR_BR11_Pos                    (11U)
#define GPIO_BRR_BR11_Msk                    (0x1UL << GPIO_BRR_BR11_Pos)       /*!< 0x00000800 */
#define GPIO_BRR_BR11                        GPIO_BRR_BR11_Msk                 /*!< Port x Reset bit 11 */
#define GPIO_BRR_BR12_Pos                    (12U)
#define GPIO_BRR_BR12_Msk                    (0x1UL << GPIO_BRR_BR12_Pos)       /*!< 0x00001000 */
#define GPIO_BRR_BR12                        GPIO_BRR_BR12_Msk                 /*!< Port x Reset bit 12 */
#define GPIO_BRR_BR13_Pos                    (13U)
#define GPIO_BRR_BR13_Msk                    (0x1UL << GPIO_BRR_BR13_Pos)       /*!< 0x00002000 */
#define GPIO_BRR_BR13                        GPIO_BRR_BR13_Msk                 /*!< Port x Reset bit 13 */
#define GPIO_BRR_BR14_Pos                    (14U)
#define GPIO_BRR_BR14_Msk                    (0x1UL << GPIO_BRR_BR14_Pos)       /*!< 0x00004000 */
#define GPIO_BRR_BR14                        GPIO_BRR_BR14_Msk                 /*!< Port x Reset bit 14 */
#define GPIO_BRR_BR15_Pos                    (15U)
#define GPIO_BRR_BR15_Msk                    (0x1UL << GPIO_BRR_BR15_Pos)       /*!< 0x00008000 */
#define GPIO_BRR_BR15                        GPIO_BRR_BR15_Msk                 /*!< Port x Reset bit 15 */

/******************  Bit definition for GPIO_LCKR register  *******************/
#define GPIO_LCKR_LCK0_Pos                   (0U)
#define GPIO_LCKR_LCK0_Msk                   (0x1UL << GPIO_LCKR_LCK0_Pos)      /*!< 0x00000001 */
#define GPIO_LCKR_LCK0                       GPIO_LCKR_LCK0_Msk                /*!< Port x Lock bit 0 */
#define GPIO_LCKR_LCK1_Pos                   (1U)
#define GPIO_LCKR_LCK1_Msk                   (0x1UL << GPIO_LCKR_LCK1_Pos)      /*!< 0x00000002 */
#define GPIO_LCKR_LCK1                       GPIO_LCKR_LCK1_Msk                /*!< Port x Lock bit 1 */
#define GPIO_LCKR_LCK2_Pos                   (2U)
#define GPIO_LCKR_LCK2_Msk                   (0x1UL << GPIO_LCKR_LCK2_Pos)      /*!< 0x00000004 */
#define GPIO_LCKR_LCK2                       GPIO_LCKR_LCK2_Msk                /*!< Port x Lock bit 2 */
#define GPIO_LCKR_LCK3_Pos                   (3U)
#define GPIO_LCKR_LCK3_Msk                   (0x1UL << GPIO_LCKR_LCK3_Pos)      /*!< 0x00000008 */
#define GPIO_LCKR_LCK3                       GPIO_LCKR_LCK3_Msk                /*!< Port x Lock bit 3 */
#define GPIO_LCKR_LCK4_Pos                   (4U)
#define GPIO_LCKR_LCK4_Msk                   (0x1UL << GPIO_LCKR_LCK4_Pos)      /*!< 0x00000010 */
#define GPIO_LCKR_LCK4                       GPIO_LCKR_LCK4_Msk                /*!< Port x Lock bit 4 */
#define GPIO_LCKR_LCK5_Pos                   (5U)
#define GPIO_LCKR_LCK5_Msk                   (0x1UL << GPIO_LCKR_LCK5_Pos)      /*!< 0x00000020 */
#define GPIO_LCKR_LCK5                       GPIO_LCKR_LCK5_Msk                /*!< Port x Lock bit 5 */
#define GPIO_LCKR_LCK6_Pos                   (6U)
#define GPIO_LCKR_LCK6_Msk                   (0x1UL << GPIO_LCKR_LCK6_Pos)      /*!< 0x00000040 */
#define GPIO_LCKR_LCK6                       GPIO_LCKR_LCK6_Msk                /*!< Port x Lock bit 6 */
#define GPIO_LCKR_LCK7_Pos                   (7U)
#define GPIO_LCKR_LCK7_Msk                   (0x1UL << GPIO_LCKR_LCK7_Pos)      /*!< 0x00000080 */
#define GPIO_LCKR_LCK7                       GPIO_LCKR_LCK7_Msk                /*!< Port x Lock bit 7 */
#define GPIO_LCKR_LCK8_Pos                   (8U)
#define GPIO_LCKR_LCK8_Msk                   (0x1UL << GPIO_LCKR_LCK8_Pos)      /*!< 0x00000100 */
#define GPIO_LCKR_LCK8                       GPIO_LCKR_LCK8_Msk                /*!< Port x Lock bit 8 */
#define GPIO_LCKR_LCK9_Pos                   (9U)
#define GPIO_LCKR_LCK9_Msk                   (0x1UL << GPIO_LCKR_LCK9_Pos)      /*!< 0x00000200 */
#define GPIO_LCKR_LCK9                       GPIO_LCKR_LCK9_Msk                /*!< Port x Lock bit 9 */
#define GPIO_LCKR_LCK10_Pos                  (10U)
#define GPIO_LCKR_LCK10_Msk                  (0x1UL << GPIO_LCKR_LCK10_Pos)     /*!< 0x00000400 */
#define GPIO_LCKR_LCK10                      GPIO_LCKR_LCK10_Msk               /*!< Port x Lock bit 10 */
#define GPIO_LCKR_LCK11_Pos                  (11U)
#define GPIO_LCKR_LCK11_Msk                  (0x1UL << GPIO_LCKR_LCK11_Pos)     /*!< 0x00000800 */
#define GPIO_LCKR_LCK11                      GPIO_LCKR_LCK11_Msk               /*!< Port x Lock bit 11 */
#define GPIO_LCKR_LCK12_Pos                  (12U)
#define GPIO_LCKR_LCK12_Msk                  (0x1UL << GPIO_LCKR_LCK12_Pos)     /*!< 0x00001000 */
#define GPIO_LCKR_LCK12                      GPIO_LCKR_LCK12_Msk               /*!< Port x Lock bit 12 */
#define GPIO_LCKR_LCK13_Pos                  (13U)
#define GPIO_LCKR_LCK13_Msk                  (0x1UL << GPIO_LCKR_LCK13_Pos)     /*!< 0x00002000 */
#define GPIO_LCKR_LCK13                      GPIO_LCKR_LCK13_Msk               /*!< Port x Lock bit 13 */
#define GPIO_LCKR_LCK14_Pos                  (14U)
#define GPIO_LCKR_LCK14_Msk                  (0x1UL << GPIO_LCKR_LCK14_Pos)     /*!< 0x00004000 */
#define GPIO_LCKR_LCK14                      GPIO_LCKR_LCK14_Msk               /*!< Port x Lock bit 14 */
#define GPIO_LCKR_LCK15_Pos                  (15U)
#define GPIO_LCKR_LCK15_Msk                  (0x1UL << GPIO_LCKR_LCK15_Pos)     /*!< 0x00008000 */
#define GPIO_LCKR_LCK15                      GPIO_LCKR_LCK15_Msk               /*!< Port x Lock bit 15 */
#define GPIO_LCKR_LCKK_Pos                   (16U)
#define GPIO_LCKR_LCKK_Msk                   (0x1UL << GPIO_LCKR_LCKK_Pos)      /*!< 0x00010000 */
#define GPIO_LCKR_LCKK                       GPIO_LCKR_LCKK_Msk                /*!< Lock key */

/*----------------------------------------------------------------------------*/

/******************************************************************************/
/*                                                                            */
/*                         Controller Area Network                            */
/*                                                                            */
/******************************************************************************/

/*!< CAN control and status registers */
/*******************  Bit definition for CAN_MCR register  ********************/
#define CAN_MCR_INRQ_Pos                     (0U)
#define CAN_MCR_INRQ_Msk                     (0x1UL << CAN_MCR_INRQ_Pos)        /*!< 0x00000001 */
#define CAN_MCR_INRQ                         CAN_MCR_INRQ_Msk                  /*!< Initialization Request */
#define CAN_MCR_SLEEP_Pos                    (1U)
#define CAN_MCR_SLEEP_Msk                    (0x1UL << CAN_MCR_SLEEP_Pos)       /*!< 0x00000002 */
#define CAN_MCR_SLEEP                        CAN_MCR_SLEEP_Msk                 /*!< Sleep Mode Request */
#define CAN_MCR_TXFP_Pos                     (2U)
#define CAN_MCR_TXFP_Msk                     (0x1UL << CAN_MCR_TXFP_Pos)        /*!< 0x00000004 */
#define CAN_MCR_TXFP                         CAN_MCR_TXFP_Msk                  /*!< Transmit FIFO Priority */
#define CAN_MCR_RFLM_Pos                     (3U)
#define CAN_MCR_RFLM_Msk                     (0x1UL << CAN_MCR_RFLM_Pos)        /*!< 0x00000008 */
#define CAN_MCR_RFLM                         CAN_MCR_RFLM_Msk                  /*!< Receive FIFO Locked Mode */
#define CAN_MCR_NART_Pos                     (4U)
#define CAN_MCR_NART_Msk                     (0x1UL << CAN_MCR_NART_Pos)        /*!< 0x00000010 */
#define CAN_MCR_NART                         CAN_MCR_NART_Msk                  /*!< No Automatic Retransmission */
#define CAN_MCR_AWUM_Pos                     (5U)
#define CAN_MCR_AWUM_Msk                     (0x1UL << CAN_MCR_AWUM_Pos)        /*!< 0x00000020 */
#define CAN_MCR_AWUM                         CAN_MCR_AWUM_Msk                  /*!< Automatic Wakeup Mode */
#define CAN_MCR_ABOM_Pos                     (6U)
#define CAN_MCR_ABOM_Msk                     (0x1UL << CAN_MCR_ABOM_Pos)        /*!< 0x00000040 */
#define CAN_MCR_ABOM                         CAN_MCR_ABOM_Msk                  /*!< Automatic Bus-Off Management */
#define CAN_MCR_TTCM_Pos                     (7U)
#define CAN_MCR_TTCM_Msk                     (0x1UL << CAN_MCR_TTCM_Pos)        /*!< 0x00000080 */
#define CAN_MCR_TTCM                         CAN_MCR_TTCM_Msk                  /*!< Time Triggered Communication Mode */
#define CAN_MCR_RESET_Pos                    (15U)
#define CAN_MCR_RESET_Msk                    (0x1UL << CAN_MCR_RESET_Pos)       /*!< 0x00008000 */
#define CAN_MCR_RESET                        CAN_MCR_RESET_Msk                 /*!< CAN software master reset */
#define CAN_MCR_DBF_Pos                      (16U)
#define CAN_MCR_DBF_Msk                      (0x1UL << CAN_MCR_DBF_Pos)         /*!< 0x00010000 */
#define CAN_MCR_DBF                          CAN_MCR_DBF_Msk                   /*!< CAN Debug freeze */

/*******************  Bit definition for CAN_MSR register  ********************/
#define CAN_MSR_INAK_Pos                     (0U)
#define CAN_MSR_INAK_Msk                     (0x1UL << CAN_MSR_INAK_Pos)        /*!< 0x00000001 */
#define CAN_MSR_INAK                         CAN_MSR_INAK_Msk                  /*!< Initialization Acknowledge */
#define CAN_MSR_SLAK_Pos                     (1U)
#define CAN_MSR_SLAK_Msk                     (0x1UL << CAN_MSR_SLAK_Pos)        /*!< 0x00000002 */
#define CAN_MSR_SLAK                         CAN_MSR_SLAK_Msk                  /*!< Sleep Acknowledge */
#define CAN_MSR_ERRI_Pos                     (2U)
#define CAN_MSR_ERRI_Msk                     (0x1UL << CAN_MSR_ERRI_Pos)        /*!< 0x00000004 */
#define CAN_MSR_ERRI                         CAN_MSR_ERRI_Msk                  /*!< Error Interrupt */
#define CAN_MSR_WKUI_Pos                     (3U)
#define CAN_MSR_WKUI_Msk                     (0x1UL << CAN_MSR_WKUI_Pos)        /*!< 0x00000008 */
#define CAN_MSR_WKUI                         CAN_MSR_WKUI_Msk                  /*!< Wakeup Interrupt */
#define CAN_MSR_SLAKI_Pos                    (4U)
#define CAN_MSR_SLAKI_Msk                    (0x1UL << CAN_MSR_SLAKI_Pos)       /*!< 0x00000010 */
#define CAN_MSR_SLAKI                        CAN_MSR_SLAKI_Msk                 /*!< Sleep Acknowledge Interrupt */
#define CAN_MSR_TXM_Pos                      (8U)
#define CAN_MSR_TXM_Msk                      (0x1UL << CAN_MSR_TXM_Pos)         /*!< 0x00000100 */
#define CAN_MSR_TXM                          CAN_MSR_TXM_Msk                   /*!< Transmit Mode */
#define CAN_MSR_RXM_Pos                      (9U)
#define CAN_MSR_RXM_Msk                      (0x1UL << CAN_MSR_RXM_Pos)         /*!< 0x00000200 */
#define CAN_MSR_RXM                          CAN_MSR_RXM_Msk                   /*!< Receive Mode */
#define CAN_MSR_SAMP_Pos                     (10U)
#define CAN_MSR_SAMP_Msk                     (0x1UL << CAN_MSR_SAMP_Pos)        /*!< 0x00000400 */
#define CAN_MSR_SAMP                         CAN_MSR_SAMP_Msk                  /*!< Last Sample Point */
#define CAN_MSR_RX_Pos                       (11U)
#define CAN_MSR_RX_Msk                       (0x1UL << CAN_MSR_RX_Pos)          /*!< 0x00000800 */
#define CAN_MSR_RX                           CAN_MSR_RX_Msk                    /*!< CAN Rx Signal */

/*******************  Bit definition for CAN_TSR register  ********************/
#define CAN_TSR_RQCP0_Pos                    (0U)
#define CAN_TSR_RQCP0_Msk                    (0x1UL << CAN_TSR_RQCP0_Pos)       /*!< 0x00000001 */
#define CAN_TSR_RQCP0                        CAN_TSR_RQCP0_Msk                 /*!< Request Completed Mailbox0 */
#define CAN_TSR_TXOK0_Pos                    (1U)
#define CAN_TSR_TXOK0_Msk                    (0x1UL << CAN_TSR_TXOK0_Pos)       /*!< 0x00000002 */
#define CAN_TSR_TXOK0                        CAN_TSR_TXOK0_Msk                 /*!< Transmission OK of Mailbox0 */
#define CAN_TSR_ALST0_Pos                    (2U)
#define CAN_TSR_ALST0_Msk                    (0x1UL << CAN_TSR_ALST0_Pos)       /*!< 0x00000004 */
#define CAN_TSR_ALST0                        CAN_TSR_ALST0_Msk                 /*!< Arbitration Lost for Mailbox0 */
#define CAN_TSR_TERR0_Pos                    (3U)
#define CAN_TSR_TERR0_Msk                    (0x1UL << CAN_TSR_TERR0_Pos)       /*!< 0x00000008 */
#define CAN_TSR_TERR0                        CAN_TSR_TERR0_Msk                 /*!< Transmission Error of Mailbox0 */
#define CAN_TSR_ABRQ0_Pos                    (7U)
#define CAN_TSR_ABRQ0_Msk                    (0x1UL << CAN_TSR_ABRQ0_Pos)       /*!< 0x00000080 */
#define CAN_TSR_ABRQ0                        CAN_TSR_ABRQ0_Msk                 /*!< Abort Request for Mailbox0 */
#define CAN_TSR_RQCP1_Pos                    (8U)
#define CAN_TSR_RQCP1_Msk                    (0x1UL << CAN_TSR_RQCP1_Pos)       /*!< 0x00000100 */
#define CAN_TSR_RQCP1                        CAN_TSR_RQCP1_Msk                 /*!< Request Completed Mailbox1 */
#define CAN_TSR_TXOK1_Pos                    (9U)
#define CAN_TSR_TXOK1_Msk                    (0x1UL << CAN_TSR_TXOK1_Pos)       /*!< 0x00000200 */
#define CAN_TSR_TXOK1                        CAN_TSR_TXOK1_Msk                 /*!< Transmission OK of Mailbox1 */
#define CAN_TSR_ALST1_Pos                    (10U)
#define CAN_TSR_ALST1_Msk                    (0x1UL << CAN_TSR_ALST1_Pos)       /*!< 0x00000400 */
#define CAN_TSR_ALST1                        CAN_TSR_ALST1_Msk                 /*!< Arbitration Lost for Mailbox1 */
#define CAN_TSR_TERR1_Pos                    (11U)
#define CAN_TSR_TERR1_Msk                    (0x1UL << CAN_TSR_TERR1_Pos)       /*!< 0x00000800 */
#define CAN_TSR_TERR1                        CAN_TSR_TERR1_Msk                 /*!< Transmission Error of Mailbox1 */
#define CAN_TSR_ABRQ1_Pos                    (15U)
#define CAN_TSR_ABRQ1_Msk                    (0x1UL << CAN_TSR_ABRQ1_Pos)       /*!< 0x00008000 */
#define CAN_TSR_ABRQ1                        CAN_TSR_ABRQ1_Msk                 /*!< Abort Request for Mailbox 1 */
#define CAN_TSR_RQCP2_Pos                    (16U)
#define CAN_TSR_RQCP2_Msk                    (0x1UL << CAN_TSR_RQCP2_Pos)       /*!< 0x00010000 */
#define CAN_TSR_RQCP2                        CAN_TSR_RQCP2_Msk                 /*!< Request Completed Mailbox2 */
#define CAN_TSR_TXOK2_Pos                    (17U)
#define CAN_TSR_TXOK2_Msk                    (0x1UL << CAN_TSR_TXOK2_Pos)       /*!< 0x00020000 */
#define CAN_TSR_TXOK2                        CAN_TSR_TXOK2_Msk                 /*!< Transmission OK of Mailbox 2 */
#define CAN_TSR_ALST2_Pos                    (18U)
#define CAN_TSR_ALST2_Msk                    (0x1UL << CAN_TSR_ALST2_Pos)       /*!< 0x00040000 */
#define CAN_TSR_ALST2                        CAN_TSR_ALST2_Msk                 /*!< Arbitration Lost for mailbox 2 */
#define CAN_TSR_TERR2_Pos                    (19U)
#define CAN_TSR_TERR2_Msk                    (0x1UL << CAN_TSR_TERR2_Pos)       /*!< 0x00080000 */
#define CAN_TSR_TERR2                        CAN_TSR_TERR2_Msk                 /*!< Transmission Error of Mailbox 2 */
#define CAN_TSR_ABRQ2_Pos                    (23U)
#define CAN_TSR_ABRQ2_Msk                    (0x1UL << CAN_TSR_ABRQ2_Pos)       /*!< 0x00800000 */
#define CAN_TSR_ABRQ2                        CAN_TSR_ABRQ2_Msk                 /*!< Abort Request for Mailbox 2 */
#define CAN_TSR_CODE_Pos                     (24U)
#define CAN_TSR_CODE_Msk                     (0x3UL << CAN_TSR_CODE_Pos)        /*!< 0x03000000 */
#define CAN_TSR_CODE                         CAN_TSR_CODE_Msk                  /*!< Mailbox Code */

#define CAN_TSR_TME_Pos                      (26U)
#define CAN_TSR_TME_Msk                      (0x7UL << CAN_TSR_TME_Pos)         /*!< 0x1C000000 */
#define CAN_TSR_TME                          CAN_TSR_TME_Msk                   /*!< TME[2:0] bits */
#define CAN_TSR_TME0_Pos                     (26U)
#define CAN_TSR_TME0_Msk                     (0x1UL << CAN_TSR_TME0_Pos)        /*!< 0x04000000 */
#define CAN_TSR_TME0                         CAN_TSR_TME0_Msk                  /*!< Transmit Mailbox 0 Empty */
#define CAN_TSR_TME1_Pos                     (27U)
#define CAN_TSR_TME1_Msk                     (0x1UL << CAN_TSR_TME1_Pos)        /*!< 0x08000000 */
#define CAN_TSR_TME1                         CAN_TSR_TME1_Msk                  /*!< Transmit Mailbox 1 Empty */
#define CAN_TSR_TME2_Pos                     (28U)
#define CAN_TSR_TME2_Msk                     (0x1UL << CAN_TSR_TME2_Pos)        /*!< 0x10000000 */
#define CAN_TSR_TME2                         CAN_TSR_TME2_Msk                  /*!< Transmit Mailbox 2 Empty */

#define CAN_TSR_LOW_Pos                      (29U)
#define CAN_TSR_LOW_Msk                      (0x7UL << CAN_TSR_LOW_Pos)         /*!< 0xE0000000 */
#define CAN_TSR_LOW                          CAN_TSR_LOW_Msk                   /*!< LOW[2:0] bits */
#define CAN_TSR_LOW0_Pos                     (29U)
#define CAN_TSR_LOW0_Msk                     (0x1UL << CAN_TSR_LOW0_Pos)        /*!< 0x20000000 */
#define CAN_TSR_LOW0                         CAN_TSR_LOW0_Msk                  /*!< Lowest Priority Flag for Mailbox 0 */
#define CAN_TSR_LOW1_Pos                     (30U)
#define CAN_TSR_LOW1_Msk                     (0x1UL << CAN_TSR_LOW1_Pos)        /*!< 0x40000000 */
#define CAN_TSR_LOW1                         CAN_TSR_LOW1_Msk                  /*!< Lowest Priority Flag for Mailbox 1 */
#define CAN_TSR_LOW2_Pos                     (31U)
#define CAN_TSR_LOW2_Msk                     (0x1UL << CAN_TSR_LOW2_Pos)        /*!< 0x80000000 */
#define CAN_TSR_LOW2                         CAN_TSR_LOW2_Msk                  /*!< Lowest Priority Flag for Mailbox 2 */

/*******************  Bit definition for CAN_RF0R register  *******************/
#define CAN_RF0R_FMP0_Pos                    (0U)
#define CAN_RF0R_FMP0_Msk                    (0x3UL << CAN_RF0R_FMP0_Pos)       /*!< 0x00000003 */
#define CAN_RF0R_FMP0                        CAN_RF0R_FMP0_Msk                 /*!< FIFO 0 Message Pending */
#define CAN_RF0R_FULL0_Pos                   (3U)
#define CAN_RF0R_FULL0_Msk                   (0x1UL << CAN_RF0R_FULL0_Pos)      /*!< 0x00000008 */
#define CAN_RF0R_FULL0                       CAN_RF0R_FULL0_Msk                /*!< FIFO 0 Full */
#define CAN_RF0R_FOVR0_Pos                   (4U)
#define CAN_RF0R_FOVR0_Msk                   (0x1UL << CAN_RF0R_FOVR0_Pos)      /*!< 0x00000010 */
#define CAN_RF0R_FOVR0                       CAN_RF0R_FOVR0_Msk                /*!< FIFO 0 Overrun */
#define CAN_RF0R_RFOM0_Pos                   (5U)
#define CAN_RF0R_RFOM0_Msk                   (0x1UL << CAN_RF0R_RFOM0_Pos)      /*!< 0x00000020 */
#define CAN_RF0R_RFOM0                       CAN_RF0R_RFOM0_Msk                /*!< Release FIFO 0 Output Mailbox */

/*******************  Bit definition for CAN_RF1R register  *******************/
#define CAN_RF1R_FMP1_Pos                    (0U)
#define CAN_RF1R_FMP1_Msk                    (0x3UL << CAN_RF1R_FMP1_Pos)       /*!< 0x00000003 */
#define CAN_RF1R_FMP1                        CAN_RF1R_FMP1_Msk                 /*!< FIFO 1 Message Pending */
#define CAN_RF1R_FULL1_Pos                   (3U)
#define CAN_RF1R_FULL1_Msk                   (0x1UL << CAN_RF1R_FULL1_Pos)      /*!< 0x00000008 */
#define CAN_RF1R_FULL1                       CAN_RF1R_FULL1_Msk                /*!< FIFO 1 Full */
#define CAN_RF1R_FOVR1_Pos                   (4U)
#define CAN_RF1R_FOVR1_Msk                   (0x1UL << CAN_RF1R_FOVR1_Pos)      /*!< 0x00000010 */
#define CAN_RF1R_FOVR1                       CAN_RF1R_FOVR1_Msk                /*!< FIFO 1 Overrun */
#define CAN_RF1R_RFOM1_Pos                   (5U)
#define CAN_RF1R_RFOM1_Msk                   (0x1UL << CAN_RF1R_RFOM1_Pos)      /*!< 0x00000020 */
#define CAN_RF1R_RFOM1                       CAN_RF1R_RFOM1_Msk                /*!< Release FIFO 1 Output Mailbox */

/********************  Bit definition for CAN_IER register  *******************/
#define CAN_IER_TMEIE_Pos                    (0U)
#define CAN_IER_TMEIE_Msk                    (0x1UL << CAN_IER_TMEIE_Pos)       /*!< 0x00000001 */
#define CAN_IER_TMEIE                        CAN_IER_TMEIE_Msk                 /*!< Transmit Mailbox Empty Interrupt Enable */
#define CAN_IER_FMPIE0_Pos                   (1U)
#define CAN_IER_FMPIE0_Msk                   (0x1UL << CAN_IER_FMPIE0_Pos)      /*!< 0x00000002 */
#define CAN_IER_FMPIE0                       CAN_IER_FMPIE0_Msk                /*!< FIFO Message Pending Interrupt Enable */
#define CAN_IER_FFIE0_Pos                    (2U)
#define CAN_IER_FFIE0_Msk                    (0x1UL << CAN_IER_FFIE0_Pos)       /*!< 0x00000004 */
#define CAN_IER_FFIE0                        CAN_IER_FFIE0_Msk                 /*!< FIFO Full Interrupt Enable */
#define CAN_IER_FOVIE0_Pos                   (3U)
#define CAN_IER_FOVIE0_Msk                   (0x1UL << CAN_IER_FOVIE0_Pos)      /*!< 0x00000008 */
#define CAN_IER_FOVIE0                       CAN_IER_FOVIE0_Msk                /*!< FIFO Overrun Interrupt Enable */
#define CAN_IER_FMPIE1_Pos                   (4U)
#define CAN_IER_FMPIE1_Msk                   (0x1UL << CAN_IER_FMPIE1_Pos)      /*!< 0x00000010 */
#define CAN_IER_FMPIE1                       CAN_IER_FMPIE1_Msk                /*!< FIFO Message Pending Interrupt Enable */
#define CAN_IER_FFIE1_Pos                    (5U)
#define CAN_IER_FFIE1_Msk                    (0x1UL << CAN_IER_FFIE1_Pos)       /*!< 0x00000020 */
#define CAN_IER_FFIE1                        CAN_IER_FFIE1_Msk                 /*!< FIFO Full Interrupt Enable */
#define CAN_IER_FOVIE1_Pos                   (6U)
#define CAN_IER_FOVIE1_Msk                   (0x1UL << CAN_IER_FOVIE1_Pos)      /*!< 0x00000040 */
#define CAN_IER_FOVIE1                       CAN_IER_FOVIE1_Msk                /*!< FIFO Overrun Interrupt Enable */
#define CAN_IER_EWGIE_Pos                    (8U)
#define CAN_IER_EWGIE_Msk                    (0x1UL << CAN_IER_EWGIE_Pos)       /*!< 0x00000100 */
#define CAN_IER_EWGIE                        CAN_IER_EWGIE_Msk                 /*!< Error Warning Interrupt Enable */
#define CAN_IER_EPVIE_Pos                    (9U)
#define CAN_IER_EPVIE_Msk                    (0x1UL << CAN_IER_EPVIE_Pos)       /*!< 0x00000200 */
#define CAN_IER_EPVIE                        CAN_IER_EPVIE_Msk                 /*!< Error Passive Interrupt Enable */
#define CAN_IER_BOFIE_Pos                    (10U)
#define CAN_IER_BOFIE_Msk                    (0x1UL << CAN_IER_BOFIE_Pos)       /*!< 0x00000400 */
#define CAN_IER_BOFIE                        CAN_IER_BOFIE_Msk                 /*!< Bus-Off Interrupt Enable */
#define CAN_IER_LECIE_Pos                    (11U)
#define CAN_IER_LECIE_Msk                    (0x1UL << CAN_IER_LECIE_Pos)       /*!< 0x00000800 */
#define CAN_IER_LECIE                        CAN_IER_LECIE_Msk                 /*!< Last Error Code Interrupt Enable */
#define CAN_IER_ERRIE_Pos                    (15U)
#define CAN_IER_ERRIE_Msk                    (0x1UL << CAN_IER_ERRIE_Pos)       /*!< 0x00008000 */
#define CAN_IER_ERRIE                        CAN_IER_ERRIE_Msk                 /*!< Error Interrupt Enable */
#define CAN_IER_WKUIE_Pos                    (16U)
#define CAN_IER_WKUIE_Msk                    (0x1UL << CAN_IER_WKUIE_Pos)       /*!< 0x00010000 */
#define CAN_IER_WKUIE                        CAN_IER_WKUIE_Msk                 /*!< Wakeup Interrupt Enable */
#define CAN_IER_SLKIE_Pos                    (17U)
#define CAN_IER_SLKIE_Msk                    (0x1UL << CAN_IER_SLKIE_Pos)       /*!< 0x00020000 */
#define CAN_IER_SLKIE                        CAN_IER_SLKIE_Msk                 /*!< Sleep Interrupt Enable */

/********************  Bit definition for CAN_ESR register  *******************/
#define CAN_ESR_EWGF_Pos                     (0U)
#define CAN_ESR_EWGF_Msk                     (0x1UL << CAN_ESR_EWGF_Pos)        /*!< 0x00000001 */
#define CAN_ESR_EWGF                         CAN_ESR_EWGF_Msk                  /*!< Error Warning Flag */
#define CAN_ESR_EPVF_Pos                     (1U)
#define CAN_ESR_EPVF_Msk                     (0x1UL << CAN_ESR_EPVF_Pos)        /*!< 0x00000002 */
#define CAN_ESR_EPVF                         CAN_ESR_EPVF_Msk                  /*!< Error Passive Flag */
#define CAN_ESR_BOFF_Pos                     (2U)
#define CAN_ESR_BOFF_Msk                     (0x1UL << CAN_ESR_BOFF_Pos)        /*!< 0x00000004 */
#define CAN_ESR_BOFF                         CAN_ESR_BOFF_Msk                  /*!< Bus-Off Flag */

#define CAN_ESR_LEC_Pos                      (4U)
#define CAN_ESR_LEC_Msk                      (0x7UL << CAN_ESR_LEC_Pos)         /*!< 0x00000070 */
#define CAN_ESR_LEC                          CAN_ESR_LEC_Msk                   /*!< LEC[2:0] bits (Last Error Code) */
#define CAN_ESR_LEC_0                        (0x1UL << CAN_ESR_LEC_Pos)         /*!< 0x00000010 */
#define CAN_ESR_LEC_1                        (0x2UL << CAN_ESR_LEC_Pos)         /*!< 0x00000020 */
#define CAN_ESR_LEC_2                        (0x4UL << CAN_ESR_LEC_Pos)         /*!< 0x00000040 */

#define CAN_ESR_TEC_Pos                      (16U)
#define CAN_ESR_TEC_Msk                      (0xFFUL << CAN_ESR_TEC_Pos)        /*!< 0x00FF0000 */
#define CAN_ESR_TEC                          CAN_ESR_TEC_Msk                   /*!< Least significant byte of the 9-bit Transmit Error Counter */
#define CAN_ESR_REC_Pos                      (24U)
#define CAN_ESR_REC_Msk                      (0xFFUL << CAN_ESR_REC_Pos)        /*!< 0xFF000000 */
#define CAN_ESR_REC                          CAN_ESR_REC_Msk                   /*!< Receive Error Counter */

/*******************  Bit definition for CAN_BTR register  ********************/
#define CAN_BTR_BRP_Pos                      (0U)
#define CAN_BTR_BRP_Msk                      (0x3FFUL << CAN_BTR_BRP_Pos)       /*!< 0x000003FF */
#define CAN_BTR_BRP                          CAN_BTR_BRP_Msk                   /*!<Baud Rate Prescaler */
#define CAN_BTR_TS1_Pos                      (16U)
#define CAN_BTR_TS1_Msk                      (0xFUL << CAN_BTR_TS1_Pos)         /*!< 0x000F0000 */
#define CAN_BTR_TS1                          CAN_BTR_TS1_Msk                   /*!<Time Segment 1 */
#define CAN_BTR_TS1_0                        (0x1UL << CAN_BTR_TS1_Pos)         /*!< 0x00010000 */
#define CAN_BTR_TS1_1                        (0x2UL << CAN_BTR_TS1_Pos)         /*!< 0x00020000 */
#define CAN_BTR_TS1_2                        (0x4UL << CAN_BTR_TS1_Pos)         /*!< 0x00040000 */
#define CAN_BTR_TS1_3                        (0x8UL << CAN_BTR_TS1_Pos)         /*!< 0x00080000 */
#define CAN_BTR_TS2_Pos                      (20U)
#define CAN_BTR_TS2_Msk                      (0x7UL << CAN_BTR_TS2_Pos)         /*!< 0x00700000 */
#define CAN_BTR_TS2                          CAN_BTR_TS2_Msk                   /*!<Time Segment 2 */
#define CAN_BTR_TS2_0                        (0x1UL << CAN_BTR_TS2_Pos)         /*!< 0x00100000 */
#define CAN_BTR_TS2_1                        (0x2UL << CAN_BTR_TS2_Pos)         /*!< 0x00200000 */
#define CAN_BTR_TS2_2                        (0x4UL << CAN_BTR_TS2_Pos)         /*!< 0x00400000 */
#define CAN_BTR_SJW_Pos                      (24U)
#define CAN_BTR_SJW_Msk                      (0x3UL << CAN_BTR_SJW_Pos)         /*!< 0x03000000 */
#define CAN_BTR_SJW                          CAN_BTR_SJW_Msk                   /*!<Resynchronization Jump Width */
#define CAN_BTR_SJW_0                        (0x1UL << CAN_BTR_SJW_Pos)         /*!< 0x01000000 */
#define CAN_BTR_SJW_1                        (0x2UL << CAN_BTR_SJW_Pos)         /*!< 0x02000000 */
#define CAN_BTR_LBKM_Pos                     (30U)
#define CAN_BTR_LBKM_Msk                     (0x1UL << CAN_BTR_LBKM_Pos)        /*!< 0x40000000 */
#define CAN_BTR_LBKM                         CAN_BTR_LBKM_Msk                  /*!<Loop Back Mode (Debug) */
#define CAN_BTR_SILM_Pos                     (31U)
#define CAN_BTR_SILM_Msk                     (0x1UL << CAN_BTR_SILM_Pos)        /*!< 0x80000000 */
#define CAN_BTR_SILM                         CAN_BTR_SILM_Msk                  /*!<Silent Mode */

/*!< Mailbox registers */
/******************  Bit definition for CAN_TI0R register  ********************/
#define CAN_TI0R_TXRQ_Pos                    (0U)
#define CAN_TI0R_TXRQ_Msk                    (0x1UL << CAN_TI0R_TXRQ_Pos)       /*!< 0x00000001 */
#define CAN_TI0R_TXRQ                        CAN_TI0R_TXRQ_Msk                 /*!< Transmit Mailbox Request */
#define CAN_TI0R_RTR_Pos                     (1U)
#define CAN_TI0R_RTR_Msk                     (0x1UL << CAN_TI0R_RTR_Pos)        /*!< 0x00000002 */
#define CAN_TI0R_RTR                         CAN_TI0R_RTR_Msk                  /*!< Remote Transmission Request */
#define CAN_TI0R_IDE_Pos                     (2U)
#define CAN_TI0R_IDE_Msk                     (0x1UL << CAN_TI0R_IDE_Pos)        /*!< 0x00000004 */
#define CAN_TI0R_IDE                         CAN_TI0R_IDE_Msk                  /*!< Identifier Extension */
#define CAN_TI0R_EXID_Pos                    (3U)
#define CAN_TI0R_EXID_Msk                    (0x3FFFFUL << CAN_TI0R_EXID_Pos)   /*!< 0x001FFFF8 */
#define CAN_TI0R_EXID                        CAN_TI0R_EXID_Msk                 /*!< Extended Identifier */
#define CAN_TI0R_STID_Pos                    (21U)
#define CAN_TI0R_STID_Msk                    (0x7FFUL << CAN_TI0R_STID_Pos)     /*!< 0xFFE00000 */
#define CAN_TI0R_STID                        CAN_TI0R_STID_Msk                 /*!< Standard Identifier or Extended Identifier */

/******************  Bit definition for CAN_TDT0R register  *******************/
#define CAN_TDT0R_DLC_Pos                    (0U)
#define CAN_TDT0R_DLC_Msk                    (0xFUL << CAN_TDT0R_DLC_Pos)       /*!< 0x0000000F */
#define CAN_TDT0R_DLC                        CAN_TDT0R_DLC_Msk                 /*!< Data Length Code */
#define CAN_TDT0R_TGT_Pos                    (8U)
#define CAN_TDT0R_TGT_Msk                    (0x1UL << CAN_TDT0R_TGT_Pos)       /*!< 0x00000100 */
#define CAN_TDT0R_TGT                        CAN_TDT0R_TGT_Msk                 /*!< Transmit Global Time */
#define CAN_TDT0R_TIME_Pos                   (16U)
#define CAN_TDT0R_TIME_Msk                   (0xFFFFUL << CAN_TDT0R_TIME_Pos)   /*!< 0xFFFF0000 */
#define CAN_TDT0R_TIME                       CAN_TDT0R_TIME_Msk                /*!< Message Time Stamp */

/******************  Bit definition for CAN_TDL0R register  *******************/
#define CAN_TDL0R_DATA0_Pos                  (0U)
#define CAN_TDL0R_DATA0_Msk                  (0xFFUL << CAN_TDL0R_DATA0_Pos)    /*!< 0x000000FF */
#define CAN_TDL0R_DATA0                      CAN_TDL0R_DATA0_Msk               /*!< Data byte 0 */
#define CAN_TDL0R_DATA1_Pos                  (8U)
#define CAN_TDL0R_DATA1_Msk                  (0xFFUL << CAN_TDL0R_DATA1_Pos)    /*!< 0x0000FF00 */
#define CAN_TDL0R_DATA1                      CAN_TDL0R_DATA1_Msk               /*!< Data byte 1 */
#define CAN_TDL0R_DATA2_Pos                  (16U)
#define CAN_TDL0R_DATA2_Msk                  (0xFFUL << CAN_TDL0R_DATA2_Pos)    /*!< 0x00FF0000 */
#define CAN_TDL0R_DATA2                      CAN_TDL0R_DATA2_Msk               /*!< Data byte 2 */
#define CAN_TDL0R_DATA3_Pos                  (24U)
#define CAN_TDL0R_DATA3_Msk                  (0xFFUL << CAN_TDL0R_DATA3_Pos)    /*!< 0xFF000000 */
#define CAN_TDL0R_DATA3                      CAN_TDL0R_DATA3_Msk               /*!< Data byte 3 */

/******************  Bit definition for CAN_TDH0R register  *******************/
#define CAN_TDH0R_DATA4_Pos                  (0U)
#define CAN_TDH0R_DATA4_Msk                  (0xFFUL << CAN_TDH0R_DATA4_Pos)    /*!< 0x000000FF */
#define CAN_TDH0R_DATA4                      CAN_TDH0R_DATA4_Msk               /*!< Data byte 4 */
#define CAN_TDH0R_DATA5_Pos                  (8U)
#define CAN_TDH0R_DATA5_Msk                  (0xFFUL << CAN_TDH0R_DATA5_Pos)    /*!< 0x0000FF00 */
#define CAN_TDH0R_DATA5                      CAN_TDH0R_DATA5_Msk               /*!< Data byte 5 */
#define CAN_TDH0R_DATA6_Pos                  (16U)
#define CAN_TDH0R_DATA6_Msk                  (0xFFUL << CAN_TDH0R_DATA6_Pos)    /*!< 0x00FF0000 */
#define CAN_TDH0R_DATA6                      CAN_TDH0R_DATA6_Msk               /*!< Data byte 6 */
#define CAN_TDH0R_DATA7_Pos                  (24U)
#define CAN_TDH0R_DATA7_Msk                  (0xFFUL << CAN_TDH0R_DATA7_Pos)    /*!< 0xFF000000 */
#define CAN_TDH0R_DATA7                      CAN_TDH0R_DATA7_Msk               /*!< Data byte 7 */

/*******************  Bit definition for CAN_TI1R register  *******************/
#define CAN_TI1R_TXRQ_Pos                    (0U)
#define CAN_TI1R_TXRQ_Msk                    (0x1UL << CAN_TI1R_TXRQ_Pos)       /*!< 0x00000001 */
#define CAN_TI1R_TXRQ                        CAN_TI1R_TXRQ_Msk                 /*!< Transmit Mailbox Request */
#define CAN_TI1R_RTR_Pos                     (1U)
#define CAN_TI1R_RTR_Msk                     (0x1UL << CAN_TI1R_RTR_Pos)        /*!< 0x00000002 */
#define CAN_TI1R_RTR                         CAN_TI1R_RTR_Msk                  /*!< Remote Transmission Request */
#define CAN_TI1R_IDE_Pos                     (2U)
#define CAN_TI1R_IDE_Msk                     (0x1UL << CAN_TI1R_IDE_Pos)        /*!< 0x00000004 */
#define CAN_TI1R_IDE                         CAN_TI1R_IDE_Msk                  /*!< Identifier Extension */
#define CAN_TI1R_EXID_Pos                    (3U)
#define CAN_TI1R_EXID_Msk                    (0x3FFFFUL << CAN_TI1R_EXID_Pos)   /*!< 0x001FFFF8 */
#define CAN_TI1R_EXID                        CAN_TI1R_EXID_Msk                 /*!< Extended Identifier */
#define CAN_TI1R_STID_Pos                    (21U)
#define CAN_TI1R_STID_Msk                    (0x7FFUL << CAN_TI1R_STID_Pos)     /*!< 0xFFE00000 */
#define CAN_TI1R_STID                        CAN_TI1R_STID_Msk                 /*!< Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_TDT1R register  ******************/
#define CAN_TDT1R_DLC_Pos                    (0U)
#define CAN_TDT1R_DLC_Msk                    (0xFUL << CAN_TDT1R_DLC_Pos)       /*!< 0x0000000F */
#define CAN_TDT1R_DLC                        CAN_TDT1R_DLC_Msk                 /*!< Data Length Code */
#define CAN_TDT1R_TGT_Pos                    (8U)
#define CAN_TDT1R_TGT_Msk                    (0x1UL << CAN_TDT1R_TGT_Pos)       /*!< 0x00000100 */
#define CAN_TDT1R_TGT                        CAN_TDT1R_TGT_Msk                 /*!< Transmit Global Time */
#define CAN_TDT1R_TIME_Pos                   (16U)
#define CAN_TDT1R_TIME_Msk                   (0xFFFFUL << CAN_TDT1R_TIME_Pos)   /*!< 0xFFFF0000 */
#define CAN_TDT1R_TIME                       CAN_TDT1R_TIME_Msk                /*!< Message Time Stamp */

/*******************  Bit definition for CAN_TDL1R register  ******************/
#define CAN_TDL1R_DATA0_Pos                  (0U)
#define CAN_TDL1R_DATA0_Msk                  (0xFFUL << CAN_TDL1R_DATA0_Pos)    /*!< 0x000000FF */
#define CAN_TDL1R_DATA0                      CAN_TDL1R_DATA0_Msk               /*!< Data byte 0 */
#define CAN_TDL1R_DATA1_Pos                  (8U)
#define CAN_TDL1R_DATA1_Msk                  (0xFFUL << CAN_TDL1R_DATA1_Pos)    /*!< 0x0000FF00 */
#define CAN_TDL1R_DATA1                      CAN_TDL1R_DATA1_Msk               /*!< Data byte 1 */
#define CAN_TDL1R_DATA2_Pos                  (16U)
#define CAN_TDL1R_DATA2_Msk                  (0xFFUL << CAN_TDL1R_DATA2_Pos)    /*!< 0x00FF0000 */
#define CAN_TDL1R_DATA2                      CAN_TDL1R_DATA2_Msk               /*!< Data byte 2 */
#define CAN_TDL1R_DATA3_Pos                  (24U)
#define CAN_TDL1R_DATA3_Msk                  (0xFFUL << CAN_TDL1R_DATA3_Pos)    /*!< 0xFF000000 */
#define CAN_TDL1R_DATA3                      CAN_TDL1R_DATA3_Msk               /*!< Data byte 3 */

/*******************  Bit definition for CAN_TDH1R register  ******************/
#define CAN_TDH1R_DATA4_Pos                  (0U)
#define CAN_TDH1R_DATA4_Msk                  (0xFFUL << CAN_TDH1R_DATA4_Pos)    /*!< 0x000000FF */
#define CAN_TDH1R_DATA4                      CAN_TDH1R_DATA4_Msk               /*!< Data byte 4 */
#define CAN_TDH1R_DATA5_Pos                  (8U)
#define CAN_TDH1R_DATA5_Msk                  (0xFFUL << CAN_TDH1R_DATA5_Pos)    /*!< 0x0000FF00 */
#define CAN_TDH1R_DATA5                      CAN_TDH1R_DATA5_Msk               /*!< Data byte 5 */
#define CAN_TDH1R_DATA6_Pos                  (16U)
#define CAN_TDH1R_DATA6_Msk                  (0xFFUL << CAN_TDH1R_DATA6_Pos)    /*!< 0x00FF0000 */
#define CAN_TDH1R_DATA6                      CAN_TDH1R_DATA6_Msk               /*!< Data byte 6 */
#define CAN_TDH1R_DATA7_Pos                  (24U)
#define CAN_TDH1R_DATA7_Msk                  (0xFFUL << CAN_TDH1R_DATA7_Pos)    /*!< 0xFF000000 */
#define CAN_TDH1R_DATA7                      CAN_TDH1R_DATA7_Msk               /*!< Data byte 7 */

/*******************  Bit definition for CAN_TI2R register  *******************/
#define CAN_TI2R_TXRQ_Pos                    (0U)
#define CAN_TI2R_TXRQ_Msk                    (0x1UL << CAN_TI2R_TXRQ_Pos)       /*!< 0x00000001 */
#define CAN_TI2R_TXRQ                        CAN_TI2R_TXRQ_Msk                 /*!< Transmit Mailbox Request */
#define CAN_TI2R_RTR_Pos                     (1U)
#define CAN_TI2R_RTR_Msk                     (0x1UL << CAN_TI2R_RTR_Pos)        /*!< 0x00000002 */
#define CAN_TI2R_RTR                         CAN_TI2R_RTR_Msk                  /*!< Remote Transmission Request */
#define CAN_TI2R_IDE_Pos                     (2U)
#define CAN_TI2R_IDE_Msk                     (0x1UL << CAN_TI2R_IDE_Pos)        /*!< 0x00000004 */
#define CAN_TI2R_IDE                         CAN_TI2R_IDE_Msk                  /*!< Identifier Extension */
#define CAN_TI2R_EXID_Pos                    (3U)
#define CAN_TI2R_EXID_Msk                    (0x3FFFFUL << CAN_TI2R_EXID_Pos)   /*!< 0x001FFFF8 */
#define CAN_TI2R_EXID                        CAN_TI2R_EXID_Msk                 /*!< Extended identifier */
#define CAN_TI2R_STID_Pos                    (21U)
#define CAN_TI2R_STID_Msk                    (0x7FFUL << CAN_TI2R_STID_Pos)     /*!< 0xFFE00000 */
#define CAN_TI2R_STID                        CAN_TI2R_STID_Msk                 /*!< Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_TDT2R register  ******************/
#define CAN_TDT2R_DLC_Pos                    (0U)
#define CAN_TDT2R_DLC_Msk                    (0xFUL << CAN_TDT2R_DLC_Pos)       /*!< 0x0000000F */
#define CAN_TDT2R_DLC                        CAN_TDT2R_DLC_Msk                 /*!< Data Length Code */
#define CAN_TDT2R_TGT_Pos                    (8U)
#define CAN_TDT2R_TGT_Msk                    (0x1UL << CAN_TDT2R_TGT_Pos)       /*!< 0x00000100 */
#define CAN_TDT2R_TGT                        CAN_TDT2R_TGT_Msk                 /*!< Transmit Global Time */
#define CAN_TDT2R_TIME_Pos                   (16U)
#define CAN_TDT2R_TIME_Msk                   (0xFFFFUL << CAN_TDT2R_TIME_Pos)   /*!< 0xFFFF0000 */
#define CAN_TDT2R_TIME                       CAN_TDT2R_TIME_Msk                /*!< Message Time Stamp */

/*******************  Bit definition for CAN_TDL2R register  ******************/
#define CAN_TDL2R_DATA0_Pos                  (0U)
#define CAN_TDL2R_DATA0_Msk                  (0xFFUL << CAN_TDL2R_DATA0_Pos)    /*!< 0x000000FF */
#define CAN_TDL2R_DATA0                      CAN_TDL2R_DATA0_Msk               /*!< Data byte 0 */
#define CAN_TDL2R_DATA1_Pos                  (8U)
#define CAN_TDL2R_DATA1_Msk                  (0xFFUL << CAN_TDL2R_DATA1_Pos)    /*!< 0x0000FF00 */
#define CAN_TDL2R_DATA1                      CAN_TDL2R_DATA1_Msk               /*!< Data byte 1 */
#define CAN_TDL2R_DATA2_Pos                  (16U)
#define CAN_TDL2R_DATA2_Msk                  (0xFFUL << CAN_TDL2R_DATA2_Pos)    /*!< 0x00FF0000 */
#define CAN_TDL2R_DATA2                      CAN_TDL2R_DATA2_Msk               /*!< Data byte 2 */
#define CAN_TDL2R_DATA3_Pos                  (24U)
#define CAN_TDL2R_DATA3_Msk                  (0xFFUL << CAN_TDL2R_DATA3_Pos)    /*!< 0xFF000000 */
#define CAN_TDL2R_DATA3                      CAN_TDL2R_DATA3_Msk               /*!< Data byte 3 */

/*******************  Bit definition for CAN_TDH2R register  ******************/
#define CAN_TDH2R_DATA4_Pos                  (0U)
#define CAN_TDH2R_DATA4_Msk                  (0xFFUL << CAN_TDH2R_DATA4_Pos)    /*!< 0x000000FF */
#define CAN_TDH2R_DATA4                      CAN_TDH2R_DATA4_Msk               /*!< Data byte 4 */
#define CAN_TDH2R_DATA5_Pos                  (8U)
#define CAN_TDH2R_DATA5_Msk                  (0xFFUL << CAN_TDH2R_DATA5_Pos)    /*!< 0x0000FF00 */
#define CAN_TDH2R_DATA5                      CAN_TDH2R_DATA5_Msk               /*!< Data byte 5 */
#define CAN_TDH2R_DATA6_Pos                  (16U)
#define CAN_TDH2R_DATA6_Msk                  (0xFFUL << CAN_TDH2R_DATA6_Pos)    /*!< 0x00FF0000 */
#define CAN_TDH2R_DATA6                      CAN_TDH2R_DATA6_Msk               /*!< Data byte 6 */
#define CAN_TDH2R_DATA7_Pos                  (24U)
#define CAN_TDH2R_DATA7_Msk                  (0xFFUL << CAN_TDH2R_DATA7_Pos)    /*!< 0xFF000000 */
#define CAN_TDH2R_DATA7                      CAN_TDH2R_DATA7_Msk               /*!< Data byte 7 */

/*******************  Bit definition for CAN_RI0R register  *******************/
#define CAN_RI0R_RTR_Pos                     (1U)
#define CAN_RI0R_RTR_Msk                     (0x1UL << CAN_RI0R_RTR_Pos)        /*!< 0x00000002 */
#define CAN_RI0R_RTR                         CAN_RI0R_RTR_Msk                  /*!< Remote Transmission Request */
#define CAN_RI0R_IDE_Pos                     (2U)
#define CAN_RI0R_IDE_Msk                     (0x1UL << CAN_RI0R_IDE_Pos)        /*!< 0x00000004 */
#define CAN_RI0R_IDE                         CAN_RI0R_IDE_Msk                  /*!< Identifier Extension */
#define CAN_RI0R_EXID_Pos                    (3U)
#define CAN_RI0R_EXID_Msk                    (0x3FFFFUL << CAN_RI0R_EXID_Pos)   /*!< 0x001FFFF8 */
#define CAN_RI0R_EXID                        CAN_RI0R_EXID_Msk                 /*!< Extended Identifier */
#define CAN_RI0R_STID_Pos                    (21U)
#define CAN_RI0R_STID_Msk                    (0x7FFUL << CAN_RI0R_STID_Pos)     /*!< 0xFFE00000 */
#define CAN_RI0R_STID                        CAN_RI0R_STID_Msk                 /*!< Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_RDT0R register  ******************/
#define CAN_RDT0R_DLC_Pos                    (0U)
#define CAN_RDT0R_DLC_Msk                    (0xFUL << CAN_RDT0R_DLC_Pos)       /*!< 0x0000000F */
#define CAN_RDT0R_DLC                        CAN_RDT0R_DLC_Msk                 /*!< Data Length Code */
#define CAN_RDT0R_FMI_Pos                    (8U)
#define CAN_RDT0R_FMI_Msk                    (0xFFUL << CAN_RDT0R_FMI_Pos)      /*!< 0x0000FF00 */
#define CAN_RDT0R_FMI                        CAN_RDT0R_FMI_Msk                 /*!< Filter Match Index */
#define CAN_RDT0R_TIME_Pos                   (16U)
#define CAN_RDT0R_TIME_Msk                   (0xFFFFUL << CAN_RDT0R_TIME_Pos)   /*!< 0xFFFF0000 */
#define CAN_RDT0R_TIME                       CAN_RDT0R_TIME_Msk                /*!< Message Time Stamp */

/*******************  Bit definition for CAN_RDL0R register  ******************/
#define CAN_RDL0R_DATA0_Pos                  (0U)
#define CAN_RDL0R_DATA0_Msk                  (0xFFUL << CAN_RDL0R_DATA0_Pos)    /*!< 0x000000FF */
#define CAN_RDL0R_DATA0                      CAN_RDL0R_DATA0_Msk               /*!< Data byte 0 */
#define CAN_RDL0R_DATA1_Pos                  (8U)
#define CAN_RDL0R_DATA1_Msk                  (0xFFUL << CAN_RDL0R_DATA1_Pos)    /*!< 0x0000FF00 */
#define CAN_RDL0R_DATA1                      CAN_RDL0R_DATA1_Msk               /*!< Data byte 1 */
#define CAN_RDL0R_DATA2_Pos                  (16U)
#define CAN_RDL0R_DATA2_Msk                  (0xFFUL << CAN_RDL0R_DATA2_Pos)    /*!< 0x00FF0000 */
#define CAN_RDL0R_DATA2                      CAN_RDL0R_DATA2_Msk               /*!< Data byte 2 */
#define CAN_RDL0R_DATA3_Pos                  (24U)
#define CAN_RDL0R_DATA3_Msk                  (0xFFUL << CAN_RDL0R_DATA3_Pos)    /*!< 0xFF000000 */
#define CAN_RDL0R_DATA3                      CAN_RDL0R_DATA3_Msk               /*!< Data byte 3 */

/*******************  Bit definition for CAN_RDH0R register  ******************/
#define CAN_RDH0R_DATA4_Pos                  (0U)
#define CAN_RDH0R_DATA4_Msk                  (0xFFUL << CAN_RDH0R_DATA4_Pos)    /*!< 0x000000FF */
#define CAN_RDH0R_DATA4                      CAN_RDH0R_DATA4_Msk               /*!< Data byte 4 */
#define CAN_RDH0R_DATA5_Pos                  (8U)
#define CAN_RDH0R_DATA5_Msk                  (0xFFUL << CAN_RDH0R_DATA5_Pos)    /*!< 0x0000FF00 */
#define CAN_RDH0R_DATA5                      CAN_RDH0R_DATA5_Msk               /*!< Data byte 5 */
#define CAN_RDH0R_DATA6_Pos                  (16U)
#define CAN_RDH0R_DATA6_Msk                  (0xFFUL << CAN_RDH0R_DATA6_Pos)    /*!< 0x00FF0000 */
#define CAN_RDH0R_DATA6                      CAN_RDH0R_DATA6_Msk               /*!< Data byte 6 */
#define CAN_RDH0R_DATA7_Pos                  (24U)
#define CAN_RDH0R_DATA7_Msk                  (0xFFUL << CAN_RDH0R_DATA7_Pos)    /*!< 0xFF000000 */
#define CAN_RDH0R_DATA7                      CAN_RDH0R_DATA7_Msk               /*!< Data byte 7 */

/*******************  Bit definition for CAN_RI1R register  *******************/
#define CAN_RI1R_RTR_Pos                     (1U)
#define CAN_RI1R_RTR_Msk                     (0x1UL << CAN_RI1R_RTR_Pos)        /*!< 0x00000002 */
#define CAN_RI1R_RTR                         CAN_RI1R_RTR_Msk                  /*!< Remote Transmission Request */
#define CAN_RI1R_IDE_Pos                     (2U)
#define CAN_RI1R_IDE_Msk                     (0x1UL << CAN_RI1R_IDE_Pos)        /*!< 0x00000004 */
#define CAN_RI1R_IDE                         CAN_RI1R_IDE_Msk                  /*!< Identifier Extension */
#define CAN_RI1R_EXID_Pos                    (3U)
#define CAN_RI1R_EXID_Msk                    (0x3FFFFUL << CAN_RI1R_EXID_Pos)   /*!< 0x001FFFF8 */
#define CAN_RI1R_EXID                        CAN_RI1R_EXID_Msk                 /*!< Extended identifier */
#define CAN_RI1R_STID_Pos                    (21U)
#define CAN_RI1R_STID_Msk                    (0x7FFUL << CAN_RI1R_STID_Pos)     /*!< 0xFFE00000 */
#define CAN_RI1R_STID                        CAN_RI1R_STID_Msk                 /*!< Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_RDT1R register  ******************/
#define CAN_RDT1R_DLC_Pos                    (0U)
#define CAN_RDT1R_DLC_Msk                    (0xFUL << CAN_RDT1R_DLC_Pos)       /*!< 0x0000000F */
#define CAN_RDT1R_DLC                        CAN_RDT1R_DLC_Msk                 /*!< Data Length Code */
#define CAN_RDT1R_FMI_Pos                    (8U)
#define CAN_RDT1R_FMI_Msk                    (0xFFUL << CAN_RDT1R_FMI_Pos)      /*!< 0x0000FF00 */
#define CAN_RDT1R_FMI                        CAN_RDT1R_FMI_Msk                 /*!< Filter Match Index */
#define CAN_RDT1R_TIME_Pos                   (16U)
#define CAN_RDT1R_TIME_Msk                   (0xFFFFUL << CAN_RDT1R_TIME_Pos)   /*!< 0xFFFF0000 */
#define CAN_RDT1R_TIME                       CAN_RDT1R_TIME_Msk                /*!< Message Time Stamp */

/*******************  Bit definition for CAN_RDL1R register  ******************/
#define CAN_RDL1R_DATA0_Pos                  (0U)
#define CAN_RDL1R_DATA0_Msk                  (0xFFUL << CAN_RDL1R_DATA0_Pos)    /*!< 0x000000FF */
#define CAN_RDL1R_DATA0                      CAN_RDL1R_DATA0_Msk               /*!< Data byte 0 */
#define CAN_RDL1R_DATA1_Pos                  (8U)
#define CAN_RDL1R_DATA1_Msk                  (0xFFUL << CAN_RDL1R_DATA1_Pos)    /*!< 0x0000FF00 */
#define CAN_RDL1R_DATA1                      CAN_RDL1R_DATA1_Msk               /*!< Data byte 1 */
#define CAN_RDL1R_DATA2_Pos                  (16U)
#define CAN_RDL1R_DATA2_Msk                  (0xFFUL << CAN_RDL1R_DATA2_Pos)    /*!< 0x00FF0000 */
#define CAN_RDL1R_DATA2                      CAN_RDL1R_DATA2_Msk               /*!< Data byte 2 */
#define CAN_RDL1R_DATA3_Pos                  (24U)
#define CAN_RDL1R_DATA3_Msk                  (0xFFUL << CAN_RDL1R_DATA3_Pos)    /*!< 0xFF000000 */
#define CAN_RDL1R_DATA3                      CAN_RDL1R_DATA3_Msk               /*!< Data byte 3 */

/*******************  Bit definition for CAN_RDH1R register  ******************/
#define CAN_RDH1R_DATA4_Pos                  (0U)
#define CAN_RDH1R_DATA4_Msk                  (0xFFUL << CAN_RDH1R_DATA4_Pos)    /*!< 0x000000FF */
#define CAN_RDH1R_DATA4                      CAN_RDH1R_DATA4_Msk               /*!< Data byte 4 */
#define CAN_RDH1R_DATA5_Pos                  (8U)
#define CAN_RDH1R_DATA5_Msk                  (0xFFUL << CAN_RDH1R_DATA5_Pos)    /*!< 0x0000FF00 */
#define CAN_RDH1R_DATA5                      CAN_RDH1R_DATA5_Msk               /*!< Data byte 5 */
#define CAN_RDH1R_DATA6_Pos                  (16U)
#define CAN_RDH1R_DATA6_Msk                  (0xFFUL << CAN_RDH1R_DATA6_Pos)    /*!< 0x00FF0000 */
#define CAN_RDH1R_DATA6                      CAN_RDH1R_DATA6_Msk               /*!< Data byte 6 */
#define CAN_RDH1R_DATA7_Pos                  (24U)
#define CAN_RDH1R_DATA7_Msk                  (0xFFUL << CAN_RDH1R_DATA7_Pos)    /*!< 0xFF000000 */
#define CAN_RDH1R_DATA7                      CAN_RDH1R_DATA7_Msk               /*!< Data byte 7 */

/*!< CAN filter registers */
/*******************  Bit definition for CAN_FMR register  ********************/
#define CAN_FMR_FINIT_Pos                    (0U)
#define CAN_FMR_FINIT_Msk                    (0x1UL << CAN_FMR_FINIT_Pos)       /*!< 0x00000001 */
#define CAN_FMR_FINIT                        CAN_FMR_FINIT_Msk                 /*!< Filter Init Mode */
#define CAN_FMR_CAN2SB_Pos                   (8U)
#define CAN_FMR_CAN2SB_Msk                   (0x3FUL << CAN_FMR_CAN2SB_Pos)     /*!< 0x00003F00 */
#define CAN_FMR_CAN2SB                       CAN_FMR_CAN2SB_Msk                /*!< CAN2 start bank */

/*******************  Bit definition for CAN_FM1R register  *******************/
#define CAN_FM1R_FBM_Pos                     (0U)
#define CAN_FM1R_FBM_Msk                     (0x3FFFUL << CAN_FM1R_FBM_Pos)     /*!< 0x00003FFF */
#define CAN_FM1R_FBM                         CAN_FM1R_FBM_Msk                  /*!< Filter Mode */
#define CAN_FM1R_FBM0_Pos                    (0U)
#define CAN_FM1R_FBM0_Msk                    (0x1UL << CAN_FM1R_FBM0_Pos)       /*!< 0x00000001 */
#define CAN_FM1R_FBM0                        CAN_FM1R_FBM0_Msk                 /*!< Filter Init Mode for filter 0 */
#define CAN_FM1R_FBM1_Pos                    (1U)
#define CAN_FM1R_FBM1_Msk                    (0x1UL << CAN_FM1R_FBM1_Pos)       /*!< 0x00000002 */
#define CAN_FM1R_FBM1                        CAN_FM1R_FBM1_Msk                 /*!< Filter Init Mode for filter 1 */
#define CAN_FM1R_FBM2_Pos                    (2U)
#define CAN_FM1R_FBM2_Msk                    (0x1UL << CAN_FM1R_FBM2_Pos)       /*!< 0x00000004 */
#define CAN_FM1R_FBM2                        CAN_FM1R_FBM2_Msk                 /*!< Filter Init Mode for filter 2 */
#define CAN_FM1R_FBM3_Pos                    (3U)
#define CAN_FM1R_FBM3_Msk                    (0x1UL << CAN_FM1R_FBM3_Pos)       /*!< 0x00000008 */
#define CAN_FM1R_FBM3                        CAN_FM1R_FBM3_Msk                 /*!< Filter Init Mode for filter 3 */
#define CAN_FM1R_FBM4_Pos                    (4U)
#define CAN_FM1R_FBM4_Msk                    (0x1UL << CAN_FM1R_FBM4_Pos)       /*!< 0x00000010 */
#define CAN_FM1R_FBM4                        CAN_FM1R_FBM4_Msk                 /*!< Filter Init Mode for filter 4 */
#define CAN_FM1R_FBM5_Pos                    (5U)
#define CAN_FM1R_FBM5_Msk                    (0x1UL << CAN_FM1R_FBM5_Pos)       /*!< 0x00000020 */
#define CAN_FM1R_FBM5                        CAN_FM1R_FBM5_Msk                 /*!< Filter Init Mode for filter 5 */
#define CAN_FM1R_FBM6_Pos                    (6U)
#define CAN_FM1R_FBM6_Msk                    (0x1UL << CAN_FM1R_FBM6_Pos)       /*!< 0x00000040 */
#define CAN_FM1R_FBM6                        CAN_FM1R_FBM6_Msk                 /*!< Filter Init Mode for filter 6 */
#define CAN_FM1R_FBM7_Pos                    (7U)
#define CAN_FM1R_FBM7_Msk                    (0x1UL << CAN_FM1R_FBM7_Pos)       /*!< 0x00000080 */
#define CAN_FM1R_FBM7                        CAN_FM1R_FBM7_Msk                 /*!< Filter Init Mode for filter 7 */
#define CAN_FM1R_FBM8_Pos                    (8U)
#define CAN_FM1R_FBM8_Msk                    (0x1UL << CAN_FM1R_FBM8_Pos)       /*!< 0x00000100 */
#define CAN_FM1R_FBM8                        CAN_FM1R_FBM8_Msk                 /*!< Filter Init Mode for filter 8 */
#define CAN_FM1R_FBM9_Pos                    (9U)
#define CAN_FM1R_FBM9_Msk                    (0x1UL << CAN_FM1R_FBM9_Pos)       /*!< 0x00000200 */
#define CAN_FM1R_FBM9                        CAN_FM1R_FBM9_Msk                 /*!< Filter Init Mode for filter 9 */
#define CAN_FM1R_FBM10_Pos                   (10U)
#define CAN_FM1R_FBM10_Msk                   (0x1UL << CAN_FM1R_FBM10_Pos)      /*!< 0x00000400 */
#define CAN_FM1R_FBM10                       CAN_FM1R_FBM10_Msk                /*!< Filter Init Mode for filter 10 */
#define CAN_FM1R_FBM11_Pos                   (11U)
#define CAN_FM1R_FBM11_Msk                   (0x1UL << CAN_FM1R_FBM11_Pos)      /*!< 0x00000800 */
#define CAN_FM1R_FBM11                       CAN_FM1R_FBM11_Msk                /*!< Filter Init Mode for filter 11 */
#define CAN_FM1R_FBM12_Pos                   (12U)
#define CAN_FM1R_FBM12_Msk                   (0x1UL << CAN_FM1R_FBM12_Pos)      /*!< 0x00001000 */
#define CAN_FM1R_FBM12                       CAN_FM1R_FBM12_Msk                /*!< Filter Init Mode for filter 12 */
#define CAN_FM1R_FBM13_Pos                   (13U)
#define CAN_FM1R_FBM13_Msk                   (0x1UL << CAN_FM1R_FBM13_Pos)      /*!< 0x00002000 */
#define CAN_FM1R_FBM13                       CAN_FM1R_FBM13_Msk                /*!< Filter Init Mode for filter 13 */

/*******************  Bit definition for CAN_FS1R register  *******************/
#define CAN_FS1R_FSC_Pos                     (0U)
#define CAN_FS1R_FSC_Msk                     (0x3FFFUL << CAN_FS1R_FSC_Pos)     /*!< 0x00003FFF */
#define CAN_FS1R_FSC                         CAN_FS1R_FSC_Msk                  /*!< Filter Scale Configuration */
#define CAN_FS1R_FSC0_Pos                    (0U)
#define CAN_FS1R_FSC0_Msk                    (0x1UL << CAN_FS1R_FSC0_Pos)       /*!< 0x00000001 */
#define CAN_FS1R_FSC0                        CAN_FS1R_FSC0_Msk                 /*!< Filter Scale Configuration for filter 0 */
#define CAN_FS1R_FSC1_Pos                    (1U)
#define CAN_FS1R_FSC1_Msk                    (0x1UL << CAN_FS1R_FSC1_Pos)       /*!< 0x00000002 */
#define CAN_FS1R_FSC1                        CAN_FS1R_FSC1_Msk                 /*!< Filter Scale Configuration for filter 1 */
#define CAN_FS1R_FSC2_Pos                    (2U)
#define CAN_FS1R_FSC2_Msk                    (0x1UL << CAN_FS1R_FSC2_Pos)       /*!< 0x00000004 */
#define CAN_FS1R_FSC2                        CAN_FS1R_FSC2_Msk                 /*!< Filter Scale Configuration for filter 2 */
#define CAN_FS1R_FSC3_Pos                    (3U)
#define CAN_FS1R_FSC3_Msk                    (0x1UL << CAN_FS1R_FSC3_Pos)       /*!< 0x00000008 */
#define CAN_FS1R_FSC3                        CAN_FS1R_FSC3_Msk                 /*!< Filter Scale Configuration for filter 3 */
#define CAN_FS1R_FSC4_Pos                    (4U)
#define CAN_FS1R_FSC4_Msk                    (0x1UL << CAN_FS1R_FSC4_Pos)       /*!< 0x00000010 */
#define CAN_FS1R_FSC4                        CAN_FS1R_FSC4_Msk                 /*!< Filter Scale Configuration for filter 4 */
#define CAN_FS1R_FSC5_Pos                    (5U)
#define CAN_FS1R_FSC5_Msk                    (0x1UL << CAN_FS1R_FSC5_Pos)       /*!< 0x00000020 */
#define CAN_FS1R_FSC5                        CAN_FS1R_FSC5_Msk                 /*!< Filter Scale Configuration for filter 5 */
#define CAN_FS1R_FSC6_Pos                    (6U)
#define CAN_FS1R_FSC6_Msk                    (0x1UL << CAN_FS1R_FSC6_Pos)       /*!< 0x00000040 */
#define CAN_FS1R_FSC6                        CAN_FS1R_FSC6_Msk                 /*!< Filter Scale Configuration for filter 6 */
#define CAN_FS1R_FSC7_Pos                    (7U)
#define CAN_FS1R_FSC7_Msk                    (0x1UL << CAN_FS1R_FSC7_Pos)       /*!< 0x00000080 */
#define CAN_FS1R_FSC7                        CAN_FS1R_FSC7_Msk                 /*!< Filter Scale Configuration for filter 7 */
#define CAN_FS1R_FSC8_Pos                    (8U)
#define CAN_FS1R_FSC8_Msk                    (0x1UL << CAN_FS1R_FSC8_Pos)       /*!< 0x00000100 */
#define CAN_FS1R_FSC8                        CAN_FS1R_FSC8_Msk                 /*!< Filter Scale Configuration for filter 8 */
#define CAN_FS1R_FSC9_Pos                    (9U)
#define CAN_FS1R_FSC9_Msk                    (0x1UL << CAN_FS1R_FSC9_Pos)       /*!< 0x00000200 */
#define CAN_FS1R_FSC9                        CAN_FS1R_FSC9_Msk                 /*!< Filter Scale Configuration for filter 9 */
#define CAN_FS1R_FSC10_Pos                   (10U)
#define CAN_FS1R_FSC10_Msk                   (0x1UL << CAN_FS1R_FSC10_Pos)      /*!< 0x00000400 */
#define CAN_FS1R_FSC10                       CAN_FS1R_FSC10_Msk                /*!< Filter Scale Configuration for filter 10 */
#define CAN_FS1R_FSC11_Pos                   (11U)
#define CAN_FS1R_FSC11_Msk                   (0x1UL << CAN_FS1R_FSC11_Pos)      /*!< 0x00000800 */
#define CAN_FS1R_FSC11                       CAN_FS1R_FSC11_Msk                /*!< Filter Scale Configuration for filter 11 */
#define CAN_FS1R_FSC12_Pos                   (12U)
#define CAN_FS1R_FSC12_Msk                   (0x1UL << CAN_FS1R_FSC12_Pos)      /*!< 0x00001000 */
#define CAN_FS1R_FSC12                       CAN_FS1R_FSC12_Msk                /*!< Filter Scale Configuration for filter 12 */
#define CAN_FS1R_FSC13_Pos                   (13U)
#define CAN_FS1R_FSC13_Msk                   (0x1UL << CAN_FS1R_FSC13_Pos)      /*!< 0x00002000 */
#define CAN_FS1R_FSC13                       CAN_FS1R_FSC13_Msk                /*!< Filter Scale Configuration for filter 13 */

/******************  Bit definition for CAN_FFA1R register  *******************/
#define CAN_FFA1R_FFA_Pos                    (0U)
#define CAN_FFA1R_FFA_Msk                    (0x3FFFUL << CAN_FFA1R_FFA_Pos)    /*!< 0x00003FFF */
#define CAN_FFA1R_FFA                        CAN_FFA1R_FFA_Msk                 /*!< Filter FIFO Assignment */
#define CAN_FFA1R_FFA0_Pos                   (0U)
#define CAN_FFA1R_FFA0_Msk                   (0x1UL << CAN_FFA1R_FFA0_Pos)      /*!< 0x00000001 */
#define CAN_FFA1R_FFA0                       CAN_FFA1R_FFA0_Msk                /*!< Filter FIFO Assignment for filter 0 */
#define CAN_FFA1R_FFA1_Pos                   (1U)
#define CAN_FFA1R_FFA1_Msk                   (0x1UL << CAN_FFA1R_FFA1_Pos)      /*!< 0x00000002 */
#define CAN_FFA1R_FFA1                       CAN_FFA1R_FFA1_Msk                /*!< Filter FIFO Assignment for filter 1 */
#define CAN_FFA1R_FFA2_Pos                   (2U)
#define CAN_FFA1R_FFA2_Msk                   (0x1UL << CAN_FFA1R_FFA2_Pos)      /*!< 0x00000004 */
#define CAN_FFA1R_FFA2                       CAN_FFA1R_FFA2_Msk                /*!< Filter FIFO Assignment for filter 2 */
#define CAN_FFA1R_FFA3_Pos                   (3U)
#define CAN_FFA1R_FFA3_Msk                   (0x1UL << CAN_FFA1R_FFA3_Pos)      /*!< 0x00000008 */
#define CAN_FFA1R_FFA3                       CAN_FFA1R_FFA3_Msk                /*!< Filter FIFO Assignment for filter 3 */
#define CAN_FFA1R_FFA4_Pos                   (4U)
#define CAN_FFA1R_FFA4_Msk                   (0x1UL << CAN_FFA1R_FFA4_Pos)      /*!< 0x00000010 */
#define CAN_FFA1R_FFA4                       CAN_FFA1R_FFA4_Msk                /*!< Filter FIFO Assignment for filter 4 */
#define CAN_FFA1R_FFA5_Pos                   (5U)
#define CAN_FFA1R_FFA5_Msk                   (0x1UL << CAN_FFA1R_FFA5_Pos)      /*!< 0x00000020 */
#define CAN_FFA1R_FFA5                       CAN_FFA1R_FFA5_Msk                /*!< Filter FIFO Assignment for filter 5 */
#define CAN_FFA1R_FFA6_Pos                   (6U)
#define CAN_FFA1R_FFA6_Msk                   (0x1UL << CAN_FFA1R_FFA6_Pos)      /*!< 0x00000040 */
#define CAN_FFA1R_FFA6                       CAN_FFA1R_FFA6_Msk                /*!< Filter FIFO Assignment for filter 6 */
#define CAN_FFA1R_FFA7_Pos                   (7U)
#define CAN_FFA1R_FFA7_Msk                   (0x1UL << CAN_FFA1R_FFA7_Pos)      /*!< 0x00000080 */
#define CAN_FFA1R_FFA7                       CAN_FFA1R_FFA7_Msk                /*!< Filter FIFO Assignment for filter 7 */
#define CAN_FFA1R_FFA8_Pos                   (8U)
#define CAN_FFA1R_FFA8_Msk                   (0x1UL << CAN_FFA1R_FFA8_Pos)      /*!< 0x00000100 */
#define CAN_FFA1R_FFA8                       CAN_FFA1R_FFA8_Msk                /*!< Filter FIFO Assignment for filter 8 */
#define CAN_FFA1R_FFA9_Pos                   (9U)
#define CAN_FFA1R_FFA9_Msk                   (0x1UL << CAN_FFA1R_FFA9_Pos)      /*!< 0x00000200 */
#define CAN_FFA1R_FFA9                       CAN_FFA1R_FFA9_Msk                /*!< Filter FIFO Assignment for filter 9 */
#define CAN_FFA1R_FFA10_Pos                  (10U)
#define CAN_FFA1R_FFA10_Msk                  (0x1UL << CAN_FFA1R_FFA10_Pos)     /*!< 0x00000400 */
#define CAN_FFA1R_FFA10                      CAN_FFA1R_FFA10_Msk               /*!< Filter FIFO Assignment for filter 10 */
#define CAN_FFA1R_FFA11_Pos                  (11U)
#define CAN_FFA1R_FFA11_Msk                  (0x1UL << CAN_FFA1R_FFA11_Pos)     /*!< 0x00000800 */
#define CAN_FFA1R_FFA11                      CAN_FFA1R_FFA11_Msk               /*!< Filter FIFO Assignment for filter 11 */
#define CAN_FFA1R_FFA12_Pos                  (12U)
#define CAN_FFA1R_FFA12_Msk                  (0x1UL << CAN_FFA1R_FFA12_Pos)     /*!< 0x00001000 */
#define CAN_FFA1R_FFA12                      CAN_FFA1R_FFA12_Msk               /*!< Filter FIFO Assignment for filter 12 */
#define CAN_FFA1R_FFA13_Pos                  (13U)
#define CAN_FFA1R_FFA13_Msk                  (0x1UL << CAN_FFA1R_FFA13_Pos)     /*!< 0x00002000 */
#define CAN_FFA1R_FFA13                      CAN_FFA1R_FFA13_Msk               /*!< Filter FIFO Assignment for filter 13 */

/*******************  Bit definition for CAN_FA1R register  *******************/
#define CAN_FA1R_FACT_Pos                    (0U)
#define CAN_FA1R_FACT_Msk                    (0x3FFFUL << CAN_FA1R_FACT_Pos)    /*!< 0x00003FFF */
#define CAN_FA1R_FACT                        CAN_FA1R_FACT_Msk                 /*!< Filter Active */
#define CAN_FA1R_FACT0_Pos                   (0U)
#define CAN_FA1R_FACT0_Msk                   (0x1UL << CAN_FA1R_FACT0_Pos)      /*!< 0x00000001 */
#define CAN_FA1R_FACT0                       CAN_FA1R_FACT0_Msk                /*!< Filter 0 Active */
#define CAN_FA1R_FACT1_Pos                   (1U)
#define CAN_FA1R_FACT1_Msk                   (0x1UL << CAN_FA1R_FACT1_Pos)      /*!< 0x00000002 */
#define CAN_FA1R_FACT1                       CAN_FA1R_FACT1_Msk                /*!< Filter 1 Active */
#define CAN_FA1R_FACT2_Pos                   (2U)
#define CAN_FA1R_FACT2_Msk                   (0x1UL << CAN_FA1R_FACT2_Pos)      /*!< 0x00000004 */
#define CAN_FA1R_FACT2                       CAN_FA1R_FACT2_Msk                /*!< Filter 2 Active */
#define CAN_FA1R_FACT3_Pos                   (3U)
#define CAN_FA1R_FACT3_Msk                   (0x1UL << CAN_FA1R_FACT3_Pos)      /*!< 0x00000008 */
#define CAN_FA1R_FACT3                       CAN_FA1R_FACT3_Msk                /*!< Filter 3 Active */
#define CAN_FA1R_FACT4_Pos                   (4U)
#define CAN_FA1R_FACT4_Msk                   (0x1UL << CAN_FA1R_FACT4_Pos)      /*!< 0x00000010 */
#define CAN_FA1R_FACT4                       CAN_FA1R_FACT4_Msk                /*!< Filter 4 Active */
#define CAN_FA1R_FACT5_Pos                   (5U)
#define CAN_FA1R_FACT5_Msk                   (0x1UL << CAN_FA1R_FACT5_Pos)      /*!< 0x00000020 */
#define CAN_FA1R_FACT5                       CAN_FA1R_FACT5_Msk                /*!< Filter 5 Active */
#define CAN_FA1R_FACT6_Pos                   (6U)
#define CAN_FA1R_FACT6_Msk                   (0x1UL << CAN_FA1R_FACT6_Pos)      /*!< 0x00000040 */
#define CAN_FA1R_FACT6                       CAN_FA1R_FACT6_Msk                /*!< Filter 6 Active */
#define CAN_FA1R_FACT7_Pos                   (7U)
#define CAN_FA1R_FACT7_Msk                   (0x1UL << CAN_FA1R_FACT7_Pos)      /*!< 0x00000080 */
#define CAN_FA1R_FACT7                       CAN_FA1R_FACT7_Msk                /*!< Filter 7 Active */
#define CAN_FA1R_FACT8_Pos                   (8U)
#define CAN_FA1R_FACT8_Msk                   (0x1UL << CAN_FA1R_FACT8_Pos)      /*!< 0x00000100 */
#define CAN_FA1R_FACT8                       CAN_FA1R_FACT8_Msk                /*!< Filter 8 Active */
#define CAN_FA1R_FACT9_Pos                   (9U)
#define CAN_FA1R_FACT9_Msk                   (0x1UL << CAN_FA1R_FACT9_Pos)      /*!< 0x00000200 */
#define CAN_FA1R_FACT9                       CAN_FA1R_FACT9_Msk                /*!< Filter 9 Active */
#define CAN_FA1R_FACT10_Pos                  (10U)
#define CAN_FA1R_FACT10_Msk                  (0x1UL << CAN_FA1R_FACT10_Pos)     /*!< 0x00000400 */
#define CAN_FA1R_FACT10                      CAN_FA1R_FACT10_Msk               /*!< Filter 10 Active */
#define CAN_FA1R_FACT11_Pos                  (11U)
#define CAN_FA1R_FACT11_Msk                  (0x1UL << CAN_FA1R_FACT11_Pos)     /*!< 0x00000800 */
#define CAN_FA1R_FACT11                      CAN_FA1R_FACT11_Msk               /*!< Filter 11 Active */
#define CAN_FA1R_FACT12_Pos                  (12U)
#define CAN_FA1R_FACT12_Msk                  (0x1UL << CAN_FA1R_FACT12_Pos)     /*!< 0x00001000 */
#define CAN_FA1R_FACT12                      CAN_FA1R_FACT12_Msk               /*!< Filter 12 Active */
#define CAN_FA1R_FACT13_Pos                  (13U)
#define CAN_FA1R_FACT13_Msk                  (0x1UL << CAN_FA1R_FACT13_Pos)     /*!< 0x00002000 */
#define CAN_FA1R_FACT13                      CAN_FA1R_FACT13_Msk               /*!< Filter 13 Active */

/*******************  Bit definition for CAN_F0R1 register  *******************/
#define CAN_F0R1_FB0_Pos                     (0U)
#define CAN_F0R1_FB0_Msk                     (0x1UL << CAN_F0R1_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F0R1_FB0                         CAN_F0R1_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F0R1_FB1_Pos                     (1U)
#define CAN_F0R1_FB1_Msk                     (0x1UL << CAN_F0R1_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F0R1_FB1                         CAN_F0R1_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F0R1_FB2_Pos                     (2U)
#define CAN_F0R1_FB2_Msk                     (0x1UL << CAN_F0R1_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F0R1_FB2                         CAN_F0R1_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F0R1_FB3_Pos                     (3U)
#define CAN_F0R1_FB3_Msk                     (0x1UL << CAN_F0R1_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F0R1_FB3                         CAN_F0R1_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F0R1_FB4_Pos                     (4U)
#define CAN_F0R1_FB4_Msk                     (0x1UL << CAN_F0R1_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F0R1_FB4                         CAN_F0R1_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F0R1_FB5_Pos                     (5U)
#define CAN_F0R1_FB5_Msk                     (0x1UL << CAN_F0R1_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F0R1_FB5                         CAN_F0R1_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F0R1_FB6_Pos                     (6U)
#define CAN_F0R1_FB6_Msk                     (0x1UL << CAN_F0R1_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F0R1_FB6                         CAN_F0R1_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F0R1_FB7_Pos                     (7U)
#define CAN_F0R1_FB7_Msk                     (0x1UL << CAN_F0R1_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F0R1_FB7                         CAN_F0R1_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F0R1_FB8_Pos                     (8U)
#define CAN_F0R1_FB8_Msk                     (0x1UL << CAN_F0R1_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F0R1_FB8                         CAN_F0R1_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F0R1_FB9_Pos                     (9U)
#define CAN_F0R1_FB9_Msk                     (0x1UL << CAN_F0R1_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F0R1_FB9                         CAN_F0R1_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F0R1_FB10_Pos                    (10U)
#define CAN_F0R1_FB10_Msk                    (0x1UL << CAN_F0R1_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F0R1_FB10                        CAN_F0R1_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F0R1_FB11_Pos                    (11U)
#define CAN_F0R1_FB11_Msk                    (0x1UL << CAN_F0R1_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F0R1_FB11                        CAN_F0R1_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F0R1_FB12_Pos                    (12U)
#define CAN_F0R1_FB12_Msk                    (0x1UL << CAN_F0R1_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F0R1_FB12                        CAN_F0R1_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F0R1_FB13_Pos                    (13U)
#define CAN_F0R1_FB13_Msk                    (0x1UL << CAN_F0R1_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F0R1_FB13                        CAN_F0R1_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F0R1_FB14_Pos                    (14U)
#define CAN_F0R1_FB14_Msk                    (0x1UL << CAN_F0R1_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F0R1_FB14                        CAN_F0R1_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F0R1_FB15_Pos                    (15U)
#define CAN_F0R1_FB15_Msk                    (0x1UL << CAN_F0R1_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F0R1_FB15                        CAN_F0R1_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F0R1_FB16_Pos                    (16U)
#define CAN_F0R1_FB16_Msk                    (0x1UL << CAN_F0R1_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F0R1_FB16                        CAN_F0R1_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F0R1_FB17_Pos                    (17U)
#define CAN_F0R1_FB17_Msk                    (0x1UL << CAN_F0R1_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F0R1_FB17                        CAN_F0R1_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F0R1_FB18_Pos                    (18U)
#define CAN_F0R1_FB18_Msk                    (0x1UL << CAN_F0R1_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F0R1_FB18                        CAN_F0R1_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F0R1_FB19_Pos                    (19U)
#define CAN_F0R1_FB19_Msk                    (0x1UL << CAN_F0R1_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F0R1_FB19                        CAN_F0R1_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F0R1_FB20_Pos                    (20U)
#define CAN_F0R1_FB20_Msk                    (0x1UL << CAN_F0R1_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F0R1_FB20                        CAN_F0R1_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F0R1_FB21_Pos                    (21U)
#define CAN_F0R1_FB21_Msk                    (0x1UL << CAN_F0R1_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F0R1_FB21                        CAN_F0R1_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F0R1_FB22_Pos                    (22U)
#define CAN_F0R1_FB22_Msk                    (0x1UL << CAN_F0R1_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F0R1_FB22                        CAN_F0R1_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F0R1_FB23_Pos                    (23U)
#define CAN_F0R1_FB23_Msk                    (0x1UL << CAN_F0R1_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F0R1_FB23                        CAN_F0R1_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F0R1_FB24_Pos                    (24U)
#define CAN_F0R1_FB24_Msk                    (0x1UL << CAN_F0R1_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F0R1_FB24                        CAN_F0R1_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F0R1_FB25_Pos                    (25U)
#define CAN_F0R1_FB25_Msk                    (0x1UL << CAN_F0R1_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F0R1_FB25                        CAN_F0R1_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F0R1_FB26_Pos                    (26U)
#define CAN_F0R1_FB26_Msk                    (0x1UL << CAN_F0R1_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F0R1_FB26                        CAN_F0R1_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F0R1_FB27_Pos                    (27U)
#define CAN_F0R1_FB27_Msk                    (0x1UL << CAN_F0R1_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F0R1_FB27                        CAN_F0R1_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F0R1_FB28_Pos                    (28U)
#define CAN_F0R1_FB28_Msk                    (0x1UL << CAN_F0R1_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F0R1_FB28                        CAN_F0R1_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F0R1_FB29_Pos                    (29U)
#define CAN_F0R1_FB29_Msk                    (0x1UL << CAN_F0R1_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F0R1_FB29                        CAN_F0R1_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F0R1_FB30_Pos                    (30U)
#define CAN_F0R1_FB30_Msk                    (0x1UL << CAN_F0R1_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F0R1_FB30                        CAN_F0R1_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F0R1_FB31_Pos                    (31U)
#define CAN_F0R1_FB31_Msk                    (0x1UL << CAN_F0R1_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F0R1_FB31                        CAN_F0R1_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F1R1 register  *******************/
#define CAN_F1R1_FB0_Pos                     (0U)
#define CAN_F1R1_FB0_Msk                     (0x1UL << CAN_F1R1_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F1R1_FB0                         CAN_F1R1_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F1R1_FB1_Pos                     (1U)
#define CAN_F1R1_FB1_Msk                     (0x1UL << CAN_F1R1_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F1R1_FB1                         CAN_F1R1_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F1R1_FB2_Pos                     (2U)
#define CAN_F1R1_FB2_Msk                     (0x1UL << CAN_F1R1_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F1R1_FB2                         CAN_F1R1_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F1R1_FB3_Pos                     (3U)
#define CAN_F1R1_FB3_Msk                     (0x1UL << CAN_F1R1_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F1R1_FB3                         CAN_F1R1_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F1R1_FB4_Pos                     (4U)
#define CAN_F1R1_FB4_Msk                     (0x1UL << CAN_F1R1_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F1R1_FB4                         CAN_F1R1_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F1R1_FB5_Pos                     (5U)
#define CAN_F1R1_FB5_Msk                     (0x1UL << CAN_F1R1_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F1R1_FB5                         CAN_F1R1_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F1R1_FB6_Pos                     (6U)
#define CAN_F1R1_FB6_Msk                     (0x1UL << CAN_F1R1_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F1R1_FB6                         CAN_F1R1_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F1R1_FB7_Pos                     (7U)
#define CAN_F1R1_FB7_Msk                     (0x1UL << CAN_F1R1_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F1R1_FB7                         CAN_F1R1_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F1R1_FB8_Pos                     (8U)
#define CAN_F1R1_FB8_Msk                     (0x1UL << CAN_F1R1_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F1R1_FB8                         CAN_F1R1_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F1R1_FB9_Pos                     (9U)
#define CAN_F1R1_FB9_Msk                     (0x1UL << CAN_F1R1_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F1R1_FB9                         CAN_F1R1_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F1R1_FB10_Pos                    (10U)
#define CAN_F1R1_FB10_Msk                    (0x1UL << CAN_F1R1_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F1R1_FB10                        CAN_F1R1_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F1R1_FB11_Pos                    (11U)
#define CAN_F1R1_FB11_Msk                    (0x1UL << CAN_F1R1_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F1R1_FB11                        CAN_F1R1_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F1R1_FB12_Pos                    (12U)
#define CAN_F1R1_FB12_Msk                    (0x1UL << CAN_F1R1_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F1R1_FB12                        CAN_F1R1_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F1R1_FB13_Pos                    (13U)
#define CAN_F1R1_FB13_Msk                    (0x1UL << CAN_F1R1_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F1R1_FB13                        CAN_F1R1_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F1R1_FB14_Pos                    (14U)
#define CAN_F1R1_FB14_Msk                    (0x1UL << CAN_F1R1_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F1R1_FB14                        CAN_F1R1_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F1R1_FB15_Pos                    (15U)
#define CAN_F1R1_FB15_Msk                    (0x1UL << CAN_F1R1_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F1R1_FB15                        CAN_F1R1_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F1R1_FB16_Pos                    (16U)
#define CAN_F1R1_FB16_Msk                    (0x1UL << CAN_F1R1_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F1R1_FB16                        CAN_F1R1_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F1R1_FB17_Pos                    (17U)
#define CAN_F1R1_FB17_Msk                    (0x1UL << CAN_F1R1_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F1R1_FB17                        CAN_F1R1_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F1R1_FB18_Pos                    (18U)
#define CAN_F1R1_FB18_Msk                    (0x1UL << CAN_F1R1_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F1R1_FB18                        CAN_F1R1_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F1R1_FB19_Pos                    (19U)
#define CAN_F1R1_FB19_Msk                    (0x1UL << CAN_F1R1_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F1R1_FB19                        CAN_F1R1_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F1R1_FB20_Pos                    (20U)
#define CAN_F1R1_FB20_Msk                    (0x1UL << CAN_F1R1_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F1R1_FB20                        CAN_F1R1_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F1R1_FB21_Pos                    (21U)
#define CAN_F1R1_FB21_Msk                    (0x1UL << CAN_F1R1_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F1R1_FB21                        CAN_F1R1_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F1R1_FB22_Pos                    (22U)
#define CAN_F1R1_FB22_Msk                    (0x1UL << CAN_F1R1_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F1R1_FB22                        CAN_F1R1_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F1R1_FB23_Pos                    (23U)
#define CAN_F1R1_FB23_Msk                    (0x1UL << CAN_F1R1_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F1R1_FB23                        CAN_F1R1_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F1R1_FB24_Pos                    (24U)
#define CAN_F1R1_FB24_Msk                    (0x1UL << CAN_F1R1_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F1R1_FB24                        CAN_F1R1_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F1R1_FB25_Pos                    (25U)
#define CAN_F1R1_FB25_Msk                    (0x1UL << CAN_F1R1_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F1R1_FB25                        CAN_F1R1_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F1R1_FB26_Pos                    (26U)
#define CAN_F1R1_FB26_Msk                    (0x1UL << CAN_F1R1_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F1R1_FB26                        CAN_F1R1_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F1R1_FB27_Pos                    (27U)
#define CAN_F1R1_FB27_Msk                    (0x1UL << CAN_F1R1_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F1R1_FB27                        CAN_F1R1_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F1R1_FB28_Pos                    (28U)
#define CAN_F1R1_FB28_Msk                    (0x1UL << CAN_F1R1_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F1R1_FB28                        CAN_F1R1_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F1R1_FB29_Pos                    (29U)
#define CAN_F1R1_FB29_Msk                    (0x1UL << CAN_F1R1_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F1R1_FB29                        CAN_F1R1_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F1R1_FB30_Pos                    (30U)
#define CAN_F1R1_FB30_Msk                    (0x1UL << CAN_F1R1_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F1R1_FB30                        CAN_F1R1_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F1R1_FB31_Pos                    (31U)
#define CAN_F1R1_FB31_Msk                    (0x1UL << CAN_F1R1_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F1R1_FB31                        CAN_F1R1_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F2R1 register  *******************/
#define CAN_F2R1_FB0_Pos                     (0U)
#define CAN_F2R1_FB0_Msk                     (0x1UL << CAN_F2R1_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F2R1_FB0                         CAN_F2R1_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F2R1_FB1_Pos                     (1U)
#define CAN_F2R1_FB1_Msk                     (0x1UL << CAN_F2R1_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F2R1_FB1                         CAN_F2R1_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F2R1_FB2_Pos                     (2U)
#define CAN_F2R1_FB2_Msk                     (0x1UL << CAN_F2R1_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F2R1_FB2                         CAN_F2R1_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F2R1_FB3_Pos                     (3U)
#define CAN_F2R1_FB3_Msk                     (0x1UL << CAN_F2R1_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F2R1_FB3                         CAN_F2R1_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F2R1_FB4_Pos                     (4U)
#define CAN_F2R1_FB4_Msk                     (0x1UL << CAN_F2R1_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F2R1_FB4                         CAN_F2R1_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F2R1_FB5_Pos                     (5U)
#define CAN_F2R1_FB5_Msk                     (0x1UL << CAN_F2R1_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F2R1_FB5                         CAN_F2R1_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F2R1_FB6_Pos                     (6U)
#define CAN_F2R1_FB6_Msk                     (0x1UL << CAN_F2R1_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F2R1_FB6                         CAN_F2R1_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F2R1_FB7_Pos                     (7U)
#define CAN_F2R1_FB7_Msk                     (0x1UL << CAN_F2R1_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F2R1_FB7                         CAN_F2R1_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F2R1_FB8_Pos                     (8U)
#define CAN_F2R1_FB8_Msk                     (0x1UL << CAN_F2R1_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F2R1_FB8                         CAN_F2R1_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F2R1_FB9_Pos                     (9U)
#define CAN_F2R1_FB9_Msk                     (0x1UL << CAN_F2R1_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F2R1_FB9                         CAN_F2R1_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F2R1_FB10_Pos                    (10U)
#define CAN_F2R1_FB10_Msk                    (0x1UL << CAN_F2R1_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F2R1_FB10                        CAN_F2R1_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F2R1_FB11_Pos                    (11U)
#define CAN_F2R1_FB11_Msk                    (0x1UL << CAN_F2R1_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F2R1_FB11                        CAN_F2R1_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F2R1_FB12_Pos                    (12U)
#define CAN_F2R1_FB12_Msk                    (0x1UL << CAN_F2R1_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F2R1_FB12                        CAN_F2R1_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F2R1_FB13_Pos                    (13U)
#define CAN_F2R1_FB13_Msk                    (0x1UL << CAN_F2R1_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F2R1_FB13                        CAN_F2R1_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F2R1_FB14_Pos                    (14U)
#define CAN_F2R1_FB14_Msk                    (0x1UL << CAN_F2R1_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F2R1_FB14                        CAN_F2R1_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F2R1_FB15_Pos                    (15U)
#define CAN_F2R1_FB15_Msk                    (0x1UL << CAN_F2R1_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F2R1_FB15                        CAN_F2R1_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F2R1_FB16_Pos                    (16U)
#define CAN_F2R1_FB16_Msk                    (0x1UL << CAN_F2R1_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F2R1_FB16                        CAN_F2R1_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F2R1_FB17_Pos                    (17U)
#define CAN_F2R1_FB17_Msk                    (0x1UL << CAN_F2R1_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F2R1_FB17                        CAN_F2R1_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F2R1_FB18_Pos                    (18U)
#define CAN_F2R1_FB18_Msk                    (0x1UL << CAN_F2R1_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F2R1_FB18                        CAN_F2R1_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F2R1_FB19_Pos                    (19U)
#define CAN_F2R1_FB19_Msk                    (0x1UL << CAN_F2R1_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F2R1_FB19                        CAN_F2R1_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F2R1_FB20_Pos                    (20U)
#define CAN_F2R1_FB20_Msk                    (0x1UL << CAN_F2R1_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F2R1_FB20                        CAN_F2R1_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F2R1_FB21_Pos                    (21U)
#define CAN_F2R1_FB21_Msk                    (0x1UL << CAN_F2R1_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F2R1_FB21                        CAN_F2R1_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F2R1_FB22_Pos                    (22U)
#define CAN_F2R1_FB22_Msk                    (0x1UL << CAN_F2R1_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F2R1_FB22                        CAN_F2R1_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F2R1_FB23_Pos                    (23U)
#define CAN_F2R1_FB23_Msk                    (0x1UL << CAN_F2R1_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F2R1_FB23                        CAN_F2R1_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F2R1_FB24_Pos                    (24U)
#define CAN_F2R1_FB24_Msk                    (0x1UL << CAN_F2R1_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F2R1_FB24                        CAN_F2R1_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F2R1_FB25_Pos                    (25U)
#define CAN_F2R1_FB25_Msk                    (0x1UL << CAN_F2R1_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F2R1_FB25                        CAN_F2R1_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F2R1_FB26_Pos                    (26U)
#define CAN_F2R1_FB26_Msk                    (0x1UL << CAN_F2R1_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F2R1_FB26                        CAN_F2R1_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F2R1_FB27_Pos                    (27U)
#define CAN_F2R1_FB27_Msk                    (0x1UL << CAN_F2R1_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F2R1_FB27                        CAN_F2R1_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F2R1_FB28_Pos                    (28U)
#define CAN_F2R1_FB28_Msk                    (0x1UL << CAN_F2R1_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F2R1_FB28                        CAN_F2R1_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F2R1_FB29_Pos                    (29U)
#define CAN_F2R1_FB29_Msk                    (0x1UL << CAN_F2R1_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F2R1_FB29                        CAN_F2R1_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F2R1_FB30_Pos                    (30U)
#define CAN_F2R1_FB30_Msk                    (0x1UL << CAN_F2R1_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F2R1_FB30                        CAN_F2R1_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F2R1_FB31_Pos                    (31U)
#define CAN_F2R1_FB31_Msk                    (0x1UL << CAN_F2R1_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F2R1_FB31                        CAN_F2R1_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F3R1 register  *******************/
#define CAN_F3R1_FB0_Pos                     (0U)
#define CAN_F3R1_FB0_Msk                     (0x1UL << CAN_F3R1_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F3R1_FB0                         CAN_F3R1_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F3R1_FB1_Pos                     (1U)
#define CAN_F3R1_FB1_Msk                     (0x1UL << CAN_F3R1_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F3R1_FB1                         CAN_F3R1_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F3R1_FB2_Pos                     (2U)
#define CAN_F3R1_FB2_Msk                     (0x1UL << CAN_F3R1_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F3R1_FB2                         CAN_F3R1_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F3R1_FB3_Pos                     (3U)
#define CAN_F3R1_FB3_Msk                     (0x1UL << CAN_F3R1_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F3R1_FB3                         CAN_F3R1_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F3R1_FB4_Pos                     (4U)
#define CAN_F3R1_FB4_Msk                     (0x1UL << CAN_F3R1_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F3R1_FB4                         CAN_F3R1_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F3R1_FB5_Pos                     (5U)
#define CAN_F3R1_FB5_Msk                     (0x1UL << CAN_F3R1_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F3R1_FB5                         CAN_F3R1_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F3R1_FB6_Pos                     (6U)
#define CAN_F3R1_FB6_Msk                     (0x1UL << CAN_F3R1_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F3R1_FB6                         CAN_F3R1_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F3R1_FB7_Pos                     (7U)
#define CAN_F3R1_FB7_Msk                     (0x1UL << CAN_F3R1_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F3R1_FB7                         CAN_F3R1_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F3R1_FB8_Pos                     (8U)
#define CAN_F3R1_FB8_Msk                     (0x1UL << CAN_F3R1_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F3R1_FB8                         CAN_F3R1_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F3R1_FB9_Pos                     (9U)
#define CAN_F3R1_FB9_Msk                     (0x1UL << CAN_F3R1_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F3R1_FB9                         CAN_F3R1_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F3R1_FB10_Pos                    (10U)
#define CAN_F3R1_FB10_Msk                    (0x1UL << CAN_F3R1_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F3R1_FB10                        CAN_F3R1_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F3R1_FB11_Pos                    (11U)
#define CAN_F3R1_FB11_Msk                    (0x1UL << CAN_F3R1_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F3R1_FB11                        CAN_F3R1_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F3R1_FB12_Pos                    (12U)
#define CAN_F3R1_FB12_Msk                    (0x1UL << CAN_F3R1_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F3R1_FB12                        CAN_F3R1_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F3R1_FB13_Pos                    (13U)
#define CAN_F3R1_FB13_Msk                    (0x1UL << CAN_F3R1_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F3R1_FB13                        CAN_F3R1_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F3R1_FB14_Pos                    (14U)
#define CAN_F3R1_FB14_Msk                    (0x1UL << CAN_F3R1_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F3R1_FB14                        CAN_F3R1_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F3R1_FB15_Pos                    (15U)
#define CAN_F3R1_FB15_Msk                    (0x1UL << CAN_F3R1_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F3R1_FB15                        CAN_F3R1_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F3R1_FB16_Pos                    (16U)
#define CAN_F3R1_FB16_Msk                    (0x1UL << CAN_F3R1_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F3R1_FB16                        CAN_F3R1_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F3R1_FB17_Pos                    (17U)
#define CAN_F3R1_FB17_Msk                    (0x1UL << CAN_F3R1_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F3R1_FB17                        CAN_F3R1_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F3R1_FB18_Pos                    (18U)
#define CAN_F3R1_FB18_Msk                    (0x1UL << CAN_F3R1_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F3R1_FB18                        CAN_F3R1_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F3R1_FB19_Pos                    (19U)
#define CAN_F3R1_FB19_Msk                    (0x1UL << CAN_F3R1_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F3R1_FB19                        CAN_F3R1_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F3R1_FB20_Pos                    (20U)
#define CAN_F3R1_FB20_Msk                    (0x1UL << CAN_F3R1_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F3R1_FB20                        CAN_F3R1_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F3R1_FB21_Pos                    (21U)
#define CAN_F3R1_FB21_Msk                    (0x1UL << CAN_F3R1_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F3R1_FB21                        CAN_F3R1_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F3R1_FB22_Pos                    (22U)
#define CAN_F3R1_FB22_Msk                    (0x1UL << CAN_F3R1_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F3R1_FB22                        CAN_F3R1_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F3R1_FB23_Pos                    (23U)
#define CAN_F3R1_FB23_Msk                    (0x1UL << CAN_F3R1_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F3R1_FB23                        CAN_F3R1_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F3R1_FB24_Pos                    (24U)
#define CAN_F3R1_FB24_Msk                    (0x1UL << CAN_F3R1_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F3R1_FB24                        CAN_F3R1_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F3R1_FB25_Pos                    (25U)
#define CAN_F3R1_FB25_Msk                    (0x1UL << CAN_F3R1_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F3R1_FB25                        CAN_F3R1_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F3R1_FB26_Pos                    (26U)
#define CAN_F3R1_FB26_Msk                    (0x1UL << CAN_F3R1_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F3R1_FB26                        CAN_F3R1_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F3R1_FB27_Pos                    (27U)
#define CAN_F3R1_FB27_Msk                    (0x1UL << CAN_F3R1_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F3R1_FB27                        CAN_F3R1_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F3R1_FB28_Pos                    (28U)
#define CAN_F3R1_FB28_Msk                    (0x1UL << CAN_F3R1_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F3R1_FB28                        CAN_F3R1_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F3R1_FB29_Pos                    (29U)
#define CAN_F3R1_FB29_Msk                    (0x1UL << CAN_F3R1_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F3R1_FB29                        CAN_F3R1_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F3R1_FB30_Pos                    (30U)
#define CAN_F3R1_FB30_Msk                    (0x1UL << CAN_F3R1_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F3R1_FB30                        CAN_F3R1_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F3R1_FB31_Pos                    (31U)
#define CAN_F3R1_FB31_Msk                    (0x1UL << CAN_F3R1_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F3R1_FB31                        CAN_F3R1_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F4R1 register  *******************/
#define CAN_F4R1_FB0_Pos                     (0U)
#define CAN_F4R1_FB0_Msk                     (0x1UL << CAN_F4R1_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F4R1_FB0                         CAN_F4R1_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F4R1_FB1_Pos                     (1U)
#define CAN_F4R1_FB1_Msk                     (0x1UL << CAN_F4R1_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F4R1_FB1                         CAN_F4R1_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F4R1_FB2_Pos                     (2U)
#define CAN_F4R1_FB2_Msk                     (0x1UL << CAN_F4R1_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F4R1_FB2                         CAN_F4R1_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F4R1_FB3_Pos                     (3U)
#define CAN_F4R1_FB3_Msk                     (0x1UL << CAN_F4R1_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F4R1_FB3                         CAN_F4R1_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F4R1_FB4_Pos                     (4U)
#define CAN_F4R1_FB4_Msk                     (0x1UL << CAN_F4R1_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F4R1_FB4                         CAN_F4R1_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F4R1_FB5_Pos                     (5U)
#define CAN_F4R1_FB5_Msk                     (0x1UL << CAN_F4R1_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F4R1_FB5                         CAN_F4R1_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F4R1_FB6_Pos                     (6U)
#define CAN_F4R1_FB6_Msk                     (0x1UL << CAN_F4R1_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F4R1_FB6                         CAN_F4R1_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F4R1_FB7_Pos                     (7U)
#define CAN_F4R1_FB7_Msk                     (0x1UL << CAN_F4R1_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F4R1_FB7                         CAN_F4R1_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F4R1_FB8_Pos                     (8U)
#define CAN_F4R1_FB8_Msk                     (0x1UL << CAN_F4R1_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F4R1_FB8                         CAN_F4R1_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F4R1_FB9_Pos                     (9U)
#define CAN_F4R1_FB9_Msk                     (0x1UL << CAN_F4R1_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F4R1_FB9                         CAN_F4R1_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F4R1_FB10_Pos                    (10U)
#define CAN_F4R1_FB10_Msk                    (0x1UL << CAN_F4R1_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F4R1_FB10                        CAN_F4R1_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F4R1_FB11_Pos                    (11U)
#define CAN_F4R1_FB11_Msk                    (0x1UL << CAN_F4R1_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F4R1_FB11                        CAN_F4R1_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F4R1_FB12_Pos                    (12U)
#define CAN_F4R1_FB12_Msk                    (0x1UL << CAN_F4R1_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F4R1_FB12                        CAN_F4R1_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F4R1_FB13_Pos                    (13U)
#define CAN_F4R1_FB13_Msk                    (0x1UL << CAN_F4R1_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F4R1_FB13                        CAN_F4R1_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F4R1_FB14_Pos                    (14U)
#define CAN_F4R1_FB14_Msk                    (0x1UL << CAN_F4R1_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F4R1_FB14                        CAN_F4R1_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F4R1_FB15_Pos                    (15U)
#define CAN_F4R1_FB15_Msk                    (0x1UL << CAN_F4R1_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F4R1_FB15                        CAN_F4R1_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F4R1_FB16_Pos                    (16U)
#define CAN_F4R1_FB16_Msk                    (0x1UL << CAN_F4R1_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F4R1_FB16                        CAN_F4R1_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F4R1_FB17_Pos                    (17U)
#define CAN_F4R1_FB17_Msk                    (0x1UL << CAN_F4R1_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F4R1_FB17                        CAN_F4R1_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F4R1_FB18_Pos                    (18U)
#define CAN_F4R1_FB18_Msk                    (0x1UL << CAN_F4R1_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F4R1_FB18                        CAN_F4R1_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F4R1_FB19_Pos                    (19U)
#define CAN_F4R1_FB19_Msk                    (0x1UL << CAN_F4R1_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F4R1_FB19                        CAN_F4R1_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F4R1_FB20_Pos                    (20U)
#define CAN_F4R1_FB20_Msk                    (0x1UL << CAN_F4R1_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F4R1_FB20                        CAN_F4R1_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F4R1_FB21_Pos                    (21U)
#define CAN_F4R1_FB21_Msk                    (0x1UL << CAN_F4R1_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F4R1_FB21                        CAN_F4R1_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F4R1_FB22_Pos                    (22U)
#define CAN_F4R1_FB22_Msk                    (0x1UL << CAN_F4R1_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F4R1_FB22                        CAN_F4R1_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F4R1_FB23_Pos                    (23U)
#define CAN_F4R1_FB23_Msk                    (0x1UL << CAN_F4R1_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F4R1_FB23                        CAN_F4R1_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F4R1_FB24_Pos                    (24U)
#define CAN_F4R1_FB24_Msk                    (0x1UL << CAN_F4R1_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F4R1_FB24                        CAN_F4R1_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F4R1_FB25_Pos                    (25U)
#define CAN_F4R1_FB25_Msk                    (0x1UL << CAN_F4R1_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F4R1_FB25                        CAN_F4R1_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F4R1_FB26_Pos                    (26U)
#define CAN_F4R1_FB26_Msk                    (0x1UL << CAN_F4R1_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F4R1_FB26                        CAN_F4R1_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F4R1_FB27_Pos                    (27U)
#define CAN_F4R1_FB27_Msk                    (0x1UL << CAN_F4R1_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F4R1_FB27                        CAN_F4R1_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F4R1_FB28_Pos                    (28U)
#define CAN_F4R1_FB28_Msk                    (0x1UL << CAN_F4R1_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F4R1_FB28                        CAN_F4R1_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F4R1_FB29_Pos                    (29U)
#define CAN_F4R1_FB29_Msk                    (0x1UL << CAN_F4R1_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F4R1_FB29                        CAN_F4R1_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F4R1_FB30_Pos                    (30U)
#define CAN_F4R1_FB30_Msk                    (0x1UL << CAN_F4R1_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F4R1_FB30                        CAN_F4R1_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F4R1_FB31_Pos                    (31U)
#define CAN_F4R1_FB31_Msk                    (0x1UL << CAN_F4R1_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F4R1_FB31                        CAN_F4R1_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F5R1 register  *******************/
#define CAN_F5R1_FB0_Pos                     (0U)
#define CAN_F5R1_FB0_Msk                     (0x1UL << CAN_F5R1_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F5R1_FB0                         CAN_F5R1_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F5R1_FB1_Pos                     (1U)
#define CAN_F5R1_FB1_Msk                     (0x1UL << CAN_F5R1_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F5R1_FB1                         CAN_F5R1_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F5R1_FB2_Pos                     (2U)
#define CAN_F5R1_FB2_Msk                     (0x1UL << CAN_F5R1_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F5R1_FB2                         CAN_F5R1_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F5R1_FB3_Pos                     (3U)
#define CAN_F5R1_FB3_Msk                     (0x1UL << CAN_F5R1_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F5R1_FB3                         CAN_F5R1_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F5R1_FB4_Pos                     (4U)
#define CAN_F5R1_FB4_Msk                     (0x1UL << CAN_F5R1_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F5R1_FB4                         CAN_F5R1_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F5R1_FB5_Pos                     (5U)
#define CAN_F5R1_FB5_Msk                     (0x1UL << CAN_F5R1_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F5R1_FB5                         CAN_F5R1_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F5R1_FB6_Pos                     (6U)
#define CAN_F5R1_FB6_Msk                     (0x1UL << CAN_F5R1_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F5R1_FB6                         CAN_F5R1_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F5R1_FB7_Pos                     (7U)
#define CAN_F5R1_FB7_Msk                     (0x1UL << CAN_F5R1_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F5R1_FB7                         CAN_F5R1_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F5R1_FB8_Pos                     (8U)
#define CAN_F5R1_FB8_Msk                     (0x1UL << CAN_F5R1_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F5R1_FB8                         CAN_F5R1_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F5R1_FB9_Pos                     (9U)
#define CAN_F5R1_FB9_Msk                     (0x1UL << CAN_F5R1_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F5R1_FB9                         CAN_F5R1_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F5R1_FB10_Pos                    (10U)
#define CAN_F5R1_FB10_Msk                    (0x1UL << CAN_F5R1_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F5R1_FB10                        CAN_F5R1_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F5R1_FB11_Pos                    (11U)
#define CAN_F5R1_FB11_Msk                    (0x1UL << CAN_F5R1_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F5R1_FB11                        CAN_F5R1_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F5R1_FB12_Pos                    (12U)
#define CAN_F5R1_FB12_Msk                    (0x1UL << CAN_F5R1_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F5R1_FB12                        CAN_F5R1_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F5R1_FB13_Pos                    (13U)
#define CAN_F5R1_FB13_Msk                    (0x1UL << CAN_F5R1_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F5R1_FB13                        CAN_F5R1_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F5R1_FB14_Pos                    (14U)
#define CAN_F5R1_FB14_Msk                    (0x1UL << CAN_F5R1_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F5R1_FB14                        CAN_F5R1_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F5R1_FB15_Pos                    (15U)
#define CAN_F5R1_FB15_Msk                    (0x1UL << CAN_F5R1_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F5R1_FB15                        CAN_F5R1_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F5R1_FB16_Pos                    (16U)
#define CAN_F5R1_FB16_Msk                    (0x1UL << CAN_F5R1_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F5R1_FB16                        CAN_F5R1_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F5R1_FB17_Pos                    (17U)
#define CAN_F5R1_FB17_Msk                    (0x1UL << CAN_F5R1_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F5R1_FB17                        CAN_F5R1_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F5R1_FB18_Pos                    (18U)
#define CAN_F5R1_FB18_Msk                    (0x1UL << CAN_F5R1_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F5R1_FB18                        CAN_F5R1_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F5R1_FB19_Pos                    (19U)
#define CAN_F5R1_FB19_Msk                    (0x1UL << CAN_F5R1_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F5R1_FB19                        CAN_F5R1_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F5R1_FB20_Pos                    (20U)
#define CAN_F5R1_FB20_Msk                    (0x1UL << CAN_F5R1_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F5R1_FB20                        CAN_F5R1_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F5R1_FB21_Pos                    (21U)
#define CAN_F5R1_FB21_Msk                    (0x1UL << CAN_F5R1_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F5R1_FB21                        CAN_F5R1_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F5R1_FB22_Pos                    (22U)
#define CAN_F5R1_FB22_Msk                    (0x1UL << CAN_F5R1_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F5R1_FB22                        CAN_F5R1_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F5R1_FB23_Pos                    (23U)
#define CAN_F5R1_FB23_Msk                    (0x1UL << CAN_F5R1_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F5R1_FB23                        CAN_F5R1_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F5R1_FB24_Pos                    (24U)
#define CAN_F5R1_FB24_Msk                    (0x1UL << CAN_F5R1_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F5R1_FB24                        CAN_F5R1_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F5R1_FB25_Pos                    (25U)
#define CAN_F5R1_FB25_Msk                    (0x1UL << CAN_F5R1_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F5R1_FB25                        CAN_F5R1_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F5R1_FB26_Pos                    (26U)
#define CAN_F5R1_FB26_Msk                    (0x1UL << CAN_F5R1_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F5R1_FB26                        CAN_F5R1_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F5R1_FB27_Pos                    (27U)
#define CAN_F5R1_FB27_Msk                    (0x1UL << CAN_F5R1_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F5R1_FB27                        CAN_F5R1_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F5R1_FB28_Pos                    (28U)
#define CAN_F5R1_FB28_Msk                    (0x1UL << CAN_F5R1_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F5R1_FB28                        CAN_F5R1_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F5R1_FB29_Pos                    (29U)
#define CAN_F5R1_FB29_Msk                    (0x1UL << CAN_F5R1_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F5R1_FB29                        CAN_F5R1_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F5R1_FB30_Pos                    (30U)
#define CAN_F5R1_FB30_Msk                    (0x1UL << CAN_F5R1_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F5R1_FB30                        CAN_F5R1_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F5R1_FB31_Pos                    (31U)
#define CAN_F5R1_FB31_Msk                    (0x1UL << CAN_F5R1_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F5R1_FB31                        CAN_F5R1_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F6R1 register  *******************/
#define CAN_F6R1_FB0_Pos                     (0U)
#define CAN_F6R1_FB0_Msk                     (0x1UL << CAN_F6R1_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F6R1_FB0                         CAN_F6R1_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F6R1_FB1_Pos                     (1U)
#define CAN_F6R1_FB1_Msk                     (0x1UL << CAN_F6R1_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F6R1_FB1                         CAN_F6R1_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F6R1_FB2_Pos                     (2U)
#define CAN_F6R1_FB2_Msk                     (0x1UL << CAN_F6R1_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F6R1_FB2                         CAN_F6R1_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F6R1_FB3_Pos                     (3U)
#define CAN_F6R1_FB3_Msk                     (0x1UL << CAN_F6R1_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F6R1_FB3                         CAN_F6R1_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F6R1_FB4_Pos                     (4U)
#define CAN_F6R1_FB4_Msk                     (0x1UL << CAN_F6R1_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F6R1_FB4                         CAN_F6R1_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F6R1_FB5_Pos                     (5U)
#define CAN_F6R1_FB5_Msk                     (0x1UL << CAN_F6R1_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F6R1_FB5                         CAN_F6R1_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F6R1_FB6_Pos                     (6U)
#define CAN_F6R1_FB6_Msk                     (0x1UL << CAN_F6R1_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F6R1_FB6                         CAN_F6R1_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F6R1_FB7_Pos                     (7U)
#define CAN_F6R1_FB7_Msk                     (0x1UL << CAN_F6R1_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F6R1_FB7                         CAN_F6R1_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F6R1_FB8_Pos                     (8U)
#define CAN_F6R1_FB8_Msk                     (0x1UL << CAN_F6R1_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F6R1_FB8                         CAN_F6R1_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F6R1_FB9_Pos                     (9U)
#define CAN_F6R1_FB9_Msk                     (0x1UL << CAN_F6R1_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F6R1_FB9                         CAN_F6R1_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F6R1_FB10_Pos                    (10U)
#define CAN_F6R1_FB10_Msk                    (0x1UL << CAN_F6R1_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F6R1_FB10                        CAN_F6R1_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F6R1_FB11_Pos                    (11U)
#define CAN_F6R1_FB11_Msk                    (0x1UL << CAN_F6R1_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F6R1_FB11                        CAN_F6R1_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F6R1_FB12_Pos                    (12U)
#define CAN_F6R1_FB12_Msk                    (0x1UL << CAN_F6R1_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F6R1_FB12                        CAN_F6R1_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F6R1_FB13_Pos                    (13U)
#define CAN_F6R1_FB13_Msk                    (0x1UL << CAN_F6R1_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F6R1_FB13                        CAN_F6R1_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F6R1_FB14_Pos                    (14U)
#define CAN_F6R1_FB14_Msk                    (0x1UL << CAN_F6R1_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F6R1_FB14                        CAN_F6R1_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F6R1_FB15_Pos                    (15U)
#define CAN_F6R1_FB15_Msk                    (0x1UL << CAN_F6R1_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F6R1_FB15                        CAN_F6R1_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F6R1_FB16_Pos                    (16U)
#define CAN_F6R1_FB16_Msk                    (0x1UL << CAN_F6R1_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F6R1_FB16                        CAN_F6R1_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F6R1_FB17_Pos                    (17U)
#define CAN_F6R1_FB17_Msk                    (0x1UL << CAN_F6R1_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F6R1_FB17                        CAN_F6R1_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F6R1_FB18_Pos                    (18U)
#define CAN_F6R1_FB18_Msk                    (0x1UL << CAN_F6R1_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F6R1_FB18                        CAN_F6R1_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F6R1_FB19_Pos                    (19U)
#define CAN_F6R1_FB19_Msk                    (0x1UL << CAN_F6R1_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F6R1_FB19                        CAN_F6R1_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F6R1_FB20_Pos                    (20U)
#define CAN_F6R1_FB20_Msk                    (0x1UL << CAN_F6R1_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F6R1_FB20                        CAN_F6R1_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F6R1_FB21_Pos                    (21U)
#define CAN_F6R1_FB21_Msk                    (0x1UL << CAN_F6R1_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F6R1_FB21                        CAN_F6R1_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F6R1_FB22_Pos                    (22U)
#define CAN_F6R1_FB22_Msk                    (0x1UL << CAN_F6R1_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F6R1_FB22                        CAN_F6R1_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F6R1_FB23_Pos                    (23U)
#define CAN_F6R1_FB23_Msk                    (0x1UL << CAN_F6R1_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F6R1_FB23                        CAN_F6R1_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F6R1_FB24_Pos                    (24U)
#define CAN_F6R1_FB24_Msk                    (0x1UL << CAN_F6R1_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F6R1_FB24                        CAN_F6R1_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F6R1_FB25_Pos                    (25U)
#define CAN_F6R1_FB25_Msk                    (0x1UL << CAN_F6R1_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F6R1_FB25                        CAN_F6R1_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F6R1_FB26_Pos                    (26U)
#define CAN_F6R1_FB26_Msk                    (0x1UL << CAN_F6R1_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F6R1_FB26                        CAN_F6R1_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F6R1_FB27_Pos                    (27U)
#define CAN_F6R1_FB27_Msk                    (0x1UL << CAN_F6R1_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F6R1_FB27                        CAN_F6R1_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F6R1_FB28_Pos                    (28U)
#define CAN_F6R1_FB28_Msk                    (0x1UL << CAN_F6R1_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F6R1_FB28                        CAN_F6R1_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F6R1_FB29_Pos                    (29U)
#define CAN_F6R1_FB29_Msk                    (0x1UL << CAN_F6R1_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F6R1_FB29                        CAN_F6R1_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F6R1_FB30_Pos                    (30U)
#define CAN_F6R1_FB30_Msk                    (0x1UL << CAN_F6R1_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F6R1_FB30                        CAN_F6R1_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F6R1_FB31_Pos                    (31U)
#define CAN_F6R1_FB31_Msk                    (0x1UL << CAN_F6R1_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F6R1_FB31                        CAN_F6R1_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F7R1 register  *******************/
#define CAN_F7R1_FB0_Pos                     (0U)
#define CAN_F7R1_FB0_Msk                     (0x1UL << CAN_F7R1_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F7R1_FB0                         CAN_F7R1_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F7R1_FB1_Pos                     (1U)
#define CAN_F7R1_FB1_Msk                     (0x1UL << CAN_F7R1_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F7R1_FB1                         CAN_F7R1_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F7R1_FB2_Pos                     (2U)
#define CAN_F7R1_FB2_Msk                     (0x1UL << CAN_F7R1_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F7R1_FB2                         CAN_F7R1_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F7R1_FB3_Pos                     (3U)
#define CAN_F7R1_FB3_Msk                     (0x1UL << CAN_F7R1_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F7R1_FB3                         CAN_F7R1_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F7R1_FB4_Pos                     (4U)
#define CAN_F7R1_FB4_Msk                     (0x1UL << CAN_F7R1_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F7R1_FB4                         CAN_F7R1_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F7R1_FB5_Pos                     (5U)
#define CAN_F7R1_FB5_Msk                     (0x1UL << CAN_F7R1_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F7R1_FB5                         CAN_F7R1_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F7R1_FB6_Pos                     (6U)
#define CAN_F7R1_FB6_Msk                     (0x1UL << CAN_F7R1_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F7R1_FB6                         CAN_F7R1_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F7R1_FB7_Pos                     (7U)
#define CAN_F7R1_FB7_Msk                     (0x1UL << CAN_F7R1_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F7R1_FB7                         CAN_F7R1_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F7R1_FB8_Pos                     (8U)
#define CAN_F7R1_FB8_Msk                     (0x1UL << CAN_F7R1_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F7R1_FB8                         CAN_F7R1_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F7R1_FB9_Pos                     (9U)
#define CAN_F7R1_FB9_Msk                     (0x1UL << CAN_F7R1_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F7R1_FB9                         CAN_F7R1_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F7R1_FB10_Pos                    (10U)
#define CAN_F7R1_FB10_Msk                    (0x1UL << CAN_F7R1_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F7R1_FB10                        CAN_F7R1_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F7R1_FB11_Pos                    (11U)
#define CAN_F7R1_FB11_Msk                    (0x1UL << CAN_F7R1_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F7R1_FB11                        CAN_F7R1_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F7R1_FB12_Pos                    (12U)
#define CAN_F7R1_FB12_Msk                    (0x1UL << CAN_F7R1_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F7R1_FB12                        CAN_F7R1_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F7R1_FB13_Pos                    (13U)
#define CAN_F7R1_FB13_Msk                    (0x1UL << CAN_F7R1_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F7R1_FB13                        CAN_F7R1_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F7R1_FB14_Pos                    (14U)
#define CAN_F7R1_FB14_Msk                    (0x1UL << CAN_F7R1_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F7R1_FB14                        CAN_F7R1_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F7R1_FB15_Pos                    (15U)
#define CAN_F7R1_FB15_Msk                    (0x1UL << CAN_F7R1_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F7R1_FB15                        CAN_F7R1_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F7R1_FB16_Pos                    (16U)
#define CAN_F7R1_FB16_Msk                    (0x1UL << CAN_F7R1_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F7R1_FB16                        CAN_F7R1_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F7R1_FB17_Pos                    (17U)
#define CAN_F7R1_FB17_Msk                    (0x1UL << CAN_F7R1_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F7R1_FB17                        CAN_F7R1_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F7R1_FB18_Pos                    (18U)
#define CAN_F7R1_FB18_Msk                    (0x1UL << CAN_F7R1_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F7R1_FB18                        CAN_F7R1_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F7R1_FB19_Pos                    (19U)
#define CAN_F7R1_FB19_Msk                    (0x1UL << CAN_F7R1_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F7R1_FB19                        CAN_F7R1_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F7R1_FB20_Pos                    (20U)
#define CAN_F7R1_FB20_Msk                    (0x1UL << CAN_F7R1_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F7R1_FB20                        CAN_F7R1_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F7R1_FB21_Pos                    (21U)
#define CAN_F7R1_FB21_Msk                    (0x1UL << CAN_F7R1_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F7R1_FB21                        CAN_F7R1_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F7R1_FB22_Pos                    (22U)
#define CAN_F7R1_FB22_Msk                    (0x1UL << CAN_F7R1_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F7R1_FB22                        CAN_F7R1_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F7R1_FB23_Pos                    (23U)
#define CAN_F7R1_FB23_Msk                    (0x1UL << CAN_F7R1_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F7R1_FB23                        CAN_F7R1_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F7R1_FB24_Pos                    (24U)
#define CAN_F7R1_FB24_Msk                    (0x1UL << CAN_F7R1_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F7R1_FB24                        CAN_F7R1_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F7R1_FB25_Pos                    (25U)
#define CAN_F7R1_FB25_Msk                    (0x1UL << CAN_F7R1_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F7R1_FB25                        CAN_F7R1_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F7R1_FB26_Pos                    (26U)
#define CAN_F7R1_FB26_Msk                    (0x1UL << CAN_F7R1_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F7R1_FB26                        CAN_F7R1_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F7R1_FB27_Pos                    (27U)
#define CAN_F7R1_FB27_Msk                    (0x1UL << CAN_F7R1_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F7R1_FB27                        CAN_F7R1_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F7R1_FB28_Pos                    (28U)
#define CAN_F7R1_FB28_Msk                    (0x1UL << CAN_F7R1_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F7R1_FB28                        CAN_F7R1_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F7R1_FB29_Pos                    (29U)
#define CAN_F7R1_FB29_Msk                    (0x1UL << CAN_F7R1_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F7R1_FB29                        CAN_F7R1_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F7R1_FB30_Pos                    (30U)
#define CAN_F7R1_FB30_Msk                    (0x1UL << CAN_F7R1_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F7R1_FB30                        CAN_F7R1_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F7R1_FB31_Pos                    (31U)
#define CAN_F7R1_FB31_Msk                    (0x1UL << CAN_F7R1_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F7R1_FB31                        CAN_F7R1_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F8R1 register  *******************/
#define CAN_F8R1_FB0_Pos                     (0U)
#define CAN_F8R1_FB0_Msk                     (0x1UL << CAN_F8R1_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F8R1_FB0                         CAN_F8R1_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F8R1_FB1_Pos                     (1U)
#define CAN_F8R1_FB1_Msk                     (0x1UL << CAN_F8R1_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F8R1_FB1                         CAN_F8R1_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F8R1_FB2_Pos                     (2U)
#define CAN_F8R1_FB2_Msk                     (0x1UL << CAN_F8R1_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F8R1_FB2                         CAN_F8R1_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F8R1_FB3_Pos                     (3U)
#define CAN_F8R1_FB3_Msk                     (0x1UL << CAN_F8R1_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F8R1_FB3                         CAN_F8R1_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F8R1_FB4_Pos                     (4U)
#define CAN_F8R1_FB4_Msk                     (0x1UL << CAN_F8R1_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F8R1_FB4                         CAN_F8R1_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F8R1_FB5_Pos                     (5U)
#define CAN_F8R1_FB5_Msk                     (0x1UL << CAN_F8R1_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F8R1_FB5                         CAN_F8R1_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F8R1_FB6_Pos                     (6U)
#define CAN_F8R1_FB6_Msk                     (0x1UL << CAN_F8R1_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F8R1_FB6                         CAN_F8R1_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F8R1_FB7_Pos                     (7U)
#define CAN_F8R1_FB7_Msk                     (0x1UL << CAN_F8R1_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F8R1_FB7                         CAN_F8R1_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F8R1_FB8_Pos                     (8U)
#define CAN_F8R1_FB8_Msk                     (0x1UL << CAN_F8R1_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F8R1_FB8                         CAN_F8R1_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F8R1_FB9_Pos                     (9U)
#define CAN_F8R1_FB9_Msk                     (0x1UL << CAN_F8R1_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F8R1_FB9                         CAN_F8R1_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F8R1_FB10_Pos                    (10U)
#define CAN_F8R1_FB10_Msk                    (0x1UL << CAN_F8R1_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F8R1_FB10                        CAN_F8R1_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F8R1_FB11_Pos                    (11U)
#define CAN_F8R1_FB11_Msk                    (0x1UL << CAN_F8R1_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F8R1_FB11                        CAN_F8R1_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F8R1_FB12_Pos                    (12U)
#define CAN_F8R1_FB12_Msk                    (0x1UL << CAN_F8R1_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F8R1_FB12                        CAN_F8R1_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F8R1_FB13_Pos                    (13U)
#define CAN_F8R1_FB13_Msk                    (0x1UL << CAN_F8R1_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F8R1_FB13                        CAN_F8R1_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F8R1_FB14_Pos                    (14U)
#define CAN_F8R1_FB14_Msk                    (0x1UL << CAN_F8R1_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F8R1_FB14                        CAN_F8R1_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F8R1_FB15_Pos                    (15U)
#define CAN_F8R1_FB15_Msk                    (0x1UL << CAN_F8R1_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F8R1_FB15                        CAN_F8R1_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F8R1_FB16_Pos                    (16U)
#define CAN_F8R1_FB16_Msk                    (0x1UL << CAN_F8R1_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F8R1_FB16                        CAN_F8R1_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F8R1_FB17_Pos                    (17U)
#define CAN_F8R1_FB17_Msk                    (0x1UL << CAN_F8R1_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F8R1_FB17                        CAN_F8R1_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F8R1_FB18_Pos                    (18U)
#define CAN_F8R1_FB18_Msk                    (0x1UL << CAN_F8R1_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F8R1_FB18                        CAN_F8R1_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F8R1_FB19_Pos                    (19U)
#define CAN_F8R1_FB19_Msk                    (0x1UL << CAN_F8R1_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F8R1_FB19                        CAN_F8R1_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F8R1_FB20_Pos                    (20U)
#define CAN_F8R1_FB20_Msk                    (0x1UL << CAN_F8R1_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F8R1_FB20                        CAN_F8R1_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F8R1_FB21_Pos                    (21U)
#define CAN_F8R1_FB21_Msk                    (0x1UL << CAN_F8R1_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F8R1_FB21                        CAN_F8R1_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F8R1_FB22_Pos                    (22U)
#define CAN_F8R1_FB22_Msk                    (0x1UL << CAN_F8R1_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F8R1_FB22                        CAN_F8R1_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F8R1_FB23_Pos                    (23U)
#define CAN_F8R1_FB23_Msk                    (0x1UL << CAN_F8R1_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F8R1_FB23                        CAN_F8R1_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F8R1_FB24_Pos                    (24U)
#define CAN_F8R1_FB24_Msk                    (0x1UL << CAN_F8R1_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F8R1_FB24                        CAN_F8R1_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F8R1_FB25_Pos                    (25U)
#define CAN_F8R1_FB25_Msk                    (0x1UL << CAN_F8R1_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F8R1_FB25                        CAN_F8R1_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F8R1_FB26_Pos                    (26U)
#define CAN_F8R1_FB26_Msk                    (0x1UL << CAN_F8R1_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F8R1_FB26                        CAN_F8R1_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F8R1_FB27_Pos                    (27U)
#define CAN_F8R1_FB27_Msk                    (0x1UL << CAN_F8R1_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F8R1_FB27                        CAN_F8R1_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F8R1_FB28_Pos                    (28U)
#define CAN_F8R1_FB28_Msk                    (0x1UL << CAN_F8R1_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F8R1_FB28                        CAN_F8R1_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F8R1_FB29_Pos                    (29U)
#define CAN_F8R1_FB29_Msk                    (0x1UL << CAN_F8R1_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F8R1_FB29                        CAN_F8R1_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F8R1_FB30_Pos                    (30U)
#define CAN_F8R1_FB30_Msk                    (0x1UL << CAN_F8R1_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F8R1_FB30                        CAN_F8R1_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F8R1_FB31_Pos                    (31U)
#define CAN_F8R1_FB31_Msk                    (0x1UL << CAN_F8R1_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F8R1_FB31                        CAN_F8R1_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F9R1 register  *******************/
#define CAN_F9R1_FB0_Pos                     (0U)
#define CAN_F9R1_FB0_Msk                     (0x1UL << CAN_F9R1_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F9R1_FB0                         CAN_F9R1_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F9R1_FB1_Pos                     (1U)
#define CAN_F9R1_FB1_Msk                     (0x1UL << CAN_F9R1_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F9R1_FB1                         CAN_F9R1_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F9R1_FB2_Pos                     (2U)
#define CAN_F9R1_FB2_Msk                     (0x1UL << CAN_F9R1_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F9R1_FB2                         CAN_F9R1_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F9R1_FB3_Pos                     (3U)
#define CAN_F9R1_FB3_Msk                     (0x1UL << CAN_F9R1_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F9R1_FB3                         CAN_F9R1_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F9R1_FB4_Pos                     (4U)
#define CAN_F9R1_FB4_Msk                     (0x1UL << CAN_F9R1_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F9R1_FB4                         CAN_F9R1_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F9R1_FB5_Pos                     (5U)
#define CAN_F9R1_FB5_Msk                     (0x1UL << CAN_F9R1_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F9R1_FB5                         CAN_F9R1_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F9R1_FB6_Pos                     (6U)
#define CAN_F9R1_FB6_Msk                     (0x1UL << CAN_F9R1_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F9R1_FB6                         CAN_F9R1_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F9R1_FB7_Pos                     (7U)
#define CAN_F9R1_FB7_Msk                     (0x1UL << CAN_F9R1_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F9R1_FB7                         CAN_F9R1_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F9R1_FB8_Pos                     (8U)
#define CAN_F9R1_FB8_Msk                     (0x1UL << CAN_F9R1_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F9R1_FB8                         CAN_F9R1_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F9R1_FB9_Pos                     (9U)
#define CAN_F9R1_FB9_Msk                     (0x1UL << CAN_F9R1_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F9R1_FB9                         CAN_F9R1_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F9R1_FB10_Pos                    (10U)
#define CAN_F9R1_FB10_Msk                    (0x1UL << CAN_F9R1_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F9R1_FB10                        CAN_F9R1_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F9R1_FB11_Pos                    (11U)
#define CAN_F9R1_FB11_Msk                    (0x1UL << CAN_F9R1_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F9R1_FB11                        CAN_F9R1_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F9R1_FB12_Pos                    (12U)
#define CAN_F9R1_FB12_Msk                    (0x1UL << CAN_F9R1_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F9R1_FB12                        CAN_F9R1_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F9R1_FB13_Pos                    (13U)
#define CAN_F9R1_FB13_Msk                    (0x1UL << CAN_F9R1_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F9R1_FB13                        CAN_F9R1_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F9R1_FB14_Pos                    (14U)
#define CAN_F9R1_FB14_Msk                    (0x1UL << CAN_F9R1_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F9R1_FB14                        CAN_F9R1_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F9R1_FB15_Pos                    (15U)
#define CAN_F9R1_FB15_Msk                    (0x1UL << CAN_F9R1_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F9R1_FB15                        CAN_F9R1_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F9R1_FB16_Pos                    (16U)
#define CAN_F9R1_FB16_Msk                    (0x1UL << CAN_F9R1_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F9R1_FB16                        CAN_F9R1_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F9R1_FB17_Pos                    (17U)
#define CAN_F9R1_FB17_Msk                    (0x1UL << CAN_F9R1_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F9R1_FB17                        CAN_F9R1_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F9R1_FB18_Pos                    (18U)
#define CAN_F9R1_FB18_Msk                    (0x1UL << CAN_F9R1_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F9R1_FB18                        CAN_F9R1_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F9R1_FB19_Pos                    (19U)
#define CAN_F9R1_FB19_Msk                    (0x1UL << CAN_F9R1_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F9R1_FB19                        CAN_F9R1_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F9R1_FB20_Pos                    (20U)
#define CAN_F9R1_FB20_Msk                    (0x1UL << CAN_F9R1_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F9R1_FB20                        CAN_F9R1_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F9R1_FB21_Pos                    (21U)
#define CAN_F9R1_FB21_Msk                    (0x1UL << CAN_F9R1_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F9R1_FB21                        CAN_F9R1_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F9R1_FB22_Pos                    (22U)
#define CAN_F9R1_FB22_Msk                    (0x1UL << CAN_F9R1_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F9R1_FB22                        CAN_F9R1_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F9R1_FB23_Pos                    (23U)
#define CAN_F9R1_FB23_Msk                    (0x1UL << CAN_F9R1_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F9R1_FB23                        CAN_F9R1_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F9R1_FB24_Pos                    (24U)
#define CAN_F9R1_FB24_Msk                    (0x1UL << CAN_F9R1_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F9R1_FB24                        CAN_F9R1_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F9R1_FB25_Pos                    (25U)
#define CAN_F9R1_FB25_Msk                    (0x1UL << CAN_F9R1_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F9R1_FB25                        CAN_F9R1_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F9R1_FB26_Pos                    (26U)
#define CAN_F9R1_FB26_Msk                    (0x1UL << CAN_F9R1_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F9R1_FB26                        CAN_F9R1_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F9R1_FB27_Pos                    (27U)
#define CAN_F9R1_FB27_Msk                    (0x1UL << CAN_F9R1_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F9R1_FB27                        CAN_F9R1_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F9R1_FB28_Pos                    (28U)
#define CAN_F9R1_FB28_Msk                    (0x1UL << CAN_F9R1_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F9R1_FB28                        CAN_F9R1_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F9R1_FB29_Pos                    (29U)
#define CAN_F9R1_FB29_Msk                    (0x1UL << CAN_F9R1_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F9R1_FB29                        CAN_F9R1_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F9R1_FB30_Pos                    (30U)
#define CAN_F9R1_FB30_Msk                    (0x1UL << CAN_F9R1_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F9R1_FB30                        CAN_F9R1_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F9R1_FB31_Pos                    (31U)
#define CAN_F9R1_FB31_Msk                    (0x1UL << CAN_F9R1_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F9R1_FB31                        CAN_F9R1_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F10R1 register  ******************/
#define CAN_F10R1_FB0_Pos                    (0U)
#define CAN_F10R1_FB0_Msk                    (0x1UL << CAN_F10R1_FB0_Pos)       /*!< 0x00000001 */
#define CAN_F10R1_FB0                        CAN_F10R1_FB0_Msk                 /*!< Filter bit 0 */
#define CAN_F10R1_FB1_Pos                    (1U)
#define CAN_F10R1_FB1_Msk                    (0x1UL << CAN_F10R1_FB1_Pos)       /*!< 0x00000002 */
#define CAN_F10R1_FB1                        CAN_F10R1_FB1_Msk                 /*!< Filter bit 1 */
#define CAN_F10R1_FB2_Pos                    (2U)
#define CAN_F10R1_FB2_Msk                    (0x1UL << CAN_F10R1_FB2_Pos)       /*!< 0x00000004 */
#define CAN_F10R1_FB2                        CAN_F10R1_FB2_Msk                 /*!< Filter bit 2 */
#define CAN_F10R1_FB3_Pos                    (3U)
#define CAN_F10R1_FB3_Msk                    (0x1UL << CAN_F10R1_FB3_Pos)       /*!< 0x00000008 */
#define CAN_F10R1_FB3                        CAN_F10R1_FB3_Msk                 /*!< Filter bit 3 */
#define CAN_F10R1_FB4_Pos                    (4U)
#define CAN_F10R1_FB4_Msk                    (0x1UL << CAN_F10R1_FB4_Pos)       /*!< 0x00000010 */
#define CAN_F10R1_FB4                        CAN_F10R1_FB4_Msk                 /*!< Filter bit 4 */
#define CAN_F10R1_FB5_Pos                    (5U)
#define CAN_F10R1_FB5_Msk                    (0x1UL << CAN_F10R1_FB5_Pos)       /*!< 0x00000020 */
#define CAN_F10R1_FB5                        CAN_F10R1_FB5_Msk                 /*!< Filter bit 5 */
#define CAN_F10R1_FB6_Pos                    (6U)
#define CAN_F10R1_FB6_Msk                    (0x1UL << CAN_F10R1_FB6_Pos)       /*!< 0x00000040 */
#define CAN_F10R1_FB6                        CAN_F10R1_FB6_Msk                 /*!< Filter bit 6 */
#define CAN_F10R1_FB7_Pos                    (7U)
#define CAN_F10R1_FB7_Msk                    (0x1UL << CAN_F10R1_FB7_Pos)       /*!< 0x00000080 */
#define CAN_F10R1_FB7                        CAN_F10R1_FB7_Msk                 /*!< Filter bit 7 */
#define CAN_F10R1_FB8_Pos                    (8U)
#define CAN_F10R1_FB8_Msk                    (0x1UL << CAN_F10R1_FB8_Pos)       /*!< 0x00000100 */
#define CAN_F10R1_FB8                        CAN_F10R1_FB8_Msk                 /*!< Filter bit 8 */
#define CAN_F10R1_FB9_Pos                    (9U)
#define CAN_F10R1_FB9_Msk                    (0x1UL << CAN_F10R1_FB9_Pos)       /*!< 0x00000200 */
#define CAN_F10R1_FB9                        CAN_F10R1_FB9_Msk                 /*!< Filter bit 9 */
#define CAN_F10R1_FB10_Pos                   (10U)
#define CAN_F10R1_FB10_Msk                   (0x1UL << CAN_F10R1_FB10_Pos)      /*!< 0x00000400 */
#define CAN_F10R1_FB10                       CAN_F10R1_FB10_Msk                /*!< Filter bit 10 */
#define CAN_F10R1_FB11_Pos                   (11U)
#define CAN_F10R1_FB11_Msk                   (0x1UL << CAN_F10R1_FB11_Pos)      /*!< 0x00000800 */
#define CAN_F10R1_FB11                       CAN_F10R1_FB11_Msk                /*!< Filter bit 11 */
#define CAN_F10R1_FB12_Pos                   (12U)
#define CAN_F10R1_FB12_Msk                   (0x1UL << CAN_F10R1_FB12_Pos)      /*!< 0x00001000 */
#define CAN_F10R1_FB12                       CAN_F10R1_FB12_Msk                /*!< Filter bit 12 */
#define CAN_F10R1_FB13_Pos                   (13U)
#define CAN_F10R1_FB13_Msk                   (0x1UL << CAN_F10R1_FB13_Pos)      /*!< 0x00002000 */
#define CAN_F10R1_FB13                       CAN_F10R1_FB13_Msk                /*!< Filter bit 13 */
#define CAN_F10R1_FB14_Pos                   (14U)
#define CAN_F10R1_FB14_Msk                   (0x1UL << CAN_F10R1_FB14_Pos)      /*!< 0x00004000 */
#define CAN_F10R1_FB14                       CAN_F10R1_FB14_Msk                /*!< Filter bit 14 */
#define CAN_F10R1_FB15_Pos                   (15U)
#define CAN_F10R1_FB15_Msk                   (0x1UL << CAN_F10R1_FB15_Pos)      /*!< 0x00008000 */
#define CAN_F10R1_FB15                       CAN_F10R1_FB15_Msk                /*!< Filter bit 15 */
#define CAN_F10R1_FB16_Pos                   (16U)
#define CAN_F10R1_FB16_Msk                   (0x1UL << CAN_F10R1_FB16_Pos)      /*!< 0x00010000 */
#define CAN_F10R1_FB16                       CAN_F10R1_FB16_Msk                /*!< Filter bit 16 */
#define CAN_F10R1_FB17_Pos                   (17U)
#define CAN_F10R1_FB17_Msk                   (0x1UL << CAN_F10R1_FB17_Pos)      /*!< 0x00020000 */
#define CAN_F10R1_FB17                       CAN_F10R1_FB17_Msk                /*!< Filter bit 17 */
#define CAN_F10R1_FB18_Pos                   (18U)
#define CAN_F10R1_FB18_Msk                   (0x1UL << CAN_F10R1_FB18_Pos)      /*!< 0x00040000 */
#define CAN_F10R1_FB18                       CAN_F10R1_FB18_Msk                /*!< Filter bit 18 */
#define CAN_F10R1_FB19_Pos                   (19U)
#define CAN_F10R1_FB19_Msk                   (0x1UL << CAN_F10R1_FB19_Pos)      /*!< 0x00080000 */
#define CAN_F10R1_FB19                       CAN_F10R1_FB19_Msk                /*!< Filter bit 19 */
#define CAN_F10R1_FB20_Pos                   (20U)
#define CAN_F10R1_FB20_Msk                   (0x1UL << CAN_F10R1_FB20_Pos)      /*!< 0x00100000 */
#define CAN_F10R1_FB20                       CAN_F10R1_FB20_Msk                /*!< Filter bit 20 */
#define CAN_F10R1_FB21_Pos                   (21U)
#define CAN_F10R1_FB21_Msk                   (0x1UL << CAN_F10R1_FB21_Pos)      /*!< 0x00200000 */
#define CAN_F10R1_FB21                       CAN_F10R1_FB21_Msk                /*!< Filter bit 21 */
#define CAN_F10R1_FB22_Pos                   (22U)
#define CAN_F10R1_FB22_Msk                   (0x1UL << CAN_F10R1_FB22_Pos)      /*!< 0x00400000 */
#define CAN_F10R1_FB22                       CAN_F10R1_FB22_Msk                /*!< Filter bit 22 */
#define CAN_F10R1_FB23_Pos                   (23U)
#define CAN_F10R1_FB23_Msk                   (0x1UL << CAN_F10R1_FB23_Pos)      /*!< 0x00800000 */
#define CAN_F10R1_FB23                       CAN_F10R1_FB23_Msk                /*!< Filter bit 23 */
#define CAN_F10R1_FB24_Pos                   (24U)
#define CAN_F10R1_FB24_Msk                   (0x1UL << CAN_F10R1_FB24_Pos)      /*!< 0x01000000 */
#define CAN_F10R1_FB24                       CAN_F10R1_FB24_Msk                /*!< Filter bit 24 */
#define CAN_F10R1_FB25_Pos                   (25U)
#define CAN_F10R1_FB25_Msk                   (0x1UL << CAN_F10R1_FB25_Pos)      /*!< 0x02000000 */
#define CAN_F10R1_FB25                       CAN_F10R1_FB25_Msk                /*!< Filter bit 25 */
#define CAN_F10R1_FB26_Pos                   (26U)
#define CAN_F10R1_FB26_Msk                   (0x1UL << CAN_F10R1_FB26_Pos)      /*!< 0x04000000 */
#define CAN_F10R1_FB26                       CAN_F10R1_FB26_Msk                /*!< Filter bit 26 */
#define CAN_F10R1_FB27_Pos                   (27U)
#define CAN_F10R1_FB27_Msk                   (0x1UL << CAN_F10R1_FB27_Pos)      /*!< 0x08000000 */
#define CAN_F10R1_FB27                       CAN_F10R1_FB27_Msk                /*!< Filter bit 27 */
#define CAN_F10R1_FB28_Pos                   (28U)
#define CAN_F10R1_FB28_Msk                   (0x1UL << CAN_F10R1_FB28_Pos)      /*!< 0x10000000 */
#define CAN_F10R1_FB28                       CAN_F10R1_FB28_Msk                /*!< Filter bit 28 */
#define CAN_F10R1_FB29_Pos                   (29U)
#define CAN_F10R1_FB29_Msk                   (0x1UL << CAN_F10R1_FB29_Pos)      /*!< 0x20000000 */
#define CAN_F10R1_FB29                       CAN_F10R1_FB29_Msk                /*!< Filter bit 29 */
#define CAN_F10R1_FB30_Pos                   (30U)
#define CAN_F10R1_FB30_Msk                   (0x1UL << CAN_F10R1_FB30_Pos)      /*!< 0x40000000 */
#define CAN_F10R1_FB30                       CAN_F10R1_FB30_Msk                /*!< Filter bit 30 */
#define CAN_F10R1_FB31_Pos                   (31U)
#define CAN_F10R1_FB31_Msk                   (0x1UL << CAN_F10R1_FB31_Pos)      /*!< 0x80000000 */
#define CAN_F10R1_FB31                       CAN_F10R1_FB31_Msk                /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F11R1 register  ******************/
#define CAN_F11R1_FB0_Pos                    (0U)
#define CAN_F11R1_FB0_Msk                    (0x1UL << CAN_F11R1_FB0_Pos)       /*!< 0x00000001 */
#define CAN_F11R1_FB0                        CAN_F11R1_FB0_Msk                 /*!< Filter bit 0 */
#define CAN_F11R1_FB1_Pos                    (1U)
#define CAN_F11R1_FB1_Msk                    (0x1UL << CAN_F11R1_FB1_Pos)       /*!< 0x00000002 */
#define CAN_F11R1_FB1                        CAN_F11R1_FB1_Msk                 /*!< Filter bit 1 */
#define CAN_F11R1_FB2_Pos                    (2U)
#define CAN_F11R1_FB2_Msk                    (0x1UL << CAN_F11R1_FB2_Pos)       /*!< 0x00000004 */
#define CAN_F11R1_FB2                        CAN_F11R1_FB2_Msk                 /*!< Filter bit 2 */
#define CAN_F11R1_FB3_Pos                    (3U)
#define CAN_F11R1_FB3_Msk                    (0x1UL << CAN_F11R1_FB3_Pos)       /*!< 0x00000008 */
#define CAN_F11R1_FB3                        CAN_F11R1_FB3_Msk                 /*!< Filter bit 3 */
#define CAN_F11R1_FB4_Pos                    (4U)
#define CAN_F11R1_FB4_Msk                    (0x1UL << CAN_F11R1_FB4_Pos)       /*!< 0x00000010 */
#define CAN_F11R1_FB4                        CAN_F11R1_FB4_Msk                 /*!< Filter bit 4 */
#define CAN_F11R1_FB5_Pos                    (5U)
#define CAN_F11R1_FB5_Msk                    (0x1UL << CAN_F11R1_FB5_Pos)       /*!< 0x00000020 */
#define CAN_F11R1_FB5                        CAN_F11R1_FB5_Msk                 /*!< Filter bit 5 */
#define CAN_F11R1_FB6_Pos                    (6U)
#define CAN_F11R1_FB6_Msk                    (0x1UL << CAN_F11R1_FB6_Pos)       /*!< 0x00000040 */
#define CAN_F11R1_FB6                        CAN_F11R1_FB6_Msk                 /*!< Filter bit 6 */
#define CAN_F11R1_FB7_Pos                    (7U)
#define CAN_F11R1_FB7_Msk                    (0x1UL << CAN_F11R1_FB7_Pos)       /*!< 0x00000080 */
#define CAN_F11R1_FB7                        CAN_F11R1_FB7_Msk                 /*!< Filter bit 7 */
#define CAN_F11R1_FB8_Pos                    (8U)
#define CAN_F11R1_FB8_Msk                    (0x1UL << CAN_F11R1_FB8_Pos)       /*!< 0x00000100 */
#define CAN_F11R1_FB8                        CAN_F11R1_FB8_Msk                 /*!< Filter bit 8 */
#define CAN_F11R1_FB9_Pos                    (9U)
#define CAN_F11R1_FB9_Msk                    (0x1UL << CAN_F11R1_FB9_Pos)       /*!< 0x00000200 */
#define CAN_F11R1_FB9                        CAN_F11R1_FB9_Msk                 /*!< Filter bit 9 */
#define CAN_F11R1_FB10_Pos                   (10U)
#define CAN_F11R1_FB10_Msk                   (0x1UL << CAN_F11R1_FB10_Pos)      /*!< 0x00000400 */
#define CAN_F11R1_FB10                       CAN_F11R1_FB10_Msk                /*!< Filter bit 10 */
#define CAN_F11R1_FB11_Pos                   (11U)
#define CAN_F11R1_FB11_Msk                   (0x1UL << CAN_F11R1_FB11_Pos)      /*!< 0x00000800 */
#define CAN_F11R1_FB11                       CAN_F11R1_FB11_Msk                /*!< Filter bit 11 */
#define CAN_F11R1_FB12_Pos                   (12U)
#define CAN_F11R1_FB12_Msk                   (0x1UL << CAN_F11R1_FB12_Pos)      /*!< 0x00001000 */
#define CAN_F11R1_FB12                       CAN_F11R1_FB12_Msk                /*!< Filter bit 12 */
#define CAN_F11R1_FB13_Pos                   (13U)
#define CAN_F11R1_FB13_Msk                   (0x1UL << CAN_F11R1_FB13_Pos)      /*!< 0x00002000 */
#define CAN_F11R1_FB13                       CAN_F11R1_FB13_Msk                /*!< Filter bit 13 */
#define CAN_F11R1_FB14_Pos                   (14U)
#define CAN_F11R1_FB14_Msk                   (0x1UL << CAN_F11R1_FB14_Pos)      /*!< 0x00004000 */
#define CAN_F11R1_FB14                       CAN_F11R1_FB14_Msk                /*!< Filter bit 14 */
#define CAN_F11R1_FB15_Pos                   (15U)
#define CAN_F11R1_FB15_Msk                   (0x1UL << CAN_F11R1_FB15_Pos)      /*!< 0x00008000 */
#define CAN_F11R1_FB15                       CAN_F11R1_FB15_Msk                /*!< Filter bit 15 */
#define CAN_F11R1_FB16_Pos                   (16U)
#define CAN_F11R1_FB16_Msk                   (0x1UL << CAN_F11R1_FB16_Pos)      /*!< 0x00010000 */
#define CAN_F11R1_FB16                       CAN_F11R1_FB16_Msk                /*!< Filter bit 16 */
#define CAN_F11R1_FB17_Pos                   (17U)
#define CAN_F11R1_FB17_Msk                   (0x1UL << CAN_F11R1_FB17_Pos)      /*!< 0x00020000 */
#define CAN_F11R1_FB17                       CAN_F11R1_FB17_Msk                /*!< Filter bit 17 */
#define CAN_F11R1_FB18_Pos                   (18U)
#define CAN_F11R1_FB18_Msk                   (0x1UL << CAN_F11R1_FB18_Pos)      /*!< 0x00040000 */
#define CAN_F11R1_FB18                       CAN_F11R1_FB18_Msk                /*!< Filter bit 18 */
#define CAN_F11R1_FB19_Pos                   (19U)
#define CAN_F11R1_FB19_Msk                   (0x1UL << CAN_F11R1_FB19_Pos)      /*!< 0x00080000 */
#define CAN_F11R1_FB19                       CAN_F11R1_FB19_Msk                /*!< Filter bit 19 */
#define CAN_F11R1_FB20_Pos                   (20U)
#define CAN_F11R1_FB20_Msk                   (0x1UL << CAN_F11R1_FB20_Pos)      /*!< 0x00100000 */
#define CAN_F11R1_FB20                       CAN_F11R1_FB20_Msk                /*!< Filter bit 20 */
#define CAN_F11R1_FB21_Pos                   (21U)
#define CAN_F11R1_FB21_Msk                   (0x1UL << CAN_F11R1_FB21_Pos)      /*!< 0x00200000 */
#define CAN_F11R1_FB21                       CAN_F11R1_FB21_Msk                /*!< Filter bit 21 */
#define CAN_F11R1_FB22_Pos                   (22U)
#define CAN_F11R1_FB22_Msk                   (0x1UL << CAN_F11R1_FB22_Pos)      /*!< 0x00400000 */
#define CAN_F11R1_FB22                       CAN_F11R1_FB22_Msk                /*!< Filter bit 22 */
#define CAN_F11R1_FB23_Pos                   (23U)
#define CAN_F11R1_FB23_Msk                   (0x1UL << CAN_F11R1_FB23_Pos)      /*!< 0x00800000 */
#define CAN_F11R1_FB23                       CAN_F11R1_FB23_Msk                /*!< Filter bit 23 */
#define CAN_F11R1_FB24_Pos                   (24U)
#define CAN_F11R1_FB24_Msk                   (0x1UL << CAN_F11R1_FB24_Pos)      /*!< 0x01000000 */
#define CAN_F11R1_FB24                       CAN_F11R1_FB24_Msk                /*!< Filter bit 24 */
#define CAN_F11R1_FB25_Pos                   (25U)
#define CAN_F11R1_FB25_Msk                   (0x1UL << CAN_F11R1_FB25_Pos)      /*!< 0x02000000 */
#define CAN_F11R1_FB25                       CAN_F11R1_FB25_Msk                /*!< Filter bit 25 */
#define CAN_F11R1_FB26_Pos                   (26U)
#define CAN_F11R1_FB26_Msk                   (0x1UL << CAN_F11R1_FB26_Pos)      /*!< 0x04000000 */
#define CAN_F11R1_FB26                       CAN_F11R1_FB26_Msk                /*!< Filter bit 26 */
#define CAN_F11R1_FB27_Pos                   (27U)
#define CAN_F11R1_FB27_Msk                   (0x1UL << CAN_F11R1_FB27_Pos)      /*!< 0x08000000 */
#define CAN_F11R1_FB27                       CAN_F11R1_FB27_Msk                /*!< Filter bit 27 */
#define CAN_F11R1_FB28_Pos                   (28U)
#define CAN_F11R1_FB28_Msk                   (0x1UL << CAN_F11R1_FB28_Pos)      /*!< 0x10000000 */
#define CAN_F11R1_FB28                       CAN_F11R1_FB28_Msk                /*!< Filter bit 28 */
#define CAN_F11R1_FB29_Pos                   (29U)
#define CAN_F11R1_FB29_Msk                   (0x1UL << CAN_F11R1_FB29_Pos)      /*!< 0x20000000 */
#define CAN_F11R1_FB29                       CAN_F11R1_FB29_Msk                /*!< Filter bit 29 */
#define CAN_F11R1_FB30_Pos                   (30U)
#define CAN_F11R1_FB30_Msk                   (0x1UL << CAN_F11R1_FB30_Pos)      /*!< 0x40000000 */
#define CAN_F11R1_FB30                       CAN_F11R1_FB30_Msk                /*!< Filter bit 30 */
#define CAN_F11R1_FB31_Pos                   (31U)
#define CAN_F11R1_FB31_Msk                   (0x1UL << CAN_F11R1_FB31_Pos)      /*!< 0x80000000 */
#define CAN_F11R1_FB31                       CAN_F11R1_FB31_Msk                /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F12R1 register  ******************/
#define CAN_F12R1_FB0_Pos                    (0U)
#define CAN_F12R1_FB0_Msk                    (0x1UL << CAN_F12R1_FB0_Pos)       /*!< 0x00000001 */
#define CAN_F12R1_FB0                        CAN_F12R1_FB0_Msk                 /*!< Filter bit 0 */
#define CAN_F12R1_FB1_Pos                    (1U)
#define CAN_F12R1_FB1_Msk                    (0x1UL << CAN_F12R1_FB1_Pos)       /*!< 0x00000002 */
#define CAN_F12R1_FB1                        CAN_F12R1_FB1_Msk                 /*!< Filter bit 1 */
#define CAN_F12R1_FB2_Pos                    (2U)
#define CAN_F12R1_FB2_Msk                    (0x1UL << CAN_F12R1_FB2_Pos)       /*!< 0x00000004 */
#define CAN_F12R1_FB2                        CAN_F12R1_FB2_Msk                 /*!< Filter bit 2 */
#define CAN_F12R1_FB3_Pos                    (3U)
#define CAN_F12R1_FB3_Msk                    (0x1UL << CAN_F12R1_FB3_Pos)       /*!< 0x00000008 */
#define CAN_F12R1_FB3                        CAN_F12R1_FB3_Msk                 /*!< Filter bit 3 */
#define CAN_F12R1_FB4_Pos                    (4U)
#define CAN_F12R1_FB4_Msk                    (0x1UL << CAN_F12R1_FB4_Pos)       /*!< 0x00000010 */
#define CAN_F12R1_FB4                        CAN_F12R1_FB4_Msk                 /*!< Filter bit 4 */
#define CAN_F12R1_FB5_Pos                    (5U)
#define CAN_F12R1_FB5_Msk                    (0x1UL << CAN_F12R1_FB5_Pos)       /*!< 0x00000020 */
#define CAN_F12R1_FB5                        CAN_F12R1_FB5_Msk                 /*!< Filter bit 5 */
#define CAN_F12R1_FB6_Pos                    (6U)
#define CAN_F12R1_FB6_Msk                    (0x1UL << CAN_F12R1_FB6_Pos)       /*!< 0x00000040 */
#define CAN_F12R1_FB6                        CAN_F12R1_FB6_Msk                 /*!< Filter bit 6 */
#define CAN_F12R1_FB7_Pos                    (7U)
#define CAN_F12R1_FB7_Msk                    (0x1UL << CAN_F12R1_FB7_Pos)       /*!< 0x00000080 */
#define CAN_F12R1_FB7                        CAN_F12R1_FB7_Msk                 /*!< Filter bit 7 */
#define CAN_F12R1_FB8_Pos                    (8U)
#define CAN_F12R1_FB8_Msk                    (0x1UL << CAN_F12R1_FB8_Pos)       /*!< 0x00000100 */
#define CAN_F12R1_FB8                        CAN_F12R1_FB8_Msk                 /*!< Filter bit 8 */
#define CAN_F12R1_FB9_Pos                    (9U)
#define CAN_F12R1_FB9_Msk                    (0x1UL << CAN_F12R1_FB9_Pos)       /*!< 0x00000200 */
#define CAN_F12R1_FB9                        CAN_F12R1_FB9_Msk                 /*!< Filter bit 9 */
#define CAN_F12R1_FB10_Pos                   (10U)
#define CAN_F12R1_FB10_Msk                   (0x1UL << CAN_F12R1_FB10_Pos)      /*!< 0x00000400 */
#define CAN_F12R1_FB10                       CAN_F12R1_FB10_Msk                /*!< Filter bit 10 */
#define CAN_F12R1_FB11_Pos                   (11U)
#define CAN_F12R1_FB11_Msk                   (0x1UL << CAN_F12R1_FB11_Pos)      /*!< 0x00000800 */
#define CAN_F12R1_FB11                       CAN_F12R1_FB11_Msk                /*!< Filter bit 11 */
#define CAN_F12R1_FB12_Pos                   (12U)
#define CAN_F12R1_FB12_Msk                   (0x1UL << CAN_F12R1_FB12_Pos)      /*!< 0x00001000 */
#define CAN_F12R1_FB12                       CAN_F12R1_FB12_Msk                /*!< Filter bit 12 */
#define CAN_F12R1_FB13_Pos                   (13U)
#define CAN_F12R1_FB13_Msk                   (0x1UL << CAN_F12R1_FB13_Pos)      /*!< 0x00002000 */
#define CAN_F12R1_FB13                       CAN_F12R1_FB13_Msk                /*!< Filter bit 13 */
#define CAN_F12R1_FB14_Pos                   (14U)
#define CAN_F12R1_FB14_Msk                   (0x1UL << CAN_F12R1_FB14_Pos)      /*!< 0x00004000 */
#define CAN_F12R1_FB14                       CAN_F12R1_FB14_Msk                /*!< Filter bit 14 */
#define CAN_F12R1_FB15_Pos                   (15U)
#define CAN_F12R1_FB15_Msk                   (0x1UL << CAN_F12R1_FB15_Pos)      /*!< 0x00008000 */
#define CAN_F12R1_FB15                       CAN_F12R1_FB15_Msk                /*!< Filter bit 15 */
#define CAN_F12R1_FB16_Pos                   (16U)
#define CAN_F12R1_FB16_Msk                   (0x1UL << CAN_F12R1_FB16_Pos)      /*!< 0x00010000 */
#define CAN_F12R1_FB16                       CAN_F12R1_FB16_Msk                /*!< Filter bit 16 */
#define CAN_F12R1_FB17_Pos                   (17U)
#define CAN_F12R1_FB17_Msk                   (0x1UL << CAN_F12R1_FB17_Pos)      /*!< 0x00020000 */
#define CAN_F12R1_FB17                       CAN_F12R1_FB17_Msk                /*!< Filter bit 17 */
#define CAN_F12R1_FB18_Pos                   (18U)
#define CAN_F12R1_FB18_Msk                   (0x1UL << CAN_F12R1_FB18_Pos)      /*!< 0x00040000 */
#define CAN_F12R1_FB18                       CAN_F12R1_FB18_Msk                /*!< Filter bit 18 */
#define CAN_F12R1_FB19_Pos                   (19U)
#define CAN_F12R1_FB19_Msk                   (0x1UL << CAN_F12R1_FB19_Pos)      /*!< 0x00080000 */
#define CAN_F12R1_FB19                       CAN_F12R1_FB19_Msk                /*!< Filter bit 19 */
#define CAN_F12R1_FB20_Pos                   (20U)
#define CAN_F12R1_FB20_Msk                   (0x1UL << CAN_F12R1_FB20_Pos)      /*!< 0x00100000 */
#define CAN_F12R1_FB20                       CAN_F12R1_FB20_Msk                /*!< Filter bit 20 */
#define CAN_F12R1_FB21_Pos                   (21U)
#define CAN_F12R1_FB21_Msk                   (0x1UL << CAN_F12R1_FB21_Pos)      /*!< 0x00200000 */
#define CAN_F12R1_FB21                       CAN_F12R1_FB21_Msk                /*!< Filter bit 21 */
#define CAN_F12R1_FB22_Pos                   (22U)
#define CAN_F12R1_FB22_Msk                   (0x1UL << CAN_F12R1_FB22_Pos)      /*!< 0x00400000 */
#define CAN_F12R1_FB22                       CAN_F12R1_FB22_Msk                /*!< Filter bit 22 */
#define CAN_F12R1_FB23_Pos                   (23U)
#define CAN_F12R1_FB23_Msk                   (0x1UL << CAN_F12R1_FB23_Pos)      /*!< 0x00800000 */
#define CAN_F12R1_FB23                       CAN_F12R1_FB23_Msk                /*!< Filter bit 23 */
#define CAN_F12R1_FB24_Pos                   (24U)
#define CAN_F12R1_FB24_Msk                   (0x1UL << CAN_F12R1_FB24_Pos)      /*!< 0x01000000 */
#define CAN_F12R1_FB24                       CAN_F12R1_FB24_Msk                /*!< Filter bit 24 */
#define CAN_F12R1_FB25_Pos                   (25U)
#define CAN_F12R1_FB25_Msk                   (0x1UL << CAN_F12R1_FB25_Pos)      /*!< 0x02000000 */
#define CAN_F12R1_FB25                       CAN_F12R1_FB25_Msk                /*!< Filter bit 25 */
#define CAN_F12R1_FB26_Pos                   (26U)
#define CAN_F12R1_FB26_Msk                   (0x1UL << CAN_F12R1_FB26_Pos)      /*!< 0x04000000 */
#define CAN_F12R1_FB26                       CAN_F12R1_FB26_Msk                /*!< Filter bit 26 */
#define CAN_F12R1_FB27_Pos                   (27U)
#define CAN_F12R1_FB27_Msk                   (0x1UL << CAN_F12R1_FB27_Pos)      /*!< 0x08000000 */
#define CAN_F12R1_FB27                       CAN_F12R1_FB27_Msk                /*!< Filter bit 27 */
#define CAN_F12R1_FB28_Pos                   (28U)
#define CAN_F12R1_FB28_Msk                   (0x1UL << CAN_F12R1_FB28_Pos)      /*!< 0x10000000 */
#define CAN_F12R1_FB28                       CAN_F12R1_FB28_Msk                /*!< Filter bit 28 */
#define CAN_F12R1_FB29_Pos                   (29U)
#define CAN_F12R1_FB29_Msk                   (0x1UL << CAN_F12R1_FB29_Pos)      /*!< 0x20000000 */
#define CAN_F12R1_FB29                       CAN_F12R1_FB29_Msk                /*!< Filter bit 29 */
#define CAN_F12R1_FB30_Pos                   (30U)
#define CAN_F12R1_FB30_Msk                   (0x1UL << CAN_F12R1_FB30_Pos)      /*!< 0x40000000 */
#define CAN_F12R1_FB30                       CAN_F12R1_FB30_Msk                /*!< Filter bit 30 */
#define CAN_F12R1_FB31_Pos                   (31U)
#define CAN_F12R1_FB31_Msk                   (0x1UL << CAN_F12R1_FB31_Pos)      /*!< 0x80000000 */
#define CAN_F12R1_FB31                       CAN_F12R1_FB31_Msk                /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F13R1 register  ******************/
#define CAN_F13R1_FB0_Pos                    (0U)
#define CAN_F13R1_FB0_Msk                    (0x1UL << CAN_F13R1_FB0_Pos)       /*!< 0x00000001 */
#define CAN_F13R1_FB0                        CAN_F13R1_FB0_Msk                 /*!< Filter bit 0 */
#define CAN_F13R1_FB1_Pos                    (1U)
#define CAN_F13R1_FB1_Msk                    (0x1UL << CAN_F13R1_FB1_Pos)       /*!< 0x00000002 */
#define CAN_F13R1_FB1                        CAN_F13R1_FB1_Msk                 /*!< Filter bit 1 */
#define CAN_F13R1_FB2_Pos                    (2U)
#define CAN_F13R1_FB2_Msk                    (0x1UL << CAN_F13R1_FB2_Pos)       /*!< 0x00000004 */
#define CAN_F13R1_FB2                        CAN_F13R1_FB2_Msk                 /*!< Filter bit 2 */
#define CAN_F13R1_FB3_Pos                    (3U)
#define CAN_F13R1_FB3_Msk                    (0x1UL << CAN_F13R1_FB3_Pos)       /*!< 0x00000008 */
#define CAN_F13R1_FB3                        CAN_F13R1_FB3_Msk                 /*!< Filter bit 3 */
#define CAN_F13R1_FB4_Pos                    (4U)
#define CAN_F13R1_FB4_Msk                    (0x1UL << CAN_F13R1_FB4_Pos)       /*!< 0x00000010 */
#define CAN_F13R1_FB4                        CAN_F13R1_FB4_Msk                 /*!< Filter bit 4 */
#define CAN_F13R1_FB5_Pos                    (5U)
#define CAN_F13R1_FB5_Msk                    (0x1UL << CAN_F13R1_FB5_Pos)       /*!< 0x00000020 */
#define CAN_F13R1_FB5                        CAN_F13R1_FB5_Msk                 /*!< Filter bit 5 */
#define CAN_F13R1_FB6_Pos                    (6U)
#define CAN_F13R1_FB6_Msk                    (0x1UL << CAN_F13R1_FB6_Pos)       /*!< 0x00000040 */
#define CAN_F13R1_FB6                        CAN_F13R1_FB6_Msk                 /*!< Filter bit 6 */
#define CAN_F13R1_FB7_Pos                    (7U)
#define CAN_F13R1_FB7_Msk                    (0x1UL << CAN_F13R1_FB7_Pos)       /*!< 0x00000080 */
#define CAN_F13R1_FB7                        CAN_F13R1_FB7_Msk                 /*!< Filter bit 7 */
#define CAN_F13R1_FB8_Pos                    (8U)
#define CAN_F13R1_FB8_Msk                    (0x1UL << CAN_F13R1_FB8_Pos)       /*!< 0x00000100 */
#define CAN_F13R1_FB8                        CAN_F13R1_FB8_Msk                 /*!< Filter bit 8 */
#define CAN_F13R1_FB9_Pos                    (9U)
#define CAN_F13R1_FB9_Msk                    (0x1UL << CAN_F13R1_FB9_Pos)       /*!< 0x00000200 */
#define CAN_F13R1_FB9                        CAN_F13R1_FB9_Msk                 /*!< Filter bit 9 */
#define CAN_F13R1_FB10_Pos                   (10U)
#define CAN_F13R1_FB10_Msk                   (0x1UL << CAN_F13R1_FB10_Pos)      /*!< 0x00000400 */
#define CAN_F13R1_FB10                       CAN_F13R1_FB10_Msk                /*!< Filter bit 10 */
#define CAN_F13R1_FB11_Pos                   (11U)
#define CAN_F13R1_FB11_Msk                   (0x1UL << CAN_F13R1_FB11_Pos)      /*!< 0x00000800 */
#define CAN_F13R1_FB11                       CAN_F13R1_FB11_Msk                /*!< Filter bit 11 */
#define CAN_F13R1_FB12_Pos                   (12U)
#define CAN_F13R1_FB12_Msk                   (0x1UL << CAN_F13R1_FB12_Pos)      /*!< 0x00001000 */
#define CAN_F13R1_FB12                       CAN_F13R1_FB12_Msk                /*!< Filter bit 12 */
#define CAN_F13R1_FB13_Pos                   (13U)
#define CAN_F13R1_FB13_Msk                   (0x1UL << CAN_F13R1_FB13_Pos)      /*!< 0x00002000 */
#define CAN_F13R1_FB13                       CAN_F13R1_FB13_Msk                /*!< Filter bit 13 */
#define CAN_F13R1_FB14_Pos                   (14U)
#define CAN_F13R1_FB14_Msk                   (0x1UL << CAN_F13R1_FB14_Pos)      /*!< 0x00004000 */
#define CAN_F13R1_FB14                       CAN_F13R1_FB14_Msk                /*!< Filter bit 14 */
#define CAN_F13R1_FB15_Pos                   (15U)
#define CAN_F13R1_FB15_Msk                   (0x1UL << CAN_F13R1_FB15_Pos)      /*!< 0x00008000 */
#define CAN_F13R1_FB15                       CAN_F13R1_FB15_Msk                /*!< Filter bit 15 */
#define CAN_F13R1_FB16_Pos                   (16U)
#define CAN_F13R1_FB16_Msk                   (0x1UL << CAN_F13R1_FB16_Pos)      /*!< 0x00010000 */
#define CAN_F13R1_FB16                       CAN_F13R1_FB16_Msk                /*!< Filter bit 16 */
#define CAN_F13R1_FB17_Pos                   (17U)
#define CAN_F13R1_FB17_Msk                   (0x1UL << CAN_F13R1_FB17_Pos)      /*!< 0x00020000 */
#define CAN_F13R1_FB17                       CAN_F13R1_FB17_Msk                /*!< Filter bit 17 */
#define CAN_F13R1_FB18_Pos                   (18U)
#define CAN_F13R1_FB18_Msk                   (0x1UL << CAN_F13R1_FB18_Pos)      /*!< 0x00040000 */
#define CAN_F13R1_FB18                       CAN_F13R1_FB18_Msk                /*!< Filter bit 18 */
#define CAN_F13R1_FB19_Pos                   (19U)
#define CAN_F13R1_FB19_Msk                   (0x1UL << CAN_F13R1_FB19_Pos)      /*!< 0x00080000 */
#define CAN_F13R1_FB19                       CAN_F13R1_FB19_Msk                /*!< Filter bit 19 */
#define CAN_F13R1_FB20_Pos                   (20U)
#define CAN_F13R1_FB20_Msk                   (0x1UL << CAN_F13R1_FB20_Pos)      /*!< 0x00100000 */
#define CAN_F13R1_FB20                       CAN_F13R1_FB20_Msk                /*!< Filter bit 20 */
#define CAN_F13R1_FB21_Pos                   (21U)
#define CAN_F13R1_FB21_Msk                   (0x1UL << CAN_F13R1_FB21_Pos)      /*!< 0x00200000 */
#define CAN_F13R1_FB21                       CAN_F13R1_FB21_Msk                /*!< Filter bit 21 */
#define CAN_F13R1_FB22_Pos                   (22U)
#define CAN_F13R1_FB22_Msk                   (0x1UL << CAN_F13R1_FB22_Pos)      /*!< 0x00400000 */
#define CAN_F13R1_FB22                       CAN_F13R1_FB22_Msk                /*!< Filter bit 22 */
#define CAN_F13R1_FB23_Pos                   (23U)
#define CAN_F13R1_FB23_Msk                   (0x1UL << CAN_F13R1_FB23_Pos)      /*!< 0x00800000 */
#define CAN_F13R1_FB23                       CAN_F13R1_FB23_Msk                /*!< Filter bit 23 */
#define CAN_F13R1_FB24_Pos                   (24U)
#define CAN_F13R1_FB24_Msk                   (0x1UL << CAN_F13R1_FB24_Pos)      /*!< 0x01000000 */
#define CAN_F13R1_FB24                       CAN_F13R1_FB24_Msk                /*!< Filter bit 24 */
#define CAN_F13R1_FB25_Pos                   (25U)
#define CAN_F13R1_FB25_Msk                   (0x1UL << CAN_F13R1_FB25_Pos)      /*!< 0x02000000 */
#define CAN_F13R1_FB25                       CAN_F13R1_FB25_Msk                /*!< Filter bit 25 */
#define CAN_F13R1_FB26_Pos                   (26U)
#define CAN_F13R1_FB26_Msk                   (0x1UL << CAN_F13R1_FB26_Pos)      /*!< 0x04000000 */
#define CAN_F13R1_FB26                       CAN_F13R1_FB26_Msk                /*!< Filter bit 26 */
#define CAN_F13R1_FB27_Pos                   (27U)
#define CAN_F13R1_FB27_Msk                   (0x1UL << CAN_F13R1_FB27_Pos)      /*!< 0x08000000 */
#define CAN_F13R1_FB27                       CAN_F13R1_FB27_Msk                /*!< Filter bit 27 */
#define CAN_F13R1_FB28_Pos                   (28U)
#define CAN_F13R1_FB28_Msk                   (0x1UL << CAN_F13R1_FB28_Pos)      /*!< 0x10000000 */
#define CAN_F13R1_FB28                       CAN_F13R1_FB28_Msk                /*!< Filter bit 28 */
#define CAN_F13R1_FB29_Pos                   (29U)
#define CAN_F13R1_FB29_Msk                   (0x1UL << CAN_F13R1_FB29_Pos)      /*!< 0x20000000 */
#define CAN_F13R1_FB29                       CAN_F13R1_FB29_Msk                /*!< Filter bit 29 */
#define CAN_F13R1_FB30_Pos                   (30U)
#define CAN_F13R1_FB30_Msk                   (0x1UL << CAN_F13R1_FB30_Pos)      /*!< 0x40000000 */
#define CAN_F13R1_FB30                       CAN_F13R1_FB30_Msk                /*!< Filter bit 30 */
#define CAN_F13R1_FB31_Pos                   (31U)
#define CAN_F13R1_FB31_Msk                   (0x1UL << CAN_F13R1_FB31_Pos)      /*!< 0x80000000 */
#define CAN_F13R1_FB31                       CAN_F13R1_FB31_Msk                /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F0R2 register  *******************/
#define CAN_F0R2_FB0_Pos                     (0U)
#define CAN_F0R2_FB0_Msk                     (0x1UL << CAN_F0R2_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F0R2_FB0                         CAN_F0R2_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F0R2_FB1_Pos                     (1U)
#define CAN_F0R2_FB1_Msk                     (0x1UL << CAN_F0R2_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F0R2_FB1                         CAN_F0R2_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F0R2_FB2_Pos                     (2U)
#define CAN_F0R2_FB2_Msk                     (0x1UL << CAN_F0R2_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F0R2_FB2                         CAN_F0R2_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F0R2_FB3_Pos                     (3U)
#define CAN_F0R2_FB3_Msk                     (0x1UL << CAN_F0R2_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F0R2_FB3                         CAN_F0R2_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F0R2_FB4_Pos                     (4U)
#define CAN_F0R2_FB4_Msk                     (0x1UL << CAN_F0R2_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F0R2_FB4                         CAN_F0R2_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F0R2_FB5_Pos                     (5U)
#define CAN_F0R2_FB5_Msk                     (0x1UL << CAN_F0R2_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F0R2_FB5                         CAN_F0R2_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F0R2_FB6_Pos                     (6U)
#define CAN_F0R2_FB6_Msk                     (0x1UL << CAN_F0R2_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F0R2_FB6                         CAN_F0R2_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F0R2_FB7_Pos                     (7U)
#define CAN_F0R2_FB7_Msk                     (0x1UL << CAN_F0R2_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F0R2_FB7                         CAN_F0R2_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F0R2_FB8_Pos                     (8U)
#define CAN_F0R2_FB8_Msk                     (0x1UL << CAN_F0R2_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F0R2_FB8                         CAN_F0R2_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F0R2_FB9_Pos                     (9U)
#define CAN_F0R2_FB9_Msk                     (0x1UL << CAN_F0R2_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F0R2_FB9                         CAN_F0R2_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F0R2_FB10_Pos                    (10U)
#define CAN_F0R2_FB10_Msk                    (0x1UL << CAN_F0R2_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F0R2_FB10                        CAN_F0R2_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F0R2_FB11_Pos                    (11U)
#define CAN_F0R2_FB11_Msk                    (0x1UL << CAN_F0R2_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F0R2_FB11                        CAN_F0R2_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F0R2_FB12_Pos                    (12U)
#define CAN_F0R2_FB12_Msk                    (0x1UL << CAN_F0R2_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F0R2_FB12                        CAN_F0R2_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F0R2_FB13_Pos                    (13U)
#define CAN_F0R2_FB13_Msk                    (0x1UL << CAN_F0R2_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F0R2_FB13                        CAN_F0R2_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F0R2_FB14_Pos                    (14U)
#define CAN_F0R2_FB14_Msk                    (0x1UL << CAN_F0R2_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F0R2_FB14                        CAN_F0R2_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F0R2_FB15_Pos                    (15U)
#define CAN_F0R2_FB15_Msk                    (0x1UL << CAN_F0R2_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F0R2_FB15                        CAN_F0R2_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F0R2_FB16_Pos                    (16U)
#define CAN_F0R2_FB16_Msk                    (0x1UL << CAN_F0R2_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F0R2_FB16                        CAN_F0R2_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F0R2_FB17_Pos                    (17U)
#define CAN_F0R2_FB17_Msk                    (0x1UL << CAN_F0R2_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F0R2_FB17                        CAN_F0R2_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F0R2_FB18_Pos                    (18U)
#define CAN_F0R2_FB18_Msk                    (0x1UL << CAN_F0R2_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F0R2_FB18                        CAN_F0R2_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F0R2_FB19_Pos                    (19U)
#define CAN_F0R2_FB19_Msk                    (0x1UL << CAN_F0R2_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F0R2_FB19                        CAN_F0R2_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F0R2_FB20_Pos                    (20U)
#define CAN_F0R2_FB20_Msk                    (0x1UL << CAN_F0R2_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F0R2_FB20                        CAN_F0R2_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F0R2_FB21_Pos                    (21U)
#define CAN_F0R2_FB21_Msk                    (0x1UL << CAN_F0R2_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F0R2_FB21                        CAN_F0R2_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F0R2_FB22_Pos                    (22U)
#define CAN_F0R2_FB22_Msk                    (0x1UL << CAN_F0R2_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F0R2_FB22                        CAN_F0R2_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F0R2_FB23_Pos                    (23U)
#define CAN_F0R2_FB23_Msk                    (0x1UL << CAN_F0R2_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F0R2_FB23                        CAN_F0R2_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F0R2_FB24_Pos                    (24U)
#define CAN_F0R2_FB24_Msk                    (0x1UL << CAN_F0R2_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F0R2_FB24                        CAN_F0R2_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F0R2_FB25_Pos                    (25U)
#define CAN_F0R2_FB25_Msk                    (0x1UL << CAN_F0R2_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F0R2_FB25                        CAN_F0R2_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F0R2_FB26_Pos                    (26U)
#define CAN_F0R2_FB26_Msk                    (0x1UL << CAN_F0R2_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F0R2_FB26                        CAN_F0R2_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F0R2_FB27_Pos                    (27U)
#define CAN_F0R2_FB27_Msk                    (0x1UL << CAN_F0R2_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F0R2_FB27                        CAN_F0R2_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F0R2_FB28_Pos                    (28U)
#define CAN_F0R2_FB28_Msk                    (0x1UL << CAN_F0R2_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F0R2_FB28                        CAN_F0R2_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F0R2_FB29_Pos                    (29U)
#define CAN_F0R2_FB29_Msk                    (0x1UL << CAN_F0R2_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F0R2_FB29                        CAN_F0R2_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F0R2_FB30_Pos                    (30U)
#define CAN_F0R2_FB30_Msk                    (0x1UL << CAN_F0R2_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F0R2_FB30                        CAN_F0R2_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F0R2_FB31_Pos                    (31U)
#define CAN_F0R2_FB31_Msk                    (0x1UL << CAN_F0R2_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F0R2_FB31                        CAN_F0R2_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F1R2 register  *******************/
#define CAN_F1R2_FB0_Pos                     (0U)
#define CAN_F1R2_FB0_Msk                     (0x1UL << CAN_F1R2_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F1R2_FB0                         CAN_F1R2_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F1R2_FB1_Pos                     (1U)
#define CAN_F1R2_FB1_Msk                     (0x1UL << CAN_F1R2_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F1R2_FB1                         CAN_F1R2_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F1R2_FB2_Pos                     (2U)
#define CAN_F1R2_FB2_Msk                     (0x1UL << CAN_F1R2_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F1R2_FB2                         CAN_F1R2_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F1R2_FB3_Pos                     (3U)
#define CAN_F1R2_FB3_Msk                     (0x1UL << CAN_F1R2_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F1R2_FB3                         CAN_F1R2_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F1R2_FB4_Pos                     (4U)
#define CAN_F1R2_FB4_Msk                     (0x1UL << CAN_F1R2_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F1R2_FB4                         CAN_F1R2_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F1R2_FB5_Pos                     (5U)
#define CAN_F1R2_FB5_Msk                     (0x1UL << CAN_F1R2_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F1R2_FB5                         CAN_F1R2_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F1R2_FB6_Pos                     (6U)
#define CAN_F1R2_FB6_Msk                     (0x1UL << CAN_F1R2_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F1R2_FB6                         CAN_F1R2_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F1R2_FB7_Pos                     (7U)
#define CAN_F1R2_FB7_Msk                     (0x1UL << CAN_F1R2_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F1R2_FB7                         CAN_F1R2_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F1R2_FB8_Pos                     (8U)
#define CAN_F1R2_FB8_Msk                     (0x1UL << CAN_F1R2_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F1R2_FB8                         CAN_F1R2_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F1R2_FB9_Pos                     (9U)
#define CAN_F1R2_FB9_Msk                     (0x1UL << CAN_F1R2_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F1R2_FB9                         CAN_F1R2_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F1R2_FB10_Pos                    (10U)
#define CAN_F1R2_FB10_Msk                    (0x1UL << CAN_F1R2_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F1R2_FB10                        CAN_F1R2_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F1R2_FB11_Pos                    (11U)
#define CAN_F1R2_FB11_Msk                    (0x1UL << CAN_F1R2_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F1R2_FB11                        CAN_F1R2_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F1R2_FB12_Pos                    (12U)
#define CAN_F1R2_FB12_Msk                    (0x1UL << CAN_F1R2_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F1R2_FB12                        CAN_F1R2_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F1R2_FB13_Pos                    (13U)
#define CAN_F1R2_FB13_Msk                    (0x1UL << CAN_F1R2_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F1R2_FB13                        CAN_F1R2_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F1R2_FB14_Pos                    (14U)
#define CAN_F1R2_FB14_Msk                    (0x1UL << CAN_F1R2_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F1R2_FB14                        CAN_F1R2_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F1R2_FB15_Pos                    (15U)
#define CAN_F1R2_FB15_Msk                    (0x1UL << CAN_F1R2_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F1R2_FB15                        CAN_F1R2_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F1R2_FB16_Pos                    (16U)
#define CAN_F1R2_FB16_Msk                    (0x1UL << CAN_F1R2_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F1R2_FB16                        CAN_F1R2_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F1R2_FB17_Pos                    (17U)
#define CAN_F1R2_FB17_Msk                    (0x1UL << CAN_F1R2_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F1R2_FB17                        CAN_F1R2_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F1R2_FB18_Pos                    (18U)
#define CAN_F1R2_FB18_Msk                    (0x1UL << CAN_F1R2_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F1R2_FB18                        CAN_F1R2_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F1R2_FB19_Pos                    (19U)
#define CAN_F1R2_FB19_Msk                    (0x1UL << CAN_F1R2_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F1R2_FB19                        CAN_F1R2_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F1R2_FB20_Pos                    (20U)
#define CAN_F1R2_FB20_Msk                    (0x1UL << CAN_F1R2_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F1R2_FB20                        CAN_F1R2_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F1R2_FB21_Pos                    (21U)
#define CAN_F1R2_FB21_Msk                    (0x1UL << CAN_F1R2_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F1R2_FB21                        CAN_F1R2_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F1R2_FB22_Pos                    (22U)
#define CAN_F1R2_FB22_Msk                    (0x1UL << CAN_F1R2_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F1R2_FB22                        CAN_F1R2_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F1R2_FB23_Pos                    (23U)
#define CAN_F1R2_FB23_Msk                    (0x1UL << CAN_F1R2_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F1R2_FB23                        CAN_F1R2_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F1R2_FB24_Pos                    (24U)
#define CAN_F1R2_FB24_Msk                    (0x1UL << CAN_F1R2_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F1R2_FB24                        CAN_F1R2_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F1R2_FB25_Pos                    (25U)
#define CAN_F1R2_FB25_Msk                    (0x1UL << CAN_F1R2_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F1R2_FB25                        CAN_F1R2_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F1R2_FB26_Pos                    (26U)
#define CAN_F1R2_FB26_Msk                    (0x1UL << CAN_F1R2_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F1R2_FB26                        CAN_F1R2_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F1R2_FB27_Pos                    (27U)
#define CAN_F1R2_FB27_Msk                    (0x1UL << CAN_F1R2_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F1R2_FB27                        CAN_F1R2_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F1R2_FB28_Pos                    (28U)
#define CAN_F1R2_FB28_Msk                    (0x1UL << CAN_F1R2_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F1R2_FB28                        CAN_F1R2_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F1R2_FB29_Pos                    (29U)
#define CAN_F1R2_FB29_Msk                    (0x1UL << CAN_F1R2_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F1R2_FB29                        CAN_F1R2_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F1R2_FB30_Pos                    (30U)
#define CAN_F1R2_FB30_Msk                    (0x1UL << CAN_F1R2_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F1R2_FB30                        CAN_F1R2_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F1R2_FB31_Pos                    (31U)
#define CAN_F1R2_FB31_Msk                    (0x1UL << CAN_F1R2_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F1R2_FB31                        CAN_F1R2_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F2R2 register  *******************/
#define CAN_F2R2_FB0_Pos                     (0U)
#define CAN_F2R2_FB0_Msk                     (0x1UL << CAN_F2R2_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F2R2_FB0                         CAN_F2R2_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F2R2_FB1_Pos                     (1U)
#define CAN_F2R2_FB1_Msk                     (0x1UL << CAN_F2R2_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F2R2_FB1                         CAN_F2R2_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F2R2_FB2_Pos                     (2U)
#define CAN_F2R2_FB2_Msk                     (0x1UL << CAN_F2R2_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F2R2_FB2                         CAN_F2R2_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F2R2_FB3_Pos                     (3U)
#define CAN_F2R2_FB3_Msk                     (0x1UL << CAN_F2R2_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F2R2_FB3                         CAN_F2R2_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F2R2_FB4_Pos                     (4U)
#define CAN_F2R2_FB4_Msk                     (0x1UL << CAN_F2R2_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F2R2_FB4                         CAN_F2R2_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F2R2_FB5_Pos                     (5U)
#define CAN_F2R2_FB5_Msk                     (0x1UL << CAN_F2R2_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F2R2_FB5                         CAN_F2R2_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F2R2_FB6_Pos                     (6U)
#define CAN_F2R2_FB6_Msk                     (0x1UL << CAN_F2R2_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F2R2_FB6                         CAN_F2R2_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F2R2_FB7_Pos                     (7U)
#define CAN_F2R2_FB7_Msk                     (0x1UL << CAN_F2R2_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F2R2_FB7                         CAN_F2R2_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F2R2_FB8_Pos                     (8U)
#define CAN_F2R2_FB8_Msk                     (0x1UL << CAN_F2R2_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F2R2_FB8                         CAN_F2R2_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F2R2_FB9_Pos                     (9U)
#define CAN_F2R2_FB9_Msk                     (0x1UL << CAN_F2R2_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F2R2_FB9                         CAN_F2R2_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F2R2_FB10_Pos                    (10U)
#define CAN_F2R2_FB10_Msk                    (0x1UL << CAN_F2R2_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F2R2_FB10                        CAN_F2R2_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F2R2_FB11_Pos                    (11U)
#define CAN_F2R2_FB11_Msk                    (0x1UL << CAN_F2R2_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F2R2_FB11                        CAN_F2R2_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F2R2_FB12_Pos                    (12U)
#define CAN_F2R2_FB12_Msk                    (0x1UL << CAN_F2R2_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F2R2_FB12                        CAN_F2R2_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F2R2_FB13_Pos                    (13U)
#define CAN_F2R2_FB13_Msk                    (0x1UL << CAN_F2R2_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F2R2_FB13                        CAN_F2R2_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F2R2_FB14_Pos                    (14U)
#define CAN_F2R2_FB14_Msk                    (0x1UL << CAN_F2R2_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F2R2_FB14                        CAN_F2R2_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F2R2_FB15_Pos                    (15U)
#define CAN_F2R2_FB15_Msk                    (0x1UL << CAN_F2R2_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F2R2_FB15                        CAN_F2R2_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F2R2_FB16_Pos                    (16U)
#define CAN_F2R2_FB16_Msk                    (0x1UL << CAN_F2R2_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F2R2_FB16                        CAN_F2R2_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F2R2_FB17_Pos                    (17U)
#define CAN_F2R2_FB17_Msk                    (0x1UL << CAN_F2R2_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F2R2_FB17                        CAN_F2R2_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F2R2_FB18_Pos                    (18U)
#define CAN_F2R2_FB18_Msk                    (0x1UL << CAN_F2R2_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F2R2_FB18                        CAN_F2R2_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F2R2_FB19_Pos                    (19U)
#define CAN_F2R2_FB19_Msk                    (0x1UL << CAN_F2R2_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F2R2_FB19                        CAN_F2R2_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F2R2_FB20_Pos                    (20U)
#define CAN_F2R2_FB20_Msk                    (0x1UL << CAN_F2R2_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F2R2_FB20                        CAN_F2R2_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F2R2_FB21_Pos                    (21U)
#define CAN_F2R2_FB21_Msk                    (0x1UL << CAN_F2R2_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F2R2_FB21                        CAN_F2R2_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F2R2_FB22_Pos                    (22U)
#define CAN_F2R2_FB22_Msk                    (0x1UL << CAN_F2R2_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F2R2_FB22                        CAN_F2R2_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F2R2_FB23_Pos                    (23U)
#define CAN_F2R2_FB23_Msk                    (0x1UL << CAN_F2R2_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F2R2_FB23                        CAN_F2R2_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F2R2_FB24_Pos                    (24U)
#define CAN_F2R2_FB24_Msk                    (0x1UL << CAN_F2R2_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F2R2_FB24                        CAN_F2R2_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F2R2_FB25_Pos                    (25U)
#define CAN_F2R2_FB25_Msk                    (0x1UL << CAN_F2R2_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F2R2_FB25                        CAN_F2R2_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F2R2_FB26_Pos                    (26U)
#define CAN_F2R2_FB26_Msk                    (0x1UL << CAN_F2R2_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F2R2_FB26                        CAN_F2R2_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F2R2_FB27_Pos                    (27U)
#define CAN_F2R2_FB27_Msk                    (0x1UL << CAN_F2R2_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F2R2_FB27                        CAN_F2R2_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F2R2_FB28_Pos                    (28U)
#define CAN_F2R2_FB28_Msk                    (0x1UL << CAN_F2R2_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F2R2_FB28                        CAN_F2R2_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F2R2_FB29_Pos                    (29U)
#define CAN_F2R2_FB29_Msk                    (0x1UL << CAN_F2R2_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F2R2_FB29                        CAN_F2R2_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F2R2_FB30_Pos                    (30U)
#define CAN_F2R2_FB30_Msk                    (0x1UL << CAN_F2R2_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F2R2_FB30                        CAN_F2R2_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F2R2_FB31_Pos                    (31U)
#define CAN_F2R2_FB31_Msk                    (0x1UL << CAN_F2R2_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F2R2_FB31                        CAN_F2R2_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F3R2 register  *******************/
#define CAN_F3R2_FB0_Pos                     (0U)
#define CAN_F3R2_FB0_Msk                     (0x1UL << CAN_F3R2_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F3R2_FB0                         CAN_F3R2_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F3R2_FB1_Pos                     (1U)
#define CAN_F3R2_FB1_Msk                     (0x1UL << CAN_F3R2_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F3R2_FB1                         CAN_F3R2_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F3R2_FB2_Pos                     (2U)
#define CAN_F3R2_FB2_Msk                     (0x1UL << CAN_F3R2_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F3R2_FB2                         CAN_F3R2_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F3R2_FB3_Pos                     (3U)
#define CAN_F3R2_FB3_Msk                     (0x1UL << CAN_F3R2_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F3R2_FB3                         CAN_F3R2_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F3R2_FB4_Pos                     (4U)
#define CAN_F3R2_FB4_Msk                     (0x1UL << CAN_F3R2_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F3R2_FB4                         CAN_F3R2_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F3R2_FB5_Pos                     (5U)
#define CAN_F3R2_FB5_Msk                     (0x1UL << CAN_F3R2_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F3R2_FB5                         CAN_F3R2_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F3R2_FB6_Pos                     (6U)
#define CAN_F3R2_FB6_Msk                     (0x1UL << CAN_F3R2_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F3R2_FB6                         CAN_F3R2_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F3R2_FB7_Pos                     (7U)
#define CAN_F3R2_FB7_Msk                     (0x1UL << CAN_F3R2_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F3R2_FB7                         CAN_F3R2_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F3R2_FB8_Pos                     (8U)
#define CAN_F3R2_FB8_Msk                     (0x1UL << CAN_F3R2_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F3R2_FB8                         CAN_F3R2_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F3R2_FB9_Pos                     (9U)
#define CAN_F3R2_FB9_Msk                     (0x1UL << CAN_F3R2_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F3R2_FB9                         CAN_F3R2_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F3R2_FB10_Pos                    (10U)
#define CAN_F3R2_FB10_Msk                    (0x1UL << CAN_F3R2_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F3R2_FB10                        CAN_F3R2_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F3R2_FB11_Pos                    (11U)
#define CAN_F3R2_FB11_Msk                    (0x1UL << CAN_F3R2_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F3R2_FB11                        CAN_F3R2_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F3R2_FB12_Pos                    (12U)
#define CAN_F3R2_FB12_Msk                    (0x1UL << CAN_F3R2_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F3R2_FB12                        CAN_F3R2_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F3R2_FB13_Pos                    (13U)
#define CAN_F3R2_FB13_Msk                    (0x1UL << CAN_F3R2_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F3R2_FB13                        CAN_F3R2_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F3R2_FB14_Pos                    (14U)
#define CAN_F3R2_FB14_Msk                    (0x1UL << CAN_F3R2_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F3R2_FB14                        CAN_F3R2_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F3R2_FB15_Pos                    (15U)
#define CAN_F3R2_FB15_Msk                    (0x1UL << CAN_F3R2_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F3R2_FB15                        CAN_F3R2_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F3R2_FB16_Pos                    (16U)
#define CAN_F3R2_FB16_Msk                    (0x1UL << CAN_F3R2_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F3R2_FB16                        CAN_F3R2_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F3R2_FB17_Pos                    (17U)
#define CAN_F3R2_FB17_Msk                    (0x1UL << CAN_F3R2_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F3R2_FB17                        CAN_F3R2_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F3R2_FB18_Pos                    (18U)
#define CAN_F3R2_FB18_Msk                    (0x1UL << CAN_F3R2_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F3R2_FB18                        CAN_F3R2_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F3R2_FB19_Pos                    (19U)
#define CAN_F3R2_FB19_Msk                    (0x1UL << CAN_F3R2_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F3R2_FB19                        CAN_F3R2_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F3R2_FB20_Pos                    (20U)
#define CAN_F3R2_FB20_Msk                    (0x1UL << CAN_F3R2_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F3R2_FB20                        CAN_F3R2_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F3R2_FB21_Pos                    (21U)
#define CAN_F3R2_FB21_Msk                    (0x1UL << CAN_F3R2_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F3R2_FB21                        CAN_F3R2_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F3R2_FB22_Pos                    (22U)
#define CAN_F3R2_FB22_Msk                    (0x1UL << CAN_F3R2_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F3R2_FB22                        CAN_F3R2_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F3R2_FB23_Pos                    (23U)
#define CAN_F3R2_FB23_Msk                    (0x1UL << CAN_F3R2_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F3R2_FB23                        CAN_F3R2_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F3R2_FB24_Pos                    (24U)
#define CAN_F3R2_FB24_Msk                    (0x1UL << CAN_F3R2_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F3R2_FB24                        CAN_F3R2_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F3R2_FB25_Pos                    (25U)
#define CAN_F3R2_FB25_Msk                    (0x1UL << CAN_F3R2_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F3R2_FB25                        CAN_F3R2_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F3R2_FB26_Pos                    (26U)
#define CAN_F3R2_FB26_Msk                    (0x1UL << CAN_F3R2_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F3R2_FB26                        CAN_F3R2_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F3R2_FB27_Pos                    (27U)
#define CAN_F3R2_FB27_Msk                    (0x1UL << CAN_F3R2_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F3R2_FB27                        CAN_F3R2_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F3R2_FB28_Pos                    (28U)
#define CAN_F3R2_FB28_Msk                    (0x1UL << CAN_F3R2_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F3R2_FB28                        CAN_F3R2_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F3R2_FB29_Pos                    (29U)
#define CAN_F3R2_FB29_Msk                    (0x1UL << CAN_F3R2_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F3R2_FB29                        CAN_F3R2_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F3R2_FB30_Pos                    (30U)
#define CAN_F3R2_FB30_Msk                    (0x1UL << CAN_F3R2_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F3R2_FB30                        CAN_F3R2_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F3R2_FB31_Pos                    (31U)
#define CAN_F3R2_FB31_Msk                    (0x1UL << CAN_F3R2_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F3R2_FB31                        CAN_F3R2_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F4R2 register  *******************/
#define CAN_F4R2_FB0_Pos                     (0U)
#define CAN_F4R2_FB0_Msk                     (0x1UL << CAN_F4R2_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F4R2_FB0                         CAN_F4R2_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F4R2_FB1_Pos                     (1U)
#define CAN_F4R2_FB1_Msk                     (0x1UL << CAN_F4R2_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F4R2_FB1                         CAN_F4R2_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F4R2_FB2_Pos                     (2U)
#define CAN_F4R2_FB2_Msk                     (0x1UL << CAN_F4R2_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F4R2_FB2                         CAN_F4R2_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F4R2_FB3_Pos                     (3U)
#define CAN_F4R2_FB3_Msk                     (0x1UL << CAN_F4R2_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F4R2_FB3                         CAN_F4R2_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F4R2_FB4_Pos                     (4U)
#define CAN_F4R2_FB4_Msk                     (0x1UL << CAN_F4R2_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F4R2_FB4                         CAN_F4R2_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F4R2_FB5_Pos                     (5U)
#define CAN_F4R2_FB5_Msk                     (0x1UL << CAN_F4R2_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F4R2_FB5                         CAN_F4R2_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F4R2_FB6_Pos                     (6U)
#define CAN_F4R2_FB6_Msk                     (0x1UL << CAN_F4R2_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F4R2_FB6                         CAN_F4R2_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F4R2_FB7_Pos                     (7U)
#define CAN_F4R2_FB7_Msk                     (0x1UL << CAN_F4R2_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F4R2_FB7                         CAN_F4R2_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F4R2_FB8_Pos                     (8U)
#define CAN_F4R2_FB8_Msk                     (0x1UL << CAN_F4R2_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F4R2_FB8                         CAN_F4R2_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F4R2_FB9_Pos                     (9U)
#define CAN_F4R2_FB9_Msk                     (0x1UL << CAN_F4R2_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F4R2_FB9                         CAN_F4R2_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F4R2_FB10_Pos                    (10U)
#define CAN_F4R2_FB10_Msk                    (0x1UL << CAN_F4R2_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F4R2_FB10                        CAN_F4R2_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F4R2_FB11_Pos                    (11U)
#define CAN_F4R2_FB11_Msk                    (0x1UL << CAN_F4R2_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F4R2_FB11                        CAN_F4R2_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F4R2_FB12_Pos                    (12U)
#define CAN_F4R2_FB12_Msk                    (0x1UL << CAN_F4R2_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F4R2_FB12                        CAN_F4R2_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F4R2_FB13_Pos                    (13U)
#define CAN_F4R2_FB13_Msk                    (0x1UL << CAN_F4R2_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F4R2_FB13                        CAN_F4R2_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F4R2_FB14_Pos                    (14U)
#define CAN_F4R2_FB14_Msk                    (0x1UL << CAN_F4R2_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F4R2_FB14                        CAN_F4R2_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F4R2_FB15_Pos                    (15U)
#define CAN_F4R2_FB15_Msk                    (0x1UL << CAN_F4R2_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F4R2_FB15                        CAN_F4R2_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F4R2_FB16_Pos                    (16U)
#define CAN_F4R2_FB16_Msk                    (0x1UL << CAN_F4R2_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F4R2_FB16                        CAN_F4R2_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F4R2_FB17_Pos                    (17U)
#define CAN_F4R2_FB17_Msk                    (0x1UL << CAN_F4R2_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F4R2_FB17                        CAN_F4R2_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F4R2_FB18_Pos                    (18U)
#define CAN_F4R2_FB18_Msk                    (0x1UL << CAN_F4R2_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F4R2_FB18                        CAN_F4R2_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F4R2_FB19_Pos                    (19U)
#define CAN_F4R2_FB19_Msk                    (0x1UL << CAN_F4R2_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F4R2_FB19                        CAN_F4R2_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F4R2_FB20_Pos                    (20U)
#define CAN_F4R2_FB20_Msk                    (0x1UL << CAN_F4R2_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F4R2_FB20                        CAN_F4R2_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F4R2_FB21_Pos                    (21U)
#define CAN_F4R2_FB21_Msk                    (0x1UL << CAN_F4R2_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F4R2_FB21                        CAN_F4R2_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F4R2_FB22_Pos                    (22U)
#define CAN_F4R2_FB22_Msk                    (0x1UL << CAN_F4R2_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F4R2_FB22                        CAN_F4R2_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F4R2_FB23_Pos                    (23U)
#define CAN_F4R2_FB23_Msk                    (0x1UL << CAN_F4R2_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F4R2_FB23                        CAN_F4R2_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F4R2_FB24_Pos                    (24U)
#define CAN_F4R2_FB24_Msk                    (0x1UL << CAN_F4R2_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F4R2_FB24                        CAN_F4R2_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F4R2_FB25_Pos                    (25U)
#define CAN_F4R2_FB25_Msk                    (0x1UL << CAN_F4R2_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F4R2_FB25                        CAN_F4R2_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F4R2_FB26_Pos                    (26U)
#define CAN_F4R2_FB26_Msk                    (0x1UL << CAN_F4R2_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F4R2_FB26                        CAN_F4R2_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F4R2_FB27_Pos                    (27U)
#define CAN_F4R2_FB27_Msk                    (0x1UL << CAN_F4R2_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F4R2_FB27                        CAN_F4R2_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F4R2_FB28_Pos                    (28U)
#define CAN_F4R2_FB28_Msk                    (0x1UL << CAN_F4R2_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F4R2_FB28                        CAN_F4R2_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F4R2_FB29_Pos                    (29U)
#define CAN_F4R2_FB29_Msk                    (0x1UL << CAN_F4R2_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F4R2_FB29                        CAN_F4R2_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F4R2_FB30_Pos                    (30U)
#define CAN_F4R2_FB30_Msk                    (0x1UL << CAN_F4R2_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F4R2_FB30                        CAN_F4R2_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F4R2_FB31_Pos                    (31U)
#define CAN_F4R2_FB31_Msk                    (0x1UL << CAN_F4R2_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F4R2_FB31                        CAN_F4R2_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F5R2 register  *******************/
#define CAN_F5R2_FB0_Pos                     (0U)
#define CAN_F5R2_FB0_Msk                     (0x1UL << CAN_F5R2_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F5R2_FB0                         CAN_F5R2_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F5R2_FB1_Pos                     (1U)
#define CAN_F5R2_FB1_Msk                     (0x1UL << CAN_F5R2_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F5R2_FB1                         CAN_F5R2_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F5R2_FB2_Pos                     (2U)
#define CAN_F5R2_FB2_Msk                     (0x1UL << CAN_F5R2_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F5R2_FB2                         CAN_F5R2_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F5R2_FB3_Pos                     (3U)
#define CAN_F5R2_FB3_Msk                     (0x1UL << CAN_F5R2_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F5R2_FB3                         CAN_F5R2_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F5R2_FB4_Pos                     (4U)
#define CAN_F5R2_FB4_Msk                     (0x1UL << CAN_F5R2_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F5R2_FB4                         CAN_F5R2_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F5R2_FB5_Pos                     (5U)
#define CAN_F5R2_FB5_Msk                     (0x1UL << CAN_F5R2_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F5R2_FB5                         CAN_F5R2_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F5R2_FB6_Pos                     (6U)
#define CAN_F5R2_FB6_Msk                     (0x1UL << CAN_F5R2_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F5R2_FB6                         CAN_F5R2_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F5R2_FB7_Pos                     (7U)
#define CAN_F5R2_FB7_Msk                     (0x1UL << CAN_F5R2_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F5R2_FB7                         CAN_F5R2_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F5R2_FB8_Pos                     (8U)
#define CAN_F5R2_FB8_Msk                     (0x1UL << CAN_F5R2_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F5R2_FB8                         CAN_F5R2_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F5R2_FB9_Pos                     (9U)
#define CAN_F5R2_FB9_Msk                     (0x1UL << CAN_F5R2_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F5R2_FB9                         CAN_F5R2_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F5R2_FB10_Pos                    (10U)
#define CAN_F5R2_FB10_Msk                    (0x1UL << CAN_F5R2_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F5R2_FB10                        CAN_F5R2_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F5R2_FB11_Pos                    (11U)
#define CAN_F5R2_FB11_Msk                    (0x1UL << CAN_F5R2_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F5R2_FB11                        CAN_F5R2_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F5R2_FB12_Pos                    (12U)
#define CAN_F5R2_FB12_Msk                    (0x1UL << CAN_F5R2_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F5R2_FB12                        CAN_F5R2_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F5R2_FB13_Pos                    (13U)
#define CAN_F5R2_FB13_Msk                    (0x1UL << CAN_F5R2_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F5R2_FB13                        CAN_F5R2_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F5R2_FB14_Pos                    (14U)
#define CAN_F5R2_FB14_Msk                    (0x1UL << CAN_F5R2_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F5R2_FB14                        CAN_F5R2_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F5R2_FB15_Pos                    (15U)
#define CAN_F5R2_FB15_Msk                    (0x1UL << CAN_F5R2_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F5R2_FB15                        CAN_F5R2_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F5R2_FB16_Pos                    (16U)
#define CAN_F5R2_FB16_Msk                    (0x1UL << CAN_F5R2_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F5R2_FB16                        CAN_F5R2_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F5R2_FB17_Pos                    (17U)
#define CAN_F5R2_FB17_Msk                    (0x1UL << CAN_F5R2_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F5R2_FB17                        CAN_F5R2_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F5R2_FB18_Pos                    (18U)
#define CAN_F5R2_FB18_Msk                    (0x1UL << CAN_F5R2_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F5R2_FB18                        CAN_F5R2_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F5R2_FB19_Pos                    (19U)
#define CAN_F5R2_FB19_Msk                    (0x1UL << CAN_F5R2_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F5R2_FB19                        CAN_F5R2_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F5R2_FB20_Pos                    (20U)
#define CAN_F5R2_FB20_Msk                    (0x1UL << CAN_F5R2_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F5R2_FB20                        CAN_F5R2_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F5R2_FB21_Pos                    (21U)
#define CAN_F5R2_FB21_Msk                    (0x1UL << CAN_F5R2_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F5R2_FB21                        CAN_F5R2_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F5R2_FB22_Pos                    (22U)
#define CAN_F5R2_FB22_Msk                    (0x1UL << CAN_F5R2_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F5R2_FB22                        CAN_F5R2_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F5R2_FB23_Pos                    (23U)
#define CAN_F5R2_FB23_Msk                    (0x1UL << CAN_F5R2_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F5R2_FB23                        CAN_F5R2_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F5R2_FB24_Pos                    (24U)
#define CAN_F5R2_FB24_Msk                    (0x1UL << CAN_F5R2_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F5R2_FB24                        CAN_F5R2_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F5R2_FB25_Pos                    (25U)
#define CAN_F5R2_FB25_Msk                    (0x1UL << CAN_F5R2_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F5R2_FB25                        CAN_F5R2_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F5R2_FB26_Pos                    (26U)
#define CAN_F5R2_FB26_Msk                    (0x1UL << CAN_F5R2_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F5R2_FB26                        CAN_F5R2_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F5R2_FB27_Pos                    (27U)
#define CAN_F5R2_FB27_Msk                    (0x1UL << CAN_F5R2_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F5R2_FB27                        CAN_F5R2_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F5R2_FB28_Pos                    (28U)
#define CAN_F5R2_FB28_Msk                    (0x1UL << CAN_F5R2_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F5R2_FB28                        CAN_F5R2_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F5R2_FB29_Pos                    (29U)
#define CAN_F5R2_FB29_Msk                    (0x1UL << CAN_F5R2_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F5R2_FB29                        CAN_F5R2_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F5R2_FB30_Pos                    (30U)
#define CAN_F5R2_FB30_Msk                    (0x1UL << CAN_F5R2_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F5R2_FB30                        CAN_F5R2_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F5R2_FB31_Pos                    (31U)
#define CAN_F5R2_FB31_Msk                    (0x1UL << CAN_F5R2_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F5R2_FB31                        CAN_F5R2_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F6R2 register  *******************/
#define CAN_F6R2_FB0_Pos                     (0U)
#define CAN_F6R2_FB0_Msk                     (0x1UL << CAN_F6R2_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F6R2_FB0                         CAN_F6R2_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F6R2_FB1_Pos                     (1U)
#define CAN_F6R2_FB1_Msk                     (0x1UL << CAN_F6R2_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F6R2_FB1                         CAN_F6R2_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F6R2_FB2_Pos                     (2U)
#define CAN_F6R2_FB2_Msk                     (0x1UL << CAN_F6R2_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F6R2_FB2                         CAN_F6R2_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F6R2_FB3_Pos                     (3U)
#define CAN_F6R2_FB3_Msk                     (0x1UL << CAN_F6R2_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F6R2_FB3                         CAN_F6R2_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F6R2_FB4_Pos                     (4U)
#define CAN_F6R2_FB4_Msk                     (0x1UL << CAN_F6R2_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F6R2_FB4                         CAN_F6R2_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F6R2_FB5_Pos                     (5U)
#define CAN_F6R2_FB5_Msk                     (0x1UL << CAN_F6R2_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F6R2_FB5                         CAN_F6R2_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F6R2_FB6_Pos                     (6U)
#define CAN_F6R2_FB6_Msk                     (0x1UL << CAN_F6R2_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F6R2_FB6                         CAN_F6R2_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F6R2_FB7_Pos                     (7U)
#define CAN_F6R2_FB7_Msk                     (0x1UL << CAN_F6R2_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F6R2_FB7                         CAN_F6R2_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F6R2_FB8_Pos                     (8U)
#define CAN_F6R2_FB8_Msk                     (0x1UL << CAN_F6R2_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F6R2_FB8                         CAN_F6R2_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F6R2_FB9_Pos                     (9U)
#define CAN_F6R2_FB9_Msk                     (0x1UL << CAN_F6R2_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F6R2_FB9                         CAN_F6R2_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F6R2_FB10_Pos                    (10U)
#define CAN_F6R2_FB10_Msk                    (0x1UL << CAN_F6R2_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F6R2_FB10                        CAN_F6R2_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F6R2_FB11_Pos                    (11U)
#define CAN_F6R2_FB11_Msk                    (0x1UL << CAN_F6R2_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F6R2_FB11                        CAN_F6R2_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F6R2_FB12_Pos                    (12U)
#define CAN_F6R2_FB12_Msk                    (0x1UL << CAN_F6R2_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F6R2_FB12                        CAN_F6R2_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F6R2_FB13_Pos                    (13U)
#define CAN_F6R2_FB13_Msk                    (0x1UL << CAN_F6R2_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F6R2_FB13                        CAN_F6R2_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F6R2_FB14_Pos                    (14U)
#define CAN_F6R2_FB14_Msk                    (0x1UL << CAN_F6R2_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F6R2_FB14                        CAN_F6R2_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F6R2_FB15_Pos                    (15U)
#define CAN_F6R2_FB15_Msk                    (0x1UL << CAN_F6R2_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F6R2_FB15                        CAN_F6R2_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F6R2_FB16_Pos                    (16U)
#define CAN_F6R2_FB16_Msk                    (0x1UL << CAN_F6R2_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F6R2_FB16                        CAN_F6R2_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F6R2_FB17_Pos                    (17U)
#define CAN_F6R2_FB17_Msk                    (0x1UL << CAN_F6R2_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F6R2_FB17                        CAN_F6R2_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F6R2_FB18_Pos                    (18U)
#define CAN_F6R2_FB18_Msk                    (0x1UL << CAN_F6R2_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F6R2_FB18                        CAN_F6R2_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F6R2_FB19_Pos                    (19U)
#define CAN_F6R2_FB19_Msk                    (0x1UL << CAN_F6R2_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F6R2_FB19                        CAN_F6R2_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F6R2_FB20_Pos                    (20U)
#define CAN_F6R2_FB20_Msk                    (0x1UL << CAN_F6R2_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F6R2_FB20                        CAN_F6R2_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F6R2_FB21_Pos                    (21U)
#define CAN_F6R2_FB21_Msk                    (0x1UL << CAN_F6R2_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F6R2_FB21                        CAN_F6R2_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F6R2_FB22_Pos                    (22U)
#define CAN_F6R2_FB22_Msk                    (0x1UL << CAN_F6R2_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F6R2_FB22                        CAN_F6R2_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F6R2_FB23_Pos                    (23U)
#define CAN_F6R2_FB23_Msk                    (0x1UL << CAN_F6R2_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F6R2_FB23                        CAN_F6R2_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F6R2_FB24_Pos                    (24U)
#define CAN_F6R2_FB24_Msk                    (0x1UL << CAN_F6R2_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F6R2_FB24                        CAN_F6R2_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F6R2_FB25_Pos                    (25U)
#define CAN_F6R2_FB25_Msk                    (0x1UL << CAN_F6R2_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F6R2_FB25                        CAN_F6R2_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F6R2_FB26_Pos                    (26U)
#define CAN_F6R2_FB26_Msk                    (0x1UL << CAN_F6R2_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F6R2_FB26                        CAN_F6R2_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F6R2_FB27_Pos                    (27U)
#define CAN_F6R2_FB27_Msk                    (0x1UL << CAN_F6R2_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F6R2_FB27                        CAN_F6R2_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F6R2_FB28_Pos                    (28U)
#define CAN_F6R2_FB28_Msk                    (0x1UL << CAN_F6R2_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F6R2_FB28                        CAN_F6R2_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F6R2_FB29_Pos                    (29U)
#define CAN_F6R2_FB29_Msk                    (0x1UL << CAN_F6R2_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F6R2_FB29                        CAN_F6R2_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F6R2_FB30_Pos                    (30U)
#define CAN_F6R2_FB30_Msk                    (0x1UL << CAN_F6R2_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F6R2_FB30                        CAN_F6R2_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F6R2_FB31_Pos                    (31U)
#define CAN_F6R2_FB31_Msk                    (0x1UL << CAN_F6R2_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F6R2_FB31                        CAN_F6R2_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F7R2 register  *******************/
#define CAN_F7R2_FB0_Pos                     (0U)
#define CAN_F7R2_FB0_Msk                     (0x1UL << CAN_F7R2_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F7R2_FB0                         CAN_F7R2_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F7R2_FB1_Pos                     (1U)
#define CAN_F7R2_FB1_Msk                     (0x1UL << CAN_F7R2_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F7R2_FB1                         CAN_F7R2_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F7R2_FB2_Pos                     (2U)
#define CAN_F7R2_FB2_Msk                     (0x1UL << CAN_F7R2_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F7R2_FB2                         CAN_F7R2_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F7R2_FB3_Pos                     (3U)
#define CAN_F7R2_FB3_Msk                     (0x1UL << CAN_F7R2_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F7R2_FB3                         CAN_F7R2_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F7R2_FB4_Pos                     (4U)
#define CAN_F7R2_FB4_Msk                     (0x1UL << CAN_F7R2_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F7R2_FB4                         CAN_F7R2_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F7R2_FB5_Pos                     (5U)
#define CAN_F7R2_FB5_Msk                     (0x1UL << CAN_F7R2_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F7R2_FB5                         CAN_F7R2_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F7R2_FB6_Pos                     (6U)
#define CAN_F7R2_FB6_Msk                     (0x1UL << CAN_F7R2_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F7R2_FB6                         CAN_F7R2_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F7R2_FB7_Pos                     (7U)
#define CAN_F7R2_FB7_Msk                     (0x1UL << CAN_F7R2_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F7R2_FB7                         CAN_F7R2_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F7R2_FB8_Pos                     (8U)
#define CAN_F7R2_FB8_Msk                     (0x1UL << CAN_F7R2_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F7R2_FB8                         CAN_F7R2_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F7R2_FB9_Pos                     (9U)
#define CAN_F7R2_FB9_Msk                     (0x1UL << CAN_F7R2_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F7R2_FB9                         CAN_F7R2_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F7R2_FB10_Pos                    (10U)
#define CAN_F7R2_FB10_Msk                    (0x1UL << CAN_F7R2_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F7R2_FB10                        CAN_F7R2_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F7R2_FB11_Pos                    (11U)
#define CAN_F7R2_FB11_Msk                    (0x1UL << CAN_F7R2_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F7R2_FB11                        CAN_F7R2_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F7R2_FB12_Pos                    (12U)
#define CAN_F7R2_FB12_Msk                    (0x1UL << CAN_F7R2_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F7R2_FB12                        CAN_F7R2_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F7R2_FB13_Pos                    (13U)
#define CAN_F7R2_FB13_Msk                    (0x1UL << CAN_F7R2_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F7R2_FB13                        CAN_F7R2_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F7R2_FB14_Pos                    (14U)
#define CAN_F7R2_FB14_Msk                    (0x1UL << CAN_F7R2_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F7R2_FB14                        CAN_F7R2_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F7R2_FB15_Pos                    (15U)
#define CAN_F7R2_FB15_Msk                    (0x1UL << CAN_F7R2_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F7R2_FB15                        CAN_F7R2_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F7R2_FB16_Pos                    (16U)
#define CAN_F7R2_FB16_Msk                    (0x1UL << CAN_F7R2_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F7R2_FB16                        CAN_F7R2_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F7R2_FB17_Pos                    (17U)
#define CAN_F7R2_FB17_Msk                    (0x1UL << CAN_F7R2_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F7R2_FB17                        CAN_F7R2_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F7R2_FB18_Pos                    (18U)
#define CAN_F7R2_FB18_Msk                    (0x1UL << CAN_F7R2_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F7R2_FB18                        CAN_F7R2_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F7R2_FB19_Pos                    (19U)
#define CAN_F7R2_FB19_Msk                    (0x1UL << CAN_F7R2_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F7R2_FB19                        CAN_F7R2_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F7R2_FB20_Pos                    (20U)
#define CAN_F7R2_FB20_Msk                    (0x1UL << CAN_F7R2_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F7R2_FB20                        CAN_F7R2_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F7R2_FB21_Pos                    (21U)
#define CAN_F7R2_FB21_Msk                    (0x1UL << CAN_F7R2_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F7R2_FB21                        CAN_F7R2_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F7R2_FB22_Pos                    (22U)
#define CAN_F7R2_FB22_Msk                    (0x1UL << CAN_F7R2_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F7R2_FB22                        CAN_F7R2_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F7R2_FB23_Pos                    (23U)
#define CAN_F7R2_FB23_Msk                    (0x1UL << CAN_F7R2_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F7R2_FB23                        CAN_F7R2_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F7R2_FB24_Pos                    (24U)
#define CAN_F7R2_FB24_Msk                    (0x1UL << CAN_F7R2_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F7R2_FB24                        CAN_F7R2_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F7R2_FB25_Pos                    (25U)
#define CAN_F7R2_FB25_Msk                    (0x1UL << CAN_F7R2_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F7R2_FB25                        CAN_F7R2_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F7R2_FB26_Pos                    (26U)
#define CAN_F7R2_FB26_Msk                    (0x1UL << CAN_F7R2_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F7R2_FB26                        CAN_F7R2_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F7R2_FB27_Pos                    (27U)
#define CAN_F7R2_FB27_Msk                    (0x1UL << CAN_F7R2_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F7R2_FB27                        CAN_F7R2_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F7R2_FB28_Pos                    (28U)
#define CAN_F7R2_FB28_Msk                    (0x1UL << CAN_F7R2_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F7R2_FB28                        CAN_F7R2_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F7R2_FB29_Pos                    (29U)
#define CAN_F7R2_FB29_Msk                    (0x1UL << CAN_F7R2_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F7R2_FB29                        CAN_F7R2_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F7R2_FB30_Pos                    (30U)
#define CAN_F7R2_FB30_Msk                    (0x1UL << CAN_F7R2_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F7R2_FB30                        CAN_F7R2_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F7R2_FB31_Pos                    (31U)
#define CAN_F7R2_FB31_Msk                    (0x1UL << CAN_F7R2_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F7R2_FB31                        CAN_F7R2_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F8R2 register  *******************/
#define CAN_F8R2_FB0_Pos                     (0U)
#define CAN_F8R2_FB0_Msk                     (0x1UL << CAN_F8R2_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F8R2_FB0                         CAN_F8R2_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F8R2_FB1_Pos                     (1U)
#define CAN_F8R2_FB1_Msk                     (0x1UL << CAN_F8R2_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F8R2_FB1                         CAN_F8R2_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F8R2_FB2_Pos                     (2U)
#define CAN_F8R2_FB2_Msk                     (0x1UL << CAN_F8R2_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F8R2_FB2                         CAN_F8R2_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F8R2_FB3_Pos                     (3U)
#define CAN_F8R2_FB3_Msk                     (0x1UL << CAN_F8R2_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F8R2_FB3                         CAN_F8R2_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F8R2_FB4_Pos                     (4U)
#define CAN_F8R2_FB4_Msk                     (0x1UL << CAN_F8R2_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F8R2_FB4                         CAN_F8R2_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F8R2_FB5_Pos                     (5U)
#define CAN_F8R2_FB5_Msk                     (0x1UL << CAN_F8R2_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F8R2_FB5                         CAN_F8R2_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F8R2_FB6_Pos                     (6U)
#define CAN_F8R2_FB6_Msk                     (0x1UL << CAN_F8R2_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F8R2_FB6                         CAN_F8R2_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F8R2_FB7_Pos                     (7U)
#define CAN_F8R2_FB7_Msk                     (0x1UL << CAN_F8R2_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F8R2_FB7                         CAN_F8R2_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F8R2_FB8_Pos                     (8U)
#define CAN_F8R2_FB8_Msk                     (0x1UL << CAN_F8R2_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F8R2_FB8                         CAN_F8R2_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F8R2_FB9_Pos                     (9U)
#define CAN_F8R2_FB9_Msk                     (0x1UL << CAN_F8R2_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F8R2_FB9                         CAN_F8R2_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F8R2_FB10_Pos                    (10U)
#define CAN_F8R2_FB10_Msk                    (0x1UL << CAN_F8R2_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F8R2_FB10                        CAN_F8R2_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F8R2_FB11_Pos                    (11U)
#define CAN_F8R2_FB11_Msk                    (0x1UL << CAN_F8R2_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F8R2_FB11                        CAN_F8R2_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F8R2_FB12_Pos                    (12U)
#define CAN_F8R2_FB12_Msk                    (0x1UL << CAN_F8R2_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F8R2_FB12                        CAN_F8R2_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F8R2_FB13_Pos                    (13U)
#define CAN_F8R2_FB13_Msk                    (0x1UL << CAN_F8R2_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F8R2_FB13                        CAN_F8R2_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F8R2_FB14_Pos                    (14U)
#define CAN_F8R2_FB14_Msk                    (0x1UL << CAN_F8R2_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F8R2_FB14                        CAN_F8R2_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F8R2_FB15_Pos                    (15U)
#define CAN_F8R2_FB15_Msk                    (0x1UL << CAN_F8R2_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F8R2_FB15                        CAN_F8R2_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F8R2_FB16_Pos                    (16U)
#define CAN_F8R2_FB16_Msk                    (0x1UL << CAN_F8R2_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F8R2_FB16                        CAN_F8R2_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F8R2_FB17_Pos                    (17U)
#define CAN_F8R2_FB17_Msk                    (0x1UL << CAN_F8R2_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F8R2_FB17                        CAN_F8R2_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F8R2_FB18_Pos                    (18U)
#define CAN_F8R2_FB18_Msk                    (0x1UL << CAN_F8R2_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F8R2_FB18                        CAN_F8R2_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F8R2_FB19_Pos                    (19U)
#define CAN_F8R2_FB19_Msk                    (0x1UL << CAN_F8R2_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F8R2_FB19                        CAN_F8R2_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F8R2_FB20_Pos                    (20U)
#define CAN_F8R2_FB20_Msk                    (0x1UL << CAN_F8R2_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F8R2_FB20                        CAN_F8R2_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F8R2_FB21_Pos                    (21U)
#define CAN_F8R2_FB21_Msk                    (0x1UL << CAN_F8R2_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F8R2_FB21                        CAN_F8R2_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F8R2_FB22_Pos                    (22U)
#define CAN_F8R2_FB22_Msk                    (0x1UL << CAN_F8R2_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F8R2_FB22                        CAN_F8R2_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F8R2_FB23_Pos                    (23U)
#define CAN_F8R2_FB23_Msk                    (0x1UL << CAN_F8R2_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F8R2_FB23                        CAN_F8R2_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F8R2_FB24_Pos                    (24U)
#define CAN_F8R2_FB24_Msk                    (0x1UL << CAN_F8R2_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F8R2_FB24                        CAN_F8R2_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F8R2_FB25_Pos                    (25U)
#define CAN_F8R2_FB25_Msk                    (0x1UL << CAN_F8R2_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F8R2_FB25                        CAN_F8R2_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F8R2_FB26_Pos                    (26U)
#define CAN_F8R2_FB26_Msk                    (0x1UL << CAN_F8R2_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F8R2_FB26                        CAN_F8R2_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F8R2_FB27_Pos                    (27U)
#define CAN_F8R2_FB27_Msk                    (0x1UL << CAN_F8R2_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F8R2_FB27                        CAN_F8R2_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F8R2_FB28_Pos                    (28U)
#define CAN_F8R2_FB28_Msk                    (0x1UL << CAN_F8R2_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F8R2_FB28                        CAN_F8R2_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F8R2_FB29_Pos                    (29U)
#define CAN_F8R2_FB29_Msk                    (0x1UL << CAN_F8R2_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F8R2_FB29                        CAN_F8R2_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F8R2_FB30_Pos                    (30U)
#define CAN_F8R2_FB30_Msk                    (0x1UL << CAN_F8R2_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F8R2_FB30                        CAN_F8R2_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F8R2_FB31_Pos                    (31U)
#define CAN_F8R2_FB31_Msk                    (0x1UL << CAN_F8R2_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F8R2_FB31                        CAN_F8R2_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F9R2 register  *******************/
#define CAN_F9R2_FB0_Pos                     (0U)
#define CAN_F9R2_FB0_Msk                     (0x1UL << CAN_F9R2_FB0_Pos)        /*!< 0x00000001 */
#define CAN_F9R2_FB0                         CAN_F9R2_FB0_Msk                  /*!< Filter bit 0 */
#define CAN_F9R2_FB1_Pos                     (1U)
#define CAN_F9R2_FB1_Msk                     (0x1UL << CAN_F9R2_FB1_Pos)        /*!< 0x00000002 */
#define CAN_F9R2_FB1                         CAN_F9R2_FB1_Msk                  /*!< Filter bit 1 */
#define CAN_F9R2_FB2_Pos                     (2U)
#define CAN_F9R2_FB2_Msk                     (0x1UL << CAN_F9R2_FB2_Pos)        /*!< 0x00000004 */
#define CAN_F9R2_FB2                         CAN_F9R2_FB2_Msk                  /*!< Filter bit 2 */
#define CAN_F9R2_FB3_Pos                     (3U)
#define CAN_F9R2_FB3_Msk                     (0x1UL << CAN_F9R2_FB3_Pos)        /*!< 0x00000008 */
#define CAN_F9R2_FB3                         CAN_F9R2_FB3_Msk                  /*!< Filter bit 3 */
#define CAN_F9R2_FB4_Pos                     (4U)
#define CAN_F9R2_FB4_Msk                     (0x1UL << CAN_F9R2_FB4_Pos)        /*!< 0x00000010 */
#define CAN_F9R2_FB4                         CAN_F9R2_FB4_Msk                  /*!< Filter bit 4 */
#define CAN_F9R2_FB5_Pos                     (5U)
#define CAN_F9R2_FB5_Msk                     (0x1UL << CAN_F9R2_FB5_Pos)        /*!< 0x00000020 */
#define CAN_F9R2_FB5                         CAN_F9R2_FB5_Msk                  /*!< Filter bit 5 */
#define CAN_F9R2_FB6_Pos                     (6U)
#define CAN_F9R2_FB6_Msk                     (0x1UL << CAN_F9R2_FB6_Pos)        /*!< 0x00000040 */
#define CAN_F9R2_FB6                         CAN_F9R2_FB6_Msk                  /*!< Filter bit 6 */
#define CAN_F9R2_FB7_Pos                     (7U)
#define CAN_F9R2_FB7_Msk                     (0x1UL << CAN_F9R2_FB7_Pos)        /*!< 0x00000080 */
#define CAN_F9R2_FB7                         CAN_F9R2_FB7_Msk                  /*!< Filter bit 7 */
#define CAN_F9R2_FB8_Pos                     (8U)
#define CAN_F9R2_FB8_Msk                     (0x1UL << CAN_F9R2_FB8_Pos)        /*!< 0x00000100 */
#define CAN_F9R2_FB8                         CAN_F9R2_FB8_Msk                  /*!< Filter bit 8 */
#define CAN_F9R2_FB9_Pos                     (9U)
#define CAN_F9R2_FB9_Msk                     (0x1UL << CAN_F9R2_FB9_Pos)        /*!< 0x00000200 */
#define CAN_F9R2_FB9                         CAN_F9R2_FB9_Msk                  /*!< Filter bit 9 */
#define CAN_F9R2_FB10_Pos                    (10U)
#define CAN_F9R2_FB10_Msk                    (0x1UL << CAN_F9R2_FB10_Pos)       /*!< 0x00000400 */
#define CAN_F9R2_FB10                        CAN_F9R2_FB10_Msk                 /*!< Filter bit 10 */
#define CAN_F9R2_FB11_Pos                    (11U)
#define CAN_F9R2_FB11_Msk                    (0x1UL << CAN_F9R2_FB11_Pos)       /*!< 0x00000800 */
#define CAN_F9R2_FB11                        CAN_F9R2_FB11_Msk                 /*!< Filter bit 11 */
#define CAN_F9R2_FB12_Pos                    (12U)
#define CAN_F9R2_FB12_Msk                    (0x1UL << CAN_F9R2_FB12_Pos)       /*!< 0x00001000 */
#define CAN_F9R2_FB12                        CAN_F9R2_FB12_Msk                 /*!< Filter bit 12 */
#define CAN_F9R2_FB13_Pos                    (13U)
#define CAN_F9R2_FB13_Msk                    (0x1UL << CAN_F9R2_FB13_Pos)       /*!< 0x00002000 */
#define CAN_F9R2_FB13                        CAN_F9R2_FB13_Msk                 /*!< Filter bit 13 */
#define CAN_F9R2_FB14_Pos                    (14U)
#define CAN_F9R2_FB14_Msk                    (0x1UL << CAN_F9R2_FB14_Pos)       /*!< 0x00004000 */
#define CAN_F9R2_FB14                        CAN_F9R2_FB14_Msk                 /*!< Filter bit 14 */
#define CAN_F9R2_FB15_Pos                    (15U)
#define CAN_F9R2_FB15_Msk                    (0x1UL << CAN_F9R2_FB15_Pos)       /*!< 0x00008000 */
#define CAN_F9R2_FB15                        CAN_F9R2_FB15_Msk                 /*!< Filter bit 15 */
#define CAN_F9R2_FB16_Pos                    (16U)
#define CAN_F9R2_FB16_Msk                    (0x1UL << CAN_F9R2_FB16_Pos)       /*!< 0x00010000 */
#define CAN_F9R2_FB16                        CAN_F9R2_FB16_Msk                 /*!< Filter bit 16 */
#define CAN_F9R2_FB17_Pos                    (17U)
#define CAN_F9R2_FB17_Msk                    (0x1UL << CAN_F9R2_FB17_Pos)       /*!< 0x00020000 */
#define CAN_F9R2_FB17                        CAN_F9R2_FB17_Msk                 /*!< Filter bit 17 */
#define CAN_F9R2_FB18_Pos                    (18U)
#define CAN_F9R2_FB18_Msk                    (0x1UL << CAN_F9R2_FB18_Pos)       /*!< 0x00040000 */
#define CAN_F9R2_FB18                        CAN_F9R2_FB18_Msk                 /*!< Filter bit 18 */
#define CAN_F9R2_FB19_Pos                    (19U)
#define CAN_F9R2_FB19_Msk                    (0x1UL << CAN_F9R2_FB19_Pos)       /*!< 0x00080000 */
#define CAN_F9R2_FB19                        CAN_F9R2_FB19_Msk                 /*!< Filter bit 19 */
#define CAN_F9R2_FB20_Pos                    (20U)
#define CAN_F9R2_FB20_Msk                    (0x1UL << CAN_F9R2_FB20_Pos)       /*!< 0x00100000 */
#define CAN_F9R2_FB20                        CAN_F9R2_FB20_Msk                 /*!< Filter bit 20 */
#define CAN_F9R2_FB21_Pos                    (21U)
#define CAN_F9R2_FB21_Msk                    (0x1UL << CAN_F9R2_FB21_Pos)       /*!< 0x00200000 */
#define CAN_F9R2_FB21                        CAN_F9R2_FB21_Msk                 /*!< Filter bit 21 */
#define CAN_F9R2_FB22_Pos                    (22U)
#define CAN_F9R2_FB22_Msk                    (0x1UL << CAN_F9R2_FB22_Pos)       /*!< 0x00400000 */
#define CAN_F9R2_FB22                        CAN_F9R2_FB22_Msk                 /*!< Filter bit 22 */
#define CAN_F9R2_FB23_Pos                    (23U)
#define CAN_F9R2_FB23_Msk                    (0x1UL << CAN_F9R2_FB23_Pos)       /*!< 0x00800000 */
#define CAN_F9R2_FB23                        CAN_F9R2_FB23_Msk                 /*!< Filter bit 23 */
#define CAN_F9R2_FB24_Pos                    (24U)
#define CAN_F9R2_FB24_Msk                    (0x1UL << CAN_F9R2_FB24_Pos)       /*!< 0x01000000 */
#define CAN_F9R2_FB24                        CAN_F9R2_FB24_Msk                 /*!< Filter bit 24 */
#define CAN_F9R2_FB25_Pos                    (25U)
#define CAN_F9R2_FB25_Msk                    (0x1UL << CAN_F9R2_FB25_Pos)       /*!< 0x02000000 */
#define CAN_F9R2_FB25                        CAN_F9R2_FB25_Msk                 /*!< Filter bit 25 */
#define CAN_F9R2_FB26_Pos                    (26U)
#define CAN_F9R2_FB26_Msk                    (0x1UL << CAN_F9R2_FB26_Pos)       /*!< 0x04000000 */
#define CAN_F9R2_FB26                        CAN_F9R2_FB26_Msk                 /*!< Filter bit 26 */
#define CAN_F9R2_FB27_Pos                    (27U)
#define CAN_F9R2_FB27_Msk                    (0x1UL << CAN_F9R2_FB27_Pos)       /*!< 0x08000000 */
#define CAN_F9R2_FB27                        CAN_F9R2_FB27_Msk                 /*!< Filter bit 27 */
#define CAN_F9R2_FB28_Pos                    (28U)
#define CAN_F9R2_FB28_Msk                    (0x1UL << CAN_F9R2_FB28_Pos)       /*!< 0x10000000 */
#define CAN_F9R2_FB28                        CAN_F9R2_FB28_Msk                 /*!< Filter bit 28 */
#define CAN_F9R2_FB29_Pos                    (29U)
#define CAN_F9R2_FB29_Msk                    (0x1UL << CAN_F9R2_FB29_Pos)       /*!< 0x20000000 */
#define CAN_F9R2_FB29                        CAN_F9R2_FB29_Msk                 /*!< Filter bit 29 */
#define CAN_F9R2_FB30_Pos                    (30U)
#define CAN_F9R2_FB30_Msk                    (0x1UL << CAN_F9R2_FB30_Pos)       /*!< 0x40000000 */
#define CAN_F9R2_FB30                        CAN_F9R2_FB30_Msk                 /*!< Filter bit 30 */
#define CAN_F9R2_FB31_Pos                    (31U)
#define CAN_F9R2_FB31_Msk                    (0x1UL << CAN_F9R2_FB31_Pos)       /*!< 0x80000000 */
#define CAN_F9R2_FB31                        CAN_F9R2_FB31_Msk                 /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F10R2 register  ******************/
#define CAN_F10R2_FB0_Pos                    (0U)
#define CAN_F10R2_FB0_Msk                    (0x1UL << CAN_F10R2_FB0_Pos)       /*!< 0x00000001 */
#define CAN_F10R2_FB0                        CAN_F10R2_FB0_Msk                 /*!< Filter bit 0 */
#define CAN_F10R2_FB1_Pos                    (1U)
#define CAN_F10R2_FB1_Msk                    (0x1UL << CAN_F10R2_FB1_Pos)       /*!< 0x00000002 */
#define CAN_F10R2_FB1                        CAN_F10R2_FB1_Msk                 /*!< Filter bit 1 */
#define CAN_F10R2_FB2_Pos                    (2U)
#define CAN_F10R2_FB2_Msk                    (0x1UL << CAN_F10R2_FB2_Pos)       /*!< 0x00000004 */
#define CAN_F10R2_FB2                        CAN_F10R2_FB2_Msk                 /*!< Filter bit 2 */
#define CAN_F10R2_FB3_Pos                    (3U)
#define CAN_F10R2_FB3_Msk                    (0x1UL << CAN_F10R2_FB3_Pos)       /*!< 0x00000008 */
#define CAN_F10R2_FB3                        CAN_F10R2_FB3_Msk                 /*!< Filter bit 3 */
#define CAN_F10R2_FB4_Pos                    (4U)
#define CAN_F10R2_FB4_Msk                    (0x1UL << CAN_F10R2_FB4_Pos)       /*!< 0x00000010 */
#define CAN_F10R2_FB4                        CAN_F10R2_FB4_Msk                 /*!< Filter bit 4 */
#define CAN_F10R2_FB5_Pos                    (5U)
#define CAN_F10R2_FB5_Msk                    (0x1UL << CAN_F10R2_FB5_Pos)       /*!< 0x00000020 */
#define CAN_F10R2_FB5                        CAN_F10R2_FB5_Msk                 /*!< Filter bit 5 */
#define CAN_F10R2_FB6_Pos                    (6U)
#define CAN_F10R2_FB6_Msk                    (0x1UL << CAN_F10R2_FB6_Pos)       /*!< 0x00000040 */
#define CAN_F10R2_FB6                        CAN_F10R2_FB6_Msk                 /*!< Filter bit 6 */
#define CAN_F10R2_FB7_Pos                    (7U)
#define CAN_F10R2_FB7_Msk                    (0x1UL << CAN_F10R2_FB7_Pos)       /*!< 0x00000080 */
#define CAN_F10R2_FB7                        CAN_F10R2_FB7_Msk                 /*!< Filter bit 7 */
#define CAN_F10R2_FB8_Pos                    (8U)
#define CAN_F10R2_FB8_Msk                    (0x1UL << CAN_F10R2_FB8_Pos)       /*!< 0x00000100 */
#define CAN_F10R2_FB8                        CAN_F10R2_FB8_Msk                 /*!< Filter bit 8 */
#define CAN_F10R2_FB9_Pos                    (9U)
#define CAN_F10R2_FB9_Msk                    (0x1UL << CAN_F10R2_FB9_Pos)       /*!< 0x00000200 */
#define CAN_F10R2_FB9                        CAN_F10R2_FB9_Msk                 /*!< Filter bit 9 */
#define CAN_F10R2_FB10_Pos                   (10U)
#define CAN_F10R2_FB10_Msk                   (0x1UL << CAN_F10R2_FB10_Pos)      /*!< 0x00000400 */
#define CAN_F10R2_FB10                       CAN_F10R2_FB10_Msk                /*!< Filter bit 10 */
#define CAN_F10R2_FB11_Pos                   (11U)
#define CAN_F10R2_FB11_Msk                   (0x1UL << CAN_F10R2_FB11_Pos)      /*!< 0x00000800 */
#define CAN_F10R2_FB11                       CAN_F10R2_FB11_Msk                /*!< Filter bit 11 */
#define CAN_F10R2_FB12_Pos                   (12U)
#define CAN_F10R2_FB12_Msk                   (0x1UL << CAN_F10R2_FB12_Pos)      /*!< 0x00001000 */
#define CAN_F10R2_FB12                       CAN_F10R2_FB12_Msk                /*!< Filter bit 12 */
#define CAN_F10R2_FB13_Pos                   (13U)
#define CAN_F10R2_FB13_Msk                   (0x1UL << CAN_F10R2_FB13_Pos)      /*!< 0x00002000 */
#define CAN_F10R2_FB13                       CAN_F10R2_FB13_Msk                /*!< Filter bit 13 */
#define CAN_F10R2_FB14_Pos                   (14U)
#define CAN_F10R2_FB14_Msk                   (0x1UL << CAN_F10R2_FB14_Pos)      /*!< 0x00004000 */
#define CAN_F10R2_FB14                       CAN_F10R2_FB14_Msk                /*!< Filter bit 14 */
#define CAN_F10R2_FB15_Pos                   (15U)
#define CAN_F10R2_FB15_Msk                   (0x1UL << CAN_F10R2_FB15_Pos)      /*!< 0x00008000 */
#define CAN_F10R2_FB15                       CAN_F10R2_FB15_Msk                /*!< Filter bit 15 */
#define CAN_F10R2_FB16_Pos                   (16U)
#define CAN_F10R2_FB16_Msk                   (0x1UL << CAN_F10R2_FB16_Pos)      /*!< 0x00010000 */
#define CAN_F10R2_FB16                       CAN_F10R2_FB16_Msk                /*!< Filter bit 16 */
#define CAN_F10R2_FB17_Pos                   (17U)
#define CAN_F10R2_FB17_Msk                   (0x1UL << CAN_F10R2_FB17_Pos)      /*!< 0x00020000 */
#define CAN_F10R2_FB17                       CAN_F10R2_FB17_Msk                /*!< Filter bit 17 */
#define CAN_F10R2_FB18_Pos                   (18U)
#define CAN_F10R2_FB18_Msk                   (0x1UL << CAN_F10R2_FB18_Pos)      /*!< 0x00040000 */
#define CAN_F10R2_FB18                       CAN_F10R2_FB18_Msk                /*!< Filter bit 18 */
#define CAN_F10R2_FB19_Pos                   (19U)
#define CAN_F10R2_FB19_Msk                   (0x1UL << CAN_F10R2_FB19_Pos)      /*!< 0x00080000 */
#define CAN_F10R2_FB19                       CAN_F10R2_FB19_Msk                /*!< Filter bit 19 */
#define CAN_F10R2_FB20_Pos                   (20U)
#define CAN_F10R2_FB20_Msk                   (0x1UL << CAN_F10R2_FB20_Pos)      /*!< 0x00100000 */
#define CAN_F10R2_FB20                       CAN_F10R2_FB20_Msk                /*!< Filter bit 20 */
#define CAN_F10R2_FB21_Pos                   (21U)
#define CAN_F10R2_FB21_Msk                   (0x1UL << CAN_F10R2_FB21_Pos)      /*!< 0x00200000 */
#define CAN_F10R2_FB21                       CAN_F10R2_FB21_Msk                /*!< Filter bit 21 */
#define CAN_F10R2_FB22_Pos                   (22U)
#define CAN_F10R2_FB22_Msk                   (0x1UL << CAN_F10R2_FB22_Pos)      /*!< 0x00400000 */
#define CAN_F10R2_FB22                       CAN_F10R2_FB22_Msk                /*!< Filter bit 22 */
#define CAN_F10R2_FB23_Pos                   (23U)
#define CAN_F10R2_FB23_Msk                   (0x1UL << CAN_F10R2_FB23_Pos)      /*!< 0x00800000 */
#define CAN_F10R2_FB23                       CAN_F10R2_FB23_Msk                /*!< Filter bit 23 */
#define CAN_F10R2_FB24_Pos                   (24U)
#define CAN_F10R2_FB24_Msk                   (0x1UL << CAN_F10R2_FB24_Pos)      /*!< 0x01000000 */
#define CAN_F10R2_FB24                       CAN_F10R2_FB24_Msk                /*!< Filter bit 24 */
#define CAN_F10R2_FB25_Pos                   (25U)
#define CAN_F10R2_FB25_Msk                   (0x1UL << CAN_F10R2_FB25_Pos)      /*!< 0x02000000 */
#define CAN_F10R2_FB25                       CAN_F10R2_FB25_Msk                /*!< Filter bit 25 */
#define CAN_F10R2_FB26_Pos                   (26U)
#define CAN_F10R2_FB26_Msk                   (0x1UL << CAN_F10R2_FB26_Pos)      /*!< 0x04000000 */
#define CAN_F10R2_FB26                       CAN_F10R2_FB26_Msk                /*!< Filter bit 26 */
#define CAN_F10R2_FB27_Pos                   (27U)
#define CAN_F10R2_FB27_Msk                   (0x1UL << CAN_F10R2_FB27_Pos)      /*!< 0x08000000 */
#define CAN_F10R2_FB27                       CAN_F10R2_FB27_Msk                /*!< Filter bit 27 */
#define CAN_F10R2_FB28_Pos                   (28U)
#define CAN_F10R2_FB28_Msk                   (0x1UL << CAN_F10R2_FB28_Pos)      /*!< 0x10000000 */
#define CAN_F10R2_FB28                       CAN_F10R2_FB28_Msk                /*!< Filter bit 28 */
#define CAN_F10R2_FB29_Pos                   (29U)
#define CAN_F10R2_FB29_Msk                   (0x1UL << CAN_F10R2_FB29_Pos)      /*!< 0x20000000 */
#define CAN_F10R2_FB29                       CAN_F10R2_FB29_Msk                /*!< Filter bit 29 */
#define CAN_F10R2_FB30_Pos                   (30U)
#define CAN_F10R2_FB30_Msk                   (0x1UL << CAN_F10R2_FB30_Pos)      /*!< 0x40000000 */
#define CAN_F10R2_FB30                       CAN_F10R2_FB30_Msk                /*!< Filter bit 30 */
#define CAN_F10R2_FB31_Pos                   (31U)
#define CAN_F10R2_FB31_Msk                   (0x1UL << CAN_F10R2_FB31_Pos)      /*!< 0x80000000 */
#define CAN_F10R2_FB31                       CAN_F10R2_FB31_Msk                /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F11R2 register  ******************/
#define CAN_F11R2_FB0_Pos                    (0U)
#define CAN_F11R2_FB0_Msk                    (0x1UL << CAN_F11R2_FB0_Pos)       /*!< 0x00000001 */
#define CAN_F11R2_FB0                        CAN_F11R2_FB0_Msk                 /*!< Filter bit 0 */
#define CAN_F11R2_FB1_Pos                    (1U)
#define CAN_F11R2_FB1_Msk                    (0x1UL << CAN_F11R2_FB1_Pos)       /*!< 0x00000002 */
#define CAN_F11R2_FB1                        CAN_F11R2_FB1_Msk                 /*!< Filter bit 1 */
#define CAN_F11R2_FB2_Pos                    (2U)
#define CAN_F11R2_FB2_Msk                    (0x1UL << CAN_F11R2_FB2_Pos)       /*!< 0x00000004 */
#define CAN_F11R2_FB2                        CAN_F11R2_FB2_Msk                 /*!< Filter bit 2 */
#define CAN_F11R2_FB3_Pos                    (3U)
#define CAN_F11R2_FB3_Msk                    (0x1UL << CAN_F11R2_FB3_Pos)       /*!< 0x00000008 */
#define CAN_F11R2_FB3                        CAN_F11R2_FB3_Msk                 /*!< Filter bit 3 */
#define CAN_F11R2_FB4_Pos                    (4U)
#define CAN_F11R2_FB4_Msk                    (0x1UL << CAN_F11R2_FB4_Pos)       /*!< 0x00000010 */
#define CAN_F11R2_FB4                        CAN_F11R2_FB4_Msk                 /*!< Filter bit 4 */
#define CAN_F11R2_FB5_Pos                    (5U)
#define CAN_F11R2_FB5_Msk                    (0x1UL << CAN_F11R2_FB5_Pos)       /*!< 0x00000020 */
#define CAN_F11R2_FB5                        CAN_F11R2_FB5_Msk                 /*!< Filter bit 5 */
#define CAN_F11R2_FB6_Pos                    (6U)
#define CAN_F11R2_FB6_Msk                    (0x1UL << CAN_F11R2_FB6_Pos)       /*!< 0x00000040 */
#define CAN_F11R2_FB6                        CAN_F11R2_FB6_Msk                 /*!< Filter bit 6 */
#define CAN_F11R2_FB7_Pos                    (7U)
#define CAN_F11R2_FB7_Msk                    (0x1UL << CAN_F11R2_FB7_Pos)       /*!< 0x00000080 */
#define CAN_F11R2_FB7                        CAN_F11R2_FB7_Msk                 /*!< Filter bit 7 */
#define CAN_F11R2_FB8_Pos                    (8U)
#define CAN_F11R2_FB8_Msk                    (0x1UL << CAN_F11R2_FB8_Pos)       /*!< 0x00000100 */
#define CAN_F11R2_FB8                        CAN_F11R2_FB8_Msk                 /*!< Filter bit 8 */
#define CAN_F11R2_FB9_Pos                    (9U)
#define CAN_F11R2_FB9_Msk                    (0x1UL << CAN_F11R2_FB9_Pos)       /*!< 0x00000200 */
#define CAN_F11R2_FB9                        CAN_F11R2_FB9_Msk                 /*!< Filter bit 9 */
#define CAN_F11R2_FB10_Pos                   (10U)
#define CAN_F11R2_FB10_Msk                   (0x1UL << CAN_F11R2_FB10_Pos)      /*!< 0x00000400 */
#define CAN_F11R2_FB10                       CAN_F11R2_FB10_Msk                /*!< Filter bit 10 */
#define CAN_F11R2_FB11_Pos                   (11U)
#define CAN_F11R2_FB11_Msk                   (0x1UL << CAN_F11R2_FB11_Pos)      /*!< 0x00000800 */
#define CAN_F11R2_FB11                       CAN_F11R2_FB11_Msk                /*!< Filter bit 11 */
#define CAN_F11R2_FB12_Pos                   (12U)
#define CAN_F11R2_FB12_Msk                   (0x1UL << CAN_F11R2_FB12_Pos)      /*!< 0x00001000 */
#define CAN_F11R2_FB12                       CAN_F11R2_FB12_Msk                /*!< Filter bit 12 */
#define CAN_F11R2_FB13_Pos                   (13U)
#define CAN_F11R2_FB13_Msk                   (0x1UL << CAN_F11R2_FB13_Pos)      /*!< 0x00002000 */
#define CAN_F11R2_FB13                       CAN_F11R2_FB13_Msk                /*!< Filter bit 13 */
#define CAN_F11R2_FB14_Pos                   (14U)
#define CAN_F11R2_FB14_Msk                   (0x1UL << CAN_F11R2_FB14_Pos)      /*!< 0x00004000 */
#define CAN_F11R2_FB14                       CAN_F11R2_FB14_Msk                /*!< Filter bit 14 */
#define CAN_F11R2_FB15_Pos                   (15U)
#define CAN_F11R2_FB15_Msk                   (0x1UL << CAN_F11R2_FB15_Pos)      /*!< 0x00008000 */
#define CAN_F11R2_FB15                       CAN_F11R2_FB15_Msk                /*!< Filter bit 15 */
#define CAN_F11R2_FB16_Pos                   (16U)
#define CAN_F11R2_FB16_Msk                   (0x1UL << CAN_F11R2_FB16_Pos)      /*!< 0x00010000 */
#define CAN_F11R2_FB16                       CAN_F11R2_FB16_Msk                /*!< Filter bit 16 */
#define CAN_F11R2_FB17_Pos                   (17U)
#define CAN_F11R2_FB17_Msk                   (0x1UL << CAN_F11R2_FB17_Pos)      /*!< 0x00020000 */
#define CAN_F11R2_FB17                       CAN_F11R2_FB17_Msk                /*!< Filter bit 17 */
#define CAN_F11R2_FB18_Pos                   (18U)
#define CAN_F11R2_FB18_Msk                   (0x1UL << CAN_F11R2_FB18_Pos)      /*!< 0x00040000 */
#define CAN_F11R2_FB18                       CAN_F11R2_FB18_Msk                /*!< Filter bit 18 */
#define CAN_F11R2_FB19_Pos                   (19U)
#define CAN_F11R2_FB19_Msk                   (0x1UL << CAN_F11R2_FB19_Pos)      /*!< 0x00080000 */
#define CAN_F11R2_FB19                       CAN_F11R2_FB19_Msk                /*!< Filter bit 19 */
#define CAN_F11R2_FB20_Pos                   (20U)
#define CAN_F11R2_FB20_Msk                   (0x1UL << CAN_F11R2_FB20_Pos)      /*!< 0x00100000 */
#define CAN_F11R2_FB20                       CAN_F11R2_FB20_Msk                /*!< Filter bit 20 */
#define CAN_F11R2_FB21_Pos                   (21U)
#define CAN_F11R2_FB21_Msk                   (0x1UL << CAN_F11R2_FB21_Pos)      /*!< 0x00200000 */
#define CAN_F11R2_FB21                       CAN_F11R2_FB21_Msk                /*!< Filter bit 21 */
#define CAN_F11R2_FB22_Pos                   (22U)
#define CAN_F11R2_FB22_Msk                   (0x1UL << CAN_F11R2_FB22_Pos)      /*!< 0x00400000 */
#define CAN_F11R2_FB22                       CAN_F11R2_FB22_Msk                /*!< Filter bit 22 */
#define CAN_F11R2_FB23_Pos                   (23U)
#define CAN_F11R2_FB23_Msk                   (0x1UL << CAN_F11R2_FB23_Pos)      /*!< 0x00800000 */
#define CAN_F11R2_FB23                       CAN_F11R2_FB23_Msk                /*!< Filter bit 23 */
#define CAN_F11R2_FB24_Pos                   (24U)
#define CAN_F11R2_FB24_Msk                   (0x1UL << CAN_F11R2_FB24_Pos)      /*!< 0x01000000 */
#define CAN_F11R2_FB24                       CAN_F11R2_FB24_Msk                /*!< Filter bit 24 */
#define CAN_F11R2_FB25_Pos                   (25U)
#define CAN_F11R2_FB25_Msk                   (0x1UL << CAN_F11R2_FB25_Pos)      /*!< 0x02000000 */
#define CAN_F11R2_FB25                       CAN_F11R2_FB25_Msk                /*!< Filter bit 25 */
#define CAN_F11R2_FB26_Pos                   (26U)
#define CAN_F11R2_FB26_Msk                   (0x1UL << CAN_F11R2_FB26_Pos)      /*!< 0x04000000 */
#define CAN_F11R2_FB26                       CAN_F11R2_FB26_Msk                /*!< Filter bit 26 */
#define CAN_F11R2_FB27_Pos                   (27U)
#define CAN_F11R2_FB27_Msk                   (0x1UL << CAN_F11R2_FB27_Pos)      /*!< 0x08000000 */
#define CAN_F11R2_FB27                       CAN_F11R2_FB27_Msk                /*!< Filter bit 27 */
#define CAN_F11R2_FB28_Pos                   (28U)
#define CAN_F11R2_FB28_Msk                   (0x1UL << CAN_F11R2_FB28_Pos)      /*!< 0x10000000 */
#define CAN_F11R2_FB28                       CAN_F11R2_FB28_Msk                /*!< Filter bit 28 */
#define CAN_F11R2_FB29_Pos                   (29U)
#define CAN_F11R2_FB29_Msk                   (0x1UL << CAN_F11R2_FB29_Pos)      /*!< 0x20000000 */
#define CAN_F11R2_FB29                       CAN_F11R2_FB29_Msk                /*!< Filter bit 29 */
#define CAN_F11R2_FB30_Pos                   (30U)
#define CAN_F11R2_FB30_Msk                   (0x1UL << CAN_F11R2_FB30_Pos)      /*!< 0x40000000 */
#define CAN_F11R2_FB30                       CAN_F11R2_FB30_Msk                /*!< Filter bit 30 */
#define CAN_F11R2_FB31_Pos                   (31U)
#define CAN_F11R2_FB31_Msk                   (0x1UL << CAN_F11R2_FB31_Pos)      /*!< 0x80000000 */
#define CAN_F11R2_FB31                       CAN_F11R2_FB31_Msk                /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F12R2 register  ******************/
#define CAN_F12R2_FB0_Pos                    (0U)
#define CAN_F12R2_FB0_Msk                    (0x1UL << CAN_F12R2_FB0_Pos)       /*!< 0x00000001 */
#define CAN_F12R2_FB0                        CAN_F12R2_FB0_Msk                 /*!< Filter bit 0 */
#define CAN_F12R2_FB1_Pos                    (1U)
#define CAN_F12R2_FB1_Msk                    (0x1UL << CAN_F12R2_FB1_Pos)       /*!< 0x00000002 */
#define CAN_F12R2_FB1                        CAN_F12R2_FB1_Msk                 /*!< Filter bit 1 */
#define CAN_F12R2_FB2_Pos                    (2U)
#define CAN_F12R2_FB2_Msk                    (0x1UL << CAN_F12R2_FB2_Pos)       /*!< 0x00000004 */
#define CAN_F12R2_FB2                        CAN_F12R2_FB2_Msk                 /*!< Filter bit 2 */
#define CAN_F12R2_FB3_Pos                    (3U)
#define CAN_F12R2_FB3_Msk                    (0x1UL << CAN_F12R2_FB3_Pos)       /*!< 0x00000008 */
#define CAN_F12R2_FB3                        CAN_F12R2_FB3_Msk                 /*!< Filter bit 3 */
#define CAN_F12R2_FB4_Pos                    (4U)
#define CAN_F12R2_FB4_Msk                    (0x1UL << CAN_F12R2_FB4_Pos)       /*!< 0x00000010 */
#define CAN_F12R2_FB4                        CAN_F12R2_FB4_Msk                 /*!< Filter bit 4 */
#define CAN_F12R2_FB5_Pos                    (5U)
#define CAN_F12R2_FB5_Msk                    (0x1UL << CAN_F12R2_FB5_Pos)       /*!< 0x00000020 */
#define CAN_F12R2_FB5                        CAN_F12R2_FB5_Msk                 /*!< Filter bit 5 */
#define CAN_F12R2_FB6_Pos                    (6U)
#define CAN_F12R2_FB6_Msk                    (0x1UL << CAN_F12R2_FB6_Pos)       /*!< 0x00000040 */
#define CAN_F12R2_FB6                        CAN_F12R2_FB6_Msk                 /*!< Filter bit 6 */
#define CAN_F12R2_FB7_Pos                    (7U)
#define CAN_F12R2_FB7_Msk                    (0x1UL << CAN_F12R2_FB7_Pos)       /*!< 0x00000080 */
#define CAN_F12R2_FB7                        CAN_F12R2_FB7_Msk                 /*!< Filter bit 7 */
#define CAN_F12R2_FB8_Pos                    (8U)
#define CAN_F12R2_FB8_Msk                    (0x1UL << CAN_F12R2_FB8_Pos)       /*!< 0x00000100 */
#define CAN_F12R2_FB8                        CAN_F12R2_FB8_Msk                 /*!< Filter bit 8 */
#define CAN_F12R2_FB9_Pos                    (9U)
#define CAN_F12R2_FB9_Msk                    (0x1UL << CAN_F12R2_FB9_Pos)       /*!< 0x00000200 */
#define CAN_F12R2_FB9                        CAN_F12R2_FB9_Msk                 /*!< Filter bit 9 */
#define CAN_F12R2_FB10_Pos                   (10U)
#define CAN_F12R2_FB10_Msk                   (0x1UL << CAN_F12R2_FB10_Pos)      /*!< 0x00000400 */
#define CAN_F12R2_FB10                       CAN_F12R2_FB10_Msk                /*!< Filter bit 10 */
#define CAN_F12R2_FB11_Pos                   (11U)
#define CAN_F12R2_FB11_Msk                   (0x1UL << CAN_F12R2_FB11_Pos)      /*!< 0x00000800 */
#define CAN_F12R2_FB11                       CAN_F12R2_FB11_Msk                /*!< Filter bit 11 */
#define CAN_F12R2_FB12_Pos                   (12U)
#define CAN_F12R2_FB12_Msk                   (0x1UL << CAN_F12R2_FB12_Pos)      /*!< 0x00001000 */
#define CAN_F12R2_FB12                       CAN_F12R2_FB12_Msk                /*!< Filter bit 12 */
#define CAN_F12R2_FB13_Pos                   (13U)
#define CAN_F12R2_FB13_Msk                   (0x1UL << CAN_F12R2_FB13_Pos)      /*!< 0x00002000 */
#define CAN_F12R2_FB13                       CAN_F12R2_FB13_Msk                /*!< Filter bit 13 */
#define CAN_F12R2_FB14_Pos                   (14U)
#define CAN_F12R2_FB14_Msk                   (0x1UL << CAN_F12R2_FB14_Pos)      /*!< 0x00004000 */
#define CAN_F12R2_FB14                       CAN_F12R2_FB14_Msk                /*!< Filter bit 14 */
#define CAN_F12R2_FB15_Pos                   (15U)
#define CAN_F12R2_FB15_Msk                   (0x1UL << CAN_F12R2_FB15_Pos)      /*!< 0x00008000 */
#define CAN_F12R2_FB15                       CAN_F12R2_FB15_Msk                /*!< Filter bit 15 */
#define CAN_F12R2_FB16_Pos                   (16U)
#define CAN_F12R2_FB16_Msk                   (0x1UL << CAN_F12R2_FB16_Pos)      /*!< 0x00010000 */
#define CAN_F12R2_FB16                       CAN_F12R2_FB16_Msk                /*!< Filter bit 16 */
#define CAN_F12R2_FB17_Pos                   (17U)
#define CAN_F12R2_FB17_Msk                   (0x1UL << CAN_F12R2_FB17_Pos)      /*!< 0x00020000 */
#define CAN_F12R2_FB17                       CAN_F12R2_FB17_Msk                /*!< Filter bit 17 */
#define CAN_F12R2_FB18_Pos                   (18U)
#define CAN_F12R2_FB18_Msk                   (0x1UL << CAN_F12R2_FB18_Pos)      /*!< 0x00040000 */
#define CAN_F12R2_FB18                       CAN_F12R2_FB18_Msk                /*!< Filter bit 18 */
#define CAN_F12R2_FB19_Pos                   (19U)
#define CAN_F12R2_FB19_Msk                   (0x1UL << CAN_F12R2_FB19_Pos)      /*!< 0x00080000 */
#define CAN_F12R2_FB19                       CAN_F12R2_FB19_Msk                /*!< Filter bit 19 */
#define CAN_F12R2_FB20_Pos                   (20U)
#define CAN_F12R2_FB20_Msk                   (0x1UL << CAN_F12R2_FB20_Pos)      /*!< 0x00100000 */
#define CAN_F12R2_FB20                       CAN_F12R2_FB20_Msk                /*!< Filter bit 20 */
#define CAN_F12R2_FB21_Pos                   (21U)
#define CAN_F12R2_FB21_Msk                   (0x1UL << CAN_F12R2_FB21_Pos)      /*!< 0x00200000 */
#define CAN_F12R2_FB21                       CAN_F12R2_FB21_Msk                /*!< Filter bit 21 */
#define CAN_F12R2_FB22_Pos                   (22U)
#define CAN_F12R2_FB22_Msk                   (0x1UL << CAN_F12R2_FB22_Pos)      /*!< 0x00400000 */
#define CAN_F12R2_FB22                       CAN_F12R2_FB22_Msk                /*!< Filter bit 22 */
#define CAN_F12R2_FB23_Pos                   (23U)
#define CAN_F12R2_FB23_Msk                   (0x1UL << CAN_F12R2_FB23_Pos)      /*!< 0x00800000 */
#define CAN_F12R2_FB23                       CAN_F12R2_FB23_Msk                /*!< Filter bit 23 */
#define CAN_F12R2_FB24_Pos                   (24U)
#define CAN_F12R2_FB24_Msk                   (0x1UL << CAN_F12R2_FB24_Pos)      /*!< 0x01000000 */
#define CAN_F12R2_FB24                       CAN_F12R2_FB24_Msk                /*!< Filter bit 24 */
#define CAN_F12R2_FB25_Pos                   (25U)
#define CAN_F12R2_FB25_Msk                   (0x1UL << CAN_F12R2_FB25_Pos)      /*!< 0x02000000 */
#define CAN_F12R2_FB25                       CAN_F12R2_FB25_Msk                /*!< Filter bit 25 */
#define CAN_F12R2_FB26_Pos                   (26U)
#define CAN_F12R2_FB26_Msk                   (0x1UL << CAN_F12R2_FB26_Pos)      /*!< 0x04000000 */
#define CAN_F12R2_FB26                       CAN_F12R2_FB26_Msk                /*!< Filter bit 26 */
#define CAN_F12R2_FB27_Pos                   (27U)
#define CAN_F12R2_FB27_Msk                   (0x1UL << CAN_F12R2_FB27_Pos)      /*!< 0x08000000 */
#define CAN_F12R2_FB27                       CAN_F12R2_FB27_Msk                /*!< Filter bit 27 */
#define CAN_F12R2_FB28_Pos                   (28U)
#define CAN_F12R2_FB28_Msk                   (0x1UL << CAN_F12R2_FB28_Pos)      /*!< 0x10000000 */
#define CAN_F12R2_FB28                       CAN_F12R2_FB28_Msk                /*!< Filter bit 28 */
#define CAN_F12R2_FB29_Pos                   (29U)
#define CAN_F12R2_FB29_Msk                   (0x1UL << CAN_F12R2_FB29_Pos)      /*!< 0x20000000 */
#define CAN_F12R2_FB29                       CAN_F12R2_FB29_Msk                /*!< Filter bit 29 */
#define CAN_F12R2_FB30_Pos                   (30U)
#define CAN_F12R2_FB30_Msk                   (0x1UL << CAN_F12R2_FB30_Pos)      /*!< 0x40000000 */
#define CAN_F12R2_FB30                       CAN_F12R2_FB30_Msk                /*!< Filter bit 30 */
#define CAN_F12R2_FB31_Pos                   (31U)
#define CAN_F12R2_FB31_Msk                   (0x1UL << CAN_F12R2_FB31_Pos)      /*!< 0x80000000 */
#define CAN_F12R2_FB31                       CAN_F12R2_FB31_Msk                /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F13R2 register  ******************/
#define CAN_F13R2_FB0_Pos                    (0U)
#define CAN_F13R2_FB0_Msk                    (0x1UL << CAN_F13R2_FB0_Pos)       /*!< 0x00000001 */
#define CAN_F13R2_FB0                        CAN_F13R2_FB0_Msk                 /*!< Filter bit 0 */
#define CAN_F13R2_FB1_Pos                    (1U)
#define CAN_F13R2_FB1_Msk                    (0x1UL << CAN_F13R2_FB1_Pos)       /*!< 0x00000002 */
#define CAN_F13R2_FB1                        CAN_F13R2_FB1_Msk                 /*!< Filter bit 1 */
#define CAN_F13R2_FB2_Pos                    (2U)
#define CAN_F13R2_FB2_Msk                    (0x1UL << CAN_F13R2_FB2_Pos)       /*!< 0x00000004 */
#define CAN_F13R2_FB2                        CAN_F13R2_FB2_Msk                 /*!< Filter bit 2 */
#define CAN_F13R2_FB3_Pos                    (3U)
#define CAN_F13R2_FB3_Msk                    (0x1UL << CAN_F13R2_FB3_Pos)       /*!< 0x00000008 */
#define CAN_F13R2_FB3                        CAN_F13R2_FB3_Msk                 /*!< Filter bit 3 */
#define CAN_F13R2_FB4_Pos                    (4U)
#define CAN_F13R2_FB4_Msk                    (0x1UL << CAN_F13R2_FB4_Pos)       /*!< 0x00000010 */
#define CAN_F13R2_FB4                        CAN_F13R2_FB4_Msk                 /*!< Filter bit 4 */
#define CAN_F13R2_FB5_Pos                    (5U)
#define CAN_F13R2_FB5_Msk                    (0x1UL << CAN_F13R2_FB5_Pos)       /*!< 0x00000020 */
#define CAN_F13R2_FB5                        CAN_F13R2_FB5_Msk                 /*!< Filter bit 5 */
#define CAN_F13R2_FB6_Pos                    (6U)
#define CAN_F13R2_FB6_Msk                    (0x1UL << CAN_F13R2_FB6_Pos)       /*!< 0x00000040 */
#define CAN_F13R2_FB6                        CAN_F13R2_FB6_Msk                 /*!< Filter bit 6 */
#define CAN_F13R2_FB7_Pos                    (7U)
#define CAN_F13R2_FB7_Msk                    (0x1UL << CAN_F13R2_FB7_Pos)       /*!< 0x00000080 */
#define CAN_F13R2_FB7                        CAN_F13R2_FB7_Msk                 /*!< Filter bit 7 */
#define CAN_F13R2_FB8_Pos                    (8U)
#define CAN_F13R2_FB8_Msk                    (0x1UL << CAN_F13R2_FB8_Pos)       /*!< 0x00000100 */
#define CAN_F13R2_FB8                        CAN_F13R2_FB8_Msk                 /*!< Filter bit 8 */
#define CAN_F13R2_FB9_Pos                    (9U)
#define CAN_F13R2_FB9_Msk                    (0x1UL << CAN_F13R2_FB9_Pos)       /*!< 0x00000200 */
#define CAN_F13R2_FB9                        CAN_F13R2_FB9_Msk                 /*!< Filter bit 9 */
#define CAN_F13R2_FB10_Pos                   (10U)
#define CAN_F13R2_FB10_Msk                   (0x1UL << CAN_F13R2_FB10_Pos)      /*!< 0x00000400 */
#define CAN_F13R2_FB10                       CAN_F13R2_FB10_Msk                /*!< Filter bit 10 */
#define CAN_F13R2_FB11_Pos                   (11U)
#define CAN_F13R2_FB11_Msk                   (0x1UL << CAN_F13R2_FB11_Pos)      /*!< 0x00000800 */
#define CAN_F13R2_FB11                       CAN_F13R2_FB11_Msk                /*!< Filter bit 11 */
#define CAN_F13R2_FB12_Pos                   (12U)
#define CAN_F13R2_FB12_Msk                   (0x1UL << CAN_F13R2_FB12_Pos)      /*!< 0x00001000 */
#define CAN_F13R2_FB12                       CAN_F13R2_FB12_Msk                /*!< Filter bit 12 */
#define CAN_F13R2_FB13_Pos                   (13U)
#define CAN_F13R2_FB13_Msk                   (0x1UL << CAN_F13R2_FB13_Pos)      /*!< 0x00002000 */
#define CAN_F13R2_FB13                       CAN_F13R2_FB13_Msk                /*!< Filter bit 13 */
#define CAN_F13R2_FB14_Pos                   (14U)
#define CAN_F13R2_FB14_Msk                   (0x1UL << CAN_F13R2_FB14_Pos)      /*!< 0x00004000 */
#define CAN_F13R2_FB14                       CAN_F13R2_FB14_Msk                /*!< Filter bit 14 */
#define CAN_F13R2_FB15_Pos                   (15U)
#define CAN_F13R2_FB15_Msk                   (0x1UL << CAN_F13R2_FB15_Pos)      /*!< 0x00008000 */
#define CAN_F13R2_FB15                       CAN_F13R2_FB15_Msk                /*!< Filter bit 15 */
#define CAN_F13R2_FB16_Pos                   (16U)
#define CAN_F13R2_FB16_Msk                   (0x1UL << CAN_F13R2_FB16_Pos)      /*!< 0x00010000 */
#define CAN_F13R2_FB16                       CAN_F13R2_FB16_Msk                /*!< Filter bit 16 */
#define CAN_F13R2_FB17_Pos                   (17U)
#define CAN_F13R2_FB17_Msk                   (0x1UL << CAN_F13R2_FB17_Pos)      /*!< 0x00020000 */
#define CAN_F13R2_FB17                       CAN_F13R2_FB17_Msk                /*!< Filter bit 17 */
#define CAN_F13R2_FB18_Pos                   (18U)
#define CAN_F13R2_FB18_Msk                   (0x1UL << CAN_F13R2_FB18_Pos)      /*!< 0x00040000 */
#define CAN_F13R2_FB18                       CAN_F13R2_FB18_Msk                /*!< Filter bit 18 */
#define CAN_F13R2_FB19_Pos                   (19U)
#define CAN_F13R2_FB19_Msk                   (0x1UL << CAN_F13R2_FB19_Pos)      /*!< 0x00080000 */
#define CAN_F13R2_FB19                       CAN_F13R2_FB19_Msk                /*!< Filter bit 19 */
#define CAN_F13R2_FB20_Pos                   (20U)
#define CAN_F13R2_FB20_Msk                   (0x1UL << CAN_F13R2_FB20_Pos)      /*!< 0x00100000 */
#define CAN_F13R2_FB20                       CAN_F13R2_FB20_Msk                /*!< Filter bit 20 */
#define CAN_F13R2_FB21_Pos                   (21U)
#define CAN_F13R2_FB21_Msk                   (0x1UL << CAN_F13R2_FB21_Pos)      /*!< 0x00200000 */
#define CAN_F13R2_FB21                       CAN_F13R2_FB21_Msk                /*!< Filter bit 21 */
#define CAN_F13R2_FB22_Pos                   (22U)
#define CAN_F13R2_FB22_Msk                   (0x1UL << CAN_F13R2_FB22_Pos)      /*!< 0x00400000 */
#define CAN_F13R2_FB22                       CAN_F13R2_FB22_Msk                /*!< Filter bit 22 */
#define CAN_F13R2_FB23_Pos                   (23U)
#define CAN_F13R2_FB23_Msk                   (0x1UL << CAN_F13R2_FB23_Pos)      /*!< 0x00800000 */
#define CAN_F13R2_FB23                       CAN_F13R2_FB23_Msk                /*!< Filter bit 23 */
#define CAN_F13R2_FB24_Pos                   (24U)
#define CAN_F13R2_FB24_Msk                   (0x1UL << CAN_F13R2_FB24_Pos)      /*!< 0x01000000 */
#define CAN_F13R2_FB24                       CAN_F13R2_FB24_Msk                /*!< Filter bit 24 */
#define CAN_F13R2_FB25_Pos                   (25U)
#define CAN_F13R2_FB25_Msk                   (0x1UL << CAN_F13R2_FB25_Pos)      /*!< 0x02000000 */
#define CAN_F13R2_FB25                       CAN_F13R2_FB25_Msk                /*!< Filter bit 25 */
#define CAN_F13R2_FB26_Pos                   (26U)
#define CAN_F13R2_FB26_Msk                   (0x1UL << CAN_F13R2_FB26_Pos)      /*!< 0x04000000 */
#define CAN_F13R2_FB26                       CAN_F13R2_FB26_Msk                /*!< Filter bit 26 */
#define CAN_F13R2_FB27_Pos                   (27U)
#define CAN_F13R2_FB27_Msk                   (0x1UL << CAN_F13R2_FB27_Pos)      /*!< 0x08000000 */
#define CAN_F13R2_FB27                       CAN_F13R2_FB27_Msk                /*!< Filter bit 27 */
#define CAN_F13R2_FB28_Pos                   (28U)
#define CAN_F13R2_FB28_Msk                   (0x1UL << CAN_F13R2_FB28_Pos)      /*!< 0x10000000 */
#define CAN_F13R2_FB28                       CAN_F13R2_FB28_Msk                /*!< Filter bit 28 */
#define CAN_F13R2_FB29_Pos                   (29U)
#define CAN_F13R2_FB29_Msk                   (0x1UL << CAN_F13R2_FB29_Pos)      /*!< 0x20000000 */
#define CAN_F13R2_FB29                       CAN_F13R2_FB29_Msk                /*!< Filter bit 29 */
#define CAN_F13R2_FB30_Pos                   (30U)
#define CAN_F13R2_FB30_Msk                   (0x1UL << CAN_F13R2_FB30_Pos)      /*!< 0x40000000 */
#define CAN_F13R2_FB30                       CAN_F13R2_FB30_Msk                /*!< Filter bit 30 */
#define CAN_F13R2_FB31_Pos                   (31U)
#define CAN_F13R2_FB31_Msk                   (0x1UL << CAN_F13R2_FB31_Pos)      /*!< 0x80000000 */
#define CAN_F13R2_FB31                       CAN_F13R2_FB31_Msk                /*!< Filter bit 31 */

/******************************************************************************/
/*                                                                            */
/*                         Reset and Clock Control                            */
/*                                                                            */
/******************************************************************************/

/********************  Bit definition for RCC_CR register  ********************/
#define RCC_CR_HSION_Pos                     (0U)
#define RCC_CR_HSION_Msk                     (0x1UL << RCC_CR_HSION_Pos)        /*!< 0x00000001 */
#define RCC_CR_HSION                         RCC_CR_HSION_Msk                  /*!< Internal High Speed clock enable */
#define RCC_CR_HSIRDY_Pos                    (1U)
#define RCC_CR_HSIRDY_Msk                    (0x1UL << RCC_CR_HSIRDY_Pos)       /*!< 0x00000002 */
#define RCC_CR_HSIRDY                        RCC_CR_HSIRDY_Msk                 /*!< Internal High Speed clock ready flag */
#define RCC_CR_HSITRIM_Pos                   (3U)
#define RCC_CR_HSITRIM_Msk                   (0x1FUL << RCC_CR_HSITRIM_Pos)     /*!< 0x000000F8 */
#define RCC_CR_HSITRIM                       RCC_CR_HSITRIM_Msk                /*!< Internal High Speed clock trimming */
#define RCC_CR_HSICAL_Pos                    (8U)
#define RCC_CR_HSICAL_Msk                    (0xFFUL << RCC_CR_HSICAL_Pos)      /*!< 0x0000FF00 */
#define RCC_CR_HSICAL                        RCC_CR_HSICAL_Msk                 /*!< Internal High Speed clock Calibration */
#define RCC_CR_HSEON_Pos                     (16U)
#define RCC_CR_HSEON_Msk                     (0x1UL << RCC_CR_HSEON_Pos)        /*!< 0x00010000 */
#define RCC_CR_HSEON                         RCC_CR_HSEON_Msk                  /*!< External High Speed clock enable */
#define RCC_CR_HSERDY_Pos                    (17U)
#define RCC_CR_HSERDY_Msk                    (0x1UL << RCC_CR_HSERDY_Pos)       /*!< 0x00020000 */
#define RCC_CR_HSERDY                        RCC_CR_HSERDY_Msk                 /*!< External High Speed clock ready flag */
#define RCC_CR_HSEBYP_Pos                    (18U)
#define RCC_CR_HSEBYP_Msk                    (0x1UL << RCC_CR_HSEBYP_Pos)       /*!< 0x00040000 */
#define RCC_CR_HSEBYP                        RCC_CR_HSEBYP_Msk                 /*!< External High Speed clock Bypass */
#define RCC_CR_CSSON_Pos                     (19U)
#define RCC_CR_CSSON_Msk                     (0x1UL << RCC_CR_CSSON_Pos)        /*!< 0x00080000 */
#define RCC_CR_CSSON                         RCC_CR_CSSON_Msk                  /*!< Clock Security System enable */
#define RCC_CR_PLLON_Pos                     (24U)
#define RCC_CR_PLLON_Msk                     (0x1UL << RCC_CR_PLLON_Pos)        /*!< 0x01000000 */
#define RCC_CR_PLLON                         RCC_CR_PLLON_Msk                  /*!< PLL enable */
#define RCC_CR_PLLRDY_Pos                    (25U)
#define RCC_CR_PLLRDY_Msk                    (0x1UL << RCC_CR_PLLRDY_Pos)       /*!< 0x02000000 */
#define RCC_CR_PLLRDY                        RCC_CR_PLLRDY_Msk                 /*!< PLL clock ready flag */


/*******************  Bit definition for RCC_CFGR register  *******************/
/*!< SW configuration */
#define RCC_CFGR_SW_Pos                      (0U)
#define RCC_CFGR_SW_Msk                      (0x3UL << RCC_CFGR_SW_Pos)         /*!< 0x00000003 */
#define RCC_CFGR_SW                          RCC_CFGR_SW_Msk                   /*!< SW[1:0] bits (System clock Switch) */
#define RCC_CFGR_SW_0                        (0x1UL << RCC_CFGR_SW_Pos)         /*!< 0x00000001 */
#define RCC_CFGR_SW_1                        (0x2UL << RCC_CFGR_SW_Pos)         /*!< 0x00000002 */

#define RCC_CFGR_SW_HSI                      0x00000000U                       /*!< HSI selected as system clock */
#define RCC_CFGR_SW_HSE                      0x00000001U                       /*!< HSE selected as system clock */
#define RCC_CFGR_SW_PLL                      0x00000002U                       /*!< PLL selected as system clock */

/*!< SWS configuration */
#define RCC_CFGR_SWS_Pos                     (2U)
#define RCC_CFGR_SWS_Msk                     (0x3UL << RCC_CFGR_SWS_Pos)        /*!< 0x0000000C */
#define RCC_CFGR_SWS                         RCC_CFGR_SWS_Msk                  /*!< SWS[1:0] bits (System Clock Switch Status) */
#define RCC_CFGR_SWS_0                       (0x1UL << RCC_CFGR_SWS_Pos)        /*!< 0x00000004 */
#define RCC_CFGR_SWS_1                       (0x2UL << RCC_CFGR_SWS_Pos)        /*!< 0x00000008 */

#define RCC_CFGR_SWS_HSI                     0x00000000U                       /*!< HSI oscillator used as system clock */
#define RCC_CFGR_SWS_HSE                     0x00000004U                       /*!< HSE oscillator used as system clock */
#define RCC_CFGR_SWS_PLL                     0x00000008U                       /*!< PLL used as system clock */

/*!< HPRE configuration */
#define RCC_CFGR_HPRE_Pos                    (4U)
#define RCC_CFGR_HPRE_Msk                    (0xFUL << RCC_CFGR_HPRE_Pos)       /*!< 0x000000F0 */
#define RCC_CFGR_HPRE                        RCC_CFGR_HPRE_Msk                 /*!< HPRE[3:0] bits (AHB prescaler) */
#define RCC_CFGR_HPRE_0                      (0x1UL << RCC_CFGR_HPRE_Pos)       /*!< 0x00000010 */
#define RCC_CFGR_HPRE_1                      (0x2UL << RCC_CFGR_HPRE_Pos)       /*!< 0x00000020 */
#define RCC_CFGR_HPRE_2                      (0x4UL << RCC_CFGR_HPRE_Pos)       /*!< 0x00000040 */
#define RCC_CFGR_HPRE_3                      (0x8UL << RCC_CFGR_HPRE_Pos)       /*!< 0x00000080 */

#define RCC_CFGR_HPRE_DIV1                   0x00000000U                       /*!< SYSCLK not divided */
#define RCC_CFGR_HPRE_DIV2                   0x00000080U                       /*!< SYSCLK divided by 2 */
#define RCC_CFGR_HPRE_DIV4                   0x00000090U                       /*!< SYSCLK divided by 4 */
#define RCC_CFGR_HPRE_DIV8                   0x000000A0U                       /*!< SYSCLK divided by 8 */
#define RCC_CFGR_HPRE_DIV16                  0x000000B0U                       /*!< SYSCLK divided by 16 */
#define RCC_CFGR_HPRE_DIV64                  0x000000C0U                       /*!< SYSCLK divided by 64 */
#define RCC_CFGR_HPRE_DIV128                 0x000000D0U                       /*!< SYSCLK divided by 128 */
#define RCC_CFGR_HPRE_DIV256                 0x000000E0U                       /*!< SYSCLK divided by 256 */
#define RCC_CFGR_HPRE_DIV512                 0x000000F0U                       /*!< SYSCLK divided by 512 */

/*!< PPRE1 configuration */
#define RCC_CFGR_PPRE1_Pos                   (8U)
#define RCC_CFGR_PPRE1_Msk                   (0x7UL << RCC_CFGR_PPRE1_Pos)      /*!< 0x00000700 */
#define RCC_CFGR_PPRE1                       RCC_CFGR_PPRE1_Msk                /*!< PRE1[2:0] bits (APB1 prescaler) */
#define RCC_CFGR_PPRE1_0                     (0x1UL << RCC_CFGR_PPRE1_Pos)      /*!< 0x00000100 */
#define RCC_CFGR_PPRE1_1                     (0x2UL << RCC_CFGR_PPRE1_Pos)      /*!< 0x00000200 */
#define RCC_CFGR_PPRE1_2                     (0x4UL << RCC_CFGR_PPRE1_Pos)      /*!< 0x00000400 */

#define RCC_CFGR_PPRE1_DIV1                  0x00000000U                       /*!< HCLK not divided */
#define RCC_CFGR_PPRE1_DIV2                  0x00000400U                       /*!< HCLK divided by 2 */
#define RCC_CFGR_PPRE1_DIV4                  0x00000500U                       /*!< HCLK divided by 4 */
#define RCC_CFGR_PPRE1_DIV8                  0x00000600U                       /*!< HCLK divided by 8 */
#define RCC_CFGR_PPRE1_DIV16                 0x00000700U                       /*!< HCLK divided by 16 */

/*!< PPRE2 configuration */
#define RCC_CFGR_PPRE2_Pos                   (11U)
#define RCC_CFGR_PPRE2_Msk                   (0x7UL << RCC_CFGR_PPRE2_Pos)      /*!< 0x00003800 */
#define RCC_CFGR_PPRE2                       RCC_CFGR_PPRE2_Msk                /*!< PRE2[2:0] bits (APB2 prescaler) */
#define RCC_CFGR_PPRE2_0                     (0x1UL << RCC_CFGR_PPRE2_Pos)      /*!< 0x00000800 */
#define RCC_CFGR_PPRE2_1                     (0x2UL << RCC_CFGR_PPRE2_Pos)      /*!< 0x00001000 */
#define RCC_CFGR_PPRE2_2                     (0x4UL << RCC_CFGR_PPRE2_Pos)      /*!< 0x00002000 */

#define RCC_CFGR_PPRE2_DIV1                  0x00000000U                       /*!< HCLK not divided */
#define RCC_CFGR_PPRE2_DIV2                  0x00002000U                       /*!< HCLK divided by 2 */
#define RCC_CFGR_PPRE2_DIV4                  0x00002800U                       /*!< HCLK divided by 4 */
#define RCC_CFGR_PPRE2_DIV8                  0x00003000U                       /*!< HCLK divided by 8 */
#define RCC_CFGR_PPRE2_DIV16                 0x00003800U                       /*!< HCLK divided by 16 */

/*!< ADCPPRE configuration */
#define RCC_CFGR_ADCPRE_Pos                  (14U)
#define RCC_CFGR_ADCPRE_Msk                  (0x3UL << RCC_CFGR_ADCPRE_Pos)     /*!< 0x0000C000 */
#define RCC_CFGR_ADCPRE                      RCC_CFGR_ADCPRE_Msk               /*!< ADCPRE[1:0] bits (ADC prescaler) */
#define RCC_CFGR_ADCPRE_0                    (0x1UL << RCC_CFGR_ADCPRE_Pos)     /*!< 0x00004000 */
#define RCC_CFGR_ADCPRE_1                    (0x2UL << RCC_CFGR_ADCPRE_Pos)     /*!< 0x00008000 */

#define RCC_CFGR_ADCPRE_DIV2                 0x00000000U                       /*!< PCLK2 divided by 2 */
#define RCC_CFGR_ADCPRE_DIV4                 0x00004000U                       /*!< PCLK2 divided by 4 */
#define RCC_CFGR_ADCPRE_DIV6                 0x00008000U                       /*!< PCLK2 divided by 6 */
#define RCC_CFGR_ADCPRE_DIV8                 0x0000C000U                       /*!< PCLK2 divided by 8 */

#define RCC_CFGR_PLLSRC_Pos                  (16U)
#define RCC_CFGR_PLLSRC_Msk                  (0x1UL << RCC_CFGR_PLLSRC_Pos)     /*!< 0x00010000 */
#define RCC_CFGR_PLLSRC                      RCC_CFGR_PLLSRC_Msk               /*!< PLL entry clock source */

#define RCC_CFGR_PLLXTPRE_Pos                (17U)
#define RCC_CFGR_PLLXTPRE_Msk                (0x1UL << RCC_CFGR_PLLXTPRE_Pos)   /*!< 0x00020000 */
#define RCC_CFGR_PLLXTPRE                    RCC_CFGR_PLLXTPRE_Msk             /*!< HSE divider for PLL entry */

/*!< PLLMUL configuration */
#define RCC_CFGR_PLLMULL_Pos                 (18U)
#define RCC_CFGR_PLLMULL_Msk                 (0xFUL << RCC_CFGR_PLLMULL_Pos)    /*!< 0x003C0000 */
#define RCC_CFGR_PLLMULL                     RCC_CFGR_PLLMULL_Msk              /*!< PLLMUL[3:0] bits (PLL multiplication factor) */
#define RCC_CFGR_PLLMULL_0                   (0x1UL << RCC_CFGR_PLLMULL_Pos)    /*!< 0x00040000 */
#define RCC_CFGR_PLLMULL_1                   (0x2UL << RCC_CFGR_PLLMULL_Pos)    /*!< 0x00080000 */
#define RCC_CFGR_PLLMULL_2                   (0x4UL << RCC_CFGR_PLLMULL_Pos)    /*!< 0x00100000 */
#define RCC_CFGR_PLLMULL_3                   (0x8UL << RCC_CFGR_PLLMULL_Pos)    /*!< 0x00200000 */

#define RCC_CFGR_PLLXTPRE_HSE                0x00000000U                      /*!< HSE clock not divided for PLL entry */
#define RCC_CFGR_PLLXTPRE_HSE_DIV2           0x00020000U                      /*!< HSE clock divided by 2 for PLL entry */

#define RCC_CFGR_PLLMULL2                    0x00000000U                       /*!< PLL input clock*2 */
#define RCC_CFGR_PLLMULL3_Pos                (18U)
#define RCC_CFGR_PLLMULL3_Msk                (0x1UL << RCC_CFGR_PLLMULL3_Pos)   /*!< 0x00040000 */
#define RCC_CFGR_PLLMULL3                    RCC_CFGR_PLLMULL3_Msk             /*!< PLL input clock*3 */
#define RCC_CFGR_PLLMULL4_Pos                (19U)
#define RCC_CFGR_PLLMULL4_Msk                (0x1UL << RCC_CFGR_PLLMULL4_Pos)   /*!< 0x00080000 */
#define RCC_CFGR_PLLMULL4                    RCC_CFGR_PLLMULL4_Msk             /*!< PLL input clock*4 */
#define RCC_CFGR_PLLMULL5_Pos                (18U)
#define RCC_CFGR_PLLMULL5_Msk                (0x3UL << RCC_CFGR_PLLMULL5_Pos)   /*!< 0x000C0000 */
#define RCC_CFGR_PLLMULL5                    RCC_CFGR_PLLMULL5_Msk             /*!< PLL input clock*5 */
#define RCC_CFGR_PLLMULL6_Pos                (20U)
#define RCC_CFGR_PLLMULL6_Msk                (0x1UL << RCC_CFGR_PLLMULL6_Pos)   /*!< 0x00100000 */
#define RCC_CFGR_PLLMULL6                    RCC_CFGR_PLLMULL6_Msk             /*!< PLL input clock*6 */
#define RCC_CFGR_PLLMULL7_Pos                (18U)
#define RCC_CFGR_PLLMULL7_Msk                (0x5UL << RCC_CFGR_PLLMULL7_Pos)   /*!< 0x00140000 */
#define RCC_CFGR_PLLMULL7                    RCC_CFGR_PLLMULL7_Msk             /*!< PLL input clock*7 */
#define RCC_CFGR_PLLMULL8_Pos                (19U)
#define RCC_CFGR_PLLMULL8_Msk                (0x3UL << RCC_CFGR_PLLMULL8_Pos)   /*!< 0x00180000 */
#define RCC_CFGR_PLLMULL8                    RCC_CFGR_PLLMULL8_Msk             /*!< PLL input clock*8 */
#define RCC_CFGR_PLLMULL9_Pos                (18U)
#define RCC_CFGR_PLLMULL9_Msk                (0x7UL << RCC_CFGR_PLLMULL9_Pos)   /*!< 0x001C0000 */
#define RCC_CFGR_PLLMULL9                    RCC_CFGR_PLLMULL9_Msk             /*!< PLL input clock*9 */
#define RCC_CFGR_PLLMULL10_Pos               (21U)
#define RCC_CFGR_PLLMULL10_Msk               (0x1UL << RCC_CFGR_PLLMULL10_Pos)  /*!< 0x00200000 */
#define RCC_CFGR_PLLMULL10                   RCC_CFGR_PLLMULL10_Msk            /*!< PLL input clock10 */
#define RCC_CFGR_PLLMULL11_Pos               (18U)
#define RCC_CFGR_PLLMULL11_Msk               (0x9UL << RCC_CFGR_PLLMULL11_Pos)  /*!< 0x00240000 */
#define RCC_CFGR_PLLMULL11                   RCC_CFGR_PLLMULL11_Msk            /*!< PLL input clock*11 */
#define RCC_CFGR_PLLMULL12_Pos               (19U)
#define RCC_CFGR_PLLMULL12_Msk               (0x5UL << RCC_CFGR_PLLMULL12_Pos)  /*!< 0x00280000 */
#define RCC_CFGR_PLLMULL12                   RCC_CFGR_PLLMULL12_Msk            /*!< PLL input clock*12 */
#define RCC_CFGR_PLLMULL13_Pos               (18U)
#define RCC_CFGR_PLLMULL13_Msk               (0xBUL << RCC_CFGR_PLLMULL13_Pos)  /*!< 0x002C0000 */
#define RCC_CFGR_PLLMULL13                   RCC_CFGR_PLLMULL13_Msk            /*!< PLL input clock*13 */
#define RCC_CFGR_PLLMULL14_Pos               (20U)
#define RCC_CFGR_PLLMULL14_Msk               (0x3UL << RCC_CFGR_PLLMULL14_Pos)  /*!< 0x00300000 */
#define RCC_CFGR_PLLMULL14                   RCC_CFGR_PLLMULL14_Msk            /*!< PLL input clock*14 */
#define RCC_CFGR_PLLMULL15_Pos               (18U)
#define RCC_CFGR_PLLMULL15_Msk               (0xDUL << RCC_CFGR_PLLMULL15_Pos)  /*!< 0x00340000 */
#define RCC_CFGR_PLLMULL15                   RCC_CFGR_PLLMULL15_Msk            /*!< PLL input clock*15 */
#define RCC_CFGR_PLLMULL16_Pos               (19U)
#define RCC_CFGR_PLLMULL16_Msk               (0x7UL << RCC_CFGR_PLLMULL16_Pos)  /*!< 0x00380000 */
#define RCC_CFGR_PLLMULL16                   RCC_CFGR_PLLMULL16_Msk            /*!< PLL input clock*16 */
#define RCC_CFGR_USBPRE_Pos                  (22U)
#define RCC_CFGR_USBPRE_Msk                  (0x1UL << RCC_CFGR_USBPRE_Pos)     /*!< 0x00400000 */
#define RCC_CFGR_USBPRE                      RCC_CFGR_USBPRE_Msk               /*!< USB Device prescaler */

/*!< MCO configuration */
#define RCC_CFGR_MCO_Pos                     (24U)
#define RCC_CFGR_MCO_Msk                     (0x7UL << RCC_CFGR_MCO_Pos)        /*!< 0x07000000 */
#define RCC_CFGR_MCO                         RCC_CFGR_MCO_Msk                  /*!< MCO[2:0] bits (Microcontroller Clock Output) */
#define RCC_CFGR_MCO_0                       (0x1UL << RCC_CFGR_MCO_Pos)        /*!< 0x01000000 */
#define RCC_CFGR_MCO_1                       (0x2UL << RCC_CFGR_MCO_Pos)        /*!< 0x02000000 */
#define RCC_CFGR_MCO_2                       (0x4UL << RCC_CFGR_MCO_Pos)        /*!< 0x04000000 */

#define RCC_CFGR_MCO_NOCLOCK                 0x00000000U                        /*!< No clock */
#define RCC_CFGR_MCO_SYSCLK                  0x04000000U                        /*!< System clock selected as MCO source */
#define RCC_CFGR_MCO_HSI                     0x05000000U                        /*!< HSI clock selected as MCO source */
#define RCC_CFGR_MCO_HSE                     0x06000000U                        /*!< HSE clock selected as MCO source  */
#define RCC_CFGR_MCO_PLLCLK_DIV2             0x07000000U                        /*!< PLL clock divided by 2 selected as MCO source */

 /* Reference defines */
 #define RCC_CFGR_MCOSEL                      RCC_CFGR_MCO
 #define RCC_CFGR_MCOSEL_0                    RCC_CFGR_MCO_0
 #define RCC_CFGR_MCOSEL_1                    RCC_CFGR_MCO_1
 #define RCC_CFGR_MCOSEL_2                    RCC_CFGR_MCO_2
 #define RCC_CFGR_MCOSEL_NOCLOCK              RCC_CFGR_MCO_NOCLOCK
 #define RCC_CFGR_MCOSEL_SYSCLK               RCC_CFGR_MCO_SYSCLK
 #define RCC_CFGR_MCOSEL_HSI                  RCC_CFGR_MCO_HSI
 #define RCC_CFGR_MCOSEL_HSE                  RCC_CFGR_MCO_HSE
 #define RCC_CFGR_MCOSEL_PLL_DIV2             RCC_CFGR_MCO_PLLCLK_DIV2

/*!<******************  Bit definition for RCC_CIR register  ********************/
#define RCC_CIR_LSIRDYF_Pos                  (0U)
#define RCC_CIR_LSIRDYF_Msk                  (0x1UL << RCC_CIR_LSIRDYF_Pos)     /*!< 0x00000001 */
#define RCC_CIR_LSIRDYF                      RCC_CIR_LSIRDYF_Msk               /*!< LSI Ready Interrupt flag */
#define RCC_CIR_LSERDYF_Pos                  (1U)
#define RCC_CIR_LSERDYF_Msk                  (0x1UL << RCC_CIR_LSERDYF_Pos)     /*!< 0x00000002 */
#define RCC_CIR_LSERDYF                      RCC_CIR_LSERDYF_Msk               /*!< LSE Ready Interrupt flag */
#define RCC_CIR_HSIRDYF_Pos                  (2U)
#define RCC_CIR_HSIRDYF_Msk                  (0x1UL << RCC_CIR_HSIRDYF_Pos)     /*!< 0x00000004 */
#define RCC_CIR_HSIRDYF                      RCC_CIR_HSIRDYF_Msk               /*!< HSI Ready Interrupt flag */
#define RCC_CIR_HSERDYF_Pos                  (3U)
#define RCC_CIR_HSERDYF_Msk                  (0x1UL << RCC_CIR_HSERDYF_Pos)     /*!< 0x00000008 */
#define RCC_CIR_HSERDYF                      RCC_CIR_HSERDYF_Msk               /*!< HSE Ready Interrupt flag */
#define RCC_CIR_PLLRDYF_Pos                  (4U)
#define RCC_CIR_PLLRDYF_Msk                  (0x1UL << RCC_CIR_PLLRDYF_Pos)     /*!< 0x00000010 */
#define RCC_CIR_PLLRDYF                      RCC_CIR_PLLRDYF_Msk               /*!< PLL Ready Interrupt flag */
#define RCC_CIR_CSSF_Pos                     (7U)
#define RCC_CIR_CSSF_Msk                     (0x1UL << RCC_CIR_CSSF_Pos)        /*!< 0x00000080 */
#define RCC_CIR_CSSF                         RCC_CIR_CSSF_Msk                  /*!< Clock Security System Interrupt flag */
#define RCC_CIR_LSIRDYIE_Pos                 (8U)
#define RCC_CIR_LSIRDYIE_Msk                 (0x1UL << RCC_CIR_LSIRDYIE_Pos)    /*!< 0x00000100 */
#define RCC_CIR_LSIRDYIE                     RCC_CIR_LSIRDYIE_Msk              /*!< LSI Ready Interrupt Enable */
#define RCC_CIR_LSERDYIE_Pos                 (9U)
#define RCC_CIR_LSERDYIE_Msk                 (0x1UL << RCC_CIR_LSERDYIE_Pos)    /*!< 0x00000200 */
#define RCC_CIR_LSERDYIE                     RCC_CIR_LSERDYIE_Msk              /*!< LSE Ready Interrupt Enable */
#define RCC_CIR_HSIRDYIE_Pos                 (10U)
#define RCC_CIR_HSIRDYIE_Msk                 (0x1UL << RCC_CIR_HSIRDYIE_Pos)    /*!< 0x00000400 */
#define RCC_CIR_HSIRDYIE                     RCC_CIR_HSIRDYIE_Msk              /*!< HSI Ready Interrupt Enable */
#define RCC_CIR_HSERDYIE_Pos                 (11U)
#define RCC_CIR_HSERDYIE_Msk                 (0x1UL << RCC_CIR_HSERDYIE_Pos)    /*!< 0x00000800 */
#define RCC_CIR_HSERDYIE                     RCC_CIR_HSERDYIE_Msk              /*!< HSE Ready Interrupt Enable */
#define RCC_CIR_PLLRDYIE_Pos                 (12U)
#define RCC_CIR_PLLRDYIE_Msk                 (0x1UL << RCC_CIR_PLLRDYIE_Pos)    /*!< 0x00001000 */
#define RCC_CIR_PLLRDYIE                     RCC_CIR_PLLRDYIE_Msk              /*!< PLL Ready Interrupt Enable */
#define RCC_CIR_LSIRDYC_Pos                  (16U)
#define RCC_CIR_LSIRDYC_Msk                  (0x1UL << RCC_CIR_LSIRDYC_Pos)     /*!< 0x00010000 */
#define RCC_CIR_LSIRDYC                      RCC_CIR_LSIRDYC_Msk               /*!< LSI Ready Interrupt Clear */
#define RCC_CIR_LSERDYC_Pos                  (17U)
#define RCC_CIR_LSERDYC_Msk                  (0x1UL << RCC_CIR_LSERDYC_Pos)     /*!< 0x00020000 */
#define RCC_CIR_LSERDYC                      RCC_CIR_LSERDYC_Msk               /*!< LSE Ready Interrupt Clear */
#define RCC_CIR_HSIRDYC_Pos                  (18U)
#define RCC_CIR_HSIRDYC_Msk                  (0x1UL << RCC_CIR_HSIRDYC_Pos)     /*!< 0x00040000 */
#define RCC_CIR_HSIRDYC                      RCC_CIR_HSIRDYC_Msk               /*!< HSI Ready Interrupt Clear */
#define RCC_CIR_HSERDYC_Pos                  (19U)
#define RCC_CIR_HSERDYC_Msk                  (0x1UL << RCC_CIR_HSERDYC_Pos)     /*!< 0x00080000 */
#define RCC_CIR_HSERDYC                      RCC_CIR_HSERDYC_Msk               /*!< HSE Ready Interrupt Clear */
#define RCC_CIR_PLLRDYC_Pos                  (20U)
#define RCC_CIR_PLLRDYC_Msk                  (0x1UL << RCC_CIR_PLLRDYC_Pos)     /*!< 0x00100000 */
#define RCC_CIR_PLLRDYC                      RCC_CIR_PLLRDYC_Msk               /*!< PLL Ready Interrupt Clear */
#define RCC_CIR_CSSC_Pos                     (23U)
#define RCC_CIR_CSSC_Msk                     (0x1UL << RCC_CIR_CSSC_Pos)        /*!< 0x00800000 */
#define RCC_CIR_CSSC                         RCC_CIR_CSSC_Msk                  /*!< Clock Security System Interrupt Clear */


/*****************  Bit definition for RCC_APB2RSTR register  *****************/
#define RCC_APB2RSTR_AFIORST_Pos             (0U)
#define RCC_APB2RSTR_AFIORST_Msk             (0x1UL << RCC_APB2RSTR_AFIORST_Pos) /*!< 0x00000001 */
#define RCC_APB2RSTR_AFIORST                 RCC_APB2RSTR_AFIORST_Msk          /*!< Alternate Function I/O reset */
#define RCC_APB2RSTR_IOPARST_Pos             (2U)
#define RCC_APB2RSTR_IOPARST_Msk             (0x1UL << RCC_APB2RSTR_IOPARST_Pos) /*!< 0x00000004 */
#define RCC_APB2RSTR_IOPARST                 RCC_APB2RSTR_IOPARST_Msk          /*!< I/O port A reset */
#define RCC_APB2RSTR_IOPBRST_Pos             (3U)
#define RCC_APB2RSTR_IOPBRST_Msk             (0x1UL << RCC_APB2RSTR_IOPBRST_Pos) /*!< 0x00000008 */
#define RCC_APB2RSTR_IOPBRST                 RCC_APB2RSTR_IOPBRST_Msk          /*!< I/O port B reset */
#define RCC_APB2RSTR_IOPCRST_Pos             (4U)
#define RCC_APB2RSTR_IOPCRST_Msk             (0x1UL << RCC_APB2RSTR_IOPCRST_Pos) /*!< 0x00000010 */
#define RCC_APB2RSTR_IOPCRST                 RCC_APB2RSTR_IOPCRST_Msk          /*!< I/O port C reset */
#define RCC_APB2RSTR_IOPDRST_Pos             (5U)
#define RCC_APB2RSTR_IOPDRST_Msk             (0x1UL << RCC_APB2RSTR_IOPDRST_Pos) /*!< 0x00000020 */
#define RCC_APB2RSTR_IOPDRST                 RCC_APB2RSTR_IOPDRST_Msk          /*!< I/O port D reset */
#define RCC_APB2RSTR_ADC1RST_Pos             (9U)
#define RCC_APB2RSTR_ADC1RST_Msk             (0x1UL << RCC_APB2RSTR_ADC1RST_Pos) /*!< 0x00000200 */
#define RCC_APB2RSTR_ADC1RST                 RCC_APB2RSTR_ADC1RST_Msk          /*!< ADC 1 interface reset */

#define RCC_APB2RSTR_ADC2RST_Pos             (10U)
#define RCC_APB2RSTR_ADC2RST_Msk             (0x1UL << RCC_APB2RSTR_ADC2RST_Pos) /*!< 0x00000400 */
#define RCC_APB2RSTR_ADC2RST                 RCC_APB2RSTR_ADC2RST_Msk          /*!< ADC 2 interface reset */

#define RCC_APB2RSTR_TIM1RST_Pos             (11U)
#define RCC_APB2RSTR_TIM1RST_Msk             (0x1UL << RCC_APB2RSTR_TIM1RST_Pos) /*!< 0x00000800 */
#define RCC_APB2RSTR_TIM1RST                 RCC_APB2RSTR_TIM1RST_Msk          /*!< TIM1 Timer reset */
#define RCC_APB2RSTR_SPI1RST_Pos             (12U)
#define RCC_APB2RSTR_SPI1RST_Msk             (0x1UL << RCC_APB2RSTR_SPI1RST_Pos) /*!< 0x00001000 */
#define RCC_APB2RSTR_SPI1RST                 RCC_APB2RSTR_SPI1RST_Msk          /*!< SPI 1 reset */
#define RCC_APB2RSTR_USART1RST_Pos           (14U)
#define RCC_APB2RSTR_USART1RST_Msk           (0x1UL << RCC_APB2RSTR_USART1RST_Pos) /*!< 0x00004000 */
#define RCC_APB2RSTR_USART1RST               RCC_APB2RSTR_USART1RST_Msk        /*!< USART1 reset */






/*****************  Bit definition for RCC_APB1RSTR register  *****************/
#define RCC_APB1RSTR_TIM2RST_Pos             (0U)
#define RCC_APB1RSTR_TIM2RST_Msk             (0x1UL << RCC_APB1RSTR_TIM2RST_Pos) /*!< 0x00000001 */
#define RCC_APB1RSTR_TIM2RST                 RCC_APB1RSTR_TIM2RST_Msk          /*!< Timer 2 reset */
#define RCC_APB1RSTR_TIM3RST_Pos             (1U)
#define RCC_APB1RSTR_TIM3RST_Msk             (0x1UL << RCC_APB1RSTR_TIM3RST_Pos) /*!< 0x00000002 */
#define RCC_APB1RSTR_TIM3RST                 RCC_APB1RSTR_TIM3RST_Msk          /*!< Timer 3 reset */
#define RCC_APB1RSTR_WWDGRST_Pos             (11U)
#define RCC_APB1RSTR_WWDGRST_Msk             (0x1UL << RCC_APB1RSTR_WWDGRST_Pos) /*!< 0x00000800 */
#define RCC_APB1RSTR_WWDGRST                 RCC_APB1RSTR_WWDGRST_Msk          /*!< Window Watchdog reset */
#define RCC_APB1RSTR_USART2RST_Pos           (17U)
#define RCC_APB1RSTR_USART2RST_Msk           (0x1UL << RCC_APB1RSTR_USART2RST_Pos) /*!< 0x00020000 */
#define RCC_APB1RSTR_USART2RST               RCC_APB1RSTR_USART2RST_Msk        /*!< USART 2 reset */
#define RCC_APB1RSTR_I2C1RST_Pos             (21U)
#define RCC_APB1RSTR_I2C1RST_Msk             (0x1UL << RCC_APB1RSTR_I2C1RST_Pos) /*!< 0x00200000 */
#define RCC_APB1RSTR_I2C1RST                 RCC_APB1RSTR_I2C1RST_Msk          /*!< I2C 1 reset */

#define RCC_APB1RSTR_CAN1RST_Pos             (25U)
#define RCC_APB1RSTR_CAN1RST_Msk             (0x1UL << RCC_APB1RSTR_CAN1RST_Pos) /*!< 0x02000000 */
#define RCC_APB1RSTR_CAN1RST                 RCC_APB1RSTR_CAN1RST_Msk          /*!< CAN1 reset */

#define RCC_APB1RSTR_BKPRST_Pos              (27U)
#define RCC_APB1RSTR_BKPRST_Msk              (0x1UL << RCC_APB1RSTR_BKPRST_Pos) /*!< 0x08000000 */
#define RCC_APB1RSTR_BKPRST                  RCC_APB1RSTR_BKPRST_Msk           /*!< Backup interface reset */
#define RCC_APB1RSTR_PWRRST_Pos              (28U)
#define RCC_APB1RSTR_PWRRST_Msk              (0x1UL << RCC_APB1RSTR_PWRRST_Pos) /*!< 0x10000000 */
#define RCC_APB1RSTR_PWRRST                  RCC_APB1RSTR_PWRRST_Msk           /*!< Power interface reset */


#define RCC_APB1RSTR_USBRST_Pos              (23U)
#define RCC_APB1RSTR_USBRST_Msk              (0x1UL << RCC_APB1RSTR_USBRST_Pos) /*!< 0x00800000 */
#define RCC_APB1RSTR_USBRST                  RCC_APB1RSTR_USBRST_Msk           /*!< USB Device reset */






/******************  Bit definition for RCC_AHBENR register  ******************/
#define RCC_AHBENR_DMA1EN_Pos                (0U)
#define RCC_AHBENR_DMA1EN_Msk                (0x1UL << RCC_AHBENR_DMA1EN_Pos)   /*!< 0x00000001 */
#define RCC_AHBENR_DMA1EN                    RCC_AHBENR_DMA1EN_Msk             /*!< DMA1 clock enable */
#define RCC_AHBENR_SRAMEN_Pos                (2U)
#define RCC_AHBENR_SRAMEN_Msk                (0x1UL << RCC_AHBENR_SRAMEN_Pos)   /*!< 0x00000004 */
#define RCC_AHBENR_SRAMEN                    RCC_AHBENR_SRAMEN_Msk             /*!< SRAM interface clock enable */
#define RCC_AHBENR_FLITFEN_Pos               (4U)
#define RCC_AHBENR_FLITFEN_Msk               (0x1UL << RCC_AHBENR_FLITFEN_Pos)  /*!< 0x00000010 */
#define RCC_AHBENR_FLITFEN                   RCC_AHBENR_FLITFEN_Msk            /*!< FLITF clock enable */
#define RCC_AHBENR_CRCEN_Pos                 (6U)
#define RCC_AHBENR_CRCEN_Msk                 (0x1UL << RCC_AHBENR_CRCEN_Pos)    /*!< 0x00000040 */
#define RCC_AHBENR_CRCEN                     RCC_AHBENR_CRCEN_Msk              /*!< CRC clock enable */




/******************  Bit definition for RCC_APB2ENR register  *****************/
#define RCC_APB2ENR_AFIOEN_Pos               (0U)
#define RCC_APB2ENR_AFIOEN_Msk               (0x1UL << RCC_APB2ENR_AFIOEN_Pos)  /*!< 0x00000001 */
#define RCC_APB2ENR_AFIOEN                   RCC_APB2ENR_AFIOEN_Msk            /*!< Alternate Function I/O clock enable */
#define RCC_APB2ENR_IOPAEN_Pos               (2U)
#define RCC_APB2ENR_IOPAEN_Msk               (0x1UL << RCC_APB2ENR_IOPAEN_Pos)  /*!< 0x00000004 */
#define RCC_APB2ENR_IOPAEN                   RCC_APB2ENR_IOPAEN_Msk            /*!< I/O port A clock enable */
#define RCC_APB2ENR_IOPBEN_Pos               (3U)
#define RCC_APB2ENR_IOPBEN_Msk               (0x1UL << RCC_APB2ENR_IOPBEN_Pos)  /*!< 0x00000008 */
#define RCC_APB2ENR_IOPBEN                   RCC_APB2ENR_IOPBEN_Msk            /*!< I/O port B clock enable */
#define RCC_APB2ENR_IOPCEN_Pos               (4U)
#define RCC_APB2ENR_IOPCEN_Msk               (0x1UL << RCC_APB2ENR_IOPCEN_Pos)  /*!< 0x00000010 */
#define RCC_APB2ENR_IOPCEN                   RCC_APB2ENR_IOPCEN_Msk            /*!< I/O port C clock enable */
#define RCC_APB2ENR_IOPDEN_Pos               (5U)
#define RCC_APB2ENR_IOPDEN_Msk               (0x1UL << RCC_APB2ENR_IOPDEN_Pos)  /*!< 0x00000020 */
#define RCC_APB2ENR_IOPDEN                   RCC_APB2ENR_IOPDEN_Msk            /*!< I/O port D clock enable */
#define RCC_APB2ENR_ADC1EN_Pos               (9U)
#define RCC_APB2ENR_ADC1EN_Msk               (0x1UL << RCC_APB2ENR_ADC1EN_Pos)  /*!< 0x00000200 */
#define RCC_APB2ENR_ADC1EN                   RCC_APB2ENR_ADC1EN_Msk            /*!< ADC 1 interface clock enable */

#define RCC_APB2ENR_ADC2EN_Pos               (10U)
#define RCC_APB2ENR_ADC2EN_Msk               (0x1UL << RCC_APB2ENR_ADC2EN_Pos)  /*!< 0x00000400 */
#define RCC_APB2ENR_ADC2EN                   RCC_APB2ENR_ADC2EN_Msk            /*!< ADC 2 interface clock enable */

#define RCC_APB2ENR_TIM1EN_Pos               (11U)
#define RCC_APB2ENR_TIM1EN_Msk               (0x1UL << RCC_APB2ENR_TIM1EN_Pos)  /*!< 0x00000800 */
#define RCC_APB2ENR_TIM1EN                   RCC_APB2ENR_TIM1EN_Msk            /*!< TIM1 Timer clock enable */
#define RCC_APB2ENR_SPI1EN_Pos               (12U)
#define RCC_APB2ENR_SPI1EN_Msk               (0x1UL << RCC_APB2ENR_SPI1EN_Pos)  /*!< 0x00001000 */
#define RCC_APB2ENR_SPI1EN                   RCC_APB2ENR_SPI1EN_Msk            /*!< SPI 1 clock enable */
#define RCC_APB2ENR_USART1EN_Pos             (14U)
#define RCC_APB2ENR_USART1EN_Msk             (0x1UL << RCC_APB2ENR_USART1EN_Pos) /*!< 0x00004000 */
#define RCC_APB2ENR_USART1EN                 RCC_APB2ENR_USART1EN_Msk          /*!< USART1 clock enable */






/*****************  Bit definition for RCC_APB1ENR register  ******************/
#define RCC_APB1ENR_TIM2EN_Pos               (0U)
#define RCC_APB1ENR_TIM2EN_Msk               (0x1UL << RCC_APB1ENR_TIM2EN_Pos)  /*!< 0x00000001 */
#define RCC_APB1ENR_TIM2EN                   RCC_APB1ENR_TIM2EN_Msk            /*!< Timer 2 clock enabled*/
#define RCC_APB1ENR_TIM3EN_Pos               (1U)
#define RCC_APB1ENR_TIM3EN_Msk               (0x1UL << RCC_APB1ENR_TIM3EN_Pos)  /*!< 0x00000002 */
#define RCC_APB1ENR_TIM3EN                   RCC_APB1ENR_TIM3EN_Msk            /*!< Timer 3 clock enable */
#define RCC_APB1ENR_WWDGEN_Pos               (11U)
#define RCC_APB1ENR_WWDGEN_Msk               (0x1UL << RCC_APB1ENR_WWDGEN_Pos)  /*!< 0x00000800 */
#define RCC_APB1ENR_WWDGEN                   RCC_APB1ENR_WWDGEN_Msk            /*!< Window Watchdog clock enable */
#define RCC_APB1ENR_USART2EN_Pos             (17U)
#define RCC_APB1ENR_USART2EN_Msk             (0x1UL << RCC_APB1ENR_USART2EN_Pos) /*!< 0x00020000 */
#define RCC_APB1ENR_USART2EN                 RCC_APB1ENR_USART2EN_Msk          /*!< USART 2 clock enable */
#define RCC_APB1ENR_I2C1EN_Pos               (21U)
#define RCC_APB1ENR_I2C1EN_Msk               (0x1UL << RCC_APB1ENR_I2C1EN_Pos)  /*!< 0x00200000 */
#define RCC_APB1ENR_I2C1EN                   RCC_APB1ENR_I2C1EN_Msk            /*!< I2C 1 clock enable */

#define RCC_APB1ENR_CAN1EN_Pos               (25U)
#define RCC_APB1ENR_CAN1EN_Msk               (0x1UL << RCC_APB1ENR_CAN1EN_Pos)  /*!< 0x02000000 */
#define RCC_APB1ENR_CAN1EN                   RCC_APB1ENR_CAN1EN_Msk            /*!< CAN1 clock enable */

#define RCC_APB1ENR_BKPEN_Pos                (27U)
#define RCC_APB1ENR_BKPEN_Msk                (0x1UL << RCC_APB1ENR_BKPEN_Pos)   /*!< 0x08000000 */
#define RCC_APB1ENR_BKPEN                    RCC_APB1ENR_BKPEN_Msk             /*!< Backup interface clock enable */
#define RCC_APB1ENR_PWREN_Pos                (28U)
#define RCC_APB1ENR_PWREN_Msk                (0x1UL << RCC_APB1ENR_PWREN_Pos)   /*!< 0x10000000 */
#define RCC_APB1ENR_PWREN                    RCC_APB1ENR_PWREN_Msk             /*!< Power interface clock enable */


#define RCC_APB1ENR_USBEN_Pos                (23U)
#define RCC_APB1ENR_USBEN_Msk                (0x1UL << RCC_APB1ENR_USBEN_Pos)   /*!< 0x00800000 */
#define RCC_APB1ENR_USBEN                    RCC_APB1ENR_USBEN_Msk             /*!< USB Device clock enable */






/*******************  Bit definition for RCC_BDCR register  *******************/
#define RCC_BDCR_LSEON_Pos                   (0U)
#define RCC_BDCR_LSEON_Msk                   (0x1UL << RCC_BDCR_LSEON_Pos)      /*!< 0x00000001 */
#define RCC_BDCR_LSEON                       RCC_BDCR_LSEON_Msk                /*!< External Low Speed oscillator enable */
#define RCC_BDCR_LSERDY_Pos                  (1U)
#define RCC_BDCR_LSERDY_Msk                  (0x1UL << RCC_BDCR_LSERDY_Pos)     /*!< 0x00000002 */
#define RCC_BDCR_LSERDY                      RCC_BDCR_LSERDY_Msk               /*!< External Low Speed oscillator Ready */
#define RCC_BDCR_LSEBYP_Pos                  (2U)
#define RCC_BDCR_LSEBYP_Msk                  (0x1UL << RCC_BDCR_LSEBYP_Pos)     /*!< 0x00000004 */
#define RCC_BDCR_LSEBYP                      RCC_BDCR_LSEBYP_Msk               /*!< External Low Speed oscillator Bypass */

#define RCC_BDCR_RTCSEL_Pos                  (8U)
#define RCC_BDCR_RTCSEL_Msk                  (0x3UL << RCC_BDCR_RTCSEL_Pos)     /*!< 0x00000300 */
#define RCC_BDCR_RTCSEL                      RCC_BDCR_RTCSEL_Msk               /*!< RTCSEL[1:0] bits (RTC clock source selection) */
#define RCC_BDCR_RTCSEL_0                    (0x1UL << RCC_BDCR_RTCSEL_Pos)     /*!< 0x00000100 */
#define RCC_BDCR_RTCSEL_1                    (0x2UL << RCC_BDCR_RTCSEL_Pos)     /*!< 0x00000200 */

/*!< RTC configuration */
#define RCC_BDCR_RTCSEL_NOCLOCK              0x00000000U                       /*!< No clock */
#define RCC_BDCR_RTCSEL_LSE                  0x00000100U                       /*!< LSE oscillator clock used as RTC clock */
#define RCC_BDCR_RTCSEL_LSI                  0x00000200U                       /*!< LSI oscillator clock used as RTC clock */
#define RCC_BDCR_RTCSEL_HSE                  0x00000300U                       /*!< HSE oscillator clock divided by 128 used as RTC clock */

#define RCC_BDCR_RTCEN_Pos                   (15U)
#define RCC_BDCR_RTCEN_Msk                   (0x1UL << RCC_BDCR_RTCEN_Pos)      /*!< 0x00008000 */
#define RCC_BDCR_RTCEN                       RCC_BDCR_RTCEN_Msk                /*!< RTC clock enable */
#define RCC_BDCR_BDRST_Pos                   (16U)
#define RCC_BDCR_BDRST_Msk                   (0x1UL << RCC_BDCR_BDRST_Pos)      /*!< 0x00010000 */
#define RCC_BDCR_BDRST                       RCC_BDCR_BDRST_Msk                /*!< Backup domain software reset  */

/*******************  Bit definition for RCC_CSR register  ********************/
#define RCC_CSR_LSION_Pos                    (0U)
#define RCC_CSR_LSION_Msk                    (0x1UL << RCC_CSR_LSION_Pos)       /*!< 0x00000001 */
#define RCC_CSR_LSION                        RCC_CSR_LSION_Msk                 /*!< Internal Low Speed oscillator enable */
#define RCC_CSR_LSIRDY_Pos                   (1U)
#define RCC_CSR_LSIRDY_Msk                   (0x1UL << RCC_CSR_LSIRDY_Pos)      /*!< 0x00000002 */
#define RCC_CSR_LSIRDY                       RCC_CSR_LSIRDY_Msk                /*!< Internal Low Speed oscillator Ready */
#define RCC_CSR_RMVF_Pos                     (24U)
#define RCC_CSR_RMVF_Msk                     (0x1UL << RCC_CSR_RMVF_Pos)        /*!< 0x01000000 */
#define RCC_CSR_RMVF                         RCC_CSR_RMVF_Msk                  /*!< Remove reset flag */
#define RCC_CSR_PINRSTF_Pos                  (26U)
#define RCC_CSR_PINRSTF_Msk                  (0x1UL << RCC_CSR_PINRSTF_Pos)     /*!< 0x04000000 */
#define RCC_CSR_PINRSTF                      RCC_CSR_PINRSTF_Msk               /*!< PIN reset flag */
#define RCC_CSR_PORRSTF_Pos                  (27U)
#define RCC_CSR_PORRSTF_Msk                  (0x1UL << RCC_CSR_PORRSTF_Pos)     /*!< 0x08000000 */
#define RCC_CSR_PORRSTF                      RCC_CSR_PORRSTF_Msk               /*!< POR/PDR reset flag */
#define RCC_CSR_SFTRSTF_Pos                  (28U)
#define RCC_CSR_SFTRSTF_Msk                  (0x1UL << RCC_CSR_SFTRSTF_Pos)     /*!< 0x10000000 */
#define RCC_CSR_SFTRSTF                      RCC_CSR_SFTRSTF_Msk               /*!< Software Reset flag */
#define RCC_CSR_IWDGRSTF_Pos                 (29U)
#define RCC_CSR_IWDGRSTF_Msk                 (0x1UL << RCC_CSR_IWDGRSTF_Pos)    /*!< 0x20000000 */
#define RCC_CSR_IWDGRSTF                     RCC_CSR_IWDGRSTF_Msk              /*!< Independent Watchdog reset flag */
#define RCC_CSR_WWDGRSTF_Pos                 (30U)
#define RCC_CSR_WWDGRSTF_Msk                 (0x1UL << RCC_CSR_WWDGRSTF_Pos)    /*!< 0x40000000 */
#define RCC_CSR_WWDGRSTF                     RCC_CSR_WWDGRSTF_Msk              /*!< Window watchdog reset flag */
#define RCC_CSR_LPWRRSTF_Pos                 (31U)
#define RCC_CSR_LPWRRSTF_Msk                 (0x1UL << RCC_CSR_LPWRRSTF_Pos)    /*!< 0x80000000 */
#define RCC_CSR_LPWRRSTF                     RCC_CSR_LPWRRSTF_Msk              /*!< Low-Power reset flag */

#endif /* STM32F103X8_H_ */
