/*
 * SPI.c
 *
 *  Created on: Sep 14, 2022
 *      Author: loppy
 */

#include "SPI.h"
#include "avr/io.h"
#include "../../UTILS/BIT_MATH.h"
#include "../../UTILS/STD_TYPES.h"

void SPI_masterInit(void)
{
	SPCR = 0x50;
	DDRB = 0xB0;
}

void SPI_slaveInit(void)
{
	SPCR = 0x40;
	DDRB = 0x40;
}

void SPI_send(u8 data)
{
	SPDR = data;
	while(!READ_BIT(SPSR,7));
}

u8 SPI_receive(void)
{
	while(!READ_BIT(SPSR,7));
	return SPDR;
}
