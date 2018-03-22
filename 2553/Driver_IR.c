/*------------------------------------------------------------------------------*/
/* Description: 		Driver_IR.c contains functions managing the IR driver   */
/*------------------------------------------------------------------------------*/

#include "Driver_IR.h"

/*------------------------------------------------------------------------------*/
/* Init_IR :  called to initialize the IR measurement*/
/* IN/OUT:	  none.*/
/* return:    none.*/
/*------------------------------------------------------------------------------*/
void Init_IR(void){
	ADC_init();
}

/*------------------------------------------------------------------------------*/
/* Begin_IR :  called to begin the IR measurement*/
/* IN/OUT:	  none.*/
/* return:    none.*/
/*------------------------------------------------------------------------------*/
void Begin_IR(void){
	ADC_Demarrer_conversion(3);
}

/*------------------------------------------------------------------------------*/
/* Read_IR :  called to read the IR measurement*/
/* IN/OUT:	  int : return measurement.*/
/* return:    none.*/
/*------------------------------------------------------------------------------*/
int Read_IR(void){
	return ADC_Lire_resultat();
}

/*------------------------------------------------------------------------------*/
/* Get_IR :  called to begin & read the IR measurement*/
/* IN/OUT:	  int : return measurement.*/
/* return:    none.*/
/*------------------------------------------------------------------------------*/
int Get_IR(void){
	ADC_Demarrer_conversion(3);
	return ADC_Lire_resultat();
}
