/*
 * REGESTERS.h
 *
 * Created: 2022-09-05 1:25:28 PM
 *  Author: Ahmed Mustafa 
 */ 

/************************************************************************/
/*     >>>>>>>>>>>>> ALL MICROCONTRLLER REGISTERS <<<<<<<<<<<<          */
/************************************************************************/
#ifndef REGESTERS_H_
#define REGESTERS_H_

#include "types.h"
/************************************************************************/
/*                     DIO REGISTERS                                    */
/************************************************************************/
//portA Registers
#define PORTA *((volatile uint8_t*)0x3B)
#define DDRA *((volatile uint8_t*)0x3A)
#define PINA *((volatile uint8_t*)0x39)

//portB Registers
#define PORTB *((volatile uint8_t*)0x38)
#define DDRB *((volatile uint8_t*)0x37)
#define PINB *((volatile uint8_t*)0x36)

//portC Registers
#define PORTC *((volatile uint8_t*)0x35)
#define DDRC *((volatile uint8_t*)0x34)
#define PINC *((volatile uint8_t*)0x33)

//portD Registers
#define PORTD *((volatile uint8_t*)0x32)
#define DDRD *((volatile uint8_t*)0x31)
#define PIND *((volatile uint8_t*)0x30)
/************************************************************************/
/*                           TIMER0 REGISTER                            */
/************************************************************************/
// TCCR0 – Timer/Counter Control Register
#define TCCR0 *((volatile uint8_t*)0x53)
// TCNT0 – Timer/Counter Register
#define TCNT0 *((volatile uint8_t*)0x52)
//TIFR – Timer/Counter Interrupt Flag Register
#define TIFR *((volatile uint8_t*)0x58)
/************************************************************************/
/*                        Interrupts Registers                          */
/************************************************************************/
// SREG – AVR Status Register
#define SREG *((volatile uint8_t*)0x5F)
//MCUCR – MCU Control Register
#define MCUCR *((volatile uint8_t*)0x55)
// GICR – General Interrupt Control Register
#define GICR *((volatile uint8_t*)0x5B)
//GIFR – General Interrupt Flag Register
#define GIFR *((volatile uint8_t*)0x5A)

#endif /* REGESTERS_H_ */