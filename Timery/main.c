#include <LPC21xx.H> 

#include "led.h"
#include "keyboard.h"
#include "timer.h"


int main(){

	LedInit();
	InitTimer0Match0(2024);

	while(1){
		WaitOnTimer0Match0();
		LedStepRight();
	}
}








