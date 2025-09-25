/******************************************************************************
 *
 * File Name: buzzer.h
 * Description: Header file for the buzzer driver.
 * Author: Youssef Alaa
 *
 ******************************************************************************/

#ifndef BUZZER_H_
#define BUZZER_H_

#include "gpio.h" /* To use setup pin direction functions */

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define BUZZER_PORT PORTD_ID
#define BUZZER_PIN  PIN3_ID

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

void BUZZER_init(void);
void BUZZER_on(void);
void BUZZER_off(void);

#endif /* BUZZER_H_ */
