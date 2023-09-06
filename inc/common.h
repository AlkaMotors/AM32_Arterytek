#pragma once
#include "main.h"

// 18 is the max buffer_padding selected in IO.c
#define GCR_BUFFER_SIZE (23 + 18)

extern uint8_t eepromBuffer[176];
extern uint16_t TIMER1_MAX_ARR;

extern uint32_t gcr[GCR_BUFFER_SIZE];
extern uint16_t adjusted_input;
extern uint32_t dma_buffer[64];
extern uint8_t dshotcommand;
extern uint16_t armed_count_threshold;
extern char forward;
extern uint8_t running;
extern uint16_t zero_input_count;
extern uint16_t signaltimeout;
extern uint16_t input;
extern uint16_t newinput;
extern char play_tone_flag;
extern uint32_t current_GPIO_PIN;
extern uint32_t current_GPIO_PORT;
extern uint32_t current_EXTI_LINE;
extern char dshot_extended_telemetry;
extern uint16_t send_extended_dshot;
extern uint8_t buffer_padding;

extern uint16_t comp_change_time;
extern uint16_t interrupt_time;

//typedef struct PID{
//	float error;
//	float Kp;
//	float Ki;
//	float Kd;
//	float integral;
//	float derivative;
//	float last_error;
//	float pid_output;
//	int16_t integral_limit;
//	int16_t output_limit;
//}PID;

typedef struct fastPID{
	int32_t error;
	uint32_t Kp;
	uint32_t Ki;
	uint32_t Kd;
	int32_t integral;
	int32_t derivative;
	int32_t last_error;
	int32_t pid_output;
	int32_t integral_limit;
	int32_t output_limit;
}fastPID;


