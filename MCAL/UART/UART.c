/*
 * UART.c
 *
 *  Created on: Sep 12, 2022
 *      Author: loppy
 */

#include "avr/io.h"
#include "../../UTILS/STD_TYPES.h"
#include "../../UTILS/BIT_MATH.h"
#include "UART.h"

void UART_vInit()
{
	// Set BaudRate -> 9600/8MhZ
	UBRRL = 51;
	UBRRH = 0;
	// Set Frame Format -> 8 data, 1 stop, No Parity
	UCSRC = 0x86;
	// Enable RX and TX
	UCSRB = 0x18;
}


void UART_vTransmit(u8 data)
{
	// Wait until transmission Register Empty
	while((UCSRA&0x20) == 0x00);
	UDR = data;
}

u8 UART_vReceive()
{
	u8 Result;
	// Wait until Reception Complete
	while((UCSRA&0x80) == 0x00);
	Result = UDR;

	/* Clear Flag */
	SET_BIT(UCSRA,7);
	return Result;
}

void UART_vGetStr(u8 * str, u8 size)
{
	u8 i;
	for (i = 0; i < size; i++)
		str[i] = UART_vReceive();
	str[i] = '\0';
}

void UART_vSendStr(u8 * str)
{
	u8 i = 0;
	while(str[i] != '\0')
	{
		UART_vTransmit(str[i]);
		i++;
	}
}
