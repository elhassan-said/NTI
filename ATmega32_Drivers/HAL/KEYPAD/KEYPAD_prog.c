/*
 * KEYPAD_prog.c
 *
 * Created: 11/9/2023 2:18:24 PM
 *  Author: Hassan Said
 */ 

#define F_CPU 16000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "KEYPAD_config.h"
#include "KEYPAD_int.h"
#include <util/delay.h>

void H_KeyPad_Void_KeyPadInit(void)
{
	DIO_voidSetPinDirection(KEYPAD_R0_PORT,KEYPAD_R0_PIN,OUTPUT);
	DIO_voidSetPinDirection(KEYPAD_R1_PORT,KEYPAD_R1_PIN,OUTPUT);
	DIO_voidSetPinDirection(KEYPAD_R2_PORT,KEYPAD_R2_PIN,OUTPUT);
	DIO_voidSetPinDirection(KEYPAD_R3_PORT,KEYPAD_R3_PIN,OUTPUT);

	DIO_voidSetPinDirection(KEYPAD_C0_PORT,KEYPAD_C0_PIN,INPUT);
	DIO_voidSetPinDirection(KEYPAD_C1_PORT,KEYPAD_C1_PIN,INPUT);
	DIO_voidSetPinDirection(KEYPAD_C2_PORT,KEYPAD_C2_PIN,INPUT);
	DIO_voidSetPinDirection(KEYPAD_C3_PORT,KEYPAD_C3_PIN,INPUT);

	DIO_voidSetPinValue(KEYPAD_R0_PORT,KEYPAD_R0_PIN,HIGH);
	DIO_voidSetPinValue(KEYPAD_R1_PORT,KEYPAD_R1_PIN,HIGH);
	DIO_voidSetPinValue(KEYPAD_R2_PORT,KEYPAD_R2_PIN,HIGH);
	DIO_voidSetPinValue(KEYPAD_R3_PORT,KEYPAD_R3_PIN,HIGH);
}
u8   H_KeyPad_U8_KeyPadRead(void)
{
	u8 Local_U8_Arr[4][4] = {{ '1' , '2' , '3' , 'A' },
	{ '4' , '5' , '6' , 'B' },
	{ '7' , '8' , '9' , 'C' },
	{ '*' , '0' , '#' , 'D' }};
	u8 Local_U8_Reading = 0;
	u8 Local_U8_Col     = 0;
	u8 Local_U8_Row     = 0;
	for(Local_U8_Row = KEYPAD_R0_PIN ; Local_U8_Row <= KEYPAD_R3_PIN ; Local_U8_Row++)
	{
		DIO_voidSetPinValue(KEYPAD_R0_PORT,Local_U8_Row,LOW);
		for(Local_U8_Col = KEYPAD_C0_PIN ; Local_U8_Col<= KEYPAD_C3_PIN ; Local_U8_Col++)
		{
			if(DIO_voidGetPinValue(KEYPAD_C0_PORT,Local_U8_Col) == KEYPAD_PRESSED)
			{
				_delay_ms(KEYPAD_DEBOUNCING_TIME);
				if(DIO_voidGetPinValue(KEYPAD_C0_PORT,Local_U8_Col) == KEYPAD_PRESSED)
				{
					while(DIO_voidGetPinValue(KEYPAD_C0_PORT,Local_U8_Col) == KEYPAD_PRESSED);
					Local_U8_Reading = Local_U8_Arr[Local_U8_Row - KEYPAD_R0_PIN][Local_U8_Col - KEYPAD_C0_PIN];
					break;
				}
			}
		}
		DIO_voidSetPinValue(KEYPAD_R0_PORT,Local_U8_Row,HIGH);
	}
	return Local_U8_Reading;
}