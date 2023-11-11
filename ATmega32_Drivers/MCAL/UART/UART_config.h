/*
 * UART_config.h
 *
 * Created: 10/29/2023 2:00:06 PM
 *  Author: Hassan Said
 */ 


#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_


/*
*  Choose from:
*  UART_ASYNCHRONOUS_MODE
*  UART_SYNCHRONOUS_MODE
*  
*
*/

#define UART_MODE_SELECT UART_ASYNCHRONOUS_MODE

/*
*  Choose from:
*  PARITY_MODE_NO_PARITY
*  PARITY_MODE_EVEN
*  PARITY_MODE_ODD
*
*/

#define PARITY_MODE PARITY_MODE_NO_PARITY

/*
*  Choose from:
*  STOP_BITS_1
*  STOP_BITS_2
*
*  
*/

#define STOP_BITS_SELECT STOP_BITS_1


#endif /* UART_CONFIG_H_ */