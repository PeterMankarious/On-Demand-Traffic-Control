/*
 * LED.c
 *
 * Created: 09-Aug-22 10:34:17 AM
 *  Author: Peter
 */ 

#include "LED.h"

uint8_t glb_blinks; //global number of blinks, used to help in reseting blinker


int initLED(uint8_t ledPort, uint8_t ledPin)
{
	initDIO(ledPort, ledPin, OUTPUT); //initialize the LED pin as output
	return 0; //successful operation
}

int onLED(uint8_t ledPort, uint8_t ledPin)
{
	writeDIO(ledPort, ledPin, HIGH); //write high on the LED's pin to turn it on
	return 0; //successful operation
}

int offLED(uint8_t ledPort, uint8_t ledPin)
{
	writeDIO(ledPort, ledPin, LOW); //write low on the LED's pin to turn it off
	return 0; //successful operation
}

int blinkLED(uint8_t ledPort, uint8_t ledPin, float time_per_blink, uint8_t number_of_blinks)
{
	//blink a set number of times with a set time for each blink in milliseconds.
	uint8_t i= 0;
	glb_blinks = number_of_blinks;
	//repeat for required number of blinks
	for(i = 0; i< glb_blinks; i++)
	{
		//turn on for half the blink time
		onLED(ledPort, ledPin);
		setTimer0(time_per_blink/2.0);
		
		//turn off for half the blink time
		offLED(ledPort, ledPin);
		setTimer0(time_per_blink/2.0);
	}
	return 0; //successful operation
}

int blink2LED(uint8_t ledPort1, uint8_t ledPin1,uint8_t ledPort2, uint8_t ledPin2, float time_per_blink, uint8_t number_of_blinks)
{
		//blink a set number of times with a set time for each blink in milliseconds.
		uint8_t i;
		glb_blinks = number_of_blinks;
		//repeat for required number of blinks
		for(i = 0; i< glb_blinks; i++)
		{
			//turn on for half the blink time
			onLED(ledPort1, ledPin1);
			onLED(ledPort2, ledPin2);
			setTimer0(time_per_blink/2.0);
			
			//turn off for half the blink time
			offLED(ledPort1, ledPin1);
			offLED(ledPort2, ledPin2);
			setTimer0(time_per_blink/2.0);
		}
		return 0; //successful operation
}

int resetBlinker()
{
	glb_blinks = 0; //makes for loop in blink functions end after its current iteration.
	return 0; //successful operation
}