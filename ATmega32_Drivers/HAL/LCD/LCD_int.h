/*
 * LCD_int.h
 *
 * Created: 11/8/2023 10:18:09 AM
 *  Author: Hassan Said
 */ 


#ifndef LCD_INT_H_
#define LCD_INT_H_


void H_LCD_Void_LCDInit(void);
void H_LCD_Void_LCDWriteCharacter(u8);
void H_LCD_Void_LCDWriteCommand(u8);
void H_LCD_Void_LCDWriteString(u8*);
void H_LCD_Void_LCDWriteNumber(s32);
void H_LCD_Void_LCDGoTo(u8,u8);
void H_LCD_Void_LCDClear(void);


#endif /* LCD_INT_H_ */