/*
 * UART_test.c
 *
 *  Created on: Sep 13, 2022
 *      Author: loppy
 */

#include "../UTILS/BIT_MATH.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/DIO/DIO_CFG.h"
#include "../HAL/LCD_DRIVER/LCD_CFG.h"
#include "../HAL/LCD_DRIVER/LCD.h"
#include "../MCAL/TIMER/TIMER.h"
#include "../MCAL/TIMER/TIMER_CFG.h"
#include "../MCAL/INT/INT.h"
#include "../MCAL/UART/UART.h"
#include "avr/delay.h"
#include "avr/io.h"


void UART_test(void)
{
	u8 data;

	SET_BIT(DDRA, 0);

	UART_vInit();
	LCD_vInit();

	while(1)
	{
		UART_vTransmit(data);

		//_delay_ms(5000);
		data = UART_vReceive();
		if (data)
		{
			TOGGLE_BIT(PORTA, 0);
		}
		LCD_vSendData(data);
	}

}
