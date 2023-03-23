/*
 * UART.h
 *
 *  Created on: Sep 12, 2022
 *      Author: loppy
 */

#ifndef MCAL_UART_UART_H_
#define MCAL_UART_UART_H_

void UART_vInit(void);

void UART_vTransmit(u8 data);

u8 UART_vReceive();

void UART_vGetStr(u8 * str, u8 size);

void UART_vSendStr(u8 * str);

#endif /* MCAL_UART_UART_H_ */
