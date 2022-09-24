/*
 * traffic_lights.h
 *
 * Created: 2022-09-14 2:39:43 AM
 *  Author: ahmed
 */ 


#ifndef TRAFFIC_LIGHTS_H_
#define TRAFFIC_LIGHTS_H_
#include "../LED/LED.h"
#include "../../MCAL/Timer0/timer0.h"

//The function that control the flow of the traffic light
function traffic_light (void);

//function that control the pedestrian button through interrupt
function isPedestrian(void);

#endif /* TRAFFIC_LIGHTS_H_ */