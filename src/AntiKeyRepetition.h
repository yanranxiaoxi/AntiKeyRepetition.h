#ifndef _AntiKeyRepetition_h_
#define _AntiKeyRepetition_h_

#include "Arduino.h"

class AntiKeyRepetition {
	private:
		byte p;
		bool state = 0;
		bool old = 0;
		bool access = 0;

	public:
		AntiKeyRepetition(byte pin);
		bool getAccessState();
		void delAccess();
};

#endif
