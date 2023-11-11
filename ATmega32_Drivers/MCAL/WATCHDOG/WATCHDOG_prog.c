/*
 * WATCHDOG_prog.c
 *
 * Created: 11/5/2023 10:11:34 AM
 *  Author: Hassan Said
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "WATCHDOG_private.h"
#include "WATCHDOG_int.h"

void WDT_voidEnable(void)
{
	SET_BIT(WDTCR_, WDE);
}

void WDT_voidDisable(void)
{
	WDTCR_ |= (1 << WDTOE) | (1 << WDE);
	CLR_BIT(WDTCR_, WDE);
}
void WDT_voidSleep(u8 sleepTime)
{
	WDTCR_ &= ~0b00000111;
	#if(sleepTime == WDP_16K)
		WDTCR_ |= WDP_MASK_16K;
	#elif(sleepTime == WDP_32K)
		WDTCR_ |= WDP_MASK_32K;
	#elif(sleepTime == WDP_64K)
		WDTCR_ |= WDP_MASK_64K;
	#elif(sleepTime == WDP_128K)
		WDTCR_ |= WDP_MASK_128K;
	#elif(sleepTime == WDP_256K)
		WDTCR_ |= WDP_MASK_256K;
	#elif(sleepTime == WDP_512K)
		WDTCR_ |= WDP_MASK_512K;
	#elif(sleepTime == WDP_1024K)
		WDTCR_ |= WDP_MASK_1024K;
	#elif(sleepTime == WDP_2048K)
		WDTCR_ |= WDP_MASK_2048K;
	#else
	#error ("Invalid sleepTime")
	#endif
}

void WDT_voidKick(void)
{
	asm("WDR");
}