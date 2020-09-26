#ifndef __BUTTON__
#define __BUTTON__

#include "Arduino.h"

class Button {

private:

  unsigned int pin;

public:

  Button(unsigned int pin);
  bool readValue();

};

#endif
