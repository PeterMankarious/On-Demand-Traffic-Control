/*
 * app.h
 *
 * Created: 09-Aug-22 10:01:38 AM
 *  Author: Peter
 */ 


#ifndef APP_H_
#define APP_H_

#include "../ECUAl/Button Driver/Button.h"
#include "../ECUAL/LED Driver/LED.h"
#include "../MCAL/Timers Driver/Timers.h"

#define Button_1_INT INT_0
#define Button_1_INT_Vector EXT_INT_0

#define Normal_Port PORT_A
#define Pedestrian_Port PORT_B

#define Green_Pin 0
#define Yellow_Pin 1
#define Red_Pin 2

#define Normal_Mode 0
#define Pedestrian_Mode 1

#define Red_Stage 0
#define Yellow_Stage 1
#define Green_Stage 2

#define toRed 0
#define toGreen 1

void initApp();
void runApp();



#endif /* APP_H_ */