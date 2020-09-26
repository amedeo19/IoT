#ifndef __LED_IMPL__
#define __LED_IMPL__

#include "Task.h"
#include "Led.h"

extern State state; 

class Led_impl: public Task {  // gestore di un singolo led

  unsigned int pin;
  Led* led;
  Status cstate;

public:

  Led_impl(unsigned int pin,Status statum);  
  void init(int period);
  void tick(int basePeriod);
};

#endif
