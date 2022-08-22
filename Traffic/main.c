/*
* Testing_2.c
*
* Created: 11-Aug-22 8:22:45 AM
* Author : Peter
*/


#include "Application/app.h"

int main(void)
{ 
	initApp();
	
	while(1)
	{
		runApp();
	}
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	/* SREG |= 1<<7;
	initButton(INT_0); //enInterrupt(INT_0);
	initLED(PORT_B, 1);//initDIO(PORT_B,1,OUTPUT);
	onLED(PORT_B, 1); //writeDIO(PORT_B,1,HIGH);
	//MCUCR |= (1) | (1<<1);
	//GICR |= 1<<6;
	
	while (1)
	{
		onLED(PORT_B, 1); //writeDIO(PORT_B,1, LOW);
		setTimer0(3000);
		offLED(PORT_B, 1); //writeDIO(PORT_B,1,HIGH);
		setTimer0(3000);
		
		blinkLED(PORT_B,1,1000,4);
		setTimer0(4000);
		
		
			if (flag_1)
			{
				writeDIO(PORT_B,1,HIGH);
			}
			else
			{
				writeDIO(PORT_B,1,LOW);
			} 
	}
*/

