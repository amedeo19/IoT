#ifndef __PIR_TASK__
#define __PIR_TASK__

#include "Task.h"
#include "Pir.h"
//using namespace std;

//extern State state;

class Pir_task: public Task {

  unsigned int pin;
  Pir* pir;
  void sleep();
  
public:

  Pir_task(unsigned int pin);  
  void init(int period);
  void tick(int basePeriod);
};

#endif
