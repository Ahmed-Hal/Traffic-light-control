/*
 * interrupt.c
 *
 * Created: 2022-09-13 11:02:37 PM
 *  Author: ahmed
 */ 
#include "interrupt.h"

//Global variable to save the chosen interrupt.
uint8_t INTnumber = 0;

void interrupt_init(uint8_t INT_NUMBER,uint8_t sense)
{
	//Global interrupt Enable
	set_bit(SREG,7);
	
	//save the value of the chosen interrupt to enable later
	INTnumber = INT_NUMBER;
	
	//Determine the sense control
	switch(INT_NUMBER)
	{
		case INT0:
		if(sense == rising)
		{
			//sense INT0 for rising edge
			set_bit(MCUCR,0);
			set_bit(MCUCR,1);
		}
		else if (sense == falling)
		{
			//sense INT0 for falling edge
			clr_bit(MCUCR,0);
			set_bit(MCUCR,1);
		}
		break;
		case INT1:
		if(sense == rising)
		{
			//sense INT1 for rising edge
			set_bit(MCUCR,2);
			set_bit(MCUCR,3);
		}
		else if (sense == falling)
		{
			//sense INT1 for falling edge
			clr_bit(MCUCR,2);
			set_bit(MCUCR,3);
		}
		break;
		
	}
}

//enable the interrupt chosen in the initialization function
void interrupt_enable(void)
{
	switch(INTnumber)
	{
		case INT0:
		//use INT0 interrupt
		set_bit(GICR,6);
		break;
		case INT1:
		//use INT1 interrupt
		set_bit(GICR,7);
		break;
	}
}
