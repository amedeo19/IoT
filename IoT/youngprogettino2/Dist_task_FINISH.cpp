#include "Dist_task_finish.h"

Dist_task_finish::Dist_task_finish(Dist* dist){
   this->dist=dist;
}

void Dist_task_finish::init(int period){
  Task::init(period);
}

void Dist_task_finish::tick(int basePeriod){
  if (State::getInstance()->getValue()==FINISH){  
    if (dist->getDistance()>DIST2){
      bool flag=this->updateAndCheckTime(basePeriod);    // if distance is correct for DT1
      if (flag){
        this->controlState();
      }
    }else{                       // reset if distance errated
      this->controlState();
    }
  }else{                        // reset if state not on because this time haven't to be overwritten
    this->reset();  
  }
} 

  void Dist_task_finish::controlState(){  // private function
    State::getInstance()->coffeeTaken();
    if (State::getInstance()->getNumerOfCoffee()==0){
      State::getInstance()->setValue(MAINTENANCE);
    }else{
      State::getInstance()->setValue(READY);
    }
    this->reset();
  }
