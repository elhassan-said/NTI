/*
 * ATmega32_Drivers.c
 *
 * Created: 10/24/2023 8:36:23 AM
 * Author : Hassan Said
 */ 

#define F_CPU 16000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "TIMER0_int.h"
// #include "TIMER1_int.h"
// #include "UART_int.h"
// #include "SPI_Int.h"
// #include "I2C_int.h"
#include "ADC_int.h"
#include "LM35_int.h"
#include "LCD_int.h"
#include <util/delay.h>

/*
static u8 stateCounter = 0;
static u16 Reading1 = 0; 
static u16 Reading2 = 0;
static u16 Reading3 = 0;

void ICU_HW(void);
*/


int main(void)
{	
	u8 tempValue = 0;
	
	
	// Initialize ADC
	M_ADC_Void_ADCInit();
	// Initialize LM35
	H_TEMPSENSOR_void_Init();
	// 1 - Set OC0 as output
	DIO_voidSetPinDirection(PORTB_ID, PIN3, OUTPUT);
	// 2 - Initialize Timer0 in PWM mode
	M_TIMER0_voidInit();
	// 3 - Start Timer0
	M_TIMER0_voidTimerStart();
	
	
	/*
	u8 arr[4] = "A#";
	u8 received_arr[4] = {0};
	u8 i = 0;
	
	DIO_voidSetPinDirection(PORTB_ID, PIN4, OUTPUT);
	DIO_voidSetPinDirection(PORTB_ID, PIN5, OUTPUT);
	DIO_voidSetPinDirection(PORTB_ID, PIN6, INPUT);
	DIO_voidSetPinDirection(PORTB_ID, PIN7, OUTPUT);
	
	M_SPI_voidMasterInit();
	*/
	
	/*
	// 1 - Initialize UART
	UART_voidInit();
	*/
	/*
	// Initialize TIMER1 
	// 1 - Initialize TIMER1 in normal mode
	M_TIMER1_void_Init();
	// 2 - Initialize ICU
	M_TIMER1_ICU_void_Init();
	// 3 - Set call Back
	M_TIMER1_ICU_void_setCallBack();
	// 4 - Enable ICU interrupt
	M_TIMER1_ICU_void_EnableInt();
	// 5 - Set ICP1 as input
	DIO_voidSetPinValue(PORTD_ID, PIN6, INPUT);
	
	// 1 - Set OC0 as output
	DIO_voidSetPinDirection(PORTB_ID, PIN3, OUTPUT);
	// 2 - Initialize Timer0 in PWM mode
	M_TIMER0_voidInit();
	// 3 - Start Timer0
	M_TIMER0_voidTimerStart();
	// 4 - PWM
	M_TIMER0_voidSetFastPWM(70);
	
	// Enable GIE 
	M_GIE_void_GlobalIntEnable();
	*/
	/*
	// Initialize LED
	 DIO_voidSetPinDirection(PORTA_ID, PIN6, OUTPUT);
	 DIO_voidSetPinValue(PORTA_ID, PIN6, 1);
	// Initialize Timer0 in normal mode
	 M_TIMER0_voidInit();
	// Enable OVFI
	 M_TIMER0_voidEnableInt(TIMER0_OVF_INT_ID);
	// Set time by 1 second
	 M_TIMER0_voidSetTime(1000);
	// Set Call Back
	 M_TIMER0_voidSetCallBack(A_LedAction, TIMER0_OVF_INT_ID);
	// Enable GIE
	 M_GIE_voidGlobalIntEnable();
	// Start TImer0
	 M_TIMER0_voidTimerStart();
	// M_TIMER0_voidTimerStop();
	*/
	
	/*
    DIO_voidSetPinDirection(PORTA_ID, PIN5, OUTPUT);
	DIO_voidSetPinDirection(PORTB_ID, PIN0, OUTPUT);
	*/
	
    while (1)
    {	
		
		
		tempValue = H_TEMPSENSOR_u8_readTemp();
		
		if (tempValue < 25)
		{
			M_TIMER0_voidSetFastPWM(0);
		}
		else if (tempValue >= 25 && tempValue <= 35)
		{
			M_TIMER0_voidSetFastPWM(50);
		}
		else if (tempValue > 35)
		{
			M_TIMER0_voidSetFastPWM(80);
		}
		else
		{
			
		}
		
		/*
		received_arr[i] = M_SPI_u8TransferByte(arr[i]);
		if(received_arr[i] == '#')
		break;
		i++;
		*/
		
		/*
		// 2 - Send ASCII Character
		UART_sendByte('H');
		// 3 - Delay 1000 millisecond
		_delay_ms(1000); 
		*/
		
		/*
		M_TIMER0_voidSetFastPWM(10);
		_delay_ms(2000);
		M_TIMER0_voidSetFastPWM(40);
		_delay_ms(2000);
		M_TIMER0_voidSetFastPWM(70);
		_delay_ms(2000);
		M_TIMER0_voidSetFastPWM(100);
		_delay_ms(2000);
		*/
		
		/*
		DIO_voidSetPinValue(PORTA_ID, PIN6, LOW);
		_delay_ms(1000);
		DIO_voidSetPinValue(PORTA_ID, PIN6, HIGH);
		_delay_ms(1000);
		DIO_voidTogglePinValue(PORTA_ID, PIN5);
		_delay_ms(1000);
		*/
		
    }
}

/*
void ICU_HW(void)
{
	if(stateCounter == 0) 
	{
		Reading1 = M_TIMER1_ICU_u16InputCaptureReading();
	}
	else if(stateCounter == 1)
	{
		M_TIMER1_ICU_voidsetTrigger();
		Reading2 = M_TIMER1_ICU_u16InputCaptureReading();
	}
	else if(stateCounter == 2)
	{
		Reading3 = M_TIMER1_ICU_u16InputCaptureReading();
		M_TIMER1_ICU_void_DisableInt();
	}
	stateCounter++;
}
*/