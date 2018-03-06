
#include "msp430g2231.h"

#include "Driver_SPI.h"
#include "Driver_Motor_IR.h"
#include "init.h"

//------------------------------------------------------------------------------
// main: 	call each init functions and wait for ever.
//------------------------------------------------------------------------------
int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;             // Stop watchdog timer

  InitPort();							// Initialize Ports
  SPI_Init();							// Initialize SPI connection
  Motor_IR_Init();						// Set pwm for ir motor

  //_BIS_SR(LPM0_bits + GIE);   		// Enter LPM0 w/ interrupt

  do{
	  TACCR1 = Motor_Set_Deg(45);
  }while(1);
}

//------------------------------------------------------------------------------
// USI_VECTOR: 	interruption when SPI buffer is updated
//------------------------------------------------------------------------------
#pragma vector=USI_VECTOR
__interrupt void universal_serial_interface(void)
{
	SPI_Receive_Data();

	// send check begin
	SPI_Send_Data('C');

	// check begin
	if(SPI_Receive_Data()=='c'){
	TACCR1 = Motor_Set_Deg(0); // set to 0 deg
	__delay_cycles(TIME_TO_CHECK);
	TACCR1 = Motor_Set_Deg(45);  // set to 45 deg
	__delay_cycles(TIME_TO_CHECK);
	TACCR1 = Motor_Set_Deg(90);
	__delay_cycles(TIME_TO_CHECK);
	TACCR1 = Motor_Set_Deg(135); // set to 135 deg
	__delay_cycles(TIME_TO_CHECK);
	TACCR1 = Motor_Set_Deg(180); // set to 180 deg
	__delay_cycles(TIME_TO_CHECK);
	}

	USICNT = 8;                    // re-load counter
}

