/*
 * LED.c
 *
 * Created: 2022-09-07 2:30:58 AM
 *  Author: ahmed
 */ 
//LED.c

#include "LED.h"
#include "../../MCAL/Timer0/timer0.h"
#define Time_between_blinks 300
uint8_t blinks_count = 0;
volatile uint8_t counter;
//Initialize a pin in a port to have an LED
function LED_init(uint8_t portNumber, uint8_t pinNumber)
{
	DIO_init(portNumber, pinNumber, output);
	return OK;
}

//Turn on LED that's on pin x of Port X
function LED_ON(uint8_t portNumber, uint8_t pinNumber)
{
	DIO_write(portNumber,pinNumber,high);
	return OK;
}

//Turn off LED that's on pin x of Port X
function LED_OFF(uint8_t portNumber, uint8_t pinNumber)
{
	DIO_write(portNumber,pinNumber,low);
	return OK;
}

//Toggle LED that's on pin x of Port X
function LED_TOGLE(uint8_t portNumber, uint8_t pinNumber)
{
	DIO_togle(portNumber,pinNumber);
	return OK;
}

function blink_LED(uint8_t portNumber, uint8_t pinNumber, uint32_t Time)
{
	//determine the number of blinks based on the total blinking time divided by the single blink time
	blinks_count = (Time/Time_between_blinks)/2; // and divide all that by 2 because we have two delays
	for (counter = 0;counter < blinks_count;counter++)
	{
		LED_ON(portNumber,pinNumber);
		delayT0_ms(Time_between_blinks);
		LED_OFF(portNumber,pinNumber);
		delayT0_ms(Time_between_blinks);
	}
	return OK;
}
function blink_2_LEDs(uint8_t _1_portNumber, uint8_t _1_pinNumber,uint8_t _2_portNumber, uint8_t _2_pinNumber, uint32_t Time)
{
	//determine the number of blinks based on the total blinking time divided by the single blink time
	blinks_count = (Time/Time_between_blinks)/2; // and divide all that by 2 because we have two delays
	for (counter = 0;counter < blinks_count;counter++)
	{
		LED_ON(_1_portNumber,_1_pinNumber);
		LED_ON(_2_portNumber,_2_pinNumber);
		delayT0_ms(Time_between_blinks);
		LED_OFF(_1_portNumber,_1_pinNumber);
		LED_OFF(_2_portNumber,_2_pinNumber);
		delayT0_ms(Time_between_blinks);
	}
	return OK;
}