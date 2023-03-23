/*
 * STEPPER.h
 *
 *  Created on: Sep 13, 2022
 *      Author: loppy
 */

#ifndef HAL_STEPPER_STEPPER_H_
#define HAL_STEPPER_STEPPER_H_

#define STEPPER_PORT	PORTB
#define LSB				0

void Stepper_vInit(void);

void Stepper_vRotateCW(u8 degree);

void Stepper_vRotateACW(u8 degree);

#endif /* HAL_STEPPER_STEPPER_H_ */
