/*
 * TIMER1_prog.c
 *
 * Created: 10/29/2023 11:02:19 AM
 *  Author: Hassan Said
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER1_private.h"
#include "TIMER1_config.h"
#include "TIMER1_int.h"
#include <avr/interrupt.h>

static void (*TIMER1_ICU_ptrCallBack)(void) = NULL;


void M_TIMER1_void_Init(void)
{
	// Normal mode
	CLR_BIT(TCCR1A, WGM10);
	CLR_BIT(TCCR1A, WGM11);
	CLR_BIT(TCCR1B, WGM12);
	CLR_BIT(TCCR1B, WGM13);
	
	// Prescaler 
	CLR_BIT(TCCR1B, CS10);
	CLR_BIT(TCCR1B, CS11);
	SET_BIT(TCCR1B, CS12);
}
void M_TIMER1_ICU_void_Init(void)
{
	SET_BIT(TCCR1B, ICES1);
}
void M_TIMER1_ICU_void_EnableInt(void) // valid
{
	SET_BIT(TIMSK, TICIE1);
}
void M_TIMER1_ICU_void_DisableInt(void) // valid
{
	CLR_BIT(TIMSK, TICIE1);
}
void M_TIMER1_ICU_void_setCallBack(void (*ptrCallBack)(void))
{
	TIMER1_ICU_ptrCallBack = ptrCallBack;
}
u16  M_TIMER1_ICU_u16InputCaptureReading(void) // valid
{
	return ICR1;
}
void M_TIMER1_ICU_voidsetTrigger(u8 copy_u8Trigger) // valid
{
	switch (copy_u8Trigger)
	{
		case TIMER1_ICU_RISING_EDGE_TRIGGER :
		SET_BIT(TCCR1B, ICES1);
		break;
		case TIMER1_ICU_FALLING_EDGE_TRIGGER :
		CLR_BIT(TCCR1B, ICES1);
		break;
	}
}
ISR(TIMER1_CAPT_vect)
{
	if(TIMER1_ICU_ptrCallBack != NULL)
	{
		TIMER1_ICU_ptrCallBack();
	}
}
