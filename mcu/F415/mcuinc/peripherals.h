/*
 * peripherals.h
 *
 *  Created on: Sep. 26, 2020
 *      Author: Alka
 */

#ifndef PERIPHERALS_H_
#define PERIPHERALS_H_



#endif /* PERIPHERALS_H_ */

#include "main.h"


void initAfterJump(void);
void initCorePeripherals(void);
//void SystemClock_Config(void);
void MX_GPIO_Init(void);
void MX_DMA_Init(void);
//static void MX_ADC_Init(void);
void AT_COMP_Init(void);
void TIM1_Init(void);
void TIM4_Init(void);
void system_clock_config(void);
void MX_IWDG_Init(void);
void TIM11_Init(void);
void TIM9_Init(void);
void TIM10_Init(void);
//static void MX_USART1_UART_Init(void);

void UN_TIM_Init(void);

void LED_GPIO_init(void);

