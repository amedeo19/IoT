#include "led_task.h"
#include "led_impl.h"

Led_task::Led_task(int* pins){
  this->leds[0] = new Led_impl(pins[0],Status::LED1);
  this->leds[1] = new Led_impl(pins[1],Status::LED2);
  this->leds[2] = new Led_impl(pins[2],Status::LED3);
  this->state = state;
}

void Led_task::init(int period){
  Task::init(period);
  int i=0;
  for (i=0;i<N_LED;i++){
    this->leds[i]->init(period/N_LED);
  }
}

void Led_task::tick(int basePeriod){
  int i=0;
  while(i<N_LED){
    this->leds[(N_LED-i)]->tick(basePeriod);    // passo dall' ultimo perchè sennò i tre led impiegano meno tempo del gestore dei led, ma devono essere sincronizzati
    i++;
  }
}
