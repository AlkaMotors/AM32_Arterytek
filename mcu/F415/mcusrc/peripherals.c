/*
 * peripherals.c
 *
 *  Created on: Sep. 26, 2020
 *      Author: Alka
 */


// PERIPHERAL SETUP


#define KR_KEY_Reload           ((uint16_t)0xAAAA)
#define KR_KEY_Enable           ((uint16_t)0xCCCC)


#include "peripherals.h"



#include "targets.h"
#include "serial_telemetry.h"
#include "common.h"
#include "functions.h"


void initCorePeripherals(void){
  system_clock_config();
	MX_GPIO_Init();
  MX_DMA_Init();
	TIM1_Init();
  TIM4_Init();
  TIM9_Init();
  AT_COMP_Init();
  TIM11_Init();
  TIM10_Init();
  	 
  UN_TIM_Init();
  #ifdef USE_SERIAL_TELEMETRY
    telem_UART_Init();
  #endif
}


void initAfterJump(void){

}


void system_clock_config(void)
{

  /* config flash psr register */
 

/// 144 mhz hick setup

flash_psr_set(FLASH_WAIT_CYCLE_4);
  crm_reset();

  crm_clock_source_enable(CRM_CLOCK_SOURCE_HICK, TRUE);
  while(crm_flag_get(CRM_HICK_STABLE_FLAG) != SET)
  {
  }
  crm_pll_config(CRM_PLL_SOURCE_HICK, CRM_PLL_MULT_36);
  crm_clock_source_enable(CRM_CLOCK_SOURCE_PLL, TRUE);
  while(crm_flag_get(CRM_PLL_STABLE_FLAG) != SET)
  {
  }
  crm_ahb_div_set(CRM_AHB_DIV_1);
  crm_apb2_div_set(CRM_APB2_DIV_2);
  crm_apb1_div_set(CRM_APB1_DIV_2);
  crm_auto_step_mode_enable(TRUE);
  crm_sysclk_switch(CRM_SCLK_PLL);
  while(crm_sysclk_switch_status_get() != CRM_SCLK_PLL)
  {
  }
  crm_auto_step_mode_enable(FALSE);
  system_core_clock_update();
}


void AT_COMP_Init(void)
{
	
  crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK, TRUE);
	crm_periph_clock_enable(CRM_CMP_PERIPH_CLOCK, TRUE);
	  /* configure PA1 as comparator input */
     gpio_mode_QUICK(GPIOA, GPIO_MODE_ANALOG, GPIO_PULL_NONE, GPIO_PINS_1);

     gpio_mode_QUICK(GPIOA, GPIO_MODE_ANALOG, GPIO_PULL_NONE, GPIO_PINS_5);

		
		NVIC_SetPriority(CMP1_IRQn, 0);
    NVIC_EnableIRQ(CMP1_IRQn);
		cmp_enable(CMP1_SELECTION, TRUE);
}


void MX_IWDG_Init(void)
{

	WDT->cmd = WDT_CMD_UNLOCK;
	WDT->cmd = WDT_CMD_ENABLE;
  WDT->div = WDT_CLK_DIV_64;
	WDT->rld = 4000;
	WDT->cmd = WDT_CMD_RELOAD;
	
}

void TIM1_Init(void){

	crm_periph_clock_enable(CRM_IOMUX_PERIPH_CLOCK, TRUE);
	crm_periph_clock_enable(CRM_TMR1_PERIPH_CLOCK, TRUE);

	gpio_pin_remap_config(TMR1_GMUX_0001, TRUE);
	
	
	TMR1->pr = 3000;
	TMR1->div = 0;
	
	TMR1->cm1 = 0x6868;   // Channel 1 and 2 in PWM output mode
	TMR1->cm2 = 0x68;     // channel 3 in PWM output mode

	tmr_output_channel_buffer_enable(TMR1,TMR_SELECT_CHANNEL_1, TRUE);
	tmr_output_channel_buffer_enable(TMR1,TMR_SELECT_CHANNEL_2, TRUE);
	tmr_output_channel_buffer_enable(TMR1,TMR_SELECT_CHANNEL_3, TRUE);
	
	tmr_period_buffer_enable(TMR1, TRUE);
	
	TMR1->brk_bit.dtc = DEAD_TIME;
	crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK, TRUE);
	crm_periph_clock_enable(CRM_GPIOB_PERIPH_CLOCK, TRUE);
	
	    /*configure PA8/PA9/PA10(TIMER0/CH0/CH1/CH2) as alternate function*/
    gpio_mode_QUICK(PHASE_A_GPIO_PORT_LOW, GPIO_MODE_MUX, GPIO_PULL_NONE, PHASE_A_GPIO_LOW);


    gpio_mode_QUICK(PHASE_B_GPIO_PORT_LOW, GPIO_MODE_MUX, GPIO_PULL_NONE, PHASE_B_GPIO_LOW);


    gpio_mode_QUICK(PHASE_C_GPIO_PORT_LOW, GPIO_MODE_MUX, GPIO_PULL_NONE, PHASE_C_GPIO_LOW);

    /*configure PB13/PB14/PB15(TIMER0/CH0N/CH1N/CH2N) as alternate function*/
    gpio_mode_QUICK(PHASE_A_GPIO_PORT_HIGH, GPIO_MODE_MUX, GPIO_PULL_NONE, PHASE_A_GPIO_HIGH);


    gpio_mode_QUICK(PHASE_B_GPIO_PORT_HIGH, GPIO_MODE_MUX, GPIO_PULL_NONE, PHASE_B_GPIO_HIGH);


    gpio_mode_QUICK(PHASE_C_GPIO_PORT_HIGH, GPIO_MODE_MUX, GPIO_PULL_NONE, PHASE_C_GPIO_HIGH);

}



void TIM4_Init(void)
{
	crm_periph_clock_enable(CRM_TMR4_PERIPH_CLOCK, TRUE);
	
	TMR4->pr = 0xFFFF;
	TMR4->div = 74;

}



void TIM9_Init(void)
{

	crm_periph_clock_enable(CRM_TMR9_PERIPH_CLOCK, TRUE);

	TMR9->pr = 100;
	TMR9->div = 149;
	
	
	NVIC_SetPriority(TMR1_BRK_TMR9_IRQn, 2);
  NVIC_EnableIRQ(TMR1_BRK_TMR9_IRQn);
	
	//TMR_Cmd(TMR14, ENABLE);
}



void TIM11_Init(void)
{
	crm_periph_clock_enable(CRM_TMR11_PERIPH_CLOCK, TRUE);

	TMR11->pr = 500;
	TMR11->div = 75;
	TMR11->ctrl1_bit.prben = TRUE;
	
	NVIC_SetPriority(TMR1_TRG_HALL_TMR11_IRQn, 0);
  NVIC_EnableIRQ(TMR1_TRG_HALL_TMR11_IRQn);
	
}



void TIM10_Init(void)
{

	crm_periph_clock_enable(CRM_TMR10_PERIPH_CLOCK, TRUE);
	TMR10->pr = 0xFFFF;
	TMR10->div = 75;
TMR10->ctrl1_bit.prben = TRUE;
	
}


void MX_DMA_Init(void)
{

crm_periph_clock_enable(CRM_DMA1_PERIPH_CLOCK, TRUE);

  NVIC_SetPriority(DMA1_Channel6_IRQn, 1);
  NVIC_EnableIRQ(DMA1_Channel6_IRQn);

}

void MX_GPIO_Init(void)
{

}


void UN_TIM_Init(void)
{
#ifdef USE_TIMER_3_CHANNEL_1
  crm_periph_clock_enable(CRM_GPIOB_PERIPH_CLOCK, TRUE);
	crm_periph_clock_enable(CRM_TMR3_PERIPH_CLOCK, TRUE);
#endif
#ifdef USE_TIMER_15_CHANNEL_1
	crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK, TRUE);
	crm_periph_clock_enable(CRM_TMR15_PERIPH_CLOCK, TRUE);
#endif
	
		crm_periph_clock_enable(CRM_IOMUX_PERIPH_CLOCK, TRUE);
	  gpio_pin_remap_config(SWJTAG_MUX_010, TRUE);
		gpio_pin_remap_config(TMR3_MUX_10, TRUE);
 
  crm_periph_clock_enable(CRM_DMA1_PERIPH_CLOCK, TRUE);
	gpio_mode_QUICK(INPUT_PIN_PORT, GPIO_MODE_INPUT, GPIO_PULL_NONE, INPUT_PIN);
	
	
	//GPIO_PinAFConfig(INPUT_PIN_PORT, GPIO_PinsSource4, GPIO_AF_1);
//	gpio_pin_mux_config(INPUT_PIN_PORT, INPUT_PIN, GPIO_MUX_1);

//	 dma_periph_address_config(INPUT_DMA_CHANNEL, (uint32_t)&TIMER_CH0CV(IC_TIMER_REGISTER));
//   dma_memory_address_config(INPUT_DMA_CHANNEL, (uint32_t)&dma_buffer);
//	 INPUT_DMA_CHANNEL->CPBA = (uint32_t)&IC_TIMER_REGISTER->CC1;
//	 INPUT_DMA_CHANNEL->CMBA = (uint32_t)&dma_buffer;
//   INPUT_DMA_CHANNEL->CHCTRL |= DMA_DIR_PERIPHERALSRC;

 //   DMA_Reset(INPUT_DMA_CHANNEL);
//  DMA_DefaultInitParaConfig(&DMA_InitStructure);

//  DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&IC_TIMER_REGISTER->CC1;
//  DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)&dma_buffer;
//  DMA_InitStructure.DMA_Direction = DMA_DIR_PERIPHERALSRC;
//  DMA_InitStructure.DMA_BufferSize = 32;
//  DMA_InitStructure.DMA_PeripheralInc = DMA_PERIPHERALINC_DISABLE;
//  DMA_InitStructure.DMA_MemoryInc = DMA_MEMORYINC_ENABLE;
//  DMA_InitStructure.DMA_PeripheralDataWidth = DMA_PERIPHERALDATAWIDTH_HALFWORD;
//  DMA_InitStructure.DMA_MemoryDataWidth = DMA_MEMORYDATAWIDTH_WORD;
//  DMA_InitStructure.DMA_Mode = DMA_MODE_NORMAL;
//  DMA_InitStructure.DMA_Priority = DMA_PRIORITY_LOW;
//  DMA_InitStructure.DMA_MTOM = DMA_MEMTOMEM_DISABLE;
//  DMA_Init(INPUT_DMA_CHANNEL, &DMA_InitStructure);

  INPUT_DMA_CHANNEL->ctrl = 0X98a; //  PERIPHERAL HALF WORD, MEMROY WORD , MEMORY INC ENABLE , TC AND ERROR INTS


   NVIC_SetPriority(IC_DMA_IRQ_NAME, 1);
   NVIC_EnableIRQ(IC_DMA_IRQ_NAME);

	

	
	IC_TIMER_REGISTER->pr = 0xFFFF;
	IC_TIMER_REGISTER->div = 16;
	IC_TIMER_REGISTER->ctrl1_bit.prben = TRUE;
  gpio_mode_QUICK(GPIOB, GPIO_MODE_INPUT, GPIO_PULL_NONE , INPUT_PIN);
	IC_TIMER_REGISTER->ctrl1_bit.tmren = TRUE;
		
}

#ifdef USE_RGB_LED              // has 3 color led
void LED_GPIO_init(){
	  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

	  /* GPIO Ports Clock Enable */
	  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);

	  LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_8);
      LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);
	  LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_3);

	  GPIO_InitStruct.Pin = LL_GPIO_PIN_8;
	  GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
	  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
	  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
	  LL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	  GPIO_InitStruct.Pin = LL_GPIO_PIN_5;
	  GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
	  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
	  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
	  LL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	  GPIO_InitStruct.Pin = LL_GPIO_PIN_3;
	  GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
	  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
	  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
	  LL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

#endif



