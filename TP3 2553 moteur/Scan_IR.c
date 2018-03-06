//------------------------------------------------------------------------------
// Name: 				Scan_IR.c
//
// Description: 		Scan_IR.c contains functions managing the IR data analysis
//
// Authors:				Paul Bouquet / Paul Mocquillon
//
// Date of creation: 	22/03/2017
//
// Version: 			1.0
//------------------------------------------------------------------------------

#include "Scan_IR.h"

//--------------------------------------------------------------------------------------------
// Scan_IR_Init : 		 Initialize the IR scanner
// IN:	  		  		none.
// OUT:	  		  		none.
// return:    		 	none.
//--------------------------------------------------------------------------------------------
void Scan_IR_Init(){
	Init_IR();								// Initialize IR measurement
}

//--------------------------------------------------------------------------------------------
// Scan_IR_Begin :		Scan each times the IR_robot rotate
// IN:	  		  		none.
// OUT:	  		  		int checked : table of IR value scanned.
// return:    		  	none.
//--------------------------------------------------------------------------------------------
void Scan_IR_Begin(int * checked){
	int i;

	// Scan begin
	for(i = 0; i < 5; i++){
		// Get value
		checked[i] = Get_IR();

		// Send values to user
		//sprintf(str, "SCAN %d : %d ( %s", i, checked[i], EOL_WINDOWS);
		//SendString( strlen(str), str);

		// Wait to sync
		__delay_cycles(TIME_TO_CHECK);
	}
}

//--------------------------------------------------------------------------------------------
// Scan_IR_Direction :  Decide the correction to realize
// IN:	  		  		int checked : table of IR value scanned.
// OUT:	  		  		int correct : the direction decided by Scan_IR_Direction.
// return:    		  	none.
//--------------------------------------------------------------------------------------------
int Scan_IR_Direction(int * checked){
	int correct = 0;
	int left = checked[0] + checked[1];
	int right = checked[3] + checked[4];
	int forward = checked[2] * 2;

	if(left > forward && left > right){
		correct = 1; // turn left
	}else if(right > forward && right > left){
		correct = 2; // turn right
	}else{
		correct = 3; // go forward
	}

	return correct;
}

//--------------------------------------------------------------------------------------------
// Scan_IR_DoCorrection : Realize the correction asked by Scan_IR_Direction
// IN:	  		  		int checked : table of IR value scanned / int correct : the direction decided by Scan_IR_Direction.
// OUT:	  		  		int result : return the direction decided.
// return:    		  	none.
//--------------------------------------------------------------------------------------------
int Scan_IR_DoCorrection(int * checked, int correct){
	int result = 0;

	// Do correction
	switch (correct){
		case 1: 	// turn left
			Motor_Turn(DIRECTION_LEFT, 0);
			result = 1;
			break;
		case 2 : 	// turn right
			Motor_Turn(DIRECTION_RIGHT, 0);
			result = 2;
			break;
		default:	 // go forward
			Motor_Turn(DIRECTION_FORWARD, 0);
			break;
	}

	// restart
	Motor_Start(1);

	// wait the end of the correction
	__delay_cycles(TIME_TO_CORRECT);

	// end of correction
	Motor_Turn(DIRECTION_FORWARD, 0);

	return result;
}
