/*
 * TIMER1_private.h
 *
 * Created: 10/29/2023 11:04:20 AM
 *  Author: Hassan Said
 */ 


#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_

#define TCCR1A (*((volatile u8 *)0x4F))  // Control register A
#define TCCR1B (*((volatile u8 *)0x4E))  // Control register B
#define ICR1   (*((volatile u16 *)0x46)) // Input Capture register - ICR1L + ICR1H
#define TIMSK  (*((volatile u8 *)0x59))  // Interrupt Enable
#define TIFR   (*((volatile u8 *)0x58))  // Event flags

// Control register A
#define WGM10  0 // Mode
#define WGM11  1 // Mode

// Control register B
#define CS10   0 
#define CS11   1 
#define CS12   2 
#define WGM12  3 // Mode
#define WGM13  4 // Mode
#define ICES1  6 // Trigger select - When the ICES1 bit is written to zero a falling edge is used as trigger

// TIMSK
#define TICIE1 5 // Input Capture Interrupt Enable



#endif /* TIMER1_PRIVATE_H_ */