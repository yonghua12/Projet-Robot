//--------------------------------------------------------------------------------------------
// DriverUART.c:	  Contains all functions for UART utilisation. (Hardware)
//--------------------------------------------------------------------------------------------
#include <msp430g2553.h>
#include "Driver_UART.h"

//--------------------------------------------------------------------------------------------
// Init_UART : 		  shall be call at the launch of the program. Initialize pin of the
//            		  microC.
// IN:	  		  	  none.
// OUT:	  		  	  none.
// return:    		  none.
//--------------------------------------------------------------------------------------------
void Init_UART(void)
{
	P1DIR |= BIT6;								// Led en sortie
    P1SEL |= (BIT1 + BIT2);                 	// P1.1 = RXD, P1.2=TXD
    P1SEL2 |= (BIT1 + BIT2);                	// P1.1 = RXD, P1.2=TXD
    UCA0CTL1 |= UCSSEL_2;                   	// SMCLK
    UCA0BR0 = 104;                          	// 1MHz, 9600
    UCA0BR1 = 0;                            	// 1MHz, 9600
    UCA0CTL0 &= ~UCPEN & ~UCPAR & ~UCMSB;
    UCA0CTL0 &= ~UC7BIT & ~UCSPB & ~UCMODE1;
    UCA0CTL0 &= ~UCMODE0 & ~UCSYNC;
    UCA0CTL1 &= ~UCSWRST;                   	// **Initialize USCI state machine**
    IE2 |= UCA0RXIE;                        	// Enable USCI_A0 RX interrupt
}

//--------------------------------------------------------------------------------------------
// UART_TXdata: 	  [UART function] shall be call for puTTY use. TXdata is for send
//			  		  character in the buffer (which is send to the UART port).
// IN:	  	 		  - 'c': character to send in the buffer (receive by puTTY).
// OUT:		  		  none.
// return:    	  	  none.
//--------------------------------------------------------------------------------------------
void UART_TXdata(unsigned char c)
{
    while (!(IFG2 & UCA0TXIFG));  				// USCI_A0 TX buffer ready? --wait flag
    UCA0TXBUF = c;              				// TX -> RXed character
}

//--------------------------------------------------------------------------------------------
// UART_RXdata: 	  [UART function] shall be call for puTTY use. RXdata is for receive
//			  		  character from the buffer (which was received to the UART port).
// IN:	  	 		  none.
// OUT:		  		  none.
// return:    		  'UCA0RXBUF': buffer which contains the character to receive.
//--------------------------------------------------------------------------------------------
unsigned char UART_RXdata()
{
	while(!(IFG2 & UCA0RXIFG)); 				//receptionUSCI_A0 ? --wait flag
	return UCA0RXBUF;
}
