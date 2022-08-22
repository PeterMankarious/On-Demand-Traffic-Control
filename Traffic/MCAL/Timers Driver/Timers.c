/*
 * Timers.c
 *
 * Created: 09-Aug-22 10:45:39 AM
 *  Author: Peter
 */ 

#include <math.h>
#include "Timers.h"

#define F_CPU 16000000 //16 MHz

volatile uint8_t debugger = 0;
volatile uint32_t N_overflows; //Number of overflows needed to get required time. volatile since it is only changed in the ISR
volatile uint8_t timer0_done; //Flag used to detect when timer is finished.
volatile uint8_t initial; //value that needs to be set to TCNT0 in each overflow to get required time.

ISR(TIMER0_OVF)
{
	if (N_overflows > 0)
	{
		N_overflows--;
		TCNT0 = initial;
	}
	else
	{
		timer0_done = 1;
	}
}

int setTimer0(float ms) //Sets a delay in milliseconds
{
	//reset flag
	timer0_done = 0;
	//initialize normal mode
	TCCR0 &= ~(1<<WGM00); TCCR0 &= ~(1<<WGM01);
	
	//calculate and write to TCNT0
	uint16_t prescaler = 1024;
	float Ttick = (float)prescaler / F_CPU; //timer per tick
	float Tmax_delay = 256 * Ttick;  //max delay, 256 is 2^8 since timer 0 is an 8 bit timer
	N_overflows = ceil( ms*0.001 / Tmax_delay ); //uint32 used to avoid overflow of the data, this will allow delay up to 274878 seconds. uint16 would have max of 4.2 seconds.
	initial = 256 - ( ms*0.001 / Ttick ) / N_overflows;
	TCNT0 = initial;
	/*
		Example with ms = 5000
		Ttick = 6.4e-5 seconds
		Tmax_delay = 0.016384 seconds
		N_overflows = 306
		initial = 0.6895... = 0
	*/
	
	//activate interrupt
	TIMSK |= 1<<TOIE0;
	
	//use prescaler 1/1024
	TCCR0 |= 1<< CS02; TCCR0 &= ~(1<< CS01); TCCR0 |= 1<< CS00; 
	
	while(!(timer0_done)) 
	{
		debugger = 1;
	}
	TCCR0 &= ~(1<< CS02); TCCR0 &= ~(1<< CS01); TCCR0 &= ~(1<< CS00); //turn off timer0
	
	return 0; //successful operation
}


int resetTimer0() //makes the timer finish its time within maximum 1 Tmax_delay (16 milliseconds)
{
	N_overflows = 0; //used in the ISR to signify end of timer period
	
	return 0;
}