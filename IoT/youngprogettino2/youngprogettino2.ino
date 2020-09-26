#include "Scheduler.h"
#include "TimerOne.h"
#include "Pir_task.h"
#include "Dist_task_on.h"
#include "Dist_task_ready.h"
#include "Dist_task_finish.h"
#include "Led_task.h"
#include "Button.h"
#include "Msg_class.h"
#include "Potentiometer.h"

Task* taskList[MAX_TASKS];
Task* pir;
Task* dist_on;
Task* dist_ready;
Task* dist_finish;
Task* led;
Dist* dist;
Pot* pot;
Button* bt;
Msg_class* msg;
Scheduler sched;

/*void wakeUp(){
  if (State::getInstance()->getValue()==STAND_BY){
    State::getInstance()->setValue(ON);
  }
}*/

void setup(){
  Serial.begin(9600);
  State::getInstance()->setValue(STAND_BY);
  State::getInstance()->setSugar(POT_MIN);
  State::getInstance()->initializeCoffe();
//  nTasks=0;
  pir = new Pir_task(PIR);
  pir->init(DT2a);
  sched.addTask(pir);
/*  addTask(pir);
  dist=new Dist(TRIG_PIN,ECHO_PIN);
  dist_on = new Dist_task_on(dist);
//  sched.addTask(dist_on);
  addTask(dist_on);
  dist_on->init(DT1); 
  dist_ready = new Dist_task_ready(dist);
//  sched.addTask(dist_ready);
  addTask(dist_ready);
  int pins[N_LED] = {LED1_PIN,LED2_PIN,LED3_PIN};
  led = new Led_task(pins);
//  sched.addTask(led);
  addTask(led);
  dist_finish = new Dist_task_finish(dist);
//  sched.addTask(dist_finish);
  addTask(dist_finish);
  dist_finish->init(DT4);
  bt = new Button(BUTTON);
  pot=new Pot(POT_PIN);
  msg = new Msg_class(pot);*/
  sched.init((PERIOD),pot,bt,msg);
/*  Timer1.initialize(PERIOD*1000);  
  Timer1.attachInterrupt(schedule);*/
}

void loop(){
  
  sched.schedule();
}

/*void potControl(){
  noInterrupts();
  State::getInstance()->setSugar(pot->sugarLevel());
  interrupts();
}

void button(){
  if (State::getInstance()->getValue()==READY){      // BUTTON CODE
    if (bt->readValue()){
      State::getInstance()->setValue(LED1);
    }
  }    
}

bool addTask(Task* task){
  if (nTasks < MAX_TASKS-1){
    taskList[nTasks] = task;
    nTasks++;
    return true;
  } else {
    return false; 
  }
}

void schedule(void){
  for (int i = 0; i < MAX_TASKS; i++){
      taskList[i]->tick(PERIOD);
  }
  button();
  potControl();
  msg->controlSugar();
  msg->sendMessage();
  msg->receiveMessage();
}*/
