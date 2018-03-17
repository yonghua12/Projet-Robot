#include "Motor.h"

void Init_Motor(void) {
	P1SEL |= BIT2;
	P1DIR |= BIT2;
	BCSCTL1 = CALBC1_1MHZ; 				// Clock frequency 1MHz
	DCOCTL = CALDCO_1MHZ; 				// Clock frequency 1MHz
	TACTL = (TASSEL_2 | MC_1 | ID_0);
	TACCTL1 = OUTMOD_7;
	TACCR0 = 33333;
	TACCR1 = 504;
}

void arret(void){
	TACCR1 = 0;
}
int Tourner(int deg) {
	int TA = 0;
	if (deg == 0) {
		TA = 504;
	} else if (deg == 30) {
		TA = 828;
	} else if (deg == 60) {
		TA = 1152;
	} else if (deg == 90) {
		TA = 1476;
	} else if (deg == 120) {
		TA = 1800;
	} else if (deg == 150) {
		TA = 2124;
	} else if(deg == 180) {
	    TA = 2448;
	}
	return TA;
}

void Motor_bala(void) {
	int i;
	for(i=0;i<=180;i+=30){
	TACCR1 = Tourner(i); // set to 0 deg
	__delay_cycles(320000);
}
	for(i=150;i>0;i-=30){
	TACCR1 = Tourner(i); // set to 135 deg
	__delay_cycles(320000);}

}
