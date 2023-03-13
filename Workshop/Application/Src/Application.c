/*
 * Application.c
 *
 *  Created on: Mar 13, 2023
 *      Author: User
 */

#include "stm32g0xx_hal.h"
#include "Application.h"

enum Status status1;
Status_t status2;

//---------------------------------------------------
enum Status CheckValuesUsingEnumStatus(uint8_t value)
{
	enum Status status;
	if(value >= MIN_VALUE && value <= MAX_VALUE)
		status = Temp_Status_Ok;
	else
		status = Temp_Status_Error;

	return status;
}

//---------------------------------------------------
Status_t CheckValuesUsingStatus_t(uint8_t value)
{
	Status_t status;
	if(value >= MIN_VALUE && value <= MAX_VALUE)
		status = Status_Ok;
	else
		status = Status_Error;

	return status;
}

//---------------------------------------------------
void ApplicationTest(void)
{

	Int8Bit temp = 10;
	uint8_t x = temp + 10;

	status1 = CheckValuesUsingEnumStatus(x);
	status2 = CheckValuesUsingStatus_t(200);
}


