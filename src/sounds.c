/*
 * sounds.c
 *
 *  Created on: May 13, 2020
 *      Author: Alka
 */

#include "sounds.h"
#include "phaseouts.h"
#include "functions.h"
#include "eeprom.h"
#include "targets.h"
#include "common.h"


uint8_t beep_volume;

//uint8_t blueJayTuneBuffer[128] = {};

void pause(uint16_t ms){
	TMR1->c1dt = 0; // volume of the beep, (duty cycle) don't go above 25 out of 2000
	TMR1->c2dt = 0;
	TMR1->c3dt = 0;

	delayMillis(ms);
	TMR1->c1dt = beep_volume; // volume of the beep, (duty cycle) don't go above 25 out of 2000
	TMR1->c2dt = beep_volume;
	TMR1->c3dt = beep_volume;
}


void setVolume(uint8_t volume){
	if(volume > 11){
		volume = 11;
	}
	if(volume < 0){
		volume = 0;
	}
	beep_volume = volume * 2;           // volume variable from 0 - 11 equates to CCR value of 0-22
}

void setCaptureCompare(){
	TMR1->c1dt = beep_volume; // volume of the beep, (duty cycle) don't go above 25 out of 2000
	TMR1->c2dt = beep_volume;
	TMR1->c3dt = beep_volume;
}

void playBJNote(uint16_t freq, uint16_t bduration){        // hz and ms
	uint16_t timerOne_reload = TIM1_AUTORELOAD;
 
	TMR1->div = 10;
	timerOne_reload = CPU_FREQUENCY_MHZ*100000 / freq;
	
	TMR1->pr = timerOne_reload;
	TMR1->c1dt = beep_volume * timerOne_reload /TIM1_AUTORELOAD ; // volume of the beep, (duty cycle) don't go above 25 out of 2000
	TMR1->c2dt = beep_volume * timerOne_reload /TIM1_AUTORELOAD;
	TMR1->c3dt = beep_volume * timerOne_reload /TIM1_AUTORELOAD;

	delayMillis(bduration);
}


uint16_t getBlueJayNoteFrequency(uint8_t bjarrayfreq){
	return 10000000/(bjarrayfreq * 247 + 4000);
}

void playBlueJayTune(){
	uint8_t full_time_count = 0;
	uint16_t duration;
	float frequency;
	comStep(3);
	//read_flash_bin(blueJayTuneBuffer , EEPROM_START_ADD + 55 , 128);
	for(int i = 59 ; i < 183 ; i+=2){
	WDT->cmd = WDT_CMD_RELOAD;
		signaltimeout = 0;

		if(eepromBuffer[i] == 255){
			full_time_count++;

		}else{
			if(eepromBuffer[i+1] == 0){
				duration = full_time_count * 254 + eepromBuffer[i];
				TMR1->c1dt = 0 ; //
				TMR1->c2dt = 0;
				TMR1->c3dt = 0;
				delayMillis(duration);
			}else{
			frequency = getBlueJayNoteFrequency(eepromBuffer[i+1]);
			duration= (full_time_count * 254 + eepromBuffer[i])  * (float)(1000 / frequency);
			playBJNote(frequency, duration);
			}
			full_time_count = 0;
		}
	}
	allOff();                // turn all channels low again
	TMR1->div = 0;           // set prescaler back to 0.
	TMR1->pr = TIMER1_MAX_ARR;
	signaltimeout = 0;
WDT->cmd = WDT_CMD_RELOAD;
}

void playStartupTune(){
	__disable_irq();

	uint8_t value = *(uint8_t*)(EEPROM_START_ADD+55);
		if(value != 0xFF){
		playBlueJayTune();
		}else{
	TMR1->pr = TIM1_AUTORELOAD;
	setCaptureCompare();
	comStep(3);       // activate a pwm channel

	TMR1->div = 55;        // frequency of beep
  delayMillis(200);         // duration of beep
  comStep(5);
  WDT->cmd = WDT_CMD_RELOAD;
  TMR1->div = 40;            // next beep is higher frequency
	delayMillis(200);

	comStep(6);
	TMR1->div = 25;         // higher again..
	delayMillis(200);
	allOff();                // turn all channels low again
	TMR1->div = 0;           // set prescaler back to 0.
	signaltimeout = 0;
	}
	
	TMR1->pr = TIMER1_MAX_ARR;
	WDT->cmd = WDT_CMD_RELOAD;
	__enable_irq();
}

void playBrushedStartupTune(){
	__disable_irq();
	TMR1->pr = TIM1_AUTORELOAD;
	setCaptureCompare();
	comStep(1);       // activate a pwm channel
	TMR1->div = 40;        // frequency of beep
    delayMillis(300);         // duration of beep
	comStep(2);       // activate a pwm channel
	TMR1->div = 30;        // frequency of beep
    delayMillis(300);         // duration of beep
	comStep(3);       // activate a pwm channel
	TMR1->div = 25;        // frequency of beep
    delayMillis(300);         // duration of beep
    comStep(4);
	TMR1->div = 20;         // higher again..
	delayMillis(300);
	allOff();                // turn all channels low again
	TMR1->div = 0;           // set prescaler back to 0.
	signaltimeout = 0;
	TMR1->pr = TIMER1_MAX_ARR;
	__enable_irq();
}

//void playStartupTune(){    // diagnostic 6 beep
//	__disable_irq();
//	TMR1->pr = TIM1_AUTORELOAD;
//	setCaptureCompare();
//	comStep(1);       // activate a pwm channel
//	TMR1->div = 70;        // frequency of beep
//    delayMillis(500);         // duration of beep
//	pause(100);
//	comStep(2);       // activate a pwm channel
//	TMR1->div = 60;        // frequency of beep
//    delayMillis(500);         // duration of beep
//	pause(100);
//	comStep(3);       // activate a pwm channel
//	TMR1->div = 50;        // frequency of beep
//    delayMillis(500);         // duration of beep
//	pause(100);
//    comStep(4);
//	TMR1->div = 40;         // higher again..
//	delayMillis(500);
//	pause(100);
//	   comStep(5);
//	TMR1->div = 30;         // higher again..
//	delayMillis(500);
//	pause(100);
//	   comStep(6);
//	TMR1->div = 20;         // higher again..
//	delayMillis(500);
//	pause(100);
//	allOff();                // turn all channels low again
//	TMR1->div = 0;           // set prescaler back to 0.
//	TMR1->pr = TIMER1_MAX_ARR;
//	WDT->cmd = WDT_CMD_RELOAD;
//	__enable_irq();
//}


void playInputTune2(){
    TMR1->pr = TIM1_AUTORELOAD;
	__disable_irq();
WDT->cmd = WDT_CMD_RELOAD;
	TMR1->div = 60;
	setCaptureCompare();
	comStep(1);
	delayMillis(75);
	TMR1->div = 80;
	delayMillis(75);
	TMR1->div = 90;
WDT->cmd = WDT_CMD_RELOAD;
	delayMillis(75);
	allOff();
	TMR1->div = 0;
	signaltimeout = 0;
	TMR1->pr = TIMER1_MAX_ARR;
	__enable_irq();
}




void playInputTune(){
	__disable_irq();
	TMR1->pr = TIM1_AUTORELOAD;
WDT->cmd = WDT_CMD_RELOAD;
	TMR1->div = 80;
	setCaptureCompare();
	comStep(3);
	delayMillis(100);
	TMR1->div = 70;
	delayMillis(100);
	TMR1->div = 40;
	delayMillis(100);
	allOff();
	TMR1->div = 0;
	signaltimeout = 0;
	TMR1->pr = TIMER1_MAX_ARR;
	__enable_irq();
}

void playDefaultTone(){
	TMR1->pr = TIM1_AUTORELOAD;
	TMR1->div = 50;
	setCaptureCompare();
	comStep(2);
	delayMillis(150);
WDT->cmd = WDT_CMD_RELOAD;
	TMR1->div = 30;
	delayMillis(150);
	allOff();
	TMR1->div = 0;
	signaltimeout = 0;
	TMR1->pr = TIMER1_MAX_ARR;

}

void playChangedTone(){
	TMR1->pr = TIM1_AUTORELOAD;
	TMR1->div = 40;
	setCaptureCompare();
	comStep(2);
	delayMillis(150);
WDT->cmd = WDT_CMD_RELOAD;
	TMR1->div = 80;
	delayMillis(150);
	allOff();
	TMR1->div = 0;
	signaltimeout = 0;
	TMR1->pr = TIMER1_MAX_ARR;

}


void playBeaconTune3(){
	TMR1->pr = TIM1_AUTORELOAD;
	__disable_irq();
	setCaptureCompare();
	for(int i = 119 ; i > 0 ; i = i- 2){
WDT->cmd = WDT_CMD_RELOAD;
		comStep(i/20);
		TMR1->div = 10+(i / 2);
		delayMillis(10);
	}
	allOff();
	TMR1->div = 0;
	signaltimeout = 0;
	TMR1->pr = TIMER1_MAX_ARR;
	__enable_irq();
}
