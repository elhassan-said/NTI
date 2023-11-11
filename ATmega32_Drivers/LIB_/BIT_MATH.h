/*
 * BIT_MATH.h
 *
 * Created: 10/18/2023 11:36:17 AM
 *  Author: Hassan Said
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(VAR, BIT) (VAR |= (1 << (BIT)))
#define CLR_BIT(VAR, BIT) (VAR &= ~(1 << (BIT)))
#define TOG_BIT(VAR, BIT) (VAR ^= (1 << (BIT)))
#define GET_BIT(VAR, BIT) (((VAR) >> (BIT)) & 0x01)

#endif /* BIT_MATH_H_ */