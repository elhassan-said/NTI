/*
 * ADC_int.h
 *
 * Created: 11/2/2023 8:47:34 AM
 *  Author: Hassan Said
 */ 


#ifndef ADC_INT_H_
#define ADC_INT_H_


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_config.h"

#define ADC_CHANNEL_0      0
#define ADC_CHANNEL_1      1
#define ADC_CHANNEL_2      2
#define ADC_CHANNEL_3      3
#define ADC_CHANNEL_4      4
#define ADC_CHANNEL_5      5
#define ADC_CHANNEL_6      6
#define ADC_CHANNEL_7      7

void M_ADC_Void_ADCInit(void);
u16  M_ADC_u16_ADCRead(u8);



#endif /* ADC_INT_H_ */