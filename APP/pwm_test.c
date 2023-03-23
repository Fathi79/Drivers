/*
 * pwm_test.c
 *
 *  Created on: Sep 7, 2022
 *      Author: loppy
 */
/*
#include "avr/io.h"
#include "avr/delay.h"
#include "avr/interrupt.h"
#include "../MCAL/DIO/DIO_CFG.h"
#include "../MCAL/DIO/DIO.h"
#include "../UTILS/BIT_MATH.h"
#include "../MCAL/INT/INT.h"
#include "../MCAL/TIMER/TIMER.h"


void main(void)
{
	u16 PWM_val = 1000;
	u8 flag = 0;
	SET_BIT(DDRD, 5);
	Timer1_vInit();
	setTopValue(20000);
	while(1)
	{
		setOCR1A_Value(PWM_val);
		_delay_ms(500);
		if(!flag)
			PWM_val += 500;
		else if (flag)
			PWM_val -= 500;

		if(PWM_val == 2500 || PWM_val == 500)
		{
			PWM_val = 1500;
			flag = !flag;
		}
	}
}
*/
