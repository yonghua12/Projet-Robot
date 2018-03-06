

#include "Driver_Motor_IR.h"

//------------------------------------------------------------------------------
// Motor_IR_Init :  called to initialize the ir motor configuration
// IN:		  none.
// OUT:	  	  none.
// return:    none.
//------------------------------------------------------------------------------
void Motor_IR_Init(void){
	// Motor management
	Motor_Start();

	// PWM init
	Motor_PWM_Init();
}


//------------------------------------------------------------------------------
// Motor_PWM_Init :  Called to start the pwm signal
// IN:		  none.
// OUT:	  	  none.
// return:    none.
//------------------------------------------------------------------------------
void Motor_PWM_Init(void){
	BCSCTL1 = CALBC1_1MHZ; 				// Clock frequency 1MHz
	DCOCTL 	= CALDCO_1MHZ; 				// Clock frequency 1MHz
	TACTL 	= (TASSEL_2 | MC_1 | ID_0);
	TACCTL1 = OUTMOD_7;
	TACCR0 	= 20000;
	TACCR1 	= MOTOR_INIT_DEG;

	//TACCTL1 |= CCIE;					// enable interrupt
	__enable_interrupt();
}

//------------------------------------------------------------------------------
// Motor_Stop :  stop the motor
// IN:		  none.
// OUT:	  	  none.
// return:    none.
//------------------------------------------------------------------------------
void Motor_Stop(void){
	P1DIR &= ~(IR_MOTOR);
}

//------------------------------------------------------------------------------
// Motor_Start :  start the motor
// IN:		  none.
// OUT:	  	  none.
// return:    none.
//------------------------------------------------------------------------------
void Motor_Start(void){
	P1SEL |= IR_MOTOR;
	P1DIR |= IR_MOTOR;
}

//------------------------------------------------------------------------------
// Motor_Set_Deg :  realize the rotation to the degree in parameter
// IN:		  deg (int) degree of rotation.
// OUT:	  	  none.
// return:    int value of TACCR1 to set the rotation.
//------------------------------------------------------------------------------
int Motor_Set_Deg(int deg){
	int taccr = 0;

	// < 45
	if(deg == 0){
		taccr = MOTOR_MAX_DEG / 5;
	// > 0 & < 45
	}else if(deg > 0 && deg <= 45){
		taccr = (2 * MOTOR_MAX_DEG) / 5;
	// > 45 & < 90
	}else if(deg > 45 && deg <= 90){
		taccr = (3 * MOTOR_MAX_DEG) / 5;
	// > 90 & < 135
	}else if(deg > 90 && deg <= 135){
		taccr = (4 * MOTOR_MAX_DEG) / 5;
	// > 135 & 180
	}else if(deg > 135 && deg <= 180){
		taccr = MOTOR_MAX_DEG;
	}

	return taccr;
}
