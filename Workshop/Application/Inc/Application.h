/*
 * Application.h
 *
 *  Created on: Mar 13, 2023
 *      Author: User
 */

#ifndef INC_APPLICATION_H_
#define INC_APPLICATION_H_

typedef enum
{
	Status_OK = 0,
	Status_WrongInputParameter,
	Status_Timeout,
	Status_Error
}Status_t;


Status_t API_1(uint8_t value, uint8_t* pData);


#endif /* INC_APPLICATION_H_ */
