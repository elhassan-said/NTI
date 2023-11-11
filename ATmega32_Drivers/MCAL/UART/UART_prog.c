/*
 * UART_prog.c
 *
 * Created: 10/29/2023 2:04:01 PM
 *  Author: Hassan Said
 */ 

#define F_CPU 8000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_config.h"
#include "UART_private.h"
#include "UART_int.h"



void UART_voidInit()
{	
	/*
	u16 UBRR_Value = 51;
	UBRRL = (u8) UBRR_Value;
	// CLR_BIT(UBRRH, URSEL);
	UBRRH = (u8) (UBRR_Value >> 8);
	*/
	SET_BIT(UCSRB, RXEN);
	SET_BIT(UCSRB, TXEN);	UCSRC |= (3 << UCSZ0);
	
	u8 temp = UCSRC;
	SET_BIT(temp, URSEL);
	
	#if(UART_MODE_SELECT == UART_ASYNCHRONOUS_MODE)
	CLR_BIT(temp, UMSEL);
	#elif(UART_MODE_SELECT == UART_SYNCHRONOUS_MODE)
	SET_BIT(temp, UMSEL);
	#else
		#error ("Invalid UART Mode")
	#endif
	
	#if(PARITY_MODE == PARITY_MODE_EVEN)
	SET_BIT(temp, UPM1);
	CLR_BIT(temp, UPM0);
	#elif(PARITY_MODE == PARITY_MODE_ODD)
	SET_BIT(temp, UPM1);
	SET_BIT(temp, UPM0);
	#elif(PARITY_MODE == PARITY_MODE_NO_PARITY)
	CLR_BIT(temp, UPM1);
	CLR_BIT(temp, UPM0);
	#else
		#error ("Invalid Parity Mode")
	#endif
	
	#if(STOP_BITS_SELECT == STOP_BITS_1)
	CLR_BIT(temp, USBS);
	#elif(STOP_BITS_SELECT == STOP_BITS_2)
	SET_BIT(temp, USBS);
	#else
		#error ("Invalid Selcetin")
	#endif
	
	UCSRC = temp;
	
    UBRRH = 0; // Clear UBBRH
	UBRRL = BAUD_9600HZ;
}

void UART_sendByte(u8 copy_u8Data)
{
	while(GET_BIT(UCSRA, UDRE) == 0); // Stuck here until the buffer is empty
	
	SET_BIT(UCSRA, TXC); // Clear TXC Flag
	UDR = copy_u8Data;
}

void UART_recieveByte(u8 *copy_u8Byte)
{
	while(GET_BIT(UCSRA, RXC) == 0); // Stuck here until data is received
	
	SET_BIT(UCSRA, RXC); // Clear RXC Flag
	UDR = *copy_u8Byte;
}