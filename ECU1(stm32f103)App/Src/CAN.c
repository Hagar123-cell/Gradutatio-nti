/*
 * CAN.c
 *
 *  Created on: Nov 24, 2023
 *      Author: El_Amir Tech
 */

//#include "stm32f103x6.h"
//#include "Common_Macros.h"
#include "CAN.h"
#include "Common_Macros.h"
/******************************************************************************/
/*           				 CAN Initialization 							  */
/******************************************************************************/

void CAN_Init(const CAN_InitTypeDef* Init_Config_Ptr )
{
	uint8_t i;

	/* We need to check if we can use the RCC (Clock Configuration from CubeIDE or adjust these to be 8mhz) */
	/* Configure GPIO with AF9, CAN1 connected to APB1 with 45MHz clock
	 * CAN1_RX  -> PA11 (IN)
	 * CAN1_TX  -> PA12 (OUT)
	 * ***********************/

	/* Enable port A clock */
	RCC->APB2ENR|= RCC_APB2ENR_IOPAEN;

	/* RX: PA11-> Input Floating
	 * TX: PA12-> Alt_Func Push-Pull 50Mhz speed */

	GPIOA->CRH &= ~(GPIO_CRH_MODE11 | GPIO_CRH_MODE12 | GPIO_CRH_CNF11 | GPIO_CRH_CNF12);
	GPIOA->CRH |= (GPIO_CRH_CNF11_0 | GPIO_CRH_CNF12_1 | GPIO_CRH_MODE12);
	//	GPIOA->CRH |= (GPIO_CRH_CNF11_1 | GPIO_CRH_CNF12_1 | GPIO_CRH_MODE12);

	/******************************************************************************/

	/* Configure CAN1 */

	/* Enable CAN1 clock */
	RCC->APB1ENR = RCC_APB1ENR_CAN1EN;

	/* Request to enter initialization mode */
	SET_BIT(CAN1->MCR, CAN_MCR_INRQ);

	/* Wait initialization acknowledge */
	while ((CAN1->MSR & CAN_MSR_INAK) == 0U);

	/* Exit from sleep mode */
	CLEAR_BIT(CAN1->MCR, CAN_MCR_SLEEP);

	/* Check Sleep mode leave acknowledge */
	while ((CAN1->MSR & CAN_MSR_SLAK) != 0U);

	/* Set the time triggered communication mode */
	if (Init_Config_Ptr->TimeTriggeredMode == ENABLE)
	{
		SET_BIT(CAN1->MCR, CAN_MCR_TTCM);
	}
	else
	{
		CLEAR_BIT(CAN1->MCR, CAN_MCR_TTCM);
	}

	/* Set the automatic bus-off management */
	if (Init_Config_Ptr->AutoBusOff == ENABLE)
	{
		SET_BIT(CAN1->MCR, CAN_MCR_ABOM);
	}
	else
	{
		CLEAR_BIT(CAN1->MCR, CAN_MCR_ABOM);
	}

	/* Set the automatic wake-up mode */
	if (Init_Config_Ptr->AutoWakeUp == ENABLE)
	{
		SET_BIT(CAN1->MCR, CAN_MCR_AWUM);
	}
	else
	{
		CLEAR_BIT(CAN1->MCR, CAN_MCR_AWUM);
	}

	/* Set the automatic retransmission */
	if (Init_Config_Ptr->AutoRetransmission == ENABLE)
	{
		CLEAR_BIT(CAN1->MCR, CAN_MCR_NART);
	}
	else
	{
		SET_BIT(CAN1->MCR, CAN_MCR_NART);
	}

	/* Set the receive FIFO locked mode */
	if (Init_Config_Ptr->ReceiveFifoLocked == ENABLE)
	{
		SET_BIT(CAN1->MCR, CAN_MCR_RFLM);
	}
	else
	{
		CLEAR_BIT(CAN1->MCR, CAN_MCR_RFLM);
	}

	/* Set the transmit FIFO priority */
	if (Init_Config_Ptr->TransmitFifoPriority == ENABLE)
	{
		SET_BIT(CAN1->MCR, CAN_MCR_TXFP);
	}
	else
	{
		CLEAR_BIT(CAN1->MCR, CAN_MCR_TXFP);
	}


	/* Set the bit timing register */
	CAN1->BTR = (uint32_t)(Init_Config_Ptr->Mode           |
			Init_Config_Ptr->SyncJumpWidth  |
			Init_Config_Ptr->TimeSeg1       |
			Init_Config_Ptr->TimeSeg2       |
			(Init_Config_Ptr->Prescaler - 1U));

	/* Initializing sTxMailBox & Filter Bank Registers with Zero */
	for(i=0;i<3;i++)
	{
		CAN1->sTxMailBox[i].TDHR = 0;
		CAN1->sTxMailBox[i].TDLR = 0;
		CAN1->sTxMailBox[i].TDTR = 0;
		CAN1->sTxMailBox[i].TIR  = 0;
	}
	for(i=0;i<14;i++)
	{
		CAN1->sFilterRegister[i].FR1 = 0;
		CAN1->sFilterRegister[i].FR2 = 0;
	}

	/* Switch to Normal Mode */
	CAN1->MCR &= ~(CAN_MCR_INRQ | CAN_MCR_SLEEP);
	CLEAR_BIT(CAN1->MCR, CAN_MCR_INRQ);

	/* Wait till you exit Init mode */
	while ((CAN1->MSR & CAN_MSR_INAK) != 0U);

}

/******************************************************************************/
/*                            CAN Filtration                                  */
/******************************************************************************/

void CAN_RX_Filter_Init(const CAN_FilterTypeDef* filterData)
{
	uint32_t FR1_REG = 0, FR2_REG = 0;


	/* Request to enter initialization mode */
	SET_BIT(CAN1->MCR, CAN_MCR_INRQ);

	/* Wait initialization acknowledge */
	while ((CAN1->MSR & CAN_MSR_INAK) == 0U);

	/* Exit from sleep mode */
	CLEAR_BIT(CAN1->MCR, CAN_MCR_SLEEP);

	/* Check Sleep mode leave acknowledge */
	while ((CAN1->MSR & CAN_MSR_SLAK) != 0U);

	/* Set Filter init mode(FINIT=1) */
	SET_BIT(CAN1->FMR, CAN_FMR_FINIT);
	/* deactivate filter */
	CLEAR_BIT( CAN1->FA1R ,1 << filterData->FilterBank);

	/* configure filter bank mode */
	CLEAR_BIT(CAN1->FM1R, 1 << filterData->FilterBank);
	CAN1->FM1R |= (filterData->FilterMode)<<(filterData->FilterBank);

	/* configure filter bank scale */
	CLEAR_BIT(CAN1->FS1R, 1 << filterData->FilterBank);
	CAN1->FS1R |= (filterData->FilterScale) << (filterData->FilterBank);

	/* assign fifo for the filter*/
	CLEAR_BIT(CAN1->FFA1R, 1 << filterData->FilterFIFOAssignment);
	CAN1->FFA1R |= (filterData->FilterFIFOAssignment) << (filterData->FilterBank);

	/* assign FR1*/
	FR1_REG = (filterData ->FilterIdHigh << 21) | (filterData->FilterIdLow);
	CAN1->sFilterRegister[filterData->FilterBank].FR1 = FR1_REG;

	/* assign FR2*/
	FR2_REG = (filterData ->FilterMaskIdHigh << 21) | (filterData->FilterMaskIdLow);
	CAN1->sFilterRegister[filterData->FilterBank].FR2 = FR2_REG;

	/* Activate filters */
	SET_BIT( CAN1->FA1R ,1 << filterData->FilterBank);

	/* ACTIVE Filter mode(FINIT=0) */
	CLEAR_BIT( CAN1->FMR, CAN_FMR_FINIT);


	/* Switch to Normal Mode */
	CAN1->MCR &= ~(CAN_MCR_INRQ | CAN_MCR_SLEEP);

	/* Wait till you exit Init mode */
	while ((CAN1->MSR & CAN_MSR_INAK) != 0U);


}

/******************************************************************************/
/*                            CAN Transmit                                    */
/******************************************************************************/

//void CAN_TX(uint32_t ID, uint8_t DLC, uint8_t* payload)
//{
//	uint32_t pTxMailbox, no_free_txMailBox = 0;
//	uint32_t transmitmailbox;
//	uint32_t tsr = READ_REG(CAN1->TSR);
//	CAN_TxHeaderTypeDef pHeader;
//
//	pHeader.StdId = ID;
//	pHeader.RTR = CAN_RTR_DATA;
//	pHeader.IDE = CAN_ID_STD;
//	pHeader.DLC = DLC;
//	pHeader.TransmitGlobalTime = DISABLE;
//	pHeader.ExtId = 0;
//
//	/* (++) HAL_CAN_GetTxMailboxesFreeLevel() to get the number of free Tx mailboxes. */
//	/* Check Tx Mailbox 0 status */
//	if ((CAN1->TSR & CAN_TSR_TME0) != 0U)
//	{
//		no_free_txMailBox++;
//	}
//
//	/* Check Tx Mailbox 1 status */
//	if ((CAN1->TSR & CAN_TSR_TME1) != 0U)
//	{
//		no_free_txMailBox++;
//	}
//
//	/* Check Tx Mailbox 2 status */
//	if ((CAN1->TSR & CAN_TSR_TME2) != 0U)
//	{
//		no_free_txMailBox++;
//	}
//
//	if(no_free_txMailBox)
//	{
//		if (pHeader.IDE == CAN_ID_STD)
//		{
//			/* Check that all the Tx mailboxes are not full */
//			if (((tsr & CAN_TSR_TME0) != 0U) ||
//					((tsr & CAN_TSR_TME1) != 0U) ||
//					((tsr & CAN_TSR_TME2) != 0U))
//			{
//				/* Select an empty transmit mailbox */
//				transmitmailbox = (tsr & CAN_TSR_CODE) >> CAN_TSR_CODE_Pos;
//
//				/* Store the Tx mailbox */
//				pTxMailbox = (uint32_t)1 << transmitmailbox;
//
//				/* Set up the Id */
//				if (pHeader.IDE == CAN_ID_STD)
//				{
//					CAN1->sTxMailBox[transmitmailbox].TIR = ((pHeader.StdId << CAN_TI0R_STID_Pos) |
//							pHeader.RTR);
//				}
//				else
//				{
//					CAN1->sTxMailBox[transmitmailbox].TIR = ((pHeader.ExtId << CAN_TI0R_EXID_Pos) |
//							pHeader.IDE |
//							pHeader.RTR);
//				}
//
//				/* Set up the DLC */
//				CAN1->sTxMailBox[transmitmailbox].TDTR = (pHeader.DLC);
//
//				/* Set up the Transmit Global Time mode */
//				if (pHeader.TransmitGlobalTime == ENABLE)
//				{
//					SET_BIT(CAN1->sTxMailBox[transmitmailbox].TDTR, CAN_TDT0R_TGT);
//				}
//
//				/* Set up the data field */
//				WRITE_REG(CAN1->sTxMailBox[transmitmailbox].TDHR,
//						((uint32_t)payload[7] << CAN_TDH0R_DATA7_Pos) |
//						((uint32_t)payload[6] << CAN_TDH0R_DATA6_Pos) |
//						((uint32_t)payload[5] << CAN_TDH0R_DATA5_Pos) |
//						((uint32_t)payload[4] << CAN_TDH0R_DATA4_Pos));
//				WRITE_REG(CAN1->sTxMailBox[transmitmailbox].TDLR,
//						((uint32_t)payload[3] << CAN_TDL0R_DATA3_Pos) |
//						((uint32_t)payload[2] << CAN_TDL0R_DATA2_Pos) |
//						((uint32_t)payload[1] << CAN_TDL0R_DATA1_Pos) |
//						((uint32_t)payload[0] << CAN_TDL0R_DATA0_Pos));
//
//				/* Request transmission */
//				SET_BIT(CAN1->sTxMailBox[transmitmailbox].TIR, CAN_TI0R_TXRQ);
//
//				/* Waiting till Transmission is complete */
//
//				while((CAN1->TSR & (pTxMailbox << CAN_TSR_TME0_Pos)) != (pTxMailbox << CAN_TSR_TME0_Pos));
//			}
//		}
//	}
//}


/******************************************************************************/
/*                            CAN Receive                                     */
/******************************************************************************/

void CAN_RX(uint32_t* ID, uint8_t* DLC, uint8_t* payload)
{

	CAN_RxHeaderTypeDef pHeader;

	while(HAL_CAN_GetRxFifoFillLevel(CAN_FILTER_FIFO0 ) == 0);

	if(HAL_CAN_GetRxMessage(CAN_FILTER_FIFO0, &pHeader, payload) != HAL_OK)
	{
		while(1)
		{

		}
	}
	*ID = pHeader.StdId;
	*DLC = pHeader.DLC;

}

HAL_StatusTypeDef HAL_CAN_GetRxMessage(uint32_t RxFifo, CAN_RxHeaderTypeDef *pHeader, uint8_t aData[])
{

	/* Check the Rx FIFO */
	if (RxFifo == CAN_RX_FIFO0) /* Rx element is assigned to Rx FIFO 0 */
	{
		/* Check that the Rx FIFO 0 is not empty */
		if ((CAN1->RF0R & CAN_RF0R_FMP0) == 0U)
		{


			return HAL_ERROR;
		}
	}
	else /* Rx element is assigned to Rx FIFO 1 */
	{
		/* Check that the Rx FIFO 1 is not empty */
		if ((CAN1->RF1R & CAN_RF1R_FMP1) == 0U)
		{

			return HAL_ERROR;
		}
	}
	/* Get the header */
	pHeader->IDE = CAN_RI0R_IDE & CAN1->sFIFOMailBox[RxFifo].RIR;
	if (pHeader->IDE == CAN_ID_STD)
	{
		pHeader->StdId = (CAN_RI0R_STID & CAN1->sFIFOMailBox[RxFifo].RIR) >> CAN_TI0R_STID_Pos;
	}
	else
	{
		pHeader->ExtId = ((CAN_RI0R_EXID | CAN_RI0R_STID) & CAN1->sFIFOMailBox[RxFifo].RIR) >> CAN_RI0R_EXID_Pos;
	}
	pHeader->RTR = (CAN_RI0R_RTR & CAN1->sFIFOMailBox[RxFifo].RIR);
	pHeader->DLC = (CAN_RDT0R_DLC & CAN1->sFIFOMailBox[RxFifo].RDTR) >> CAN_RDT0R_DLC_Pos;
	pHeader->FilterMatchIndex = (CAN_RDT0R_FMI & CAN1->sFIFOMailBox[RxFifo].RDTR) >> CAN_RDT0R_FMI_Pos;
	pHeader->Timestamp = (CAN_RDT0R_TIME & CAN1->sFIFOMailBox[RxFifo].RDTR) >> CAN_RDT0R_TIME_Pos;

	/* Get the data */
	aData[0] = (uint8_t)((CAN_RDL0R_DATA0 & CAN1->sFIFOMailBox[RxFifo].RDLR) >> CAN_RDL0R_DATA0_Pos);
	aData[1] = (uint8_t)((CAN_RDL0R_DATA1 & CAN1->sFIFOMailBox[RxFifo].RDLR) >> CAN_RDL0R_DATA1_Pos);
	aData[2] = (uint8_t)((CAN_RDL0R_DATA2 & CAN1->sFIFOMailBox[RxFifo].RDLR) >> CAN_RDL0R_DATA2_Pos);
	aData[3] = (uint8_t)((CAN_RDL0R_DATA3 & CAN1->sFIFOMailBox[RxFifo].RDLR) >> CAN_RDL0R_DATA3_Pos);
	aData[4] = (uint8_t)((CAN_RDH0R_DATA4 & CAN1->sFIFOMailBox[RxFifo].RDHR) >> CAN_RDH0R_DATA4_Pos);
	aData[5] = (uint8_t)((CAN_RDH0R_DATA5 & CAN1->sFIFOMailBox[RxFifo].RDHR) >> CAN_RDH0R_DATA5_Pos);
	aData[6] = (uint8_t)((CAN_RDH0R_DATA6 & CAN1->sFIFOMailBox[RxFifo].RDHR) >> CAN_RDH0R_DATA6_Pos);
	aData[7] = (uint8_t)((CAN_RDH0R_DATA7 & CAN1->sFIFOMailBox[RxFifo].RDHR) >> CAN_RDH0R_DATA7_Pos);

	/* Release the FIFO */
	if (RxFifo == CAN_RX_FIFO0) /* Rx element is assigned to Rx FIFO 0 */
	{
		/* Release RX FIFO 0 */
		SET_BIT(CAN1->RF0R, CAN_RF0R_RFOM0);
	}
	else /* Rx element is assigned to Rx FIFO 1 */
	{
		/* Release RX FIFO 1 */
		SET_BIT(CAN1->RF1R, CAN_RF1R_RFOM1);
	}

	/* Return function status */
	return HAL_OK;


}

uint32_t HAL_CAN_GetRxFifoFillLevel(uint32_t RxFifo)
{
	uint32_t filllevel = 0U;


	if (RxFifo == CAN_RX_FIFO0)
	{
		filllevel = CAN1->RF0R & 				CAN_RF0R_FMP0;

	}
	else
		/* RxFifo == CAN_RX_FIFO1 */
	{
		filllevel = CAN1->RF1R & 				CAN_RF1R_FMP1;
	}


	/* Return Rx FIFO fill level */
	return filllevel;
}


///* Original TX CubeIDE generated */
void CAN_TX(uint32_t ID, uint8_t DLC, uint8_t* payload)
{
	uint32_t pTxMailbox, no_free_txMailBox = 0;
	CAN_TxHeaderTypeDef pHeader;

	pHeader.StdId = ID;
	pHeader.RTR = CAN_RTR_DATA;
	pHeader.IDE = CAN_ID_STD;
	pHeader.DLC = DLC;

	/* (++) HAL_CAN_GetTxMailboxesFreeLevel() to get the number of free Tx
         mailboxes. */
	no_free_txMailBox = HAL_CAN_GetTxMailboxesFreeLevel();

	if(no_free_txMailBox)
	{
		/* (++) HAL_CAN_AddTxMessage() to request transmission of a new
				message. */
		if(HAL_CAN_AddTxMessage(&pHeader, payload, &pTxMailbox) != HAL_OK)
		{
			while(1);
		}


		/*	(++) HAL_CAN_IsTxMessagePending() to check if a message is pending
		                 in a Tx mailbox. */

		/* Waiting till Transmission is complete */

		while(HAL_CAN_IsTxMessagePending(pTxMailbox));


	}
}

uint32_t HAL_CAN_GetTxMailboxesFreeLevel(void)
{
	uint32_t freelevel = 0U;

	/* Check Tx Mailbox 0 status */
	if ((CAN1->TSR & CAN_TSR_TME0) != 0U)
	{
		freelevel++;
	}

	/* Check Tx Mailbox 1 status */
	if ((CAN1->TSR & CAN_TSR_TME1) != 0U)
	{
		freelevel++;
	}

	/* Check Tx Mailbox 2 status */
	if ((CAN1->TSR & CAN_TSR_TME2) != 0U)
	{
		freelevel++;
	}


	/* Return Tx Mailboxes free level */
	return freelevel;
}

HAL_StatusTypeDef HAL_CAN_AddTxMessage(CAN_TxHeaderTypeDef *pHeader, uint8_t aData[], uint32_t *pTxMailbox)
{
	uint32_t transmitmailbox;

	uint32_t tsr = READ_REG(CAN1->TSR);

	/* Check that all the Tx mailboxes are not full */
	if (((tsr & CAN_TSR_TME0) != 0U) ||
			((tsr & CAN_TSR_TME1) != 0U) ||
			((tsr & CAN_TSR_TME2) != 0U))
	{
		/* Select an empty transmit mailbox */
		transmitmailbox = (tsr & CAN_TSR_CODE) >> CAN_TSR_CODE_Pos;

		/* Check transmit mailbox value */
		if (transmitmailbox > 2U)
		{
			return HAL_ERROR;
		}

		/* Store the Tx mailbox */
		*pTxMailbox = (uint32_t)1 << transmitmailbox;

		/* Set up the Id */
		if (pHeader->IDE == CAN_ID_STD)
		{
			CAN1->sTxMailBox[transmitmailbox].TIR = ((pHeader->StdId << CAN_TI0R_STID_Pos) |
					pHeader->RTR);
		}
		else
		{
			CAN1->sTxMailBox[transmitmailbox].TIR = ((pHeader->ExtId << CAN_TI0R_EXID_Pos) |
					pHeader->IDE |
					pHeader->RTR);
		}

		/* Set up the DLC */
		CAN1->sTxMailBox[transmitmailbox].TDTR = (pHeader->DLC);

		/* Set up the Transmit Global Time mode */
		if (pHeader->TransmitGlobalTime == ENABLE)
		{
			SET_BIT(CAN1->sTxMailBox[transmitmailbox].TDTR, CAN_TDT0R_TGT);
		}

		/* Set up the data field */
		WRITE_REG(CAN1->sTxMailBox[transmitmailbox].TDHR,
				((uint32_t)aData[7] << CAN_TDH0R_DATA7_Pos) |
				((uint32_t)aData[6] << CAN_TDH0R_DATA6_Pos) |
				((uint32_t)aData[5] << CAN_TDH0R_DATA5_Pos) |
				((uint32_t)aData[4] << CAN_TDH0R_DATA4_Pos));
		WRITE_REG(CAN1->sTxMailBox[transmitmailbox].TDLR,
				((uint32_t)aData[3] << CAN_TDL0R_DATA3_Pos) |
				((uint32_t)aData[2] << CAN_TDL0R_DATA2_Pos) |
				((uint32_t)aData[1] << CAN_TDL0R_DATA1_Pos) |
				((uint32_t)aData[0] << CAN_TDL0R_DATA0_Pos));

		/* Request transmission */
		SET_BIT(CAN1->sTxMailBox[transmitmailbox].TIR, CAN_TI0R_TXRQ);

		/* Return function status */
		return HAL_OK;
	}
	else
	{
		return HAL_ERROR;
	}

}

uint32_t HAL_CAN_IsTxMessagePending(uint32_t TxMailboxes)
{
	uint32_t status = 0U;

	/* Check pending transmission request on the selected Tx Mailboxes */
	if ((CAN1->TSR & (TxMailboxes << CAN_TSR_TME0_Pos)) != (TxMailboxes << CAN_TSR_TME0_Pos))
	{
		status = 1U;
	}
	/* Return status */
	return status;
}
