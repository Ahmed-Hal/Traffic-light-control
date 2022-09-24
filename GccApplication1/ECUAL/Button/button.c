/*
 * button.c
 *
 * Created: 2022-09-06 11:56:17 AM
 *  Author: ahmed
 */ 
#include "button.h"

//initialize Button as Input in pinX of PortX
function button_init(uint8_t buttonPort, uint8_t buttonPin)
{
	DIO_init(buttonPort,buttonPin,input); 
	return OK;
}

//read button value of PinX of PortX
function button_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value)
{
	DIO_read(buttonPort,buttonPin,value);
	return OK;
}
