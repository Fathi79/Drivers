/*
 * ICU_test.c
 *
 *  Created on: Sep 8, 2022
 *      Author: loppy
 */

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

u16 flag = 0;
u16 reading [3];

void detectTimeInput(void)
{
	TOGGLE_BIT(TCCR1B, 6);		//Change the edge
	reading[flag] = ICR1;
	flag++;
	if(flag == 3)
		CLEAR_BIT(TIMSK,5);		//Disable PIE of the ICU
}

void ICU_test(void)
{
	SET_BIT(DDRB,3);
	CLEAR_BIT(DDRD, 6);

	setCallBackTimer1(detectTimeInput);

	LCD_vInit();

	Timer0_vInit();
	Timer1_vInit();

	while(flag<3);

	LCD_DisplayStr("TICK TIME: ");
	LCD_intToStr(reading[2]-reading[0]);
	LCD_DisplayStr_row_col("DUTY: ", 2, 0);
	LCD_intToStr(reading[2]-reading[1]);

}
