#ifndef __DIST_TASK_FINISH__
#define __DIST_TASK_FINISH__

#include "Task.h"
#include "Distantiometer.h"

class Dist_task_finish: public Task {  // abstract class

private:
  
  Dist* dist;
  void controlState();
  
public:

  Dist_task_finish(Dist* dist);
  void init(int period);
  void tick(int basePeriod);
};

#endif
