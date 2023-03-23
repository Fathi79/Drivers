/*
 * SPI.h
 *
 *  Created on: Sep 14, 2022
 *      Author: loppy
 */

#ifndef MCAL_SPI_SPI_H_
#define MCAL_SPI_SPI_H_

#include "../../UTILS/STD_TYPES.h"

void SPI_masterInit(void);

void SPI_slaveInit(void);

void SPI_send(u8 data);

u8 SPI_receive(void);

#endif /* MCAL_SPI_SPI_H_ */
