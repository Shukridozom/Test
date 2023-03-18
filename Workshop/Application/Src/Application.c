/*
 * Application.c
 *
 *  Created on: Mar 13, 2023
 *      Author: User
 */

//API: Application Programming Interface

// output result
// asserting parameters [data validation]

#include "stm32g0xx_hal.h"
#include "Application.h"

static Status_t Step1(void);
static Status_t Step2(void);
static Status_t Step3(void);
static Status_t Step4(void);
static Status_t Step5WithTimeout(uint32_t timeout);
static uint8_t flag = 0;


Status_t API_1(uint8_t value, uint8_t* pData)
{
	Status_t status = Status_OK;
	if(pData == NULL)
		return Status_Error;

	status = Step1(); // Step1() function in Application.c file
	if(status == Status_Error)
		return Status_Error;

	status = Step2();
	if(status == Status_Error)
		return Status_Error;

	status = Step3();
	if(status == Status_Error)
		return Status_Error;

	status = Step4();
	if(status != Status_OK)
		return Status_Error;


	status = Step5WithTimeout(100);
	if(status == Status_Timeout)
		return status;


	return status;
}



static Status_t Step5WithTimeout(uint32_t timeout)
{
	const uint32_t maxValue = 0xFFFFFFFF;
	uint32_t tickstart = HAL_GetTick();
	uint32_t currentTick = HAL_GetTick();
	uint32_t compareValue = 0;
	Status_t status = Status_OK;


	while(compareValue < timeout)
	{
		status = Status_Timeout;
		currentTick = HAL_GetTick();

		if(currentTick > tickstart)
			compareValue = currentTick - tickstart;
		else
			compareValue = currentTick - tickstart + maxValue;


		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_RESET)
		{
			//Implementation
			status = Status_OK;
			break;
		}
	}

	return status;

}

static Status_t Step1(void)
{
	return Status_OK;
}

static Status_t Step2(void)
{
	return Status_OK;
}

static Status_t Step3(void)
{
	return Status_OK;
}

static Status_t Step4(void)
{
	return Status_OK;
}




