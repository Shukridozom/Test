/*
 * Application.h
 *
 *  Created on: Mar 13, 2023
 *      Author: User
 */

#include "DataTypes.h"

#ifndef INC_APPLICATION_H_
#define INC_APPLICATION_H_

#define MIN_VALUE	10
#define MAX_VALUE	100


void TestApplication(void);
enum Status CheckValuesUsingEnumStatus(uint8_t value);
Status_t CheckValuesUsingStatus_t(uint8_t value);


#endif /* INC_APPLICATION_H_ */
