/*
 * comparator.c
 *
 *  Created on: Sep. 26, 2020
 *      Author: Alka
 */

#include "comparator.h"
#include "targets.h"


void maskPhaseInterrupts(){
	EXINT->inten &= ~EXTI_LINE;
	EXINT->intsts = EXTI_LINE;
}

void enableCompInterrupts(){
	EXINT->inten |= EXTI_LINE;
}


void changeCompInput()
{
#ifdef MCU_AT415
	if (step == 1 || step == 4)
	{   // c floating
	CMP->ctrlsts1 = PHASE_C_COMP;
	}
	if (step == 2 || step == 5)
	{   // a floating	
		CMP->ctrlsts1 = PHASE_A_COMP;
	}
	if (step == 3 || step == 6)
	{   // b floating
		CMP->ctrlsts1 = PHASE_B_COMP;
	}
#endif
#ifdef MCU_AT421	
if (step == 1 || step == 4)
	{   // c floating
	CMP->ctrlsts = PHASE_C_COMP;
	}
	if (step == 2 || step == 5)
	{   // a floating	
		CMP->ctrlsts = PHASE_A_COMP;
	}
	if (step == 3 || step == 6)
	{   // b floating
		CMP->ctrlsts = PHASE_B_COMP;	
	}
#endif	
	if (rising)
	{
     EXINT->polcfg1 &= ~(uint32_t)EXTI_LINE;
     EXINT->polcfg2 |= (uint32_t)EXTI_LINE;
		
	}else{
		 EXINT->polcfg1 |= (uint32_t)EXTI_LINE;
     EXINT->polcfg2 &= ~(uint32_t)EXTI_LINE;
	}


}
