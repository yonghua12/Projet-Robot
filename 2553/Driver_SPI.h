/*------------------------------------------------------------------------------*/
/* Description: 		Driver_SPI.h contains functions managing SPI            */
/*------------------------------------------------------------------------------*/

#ifndef DRIVER_SPI_HEADER
#define DRIVER_SPI_HEADER

#include <msp430.h>
#include <string.h>

void Init_SPI(void) ;
void TX_SPI(unsigned char c);
unsigned int RX_SPI(void);
void Send_char_SPI(unsigned char carac);



#endif /* DRIVER_SPI_H_ */
