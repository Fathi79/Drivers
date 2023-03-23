/*
 * ADC_CFG.h
 *
 *  Created on: Sep 5, 2022
 *      Author: loppy
 */

#ifndef MCAL_ADC_ADC_CFG_H_
#define MCAL_ADC_ADC_CFG_H_

/******************* ADC MAX VOLTAGE *************/

#define ADC_AREF_INT	1 // voltage = 2.56
#define ADC_AREF_EXT	2 // voltage = any desired value
#define ADC_AVCC		3 // voltage = 5V


/******************* ADC CHANNELS *****************/

#define ADC_CH0		0
#define ADC_CH1		1
#define ADC_CH2		2
#define ADC_CH3		3
#define ADC_CH4		4
#define ADC_CH5		5
#define ADC_CH6		6
#define ADC_CH7		7


/******************* ADC PRESCALAR *************/

#define ADC_PRE_2		1
#define ADC_PRE_4		2
#define ADC_PRE_8		3
#define ADC_PRE_16		4
#define ADC_PRE_32		5
#define ADC_PRE_64		6
#define ADC_PRE_128		7


/****************** ADC INTERRUPT STATE ************/

#define ADC_ENABLE_INT		1
#define ADC_DISABLE_INT		2


#endif /* MCAL_ADC_ADC_CFG_H_ */
