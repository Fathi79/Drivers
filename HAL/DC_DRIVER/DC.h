/*
 * DC.h
 *
 *  Created on: Sep 12, 2022
 *      Author: loppy
 */

#ifndef HAL_DC_DRIVER_DC_H_
#define HAL_DC_DRIVER_DC_H_

/********************** Pins Configuration **********************/
#define DC_LEFT_PIN 		GROUP_A,PIN_0
#define DC_RIGHT_PIN		GROUP_A,PIN_1
#define DC_PORT				PORTA
#define DC_PIN0				PIN_0
#define DC_PIN1				PIN_1

/********************** Digital Control *********************/

void DC_INIT();

void DC_clockWise();

void DC_antiClockWise();

void DC_stop();

//Set DC_PWM_PIN and DC_OCR_VALUE first
//Set DC_PORT,	DC_PIN0,	DC_PIN1
//Call the initializer
void DC_PWM_INIT();

//Call Timer0_vOpenPIE(); before this function
void DC_fake_PWM();


#endif /* HAL_DC_DRIVER_DC_H_ */
