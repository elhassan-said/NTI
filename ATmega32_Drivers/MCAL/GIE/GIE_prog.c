/*
 * GIE_prog.c
 *
 * Created: 11/2/2023 7:44:32 AM
 *  Author: Hassan Said
 */



#include "GIE_int.h"
#include "GIE_private.h"

void M_GIE_void_GlobalIntEnable(void)
{
	SET_BIT(SREG_REG, I_BIT);
}
void M_GIE_void_GlobalIntDisable(void)
{
	CLR_BIT(SREG_REG, I_BIT);
}
