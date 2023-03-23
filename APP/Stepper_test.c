/*
 * Stepper_test.c
 *
 *  Created on: Sep 13, 2022
 *      Author: loppy
 */

#include "../UTILS/BIT_MATH.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/DIO/DIO_CFG.h"
#include "../HAL/LCD_DRIVER/LCD_CFG.h"
#include "../HAL/LCD_DRIVER/LCD.h"
#include "../HAL/STEPPER/STEPPER.h"
#include "../MCAL/TIMER/TIMER.h"
#include "../MCAL/TIMER/TIMER_CFG.h"
#include "../MCAL/INT/INT.h"
#include "../MCAL/UART/UART.h"
#include "avr/delay.h"
#include "avr/io.h"


void Stepper_test(void)
{
	DDRB = 0xFF;
	PORTB = 1;

	while(1)
	{
		Stepper_vRotateCW(90);

		_delay_ms(1000);

		Stepper_vRotateACW(90);

		_delay_ms(1000);
	}

}
