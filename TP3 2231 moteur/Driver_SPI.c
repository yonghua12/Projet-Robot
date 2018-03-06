

#include "Driver_SPI.h"

//------------------------------------------------------------------------------
// SPI_Init :  Called at the start of the main program. Initialize parameters
//			  for SPI communication.
// IN:		  none.
// OUT:	  	  none.
// return:    none.
//------------------------------------------------------------------------------
void SPI_Init(void){
	  USICTL0 |= USISWRST;                 			// start config
	  USICTL0 |= USIPE7 + USIPE6 + USIPE5 + USIOE; 	// Port, SPI slave
	  USICTL1 |= USIIE;                    			// Counter interrupt, flag remains set
	  USICNT = 8;                           		// init-load counter
	  //USICTL1 = USICKPL;                  		// Setup clock polarity --> keep low
	  USICTL1 |= USICKPH;							// Setup phase
	  USICTL0 &= ~USISWRST;                 		// USI released for operation stop config
}

//------------------------------------------------------------------------------
// SPI_Send_Data: Called on sending character from SLAVE to MASTER
// IN:	  	  - 'c': character to write in the buffer (received by MASTER).
// OUT:		  none.
// return:    none.
//------------------------------------------------------------------------------
void SPI_Send_Data(unsigned char carac)
{
	USISRL = 2*carac;						//
	USICNT = 8;							// sizeof char
}

//------------------------------------------------------------------------------
// SPI_Receive_Data: Called when receiving a character from MASTER
// IN:	  	  none.
// OUT:		  none.
// return:    'USISRL': buffer which contains the character received.
//------------------------------------------------------------------------------
unsigned char SPI_Receive_Data(){
	  //while((USICTL1 & USIIFG) != BIT0); // Scrutation
	  return USISRL;
}
