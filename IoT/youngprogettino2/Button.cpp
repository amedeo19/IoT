#include "Button.h"

Button::Button(unsigned int pin){
  this->pin=pin;
  pinMode(pin,INPUT);
}

bool Button::readValue(){
  return (digitalRead(this->pin));
}
