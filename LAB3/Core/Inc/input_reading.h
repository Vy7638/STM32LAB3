/*
 * input_reading.h
 *
 *  Created on: Nov 3, 2023
 *      Author: ADMIN
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#include "main.h"

void button_reading ( void );
void clear_button();
unsigned char is_button_pressed ( unsigned char index );
unsigned char is_button_pressed_1s ( unsigned char index );

#endif /* INC_INPUT_READING_H_ */
