/*
 * TIMER_prog.c
 *
 * Created: 10/24/2023 9:27:43 AM
 *  Author: Hassan Said
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"
#include "TIMER0_int.h"
#include <avr/interrupt.h>
#include <stdlib.h>



static u32 TIMER0_u32NumOfOverflows = 0;
static u8 TIMER0_u8NumOfRemainingTicks = 0;
void (*TIMER0_ptrCallBackArr[2]) (void) = {NULL, NULL};


void M_TIMER0_voidInit(void) // valid 
{
	// - Configure timer mode
	#if(TIMER0_MODE == TIMER0_MODE_NORMAL)
		CLR_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
	// - Configure OC0 pin mode
	/*
	#if(TIMER0_OC0_MODE >= TIMER0_OC0_MODE_DISCONNECTED && TIMER0_OC0_MODE <= TIMER0_OC0_MODE_SET)
		TCCR0 &= TIMER0_OC0_MASK;
		TCCR0 |= TIMER0_OC0_MODE << TIMER0_OC0_SH;
	#else
		#error ("Invalid OC0 Mode")
	#endif
	*/
	#elif(TIMER0_MODE == TIMER0_MODE_CTC)
		CLR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
	#elif(TIMER0_MODE == TIMER0_MODE_FAST_PWM)
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
	// Configure OC0 Mode
	#if(TIMER0_OC0_MODE == TIMER0_OC0_MODE_PWM_NONINVERTED || TIMER0_OC0_MODE == TIMER0_OC0_MODE_PWM_INVERTED)
	TCCR0 &= TIMER0_OC0_MASK;
	TCCR0 |= TIMER0_OC0_MODE; // 0b00100000
	// || TIMER0_OC0_MODE == TIMER0_OC0_MODE_PWM_INVERTED)
	#else
		#error ("Invalid OC0 Mode")
	#endif
	#elif(TIMER0_MODE == TIMER0_MODE_PHASECORRECT_PWM)
		SET_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
	#else
		#error ("Invalid Timer Mode")
	#endif
	
}
void M_TIMER0_voidSetTime(u32 copy_u32Delay) // millisecond 
{
	u32 Local_u32arr[5] = {1,8,64,512,1024};
	f32 Local_u32TickTime = (f32) Local_u32arr[TIMER0_PRESCALER-1] / FCPU;
	u32 Local_u32DesiredTicks = (copy_u32Delay * 1000) / Local_u32TickTime;
	TIMER0_u32NumOfOverflows = Local_u32DesiredTicks / 256;
	TIMER0_u8NumOfRemainingTicks = Local_u32DesiredTicks % 256;
	if(TIMER0_u8NumOfRemainingTicks != 0)
	{
		TCNT0 = 256 - TIMER0_u8NumOfRemainingTicks;
		TIMER0_u32NumOfOverflows++;
	}
	
}
void M_TIMER0_voidTimerStart(void) // valid
{
	// - Configure prescaler 
		#if((TIMER0_PRESCALER >=  TIMER0_TIMER_STOP) && (TIMER0_PRESCALER <= TIMER0_PRESCALER_EXT_RISING_EDGE))
		TCCR0 &= TIMER0_PRESCALER_MASK;
		TCCR0 |= TIMER0_PRESCALER;
	#else
		#error ("Invalid Prescaler")
	#endif
	
}
void M_TIMER0_voidTimerStop(void)
{
	TCCR0 &= TIMER0_PRESCALER_MASK;
}
void M_TIMER0_voidSetCallBack(void(*ptrCallBack)(void), u8 copy_u8IntID)
{
	TIMER0_ptrCallBackArr[copy_u8IntID] = ptrCallBack;
}
void M_TIMER0_voidEnableInt(u8 copy_u8IntID)
{
	switch(copy_u8IntID)
	{
		case TIMER0_OVF_INT_ID:
			SET_BIT(TIMSK,TOIE0);
		break;
		
		case TIMER0_OCM_INT_ID:
			SET_BIT(TIMSK,OCIE0);
		break;
		default:
		break;
	}
}
void M_TIMER0_voidDisableInt(u8 copy_u8IntID)
{
	switch(copy_u8IntID)
	{
		case TIMER0_OVF_INT_ID:
		CLR_BIT(TIMSK,TOIE0);
		break;
		
		case TIMER0_OCM_INT_ID:
		CLR_BIT(TIMSK,OCIE0);
		break;
		default:
		break;
	}
}
void M_TIMER0_voidSetFastPWM(u8 copy_u8DutyCycle) // valid
{
	#if(TIMER0_MODE == TIMER0_MODE_FAST_PWM)
		#if(TIMER0_OC0_MODE == TIMER0_OC0_MODE_PWM_NONINVERTED)
			OCR0_ = abs(((copy_u8DutyCycle * 256)/100) - 1);
		#elif(TIMER0_OC0_MODE == TIMER0_OC0_MODE_PWM_INVERTED)
			OCR0_ = abs(255 - ((copy_u8DutyCycle * 256)/100));
		#else
			#error ("Invalid OC0 Mode")
		#endif
	#endif	
}
ISR(TIMER0_OVF_vect) /* The ISR will be entered every overflow and OFVcounter will be incremented every time entering the ISR if this counter equals number of over flows */
{
	static u32 OVFcounter = 0;
	OVFcounter++;
	if(OVFcounter == TIMER0_u32NumOfOverflows)
	{
		TCNT0 = 256 - TIMER0_u8NumOfRemainingTicks; // Preload TCNT0
	}
	TIMER0_ptrCallBackArr[TIMER0_OVF_INT_ID](); // Call function in application layer
	OVFcounter = 0; // Clear counter
}
ISR(TIMER0_COMP_vect)
{
	
}



