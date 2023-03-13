/*
 * DataTypes.h
 *
 *  Created on: Mar 13, 2023
 *      Author: User
 */

#ifndef INC_DATATYPES_H_
#define INC_DATATYPES_H_

//---------------------------------------------------
enum Status
{
	Temp_Status_Ok = 0,
	Temp_Status_Error
};

//---------------------------------------------------
typedef enum
{
	Status_Ok = 0,
	Status_Error
}Status_t;

//---------------------------------------------------
typedef uint8_t Int8Bit;

//---------------------------------------------------
typedef struct
{
	uint16_t pressure;
	uint16_t acceleration;
}Sensor_t;

//---------------------------------------------------
typedef struct
{
	Sensor_t Sensor1;
	Sensor_t Sensor2;
}Sensor_Unit_t;



#endif /* INC_DATATYPES_H_ */
