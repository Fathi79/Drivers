/*
 * STOPWATCH.c
 *
 *  Created on: Sep 11, 2022
 *      Author: loppy
 */
/*
#include "avr/io.h"
#include "avr/delay.h"
#include "avr/interrupt.h"
#include "../MCAL/DIO/DIO_CFG.h"
#include "../MCAL/DIO/DIO.h"
#include "../UTILS/BIT_MATH.h"
#include "../MCAL/INT/INT.h"
#include "../MCAL/TIMER/TIMER.h"
#include "../HAL/LCD_DRIVER/LCD_CFG.h"
#include "../HAL/LCD_DRIVER/LCD.h"

//u8 minutes, hours, seconds;
u16 time;
u8 ticks = 0;

void startTimer()
{
	Timer0_vOpenPIE();
}

void pauseTimer()
{
	Timer0_vClosePIE();
}

void resetTimer()
{
	//hours = 0;		minutes = 0;	seconds = 0;
	time = 0;
	ticks = 0;
	setTCNT0(238);
	Timer0_vOpenPIE();
}

void CounterHandler()
{
	if (ticks == 122)
	{
		setTCNT0(238);
		ticks = 0;

		time++;
	}
	else
		ticks++;
}

void stopWatch_Init(void)
{
	setCallBack(startTimer, 1);
	setCallBack(pauseTimer, 2);
	setCallBack(resetTimer, 3);

	LCD_vInit();
	INT0_Enable();
	INT1_Enable();
	INT2_Enable();

	//hours = 0;		minutes = 0;	seconds = 0;
	time = 0;

	setCallBackTimer0(CounterHandler);

	setTCNT0(238);
	Timer0_vInit();
	Timer0_vClosePIE();
}

void stopWatchUpdateTime()
{
		LCD_goto_row_col(1, 4);

		if(time / 3600 < 10)
			LCD_vSendData('0');
		LCD_intToStr(time / 3600);
		LCD_vSendData(':');

		if((time / 60)%60 < 10)
			LCD_vSendData('0');
		LCD_intToStr((time / 60)%60);
		LCD_vSendData(':');

		if(time % 60 < 10)
			LCD_vSendData('0');
		LCD_intToStr(time % 60);
		LCD_vSendData(' ');
}
*/
