/*
 * led.h
 *
 *  Created on: Nov 5, 2023
 *      Author: ADMIN
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include "main.h"
#include "software_timer.h"

void clear_led();
void green_red();
void amber_red();
void red_green();
void red_amber();

void red_blinky();
void green_blinky();
void amber_blinky();

void display_7seg(int num);
void state_7seg(int index, int num1, int num2);

#endif /* INC_LED_H_ */
