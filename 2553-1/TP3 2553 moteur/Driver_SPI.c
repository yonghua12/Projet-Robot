//--------------------------------------------------------------------------------------------
// DriverUART.c:	  Contains all functions for SPI utilisation. (Hardware)
//--------------------------------------------------------------------------------------------
#include "Driver_SPI.h"

#include <msp430g2553.h>

//--------------------------------------------------------------------------------------------
// Init_SPI :  		  shall be call at the launch of the program. Initialize parameters
//			  		  for SPI communication.
// IN/OUT:	  		  none.
// return:    		  none.
//--------------------------------------------------------------------------------------------
void Init_SPI(void)
{
	P1DIR |= BIT4;
	P1OUT |= BIT4;
	P1SEL |= (BIT5 + BIT6 + BIT7);                 	// P1.1 = RXD, P1.2=TXD
	P1SEL2 |= (BIT5 + BIT6 + BIT7);                	// P1.1 = RXD, P1.2=TXD

	UCB0CTL1 |= UCSSEL_2;
	UCB0BR0 = 104;                          		// 1MHz, 9600
	UCB0BR1 = 0;                            		// 1MHz, 9600

	UCB0CTL0 = 0 | (UCMSB | UCMST);
	//UCA0CTL0 |= (UCCKPH | UCSYNC); 				//lichong
	UCB0CTL1 &= ~UCSWRST;                   		// **Initialize USCI state machine**
}

//--------------------------------------------------------------------------------------------
// SPI_TX: 	  		  [SPI function] shall be call for send character from MASTER to SLAVE
// IN:	  	  		  - 'c': character to send in the buffer (receive by SLAVE).
// OUT:		  		  none.
// return:   		  none.
//--------------------------------------------------------------------------------------------
void SPI_TX(unsigned char c)
{
	while (!(IFG2 & UCB0TXIFG));  					// USCI_A0 TX buffer ready? --wait flag
	UCB0TXBUF = c;              					// TX -> RXed character
	__delay_cycles(50);								//Wait for slave (keep up);
}

//--------------------------------------------------------------------------------------------
// SPI_RX: 	  		  [SPI function] shall be call for receive character from SLAVE
// IN:	  	  		  none.
// OUT:		  		  none.
// return:    		  'UCA0RXBUF': buffer which contains the character to receive.
//--------------------------------------------------------------------------------------------
unsigned char SPI_RX()
{
	while(!(IFG2 & UCB0RXIFG)); 					//receptionUSCI_A0 ? --wait flag
	return UCB0RXBUF;
}
