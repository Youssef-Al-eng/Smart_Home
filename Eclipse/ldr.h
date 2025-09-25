/******************************************************************************
 *
 * File Name: ldr.h
 * Description: Header file for the LDR sensor driver.
 * Author: Youssef Alaa
 *
 ******************************************************************************/

#ifndef LDR_H_
#define LDR_H_

#include "std_types.h"

#define LDR_SENSOR_CHANNEL				  0
#define LDR_SENSOR_MAX_VOLT 			  2.56
#define LDR_SENSOR_MAX_LIGHT_INTENSITY	  100

uint16 LDR_getLightIntensity(void);

#endif /* LDR_H_ */
