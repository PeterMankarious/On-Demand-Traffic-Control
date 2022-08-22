/*
 * app.c
 *
 * Created: 09-Aug-22 10:01:49 AM
 *  Author: Peter
 */ 

#include "app.h"

volatile uint8_t mode; //normal or pedestrian
volatile uint8_t normal_stage; //green, yellow or red stage
volatile uint8_t pedestrian_stage; //green, yellow or red stage
volatile uint8_t direction; //to red, or to green. used in yellow stage to know the next stage.
volatile uint8_t pedestrian_done; //starts with 0 and becomes 1 when pedestrian mode operations are done.

void initApp()
{	
	//enable global interrupt
	SREG |= 1<<7;
	//initialize button
	initButton(Button_1_INT);
	//initialize LEDs and turn them all off
	initLED(Normal_Port,Green_Pin); offLED(Normal_Port,Green_Pin);
	initLED(Normal_Port,Yellow_Pin); offLED(Normal_Port,Yellow_Pin);
	initLED(Normal_Port,Red_Pin); offLED(Normal_Port,Red_Pin);
	initLED(Pedestrian_Port,Green_Pin); offLED(Pedestrian_Port,Green_Pin);
	initLED(Pedestrian_Port,Yellow_Pin); offLED(Pedestrian_Port,Yellow_Pin);
	initLED(Pedestrian_Port,Red_Pin); offLED(Pedestrian_Port,Red_Pin);
	//start in normal mode
	mode = Normal_Mode;
	//start in red stage
	normal_stage = Red_Stage;
	//starting from red so going to green
	direction = toGreen;
}

void runApp() //should be put inside a while loop
{
	if (mode == Normal_Mode)
	{
		switch(normal_stage)
		{
			case Red_Stage: //turn on normal red LED for 5 seconds then go to next stage
			onLED(Normal_Port, Red_Pin);
			setTimer0(5000); //5000ms = 5 seconds
			offLED(Normal_Port, Red_Pin);
			normal_stage = Yellow_Stage;
			break;
			
			case Yellow_Stage://blink yellow LED for 5 seconds then go to next stage
			blinkLED(Normal_Port, Yellow_Pin, 1000, 5); //blink 5 times for 1 second each
			if(direction == toGreen)
			{
				normal_stage = Green_Stage; //next stage is green
				direction = toRed; //next time yellow stage is passed, the next stage will be red
			}
			else if(direction == toRed)
			{
				normal_stage = Red_Stage; //next stage is red
				direction = toGreen; //next time yellow stage is passed, the next stage will be green
			}
			break;
			
			case Green_Stage: //turn on normal green LED for 5 seconds then go to next stage
			onLED(Normal_Port, Green_Pin);
			setTimer0(5000); //5000ms = 5 seconds
			offLED(Normal_Port, Green_Pin);
			normal_stage = Yellow_Stage;
			break;
		}
	}
	else if(mode == Pedestrian_Mode)
	{
		switch(pedestrian_stage)
		{
			case Red_Stage: //turn on pedestrian red LED and green for 5 seconds then go to next stage
			direction = toGreen;
			onLED(Pedestrian_Port, Red_Pin);
			onLED(Normal_Port, Green_Pin);
			setTimer0(5000); //5000ms = 5 seconds
			offLED(Pedestrian_Port, Red_Pin);
			offLED(Normal_Port, Green_Pin);
			pedestrian_stage = Yellow_Stage;
			if(pedestrian_done)
			{
				mode = Normal_Mode;
			}
			break;
			
			case Yellow_Stage://blink both yellow LEDs for 5 seconds then go to next stage
			blink2LED(Pedestrian_Port, Yellow_Pin, Normal_Port, Yellow_Pin, 1000, 5); 
			if(direction == toGreen)
			{
				pedestrian_stage = Green_Stage; //next stage is green
				direction = toRed; //next time yellow stage is passed, the next stage will be red
			}
			else if(direction == toRed)
			{
				pedestrian_stage = Red_Stage; //next stage is red
				direction = toGreen; //next time yellow stage is passed, the next stage will be green
				offLED(Pedestrian_Port,Green_Pin); //turn off green LED that was on from previous stage
			}
			break;
			
			case Green_Stage: //turn on pedestrian green LED and normal red LED for 5 seconds then go to next stage
			direction = toRed; 
			pedestrian_done = 1; //go to normal mode after returning to red.
			onLED(Pedestrian_Port, Green_Pin);
			onLED(Normal_Port, Red_Pin);
			setTimer0(5000); //5000ms = 5 seconds
			//pedestrian green LED will be turned off AFTER yellow finishes blinking according to required logic
			offLED(Normal_Port, Red_Pin);
			pedestrian_stage = Yellow_Stage;
			break;
		}
	}
}

ISR(Button_1_INT_Vector)
{
	if (mode == Normal_Mode) //only take action if button is pressed in normal mode
	{
		mode = Pedestrian_Mode; //switch to pedestrian mode
		direction = toGreen; //always going towards green in start of pedestrian mode
		pedestrian_done = 0; //will be set to 1 to go back to normal mode when pedestrian mode operations are done
		
		switch (normal_stage)
		{
			//if normal red LED was on then start with green pedestrian LED
			case Red_Stage: 
			pedestrian_stage = Green_Stage;
			break;
			//if normal yellow LED was on then start with yellow pedestrian LED
			case Yellow_Stage:
			pedestrian_stage = Yellow_Stage;
			direction = toRed; //this needs to be set that way so it is changed back to toGreen when the ISR call exits to the yellow stage.
			break;
			//if normal green LED was on then start with red pedestrian LED
			case Green_Stage:
			pedestrian_stage = Red_Stage;
			break;
		}
		offLED(Pedestrian_Port,Red_Pin);
		resetBlinker();
		resetTimer0();
	}
}