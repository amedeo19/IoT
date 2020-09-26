#ifndef __TASK__
#define __TASK__

#include "Arduino.h"
#include "State.h"

class Task {

  int myPeriod;
  int timeElapsed;
  
public:
  void init(int period){
    myPeriod = period;  
    timeElapsed = 0;
  }

  virtual void tick(int basePeriod) = 0;

  bool updateAndCheckTime(int basePeriod){
    timeElapsed += basePeriod;
    (timeElapsed);
    if (timeElapsed >= myPeriod){
      timeElapsed = 0;
      return true;
    } else {
      return false; 
    }
  }

  void reset(){
    timeElapsed=0;
  }
  
};

#endif
