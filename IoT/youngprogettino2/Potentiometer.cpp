#include "Potentiometer.h"
#include "Arduino.h"
#include "config.h"

Pot::Pot(const int pin){
  this->pin=pin;
}

int Pot::sugarLevel(){
  return (map((analogRead(pin)), 0, 1023, POT_MIN, POT_MAX));
}
