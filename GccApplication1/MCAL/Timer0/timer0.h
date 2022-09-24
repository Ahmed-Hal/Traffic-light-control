/*
 * timer0.h
 */ 

#ifndef TIMER0_H_
#define TIMER0_H_

#include "../DIO/DIO.h"
#include <math.h>



//CPU frequency 
#define CPU_frequency 1000000

//timer Mood Macros 
#define Normal 'N'
#define PWM_paseCorrect 'O'
#define PWM_fast 'p'
#define CTC	'Q'

//initiate timer0
void timer0_init(uint8_t timerMood);
//set timer0 delay 
void delayT0_ms(double delay);

#endif /* TIMER0_H_ */