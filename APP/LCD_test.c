/*
 * LCD_test.c
 *
 *  Created on: Aug 30, 2022
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

void main(void)
{
	LCD_vInit();


	u8 arr[8] = {
			0x1B,
			0x1F,
			0x1F,
			0x0E,
			0x04,
			0,
			0,
			'\0'
	};

	00011011,
	00011111,
	00011111,
	00001110,
	00000100,
	00000000

		//LCD_DisplayCustomChar(arr, 0x40);

		u8 arr[5] = "LUCA\0";
		u8 arr2[6] = "MOTAZ\0";

		LCD_DisplayStr(arr);
		LCD_goto_row_col(2, 6);

		LCD_DisplayStr_row_col(arr, 1, 6);
		LCD_intToStr(57638);
		LCD_DisplayStr_row_col(arr2, 2, 6);

}



    setPinDir(GROUP_A, PIN_0, OUTPUT);
	while(1)
	{
	setPinValue(GROUP_A, PIN_0, HIGH);
	_delay_ms(1000);
	setPinValue(GROUP_A, PIN_0, LOW);
	_delay_ms(1000);
	}
*/
