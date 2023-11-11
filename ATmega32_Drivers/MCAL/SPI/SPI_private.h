/*
 * SPI_private.h
 *
 * Created: 10/30/2023 12:10:54 PM
 *  Author: Hassan Said
 */ 


#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPCR *((volatile u8 *)0x2D)
#define SPSR *((volatile u8 *)0x2E)
#define SPDR *((volatile u8 *)0x2F)

// SPCR
#define SPIE 7 // Interrupt Enable
#define SPE  6 // SPI Enable
#define DORD 5 // Data order
#define MSTR 4 // Master or Slave 
#define CPOL 3 // CLK Polarity
#define CPHA 2 // CLK Phase
#define SPR1 1 // Prescaler
#define SPR0 0 // Prescaler

// SPSR
#define SPIF  7 // Interrupt Flag
#define WCOL  6 // Write collision 
#define SPI2X 0 // Double speed mode

// Polarity
#define SPI_CLK_POL_IDLE_HIGH 1
#define SPI_CLK_POL_IDLE_LOW  0

// Phase
#define SPI_CLK_PHASE_SAMPLE_FIRST 0
#define SPI_CLK_PHASE_SETUP_FIRST  1

// Data order
#define SPI_DATA_ORDER_MSB_FIRST 0
#define SPI_DATA_ORDER_LSB_FIRST 1

// Prescaler
#define SPI_PRESCALER_NORAML_4   0
#define SPI_PRESCALER_NORAML_16  1
#define SPI_PRESCALER_NORAML_64  2
#define SPI_PRESCALER_NORAML_128 3

#define SPI_PRESCALER_DOUBLE_2  0
#define SPI_PRESCALER_DOUBLE_8  1
#define SPI_PRESCALER_DOUBLE_32 2
#define SPI_PRESCALER_DOUBLE_64 3

// Speed
#define SPI_SPEED_MODE_NORMAL 0
#define SPI_SPEED_MODE_DOUBLE 1

// Prescaler mask
#define SPI_PRESCALER_MASK 0b11111100


#endif /* SPI_PRIVATE_H_ */