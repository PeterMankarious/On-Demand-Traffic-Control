/*
 * registers.h
 *
 * Created: 09-Aug-22 8:45:19 AM
 *  Author: Peter
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "../Utilities/types.h"

//DIO
#define PORTA *((volatile uint8_t*)0x3B)
#define DDRA *((volatile uint8_t*)0x3A)

#define PORTB *((volatile uint8_t*)0x38)
#define DDRB *((volatile uint8_t*)0x37)

#define PORTD *((volatile uint8_t*)0x32)
#define DDRD *((volatile uint8_t*)0x31)

//External Interrupts
#define SREG *((volatile uint8_t*)0x5F)

#define MCUCR *((volatile uint8_t*)0x55)
#define ISC00 0
#define ISC01 1

#define GICR *((volatile uint8_t*)0x5B)
#define INT0 6

//Timers
#define TIMSK *((volatile uint8_t*)0x59)
#define TOIE0 0

#define TCCR0 *((volatile uint8_t*)0x53)
#define CS00 0
#define CS01 1
#define CS02 2
#define WGM01 3
#define WGM00 6

#define TCNT0 *((volatile uint8_t*)0x52)

#endif /* REGISTERS_H_ */