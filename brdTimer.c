#include "brdTimer.h"

void BRD_Timer_InitStructDef(TIMER_CntInitTypeDef *TimerInitStruct)
{
  TIMER_CntStructInit (TimerInitStruct);
  TimerInitStruct->TIMER_IniCounter       = 0;                          // ��������� �������� �������
  TimerInitStruct->TIMER_Prescaler        = 0xFFFF;                     // ������������ �������
  TimerInitStruct->TIMER_Period           = 0x4C4;                      // ������ �������
  TimerInitStruct->TIMER_CounterMode      = TIMER_CntMode_ClkFixedDir;  // ����� �����
  TimerInitStruct->TIMER_CounterDirection = TIMER_CntDir_Up;            // ����������� �����
}


void BRD_Timer_Init(Timer_Obj *TimerObj, TIMER_CntInitTypeDef *TimerInitStruct)
{
  // ��������� ������������ ������� TIMER1
  RST_CLK_PCLKcmd (TimerObj->ClockMask, ENABLE);

  // ��������������� ������� TIMER1
  TIMER_DeInit (TimerObj->TIMERx);

  // ����� ������������ �������� ������� ������� TIMER1
  TIMER_BRGInit (TimerObj->TIMERx, TimerObj->ClockBRG);

 // ������������� ������� TIMER1
  TIMER_CntInit (TimerObj->TIMERx, TimerInitStruct);

  // ����� ���������� ����������
  TIMER_ITConfig (TimerObj->TIMERx, TimerObj->EventIT, ENABLE);

  // ��������� ������� TIMER1
  TIMER_Cmd (TimerObj->TIMERx, ENABLE);

  // ���������� ���������� ���������� ���������� �� ������� TIMER1
  NVIC_SetPriority (TimerObj->IRQn, 1);

  // ��������� ���������� ���������� �� ������� TIMER1
  NVIC_EnableIRQ (TimerObj->IRQn);
}

//// ���������� ���������� ���������� �� ������� TIMER1
//void Timer1_IRQHandler (void)
//{
//  // ����� ���������� �� ������� TIMER1
//  TIMER_ClearITPendingBit (MDR_TIMER1, TIMER_STATUS_CNT_ARR);
//}
