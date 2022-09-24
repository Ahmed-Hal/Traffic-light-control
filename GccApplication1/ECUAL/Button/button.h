/*
 * button.h
 *
 * Created: 2022-09-06 11:56:42 AM
 *  Author: ahmed
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/DIO/DIO.h"

//initialize Button as Input in pinX of PortX
function button_init(uint8_t buttonPort, uint8_t buttonPin);

//read button value of PinX of PortX
function button_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value);

#endif /* BUTTON_H_ */