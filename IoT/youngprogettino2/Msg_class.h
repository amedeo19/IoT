#ifndef __MSG_CLASS__
#define __MSG_CLASS__

#include "Task.h"
#include "Potentiometer.h"
#include "MsgService.h"

class Msg_class {

  unsigned int oldValue;
  Pot* pot;

public:

  // creare funzione booleana per controllo se livello di zucchero è cambiato, nel caso inviare un messaggio

  void controlSugar();
  void sendMessage();
  void receiveMessage();
  Msg_class(Pot* pot);
  
};

#endif
