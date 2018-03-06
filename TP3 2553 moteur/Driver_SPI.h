//--------------------------------------------------------------------------------------------
// DriverSPI.h:	  Contains prototype of DriverSPI functions.
//--------------------------------------------------------------------------------------------
#ifndef INIT_HEADER_SPI
#define INIT_HEADER_SPI

//--------------------------------------------------------------------------------------------
// Init_SPI :  	  Shall be call at the launch of the program. Initialize parameters
//			  	  for SPI communication.
// IN/OUT:	  	  none.
// return:    	  none.
//--------------------------------------------------------------------------------------------
void Init_SPI(void);

//--------------------------------------------------------------------------------------------
// SPI_TX: 	  	  [SPI function] shall be call for send character from MASTER to SLAVE
// IN:	  	 	  - 'c': character to send in the buffer (receive by SLAVE).
// OUT:		  	  none.
// return:    	  none.
//--------------------------------------------------------------------------------------------
void SPI_TX(unsigned char c);

//--------------------------------------------------------------------------------------------
// SPI_RX: 	  	  [SPI function] shall be call for receive character from SLAVE
// IN:	  	  	  none.
// OUT:		  	  none.
// return:        'UCA0RXBUF': buffer which contains the character to receive.
//--------------------------------------------------------------------------------------------
unsigned char SPI_RX();

#endif
