/*
 * DC_test.c
 *
 *  Created on: Aug 30, 2022
 *      Author: loppy
 */

#include "../UTILS/BIT_MATH.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/DIO/DIO_CFG.h"
#include "../HAL/DC_DRIVER/DC.h"
#include "../MCAL/TIMER/TIMER.h"
#include "../MCAL/TIMER/TIMER_CFG.h"
#include "../MCAL/INT/INT.h"
#include "avr/delay.h"
#include "avr/io.h"

u8 DC_PWM_PIN, DC_OCR_VALUE;


void DC_test(void)
{
	u8 i;
	DC_INIT();

	while(1)
	{
		Timer0_vOpenPIE();
		for(i = 255; i > 0; i--)
		{
			DC_OCR_VALUE = i;
			setOCR0(DC_OCR_VALUE);
			_delay_ms(20);
		}

		Timer0_vClosePIE();
		DC_stop();
		_delay_ms(3000);

		if(DC_PWM_PIN == DC_PIN0)
			DC_PWM_PIN = DC_PIN1;
		else
			DC_PWM_PIN = DC_PIN0;
	}

	while(1)
	{
		DC_clockWise();
		_delay_ms(2000);
		DC_stop();
		_delay_ms(1000);
		DC_antiClockWise();
		_delay_ms(2000);
		DC_stop();
		_delay_ms(1000);
	}

}

