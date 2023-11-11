/*
 * DIO_int.h
 *
 * Created: 10/24/2023 9:52:29 PM
 *  Author: Hassan Said
 */ 


#ifndef DIO_INT_H_
#define DIO_INT_H_

#define PORTA_ID 0
#define PORTB_ID 1
#define PORTC_ID 2
#define PORTD_ID 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define INPUT  0
#define OUTPUT 1

#define LOW  0
#define HIGH 1

#define DDRA_INPUT_MASK  0x00
#define DDRB_INPUT_MASK  0x00
#define DDRC_INPUT_MASK  0x00
#define DDRD_INPUT_MASK  0x00
#define DDRA_OUTPUT_MASK 0xFF
#define DDRB_OUTPUT_MASK 0xFF
#define DDRC_OUTPUT_MASK 0xFF
#define DDRD_OUTPUT_MASK 0xFF

void DIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direc); /* Function for set pin direction that takes port name, pin name and direction all values from the same file */
void DIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value); /* Function for set pin value */
void DIO_voidGetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin, u8 *ptrValue);
void DIO_voidTogglePinValue(u8 Copy_u8Port, u8 Copy_u8Pin);

/*
void DIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direc);
void DIO_voidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);
void DIO_voidGetPortValue (u8 Cpy_u8Port);
*/


#endif /* DIO_INT_H_ */