/*
 * UART_private.h
 *
 * Created: 10/29/2023 2:02:23 PM
 *  Author: Hassan Said
 */ 


#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#define UBRRL 	(*((volatile u8 *)0x29)) // USART Baud Rate Register
#define UBRRH   (*((volatile u8 *)0x40)) 
#define UCSRA 	(*((volatile u8 *)0x2B)) // USART Control and Status Register A
#define UCSRB 	(*((volatile u8 *)0x2A)) // USART Control and Status Register B
#define UCSRC 	(*((volatile u8 *)0x40)) // USART Control and Status Register C
#define UDR 	(*((volatile u8 *)0x2C)) // USART I/O Data Register

// UCSRA
#define RXC		7
#define TXC		6
#define UDRE	5
#define FE		4
#define DOR		3
#define PE		2
#define U2X		1
#define MPCM	0

// UCSRB
#define RXCIE	7
#define TXCIE	6
#define UDRIE	5
#define RXEN	4
#define TXEN	3
#define UCSZ2	2
#define RXB8	1
#define TXB8	0

// UCSRC
#define URSEL	7
#define UMSEL	6
#define UPM1	5
#define UPM0	4
#define USBS	3
#define UCSZ1	2
#define UCSZ0	1
#define UCPOL	0

#define UART_ASYNCHRONOUS_MODE 0
#define UART_SYNCHRONOUS_MODE  1

#define PARITY_MODE_NO_PARITY 0
#define PARITY_MODE_EVEN      2
#define PARITY_MODE_ODD       3

#define STOP_BITS_1 0
#define STOP_BITS_2 1

#define BAUD_9600HZ 51


#endif /* UART_PRIVATE_H_ */