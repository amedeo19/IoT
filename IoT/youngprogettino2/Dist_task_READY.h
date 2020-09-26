#ifndef __DIST_TASK_READY__
#define __DIST_TASK_READY__

#include "Task.h"
#include "Distantiometer.h"

class Dist_task_ready: public Task { 

  Dist* dist;

public:

  Dist_task_ready(Dist* dist);
  void init(int period);
  void tick(int basePeriod);
};

#endif
