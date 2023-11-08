/*
 * fsm_manual.c
 *
 *  Created on: Nov 7, 2023
 *      Author: ADMIN
 */

#include "fsm_manual.h"

void fsm_manual_run(){
	switch (status) {
		case MANUAL_RED:
			red_blinky();
			num1Seg = 2;
			num2Seg = timerTempRed;
			break;
		case MANUAL_AMBER:
			amber_blinky();
			num1Seg = 3;
			num2Seg = timerTempAmber;
			break;
		case MANUAL_GREEN:
			green_blinky();
			num1Seg = 4;
			num2Seg = timerTempGreen;
			break;
		default:
			break;
	}
}
