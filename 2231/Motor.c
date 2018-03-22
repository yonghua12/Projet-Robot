/*-----------------------------------------------------------------------------*/
/* Motor.h contains prototype of all managing functions for motors IR		   */
/*-----------------------------------------------------------------------------*/
#include "Motor.h"


/*-----------------------------------------------------------------------------*/
/*Init_Motor :  initialize the motor IR*/
/*-----------------------------------------------------------------------------*/
void Init_Motor(void) {
	P1SEL |= BIT2;
	P1DIR |= BIT2;
	BCSCTL1 = CALBC1_1MHZ; 				/* Clock frequency 1MHz*/
	DCOCTL = CALDCO_1MHZ; 				/* Clock frequency 1MHz*/
	TACTL = (TASSEL_2 | MC_1 | ID_0);
	TACCTL1 = OUTMOD_7;
	TACCR0 = 33333;
	TACCR1 = 504;
}
/*-----------------------------------------------------------------------------*/
/* arret :  stop the motor IR*/
/* IN/OUT:	  none.*/
/* return:    none.*/
/*-----------------------------------------------------------------------------*/
void arret(void){
	TACCR1 = 0;
}
/*-----------------------------------------------------------------------------*/
/* Tourner :  trun the motor IR*/
/* IN/OUT:	  degree*/
/* return:    TA*/
/*-----------------------------------------------------------------------------*/
static int Tourner(int deg) {
	int TA = 0;     /*initialize TA*/
	switch(deg){
		case 0 : 
			TA = 504;
			break;
		case 30 :
			TA = 828;
			break;
		case 60 :
			TA = 1152;
			break;
		case 90 :
			TA = 1476;
			break;
		case 120 :
			TA = 1800;
			break;
		case 150 :
			TA = 2124;
			break;
		case 180 :
			TA = 2448;
			break;
		default :
			TA = 0;
			break;

	return TA;
}
/*-----------------------------------------------------------------------------*/
/* Motor_bala :  turn the motor IR*/
/* IN/OUT:	  none.*/
/* return:    none.*/
/*-----------------------------------------------------------------------------*/
void Motor_bala(void) {
	int i;
	for(i=0;i<=180;i=i+30){
	TACCR1 = Tourner(i);    /* set to 0 deg*/
	__delay_cycles(320000); /*wait*/
}
	for(i=150;i>0;i=i-30){
	TACCR1 = Tourner(i);   /* set to 135 deg*/
	__delay_cycles(320000);}/*wait*/

}
