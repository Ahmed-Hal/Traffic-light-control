/*
 * app.h
 *
 * Created: 2022-09-07 1:55:04 AM
 *  Author: ahmed
 */ 


#ifndef APP_H_
#define APP_H_
//#include "../MCAL/DIO/DIO.h"
#include "../ECUAL/Button/button.h"
#include "../ECUAL/LED/LED.h"
#include "../MCAL/Timer0/timer0.h"
#include "../MCAL/Interrupts/interrupt.h"
#include "../ECUAL/Traffic Light/traffic_lights.h"

	
//Application initialization
function App_init();


//Application start
function App_start();



#endif /* APP_H_ */