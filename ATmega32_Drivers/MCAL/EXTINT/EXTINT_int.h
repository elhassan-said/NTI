/*
 * EXTINT_int.h
 *
 * Created: 11/2/2023 8:01:18 AM
 *  Author: Hassan Said
 */ 


#ifndef EXTINT_INT_H_
#define EXTINT_INT_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTINT_config.h"
#include <avr/interrupt.h>


#define INT0_CHANNEL 0
#define INT1_CHANNEL 1
#define INT2_CHANNEL 2

void M_EXTINT_void_EXTINTInit(u8 Copy_u8_ExtIntChannel);
void M_EXTINT_void_SetCallBack(u8 Copy_u8_ExtIntChannel, void(*Copy_ptr)(void));


#endif /* EXTINT_INT_H_ */