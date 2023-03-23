/*
 * timer_test.c
 *
 *  Created on: Sep 6, 2022
 *      Author: loppy
 */
/*
#include "avr/io.h"
#include "avr/interrupt.h"
#include "../MCAL/DIO/DIO_CFG.h"
#include "../MCAL/DIO/DIO.h"
#include "../UTILS/BIT_MATH.h"
#include "../MCAL/INT/INT.h"
#include "../MCAL/TIMER/TIMER.h"

void LED_Toggle_Timer(void)
{
	static volatile u16 count = 0;
	count++;
	if(count == 1000)
	{
		TOGGLE_BIT(PORTA, 0);
		count = 0;
		setTCNT0(189);
	}
}

int main(void)
{
	SET_BIT(DDRA, 0);
	setCallBackTimer(LED_Toggle_Timer);
	Timer0_Init();
	setTCNT0(189);
	while(1);

	return 0;
}
*/
