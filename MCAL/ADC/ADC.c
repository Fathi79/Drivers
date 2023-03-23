/*
 * ADC.c
 *
 *  Created on: Sep 4, 2022
 *      Author: loppy
 */
#include "ADC.h"

void ADC_vInit()
{
	CLEAR_PORT(DDRA);
	CLEAR_PORT(PORTA);
	//Setting Vref to 2.56V
	#if ADC_VOLTAGE == ADC_AREF_INT
	SET_BIT(ADMUX, 7);
	SET_BIT(ADMUX, 6);
	#elif ADC_VOLTAGE == ADC_AREF_EXT
	CLEAR_BIT(ADMUX, 7);
	CLEAR_BIT(ADMUX, 6);
	#elif ADC_VOLTAGE == ADC_AVCC
	CLEAR_BIT(ADMUX, 7);
	SET_BIT(ADMUX, 6);
	#endif

	//Right adjustment of the result
	CLEAR_BIT(ADMUX, 5);

	//Set channel
	ADMUX = (ADMUX & 0xE0) | (ADC_CHANNEL & 0x1F);		//Clearing the last five bits

	//Enable ADC
	SET_BIT(ADCSRA, 7);

	//Set the interrupts
	#if ADC_INT_MODE == ADC_DISABLE_INT
	CLEAR_BIT(ADCSRA, 3);
	#elif ADC_INT_MODE == ADC_ENABLE_INT
	SET_BIT(ADCSRA, 3);
	#endif

	//Set the frequency
	#if ADC_PRESCALER == ADC_PRE_128
	ADCSRA = ADCSRA | (ADC_PRESCALAR & 0x07);
	#elif ADC_PRESCALER == ADC_PRE_64
	ADCSRA = ADCSRA | (ADC_PRESCALAR & 0x07);
	#elif ADC_PRESCALER == ADC_PRE_32
	ADCSRA = ADCSRA | (ADC_PRESCALAR & 0x07);
	#elif ADC_PRESCALER == ADC_PRE_16
	ADCSRA = ADCSRA | (ADC_PRESCALAR & 0x07);
	#elif ADC_PRESCALER == ADC_PRE_8
	ADCSRA = ADCSRA | (ADC_PRESCALAR & 0x07);
	#elif ADC_PRESCALER == ADC_PRE_4
	ADCSRA = ADCSRA | (ADC_PRESCALAR & 0x07);
	#elif ADC_PRESCALER == ADC_PRE_2
	ADCSRA = ADCSRA | (ADC_PRESCALAR & 0x07);
	#endif

}

void ADC_vStartConversion(void)
{
	//Start conversion
	SET_BIT(ADCSRA, 6);
}

u16 ADC_u16ReadData(u8 channel)
{
	u16 result, temp;

	ADMUX = (ADMUX & 0xE0) | (ADC_CHANNEL & 0x1F);

	ADC_vStartConversion();

	#if ADC_INT_MODE == ADC_DISABLE_INT
	//Wait until conversion ends
	while ((READ_BIT(ADCSRA,4)) != 1);
	//Reset the flag
	SET_BIT(ADCSRA, 4);
	#elif ADC_INT_MODE == ADC_ENABLE_INT
	/* write code for interrupt */
	#endif

	return ADC;
}

