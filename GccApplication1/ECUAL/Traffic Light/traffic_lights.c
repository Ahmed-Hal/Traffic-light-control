/*
 * traffic_lights.c
 *
 * Created: 2022-09-14 2:40:02 AM
 *  Author: ahmed
 */ 
#include "traffic_lights.h"

//variables to chick which traffic light Was on
uint8_t A0_value = 0, A1_value = 0, A2_value = 0, Yellow_blinking = 0,
INT_flag = 0,				//interrupt flag to start pedestrian mood
wasYellowON = 0,			//flag to indicate if led is yellow at the end of pedestrian mood 
isNowPedestrian = 0;		//flag to know whether pedestrian mood is ON or Not


function traffic_light (void)
{
	wasYellowON = 0;
	
	if (INT_flag == 0)										//If No Flag						First >> Green LED ON in Normal Mood
	{
		
		LED_ON(port_A,0);									//cars green LED ON					>>Cars Can Cross
		delayT0_ms(5000);
		LED_OFF(port_A,0);									//cars green LED OFF
		
	}
	if (INT_flag == 1)										//If Flag There			
	{
		isNowPedestrian = 1;								// now we're in pedestrian mood
		LED_OFF(port_B,2);									//man red led OFF					>> Was turned When Button Was Clicked
		
		blink_2_LEDs(port_A,1,port_B,1,5000);				//man & car yellow blink			>>Man Get ready to Cross the Road
															//									>>Cars Get ready to Stop
						
		LED_ON(port_B,0);									//man green led ON					>> Man Can Cross The Road
		LED_ON(port_A,2);									//cars red led ON					>> Cars Stop
		delayT0_ms(5000);		
		LED_OFF(port_A,2);									//cars red led OFF
				
		blink_2_LEDs(port_A,1,port_B,1,5000);				//man & car yellow leds Blink					|man Get Off The Pedestrian |car Get Ready to Move
 
		wasYellowON = 1;									//yellow was blinking for 5 Secs
		
		LED_OFF(port_B,0);									//man green led OFF
		INT_flag = 0;
		isNowPedestrian = 0;								// Pedestrian Mood Ended
	}

		
	if (INT_flag == 0 && wasYellowON == 0)
	{
		Yellow_blinking = 1;
		blink_LED(port_A,1,5000);
		Yellow_blinking = 0;
		LED_OFF(port_B,2);									//man red led OFF					>> Was turned When Button Was Clicked
	}
	if (INT_flag == 1)
	{
		isNowPedestrian = 1;								// now we're in pedestrian mood
		
		LED_ON(port_B,0);									//man green led ON					>> Man Can Cross The Road
		LED_ON(port_A,2);									//cars red led ON					>> Cars Stop
		delayT0_ms(5000);
		LED_OFF(port_A,2);									//cars red led OFF
		
		blink_2_LEDs(port_A,1,port_B,1,5000);				//man & car yellow leds Blink					|man Get Off The Pedestrian |car Get Ready to Move

		wasYellowON = 1;									//yellow was blinking for 5 Secs
		
		LED_OFF(port_B,0);									//man green led OFF
		INT_flag = 0;
		isNowPedestrian = 0;								// Pedestrian Mood Ended
	}
	
	if (INT_flag == 0 && wasYellowON == 0)
	{
		LED_ON(port_A,2);									//cars Red LED ON					>> Cars Stop
		delayT0_ms(5000);
		LED_OFF(port_A,2);									//cars Red LED OFF
	}
	if (INT_flag == 1)
	{
		isNowPedestrian = 1;								// now we're in pedestrian mood
		
		LED_ON(port_A,2);									//cars red led ON					>> Cars Keep Waiting 5 more seconds
		delayT0_ms(5000);
		LED_OFF(port_A,2);									//cars red led OFF
				
		blink_2_LEDs(port_A,1,port_B,1,5000);				//man & car yellow leds Blink					|man Get Off The Pedestrian |car Get Ready to Move

		LED_OFF(port_B,0);									//man green led OFF
		INT_flag = 0;
		isNowPedestrian = 0;								// Pedestrian Mood Ended
	}
	return OK;
}

function isPedestrian(void)
{
	
	DIO_read(port_A,0,&A0_value);		//chick green led state
	DIO_read(port_A,2,&A2_value);		//chick red led state
	
	//If LED was green or Yellow and isn't in pedestrian mood
	if((A0_value == high || Yellow_blinking == high) && (isNowPedestrian == 0))
	{
		//raise the pedestrian interrupt flag
		INT_flag = 1;
		
		//Turn pedestrian red LED ON
		LED_ON(port_B,2);
	}
	//If LED was red and isn't in pedestrian mood
	else if((A2_value == high) && (isNowPedestrian == 0))
	{
		//raise the pedestrian interrupt flag
		INT_flag = 1;
		
		//Turn pedestrian Green LED ON
		LED_ON(port_B,0);
	}
	return OK;
}