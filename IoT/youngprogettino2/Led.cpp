#include "Led.h"
#include "Arduino.h"

Led::Led(unsigned int pin){
  this->pin = pin;
  pinMode(pin,OUTPUT);
}

void Led::switchOn(){
  digitalWrite(pin,HIGH);
}

void Led::switchOff(){
  digitalWrite(pin,LOW);
};
