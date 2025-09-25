/******************************************************************************
 *
 * File Name: adc.c
 * Description: ADC driver source file for ATmega32.
 * Author: Youssef Alaa
 *
 ******************************************************************************/

#include "avr/io.h" /* To use the ADC Registers */
#include "adc.h"
#include "common_macros.h" /* To use macros like SET_BIT */

/*******************************************************************************
 *                      Function Definitions                                   *
 *******************************************************************************/

void ADC_init(void)
{
	ADMUX = 0xC0;

	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
}

uint16 ADC_readChannel(uint8 channel_num)
{
	channel_num &= 0x07;
	ADMUX &= 0xE0;
	ADMUX = ADMUX | channel_num;
	SET_BIT(ADCSRA,ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF);
	return ADC;
}
