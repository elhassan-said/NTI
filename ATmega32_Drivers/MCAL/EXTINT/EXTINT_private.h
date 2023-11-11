/*
 * EXTINT_private.h
 *
 * Created: 11/2/2023 8:06:48 AM
 *  Author: Hassan Said
 */ 


#ifndef EXTINT_PRIVATE_H_
#define EXTINT_PRIVATE_H_


#define MCUCR_REG  *((volatile u8 *)0x55)
#define GICR_REG   *((volatile u8 *)0x5B)
#define MCUCSR_REG *((volatile u8 *)0x54)


#define EXT_INT_FALLING_EDGE            1
#define EXT_INT_RISING_EDGE             2
#define EXT_INT_LOW_LEVEL               3
#define EXT_INT_ANY_LOGICAL_CHANGE      4


#define ISC2_BIT 6


#define ISC11_BIT 3
#define ISC10_BIT 2
#define ISC01_BIT 1
#define ISC00_BIT 0


#define INT1_BIT 7
#define INT0_BIT 6
#define INT2_BIT 5


#define EXT_INT_FALLING_EDGE       1
#define EXT_INT_RISING_EDGE        2
#define EXT_INT_LOW_LEVEL          3
#define EXT_INT_ANY_LOGICAL_CHANGE 4


#endif /* EXTINT_PRIVATE_H_ */