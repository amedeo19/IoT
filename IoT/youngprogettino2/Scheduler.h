#ifndef __SCHEDULER__
#define __SCHEDULER__

//#include "TimerOne.h"
#include "Task.h"
#include "Button.h"
#include "Msg_class.h"
#include "Potentiometer.h"
#include "Timer.h"

class Scheduler {      // abstract class
  
  int basePeriod;
  int nTasks;
  Task* taskList[MAX_TASKS];
  Pot* pot;
  Button* bt;
  Msg_class* msg;
  Timer timer;

  void potControl();
  void button();

public:
  void init(int basePeriod,Pot* pot,Button* bt,Msg_class* msg);
  bool addTask(Task* task);  
  void schedule();
};

#endif
