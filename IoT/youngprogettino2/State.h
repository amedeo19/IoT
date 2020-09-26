#include "config.h"
#include "Arduino.h"

  class State{
  
    private:
    
        /* Here will be the instance stored. */
    
        static State* instance;
        Status statum;
        bool coffeeNumber=NMAX;
        int sugar; 
        
        /* Private constructor to prevent instancing. */
        State();
        ~State();

    public:

        Status getValue();
        
        void setValue(Status v);

        bool getButton();
        
        void setButton(bool v);

        unsigned int getSugar();

        void setSugar(unsigned int v);

        unsigned int getNumerOfCoffee();
        
        void coffeeTaken();

        void recharge();

        void initializeCoffe();
 
        static State* getInstance();

};
