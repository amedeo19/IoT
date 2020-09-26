#include "Led_impl.h"
#include "Arduino.h"
#include "config.h"

Led_impl::Led_impl(unsigned int pin,Status statum){
  this->pin = pin;
  this->cstate = statum;  
}

void Led_impl::init(int period){
  Task::init(period);
  led = new Led(this->pin);
}

void Led_impl::tick(int basePeriod){
  noInterrupts();
  if (State::getInstance()->getValue()==cstate){
      bool flag=this->updateAndCheckTime(basePeriod);
      if (flag){
       switch(cstate){
          case LED1: State::getInstance()->setValue(LED2);
            break;
          case LED2: State::getInstance()->setValue(LED3);
            break;
          case LED3: State::getInstance()->setValue(FINISH);
            break;
       }
       this->reset();
    }
  }else{
    this->reset();
  }
  interrupts();
}
