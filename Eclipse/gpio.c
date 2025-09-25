/******************************************************************************
 *
 * File Name: gpio.c
 * Description: Source file for the AVR GPIO driver.
 * Author: Youssef Alaa
 *
 ******************************************************************************/

#include "gpio.h"
#include "common_macros.h"
#include "std_types.h"
#include "avr/io.h"

void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction)
{
	if ((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS)) {
		// Do Nothing
	} else {
		switch (port_num) {
			case PORTA_ID:
				(direction == PIN_OUTPUT) ? SET_BIT(DDRA, pin_num) : CLEAR_BIT(DDRA, pin_num);
				break;
			case PORTB_ID:
				(direction == PIN_OUTPUT) ? SET_BIT(DDRB, pin_num) : CLEAR_BIT(DDRB, pin_num);
				break;
			case PORTC_ID:
				(direction == PIN_OUTPUT) ? SET_BIT(DDRC, pin_num) : CLEAR_BIT(DDRC, pin_num);
				break;
			case PORTD_ID:
				(direction == PIN_OUTPUT) ? SET_BIT(DDRD, pin_num) : CLEAR_BIT(DDRD, pin_num);
				break;
		}
	}
}

void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value)
{
	if (port_num >= NUM_OF_PORTS || pin_num >= NUM_OF_PINS_PER_PORT) {
		// Do Nothing
	} else {
		switch (port_num) {
			case PORTA_ID:
				(value == LOGIC_HIGH) ? SET_BIT(PORTA, pin_num) : CLEAR_BIT(PORTA, pin_num);
				break;
			case PORTB_ID:
				(value == LOGIC_HIGH) ? SET_BIT(PORTB, pin_num) : CLEAR_BIT(PORTB, pin_num);
				break;
			case PORTC_ID:
				(value == LOGIC_HIGH) ? SET_BIT(PORTC, pin_num) : CLEAR_BIT(PORTC, pin_num);
				break;
			case PORTD_ID:
				(value == LOGIC_HIGH) ? SET_BIT(PORTD, pin_num) : CLEAR_BIT(PORTD, pin_num);
				break;
		}
	}
}

uint8 GPIO_readPin(uint8 port_num, uint8 pin_num)
{
	if (port_num >= NUM_OF_PORTS || pin_num >= NUM_OF_PINS_PER_PORT) {
		return 0;
	} else {
		switch (port_num) {
			case PORTA_ID:
				return BIT_IS_SET(PINA, pin_num);
			case PORTB_ID:
				return BIT_IS_SET(PINB, pin_num);
			case PORTC_ID:
				return BIT_IS_SET(PINC, pin_num);
			case PORTD_ID:
				return BIT_IS_SET(PIND, pin_num);
		}
	}
	return 0;
}

void GPIO_setupPortDirection(uint8 port_num, GPIO_PortDirectionType direction)
{
	if (port_num >= NUM_OF_PORTS) {
		// Do Nothing
	} else {
		switch (port_num) {
			case PORTA_ID:
				DDRA = direction;
				break;
			case PORTB_ID:
				DDRB = direction;
				break;
			case PORTC_ID:
				DDRC = direction;
				break;
			case PORTD_ID:
				DDRD = direction;
				break;
		}
	}
}

void GPIO_writePort(uint8 port_num, uint8 value)
{
	if (port_num >= NUM_OF_PORTS) {
		// Do Nothing
	} else {
		switch (port_num) {
			case PORTA_ID:
				PORTA = value;
				break;
			case PORTB_ID:
				PORTB = value;
				break;
			case PORTC_ID:
				PORTC = value;
				break;
			case PORTD_ID:
				PORTD = value;
				break;
		}
	}
}

uint8 GPIO_readPort(uint8 port_num)
{
	if (port_num >= NUM_OF_PORTS) {
		return 0;
	} else {
		switch (port_num) {
			case PORTA_ID:
				return PINA;
			case PORTB_ID:
				return PINB;
			case PORTC_ID:
				return PINC;
			case PORTD_ID:
				return PIND;
		}
	}
	return 0;
}
