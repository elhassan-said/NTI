/*
 * WARCHDOG_int.h
 *
 * Created: 11/5/2023 10:09:25 AM
 *  Author: Hassan Said
 */ 


#ifndef WARCHDOG_INT_H_
#define WARCHDOG_INT_H_

#define WDP_MASK_16K   0b00000000
#define WDP_MASK_32K   0b00000001
#define WDP_MASK_64K   0b00000010
#define WDP_MASK_128K  0b00000011
#define WDP_MASK_256K  0b00000100
#define WDP_MASK_512K  0b00000101
#define WDP_MASK_1024K 0b00000110
#define WDP_MASK_2048K 0b00000111


void WDT_voidEnable(void);
void WDT_voidDisable(void);
void WDT_voidSleep(u8 sleepTime);
void WDT_voidKick(void);



#endif /* WARCHDOG_INT_H_ */