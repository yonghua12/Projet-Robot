/*
 * Driver_SPI.h
 *
 *  Created on: 16 mars 2018
 *      Author: y.xie.13
 */

#ifndef DRIVER_SPI_H_
#define DRIVER_SPI_H_

#include <msp430.h>
#include <string.h>

void Init_SPI(void) ;
void TX_SPI(unsigned char c);
unsigned char RX_SPI(void);
void Send_char_SPI(unsigned char carac);



#endif /* DRIVER_SPI_H_ */
