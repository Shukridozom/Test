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

Int8Bit varInt8Bit = 10;
uint8_t var8Bit = 0;


Sensor_Unit_t unit1 = {0}, unit2 = {0};

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
Status_t CopySenorData(Sensor_t sourceSensor, Sensor_t* targetSensor)
{
	if(targetSensor == NULL)
		return Status_Error;

	targetSensor->acceleration = sourceSensor.acceleration;
	targetSensor->pressure = sourceSensor.pressure;

	return Status_Ok;
}
//---------------------------------------------------
Status_t CopyUnitData(Sensor_Unit_t sourceUnit, Sensor_Unit_t* targetUnit)
{
	if(targetUnit == NULL)
		return Status_Error;

	targetUnit->Sensor1.acceleration = sourceUnit.Sensor1.acceleration;
	targetUnit->Sensor1.pressure = sourceUnit.Sensor1.pressure;

	targetUnit->Sensor2 = sourceUnit.Sensor2;

	return Status_Ok;
}

//---------------------------------------------------
void ApplicationTest(void)
{

	var8Bit = varInt8Bit + 20;

	status1 = CheckValuesUsingEnumStatus(var8Bit);
	status2 = CheckValuesUsingStatus_t(200);


	unit1.Sensor1.acceleration = 10;
	unit1.Sensor1.pressure = 20;
	unit1.Sensor2.acceleration = 30;
	unit1.Sensor2.pressure = 40;

	CopyUnitData(unit1, &unit2);
}


