/*
 * LM35_prog.c
 *
 * Created: 11/6/2023 7:12:40 AM
 *  Author: Hassan Said
 */ 

#include "STD_TYPES.h"
#include "DIO_int.h"
#include "ADC_int.h"
#include "LM35_private.h"
#include "LM35_config.h"
#include "LM35_int.h"

void H_TEMPSENSOR_void_Init(void)
{
	// Set PA0 as input - Temperature sensor channel pin
	DIO_voidSetPinDirection(PORTA_ID, TEMP_SENSOR_CHANNEL, INPUT);
}
u8 H_TEMPSENSOR_u8_readTemp(void)
{
	// Call ADC to convert - Read digital value
	u16 adc_read = M_ADC_u16_ADCRead(TEMP_SENSOR_CHANNEL);
	
	// Convert digital value to 
	u32 read_mv = ((u32)adc_read * TEMP_VREF) / TEMP_RES;
	
	// Convert from mv to degree C
	u8 temp = read_mv / 10;
	
	return temp;
}