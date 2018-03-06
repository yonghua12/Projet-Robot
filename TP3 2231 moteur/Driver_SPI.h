//------------------------------------------------------------------------------
// Driver_SPI.h contains prototype of all managing functions for Inputs and Outputs
//------------------------------------------------------------------------------
#ifndef DRIVER_SPI_HEADER
#define DRIVER_SPI_HEADER

#include <msp430g2231.h>

//------------------------------------------------------------------------------
// SPI_Send_Data: Called on sending character from SLAVE to MASTER
// IN:	  	  - 'c': character to write in the buffer (received by MASTER).
// OUT:		  none.
// return:    none.
//------------------------------------------------------------------------------
void SPI_Send_Data(unsigned char carac);

//------------------------------------------------------------------------------
// SPI_Receive_Data: Called when receiving a character from MASTER
// IN:	  	  none.
// OUT:		  none.
// return:    'USISRL': buffer which contains the character received.
//------------------------------------------------------------------------------
unsigned char SPI_Receive_Data();

//------------------------------------------------------------------------------
// SPI_Init :  shall be call at the launch of the program. Initialize parameters
//			  for SPI communication.
// IN/OUT:	  none.
// return:    none.
//------------------------------------------------------------------------------
void SPI_Init(void);

#endif
