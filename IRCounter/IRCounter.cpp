/*
  IRCounter.h - Library for counting object using infrared sensor
  Copyright (c) 2018 Deswin Auliyaa. All right reserved.
*/

// include core Wiring API
#include "Arduino.h"

// include this library's description file
#include "IRCounter.h"

// Constructor
// Function that handles the creation and setup of instances
IRCounter::IRCounter(int pin)
{
	// initialize this instance's variables
	_pin = pin;
	_count = 0;
	_prevIR = 0;
	_lastIR = 0;
	_ir = 0;
	
	// do whatever is required to initialize the library
	pinMode(pin, INPUT);
}

// Public Methods
// Functions available in Wiring sketches, this library, and other libraries
int IRCounter::count(int state, int interval = 75)
{
	_ir = digitalRead(_pin);
	if(_ir == state and _prevIR == 0){
		if(millis() - _lastIR > interval){
			_count = _count + 1;
		}
		_lastIR = millis();
	}
	_prevIR = _ir;
	
	return _count;
}

void IRCounter::reset(void)
{
	_count = 0;
}