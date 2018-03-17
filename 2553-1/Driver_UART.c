/*
 * Driver_UART.c
 *
 *  Created on: 16 mars 2018
 *      Author: y.xie.13
 */
#include <msp430.h>
#include <string.h>
#include "Driver_SPI.h"
#include "robot.h"
#include "Driver_UART.h"

/*
 * Definitions
 */
#define RELEASE "\r\t\tSPI-rIII132018"
#define PROMPT  "\r\nmaster>"
#define CMDLEN  10

#define TRUE    1
#define FALSE   0

#define LF      0x0A            // line feed or \n#define CR      0x0D            // carriage return or \r#define BSPC    0x08            // back space#define DEL     0x7F            // SUPRESS#define ESC     0x1B            // escape
#define _CS         BIT4            // chip select for SPI Master->Slave ONLY on 4 wires Mode#define SCK         BIT5            // Serial Clock#define DATA_OUT    BIT6            // DATA out#define DATA_IN     BIT7            // DATA in#define LED         BIT0            // Red LED on Launchpad
int auto_mode = 1;
/*
 * Variables globales
 */
// static const char spi_in = 0x37;
unsigned char cmd[CMDLEN];      // tableau de caracteres lie a la commande user

/* ----------------------------------------------------------------------------
 * Fonction d'initialisation de l'UART
 * Entree : -
 * Sorties: -
 */
void init_UART(void) {
	P1SEL |= (BIT1 | BIT2);                    // P1.1 = RXD, P1.2=TXD
	P1SEL2 |= (BIT1 | BIT2);                    // P1.1 = RXD, P1.2=TXD
	UCA0CTL1 |= UCSWRST;                        // SOFTWARE RESET
	UCA0CTL1 |= UCSSEL_2;                       // SMCLK (2 - 3)
	UCA0BR0 = 104;                     // 1MHz, OSC16, 9600 (8Mhz : 52) : 8/115k
	UCA0BR1 = 0;                                // 1MHz, OSC16, 9600
	UCA0MCTL = 10;
	UCA0CTL0 &= ~(UCPEN | UCMSB | UCDORM);
	UCA0CTL0 &= ~(UC7BIT | UCSPB | UCMODE_3 | UCSYNC); // dta:8 stop:1 usci_mode3uartmode
	UCA0CTL1 &= ~UCSWRST;                   // **Initialize USCI state machine**
	/* Enable USCI_A0 RX interrupt */
	IE2 |= UCA0RXIE;
}

/* ----------------------------------------------------------------------------
 * Fonction d'emission d'une chaine de caracteres
 * Entree : pointeur sur chaine de caracteres
 * Sorties:  -
 */
void envoi_msg_UART(unsigned char *msg) {
	unsigned int i = 0;
	for (i = 0; msg[i] != 0x00; i++) {
		while (!(IFG2 & UCA0TXIFG))
			; //attente de fin du dernier envoi (UCA0TXIFG ?1 quand UCA0TXBUF vide)
		UCA0TXBUF = msg[i];
	}
}

/* ----------------------------------------------------------------------------
 * Fonction d'interpretation des commandes utilisateur
 * Entrees: -
 * Sorties:  -
 */
void interpreteur(void) {
	if (strcmp((const char *) cmd, "h") == 0) //----------------------------------- help
			{
		envoi_msg_UART("\r\nCommandes :");
		envoi_msg_UART("\r\n'ver' : version");
		envoi_msg_UART("\r\n'0' : démarrer moteur infra");
		envoi_msg_UART("\r\n'1' : arrêter moteur infra");
		envoi_msg_UART("\r\n'2' : robot start");
		envoi_msg_UART("\r\n'3' : robot stop");
		envoi_msg_UART("\r\n'4' : robot turn right");
		envoi_msg_UART("\r\n'5' : robot turn left");
		envoi_msg_UART("\r\n'9' : SPI Init.");
		envoi_msg_UART("\r\n'a' : change mode\r\n");
		envoi_msg_UART("\r\n'h' : help\r\n");
	} else if (strcmp((const char *) cmd, "0") == 0) {
		envoi_msg_UART("\r\n");
		envoi_msg_UART((unsigned char *) cmd);
		envoi_msg_UART("->");
		Send_char_SPI(0x30); // Send '0' over SPI to Slave
		envoi_msg_UART("\r\n");
	} else if (strcmp((const char *) cmd, "1") == 0) {
		envoi_msg_UART("\r\n");
		envoi_msg_UART((unsigned char *) cmd);
		envoi_msg_UART("->");
		Send_char_SPI(0x31); // Send '1' over SPI to Slave
		envoi_msg_UART("\r\n");
	} else if (strcmp((const char *) cmd, "2") == 0) {
		envoi_msg_UART("\r\n");
		Motor_Start(1);
		envoi_msg_UART("\r\n");
	} else if (strcmp((const char *) cmd, "3") == 0) {
		envoi_msg_UART("\r\n");
		Motor_Slow_Stop(0);
		envoi_msg_UART("\r\n");
	} else if (strcmp((const char *) cmd, "4") == 0) {
		envoi_msg_UART("\r\nRight");
		Motor_Turn(DIRECTION_RIGHT, 0);
		envoi_msg_UART("\r\n");
	} else if (strcmp((const char *) cmd, "5") == 0) {
		envoi_msg_UART("\r\nLeft");
		Motor_Turn(DIRECTION_LEFT, 0);
		envoi_msg_UART("\r\n");
	} else if (strcmp((const char *) cmd, "9") == 0) {
		Init_SPI();
		envoi_msg_UART("\r\nSPI set !");
	} else if (strcmp((const char *) cmd, "ver") == 0) {
		envoi_msg_UART("\r\n");
		envoi_msg_UART(RELEASE);
		envoi_msg_UART("\r\n");
	} else if (strcmp((const char *) cmd, "a") == 0) {
		if (auto_mode == 0) {
			envoi_msg_UART("Auto mode activated%s");
			auto_mode = 1;
		} else {
			envoi_msg_UART("Auto mode desactivated%s");
			auto_mode = 0;
		}
	} else                         //---------------------------- default choice
	{
		envoi_msg_UART("\r\n ?");
		envoi_msg_UART((unsigned char *) cmd);
	}
	envoi_msg_UART(PROMPT);        //---------------------------- command prompt
}
