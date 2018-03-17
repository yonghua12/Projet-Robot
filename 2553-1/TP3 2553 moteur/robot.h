//------------------------------------------------------------------------------
// robot.h contains prototype of all managing functions for driver robot
//------------------------------------------------------------------------------
#ifndef ROBOT_MOTOR_HEADER
#define ROBOT_MOTOR_HEADER

#include <msp430g2553.h>
#include "Driver_Motor.h"

//------------------------------------------------------------------------------
// Motor_Init :  called to initialize the driver robot motor configuration
// IN/OUT:	  none.
// return:    none.
//------------------------------------------------------------------------------
void Motor_Init(void);

//------------------------------------------------------------------------------
// Motor_Slow_Stop :  called to stop the robot OR slow the speed
// IN/OUT:	  int speed_decr : set the speed decrementation, if 0 stop the robot.
// return:    none.
//------------------------------------------------------------------------------
void Motor_Slow_Stop(int speed_decr);

//------------------------------------------------------------------------------
// Motor_Start :  called to restart the robot from the current configuration
// IN/OUT:	  int speed_inc : set the speed incrementation, if 0 just restart.
// return:    none.
//------------------------------------------------------------------------------
void Motor_Start(int speed_inc);

//------------------------------------------------------------------------------
// Motor_Turn :  called to restart the robot from the current configuration
// IN/OUT:	  int direction : set the wheels direction
//			  int deg : realize a rounded turn with this degree.
// return:    none.
//------------------------------------------------------------------------------
void Motor_Turn(int direction, int deg);

#endif
