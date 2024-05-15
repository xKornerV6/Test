#include <LPC21xx.H>

#include "led.h"

#define LED0_bm (1<<16) 
#define LED1_bm (1<<17)
#define LED2_bm (1<<18)
#define LED3_bm (1<<19)

enum eStepDirections {LEFT,RIGHT};

void LedInit()
	{
		IO1DIR = LED0_bm|LED1_bm|LED2_bm|LED3_bm;
		IO1SET = LED0_bm;
	}
void LedOn(unsigned char ucLedIndeks){
	IO1CLR = LED0_bm|LED1_bm|LED2_bm|LED3_bm;
	switch(ucLedIndeks){
		case(0):
			IO1SET = LED0_bm;
			break;
		case(1):
			IO1SET = LED1_bm;
			break;
		case(2):
			IO1SET = LED2_bm;
			break;
		case(3):
			IO1SET = LED3_bm;
			break;
		default:
			break;
	}
}


void LedStep(enum eStepDirections eDirection){
	static unsigned char ucLedNumber;
	switch(eDirection){
		case LEFT:
			ucLedNumber++;
			break;
		case RIGHT:
			ucLedNumber--;
			break;
		default:
			break;
	}
	LedOn(ucLedNumber%4);
}

void LedStepLeft(void){
	LedStep(LEFT);
}

void LedStepRight(void){
	LedStep(RIGHT);
}
