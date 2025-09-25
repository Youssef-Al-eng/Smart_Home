/******************************************************************************
 *
 * File Name: lm35_sensor.h
 * Description: Header file for interfacing the LM35 temperature sensor using ADC.
 * Author: Youssef Alaa
 *
 ******************************************************************************/

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "std_types.h"

#define SENSOR_CHANNEL_ID         1
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150

uint8 LM35_getTemperature(void);

#endif /* LM35_SENSOR_H_ */
