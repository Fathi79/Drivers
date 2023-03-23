/*
 * DC.c
 *
 *  Created on: Sep 12, 2022
 *      Author: loppy
 */

#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/DIO/DIO_CFG.h"
#include "../../MCAL/TIMER/TIMER.h"
#include "../../MCAL/INT/INT.h"
#include "avr/delay.h"
#include "avr/io.h"
#include "../../UTILS/BIT_MATH.h"
#include "DC.h"

extern u8 DC_PWM_PIN, DC_OCR_VALUE;

void DC_INIT()
{
	setPinDir(DC_RIGHT_PIN, OUTPUT);
	setPinDir(DC_LEFT_PIN, OUTPUT);
	setPinValue(DC_LEFT_PIN, LOW);
	setPinValue(DC_RIGHT_PIN, LOW);
}

void DC_clockWise()
{
	setPinValue(DC_RIGHT_PIN, HIGH);
	setPinValue(DC_LEFT_PIN, LOW);
	_delay_ms(50);
}

void DC_antiClockWise()
{
	setPinValue(DC_LEFT_PIN, HIGH);
	setPinValue(DC_RIGHT_PIN, LOW);
	_delay_ms(50);
}

void DC_stop()
{
	setPinValue(DC_LEFT_PIN, LOW);
	setPinValue(DC_RIGHT_PIN, LOW);
}

void DC_PWM_INIT()
{
	setCallBackTimer2(DC_fake_PWM);
	DC_PWM_PIN = DC_PIN0;
	DC_OCR_VALUE = 150;
	setOCR2(DC_OCR_VALUE);
	Timer2_vInit();
}

void DC_fake_PWM()
{
	TOGGLE_BIT(DC_PORT, DC_PWM_PIN);
	DC_OCR_VALUE = 255 - DC_OCR_VALUE;
	setOCR2(DC_OCR_VALUE);
}


