#include "Scheduler.h"

void Scheduler::init(int basePeriod,Pot* pot,Button* bt,Msg_class* msg){
  this->basePeriod = basePeriod;
  timer.setupPeriod(basePeriod);  
  nTasks = 0;
  this->pot=pot;
  this->bt=bt;
  this->msg=msg;
}

bool Scheduler::addTask(Task* task){
  if (nTasks < MAX_TASKS-1){
    taskList[nTasks] = task;
    nTasks++;
    return true;
  } else {
    return false; 
  }
}

void Scheduler::potControl(){
  State::getInstance()->setSugar(pot->sugarLevel());
}

void Scheduler::button(){
  if (State::getInstance()->getValue()==READY){      // BUTTON CODE
    if (bt->readValue()){
      State::getInstance()->setValue(LED1);
    }
  } 
}

void Scheduler::schedule(void){
  timer.waitForNextTick();
  button();
  potControl();
  for (int i = 0; i < nTasks; i++){
      taskList[i]->tick(PERIOD);
  }
  msg->controlSugar();
  msg->sendMessage();
  msg->receiveMessage();
}
