#include "State.h"
#include <stddef.h> 

State::State(){};

State::~State(){};

State* State::instance;

        Status State::getValue(){
            return statum;
        }

        void State::setValue(Status v){
          statum = v;
        }

        unsigned int State::getSugar(){
          return sugar;
        }
        
        void State::setSugar(unsigned int v){
          sugar = v;
        }

        unsigned int State::getNumerOfCoffee(){
          return coffeeNumber;
        }
        
        void State::coffeeTaken(){
          int newCoffe=coffeeNumber-1;
          coffeeNumber=newCoffe;
        }

        void State::recharge(){
          coffeeNumber=NC;
        }

        void State::initializeCoffe(){
          coffeeNumber=NMAX;
        }

State* State::getInstance(){

          if (instance==NULL){
            instance = new State;
          }
          
          return instance;
}
