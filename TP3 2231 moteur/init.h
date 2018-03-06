//------------------------------------------------------------------------------
// init.h contains prototype of init functions.
//------------------------------------------------------------------------------
#ifndef INIT_HEADER
#define INIT_HEADER

#define TIME_TO_CHECK 400000

//------------------------------------------------------------------------------
// InitPort : Called at the start of the main program. Initialize port
//			  for SPI communication.
// IN/OUT:	  none.
// return:    none.
//------------------------------------------------------------------------------
void InitPort(void);

#endif
