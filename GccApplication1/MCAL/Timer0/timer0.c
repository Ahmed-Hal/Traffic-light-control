/*
 * timer0.c
 * */ 
#include "timer0.h"

double T_tick = 0,T_maxDelay = 0;
uint32_t overflowsNumber = 0, T_initValue = 0, overflowCounter = 0;

//initiate timer with the needed mood
void timer0_init(uint8_t timerMood)
{
	//Chose Mood of Operation
	switch(timerMood)
	{
		case Normal: 
		TCCR0 = 0x00;
		break;
		case PWM_paseCorrect:
		TCCR0 = 0x40;
		break;
		case CTC:
		TCCR0 = 0x08;
		break;
		case PWM_fast:
		TCCR0 = 0x48;
		break;
	}

}

//Set Needed Delay
void delayT0_ms(double delay)
{
	//convert delay to Ms
	delay = delay/1000;
	
	//calculate tick time 
	T_tick = 1.0/CPU_frequency;
	
	//calculate max delay time
	T_maxDelay = 256*T_tick;
	
	//calculate overflow flag count
	overflowsNumber = ceil((delay)/T_maxDelay);
	
	//calculate the timer initial value 
	T_initValue = 256 - ((delay)/T_tick)/overflowsNumber;
	
	//set timer initial value
	TCNT0 = T_initValue;
	
	//start timer in no prescaling mood
	set_bit(TCCR0,0);
	
	//Make a loop to count the overflows
	overflowCounter = 0;
	while (overflowCounter < overflowsNumber)
	{
		
		//wait until overflow flag =1
		while ((TIFR &(1<<0)) == 0);
		
		//clear overflow flag
		set_bit(TIFR,0);
		
		overflowCounter++;
	}
	overflowCounter = 0;
	TCCR0 = 0x00;
	
}
