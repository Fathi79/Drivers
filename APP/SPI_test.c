/*
 * SPI_test.c
 *
 *  Created on: Sep 14, 2022
 *      Author: loppy
 */

#include "avr/io.h"
#include "avr/delay.h"
#include "../UTILS/STD_TYPES.h"
#include "../UTILS/BIT_MATH.h"
#include "../MCAL/SPI/SPI.h"
#include "../MCAL/UART/UART.h"
#include "../HAL/LCD_DRIVER/LCD_CFG.h"
#include "../HAL/LCD_DRIVER/LCD.h"


void spi_slave_test(void)
{
	u8 data;
	SPI_slaveInit();
	DDRD = 0xff;

	while(1)
	{
		data = SPI_receive();
		if (data == 'x')
			PORTD = 0xff;
		SPI_send(data);
	}

}

void spi_master_test(void)
{
	u8 data;
	LCD_vInit();
	SPI_masterInit();
	UART_vInit();
	while(1)
	{
		data = UART_vReceive();
		SPI_send(data);
		data = SPI_receive();
		LCD_vSendData(data);
	}
}
