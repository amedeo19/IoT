#ifndef __LED_TASK__
#define __LED_TASK__

#include "Task.h"
#include "Led_impl.h"

class Led_task: public Task {  

  Led_impl* leds[N_LED];
  State* state;

public:

  Led_task(int* pins);  
  void init(int period);
  void tick(int basePeriod);
};

#endif
