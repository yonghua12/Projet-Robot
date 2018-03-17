//------------------------------------------------------------------------------
// Driver_Motor.h contains prototype of all managing functions for robot motors
//------------------------------------------------------------------------------
#ifndef DRIVER_MOTOR_HEADER
#define DRIVER_MOTOR_HEADER

#include <msp430g2553.h>

#define LEFT_MOTOR BIT2
#define RIGHT_MOTOR BIT4

#define LEFT_MOTOR_PWM_MAX 3680
#define RIGHT_MOTOR_PWM_MAX 4000

#define LEFT_WHEEL BIT1
#define RIGHT_WHEEL BIT5

#define DIRECTION_FORWARD 1
#define DIRECTION_RIGHT 2
#define DIRECTION_LEFT 3

//------------------------------------------------------------------------------
// Driver_Motor_Init :  called to initialize the ir motor configuration
// IN/OUT:	  none.
// return:    none.
//------------------------------------------------------------------------------
void Driver_Motor_PWM_Init(void);

//------------------------------------------------------------------------------
// Driver_Motor_Stop :  stop the motor
// IN/OUT:	  none.
// return:    none.
//------------------------------------------------------------------------------
void Driver_Motor_Stop(void);

//------------------------------------------------------------------------------
// Driver_Motor_Start :  start the motor
// IN/OUT:	  none.
// return:    none.
//------------------------------------------------------------------------------
void Driver_Motor_Start(void);

//------------------------------------------------------------------------------
// Driver_Motor_Acceleration :  increase the speed of the motor
// IN/OUT:	  int inc : mulitplication of incrementation.
// return:    none.
//------------------------------------------------------------------------------
void Driver_Motor_Acceleration(int inc);

//------------------------------------------------------------------------------
// Driver_Motor_Deceleration :  decrease the speed of the motor
// IN/OUT:	  int decr : multiplication of deceleration.
// return:    none.
//------------------------------------------------------------------------------
void Driver_Motor_Deceleration(int decr);

//------------------------------------------------------------------------------
// Motor_Change_Wheel_Direction :  change the direction of the wheel of the motor
// IN/OUT:	  int direction : direction value.
// return:    none.
//------------------------------------------------------------------------------
void Driver_Motor_Change_Wheel_Direction(int direction);

//------------------------------------------------------------------------------
// Driver_Motor_Default_Speed :   change the speed to default
// IN/OUT:	  none.
// return:    none.
//------------------------------------------------------------------------------
void Driver_Motor_Default_Speed(void);

//------------------------------------------------------------------------------
// Driver_Motor_Max_Speed :  change the speed to max
// IN/OUT:	  none.
// return:    none.
//------------------------------------------------------------------------------
void Driver_Motor_Max_Speed(void);

//------------------------------------------------------------------------------
// Driver_Motor_Correct_Speed :  equalize the wheels speed
// IN/OUT:	  none.
// return:    none.
//------------------------------------------------------------------------------
void Driver_Motor_Correct_Speed(void);

#endif

