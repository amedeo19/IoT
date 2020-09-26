#include "Distantiometer.h"
#include "Arduino.h"

Dist::Dist(int trigPin, int echoPin){
	this->trigPin=trigPin;
	this->echoPin=echoPin;
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
}

long Dist::getDistance(){

  long durata,distanza;
  
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  durata = pulseIn(ECHO_PIN,HIGH);
  
  
// Converti il tempo in distanza:
  distanza = durata / 29.1 / 2 ;
 return distanza;
}
