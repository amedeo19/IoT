#include "Pir.h"
#include "Arduino.h"
#include "config.h"

Pir::Pir(unsigned int pin){
  pinMode(pin,INPUT);
  this->pin = pin;
}

bool Pir::rilevated(){
  return ((digitalRead(pin))==HIGH);
}
