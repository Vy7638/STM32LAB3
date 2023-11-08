/*
 * input_processing.c
 *
 *  Created on: Nov 3, 2023
 *      Author: ADMIN
 */

#include "main.h"
#include "input_reading.h"
#include "global.h"
#include "fsm_auto.h"

enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND};
enum ButtonState buttonState0 = BUTTON_RELEASED;
enum ButtonState buttonState1 = BUTTON_RELEASED;
enum ButtonState buttonState2 = BUTTON_RELEASED;

void fsm_for_input_processing(void){
	//button 1
	switch(buttonState0){
		case BUTTON_RELEASED:
			if(is_button_pressed(0)){
				buttonState0 = BUTTON_PRESSED;
				//INCREASE VALUE OF PORT A BY ONE UNIT
				switch (status) {
					case MANUAL_RED:
						status = MANUAL_AMBER;
						clear_led();
						timerTempAmber = timerAmber;
						break;
					case MANUAL_AMBER:
						status = MANUAL_GREEN;
						clear_led();
						timerTempGreen = timerGreen;
						break;
					case MANUAL_GREEN:
						status = RED_GREEN;
						if (timerRed != timerAmber + timerGreen){
							timerAmber = timerRed - timerGreen;
						}
						fsm_init_timer();
						break;
					case RED_GREEN:
						status = MANUAL_RED;
						clear_led();
						timerTempRed = timerRed;
					case RED_AMBER:
						status = MANUAL_RED;
						clear_led();
						timerTempRed = timerRed;
					case GREEN_RED:
						status = MANUAL_RED;
						clear_led();
						timerTempRed = timerRed;
						break;
					case AMBER_RED:
						status = MANUAL_RED;
						clear_led();
						timerTempRed = timerRed;
					default:

						break;
				}
			}
			break;
		case BUTTON_PRESSED:
			if(!is_button_pressed(0)){
				buttonState0 = BUTTON_RELEASED;
			}
			else{
				if(is_button_pressed_1s(0)){
					buttonState0 = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				}
			}
			break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if(!is_button_pressed(0)){
				buttonState0 = BUTTON_RELEASED;
			}
			//todo
			break;
	}
	//button 2
	switch(buttonState1){
		case BUTTON_RELEASED:
			if(is_button_pressed(1)){
				buttonState1 = BUTTON_PRESSED;
				//INCREASE VALUE OF PORT A BY ONE UNIT
				switch (status) {
					case MANUAL_RED:
						++timerTempRed;
						if (timerTempRed >= 100){
							timerTempRed = 0;
						}
						break;
					case MANUAL_AMBER:
						++timerTempAmber;
						if (timerTempAmber >= 100){
							timerTempAmber = 0;
						}
						break;
					case MANUAL_GREEN:
						++timerTempGreen;
						if (timerTempGreen >= 100){
							timerTempGreen = 0;
						}
						break;
					default:

						break;
				}
			}
			break;
		case BUTTON_PRESSED:
			if(!is_button_pressed(1)){
				buttonState1 = BUTTON_RELEASED;
			}
			else{
				if(is_button_pressed_1s(1)){
					buttonState1 = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				}
			}
			break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if(!is_button_pressed(1)){
				buttonState1 = BUTTON_RELEASED;
			}
			//todo
			break;
	}
	//button 3
	switch(buttonState2){
		case BUTTON_RELEASED:
			if(is_button_pressed(2)){
				buttonState2 = BUTTON_PRESSED;
				//INCREASE VALUE OF PORT A BY ONE UNIT
				switch (status) {
					case MANUAL_RED:
						timerRed = timerTempRed;
						break;
					case MANUAL_AMBER:
						timerAmber = timerTempAmber;
						break;
					case MANUAL_GREEN:
						timerGreen = timerTempGreen;
						break;
					default:

						break;
				}
			}
			break;
		case BUTTON_PRESSED:
			if(!is_button_pressed(2)){
				buttonState2 = BUTTON_RELEASED;
			}
			else{
				if(is_button_pressed_1s(2)){
					buttonState2 = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				}
			}
			break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if(!is_button_pressed(2)){
				buttonState2 = BUTTON_RELEASED;
			}

			break;
	}
}
