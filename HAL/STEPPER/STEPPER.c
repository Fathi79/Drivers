/*
 * STEPPER.c
 *
 *  Created on: Sep 13, 2022
 *      Author: loppy
 */

#include "../../UTILS/STD_TYPES.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/DIO/DIO_CFG.h"
#include "STEPPER.h"
#include "avr/delay.h"
#include "avr/io.h"

void Stepper_vInit()
{
	setPortDir(GROUP_B, 0xFF);
	setPortValue(GROUP_B, 1 << LSB);
}

void Stepper_vRotateCW(u8 degree)
{
	u8 i;
	PORTB = 1 << LSB;
	for(i = 0; i < degree; i++)
	{
		if (PORTB == (0x01 << (4+LSB)))
			PORTB = (1 << LSB);
		_delay_ms(10);
		PORTB = PORTB << 1;
	}
}

void Stepper_vRotateACW(u8 degree)
{
	u8 i;
	PORTB = 1 << LSB+3;
	for(i = 0; i < degree; i++)
	{
		if ((PORTB & (0x0f << LSB)) == 0)
			PORTB = (1 << LSB+3);
		_delay_ms(10);
		PORTB = PORTB >> 1;
	}
}
