/*
 * Driver_SPI.c
 *
 *  Created on: 16 mars 2018
 *      Author: y.xie.13
 */
#include <msp430.h>
#include <string.h>
#include "Driver_SPI.h"

void Init_SPI(void) {
	P1DIR |= BIT4;
	P1OUT |= BIT4;
	P1SEL |= (BIT5 + BIT6 + BIT7);                 	// P1.1 = RXD, P1.2=TXD
	P1SEL2 |= (BIT5 + BIT6 + BIT7);                	// P1.1 = RXD, P1.2=TXD

	UCB0CTL1 |= UCSSEL_2;
	UCB0BR0 = 104;                          		// 1MHz, 9600
	UCB0BR1 = 0;                            		// 1MHz, 9600

	UCB0CTL0 = 0 | (UCMSB | UCMST);
	UCB0CTL0 |= (UCCKPH | UCSYNC); 				//lichong
	UCB0CTL1 &= ~UCSWRST;                          // Enable USCI0 RX interrupt
	//IFG2&=~UCB0TXIFG;
}

void TX_SPI(unsigned char c) {
	while (!(IFG2 & UCB0TXIFG))
		;  					// USCI_A0 TX buffer ready? --wait flag
	UCB0TXBUF = c;              					// TX -> RXed character
	__delay_cycles(50);								//Wait for slave (keep up);
}

unsigned char RX_SPI(void) {
	while (!(IFG2 & UCB0RXIFG))
		; 					//receptionUSCI_A0 ? --wait flag
	return UCB0RXBUF;
}

void Send_char_SPI(unsigned char carac) {
	while ((UCB0STAT & UCBUSY))
		;   // attend que USCI_SPI soit dispo.
	UCB0TXBUF = carac;              // Put caracter in transmit buffer
	while (!(IFG2 & UCA0TXIFG))
		;
	UCA0TXBUF = UCB0RXBUF;          // ECHO LOCAL
}



