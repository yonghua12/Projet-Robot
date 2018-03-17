//--------------------------------------------------------------------------------------------
// DriverGPIO.h:	  Contains prototype of DriverGPIO functions.
//--------------------------------------------------------------------------------------------
#ifndef IO_HEADER_GPIO
#define IO_HEADER_GPIO
#include "const.h"
#include "Driver_SPI.h"
#include "Driver_UART.h"

//--------------------------------------------------------------------------------------------
// SendString: 		  shall be call for send array of character to puTTY (and puTTY only)
// IN:	  	  		  - 'size': size of the string to send.
//					  - 'pstr': pointer on the string to send.
// OUT:		  		  none.
// return:    		  none.
//--------------------------------------------------------------------------------------------
void SendString(int size, char * pstr);

//--------------------------------------------------------------------------------------------
// ReadUART: 			shall be call for read the character send by puTTY / Bluetooth
// IN:	  	  			none.
// OUT:		  			none.
// return:    			Character read in UART buffer.
//--------------------------------------------------------------------------------------------
unsigned char ReadUART();

//--------------------------------------------------------------------------------------------
// sendAlphabet: 	  shall be call for send alphabet from MASTER to SLAVE.
//					  After each send of character, wait for the response.
// IN:	  	  		  none.
// OUT:		 		  none.
// return:    		  none.
//--------------------------------------------------------------------------------------------
void sendAlphabet(void);

//--------------------------------------------------------------------------------------------
// showHelp: 		  shall be call when user (puTTY) ask for help (h)
// IN:	  	  		  none.
// OUT:		 		  none.
// return:    		  none.
//--------------------------------------------------------------------------------------------
void showHelp(void);

//--------------------------------------------------------------------------------------------
// chipSelect: 		  Put 0 to the selected chip
// IN:	  	  		  none.
// OUT:		 		  none.
// return:    		  none.
//--------------------------------------------------------------------------------------------
void chipSelect(void);

//--------------------------------------------------------------------------------------------
// chipUnselect: 	  Put 1 to the selected chip
// IN:	  	  		  none.
// OUT:		 		  none.
// return:    		  none.
//--------------------------------------------------------------------------------------------
void chipUnselect(void);

//--------------------------------------------------------------------------------------------
// listeningSPI: 	  shall be call when SLAVE is responding to MASTER
// IN:	  	  		  none.
// OUT:		 		  unsigned char.
// return:    		  value read.
//--------------------------------------------------------------------------------------------
unsigned char listening_SPI();

//--------------------------------------------------------------------------------------------
// sendCharNULL_SPI: 	shall be call for update buffer
// IN:	  	  			- 'param_char': character to send.
// OUT:		 			none.
// return:    			none.
//--------------------------------------------------------------------------------------------
void sendCharNULL_SPI(void);

//--------------------------------------------------------------------------------------------
// sendCharSPI: 	  shall be call for send alphabet from MASTER to SLAVE.
//					  After send character, wait for the response.
// IN:	  	  		  - 'param_char': character to send.
// OUT:		 		  none.
// return:    		  none.
//--------------------------------------------------------------------------------------------
void sendChar_SPI(char param_char);

#endif
