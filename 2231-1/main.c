#include <msp430.h> 
#include <intrinsics.h>
#include "Motor.h"

volatile unsigned int RXDta;

void Init_SPI(void){
	  USICTL0 |= USISWRST;                 			// start config
	  USICTL0 |= USIPE7 + USIPE6 + USIPE5 + USIOE; 	// Port, SPI slave
	  USICTL1 |= USIIE;                    			// Counter interrupt, flag remains set
	  USICNT = 8;                           		// init-load counter
	  USICTL1 |= USICKPL;                  		// Setup clock polarity --> keep low
	  USICTL1 |= USICKPH;							// Setup phase
	  USICTL0 &= ~USISWRST;                 		// USI released for operation stop config

}

unsigned char RX_Data(){
	  while((USICTL1 & USIIFG) != BIT0); // Scrutation
	  return USISRL;
}
/*
 * main.c
 */
void main( void )
{
    // Stop watchdog timer to prevent time out reset
    WDTCTL = WDTPW | WDTHOLD;

 if(CALBC1_1MHZ==0xFF || CALDCO_1MHZ==0xFF)
    {
        __bis_SR_register(LPM4_bits);
    }
    else
    {
        // Factory Set.
        DCOCTL = 0;
        BCSCTL1 = CALBC1_1MHZ;
        DCOCTL = (0 | CALDCO_1MHZ);
    }

    //--------------- Secure mode
    P1SEL = 0x00;        // GPIO
    P1DIR = 0x00;         // IN

    // led
    P1DIR |=  BIT0;
    P1OUT &= ~BIT0;
    Init_SPI();
    Init_Motor();
   // Motor_bala();
        __bis_SR_register(LPM4_bits | GIE); // general interrupts enable & Low Power Mode
    }


// --------------------------- R O U T I N E S   D ' I N T E R R U P T I O N S

/* ************************************************************************* */
/* VECTEUR INTERRUPTION USI                                                  */
/* ************************************************************************* */
#pragma vector=USI_VECTOR
__interrupt void USCI0RX_ISR(void)
{
	/*while( !(USICTL1 & USIIFG) );   // waiting char by USI counter flag

	//RX_Data() = USISRL;
	USICNT &= ~USI16B;  // re-load counter
	USISRL = 0x23;
	USICNT = 0x08;      // 8 bits count, that re-enable USI for next transfer
	P1OUT |= BIT0;*/
	if (RX_Data()== 0x30) //if the input buffer is 0x30 (mainly to read the buffer)
	{
		//P1OUT |= BIT0; //turn on LED
		Motor_bala();
	}
	else if (RX_Data()== 0x31)
	{
		//P1OUT &= ~BIT0; //turn off LED
		arret();
	}
}
//------------------------------------------------------------------ End ISR
