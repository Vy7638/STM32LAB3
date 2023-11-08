/*
 * global.h
 *
 *  Created on: Nov 5, 2023
 *      Author: ADMIN
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define INIT 		0
#define RED_GREEN 	1
#define RED_AMBER 	2
#define GREEN_RED 	3
#define AMBER_RED 	4


#define MANUAL_RED 		11
#define MANUAL_AMBER	12
#define MANUAL_GREEN	13

#define TIMER_RED 	5
#define TIMER_AMBER 2
#define TIMER_GREEN 3

extern int status;

int timerRed;
int timerAmber;
int timerGreen;

int timerTempRed;
int timerTempAmber;
int timerTempGreen;

int num1Seg;
int num2Seg;


#endif /* INC_GLOBAL_H_ */
