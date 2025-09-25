/******************************************************************************
 *
 * File Name: buzzer.c
 * Description: Source file for the buzzer driver.
 * Author: Youssef Alaa
 *
 ******************************************************************************/

#include "buzzer.h"

void BUZZER_init(void)
{
	GPIO_setupPinDirection(BUZZER_PORT, BUZZER_PIN, PIN_OUTPUT);
	BUZZER_off();
}

void BUZZER_on(void)
{
	GPIO_writePin(BUZZER_PORT, BUZZER_PIN, LOGIC_HIGH);
}

void BUZZER_off(void)
{
	GPIO_writePin(BUZZER_PORT, BUZZER_PIN, LOGIC_LOW);
}
