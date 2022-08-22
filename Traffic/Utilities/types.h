/*
 * types.h
 *
 * Created: 09-Aug-22 8:51:30 AM
 *  Author: Peter
 */ 


#ifndef TYPES_H_
#define TYPES_H_

//typedefs
typedef unsigned char uint8_t;
typedef unsigned short uint16_t; 
typedef unsigned long uint32_t;

//vectors and ISR
#define ISR(INT_VECT)void INT_VECT(void) __attribute__((signal,used));\
void INT_VECT(void)

#define EXT_INT_0 __vector_1
#define TIMER0_OVF __vector_11

#define sei() __asm__ __volatile__ ("sei" ::: "memory") 




#endif /* TYPES_H_ */