//------------------------------------------------------------------------------
// Name: 				robot.c
//
// Description: 		robot.c contains functions managing the robot driver
//
// Authors:				Paul Bouquet / Paul Mocquillon
//
// Date of creation: 	22/03/2017
//
// Version: 			1.0
//------------------------------------------------------------------------------

#include "Driver_IR.h"

//------------------------------------------------------------------------------
// Init_IR :  called to initialize the IR measurement
// IN/OUT:	  none.
// return:    none.
//------------------------------------------------------------------------------
void Init_IR(void){
	ADC_init();
}

//------------------------------------------------------------------------------
// Begin_IR :  called to begin the IR measurement
// IN/OUT:	  none.
// return:    none.
//------------------------------------------------------------------------------
void Begin_IR(void){
	ADC_Demarrer_conversion(3);
}

//------------------------------------------------------------------------------
// Read_IR :  called to read the IR measurement
// IN/OUT:	  int : return measurement.
// return:    none.
//------------------------------------------------------------------------------
int Read_IR(void){
	return ADC_Lire_resultat();
}

//------------------------------------------------------------------------------
// Get_IR :  called to begin & read the IR measurement
// IN/OUT:	  int : return measurement.
// return:    none.
//------------------------------------------------------------------------------
int Get_IR(void){
	ADC_Demarrer_conversion(3);
	return ADC_Lire_resultat();
}
