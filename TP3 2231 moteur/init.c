

#include "msp430g2231.h"
#include "init.h"

//------------------------------------------------------------------------------
// InitPort : Called at the start of the main program. Initialize port
// IN:		  none.
// OUT:	  	  none.
// return:    none.
//------------------------------------------------------------------------------
void InitPort(void){
	  P1OUT = 0x00;                        			// Init ouput to null
	  P1DIR = BIT0;                        			// P1.0 output
	  P1DIR &= ~(BIT1 + BIT3 + BIT5 + BIT7);		// P1.1, P1.3, P1.5, P1.7 inputs
	  P1SEL |= BIT5 + BIT6 + BIT7;					// P1.5, P1.6, P1.7 sel
	  P1DIR |= BIT6;								// P1.6 output
}
