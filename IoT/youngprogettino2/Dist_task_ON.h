#ifndef __DIST_TASK_ON__
#define __DIST_TASK_ON__

#include "Task.h"
#include "Distantiometer.h"

class Dist_task_on: public Task {  

  Dist* dist;

public:

  Dist_task_on(Dist* dist);
  void init(int period);
  void tick(int basePeriod);
};

#endif
