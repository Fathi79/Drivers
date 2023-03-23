/*
 * LM35_test.c
 *
 *  Created on: Sep 5, 2022
 *      Author: loppy
 */
/*
#include "../HAL/LCD_DRIVER/LCD.h"
#include "../HAL/LCD_DRIVER/LCD_CFG.h"
#include "avr/io.h"
#include "avr/delay.h"
#include "avr/interrupt.h"
#include "../MCAL/DIO/DIO_CFG.h"
#include "../MCAL/DIO/DIO.h"
#include "../UTILS/BIT_MATH.h"
#include "../MCAL/INT/INT.h"
#include "../MCAL/ADC/ADC.h"



int main(void)
{
	LCD_vInit();
	ADC_vInit();

	u16 x;
	LCD_DisplayStr_row_col("TEMPERATURE: ", 0, 0);
	while(1)
	{
		x = ADC_u16ReadData(0);
		LCD_DisplayStr_row_col("    ", 0, 12);
		LCD_goto_row_col(0, 12);
		x = (x*150*5)/(1023*1.5);
		//x = x - 55;
		LCD_intToStr(x);
		_delay_ms(1000);
	}

	return 0;
}
*/
