/*
 * main.c
 *
 *  Created on: Aug 24, 2022
 *      Author: Ds
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


void LED_ON()
{
	CLEAR_PORT(PORTA);
}

int main(void)
{
	SET_PORT(DDRA);
	setCallBack(LED_ON, 2);
	INT1_Enable();
	SET_PORT(PORTA);
	while(1);

	return 0;
}
*/
/*
ISR(INT1_vect)
{
	flag = 1;
}


int main()
{
	INT1_Enable();		//init for INT1
	SET_PORT(DDRA);
	CLEAR_PORT(PORTA);

	flag = 0;
	PORTA = 1;
	u8 ledArr = 1;
	while (1)
	{
		u8 i;
		if(flag)
		{
			CLEAR_BIT(GICR, 7);
			CLEAR_BIT(SREG, 7);
			for(i = 0; i < 5; i++)
			{
				SET_PORT(PORTA);
				_delay_ms(1000);
				CLEAR_PORT(PORTA);
				_delay_ms(1000);
			}
			flag = 0;
			SET_PORT(GIFR);
			SET_BIT(SREG, 7);
			SET_BIT(GICR, 7);
		}
		ledArr = ledArr << 1;
		if(ledArr == 0)
			ledArr = 1;
		PORTA = ledArr;
		_delay_ms(300);
	}

}

void INT1_Enable()
{
	CLEAR_BIT(DDRD, 3);	//set PD2 as input
	SET_BIT(PORTD, 3);	//Activate pull-up for PD2

	SET_BIT(MCUCR, 3);	//sense falling edge for INT1
	CLEAR_BIT(MCUCR, 2);

	SET_BIT(SREG, 7);	//enable GIE
	SET_BIT(GICR, 7);	//Enable PIE for INT1
}
*/
