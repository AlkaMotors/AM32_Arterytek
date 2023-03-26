///*
// * serial_telemetry.c
// *
// *  Created on: May 13, 2020
// *      Author: Alka
// */


#include "serial_telemetry.h"
#include "targets.h"

uint8_t aTxBuffer[10];
uint8_t nbDataToTransmit = sizeof(aTxBuffer);


void send_telem_DMA(){   // set data length and enable channel to start transfer
#ifdef USE_PA14_TELEMETRY
			DMA1_CHANNEL4->ctrl_bit.chen = FALSE; 
      DMA1_CHANNEL4->dtcnt = nbDataToTransmit;
	    DMA1_CHANNEL4->ctrl_bit.chen = TRUE;
#else	
			DMA1_CHANNEL2->ctrl_bit.chen = FALSE; 
      DMA1_CHANNEL2->dtcnt = nbDataToTransmit;
	    DMA1_CHANNEL2->ctrl_bit.chen = TRUE;
#endif
}



uint8_t update_crc8(uint8_t crc, uint8_t crc_seed){
uint8_t crc_u, i;
crc_u = crc;
crc_u ^= crc_seed;
for ( i=0; i<8; i++) crc_u = ( crc_u & 0x80 ) ? 0x7 ^ ( crc_u << 1 ) : ( crc_u << 1 );
return (crc_u);
}

uint8_t get_crc8(uint8_t *Buf, uint8_t BufLen){
uint8_t crc = 0, i;
for( i=0; i<BufLen; i++) crc = update_crc8(Buf[i], crc);
return (crc);
}


void makeTelemPackage(uint8_t temp, uint16_t voltage, uint16_t current, uint16_t consumption, uint16_t e_rpm){

  aTxBuffer[0] = temp; // temperature

  aTxBuffer[1] = (voltage >> 8) & 0xFF; // voltage hB
  aTxBuffer[2] = voltage & 0xFF; // voltage   lowB

  aTxBuffer[3] = (current >> 8) & 0xFF; // current
  aTxBuffer[4] = current & 0xFF; // divide by 10 for Amps

  aTxBuffer[5] = (consumption >> 8) & 0xFF; // consumption
  aTxBuffer[6] = consumption & 0xFF; //  in mah

  aTxBuffer[7] = (e_rpm >> 8) & 0xFF; //
  aTxBuffer[8] = e_rpm & 0xFF; // eRpM *100

  aTxBuffer[9] = get_crc8(aTxBuffer,9);
}


void telem_UART_Init(void)
{
	#ifdef USE_PA14_TELEMETRY
  gpio_init_type gpio_init_struct;


  crm_periph_clock_enable(CRM_USART2_PERIPH_CLOCK, TRUE);
  crm_periph_clock_enable(CRM_GPIOB_PERIPH_CLOCK, TRUE);
	crm_periph_clock_enable(CRM_DMA1_PERIPH_CLOCK, TRUE);
  
	  /* configure the usart2 tx pin */
  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
  gpio_init_struct.gpio_out_type  = GPIO_OUTPUT_PUSH_PULL;
  gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
  gpio_init_struct.gpio_pins = GPIO_PINS_14;
  gpio_init_struct.gpio_pull = GPIO_PULL_UP;
  gpio_init(GPIOA, &gpio_init_struct);
  gpio_pin_mux_config(GPIOA, GPIO_PINS_SOURCE14, GPIO_MUX_1);

		  
  dma_reset(DMA1_CHANNEL4);
	
	dma_init_type dma_init_struct;
  dma_default_para_init(&dma_init_struct);
  dma_init_struct.buffer_size = nbDataToTransmit;
  dma_init_struct.direction = DMA_DIR_MEMORY_TO_PERIPHERAL;
  dma_init_struct.memory_base_addr = (uint32_t)&aTxBuffer;
  dma_init_struct.memory_data_width = DMA_MEMORY_DATA_WIDTH_BYTE;
  dma_init_struct.memory_inc_enable = TRUE;
  dma_init_struct.peripheral_base_addr = (uint32_t)&USART2->dt;
  dma_init_struct.peripheral_data_width = DMA_PERIPHERAL_DATA_WIDTH_BYTE;
  dma_init_struct.peripheral_inc_enable = FALSE;
  dma_init_struct.priority = DMA_PRIORITY_LOW;
  dma_init_struct.loop_mode_enable = FALSE;
  dma_init(DMA1_CHANNEL4, &dma_init_struct);
		
//	DMA1_CHANNEL4->ctrl |= DMA_FDT_INT;
//	DMA1_CHANNEL4->ctrl |= DMA_DTERR_INT;
	
	
  /* configure usart1 param */
  usart_init(USART2, 115200, USART_DATA_8BITS, USART_STOP_1_BIT);
  usart_transmitter_enable(USART2, TRUE);
  usart_receiver_enable(USART2, TRUE);
  usart_single_line_halfduplex_select(USART2, TRUE);
	usart_dma_transmitter_enable(USART2, TRUE);
  usart_enable(USART2, TRUE);
	
 // nvic_irq_enable(DMA1_Channel5_4_IRQn, 3, 0);
  #else
	
  gpio_init_type gpio_init_struct;


  crm_periph_clock_enable(CRM_USART1_PERIPH_CLOCK, TRUE);
  crm_periph_clock_enable(CRM_GPIOB_PERIPH_CLOCK, TRUE);
	crm_periph_clock_enable(CRM_DMA1_PERIPH_CLOCK, TRUE);
  
	  /* configure the usart2 tx pin */
  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
  gpio_init_struct.gpio_out_type  = GPIO_OUTPUT_PUSH_PULL;
  gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
  gpio_init_struct.gpio_pins = GPIO_PINS_6;
  gpio_init_struct.gpio_pull = GPIO_PULL_UP;
  gpio_init(GPIOB, &gpio_init_struct);
  gpio_pin_mux_config(GPIOB, GPIO_PINS_SOURCE6, GPIO_MUX_0);

		  
  dma_reset(DMA1_CHANNEL2);
	
	dma_init_type dma_init_struct;
  dma_default_para_init(&dma_init_struct);
  dma_init_struct.buffer_size = nbDataToTransmit;
  dma_init_struct.direction = DMA_DIR_MEMORY_TO_PERIPHERAL;
  dma_init_struct.memory_base_addr = (uint32_t)&aTxBuffer;
  dma_init_struct.memory_data_width = DMA_MEMORY_DATA_WIDTH_BYTE;
  dma_init_struct.memory_inc_enable = TRUE;
  dma_init_struct.peripheral_base_addr = (uint32_t)&USART1->dt;
  dma_init_struct.peripheral_data_width = DMA_PERIPHERAL_DATA_WIDTH_BYTE;
  dma_init_struct.peripheral_inc_enable = FALSE;
  dma_init_struct.priority = DMA_PRIORITY_LOW;
  dma_init_struct.loop_mode_enable = FALSE;
  dma_init(DMA1_CHANNEL2, &dma_init_struct);
		
//	DMA1_CHANNEL2->ctrl |= DMA_FDT_INT;
//	DMA1_CHANNEL2->ctrl |= DMA_DTERR_INT;
	
	
  /* configure usart1 param */
  usart_init(USART1, 115200, USART_DATA_8BITS, USART_STOP_1_BIT);
  usart_transmitter_enable(USART1, TRUE);
  usart_receiver_enable(USART1, TRUE);
  usart_single_line_halfduplex_select(USART1, TRUE);
	usart_dma_transmitter_enable(USART1, TRUE);
  usart_enable(USART1, TRUE);
	
 // nvic_irq_enable(DMA1_Channel3_2_IRQn, 3, 0);
	
	#endif
}