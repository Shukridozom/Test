/*
 * Functions.c
 *
 *  Created on: Mar 6, 2023
 *      Author: User
 */

#include "stm32g0xx_hal.h"

// variable1 declaration
extern int variable1;

//variable2 declaration
extern int variable2;


//Function1(int a) definition
int Function1(int a)
{
	return a + variable1*10 + variable2*100;
}


