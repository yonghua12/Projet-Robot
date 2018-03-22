//--------------------------------------------------------------------------------------------
// Authors:				XIE Yonghua / LUO Jingsi
//
// Date of creation: 	21/03/2018
//
// Version: 			1.3
//--------------------------------------------------------------------------------------------
#include <msp430.h>
#include <string.h>
#include "robot.h"
#include "Driver_Motor.h"
#include "Driver_SPI.h"
#include "Driver_UART.h"
#include "Scan_IR.h"

/*
 * Definitions
 */
#define RELEASE "\r\t\tSPI-rIII132018"
#define PROMPT  "\r\nmaster>"
#define CMDLEN  10

#define TRUE    1
#define FALSE   0

#define LF      0x0A            /* line feed or \n*/
#define CR      0x0D            /* carriage return or \r*/
#define BSPC    0x08            /* back space*/
#define DEL     0x7F            /* SUPRESS*/
#define ESC     0x1B            /* escape*/

#define SCK         BIT5            /* Serial Clock*/
#define DATA_OUT    BIT6            /* DATA out*/
#define DATA_IN     BIT7            /* DATA in*/
#define LED         BIT0            /* Red LED on Launchpad*/

void init_BOARD(void);
void init_UART(void);
void Init_SPI(void);
void interpreteur(void);
void envoi_msg_UART(char *msg);
void Send_char_SPI(unsigned char carac);
void mode(void);

int a, i;

/*
 * Variables globales
 */

signed char cmd[CMDLEN];      /* tableau de caracteres lie a la commande user*/
unsigned char car = 0x30;       
signed int nb_car = 0;
unsigned bool intcmd = FALSE;   /* call interpreteur()*/

/* ----------------------------------------------------------------------------
 * Fonction d'initialisation de la carte TI LauchPAD
 * Entrees: -
 * Sorties:  -
 */

void init_BOARD(void) {
	/* Stop watchdog timer to prevent time out reset*/
	WDTCTL = WDTPW | WDTHOLD;

	if ((CALBC1_1MHZ == 0xFF) || (CALDCO_1MHZ == 0xFF)) {
		__bis_SR_register(LPM4_bits);
	} else {
		/* Factory Set.*/
		DCOCTL = 0;
		BCSCTL1 = CALBC1_1MHZ;
		DCOCTL = (0 | CALDCO_1MHZ);
	}

	/*--------------- Secure mode*/
	P1SEL = 0x00;        /* GPIO*/
	P1SEL2 = 0x00;        /* GPIO*/
	P2SEL = 0x00;        /* GPIO*/
	P2SEL2 = 0x00;        /* GPIO*/
	P1DIR = 0x00;         /* IN*/
	P2DIR = 0x00;         /* IN*/

	P1SEL &= ~LED;
	P1SEL2 &= ~LED;
	P1DIR |= LED;  /* reset slave & LED: output*/
	P1OUT &= ~LED;
}

/*--------------------------------------------------------------------------------------------*/
/* chipSelect: 			Put 0 to the selected chip
/* IN:	  	  			none.
/* OUT:		 			none.
/* return:    			none.
/*--------------------------------------------------------------------------------------------*/
void chipSelect(void) {
	P1OUT &= ~BIT4; /*CS select*/
}

/*--------------------------------------------------------------------------------------------*/
/* chipUnselect: 		Put 1 to the selected chip
/* IN:	  	  			none.
/* OUT:		 			none.
/* return:    			none.
/*--------------------------------------------------------------------------------------------*/
void chipUnselect(void) {
	P1OUT |= BIT4; //CS unselect
}

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * main.c
 */
int main(void) {

	int checked[4];
	int auto_mode = 1;
	int correction;
	WDTCTL = WDTPW + WDTHOLD;   			/* Stop WDT*/
	BCSCTL1 = CALBC1_1MHZ;      			/* Set DCO to 1Mhz*/
	DCOCTL = CALDCO_1MHZ;       			/* Set DCO to 1Mhz*/
	P1DIR = BIT0;

	/*init_BOARD();*/
	init_UART();
	Init_SPI();
	Scan_IR_Init();
	Motor_Init();
	ADC_init();
	envoi_msg_UART("\rReady !\r\n"); /* user prompt*/
	while (1) {
		if (intcmd) {
			interpreteur();         /* execute la commande utilisateur*/
			intcmd = FALSE;         /* acquitte la commande en cours*/
		} else {
	/*		__bis_SR_register(LPM4_bits | GIE); // general interrupts enable & Low Power Mode*/
			__bis_SR_register(GIE);
		}
		if (auto_mode == 1) {
			/*if obstacle in front*/
			if (Get_IR() > IR_MAX) {
				Motor_Slow_Stop(0);
				chipSelect();
				Send_char_SPI(0x30);
				chipUnselect();
				/* Get data from scan*/
				Scan_IR_Begin(checked);

				/* Correction*/
				correction = Scan_IR_DoCorrection(checked, Scan_IR_Direction(checked));
			} else {
				Motor_Start(1);
			}
		}

	return 0;
	}
	
}

/* --------------------------- R O U T I N E S   D ' I N T E R R U P T I O N S*/

/* ************************************************************************* */
/* VECTEUR INTERRUPTION USCI RX                                              */
/* ************************************************************************* */
#pragma vector = USCIAB0RX_VECTOR
__interrupt
void USCIAB0RX_ISR(void) {
	/*---------------- UART
	if ((IFG2 & UCA0RXIFG)==0) {
		while ((IFG2 & UCA0RXIFG)!=0){	/* lecture caractère reçu*/
			cmd[nb_car] = UCA0RXBUF; 
		}
			
		while (!(IFG2 & UCA0TXIFG)!=0){	/* attente de fin du dernier envoi (UCA0TXIFG ?1 quand UCA0TXBUF vide) / echo*/
			UCA0TXBUF = cmd[nb_car];
		}
		
		if (cmd[nb_car] == ESC) {
			nb_car = 0;
			cmd[1] = 0x00;
			cmd[0] = CR;
		}

		if ((cmd[nb_car] == CR) || (cmd[nb_car] == LF)) {
			cmd[nb_car] = 0x00;
			intcmd = TRUE;
			nb_car = 0;
			__bic_SR_register_on_exit(LPM4_bits);   /* OP mode !*/
		} else if ((nb_car < CMDLEN)
				&& !((cmd[nb_car] == BSPC) || (cmd[nb_car] == DEL))) {
			nb_car++;
		} else {
			cmd[nb_car] = 0x00;
			nb_car--;
		}
	}
}
/*------------------------------------------------------------------ End ISR*/
