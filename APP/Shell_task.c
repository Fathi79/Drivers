/*
 * Shell_task.c
 *
 *  Created on: Sep 13, 2022
 *      Author: loppy
 */

#include "../UTILS/BIT_MATH.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/DIO/DIO_CFG.h"
#include "../MCAL/TIMER/TIMER.h"
#include "../MCAL/TIMER/TIMER_CFG.h"
#include "../MCAL/INT/INT.h"
#include "../MCAL/UART/UART.h"
#include "../HAL/LCD_DRIVER/LCD_CFG.h"
#include "../HAL/LCD_DRIVER/LCD.h"
#include "../HAL/STEPPER/STEPPER.h"
#include "../HAL/DC_DRIVER/DC.h"
#include "avr/delay.h"
#include "avr/io.h"

u8 DC_PWM_PIN, DC_OCR_VALUE;

u16 time;
u8 ticks = 0;


//u8 frameIndex = 0;
//u8 frameError = 0;

void stopWatch_Init(void);
void stopWatchUpdateTime();
void CounterHandler(void);

u8 checkFrame(u8 * arr);
u8 isNum(u8 c);
u8 strToInt(u8 * str, u8 size);

void updateLCDStatus(u8 * arr, u8 speed, u8 dir);

int Shell(void)
{
	u8 frame[9] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0'};
	u8 speedPercent = 0, angle = 0;

	LCD_vInit();

	LCD_DisplayStr_row_col("Time:", 2, 0);
	LCD_DisplayStr_row_col("AM", 2, 14);
	LCD_DisplayStr_row_col("Speed:", 1, 0);
	LCD_DisplayStr_row_col("D:", 1, 10);


	DC_INIT();
	DC_PWM_INIT();
	Timer2_vClosePIE();
	DC_stop();
	Stepper_vInit();
	UART_vInit();

	stopWatch_Init();

	while(1)
	{
		//Receive control frame
		UART_vGetStr(frame, 8);

		//Check the frame validity
		if (checkFrame(frame))
		{
			//Set the desired value
			speedPercent = strToInt(frame, 3);
			if (speedPercent == 0)
			{
				Timer2_vClosePIE();
				DC_stop();
			}
			else
			{
				DC_OCR_VALUE = (speedPercent/100.0)*255;

				//Set the DC direction
				if(frame[3] == 'F')
				{
					DC_PWM_PIN = DC_PIN0;
					setPinValue(DC_PORT, DC_PIN1, LOW);
				}
				else
				{
					DC_PWM_PIN = DC_PIN1;
					setPinValue(DC_PORT, DC_PIN0, LOW);
				}

				//Start moving the DC
				Timer2_vOpenPIE();
			}
			//Get the stepper angle
			angle = strToInt(&frame[4], 2);

			//Get the direction
			if (frame[6] == 'R')
				Stepper_vRotateCW(angle);
			else
				Stepper_vRotateACW(angle);

			updateLCDStatus(frame, speedPercent, angle);
		}
		else
			UART_vSendStr("Frame error");
	}

	return 0;
}

void stopWatch_Init(void)
{
	//LCD_vInit();

	time = 0;

	setCallBackTimer0(CounterHandler);

	setTCNT0(238);
	Timer0_vInit();
}

void CounterHandler()
{
	if (ticks == 122)
	{
		setTCNT0(238);
		ticks = 0;
		time++;
		stopWatchUpdateTime();
	}
	else
		ticks++;
}

void stopWatchUpdateTime()
{
		LCD_goto_row_col(2, 5);

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
}

u8 checkFrame(u8 * arr)
{
	if (arr[7] == 'E'
			&& (arr[0] == '1' || arr[0] == '0')
			&& isNum(arr[1])
			&& isNum(arr[2])
			&& (arr[3] == 'F' || arr[3] == 'B')
			&& isNum(arr[4])
			&& isNum(arr[5])
			&& (arr[6] == 'L' || arr[6] == 'R'))
		return 1;

	return 0;
}

u8 isNum(u8 c)
{
	if (c >= '0' && c <= '9')
		return 1;
	return 0;
}

u8 strToInt(u8 * str, u8 size)
{
	u8 i = 0;
	u8 result = 0;
	while(i < size)
	{
		result *= 10;
		result += (*str) - '0';
		i++;
		str++;
	}

	return result;
}

void updateLCDStatus(u8 * arr, u8 speed, u8 dir)
{
	LCD_goto_row_col(1, 6);
	LCD_intToStr(speed);
	if (speed != 100)
		LCD_vSendData(' ');

	LCD_goto_row_col(1, 12);
	if (arr[6] == 'L' && dir != 0)
		LCD_vSendData('-');
	LCD_intToStr(dir);
	LCD_vSendData(' ');
}

