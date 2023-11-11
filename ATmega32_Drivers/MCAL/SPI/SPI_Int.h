/*
 * SPI_Int.h
 *
 * Created: 10/30/2023 1:41:54 PM
 *  Author: Hassan Said
 */ 


#ifndef SPI_INT_H_
#define SPI_INT_H_

void M_SPI_voidMasterInit(void);
void M_SPI_voidSlaveInit(void);
u8 M_SPI_u8TransferByte(u8 copy_u8data);


#endif /* SPI_INT_H_ */