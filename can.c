/*
 * can.c
 *
 *  Created on: Nov 24, 2023
 *      Author: Ahmed Yasser
 */

#include "can.h"
#include "stdint.h"


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

void CAN_RX(uint32_t* ID, uint8_t* DLC, uint8_t* payload)
{

	CAN_RxHeaderTypeDef pHeader;

	while(HAL_CAN_GetRxFifoFillLevel(CAN_FILTER_FIFO0 ) == 0);

	if(HAL_CAN_GetRxMessage(CAN_FILTER_FIFO0, &pHeader, payload) != HAL_OK);
	{
		while(1)
		{

		}
	}
	*ID = pHeader.StdId;
	*DLC = pHeader.DLC;

}
