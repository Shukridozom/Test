/*
 * Pointers.c
 *
 *  Created on: Mar 9, 2023
 *      Author: User
 */
#include "Pointers.h"

/*
 * Test Variables
 */
uint8_t var8Bit = 0;
uint16_t var16Bit = 0;
uint32_t var32Bit = 0;
float varFloat = 0;
uint8_t arrayOfNumbers[10] = {1,2,3,4,5,6,7,8,9,10};
uint8_t outputBuffer[20] = {0};
uint8_t status;
uint8_t* ptr = NULL; //OR: uint8_t *ptr; OR: uint8_t * ptr;

//-------------------------------------------------------
void TestPointers(void)
{
	//Getting the address of the variable
	ptr = &var8Bit;

	//Accessing var8Bit by its address
	*ptr = 100;

	//Passing By Value
	var32Bit = Add_5_PassByValue(var8Bit);

	//Passing By Reference
	var32Bit = Add_5_PassByReference(&var8Bit);

	//Passing an array to a function:
	var16Bit = CalculateSumOfValues(arrayOfNumbers, 10);
	//Or: sum = CalculateSumOfValues(&numbers[0], 10);

	//Passing the output variable as reference & getting validation: passing with errors
	status = CalculateSumOfValuesWithValidation(NULL,10,&var16Bit);

	//Passing the output variable as reference & getting validation: passing without errors
	status = CalculateSumOfValuesWithValidation(arrayOfNumbers,10,&var16Bit);


	//Swapping the byte order of a 32-bit value to Big-Endian
	var32Bit = 0x1A46589D;
	var32Bit = SwapByteOrderUint32_t(var32Bit);

	//Receiving data at a specific address
	status = ReadMessage(1, outputBuffer, &var8Bit); //message id = 1
	status = ReadMessage(2, outputBuffer, &var8Bit); //message id = 2
	status = ReadMessage(10,outputBuffer, &var8Bit); //Unavailable message id

	//Representing a float value in a 32bit:
	varFloat = 1099511627775;
	status = WriteFloatAs32Bit((uint8_t*)&var32Bit, varFloat);

	//Reading a 32bit value as float: (the value is 1099511627775)
	varFloat = var32Bit; //Error
	varFloat = (float)var32Bit;
	varFloat = Read32BitAsFloat((uint8_t*)&var32Bit, &varFloat);
}

//-------------------------------------------------------
uint8_t Add_5_PassByValue(uint8_t value)
{
	value += 5;
	return value;
}

//-------------------------------------------------------
uint8_t Add_5_PassByReference(uint8_t* pData)
{

	*pData += 5;
	return *pData;
}


//-------------------------------------------------------
uint16_t CalculateSumOfValues(uint8_t* pData, uint8_t length)
{
	uint16_t value = 0;
	for(uint8_t i = 0;i<length;i++)
	{
		value += pData[i];
		//OR: value += *(pData + i);
	}

	return value;
}

//-------------------------------------------------------
uint8_t CalculateSumOfValuesWithValidation(uint8_t* pData, uint8_t length, uint16_t* sum)
{
	if(sum == NULL || pData == NULL)
		return 0;

	uint16_t value = 0;
	for(uint8_t i = 0;i<length;i++)
	{
		value += pData[i];
		//Or: value += *(pData + i);
	}
	*sum = value;
	return 1;
}

//-------------------------------------------------------
uint32_t SwapByteOrderUint32_t(uint32_t value)
{
	uint8_t* ptr = (uint8_t*)&value;
	uint8_t temp[4] = {0};
	for(uint8_t i = 0;i<4;i++)
	{
		temp[3-i] = (*ptr)++;
	}
	return (*(uint32_t*)&temp);
}

//-------------------------------------------------------
uint8_t ReadMessage(uint8_t messageId, uint8_t* pData, uint8_t* messageLength)
{
	if(pData == NULL)
		return 1;
	switch (messageId) {

		case 1:
			*pData = 'M';
			pData++; *pData = 'S';
			pData++; *pData = 'G';
			pData++; *pData = '1';
			*messageLength = 4;
			break;

		case 2:
			*pData = 'M';
			pData++; *pData = 'S';
			pData++; *pData = 'G';
			pData++; *pData = '_';
			pData++; *pData = '2';
			*messageLength = 5;

		default:
			*messageLength = 5;
			break;

	}

	if(*messageLength == 0)
		return 1;
	else
		return 0;
}

//-------------------------------------------------------
uint8_t WriteFloatAs32Bit(uint8_t* pData, float value)
{
	if(pData == NULL)
		return 1;

	uint8_t* ptr = (uint8_t*)&value;
	for(uint8_t i = 0;i<4;i++)
	{
		pData[i] = *ptr;
		ptr++;
	}
		return 0;
}

//-------------------------------------------------------
uint8_t Read32BitAsFloat(uint8_t* pData, float* value)
{
	if(pData == NULL || value == NULL)
		return 1;

	*value = (float)(*pData | (*(pData + 1)<<8) | (*(pData + 2)<<16) | (*(pData + 3) << 24));

	return 0;
}
