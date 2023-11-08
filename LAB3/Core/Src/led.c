/*
 * led.c
 *
 *  Created on: Nov 5, 2023
 *      Author: ADMIN
 */

#include "led.h"

void clear_led(){
	HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin|LED_AMBER_1_Pin|LED_GREEN_1_Pin|
			LED_RED_2_Pin|LED_AMBER_2_Pin|LED_GREEN_2_Pin, GPIO_PIN_SET);
}

void red_green(){
	HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin|LED_GREEN_2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, LED_AMBER_1_Pin|LED_GREEN_1_Pin|LED_RED_2_Pin|LED_AMBER_2_Pin, GPIO_PIN_SET);
}

void red_amber(){
	HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin|LED_AMBER_2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, LED_AMBER_1_Pin|LED_GREEN_1_Pin|LED_RED_2_Pin|LED_GREEN_2_Pin, GPIO_PIN_SET);
}

void green_red(){
	HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin|LED_RED_2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin|LED_AMBER_1_Pin|LED_AMBER_2_Pin|LED_GREEN_2_Pin, GPIO_PIN_SET);
}

void amber_red(){
	HAL_GPIO_WritePin(GPIOA, LED_AMBER_1_Pin|LED_RED_2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin|LED_GREEN_1_Pin|LED_AMBER_2_Pin|LED_GREEN_2_Pin, GPIO_PIN_SET);
}

void red_blinky(){
	HAL_GPIO_TogglePin(GPIOA, LED_RED_1_Pin|LED_RED_2_Pin);
}

void green_blinky(){
	HAL_GPIO_TogglePin(GPIOA, LED_GREEN_1_Pin|LED_GREEN_2_Pin);
}

void amber_blinky(){
	HAL_GPIO_TogglePin(GPIOA, LED_AMBER_1_Pin|LED_AMBER_2_Pin);
}

void display_7seg(int num){
	switch (num) {
		case 0:
			HAL_GPIO_WritePin(GPIOB, SEG_0_Pin|SEG_1_Pin|SEG_2_Pin|SEG_3_Pin|SEG_4_Pin|SEG_5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG_6_Pin, GPIO_PIN_SET);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOB, SEG_1_Pin|SEG_2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG_0_Pin|SEG_3_Pin|SEG_4_Pin|SEG_5_Pin|SEG_6_Pin, GPIO_PIN_SET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOB, SEG_0_Pin|SEG_1_Pin|SEG_3_Pin|SEG_4_Pin|SEG_6_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG_2_Pin|SEG_5_Pin, GPIO_PIN_SET);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOB, SEG_0_Pin|SEG_1_Pin|SEG_2_Pin|SEG_3_Pin|SEG_6_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG_4_Pin|SEG_5_Pin, GPIO_PIN_SET);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOB, SEG_1_Pin|SEG_2_Pin|SEG_5_Pin|SEG_6_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG_0_Pin|SEG_3_Pin|SEG_4_Pin, GPIO_PIN_SET);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOB, SEG_0_Pin|SEG_2_Pin|SEG_3_Pin|SEG_5_Pin|SEG_6_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG_1_Pin|SEG_4_Pin, GPIO_PIN_SET);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOB, SEG_0_Pin|SEG_2_Pin|SEG_3_Pin|SEG_4_Pin|SEG_5_Pin|SEG_6_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG_1_Pin, GPIO_PIN_SET);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOB, SEG_0_Pin|SEG_1_Pin|SEG_2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG_3_Pin|SEG_4_Pin|SEG_5_Pin|SEG_6_Pin, GPIO_PIN_SET);
			break;
		case 8:
			HAL_GPIO_WritePin(GPIOB, SEG_0_Pin|SEG_1_Pin|SEG_2_Pin|SEG_3_Pin|SEG_4_Pin|SEG_5_Pin|SEG_6_Pin, GPIO_PIN_RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(GPIOB, SEG_0_Pin|SEG_1_Pin|SEG_2_Pin|SEG_3_Pin|SEG_5_Pin|SEG_6_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG_4_Pin, GPIO_PIN_SET);
			break;
		default:
			break;
	}
}

void state_7seg(int index, int num1, int num2){
	switch (index) {
		case 0:
			HAL_GPIO_WritePin(GPIOA, LED_MODE_2_Pin|LED_TIMER_1_Pin|LED_TIMER_2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LED_MODE_1_Pin, GPIO_PIN_RESET);
			display_7seg(num1 / 10);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOA, LED_MODE_1_Pin|LED_TIMER_1_Pin|LED_TIMER_2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LED_MODE_2_Pin, GPIO_PIN_RESET);
			display_7seg(num1 % 10);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOA, LED_MODE_1_Pin|LED_MODE_2_Pin|LED_TIMER_2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LED_TIMER_1_Pin, GPIO_PIN_RESET);
			display_7seg(num2 / 10);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOA, LED_MODE_1_Pin|LED_MODE_2_Pin|LED_TIMER_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LED_TIMER_2_Pin, GPIO_PIN_RESET);
			display_7seg(num2 % 10);
			break;
		default:
			break;
	}
}







