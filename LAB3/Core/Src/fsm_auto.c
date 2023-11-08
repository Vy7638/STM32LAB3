/*
 * fsm_auto.c
 *
 *  Created on: Nov 5, 2023
 *      Author: ADMIN
 */

#include "fsm_auto.h"

void fsm_init_timer(){
	counterRedGreen = timerGreen;
	counterGreenRed = timerGreen;
	counterAmberRed = timerAmber;
	counterRedAmber = timerAmber;
}

void fsm_auto_run(){
	switch (status) {
		case INIT:
			status = RED_GREEN;
			fsm_init_timer();
			break;
		case RED_GREEN:
			red_green();
			counterRedGreen--;

			num1Seg = counterRedGreen + timerAmber;
			num2Seg = counterRedGreen;

			if (counterRedGreen <= 0){
				status = RED_AMBER;
				counterRedAmber = timerAmber;
			}

			break;
		case RED_AMBER:
			red_amber();
			counterRedAmber--;

			num1Seg = num2Seg = counterRedAmber;

			if (counterRedAmber <= 0){
				status = GREEN_RED;
				counterGreenRed = timerGreen;
			}
			break;
		case GREEN_RED:
			green_red();
			counterGreenRed--;

			num1Seg = counterGreenRed;
			num2Seg = counterGreenRed + timerAmber;

			if (counterGreenRed <= 0){
				status = AMBER_RED;
				counterAmberRed = timerAmber;
			}
			break;
		case AMBER_RED:
			amber_red();
			counterAmberRed--;

			num1Seg = num2Seg = counterAmberRed;

			if (counterAmberRed <= 0){
				status = RED_GREEN;
				counterRedGreen = timerGreen;
			}
			break;
		default:
			break;
	}
}
