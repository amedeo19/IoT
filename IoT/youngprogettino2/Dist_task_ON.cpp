#include "Dist_task_on.h"

Dist_task_on::Dist_task_on(Dist* dist){
  
   this->dist=dist;
}

void Dist_task_on::init(int period){
  Task::init(period);
}

void Dist_task_on::tick(int basePeriod){
	if (State::getInstance()->getValue()==ON){	
		if (dist->getDistance()<=DIST1){
			bool flag=this->updateAndCheckTime(basePeriod);    // if distance is correct for DT1
			if (flag){
				State::getInstance()->setValue(READY);
				this->reset();
			}
		}else{											 // reset if distance errated
			this->reset();
		}
	}else{												// reset if state not on because this time haven't to be overwritten
		this->reset();	
	}
} 
