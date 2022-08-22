/*
 * LED.h
 *
 * Created: 09-Aug-22 10:34:07 AM
 *  Author: Peter
 */ 


#ifndef LED_H_
#define LED_H_

//Includes
#include "../../MCAL/DIO Driver/DIO.h"
#include "../../MCAL/Timers Driver/Timers.h"

//Function prototypes
int initLED(uint8_t ledPort, uint8_t ledPin); //initialize LED pin to be output

int onLED(uint8_t ledPort, uint8_t ledPin); //turn on LED

int offLED(uint8_t ledPort, uint8_t ledPin); //turn off LED

int blinkLED(uint8_t ledPort, uint8_t ledPin, float time_per_blink, uint8_t number_of_blinks); //turn on LED then off (blink)

int blink2LED(uint8_t ledPort1, uint8_t ledPin1,uint8_t ledPort2, uint8_t ledPin2, float time_per_blink, uint8_t number_of_blinks); //blink 2 LEDs at the same time

int resetBlinker(); //stops blinker

#endif /* LED_H_ */