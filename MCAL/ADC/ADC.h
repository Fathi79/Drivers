/*
 * ADC.h
 *
 *  Created on: Sep 4, 2022
 *      Author: loppy
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_

#include "ADC_CFG.h"
#include "avr/io.h"
#include "avr/interrupt.h"
#include "../../UTILS/STD_TYPES.h"
#include "../../UTILS/BIT_MATH.h"

/****************** ADC CONFIGURATION ***************/

#define ADC_VOLTAGE		ADC_AREF_INT
#define ADC_CHANNEL		ADC_CH0
#define ADC_PRESCALAR	ADC_PRE_64
#define ADC_INT_MODE	ADC_DISABLE_INT

/****************** FUNCTIONS PROTOTYPES *************/

void ADC_vInit();

void ADC_vStartConversion(void);

u16 ADC_u16ReadData(u8 channel);

#endif /* MCAL_ADC_ADC_H_ */
