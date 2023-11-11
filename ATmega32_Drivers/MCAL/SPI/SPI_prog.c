/*
 * SPI_prog.c
 *
 * Created: 10/30/2023 1:46:37 PM
 *  Author: Hassan Said
 */ 

#define F_CPU 16000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_config.h"
#include "SPI_private.h"
#include "SPI_Int.h"

void M_SPI_voidMasterInit(void)
{
	// Enable SPI and master mode
	SPCR = (1 << SPE) | (1 << MSTR);
	// Data order
	#if(SPI_DATA_ORDER == SPI_DATA_ORDER_LSB_FIRST)
		SET_BIT(SPCR, DORD);
	#else
		CLR_BIT(SPCR, DORD);
	#endif
	
	// CLK Polarity
	#if(SPI_CLK_POL == SPI_CLK_POL_IDLE_LOW)
		CLR_BIT(SPCR, CPOL);
	#else
		SET_BIT(SPCR, CPOL);
	#endif
	
	// CLK Phase
	#if(SPI_CLK_PHASE == SPI_CLK_PHASE_SAMPLE_FIRST)
		CLR_BIT(SPCR, CPHA);
	#else
		SET_BIT(SPCR, CPHA);
	#endif
	
	// Speed mode
	#if(SPI_SPEED_MODE == SPI_SPEED_MODE_NORMAL)
		CLR_BIT(SPSR, SPI2X);
	#else
		SET_BIT(SPSR, SPI2X);
	#endif
	
	// Prescaler
	SPCR &= SPI_PRESCALER_MASK;
	SPCR |= SPI_PRESCALER;
}
void M_SPI_voidSlaveInit(void)
{
	// Enable SPI and slave mode
	SPCR = (1 << SPE);
	CLR_BIT(SPCR, MSTR);
	// Data order
	#if(SPI_DATA_ORDER == SPI_DATA_ORDER_LSB_FIRST)
	SET_BIT(SPCR, DORD);
	#else
	CLR_BIT(SPCR, DORD);
	#endif
	
	// CLK Polarity
	#if(SPI_CLK_POL == SPI_CLK_POL_IDLE_LOW)
	CLR_BIT(SPCR, CPOL);
	#else
	SET_BIT(SPCR, CPOL);
	#endif
	
	// CLK Phase
	#if(SPI_CLK_PHASE == SPI_CLK_PHASE_SAMPLE_FIRST)
	CLR_BIT(SPCR, CPHA);
	#else
	SET_BIT(SPCR, CPHA);
	#endif
}
u8 M_SPI_u8TransferByte(u8 copy_u8data)
{
	SPDR = copy_u8data;
	while(GET_BIT(SPSR, SPIF) == 0); // Stuck here until data is transfered
	return SPDR; // Return data received
}