/*
 * DIO_prog.c
 *
 * Created: 10/24/2023 10:07:24 PM
 *  Author: Hassan Said
 */ 


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_private.h"
#include "DIO_int.h"



void DIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direc)
{
	switch(Copy_u8Port)
	{
		case PORTA_ID:
			CLR_BIT(DDRA,Copy_u8Pin);
			DDRA |= Copy_u8Direc << Copy_u8Pin;
		break;

		case PORTB_ID:
			CLR_BIT(DDRB,Copy_u8Pin);
			DDRB |= Copy_u8Direc << Copy_u8Pin;
		break;
		
		case PORTC_ID:
			CLR_BIT(DDRC,Copy_u8Pin);
			DDRC |= Copy_u8Direc << Copy_u8Pin;
		break;
		
		case PORTD_ID:
			CLR_BIT(DDRD,Copy_u8Pin);
			DDRD |= Copy_u8Direc << Copy_u8Pin;
		break;
		default:
		break;
	}
}

void DIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
			case PORTA_ID:
			CLR_BIT(PORTA,Copy_u8Pin);
			PORTA |= (Copy_u8Value) << (Copy_u8Pin);
			break;

			case PORTB_ID:
			CLR_BIT(PORTB,Copy_u8Pin);
			PORTB |= Copy_u8Value << Copy_u8Pin;
			break;
			
			case PORTC_ID:
			CLR_BIT(PORTC,Copy_u8Pin);
			PORTC |= Copy_u8Value << Copy_u8Pin;
			break;
			
			case PORTD_ID:
			CLR_BIT(DDRD,Copy_u8Pin);
			PORTD |= Copy_u8Value << Copy_u8Pin;
			break;
			default:
			break;
		}
}

void DIO_voidGetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin, u8 *ptrValue)
{
	switch(Copy_u8Port)
	{
		case PORTA_ID:
		*ptrValue = GET_BIT(PINA,Copy_u8Pin);
		break;

		case PORTB_ID:
		*ptrValue = GET_BIT(PINB,Copy_u8Pin);
		break;
		
		case PORTC_ID:
		*ptrValue = GET_BIT(PINC,Copy_u8Pin);
		break;
		
		case PORTD_ID:
		*ptrValue = GET_BIT(PIND,Copy_u8Pin);
		break;
		default:
		break;
	}
}
void DIO_voidTogglePinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
		switch(Copy_u8Port)
		{
			case PORTA_ID:
			TOG_BIT(PORTA, Copy_u8Pin);
			break;

			case PORTB_ID:
			TOG_BIT(PORTB, Copy_u8Pin);
			break;
			
			case PORTC_ID:
			TOG_BIT(PORTC, Copy_u8Pin);
			break;
			
			case PORTD_ID:
			TOG_BIT(PORTC, Copy_u8Pin);
			break;
			default:
			break;
		}
}
