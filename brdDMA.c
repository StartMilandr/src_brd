#include <MDR32F9Qx_port.h>
#include <MDR32F9Qx_rst_clk.h>

#include "brdDMA.h"
#include "brdDef.h"

void BRD_DMA_Init(void)
{
  // ��������� ������������ ������ DMA
  //RST_CLK_PCLKcmd (BRD_DMA_CLOCK_SELECT, ENABLE); - ��������� ��� ����� ������ DMA ��� ���������� ������������ �� SSP1, SSP2

  // ��������������� DMA
  DMA_DeInit();	
  
  // ����� ���������� �� DMA
  NVIC_ClearPendingIRQ (DMA_IRQn);  
}  

// ������������� ������ DMA
void BRD_DMA_Init_Channel (uint32_t DMA_Channel, DMA_ChannelInitTypeDef*  pDMAChannelInitStruct)
{
  // ������������� ������ DMA,
	DMA_Init(DMA_Channel, pDMAChannelInitStruct);

  // ���������� ���������� ���������� ���������� �� DMA
  NVIC_SetPriority (DMA_IRQn, 1);

  // ��������� ���������� ���������� �� DMA
  NVIC_EnableIRQ (DMA_IRQn); 
	
  DMA_Cmd(DMA_Channel, ENABLE);
}

//// �������� - ���������� ���������� �� DMA
//void DMA_IRQHandler (void)
//{
//  // ������������ ������ ����� �������-�������� ��������������
//  DMA_Init (DMA_Channel, &DMAChannelInitStruct);
//  NVIC_ClearPendingIRQ (DMA_IRQn);
//}	

extern DMA_CtrlDataTypeDef DMA_ControlTable[DMA_Channels_Number * (1 + DMA_AlternateData)];

void BRD_DMA_Read_ChannelCtrl(uint32_t DMA_Channel, uint32_t *dmaControl)
{
	*dmaControl = DMA_ControlTable[DMA_Channel].DMA_Control;
}

void BRD_DMA_Write_ChannelCtrl(uint32_t DMA_Channel, uint32_t dmaControl)
{
	DMA_ControlTable[DMA_Channel].DMA_Control = dmaControl;
}

//void BRD_DMA_Read_ChannelCtrlRec(uint32_t DMA_Channel, DMA_CtrlDataTypeDef *chanTable)
//{
//	chanTable->DMA_SourceEndAddr = DMA_ControlTable[DMA_Channel].DMA_SourceEndAddr;
//	chanTable->DMA_DestEndAddr   = DMA_ControlTable[DMA_Channel].DMA_DestEndAddr;
//	chanTable->DMA_Control       = DMA_ControlTable[DMA_Channel].DMA_Control;
//}

//void BRD_DMA_Write_ChannelCtrlRec(uint32_t DMA_Channel, uint32_t *chanTable)
//{
//	DMA_ControlTable[DMA_Channel].DMA_SourceEndAddr = chanTable->DMA_SourceEndAddr;
//	DMA_ControlTable[DMA_Channel].DMA_DestEndAddr   = chanTable->DMA_DestEndAddr;
//	DMA_ControlTable[DMA_Channel].DMA_Control       = chanTable->DMA_Control;
//}



