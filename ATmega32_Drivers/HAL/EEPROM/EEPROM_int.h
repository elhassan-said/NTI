/*
 * EEPROM_int.h
 *
 * Created: 11/1/2023 6:11:34 PM
 *  Author: Hassan Said
 */ 


#ifndef EEPROM_INT_H_
#define EEPROM_INT_H_

void H_EEPROM_void_Init(void);
void H_EEPROM_void_writeByte(u16 copy_u16add, u8 copy_u8data);
u8 H_EEPROM_u8_readByte(u16 copy_u16add, u8 *ptr);



#endif /* EEPROM_INT_H_ */