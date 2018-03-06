//------------------------------------------------------------------------------
// Driver_IR.h contains prototype of all managing functions for IR measurement
//------------------------------------------------------------------------------
#ifndef DRIVER_IR_HEADER
#define DRIVER_IR_HEADER

#include "Driver_ADC.h"

#define IR_MAX 500

//------------------------------------------------------------------------------
// Init_IR :  called to initialize the IR measurement
// IN/OUT:	  none.
// return:    none.
//------------------------------------------------------------------------------
void Init_IR(void);

//------------------------------------------------------------------------------
// Begin_IR :  called to begin the IR measurement
// IN/OUT:	  none.
// return:    none.
//------------------------------------------------------------------------------
void Begin_IR(void);

//------------------------------------------------------------------------------
// Read_IR :  called to read the IR measurement
// IN/OUT:	  int : return measurement.
// return:    none.
//------------------------------------------------------------------------------
int Read_IR(void);

//------------------------------------------------------------------------------
// Get_IR :  called to begin & read the IR measurement
// IN/OUT:	  int : return measurement.
// return:    none.
//------------------------------------------------------------------------------
int Get_IR(void);

#endif
