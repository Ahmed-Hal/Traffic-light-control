/*
 * interrupt.h
 *
 * Created: 2022-09-13 11:02:22 PM
 *  Author: ahmed
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_
#include "../registers/registers.h"
#include "../DIO/DIO.h"
//sense control macros
#define falling 'F'
#define rising 'R'
//interrupt control macros
#define INT0 2
#define INT1 3

//External Interrupt Request 0
#define EXT_INT_0 __vector_1

//External Interrupt Request 1
#define EXT_INT_1 __vector_2

//Macro Defining the ISR
#define ISR(INT_VECT) void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)

//Enable global interrupt and determine interrupt sense and control 
void interrupt_init( uint8_t INT_NUMBER,uint8_t sense);

//enable the interrupt chosen in the initialization function
void interrupt_enable(void);

#endif /* INTERRUPT_H_ */