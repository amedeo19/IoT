#ifndef __DIST__
#define __DIST__

#include "config.h"

class Dist{

	unsigned int trigPin,echoPin;

public:
	
	Dist(int trigPin, int echoPin);
	long getDistance();
	
};


#endif
