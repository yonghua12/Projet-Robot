//------------------------------------------------------------------------------
// Name: 				Driver_Motor.c
//
// Description: 		Driver_Motor.c contains functions managing the robot motors
//
// Authors:				Paul Bouquet / Paul Mocquillon
//
// Date of creation: 	21/03/2017
//
// Version: 			1.1
//------------------------------------------------------------------------------

#include "Driver_Motor.h"


//------------------------------------------------------------------------------
// Driver_Motor_PWM_Init :  Called to start the pwm signal
// IN/OUT:	  none.
// return:    none.
//------------------------------------------------------------------------------
void Driver_Motor_PWM_Init(void){
	BCSCTL1 	= CALBC1_1MHZ; 				// Clock frequency 1MHz
	DCOCTL 		= CALDCO_1MHZ; 				// Clock frequency 1MHz
	TA1CTL 		= (TASSEL_2 | MC_1 | ID_0);
	TA1CCTL1 	= OUTMOD_7;
	TA1CCTL2 	= OUTMOD_7;
	TA1CCR0 	= 4000;

	//TACCTL1 |= CCIE;					// enable interrupt
	__enable_interrupt();
}

//------------------------------------------------------------------------------
// Driver_Motor_Stop :  stop the motor
// IN/OUT:	  none.
// return:    none.
//------------------------------------------------------------------------------
void Driver_Motor_Stop(void){
	P2DIR &= ~(RIGHT_MOTOR | LEFT_MOTOR);
}

//------------------------------------------------------------------------------
// Driver_Motor_Start :  start the motor
// IN/OUT:	  none.
// return:    none.
//------------------------------------------------------------------------------
void Driver_Motor_Start(void){
	// PORTS
	P2SEL |= (LEFT_MOTOR | RIGHT_MOTOR);
	P2DIR |= (LEFT_WHEEL | LEFT_MOTOR | RIGHT_MOTOR | RIGHT_WHEEL);
	//P2OUT &= ~(LEFT_WHEEL | LEFT_MOTOR | RIGHT_MOTOR | RIGHT_WHEEL);
}

//------------------------------------------------------------------------------
// Driver_Motor_Acceleration :  increase the speed of the motor
// IN/OUT:	  int inc : mulitplication of incrementation.
// return:    none.
//------------------------------------------------------------------------------
void Driver_Motor_Acceleration(int inc){
	// check if not under maximum value
	if((TA1CCR1 < (LEFT_MOTOR_PWM_MAX + (100*inc))) && (TA1CCR2 < (RIGHT_MOTOR_PWM_MAX + (100*inc)))){
		TA1CCR1 	+= 100*inc;
		TA1CCR2 	+= 100*inc;
	}
}

//------------------------------------------------------------------------------
// Driver_Motor_Deceleration :  decrease the speed of the motor
// IN/OUT:	  int decr : multiplication of deceleration.
// return:    none.
//------------------------------------------------------------------------------
void Driver_Motor_Deceleration(int decr){
	// check if not future negative value
	if((TA1CCR1 > (100*decr)) && (TA1CCR2 > (100*decr))){
		TA1CCR1 	-= 100*decr;
		TA1CCR2 	-= 100*decr;

	// else stop
	}else{
		TA1CCR1 	= 0;
		TA1CCR2 	= 0;
	}
}

//------------------------------------------------------------------------------
// Motor_Change_Wheel_Direction :  change the direction of the wheel of the motor
// IN/OUT:	  int direction : direction value.
// return:    none.
//------------------------------------------------------------------------------
void Driver_Motor_Change_Wheel_Direction(int direction){
	switch (direction){
	// go forward
	case DIRECTION_FORWARD:
		P2OUT &= ~(LEFT_WHEEL);
		P2OUT |= RIGHT_WHEEL;
		break;

	// go right
	case DIRECTION_RIGHT:
		P2OUT |= LEFT_WHEEL;
		P2OUT |= RIGHT_WHEEL;
		//TA1CCR2 = 0;
		break;

	// go left
	case DIRECTION_LEFT:
		//TA1CCR1 = 0;
		P2OUT &= ~(LEFT_WHEEL);
		P2OUT &= ~(RIGHT_WHEEL);
		break;

	//
	default:
		P2OUT |= LEFT_WHEEL;
		P2OUT &= ~(RIGHT_WHEEL);
		break;
	}
}

//------------------------------------------------------------------------------
// Driver_Motor_Default_Speed :  change the speed to default
// IN/OUT:	  none.
// return:    none.
//------------------------------------------------------------------------------
void Driver_Motor_Default_Speed(void){
	TA1CCR1 	= (3*LEFT_MOTOR_PWM_MAX)/4;
	TA1CCR2 	= (3*RIGHT_MOTOR_PWM_MAX)/4;
}

//------------------------------------------------------------------------------
// Driver_Motor_Max_Speed :  change the speed to max
// IN/OUT:	  none.
// return:    none.
//------------------------------------------------------------------------------
void Driver_Motor_Max_Speed(void){
	TA1CCR1 	= LEFT_MOTOR_PWM_MAX;
	TA1CCR2 	= RIGHT_MOTOR_PWM_MAX;
}

//------------------------------------------------------------------------------
// Driver_Motor_Correct_Speed :  equalize the wheels speed
// IN/OUT:	  none.
// return:    none.
//------------------------------------------------------------------------------
void Driver_Motor_Correct_Speed(void){
	if(TA1CCR1 > TA1CCR2){
		TA1CCR2 = TA1CCR1;
	}else{
		TA1CCR1 = TA1CCR2;
	}
}
