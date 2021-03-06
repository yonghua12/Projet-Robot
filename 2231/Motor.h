#ifndef MOTOR_HEADER
#define MOTOR_HEADER

#include <msp430g2231.h>
#include "Motor.h"
/*-----------------------------------------------------------------------------*/
/*Init_Motor :  initialize the motor IR*/
/* IN/OUT:	  none.*/
/* return:    none.*/
/*-----------------------------------------------------------------------------*/
void Init_Motor(void);
/*-----------------------------------------------------------------------------*/
/* Tourner :  trun the motor IR*/
/* IN/OUT:	  none.*/
/* return:    none.*/
/*-----------------------------------------------------------------------------*/
static int Tourner(int deg);
/*-----------------------------------------------------------------------------*/
/* Motor_bala :  turn the motor IR*/
/* IN/OUT:	  none.*/
/* return:    none.*/
/*-----------------------------------------------------------------------------*/
void Motor_bala(void);
/*-----------------------------------------------------------------------------*/
/* arret :  stop the motor IR*/
/* IN/OUT:	  none.*/
/* return:    none.*/
/*-----------------------------------------------------------------------------*/
void arret(void);

#endif
