//--------------------------------------------------------------------------------------------
//  DriverGPIO.c:	   Contains functions managing Inputs and Outputs of the microC.
//					   Calls other drivers. (Interface between user and hardware)
//--------------------------------------------------------------------------------------------
#include "Driver_GPIO.h"

#include <msp430g2553.h>
#include <stdio.h>
#include <string.h>

//--------------------------------------------------------------------------------------------
// SendString: 			shall be call for send array of character to puTTY / Bluetooth
// IN:	  	  			- 'size': size of the string to send.
//						- 'pstr': pointer on the string to send.
// OUT:		  			none.
// return:    			none.
//--------------------------------------------------------------------------------------------
void SendString(int size, char * pstr)
{
	int i;

	for(i=0; i<size; i++)              					//For each element of the string.
	{
		UART_TXdata((unsigned char)pstr[i]);			//Send the current character.
	}
}

//--------------------------------------------------------------------------------------------
// ReadUART: 			shall be call for read the character send by puTTY / Bluetooth
// IN:	  	  			none.
// OUT:		  			none.
// return:    			Character read in UART buffer.
//--------------------------------------------------------------------------------------------
unsigned char ReadUART()
{
	return UART_RXdata();
}


//--------------------------------------------------------------------------------------------
// sendAlphabet: 		shall be call for send alphabet from MASTER to SLAVE.
//						After each send of character, wait for the response.
// IN:	  	  			none.
// OUT:		 			none.
// return:    			none.
//--------------------------------------------------------------------------------------------
void sendAlphabet(void)
{
	char l;
	// For each alphabet char
	for(l = 'a'; l<='z'; ++l)
	{
		// Sending character
		sendChar_SPI(l);
		// Receiving
		listening_SPI(); 	//todo: shall threat response. If not equivalent of sending character, shall failed.
	}
}

//--------------------------------------------------------------------------------------------
// sendChar_SPI: 		shall be call for send alphabet from MASTER to SLAVE.
//						After send character, wait for the response.
// IN:	  	  			- 'param_char': character to send.
// OUT:		 			none.
// return:    			none.
//--------------------------------------------------------------------------------------------
void sendChar_SPI(char param_char)
{
	SPI_TX((unsigned char)param_char);		//Send to SLAVE the actual character.
	sendCharNULL_SPI();
}

//--------------------------------------------------------------------------------------------
// sendCharNULL_SPI: 	shall be call for update buffer
// IN:	  	  			- 'param_char': character to send.
// OUT:		 			none.
// return:    			none.
//--------------------------------------------------------------------------------------------
void sendCharNULL_SPI(void)
{
	//Sending
	SPI_TX((unsigned char)0x00);		//Send to SLAVE NULL value
}

//--------------------------------------------------------------------------------------------
// listeningSPI: 		shall be call when SLAVE is responding to MASTER
// IN:	  	  			none.
// OUT:		 			none.
// return:    			none.
//--------------------------------------------------------------------------------------------
unsigned char listening_SPI()
{
	//char str[30];
	unsigned char result;

	// get result
	SPI_RX();
	result = SPI_RX();									//receiving from SLAVE
	return result;
}

//--------------------------------------------------------------------------------------------
// showHelp: 			shall be call when user (puTTY) ask for help (h)
// IN:	  	  			none.
// OUT:		 			none.
// return:    			none.
//--------------------------------------------------------------------------------------------
void showHelp(void)
{
	char str[100];
	sprintf(str, "s%sEnvoyer caractère en SPI%s", TAB_WINDOWS, EOL_WINDOWS);
	SendString( strlen(str), str);
	sprintf(str, "h%sAfficher la liste des commandes%sh", TAB_WINDOWS, EOL_WINDOWS);
	SendString( strlen(str), str);
	sprintf(str, "l%sListen SPI%s", TAB_WINDOWS, EOL_WINDOWS);
	SendString( strlen(str), str);
}

//--------------------------------------------------------------------------------------------
// chipSelect: 			Put 0 to the selected chip
// IN:	  	  			none.
// OUT:		 			none.
// return:    			none.
//--------------------------------------------------------------------------------------------
void chipSelect(void)
{
	P1OUT &= ~BIT4; //CS select
}

//--------------------------------------------------------------------------------------------
// chipUnselect: 		Put 1 to the selected chip
// IN:	  	  			none.
// OUT:		 			none.
// return:    			none.
//--------------------------------------------------------------------------------------------
void chipUnselect(void)
{
	P1OUT |= BIT4; //CS unselect
}

