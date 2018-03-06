//------------------------------------------------------------------------------
// Driver_Motor_IR.h contains prototype of all managing functions for IR motor rotation
//------------------------------------------------------------------------------
#ifndef DRIVER_MOTOR_IR_HEADER
#define DRIVER_MOTOR_IR_HEADER

#include <msp430g2231.h>

#define IR_MOTOR BIT2
#define MOTOR_INIT_DEG 500
#define MOTOR_MAX_DEG 2500

//------------------------------------------------------------------------------
// Motor_IR_Init :  called to initialize the ir motor configuration
// IN/OUT:	  none.
// return:    none.
//------------------------------------------------------------------------------
void Motor_IR_Init(void);

//------------------------------------------------------------------------------
// Motor_PWM_Init :  Called to start the pwm signal
// IN/OUT:	  none.
// return:    none.
//------------------------------------------------------------------------------
void Motor_PWM_Init(void);

//------------------------------------------------------------------------------
// Motor_Stop :  stop the motor
// IN/OUT:	  none.
// return:    none.
//------------------------------------------------------------------------------
void Motor_Stop(void);

//------------------------------------------------------------------------------
// Motor_Start :  start the motor
// IN/OUT:	  none.
// return:    none.
//------------------------------------------------------------------------------
void Motor_Start(void);

//------------------------------------------------------------------------------
// Motor_Start :  start the motor
// IN/OUT:	  deg (int) degree of rotation.
// return:    int value of TACCR1 to set the rotation.
//------------------------------------------------------------------------------
int Motor_Set_Deg(int deg);

#endif
