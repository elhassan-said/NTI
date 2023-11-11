/*
 * TIMER0_int.h
 *
 * Created: 10/24/2023 9:26:02 AM
 *  Author: Hassan Said
 */ 


#ifndef TIMER0_INT_H_
#define TIMER0_INT_H_

#define TIMER0_OVF_INT_ID 0
#define TIMER0_OCM_INT_ID 1

void M_TIMER0_voidInit(void);
void M_TIMER0_voidSetTime(u32 copy_u32Delay);
void M_TIMER0_voidTimerStart(void);
void M_TIMER0_voidTimerStop(void);
void M_TIMER0_voidSetCallBack(void(*ptrCallBack)(void), u8 copy_u8IntID);
void M_TIMER0_voidEnableInt(u8 copy_u8IntID);
void M_TIMER0_voidDisableInt(u8 copy_u8IntID);
void M_TIMER0_voidSetFastPWM(u8 copy_u8DutyCycle);


#endif /* TIMER0_INT_H_ */
