/*
 * Button.c
 *
 * Created: 09-Aug-22 11:22:29 AM
 *  Author: Peter
 */ 

#include "Button.h"

int initButton(uint8_t INTx)
{
	//initialize button by enabling the external interrupt it is connected to.
	enInterrupt(INTx);
	return 0; //successful operation
}