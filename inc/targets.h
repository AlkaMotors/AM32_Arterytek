

#ifndef USE_MAKE

//#define AT32dev045_PA2
//#define AT32dev504_PA2
//#define AT32dev450_PA2
//#define AT32dev054_PA2
//#define AT32dev405_PA2
//#define AT32dev540_PA2

//#define AT32dev045_PB4
//#define AT32dev504_PB4
//#define AT32dev450_PB4
//#define AT32dev054_PB4
//#define AT32dev405_PB4
//#define AT32dev540_PB4


//#define AT32DEV_F421
//#define TEKKO32_F421
//#define FOXEER_F421
//#define AIKON_SINGLE_F421
//#define AIKON_55A_F421
//#define WRAITH32_F421

#endif

#ifdef  SWAP_PB0_PA7_F421
#define FIRMWARE_NAME           "SWAP PB0 PA7"
#define FILE_NAME                "SWAP_PB0_PA7"
#define DEAD_TIME               60
#define HARDWARE_GROUP_AT_045
#define HARDWARE_GROUP_AT_F
#define USE_SERIAL_TELEMETRY
#define USE_PA14_TELEMETRY
#define PA6_NTC_ONLY
#endif

#ifdef  F4A_AIO_F421
#define FIRMWARE_NAME           "F4A AIO     "
#define FILE_NAME                "F4A_AIO_F421"
#define DEAD_TIME               20
#define HARDWARE_GROUP_AT_540
#define HARDWARE_GROUP_AT_F
//#define USE_SERIAL_TELEMETRY
//#define USE_PA14_TELEMETRY
//#define PA6_NTC_ONLY
#endif

#ifdef  F4A_4IN1_F421
#define FIRMWARE_NAME           "F4A 4in1    "
#define FILE_NAME                "F4A_4IN1_F421"
#define DEAD_TIME               45
#define HARDWARE_GROUP_AT_540
#define HARDWARE_GROUP_AT_E
#define USE_SERIAL_TELEMETRY
#define USE_PA14_TELEMETRY
#define PA6_NTC_ONLY
#endif

#ifdef  F4A_SINGLE_F421
#define FIRMWARE_NAME           "F4A Single  "
#define FILE_NAME                "F4A_SINGLE_F421"
#define DEAD_TIME               60
#define HARDWARE_GROUP_AT_540
#define HARDWARE_GROUP_AT_E
#define USE_SERIAL_TELEMETRY
#define USE_PA14_TELEMETRY
#define PA6_NTC_ONLY
#endif

#ifdef  F4A_EXTCOMP_F421
#define FIRMWARE_NAME           "F4A Ext Comp"
#define FILE_NAME                "F4A_EXTCOMP_F421"
#define DEAD_TIME               60
#define HARDWARE_GROUP_AT_045
#define HARDWARE_GROUP_AT_E
#define USE_SERIAL_TELEMETRY
#endif


#ifdef AT32DEV_F421
#define FIRMWARE_NAME           "AT32PB4     "
#define FILE_NAME                "AT32DEV_F421"
#define DEAD_TIME               60
#define HARDWARE_GROUP_AT_B
#define HARDWARE_GROUP_AT_045
#define USE_SERIAL_TELEMETRY
#endif

#ifdef DARWIN_F421
#define FIRMWARE_NAME           "DARWIN F421 "
#define FILE_NAME                "DARWIN_F421"
#define DEAD_TIME               60
#define HARDWARE_GROUP_AT_B
#define HARDWARE_GROUP_AT_245          // pa2
#define USE_SERIAL_TELEMETRY
#endif


#ifdef AT32SLOTCAR_F421
#define FIRMWARE_NAME           "AT32_SC     "
#define FILE_NAME                "AT32SLOTCAR_F421"
#define DEAD_TIME               180
#define HARDWARE_GROUP_AT_B
#define HARDWARE_GROUP_AT_045
#endif
/****************************************Generic********************************************/

#ifdef  AT32F421_PB4_054
#define FIRMWARE_NAME           "AT32PB4_054 "
#define FILE_NAME               "AT32F421_PB4_054"
#define DEAD_TIME               80
#define HARDWARE_GROUP_AT_B
#define HARDWARE_GROUP_AT_054
#define USE_SERIAL_TELEMETRY
#endif

#ifdef  AT32F421_PB4_405
#define FIRMWARE_NAME           "AT32PB4_405 "
#define FILE_NAME               "AT32F421_PB4_405"
#define DEAD_TIME               80
#define HARDWARE_GROUP_AT_B
#define HARDWARE_GROUP_AT_405
#define USE_SERIAL_TELEMETRY
#endif

#ifdef  AT32F421_PB4_540
#define FIRMWARE_NAME           "AT32PB4_540 "
#define FILE_NAME               "AT32F421_PB4_540"
#define DEAD_TIME               80
#define HARDWARE_GROUP_AT_B
#define HARDWARE_GROUP_AT_540
#define USE_SERIAL_TELEMETRY
#endif





/***************************************End Generic *****************************************/

#ifdef TEKKO32_F421
#define FIRMWARE_NAME           "Tekko32 F4  "
#define FILE_NAME                "TEKKO32_F421"
#define DEAD_TIME               80
#define HARDWARE_GROUP_AT_A
#define USE_SERIAL_TELEMETRY
#endif

#ifdef HAKRC_G_F421                                     
#define FIRMWARE_NAME           "HAKRC F4 G  "
#define FILE_NAME                "HAKRC_G_F421"
#define DEAD_TIME               80
#define HARDWARE_GROUP_AT_B
#define HARDWARE_GROUP_AT_450
#define USE_SERIAL_TELEMETRY

#endif

#ifdef HAKRC_G23_F421                                     
#define FIRMWARE_NAME           "HAKRC F4 G23"
#define FILE_NAME                "HAKRC_G23_F421"
#define DEAD_TIME               80
#define HARDWARE_GROUP_AT_B
#define HARDWARE_GROUP_AT_450
#define USE_SERIAL_TELEMETRY
#define MILLIVOLT_PER_AMP          45
#define CURRENT_OFFSET            505          // mv
#define USE_NTC
#define USE_WS2812
#define ADC_CHANNEL_CURRENT  ADC_CHANNEL_3
#define ADC_CHANNEL_VOLTAGE  ADC_CHANNEL_2
#define ADC_CHANNEL_TEMP     ADC_CHANNEL_6
#endif

#ifdef HAKRC_K_F421                                     
#define FIRMWARE_NAME           "HAKRC F4 K  "
#define FILE_NAME               "HAKRC_K_F421"
#define DEAD_TIME               80
#define HARDWARE_GROUP_AT_B
#define HARDWARE_GROUP_AT_504
#define USE_SERIAL_TELEMETRY
#endif

#ifdef  FOXEER_F421
#define HARDWARE_GROUP_AT_C
#define FIRMWARE_NAME           "FOXEER F4   "
#define FILE_NAME                "FOXEER_F421"
#define DEAD_TIME               60
#define HARDWARE_GROUP_AT_540
#define USE_SERIAL_TELEMETRY
#endif


#ifdef  WRAITH32_F421
#define FIRMWARE_NAME           "WRAITH32_F4  "
#define FILE_NAME                "WRAITH32_F421"
#define DEAD_TIME               60
#define HARDWARE_GROUP_AT_045
#define HARDWARE_GROUP_AT_C
#define USE_SERIAL_TELEMETRY
#define TARGET_VOLTAGE_DIVIDER  	 74
#define MILLIVOLT_PER_AMP          45
#define CURRENT_OFFSET            526          // mv
#define TARGET_STALL_PROTECTION_INTERVAL 9000
#endif

#ifdef  AIKON_55A_F421
#define FIRMWARE_NAME           "AIKON F4 55A"
#define FILE_NAME                "AIKON_55A_F421"
#define DEAD_TIME               60
#define HARDWARE_GROUP_AT_C
#define HARDWARE_GROUP_AT_045
#define USE_SERIAL_TELEMETRY
#endif

#ifdef  AIKON_SINGLE_F421
#define FIRMWARE_NAME           "AIKON S F4  "
#define FILE_NAME                "AIKON_SINGLE_F421"
#define DEAD_TIME               60
#define HARDWARE_GROUP_AT_B
#define HARDWARE_GROUP_AT_045
#define USE_SERIAL_TELEMETRY
#endif

#ifdef AT32DEV_F415
#define FIRMWARE_NAME           "AT32F415    "
#define FILE_NAME               "AT32DEV_F415"
#define DEAD_TIME               80
#define HARDWARE_GROUP_AT_D
#define USE_SERIAL_TELEMETRY
#endif

#ifdef DAKEFPV_35A_F415
#define FIRMWARE_NAME           "DakeFPV 35A "
#define FILE_NAME               "DAKEFPV_35A_F415"
#define DEAD_TIME               20
#define HARDWARE_GROUP_AT_D
#define USE_SERIAL_TELEMETRY
#endif

#ifdef TEKKO32_F415
#define FIRMWARE_NAME           "Tekko32 F4  "
#define FILE_NAME               "TEKKO32_F415"
#define DEAD_TIME               100
#define HARDWARE_GROUP_AT_D
#define USE_SERIAL_TELEMETRY
#endif
/********************************** defaults if not set ***************************/

#ifndef 	TARGET_VOLTAGE_DIVIDER
#define 	TARGET_VOLTAGE_DIVIDER  	110
#endif

#ifndef 	SINE_DIVIDER
#define 	SINE_DIVIDER 				2
#endif

#ifndef  	MILLIVOLT_PER_AMP
#define   MILLIVOLT_PER_AMP           20
#endif 

#ifndef 	  CURRENT_OFFSET
#define     CURRENT_OFFSET              0
#endif

#ifndef TARGET_STALL_PROTECTION_INTERVAL
#define TARGET_STALL_PROTECTION_INTERVAL 6500
#endif



#ifdef HARDWARE_GROUP_AT_B

#define MCU_AT421
#define USE_TIMER_3_CHANNEL_1
#define INPUT_PIN               GPIO_PINS_4
#define INPUT_PIN_SOURCE        GPIO_PINS_SOURCE4
#define INPUT_PIN_PORT          GPIOB
#define IC_TIMER_CHANNEL        TMR_SELECT_CHANNEL_1
#define IC_TIMER_REGISTER       TMR3
#define INPUT_DMA_CHANNEL       DMA1_CHANNEL4
#define IC_DMA_IRQ_NAME         DMA1_Channel5_4_IRQn

#define PHASE_A_GPIO_LOW        GPIO_PINS_1
#define PHASE_A_PIN_SOURCE_LOW  GPIO_PINS_SOURCE1
#define PHASE_A_GPIO_PORT_LOW   GPIOB
#define PHASE_A_GPIO_HIGH       GPIO_PINS_10
#define PHASE_A_PIN_SOURCE_HIGH  GPIO_PINS_SOURCE10
#define PHASE_A_GPIO_PORT_HIGH  GPIOA

#define PHASE_B_GPIO_LOW        GPIO_PINS_0
#define PHASE_B_PIN_SOURCE_LOW  GPIO_PINS_SOURCE0
#define PHASE_B_GPIO_PORT_LOW   GPIOB
#define PHASE_B_GPIO_HIGH       GPIO_PINS_9
#define PHASE_B_PIN_SOURCE_HIGH  GPIO_PINS_SOURCE9
#define PHASE_B_GPIO_PORT_HIGH  GPIOA

#define PHASE_C_GPIO_LOW        GPIO_PINS_7
#define PHASE_C_PIN_SOURCE_LOW  GPIO_PINS_SOURCE7
#define PHASE_C_GPIO_PORT_LOW   GPIOA
#define PHASE_C_GPIO_HIGH       GPIO_PINS_8
#define PHASE_C_PIN_SOURCE_HIGH  GPIO_PINS_SOURCE8
#define PHASE_C_GPIO_PORT_HIGH  GPIOA

#endif

#ifdef HARDWARE_GROUP_AT_C

#define MCU_AT421
#define USE_TIMER_15_CHANNEL_1
#define INPUT_PIN               GPIO_PINS_2
#define INPUT_PIN_SOURCE        GPIO_PINS_SOURCE2
#define INPUT_PIN_PORT          GPIOA
#define IC_TIMER_CHANNEL        TMR_SELECT_CHANNEL_1
#define IC_TIMER_REGISTER       TMR15
#define INPUT_DMA_CHANNEL       DMA1_CHANNEL5
#define IC_DMA_IRQ_NAME         DMA1_Channel5_4_IRQn

#define PHASE_A_GPIO_LOW        GPIO_PINS_1
#define PHASE_A_PIN_SOURCE_LOW  GPIO_PINS_SOURCE1
#define PHASE_A_GPIO_PORT_LOW   GPIOB
#define PHASE_A_GPIO_HIGH       GPIO_PINS_10
#define PHASE_A_PIN_SOURCE_HIGH  GPIO_PINS_SOURCE10
#define PHASE_A_GPIO_PORT_HIGH  GPIOA

#define PHASE_B_GPIO_LOW        GPIO_PINS_0
#define PHASE_B_PIN_SOURCE_LOW  GPIO_PINS_SOURCE0
#define PHASE_B_GPIO_PORT_LOW   GPIOB
#define PHASE_B_GPIO_HIGH       GPIO_PINS_9
#define PHASE_B_PIN_SOURCE_HIGH  GPIO_PINS_SOURCE9
#define PHASE_B_GPIO_PORT_HIGH  GPIOA

#define PHASE_C_GPIO_LOW        GPIO_PINS_7
#define PHASE_C_PIN_SOURCE_LOW  GPIO_PINS_SOURCE7
#define PHASE_C_GPIO_PORT_LOW   GPIOA
#define PHASE_C_GPIO_HIGH       GPIO_PINS_8
#define PHASE_C_PIN_SOURCE_HIGH  GPIO_PINS_SOURCE8
#define PHASE_C_GPIO_PORT_HIGH  GPIOA


#endif

#ifdef HARDWARE_GROUP_AT_D

#define MCU_AT415
#define USE_TIMER_3_CHANNEL_1
#define INPUT_PIN               GPIO_PINS_4
#define INPUT_PIN_PORT          GPIOB
#define IC_TIMER_CHANNEL        TMR_SELECT_CHANNEL_1
#define IC_TIMER_REGISTER       TMR3
#define INPUT_DMA_CHANNEL       DMA1_CHANNEL6
#define IC_DMA_IRQ_NAME         DMA1_Channel6_IRQn

#define PHASE_A_GPIO_LOW        GPIO_PINS_1
#define PHASE_A_PIN_SOURCE_LOW  GPIO_PIN_SOURCE1
#define PHASE_A_GPIO_PORT_LOW   GPIOB
#define PHASE_A_GPIO_HIGH       GPIO_PINS_10
#define PHASE_A_PIN_SOURCE_HIGH GPIO_PIN_SOURCE10
#define PHASE_A_GPIO_PORT_HIGH  GPIOA

#define PHASE_B_GPIO_LOW        GPIO_PINS_0
#define PHASE_B_PIN_SOURCE_LOW  GPIO_PIN_SOURCE0
#define PHASE_B_GPIO_PORT_LOW   GPIOB
#define PHASE_B_GPIO_HIGH       GPIO_PINS_9
#define PHASE_B_PIN_SOURCE_HIGH  GPIO_PIN_SOURCE9
#define PHASE_B_GPIO_PORT_HIGH  GPIOA

#define PHASE_C_GPIO_LOW        GPIO_PINS_7
#define PHASE_C_PIN_SOURCE_LOW  GPIO_PIN_SOURCE7
#define PHASE_C_GPIO_PORT_LOW   GPIOA
#define PHASE_C_GPIO_HIGH       GPIO_PINS_8
#define PHASE_C_PIN_SOURCE_HIGH  GPIO_PIN_SOURCE8
#define PHASE_C_GPIO_PORT_HIGH  GPIOA


//#define PHASE_A_COMP COMP_INMInput_IN3  // pa0
//#define PHASE_B_COMP COMP_INMInput_IN1  // pa4
//#define PHASE_C_COMP COMP_INMInput_IN2  // pa5

#define PHASE_A_COMP  0x400000E1            // works for polling mode
#define PHASE_B_COMP  0x400000C1
#define PHASE_C_COMP  0x400000D1

#endif

#ifdef HARDWARE_GROUP_AT_E

#define MCU_AT421
#define USE_TIMER_15_CHANNEL_1
#define USE_PA14_TELEMETRY
#define USE_PA6_TEMP
#define INPUT_PIN               GPIO_PINS_2
#define INPUT_PIN_SOURCE        GPIO_PINS_SOURCE2
#define INPUT_PIN_PORT          GPIOA
#define IC_TIMER_CHANNEL        TMR_SELECT_CHANNEL_1
#define IC_TIMER_REGISTER       TMR15
#define INPUT_DMA_CHANNEL       DMA1_CHANNEL5
#define IC_DMA_IRQ_NAME         DMA1_Channel5_4_IRQn

#define PHASE_A_GPIO_LOW        GPIO_PINS_1
#define PHASE_A_PIN_SOURCE_LOW  GPIO_PINS_SOURCE1
#define PHASE_A_GPIO_PORT_LOW   GPIOB
#define PHASE_A_GPIO_HIGH       GPIO_PINS_10
#define PHASE_A_PIN_SOURCE_HIGH  GPIO_PINS_SOURCE10
#define PHASE_A_GPIO_PORT_HIGH  GPIOA

#define PHASE_B_GPIO_LOW        GPIO_PINS_0
#define PHASE_B_PIN_SOURCE_LOW  GPIO_PINS_SOURCE0
#define PHASE_B_GPIO_PORT_LOW   GPIOB
#define PHASE_B_GPIO_HIGH       GPIO_PINS_9
#define PHASE_B_PIN_SOURCE_HIGH  GPIO_PINS_SOURCE9
#define PHASE_B_GPIO_PORT_HIGH  GPIOA

#define PHASE_C_GPIO_LOW        GPIO_PINS_7
#define PHASE_C_PIN_SOURCE_LOW  GPIO_PINS_SOURCE7
#define PHASE_C_GPIO_PORT_LOW   GPIOA
#define PHASE_C_GPIO_HIGH       GPIO_PINS_8
#define PHASE_C_PIN_SOURCE_HIGH  GPIO_PINS_SOURCE8
#define PHASE_C_GPIO_PORT_HIGH  GPIOA


#endif





#ifdef HARDWARE_GROUP_AT_F

#define MCU_AT421
#define USE_TIMER_15_CHANNEL_1
#define USE_PA14_TELEMETRY
#define USE_PA6_TEMP
#define INPUT_PIN               GPIO_PINS_2
#define INPUT_PIN_SOURCE        GPIO_PINS_SOURCE2
#define INPUT_PIN_PORT          GPIOA
#define IC_TIMER_CHANNEL        TMR_SELECT_CHANNEL_1
#define IC_TIMER_REGISTER       TMR15
#define INPUT_DMA_CHANNEL       DMA1_CHANNEL5
#define IC_DMA_IRQ_NAME         DMA1_Channel5_4_IRQn

#define PHASE_A_GPIO_LOW        GPIO_PINS_1
#define PHASE_A_PIN_SOURCE_LOW  GPIO_PINS_SOURCE1
#define PHASE_A_GPIO_PORT_LOW   GPIOB
#define PHASE_A_GPIO_HIGH       GPIO_PINS_10
#define PHASE_A_PIN_SOURCE_HIGH  GPIO_PINS_SOURCE10
#define PHASE_A_GPIO_PORT_HIGH  GPIOA

#define PHASE_B_GPIO_LOW        GPIO_PINS_7
#define PHASE_B_PIN_SOURCE_LOW  GPIO_PINS_SOURCE7
#define PHASE_B_GPIO_PORT_LOW   GPIOA
#define PHASE_B_GPIO_HIGH       GPIO_PINS_9
#define PHASE_B_PIN_SOURCE_HIGH  GPIO_PINS_SOURCE9
#define PHASE_B_GPIO_PORT_HIGH  GPIOA

#define PHASE_C_GPIO_LOW        GPIO_PINS_0
#define PHASE_C_PIN_SOURCE_LOW  GPIO_PINS_SOURCE0
#define PHASE_C_GPIO_PORT_LOW   GPIOB
#define PHASE_C_GPIO_HIGH       GPIO_PINS_8
#define PHASE_C_PIN_SOURCE_HIGH  GPIO_PINS_SOURCE8
#define PHASE_C_GPIO_PORT_HIGH  GPIOA

#endif

#ifdef HARDWARE_GROUP_AT_045
#define PHASE_A_COMP  0x400000E1       //pa0     // works for polling mode
#define PHASE_B_COMP  0x400000C1       //pa4
#define PHASE_C_COMP  0x400000D1       //pa5
#endif
#ifdef HARDWARE_GROUP_AT_504
#define PHASE_A_COMP  0x400000D1       //pa5            // works for polling mode
#define PHASE_B_COMP  0x400000E1       //pa0       
#define PHASE_C_COMP  0x400000C1       //pa4       
#endif
#ifdef HARDWARE_GROUP_AT_450
#define PHASE_A_COMP  0x400000C1       //pa4            // works for polling mode
#define PHASE_B_COMP  0x400000D1       //pa5      
#define PHASE_C_COMP  0x400000E1       //pa0       
#endif
#ifdef HARDWARE_GROUP_AT_054
#define PHASE_A_COMP  0x400000E1       //pa0            // works for polling mode
#define PHASE_B_COMP  0x400000D1       //pa5       
#define PHASE_C_COMP  0x400000C1       //pa4      
#endif
#ifdef HARDWARE_GROUP_AT_405
#define PHASE_A_COMP  0x400000C1       //pa4            // works for polling mode
#define PHASE_B_COMP  0x400000E1       //pa0       
#define PHASE_C_COMP  0x400000D1       //pa5       
#endif
#ifdef HARDWARE_GROUP_AT_540
#define PHASE_A_COMP  0x400000D1       //pa5           // works for polling mode
#define PHASE_B_COMP  0x400000C1       //pa4       
#define PHASE_C_COMP  0x400000E1       //pa0       
#endif

#ifdef HARDWARE_GROUP_AT_245
#define PHASE_A_COMP  0x400000F1       //pa2     // works for polling mode
#define PHASE_B_COMP  0x400000C1       //pa4
#define PHASE_C_COMP  0x400000D1       //pa5
#endif

/************************************ MCU COMMON PERIPHERALS **********************************************/



/**************************************DEFAULT ADC INPUTS *************************************************/
#ifndef ADC_CHANNEL_CURRENT
#define ADC_CHANNEL_CURRENT  ADC_CHANNEL_6
#endif

#ifndef ADC_CHANNEL_VOLTAGE
#define ADC_CHANNEL_VOLTAGE  ADC_CHANNEL_3
#endif
#ifndef ADC_CHANNEL_TEMP
#define ADC_CHANNEL_TEMP     ADC_CHANNEL_16
#endif




/***************************************************************************/
#ifdef MCU_AT421
#define CPU_FREQUENCY_MHZ   120

#define EEPROM_START_ADD  (uint32_t)0x08007C00

#define INTERVAL_TIMER     TMR6
#define TEN_KHZ_TIMER      TMR14
#define UTILITY_TIMER      TMR17
#define COM_TIMER          TMR16
#define TIM1_AUTORELOAD    5000
#define APPLICATION_ADDRESS 0x08001000
#define EXTI_LINE   EXINT_LINE_21
#define TARGET_MIN_BEMF_COUNTS 8
#define USE_ADC
#define DSHOT_PRE            76
#endif

#ifdef MCU_AT415
#define CPU_FREQUENCY_MHZ   144

#define EEPROM_START_ADD  (uint32_t)0x08007C00

#define INTERVAL_TIMER     TMR4
#define TEN_KHZ_TIMER      TMR9
#define UTILITY_TIMER      TMR10
#define COM_TIMER          TMR11
#define TIM1_AUTORELOAD    6000
#define APPLICATION_ADDRESS 0x08001000
#define EXTI_LINE   EXINT_LINE_19
#define TARGET_MIN_BEMF_COUNTS 10
#define USE_ADC
#define DSHOT_PRE            95
#endif




