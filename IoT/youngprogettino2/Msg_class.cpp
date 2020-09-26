#include "MsgService.h"
#include "Msg_class.h"
#include "Arduino.h"
#include "config.h"

boolean toSend=false;

Msg_class::Msg_class(Pot* pot){  // devi prima chiamare initialize, in teoria dovrebbe prendere bene il pin
  this->pot =  pot;
  this->oldValue=NOSUGAR;
  MsgService.init();
}

void Msg_class::controlSugar(){

  if((State::getInstance()->getSugar() != this->oldValue) && (State::getInstance()->getValue()==READY)){
    this->oldValue=State::getInstance()->getSugar();
    State::getInstance()->setSugar(this->oldValue); 
    MsgService.sendMsg(""+ State::getInstance()->getSugar());
  }else if ((State::getInstance()->getSugar() == NOSUGAR)&& (State::getInstance()->getValue()!=READY)){
    this->oldValue=NOSUGAR;
  }
}

void Msg_class::sendMessage(){
  
  //controllo lo stato attivo

  if(State::getInstance()->getValue()==READY){
    MsgService.sendMsg("READY");
  } else if(State::getInstance()->getValue()==MAINTENANCE){
    MsgService.sendMsg("MAINTENANCE");
  } else if(State::getInstance()->getValue()==LED1){
    MsgService.sendMsg("LED1");
  } else if(State::getInstance()->getValue()==LED3){
    MsgService.sendMsg("LED3");
  }else if(State::getInstance()->getValue()==FINISH){
    MsgService.sendMsg("FINISH");
  }

  
}

void Msg_class::receiveMessage(){

  if (State::getInstance()->getValue()==MAINTENANCE){
    if (MsgService.isMsgAvailable()) {
      Msg* msg = MsgService.receiveMsg();
      if (msg->getContent() == "charge"){
        State::getInstance()->setValue(STAND_BY);   
      }
      delete msg;
    }
  }
}
