/*
 * TIMER1_int.h
 *
 * Created: 10/29/2023 11:04:49 AM
 *  Author: Hassan Said
 */ 


#ifndef TIMER1_INT_H_
#define TIMER1_INT_H_

#define TIMER1_ICU_RISING_EDGE_TRIGGER    1
#define TIMER1_ICU_FALLING_EDGE_TRIGGER   0

void M_TIMER1_void_Init(void);
void M_TIMER1_ICU_void_Init(void);
void M_TIMER1_ICU_void_EnableInt(void);
void M_TIMER1_ICU_void_DisableInt(void);
void M_TIMER1_ICU_void_setCallBack(void (*ptrCallBack)(void));
u16  M_TIMER1_ICU_u16InputCaptureReading(void);
void M_TIMER1_ICU_voidsetTrigger(u8 copy_u8Trigger);



#endif /* TIMER1_INT_H_ */