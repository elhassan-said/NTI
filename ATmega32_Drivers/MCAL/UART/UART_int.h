/*
 * UART_int.h
 *
 * Created: 10/29/2023 2:00:38 PM
 *  Author: Hassan Said
 */ 


#ifndef UART_INT_H_
#define UART_INT_H_



void UART_voidInit();
void UART_sendByte(u8 copy_u8Data);
void UART_recieveByte(u8 *copy_u8Byte);


#endif /* UART_INT_H_ */