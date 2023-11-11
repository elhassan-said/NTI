/*
 * WATCHDOG_private.h
 *
 * Created: 11/5/2023 10:11:16 AM
 *  Author: Hassan Said
 */ 


#ifndef WATCHDOG_PRIVATE_H_
#define WATCHDOG_PRIVATE_H_

#define WDTCR_ 	(*((volatile u8 *)0x41))

#define WDP_16K   0
#define WDP_32K   1
#define WDP_64K   2
#define WDP_128K  3
#define WDP_256K  4
#define WDP_512K  5
#define WDP_1024K 6
#define WDP_2048K 7  

#define WDP0  0
#define WDP1  1
#define WDP2  2
#define WDE   3
#define WDTOE 4


#endif /* WATCHDOG_PRIVATE_H_ */