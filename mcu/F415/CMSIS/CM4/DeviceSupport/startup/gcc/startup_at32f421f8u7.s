/**
  ******************************************************************************
  * File   : startup_at32f421f8u7.s
  * Version: V1.2.4
  * Date   : 2020-08-26
  * Brief  : AT32F4xx Devices vector table for GCC toolchain.
  *            This module performs:
  *                - Set the initial SP
  *                - Set the initial PC == Reset_Handler,
  *                - Set the vector table entries with the exceptions ISR address
  *                - Configure the clock system and the external SRAM to
  *                  be used as data memory (optional, to be enabled by user)
  *                - Branches to main in the C library (which eventually
  *                  calls main()).
  *            After Reset the Cortex-M4 processor is in Thread mode,
  *            priority is Privileged, and the Stack is set to Main.
  ******************************************************************************
  */

  .syntax unified
  .cpu cortex-m4
  .fpu softvfp
  .thumb

.global  g_pfnVectors
.global  Default_Handler

/* start address for the initialization values of the .data section.
defined in linker script */
.word  _sidata
/* start address for the .data section. defined in linker script */
.word  _sdata
/* end address for the .data section. defined in linker script */
.word  _edata
/* start address for the .bss section. defined in linker script */
.word  _sbss
/* end address for the .bss section. defined in linker script */
.word  _ebss
/* stack used for SystemInit_ExtMemCtl; always internal RAM used */

/**
 * @brief  This is the code that gets called when the processor first
 *          starts execution following a reset event. Only the absolutely
 *          necessary set is performed, after which the application
 *          supplied main() routine is called.
 * @param  None
 * @retval None
*/

    .section  .text.Reset_Handler
  .weak  Reset_Handler
  .type  Reset_Handler, %function
Reset_Handler:

/* Copy the data segment initializers from flash to SRAM */
  movs  r1, #0
  b  LoopCopyDataInit

CopyDataInit:
  ldr  r3, =_sidata
  ldr  r3, [r3, r1]
  str  r3, [r0, r1]
  adds  r1, r1, #4

LoopCopyDataInit:
  ldr  r0, =_sdata
  ldr  r3, =_edata
  adds  r2, r0, r1
  cmp  r2, r3
  bcc  CopyDataInit
  ldr  r2, =_sbss
  b  LoopFillZerobss
/* Zero fill the bss segment. */
FillZerobss:
  movs  r3, #0
  str  r3, [r2], #4

LoopFillZerobss:
  ldr  r3, = _ebss
  cmp  r2, r3
  bcc  FillZerobss

/* Call the clock system intitialization function.*/
  bl  SystemInit
/* Call the application's entry point.*/
  bl  main
  bx  lr
.size  Reset_Handler, .-Reset_Handler

/**
 * @brief  This is the code that gets called when the processor receives an
 *         unexpected interrupt.  This simply enters an infinite loop, preserving
 *         the system state for examination by a debugger.
 * @param  None
 * @retval None
*/
    .section  .text.Default_Handler,"ax",%progbits
Default_Handler:
Infinite_Loop:
  b  Infinite_Loop
  .size  Default_Handler, .-Default_Handler
/******************************************************************************
*
* The minimal vector table for a Cortex M3. Note that the proper constructs
* must be placed on this to ensure that it ends up at physical address
* 0x0000.0000.
* 
*******************************************************************************/
   .section  .isr_vector,"a",%progbits
  .type  g_pfnVectors, %object
  .size  g_pfnVectors, .-g_pfnVectors


g_pfnVectors:
  .word  _estack
  .word  Reset_Handler
  .word  NMI_Handler
  .word  HardFault_Handler
  .word  MemManage_Handler
  .word  BusFault_Handler
  .word  UsageFault_Handler
  .word  0
  .word  0
  .word  0
  .word  0
  .word  SVC_Handler
  .word  DebugMon_Handler
  .word  0
  .word  PendSV_Handler
  .word  SysTick_Handler
  
  /* External Interrupts */
  .word  WWDG_IRQHandler                     /* Window Watchdog                             */
  .word  PVD_IRQHandler                      /* PVD through EXTI Line detect                */
  .word  ERTC_IRQHandler                     /* ERTC                                        */
  .word  FLASH_IRQHandler                    /* Flash                                       */
  .word  RCC_IRQHandler                      /* RCC                                         */
  .word  EXTI1_0_IRQHandler                  /* EXTI Line 1 & 0                             */
  .word  EXTI3_2_IRQHandler                  /* EXTI Line 3 & 2                             */
  .word  EXTI15_4_IRQHandler                 /* EXTI Line 4 to 15                           */
  .word  0                                   /* Reserved                                    */
  .word  DMA1_Channel1_IRQHandler            /* DMA1 Channel 1                              */
  .word  DMA1_Channel3_2_IRQHandler          /* DMA1 Channel 3 & 2                          */
  .word  DMA1_Channel7_4_IRQHandler          /* DMA1 Channel 4 to 7                         */
  .word  ADC_COMP_IRQHandler                 /* ADC1 & COMP                                 */
  .word  TMR1_BRK_UP_TRG_COM_IRQHandler      /* TMR1 Break UP TRG COM                       */
  .word  TMR1_CC_IRQHandler                  /* TMR1 Capture Compare                        */
  .word  TMR3_GLOBAL_IRQHandler              /* TMR3                                        */
  .word  TMR6_GLOBAL_IRQHandler              /* TMR6                                        */
  .word  TMR14_GLOBAL_IRQHandler             /* TMR14                                       */
  .word  TMR15_GLOBAL_IRQHandler             /* TMR15                                       */
  .word  TMR16_GLOBAL_IRQHandler             /* TMR16                                       */
  .word  TMR17_GLOBAL_IRQHandler             /* TMR17                                       */
  .word  I2C1_EV_IRQHandler                  /* I2C1 Event                                  */
  .word  I2C2_EV_IRQHandler                  /* I2C2 Event                                  */
  .word  SPI1_IRQHandler                     /* SPI1                                        */
  .word  0                                   /* Reserved                                    */
  .word  USART1_IRQHandler                   /* USART1                                      */
  .word  USART2_IRQHandler                   /* USART2                                      */
  .word  0                                   /* Reserved                                    */
  .word  0                                   /* Reserved                                    */
  .word  0                  			  	 /* Reserved                                    */
  .word  I2C1_ER_IRQHandler                  /* I2C2 Error                                  */
  .word  0                  			  	 /* Reserved                                    */
  .word  I2C2_ER_IRQHandler                  /* I2C2 Error                                  */

/*******************************************************************************
*
* Provide weak aliases for each Exception handler to the Default_Handler. 
* As they are weak aliases, any function with the same name will override 
* this definition.
* 
*******************************************************************************/
   .weak      NMI_Handler
   .thumb_set NMI_Handler,Default_Handler
  
   .weak      HardFault_Handler
   .thumb_set HardFault_Handler,Default_Handler
  
   .weak      MemManage_Handler
   .thumb_set MemManage_Handler,Default_Handler
  
   .weak      BusFault_Handler
   .thumb_set BusFault_Handler,Default_Handler

   .weak      UsageFault_Handler
   .thumb_set UsageFault_Handler,Default_Handler

   .weak      SVC_Handler
   .thumb_set SVC_Handler,Default_Handler

   .weak      DebugMon_Handler
   .thumb_set DebugMon_Handler,Default_Handler

   .weak      PendSV_Handler
   .thumb_set PendSV_Handler,Default_Handler

   .weak      SysTick_Handler
   .thumb_set SysTick_Handler,Default_Handler              
  
   .weak      WWDG_IRQHandler
   .thumb_set WWDG_IRQHandler,Default_Handler      

   .weak      PVD_IRQHandler
   .thumb_set PVD_IRQHandler,Default_Handler

   .weak      ERTC_IRQHandler
   .thumb_set ERTC_IRQHandler,Default_Handler

   .weak      FLASH_IRQHandler
   .thumb_set FLASH_IRQHandler,Default_Handler

   .weak      RCC_IRQHandler
   .thumb_set RCC_IRQHandler,Default_Handler

   .weak      EXTI1_0_IRQHandler
   .thumb_set EXTI1_0_IRQHandler,Default_Handler

   .weak      EXTI3_2_IRQHandler
   .thumb_set EXTI3_2_IRQHandler,Default_Handler

   .weak      EXTI15_4_IRQHandler
   .thumb_set EXTI15_4_IRQHandler,Default_Handler 

   .weak      DMA1_Channel1_IRQHandler
   .thumb_set DMA1_Channel1_IRQHandler,Default_Handler

   .weak      DMA1_Channel3_2_IRQHandler
   .thumb_set DMA1_Channel3_2_IRQHandler,Default_Handler

   .weak      DMA1_Channel7_4_IRQHandler
   .thumb_set DMA1_Channel7_4_IRQHandler,Default_Handler

   .weak      ADC_COMP_IRQHandler
   .thumb_set ADC_COMP_IRQHandler,Default_Handler

   .weak      TMR1_BRK_UP_TRG_COM_IRQHandler
   .thumb_set TMR1_BRK_UP_TRG_COM_IRQHandler,Default_Handler

   .weak      TMR1_CC_IRQHandler
   .thumb_set TMR1_CC_IRQHandler,Default_Handler

   .weak      TMR3_GLOBAL_IRQHandler
   .thumb_set TMR3_GLOBAL_IRQHandler,Default_Handler

   .weak      TMR6_GLOBAL_IRQHandler
   .thumb_set TMR6_GLOBAL_IRQHandler,Default_Handler

   .weak      TMR14_GLOBAL_IRQHandler
   .thumb_set TMR14_GLOBAL_IRQHandler,Default_Handler

   .weak      TMR15_GLOBAL_IRQHandler
   .thumb_set TMR15_GLOBAL_IRQHandler,Default_Handler

   .weak      TMR16_GLOBAL_IRQHandler
   .thumb_set TMR16_GLOBAL_IRQHandler,Default_Handler

   .weak      TMR17_GLOBAL_IRQHandler 
   .thumb_set TMR17_GLOBAL_IRQHandler ,Default_Handler

   .weak      I2C1_EV_IRQHandler
   .thumb_set I2C1_EV_IRQHandler,Default_Handler

   .weak      I2C2_EV_IRQHandler
   .thumb_set I2C2_EV_IRQHandler,Default_Handler

   .weak      SPI1_IRQHandler
   .thumb_set SPI1_IRQHandler,Default_Handler

   .weak      USART1_IRQHandler
   .thumb_set USART1_IRQHandler,Default_Handler

   .weak      USART2_IRQHandler
   .thumb_set USART2_IRQHandler,Default_Handler

   .weak      I2C1_ER_IRQHandler
   .thumb_set I2C1_ER_IRQHandler,Default_Handler

   .weak      I2C2_ER_IRQHandler
   .thumb_set I2C2_ER_IRQHandler,Default_Handler

/************************ (C) COPYRIGHT Artery Tek *****END OF FILE****/
