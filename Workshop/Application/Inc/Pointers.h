/*
 * Pointers.h
 *
 *  Created on: Mar 9, 2023
 *      Author: User
 */

#ifndef INC_POINTERS_H_
#define INC_POINTERS_H_

#include "stm32g0xx_hal.h"


/*
 * Test Variables
 */
extern uint8_t var8Bit;
extern uint16_t var16Bit;
extern uint32_t var32Bit;
extern float varFloat;
extern uint8_t arrayOfNumbers[10];
extern uint8_t outputBuffer[20];
extern uint8_t status;
extern uint8_t* ptr; //OR: uint8_t *ptr; OR: uint8_t * ptr;



void TestPointers(void);

uint8_t Add_5_PassByValue(uint8_t value);

uint8_t Add_5_PassByReference(uint8_t* pData);

uint16_t CalculateSumOfValues(uint8_t* pData, uint8_t length);

/*
 * returns: 0 -->Ok, 1 -->Error
 */
uint8_t CalculateSumOfValuesWithValidation(uint8_t* pData, uint8_t length, uint16_t* sum);

/*
 * Swap an unsigned 32bit value Byte order [From Little-Endian to Big-Endian and vice versa]
 */
uint32_t SwapByteOrderUint32_t(uint32_t value);


/*
 * returns: 0 -->Ok, 1 -->Error
 */
uint8_t ReadMessage(uint8_t messageId, uint8_t* pData, uint8_t* messageLength);

/*
 * returns: 0 -->Ok, 1 -->Error
 */
uint8_t WriteFloatAs32Bit(uint8_t* pData, float value);

/*
 * returns: 0 -->Ok, 1 -->Error
 */
uint8_t Read32BitAsFloat(uint8_t* pData, float* value);


#endif /* INC_POINTERS_H_ */
