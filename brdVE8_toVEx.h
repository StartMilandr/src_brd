#ifndef _BRD_VE8_TO_VE_X_H
#define _BRD_VE8_TO_VE_X_H

#ifdef USE_BOARD_VE_8

//  Clock 
  #define RST_CLK_PCLKcmd    CLKCTRL_PER0_CLKcmd

  //  #define RST_CLK_CPU_PLLmul1   8
  //  #define RST_CLK_CPU_PLLmul2   8
  #define RST_CLK_CPU_PLLmul3   3
  #define RST_CLK_CPU_PLLmul4   4
  #define RST_CLK_CPU_PLLmul5   5
  #define RST_CLK_CPU_PLLmul6   6
  #define RST_CLK_CPU_PLLmul7   7
  #define RST_CLK_CPU_PLLmul8   8
  #define RST_CLK_CPU_PLLmul9   9
  #define RST_CLK_CPU_PLLmul10  10 


//  Port
  #define MDR_PORT_TypeDef  PortControl
  
//  ADC  
  #define ADC_InitTypeDef   ADCx_InitTypeDef  
#endif



#endif //_BRD_VE8_TO_VE_X_H
