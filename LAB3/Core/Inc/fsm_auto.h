/*
 * fsm_auto.h
 *
 *  Created on: Nov 5, 2023
 *      Author: ADMIN
 */

#ifndef INC_FSM_AUTO_H_
#define INC_FSM_AUTO_H_

#include "main.h"
#include "global.h"
#include "software_timer.h"
#include "led.h"

int counterRedGreen;
int counterRedAmber;
int counterGreenRed;
int counterAmberRed;

void fsm_init_timer();
void fsm_auto_run();

#endif /* INC_FSM_AUTO_H_ */
