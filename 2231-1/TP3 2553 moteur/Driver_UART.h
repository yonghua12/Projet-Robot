//--------------------------------------------------------------------------------------------
// DriverUART.h:	  Contains prototype of DriverUART functions.
//--------------------------------------------------------------------------------------------
#ifndef INIT_HEADER_UART
#define INIT_HEADER_UART

//--------------------------------------------------------------------------------------------
// Init_UART : 		  shall be call at the launch of the program. Initialize pin of the
//            		  microC.
// IN/OUT:	  		  none.
// return:    		  none.
//--------------------------------------------------------------------------------------------
void Init_UART(void);

//--------------------------------------------------------------------------------------------
// UART_TXdata: 	  [UART function] shall be call for puTTY use. TXdata is for send
//			  		  character in the buffer (which is send to the UART port).
// IN:	  	  		  - 'c': character to send in the buffer (receive by puTTY).
// OUT:		  		  none.
// return:   		  none.
//--------------------------------------------------------------------------------------------
void UART_TXdata(unsigned char c);

//--------------------------------------------------------------------------------------------
// UART_RXdata: 	  [UART function] shall be call for puTTY use. RXdata is for receive
//			  		  character from the buffer (which was received to the UART port).
// IN:	  	  		  none.
// OUT:		  		  none.
// return:    		  'UCA0RXBUF': buffer which contains the character to receive.
//--------------------------------------------------------------------------------------------
unsigned char UART_RXdata();

#endif
