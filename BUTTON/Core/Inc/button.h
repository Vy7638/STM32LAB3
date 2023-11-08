/*
 * button.h
 *
 *  Created on: Nov 1, 2023
 *      Author: ADMIN
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESS_STATE GPIO_PIN_RESET

void getKeyInput();

#endif /* INC_BUTTON_H_ */
