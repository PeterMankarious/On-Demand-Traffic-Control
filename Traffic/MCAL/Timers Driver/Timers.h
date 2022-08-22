/*
 * Timers.h
 *
 * Created: 09-Aug-22 10:45:26 AM
 *  Author: Peter
 */ 


#ifndef TIMERS_H_
#define TIMERS_H_

//Includes
#include "../registers.h"

//Function prototypes
int setTimer0(float ms); //timer starts counting an amount of milliseconds

int resetTimer0(); //makes timer force finish its time.

#endif /* TIMERS_H_ */