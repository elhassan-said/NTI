/*
 * ADC_prog.c
 *
 * Created: 11/2/2023 8:52:59 AM
 *  Author: Hassan Said
 */ 

#include "ADC_private.h"
#include "ADC_int.h"
#include <avr/interrupt.h>


u16 gADC_value = 0;

void M_ADC_Void_ADCInit(void)
{
	#if(ADC_VREF == AVCC)
		SET_BIT(ADMUX_REG, REFS0_BIT);
		CLR_BIT(ADMUX_REG, REFS1_BIT);
	#elif(ADC_VREF == AREF_PIN)
		CLR_BIT(ADMUX_REG, REFS0_BIT);
		CLR_BIT(ADMUX_REG, REFS1_BIT);
	#elif(ADC_VREF == _2V5)
		SET_BIT(ADMUX_REG, REFS0_BIT);
		SET_BIT(ADMUX_REG, REFS1_BIT);
	#endif
		/* TO SELECT RIGHT ADJUST */
		CLR_BIT(ADMUX_REG, ADLAR_BIT);
	#if(ADC_PRESCALER_DV == 128)
		SET_BIT(ADCSRA_REG, ADPS0_BIT);
		SET_BIT(ADCSRA_REG, ADPS1_BIT);
		SET_BIT(ADCSRA_REG, ADPS2_BIT);
	#elif(ADC_PRESCALER_DV == 64)
		CLR_BIT(ADCSRA_REG, ADPS0_BIT);
		SET_BIT(ADCSRA_REG, ADPS1_BIT);
		SET_BIT(ADCSRA_REG, ADPS2_BIT);
	#endif
		/* TO ENABLE AUTO TRIGGER MODE */
		SET_BIT(ADCSRA_REG, ADATE_BIT);
		/* TO ENABLE ADC CIRCIUT */
		SET_BIT(ADCSRA_REG, ADEN_BIT);
		/* TO START CONVERSION */
		SET_BIT(ADCSRA_REG, ADSC_BIT);

		/*
		SET_BIT(ADCSRA_REG, 3); // Interrupt Enable
		ADMUX_REG = ADMUX_REG & 0b11100000;
		ADMUX_REG = ADMUX_REG | 0;
		*/
}

u16  M_ADC_u16_ADCRead(u8 Copy_u8_AdcChannel)
{
	u32 Local_U32_Counter = 0;
	ADMUX_REG = ADMUX_REG & 0b11100000;
	ADMUX_REG = ADMUX_REG | Copy_u8_AdcChannel;

	//CLR_BIT(ADCSRA_REG,ADIF_BIT);
	SET_BIT(ADCSRA_REG,ADSC_BIT);
	while(Local_U32_Counter < 2000000)
	{
		Local_U32_Counter++;
		if(GET_BIT(ADCSRA_REG,ADIF_BIT) == ADC_CONVERSION_COMPLETE)
		{
			break;
		}
	}
	return ADCVALUE;
}

/*
ISR(ADC_vect)
{
	SET_BIT(ADCSRA_REG, ADSC_BIT);

	// put ADC reading in a global variable
	gADC_value = ADCVALUE;
}
*/