/*
* DIO.c
*
* Created: 09-Aug-22 8:59:05 AM
*  Author: Peter
*/

#include "DIO.h"

int initDIO(uint8_t portNumber, uint8_t pinNumber,uint8_t state)
{
	//set the required pin to output
	if (state == OUTPUT)
	{
		switch(portNumber)
		{
			case PORT_A:
			DDRA |= (1<<pinNumber); //set the bit without affecting other bits in the register
			break;
			
			case PORT_B:
			DDRB |= (1<<pinNumber); //set the bit without affecting other bits in the register
			break;
			
			case PORT_D:
			DDRD |= (1<<pinNumber); //set the bit without affecting other bits in the register
			break;
			
			default:
			return 1; //error unknown portNumber
		}
	}
	//set the required pin to input
	else if(state == INPUT)
	{
		switch(portNumber)
		{
			case PORT_A:
			DDRA &= ~(1<<pinNumber); //reset the bit without affecting the other bits in the register
			break;
			
			case PORT_B:
			DDRB &= ~(1<<pinNumber); //reset the bit without affecting the other bits in the register
			break;
			
			case PORT_D:
			DDRD &= ~(1<<pinNumber); //reset the bit without affecting the other bits in the register
			break;
			
			default:
			return 1; //error unknown portNumber
		}
	}
	else
	{
		return 1; //error unknown state
	}
	return 0; //successful operation
}

int enInterrupt(uint8_t INTx)
{
	//enable an external interrupt
	switch(INTx)
	{
		case INT_0:
		initDIO(PORT_D,2,INPUT); //ensure the pin is initialized to input
		MCUCR |= (1<<ISC00) | (1<<ISC01); //generate interrupt request on rising edge
		GICR |= (1<<INT0); //enable interrupt
		break;
		
		default:
		return 1; //error unknown interrupt
	}
	return 0; //successful operation
}

int writeDIO(uint8_t portNumber, uint8_t pinNumber,uint8_t value)
{
	//set the required pin output to high
	if (value == HIGH)
	{
		switch(portNumber)
		{
			case PORT_A:
			PORTA |= (1<<pinNumber); //set the bit without affecting other bits in the register
			break;
			
			case PORT_B:
			PORTB |= (1<<pinNumber); //set the bit without affecting other bits in the register
			break;
			
			case PORT_D:
			PORTD |= (1<<pinNumber); //set the bit without affecting other bits in the register
			break;
			
			default:
			return 1; //error unknown portNumber
		}
	}
	//set the required pin output to low
	else if(value == LOW)
	{
		switch(portNumber)
		{
			case PORT_A:
			PORTA &= ~(1<<pinNumber); //reset the bit without affecting the other bits in the register
			break;
			
			case PORT_B:
			PORTB &= ~(1<<pinNumber); //reset the bit without affecting the other bits in the register
			break;
			
			case PORT_D:
			PORTD &= ~(1<<pinNumber); //reset the bit without affecting the other bits in the register
			break;
			
			default:
			return 1; //error unknown portNumber
		}
	}
	else
	{
		return 1; //error unknown value
	}
	return 0; //successful operation
}