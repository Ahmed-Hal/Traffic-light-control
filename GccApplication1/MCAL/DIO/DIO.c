/*
 * DIO.c
 *
 * Created: 2022-09-05 3:07:31 PM
 *  Author: Ahmed
 */ 

#include "DIO.h"

//initialize pin direction in any port
void DIO_init(uint8_t port_num , uint8_t pin_num , uint8_t direction)
{
	switch(port_num)
	{
		case port_A:
		if (direction == output)
		{
			set_bit(DDRA,pin_num);
		}
		else if (direction == input)
		{
			clr_bit(DDRA,pin_num);
		}
		break;
		
		case port_B:
		if (direction == output)
		{
			set_bit(DDRB,pin_num);
		}
		else if (direction == input)
		{
			clr_bit(DDRB,pin_num);
		}
		break;
		
		case port_C:
		if (direction == output)
		{
			set_bit(DDRC,pin_num);
		}
		else if (direction == input)
		{
			clr_bit(DDRC,pin_num);
		}
		break;
		
		case port_D:
		if (direction == output)
		{
			set_bit(DDRD,pin_num);
		}
		else if (direction == input)
		{
			clr_bit(DDRD,pin_num);
		}
		break;
	}
	
}

//read the state of any pen in any port
void DIO_write(uint8_t port_num , uint8_t pin_num , uint8_t pin_state)
{
	switch(port_num)
	{
		case port_A:
		if (pin_state == high)
		{
			set_bit(PORTA,pin_num);
		}
		else if (pin_state == low)
		{
			clr_bit(PORTA,pin_num);
		}
		break;
		
		case port_B:
		if (pin_state == high)
		{
			set_bit(PORTB,pin_num);
		}
		else if (pin_state == low)
		{
			clr_bit(PORTB,pin_num);
		}
		break;
		
		case port_C:
		if (pin_state == high)
		{
			set_bit(PORTC,pin_num);
		}
		else if (pin_state == low)
		{
			clr_bit(PORTC,pin_num);
		}
		break;
		
		case port_D:
		if (pin_state == high)
		{
			set_bit(PORTD,pin_num);
		}
		else if (pin_state == low)
		{
			clr_bit(PORTD,pin_num);
		}
		break;
	}

}

//write the state of any pen in any port
void DIO_read(uint8_t port_num , uint8_t pin_num , uint8_t *value)
{
	switch(port_num)
	{
		case port_A:
			*value =(PINA & (1<<pin_num))>>pin_num;
		break;

		case port_B:
			*value =(PINB & (1<<pin_num))>>pin_num;
		break;

		case port_C:
			*value =(PINC & (1<<pin_num))>>pin_num;
		break;

		case port_D:
			*value =(PIND & (1<<pin_num))>>pin_num;
		break;

	}
}

//toggle the state of any pen in any port
void DIO_togle(uint8_t port_num , uint8_t pin_num)
{
		switch(port_num)
		{
			case port_A:
			tolge(PORTA,pin_num);
			break;

			case port_B:
			tolge(PORTB,pin_num);
			break;

			case port_C:
			tolge(PORTC,pin_num);
			break;

			case port_D:
			tolge(PORTD,pin_num);
			break;

		}

}

