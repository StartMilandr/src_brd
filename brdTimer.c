#include "brdTimer.h"

void BRD_Timer_InitStructDef(TIMER_CntInitTypeDef *TimerInitStruct, uint32_t Pll_Mul, uint32_t freq)
{
  TIMER_CntStructInit (TimerInitStruct);
  TimerInitStruct->TIMER_IniCounter       = 0;                                      // ��������� �������� �������
  TimerInitStruct->TIMER_Prescaler        = Pll_Mul;                                      // ������������ �������
  TimerInitStruct->TIMER_Period           = CALC_PERIOD(SystemCoreClock, freq, 1);  // ������ ������� 1KHz (�� HSI = 8���) = 8000
  TimerInitStruct->TIMER_CounterMode      = TIMER_CntMode_ClkFixedDir;              // ����� �����
  TimerInitStruct->TIMER_CounterDirection = TIMER_CntDir_Up;                        // ����������� �����
}


void BRD_Timer_Init(Timer_Obj *TimerObj, TIMER_CntInitTypeDef *TimerInitStruct)
{
  // ��������� ������������ �������
  RST_CLK_PCLKcmd (TimerObj->ClockMask, ENABLE);

  // ��������������� �������
  TIMER_DeInit (TimerObj->TIMERx);

  // ����� ������������ �������� ������� ������� 
  TIMER_BRGInit (TimerObj->TIMERx, TimerObj->ClockBRG);

 // ������������� �������
  TIMER_CntInit (TimerObj->TIMERx, TimerInitStruct);
}

void BRD_Timer_Start(Timer_Obj *TimerObj)
{
  TIMER_Cmd (TimerObj->TIMERx, ENABLE);
}

void BRD_Timer_InitIRQ(Timer_Obj *TimerObj, uint32_t priority)
{
  // ����� ���������� ����������
  TIMER_ITConfig (TimerObj->TIMERx, TimerObj->EventIT, ENABLE);
  
  // ���������� ���������� ���������� ���������� �� �������
  NVIC_SetPriority (TimerObj->IRQn, 1);

  // ��������� ���������� ���������� �� ������� 
  NVIC_EnableIRQ (TimerObj->IRQn);
}

//// ���������� ���������� ���������� �� ������� TIMER1
//void Timer1_IRQHandler (void)
//{
//  // ����� ���������� �� ������� TIMER1
//  TIMER_ClearITPendingBit (MDR_TIMER1, TIMER_STATUS_CNT_ARR);
//}
