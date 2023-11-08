/*
 * button.c
 *
 *  Created on: Nov 1, 2023
 *      Author: ADMIN
 */

#include "button.h"

int keyReg0 = NORMAL_STATE;
int keyReg1 = NORMAL_STATE;
int keyReg2 = NORMAL_STATE;

int keyReg3 = NORMAL_STATE;
int counterPress = 200;

void subKeyProcess(){
	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
}

void getKeyInput(){
	keyReg0 = keyReg1;
	keyReg1 = keyReg2;
	keyReg2 = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
	if ((keyReg0 == keyReg1) && (keyReg1 == keyReg2)){
		if (keyReg3 != keyReg2 || counterPress <= 0){
			keyReg3 = keyReg2;
			if (keyReg2 == PRESS_STATE){
				//
				subKeyProcess();
				counterPress = 200;
			}
		}
		else {
			counterPress--;
		}
	}
}
