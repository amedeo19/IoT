#include "Dist_task_ready.h"

Dist_task_ready::Dist_task_ready(Dist* dist){
  
  this->dist=dist;
}

void Dist_task_ready::init(int period){
  Task::init(period);
}


void Dist_task_ready::tick(int basePeriod){
	if (State::getInstance()->getValue()==READY){	
    Serial.println(dist->getDistance());
		if (dist->getDistance()>DIST1){
			bool flag=this->updateAndCheckTime(basePeriod);    // if distance is correct for DT1
			if (flag){
				State::getInstance()->setValue(ON);
				this->reset();
			}
		}else{											 // reset if distance errated
			this->reset();
		}
	}else{												// reset if state not on because this time haven't to be overwritten
		this->reset();	
	}
}                                                                                            
