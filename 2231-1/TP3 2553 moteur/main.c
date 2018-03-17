
#include <msp430g2553.h>
#include <stdio.h>
#include <string.h>

#include "Driver_GPIO.h"
#include "Driver_Motor.h"
#include "Scan_IR.h"
#include "robot.h"
//--------------------------------------------------------------------------------------------

int auto_mode = 1;

//--------------------------------------------------------------------------------------------
// main: 		   Call each init functions and wait for ever.
//--------------------------------------------------------------------------------------------
void main(void)
{
	char str[200];
	unsigned char res;
	int checked[4]; 		// IR measurement

	WDTCTL = WDTPW + WDTHOLD;   			// Stop WDT
    BCSCTL1 = CALBC1_1MHZ;      			// Set DCO to 1Mhz
    DCOCTL = CALDCO_1MHZ;       			// Set DCO to 1Mhz
    P1DIR = BIT0;

    Init_UART();
    Init_SPI();
    Scan_IR_Init();
    Motor_Init();

    sprintf(str, ">");
    SendString( strlen(str), str);

    //__bis_SR_register(GIE); 				// interrupts enabled
    while(1){
        	if(auto_mode == 1){
        		//if obstacle in front
        		if(Get_IR() > IR_MAX){
        			Motor_Slow_Stop(0);
    				chipSelect();
    				sendChar_SPI('c');
    				res = listening_SPI();
    				chipUnselect();
    				if(res){
    					// Get data from scan
    					Scan_IR_Begin(checked);

    					// Correction
    					Scan_IR_DoCorrection(checked, Scan_IR_Direction(checked));
    				}
    			}

    			Motor_Start(100);
        	}
    }
}

//--------------------------------------------------------------------------------------------
// USCI0RX_ISR: 	interruption when SPI buffer is updated
//--------------------------------------------------------------------------------------------
// Echo back RXed character, confirm TX buffer is ready first
#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR(void)
{
	char str[200];
	unsigned char choice, res;
	int checked[4]; 		// IR measurement

	choice = ReadUART();

	chipUnselect();

	switch((int)choice)
	{
		// show help
		case (int)'h':
				sprintf(str, "HELP%s", EOL_WINDOWS);
				SendString( strlen(str), str);
				showHelp();
				break;

		// (speed up)
		case (int)'z':
				sprintf(str, "SPEED UP%s", EOL_WINDOWS);
				SendString( strlen(str), str);
				Motor_Start(1);
				break;

		// (scan)
		case (int)'c':
				sprintf(str, "SCAN%s", EOL_WINDOWS);
				SendString( strlen(str), str);
				Motor_Slow_Stop(0);
				chipSelect();
				sendChar_SPI(choice);
				res = listening_SPI();
				chipUnselect();
				if(res){
					// Get data from scan
					Scan_IR_Begin(checked);

					// Correction
					Scan_IR_DoCorrection(checked, Scan_IR_Direction(checked));
				}else{
					sprintf(str, "Le scan a echou?:( %s", EOL_WINDOWS);
					SendString( strlen(str), str);
				}
				break;

		// (turn left)
		case (int)'q':
				sprintf(str, "LEFT%s", EOL_WINDOWS);
				SendString( strlen(str), str);
				Motor_Turn(DIRECTION_LEFT, 0);
				break;

		// (turn righ)
		case (int)'d':
				sprintf(str, "RIGHT%s", EOL_WINDOWS);
				SendString( strlen(str), str);
				Motor_Turn(DIRECTION_RIGHT, 0);
				break;

		// (down speed)
		case (int)'s':
				sprintf(str, "DOWN SPEED%s", EOL_WINDOWS);
				SendString( strlen(str), str);
				Motor_Slow_Stop(1);
				break;

		// (STOP)
		case (int)'a':
				sprintf(str, "STOOOOOOP%s", EOL_WINDOWS);
				SendString( strlen(str), str);
				Motor_Slow_Stop(0);
				break;

		// (START)
		case (int)'e':
				sprintf(str, "START%s", EOL_WINDOWS);
				SendString( strlen(str), str);
				Motor_Start(0);
				break;

		// (FULL SPEED)
		case (int)'f':
				sprintf(str, "FULL%s", EOL_WINDOWS);
				SendString( strlen(str), str);
				Motor_Start(10);
				break;

		// AUTO MODE
		case (int)'A':
				if(auto_mode == 0){
					sprintf(str, "Auto mode activated%s", EOL_WINDOWS);
					SendString( strlen(str), str);
					auto_mode = 1;
				}else{
					sprintf(str, "Auto mode desactivated%s", EOL_WINDOWS);
					SendString( strlen(str), str);
					auto_mode = 0;
				}
				break;
	}

	// current launchpad
	sprintf(str, "%s", LAUNCHPAD_ROLE);
	SendString( strlen(str), str);

	// Return pipe
    sprintf(str, ">");
    SendString( strlen(str), str);
}
