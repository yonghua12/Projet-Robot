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

#include "robot.h"

//------------------------------------------------------------------------------
// Motor_Init :  called to initialize the driver robot motor configuration
// IN/OUT:	  none.
// return:    none.
//------------------------------------------------------------------------------
void Motor_Init(void){
	// Initialize ports
	Driver_Motor_Start();

	// Initialize pwm
	Driver_Motor_PWM_Init();

	// Stop
	Driver_Motor_Stop();

	// Set wheels to go forward
	Driver_Motor_Change_Wheel_Direction(DIRECTION_FORWARD);
}

//------------------------------------------------------------------------------
// Motor_Slow_Stop :  called to stop the robot OR slow the speed
// IN/OUT:	  int speed_decr : set the speed decrementation, if 0 stop the robot.
// return:    none.
//------------------------------------------------------------------------------
void Motor_Slow_Stop(int speed_decr){
	// If speed_decr == 0 --> Stop the robot
	if(speed_decr == 0){
		// set to default
		Driver_Motor_Default_Speed();

		// stop
		Driver_Motor_Stop();

	// If not : decelerate the robot * speed_decr
	}else{
		Driver_Motor_Deceleration(speed_decr);
	}
}


//------------------------------------------------------------------------------
// Motor_Start :  called to restart the robot from the current configuration
// IN/OUT:	  int speed_inc : set the speed incrementation, if 0 just restart.
// return:    none.
//------------------------------------------------------------------------------
void Motor_Start(int speed_inc){
	// Correct wheels speed
	Driver_Motor_Correct_Speed();

	//	Set speed to full
	if(speed_inc >= 10){
			Driver_Motor_Max_Speed();

	// Increment the speed
	}else if(speed_inc > 0){
		Driver_Motor_Acceleration(speed_inc);
	}

	// if just restarting previous configuration
	Driver_Motor_Start();
}

//------------------------------------------------------------------------------
// Motor_Turn :  called to restart the robot from the current configuration
// IN/OUT:	  int direction : set the wheels direction
//			  int deg : realize a rounded turn with this degree.
// return:    none.
//------------------------------------------------------------------------------
void Motor_Turn(int direction, int deg){
	// Correct wheels speed
	Driver_Motor_Correct_Speed();

	// If just setting the wheels direction
	if(deg == 0){
		Driver_Motor_Change_Wheel_Direction(direction);

	// Rounded turn
	}else{
		// TODO
	}
}

