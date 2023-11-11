/*
 * EXTINT_config.h
 *
 * Created: 11/2/2023 7:58:56 AM
 *  Author: Hassan Said
 */ 


#ifndef EXTINT_CONFIG_H_
#define EXTINT_CONFIG_H_

/*
 * EXTINT0_SENSE_CONTROL OPTIONS :
 *                                      1 - EXT_INT_FALLING_EDGE
 *                                      2 - EXT_INT_RISING_EDGE
 *                                      3 - EXT_INT_LOW_LEVEL
 *                                      4 - EXT_INT_ANY_LOGICAL_CHANGE
 */
#define EXTINT0_SENSE_CONTROL EXT_INT_FALLING_EDGE

/*
 * EXTINT1_SENSE_CONTROL OPTIONS :
 *                                      1 - EXT_INT_FALLING_EDGE
 *                                      2 - EXT_INT_RISING_EDGE
 *                                      3 - EXT_INT_LOW_LEVEL
 *                                      4 - EXT_INT_ANY_LOGICAL_CHANGE
 */
#define EXTINT1_SENSE_CONTROL EXT_INT_RISING_EDGE

/*
 * EXTINT2_SENSE_CONTROL OPTIONS :
 *                                      1 - EXT_INT_FALLING_EDGE
 *                                      2 - EXT_INT_RISING_EDGE
 */
#define EXTINT2_SENSE_CONTROL EXT_INT_RISING_EDGE




#endif /* EXTINT_CONFIG_H_ */