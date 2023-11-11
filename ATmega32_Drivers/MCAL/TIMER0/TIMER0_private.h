/*
 * TIMER0_private.h
 *
 * Created: 10/24/2023 9:27:22 AM
 *  Author: Hassan Said
 */ 


#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#define TCCR0 	(*((volatile u8 *)0x53)) // Control
#define TCNT0 	(*((volatile u8 *)0x52)) // Counter
#define OCR0_	(*((volatile u8 *)0x5C)) // Compare match
#define TIMSK	(*((volatile u8 *)0x59)) // Interrupt enable
#define TIFR	(*((volatile u8 *)0x58)) // Event flag


/* Timer/Counter0 Control Register – TCCR0 */
#define CS00  0 // Prescaler
#define CS01  1 // Prescaler
#define CS02  2 // Prescaler
#define WGM01 3 // Timer mode
#define COM00 4 // OC0 Pin mode
#define COM01 5 // OC0 Pin mode
#define WGM00 6 // Timer mode
#define FOC0  7 

/* Timer/Counter Interrupt Mask Register – TIMSK */
#define TOIE0 0
#define OCIE0 1


/* Timer/Counter Interrupt Flag Register – TIFR */
#define TOV0 0
#define OCF0 1

#define TIMER0_MODE_NORMAL            0
#define TIMER0_MODE_CTC               1
#define TIMER0_MODE_FAST_PWM          2
#define TIMER0_MODE_PHASECORRECT_PWM  3

#define TIMER0_TIMER_STOP                    0
#define TIMER0_PRESCALER_1                   1
#define TIMER0_PRESCALER_8                   2
#define TIMER0_PRESCALER_64                  3
#define TIMER0_PRESCALER_256                 4
#define TIMER0_PRESCALER_1024                5
#define TIMER0_PRESCALER_EXT_FALLING_EDGE    6
#define TIMER0_PRESCALER_EXT_RISING_EDGE     7

#define TIMER0_PRESCALER_MASK 0b11111000


#define TIMER0_OC0_MODE_DISCONNECTED 0
#define TIMER0_OC0_MODE_TOG          1
#define TIMER0_OC0_MODE_CLR          2
#define TIMER0_OC0_MODE_SET          3

#define TIMER0_OC0_MODE_PWM_INVERTED     0b00110000
#define TIMER0_OC0_MODE_PWM_NONINVERTED  0b00100000

#define TIMER0_OC0_MASK 0b11001111

#define TIMER0_OC0_SH 4

#endif /* TIMER0_PRIVATE_H_ */
