/*
 * DIO.h
 *
 * Created: 09-Aug-22 8:58:52 AM
 *  Author: Peter
 */ 


#ifndef DIO_H_
#define DIO_H_

//Includes
#include "../registers.h"

//Macros

//Ports
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_D 'D'

//States
#define INPUT 0
#define OUTPUT 1

//Values
#define LOW 0
#define HIGH 1

//Interrupts
#define INT_0 0

//Function prototypes
int initDIO(uint8_t portNumber, uint8_t pinNumber,uint8_t state); //initialize DIO to input or output according to 'state'

int enInterrupt(uint8_t INTx); //Enable external interrupt on rising edge.

int writeDIO(uint8_t portNumber, uint8_t pinNumber,uint8_t value); //Write output to DIO according to 'value'



#endif /* DIO_H_ */