/*
  IRCounter.h - Library for counting object using infrared sensor
  Copyright (c) 2018 Deswin Auliyaa. All right reserved.
*/

// ensure this library description is only included once
#ifndef IRCounter_h
#define IRCounter_h

// include types & constants of Wiring core API
#include "Arduino.h"

// library interface description
class IRCounter
{
	// user-accessible "public" interface
	public:
		IRCounter(int pin);
		int count(int state, int interval = 75);
		void reset(void);
	
	// library-accessible "private" interface
	private:
		int _pin;
		int _prevIR;
		int _ir;	
		long int _lastIR;
		long int _count;
};

#endif

