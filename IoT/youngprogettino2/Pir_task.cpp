#include "Arduino.h"
#include "Pir_task.h"
#include "TimerOne.h"
#include <avr/sleep.h>

Pir_task::Pir_task(unsigned int pin){
  this->pin = pin;
}

void Pir_task::init(int period){
  Task::init(period);
  this->pir = new Pir(pin);
}

void wakeUp(){
  if (State::getInstance()->getValue()==STAND_BY){
    State::getInstance()->setValue(ON);
  }
}

void Pir_task::tick(int basePeriod){

  Serial.println("Pir task");
  if(State::getInstance()->getValue()==STAND_BY){  
    attachInterrupt(digitalPinToInterrupt(PIR), wakeUp, RISING);
    this->sleep();
    Serial.println("Risvegliato");   
    State::getInstance()->setValue(ON);
  }else{
    if (State::getInstance()->getValue()==ON){
      Serial.flush();
      Serial.println("stato ON");
      
  	  if (pir->rilevated()){
        Serial.flush();
        Serial.println("rilevated");
        this->reset();
  	  }else{
        Serial.flush();
        Serial.println("Not rilevated");
        bool flag=this->updateAndCheckTime(basePeriod);
        if (flag){
          Serial.flush();
          Serial.println("RITORNO A STAND_BY");
          State::getInstance()->setValue(STAND_BY);
          this->reset();
        }
  	  }
    }else{
  	 this->reset();
    }
  }
}

void Pir_task::sleep(){
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_mode();
  sleep_disable();
}
