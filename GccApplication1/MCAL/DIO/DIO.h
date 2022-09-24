/*
 * DIO.h
 *
 * Created: 2022-09-05 3:07:46 PM
 *  Author: ahmed
 */ 

//DIO.h
#ifndef DIO_H_
#define DIO_H_

#include "../registers/registers.h"

//MACROS to set , clear or toggle bits
#define set_bit(x,Bit_num) x|=(1<<Bit_num)
#define clr_bit(x,Bit_num) x&=~(1<<Bit_num)
#define tolge(x,Bit_num) x^=(1<<Bit_num)

//ports macros
#define port_A 'A'
#define port_B 'B'
#define port_C 'C'
#define port_D 'D'

//pin direction
#define input  0
#define output 1

//PIN STATE
#define low  0
#define high 1

/***************** Functions Prototypes ****************/

//initialize pin direction in any port
void DIO_init(uint8_t port_num , uint8_t pin_num , uint8_t direction);
//read the state of any pen in any port
void DIO_read(uint8_t port_num , uint8_t pin_num , uint8_t* value);
//write the state of any pen in any port
void DIO_write(uint8_t port_num , uint8_t pin_num , uint8_t pin_state);
//toggle the state of any pen in any port
void DIO_togle(uint8_t port_num , uint8_t pin_num);

#endif /* DIO_H_ */