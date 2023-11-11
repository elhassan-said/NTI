/*
 * KEYPAD_config.h
 *
 * Created: 11/9/2023 2:00:01 PM
 *  Author: Hassan Said
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define KEYPAD_R0_PORT            PORTC_ID
#define KEYPAD_R0_PIN             PIN5
#define KEYPAD_R1_PORT            PORTC_ID
#define KEYPAD_R1_PIN             PIN4
#define KEYPAD_R2_PORT            PORTC_ID
#define KEYPAD_R2_PIN             PIN3
#define KEYPAD_R3_PORT            PORTC_ID
#define KEYPAD_R3_PIN             PIN2

#define KEYPAD_C0_PORT            PORTD_ID
#define KEYPAD_C0_PIN             PIN7
#define KEYPAD_C1_PORT            PORTD_ID
#define KEYPAD_C1_PIN             PIN6
#define KEYPAD_C2_PORT            PORTD_ID
#define KEYPAD_C2_PIN             PIN5
#define KEYPAD_C3_PORT            PORTD_ID
#define KEYPAD_C3_PIN             PIN3

/*
 * SELECT KEYPAD_DEBOUNCING_TIME IN MILLI SECOND
 */

#define KEYPAD_DEBOUNCING_TIME    120



#endif /* KEYPAD_CONFIG_H_ */