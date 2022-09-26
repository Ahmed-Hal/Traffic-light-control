/*
 * app.c
 *
 * Created: 2022-09-07 1:54:52 AM
 *  Author: ahmed
 */ 

#include "app.h"

//Application initialization
function App_init()
{
	LED_init(port_A,0);			//Initialize cars green led as output
	
	LED_init(port_A,1);			//Initialize cars yellow led as output
	
	LED_init(port_A,2);			//Initialize cars red led as output
	
	LED_init(port_B,0);			//Initialize pedestrian green led as output
	
	LED_init(port_B,1);			//Initialize pedestrian yellow led as output
	
	LED_init(port_B,2);			//Initialize pedestrian red led as output
	
	interrupt_init(INT0,rising);//Initialize interrupt pin and sense
	
	button_init(port_D,2);		//Initialize Button as an Input
	
	timer0_init(Normal);		//Initialize Timer0 in Normal Mood
return OK;
}

//Application start
function App_start()
{		
	
	interrupt_enable();			//enable Interrupt register initialized above
	while(1)
	{
		traffic_light();		//Start traffic light flow
	}
return OK;
}
//Interrupt Service Routine (ISR)
ISR(EXT_INT_0)
{
	isPedestrian();				//button is pressed > Chick if now is pedestrian mood and act on it
}