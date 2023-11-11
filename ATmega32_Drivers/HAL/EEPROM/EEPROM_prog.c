/*
 * EEPROM_prog.c
 *
 * Created: 11/1/2023 6:12:48 PM
 *  Author: Hassan Said
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "I2C_int.h"
#include "EEPROM_private.h"
#include "EEPROM_config.h"
#include "EEPROM_int.h"


void H_EEPROM_void_Init(void)
{
	M_TWI_void_Init();
}

void H_EEPROM_void_writeByte(u16 copy_u16add, u8 copy_u8data)
{
	u8 _3MSB = 0;
	M_TWI_void_sendStart();
	if ( !(M_TWI_u8_getStatus() == TWI_MT_START_SUCCESS) )
	{
		return 0;
	}
	_3MSB = (u8) ((copy_u16add & 0700) >> 7); // 0000 A10 A9 A8 R/W 
	M_TWI_void_sendByte(_3MSB | 0x0A);
	if ( !(M_TWI_u8_getStatus() == TWI_MT_SLA_W_ACK))
	{
		return 0;
	}
	M_TWI_void_sendByte((u8)copy_u16add); // A7 --- A0
	if ( !(M_TWI_u8_getStatus() == TWI_MT_SLA_W_ACK))
	{
		return 0;
	}
	M_TWI_void_sendByte(copy_u8data);
	if ( !(M_TWI_u8_getStatus() == TWI_MT_SLA_W_ACK))
	{
		return 0;
	}
	M_TWI_void_sendStop();
	return 1;
}
u8 H_EEPROM_u8_readByte(u16 copy_u16add, u8 *ptr)
{
	
}