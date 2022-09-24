/*
 * LED.h
 *
 * Created: 2022-09-07 2:31:10 AM
 *  Author: ahmed
 */ 

//LED.h

#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO/DIO.h"


//Initialize a pin in a port to have an LED
function LED_init(uint8_t portNumber, uint8_t pinNumber);

//Turn on LED that's on pin x of Port X 
function LED_ON(uint8_t portNumber, uint8_t pinNumber);

//Turn off LED that's on pin x of Port X
function LED_OFF(uint8_t portNumber, uint8_t pinNumber);

//Toggle LED that's on pin x of Port X
function LED_TOGLE(uint8_t portNumber, uint8_t pinNumber);

//Blink the led for a defined amount of time in ms
function blink_LED(uint8_t portNumber, uint8_t pinNumber, uint32_t Time);

//Blink 2 LEDs for a defined amount of time in ms
function blink_2_LEDs(uint8_t _1_portNumber, uint8_t _1_pinNumber,uint8_t _2_portNumber, uint8_t _2_pinNumber, uint32_t Time);

#endif /* LED_H_ */