/*------------------------------------------------------------------------------*/
/* Description:      SCAN_IR.h contains prototype of all managing functions for IR data analysis*/
/*------------------------------------------------------------------------------*/
#ifndef SCAN_IR_HEADER
#define SCAN_IR_HEADER

#include <string.h>
#include "const.h"
#include "Driver_IR.h"
#include "Driver_Motor.h"
#include "robot.h"

/*--------------------------------------------------------------------------------------------*/
/* Scan_IR_Init : 		 Initialize the IR scanner*/
/* IN:	  		  		none.*/
/* OUT:	  		  		none.*/
/* return:    		 	none.*/
/*--------------------------------------------------------------------------------------------*/
void Scan_IR_Init(void);

/*--------------------------------------------------------------------------------------------*/
/* Scan_IR_Begin :		Scan each times the IR_robot rotate*/
/* IN:	  		  		none.*/
/* OUT:	  		  		int checked : table of IR value scanned.*/
/* return:    		  	none.*/
/*--------------------------------------------------------------------------------------------*/
void Scan_IR_Begin(int * checked);

/*--------------------------------------------------------------------------------------------*/
/* Scan_IR_Direction :  Decide the correction to realize*/
/* IN:	  		  		int checked : table of IR value scanned.*/
/* OUT:	  		  		int correct : the direction decided by Scan_IR_Direction.*/
/* return:    		  	none.*/
/*--------------------------------------------------------------------------------------------*/
int Scan_IR_Direction(int * checked);

/*--------------------------------------------------------------------------------------------*/
/* Scan_IR_DoCorrection : Realize the correction asked by Scan_IR_Direction*/
/* IN:	  		  		int checked : table of IR value scanned / int correct : the direction decided by Scan_IR_Direction.*/
/* OUT:	  		  		int result : return the direction decided.*/
/* return:    		  	none.*/
/*--------------------------------------------------------------------------------------------*/
int Scan_IR_DoCorrection(int * checked, int correct);

#endif
