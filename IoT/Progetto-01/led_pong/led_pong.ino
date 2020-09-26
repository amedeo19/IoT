#define LED_FLASH 9 
#define LED_1 5
#define LED_2 7
#define LED_3 6
#define T_1 2
#define T_2 3
#define T_3 8
#define TR 1   // initial response time
#define POT_PIN A0

// regulation
#define FADE_AMOUNT 5
#define MILLI 1000 // for conversion
#define FINISH 2
#define BOUNCING 150
#define MIN_INTENSITY 0
#define MAX_INTENSITY 255
#define MIN_SPEED 1
#define MAX_SPEED 4
#define FADING 22
#define BLINKING 500
#define MICRO 1000000
#define TL 1

int ledSpeed;
int count;
double rt;             // reaction time
double timeLed;
bool game_on;
unsigned long ts;
const double SEVEN = 7;
const double EIGHT = 8;
bool button1_error;
bool button2_error;
bool first_time;

  // LED_FLASH
int fadeAmount;
int currIntensity;
void ledFading();

// Button T_3
void start();

// LED_PONG
bool ledDirection; // "false" left, "true" right
bool pressed;
volatile int currentLed; // ledCurrent
void off();
void moves();
void changeDirection();
void countInc();
void finish(int led_lose,int led_win);
void delayLed();
void check_error();
void player2_win();
void player1_win();

void setup() {
  // put your setup code here, to run once:
  game_on=false;
  button1_error=false;
  button2_error=false;
  first_time=true;
  
  // FADE
  currIntensity=0;
  fadeAmount=FADE_AMOUNT;
  
  // LED_PONG
  pressed=false;
  count=0;
  rt=TR;
  timeLed=TL;
    
  pinMode(LED_FLASH, OUTPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(T_1, INPUT);
  pinMode(T_2, INPUT);
  pinMode(T_3, INPUT);

//  attachInterrupt(digitalPinToInterrupt(T_1), Button_1, RISING);
//  attachInterrupt(digitalPinToInterrupt(T_2), Button_2, RISING);

  randomSeed(analogRead(2));
  Serial.begin(9600);
  Serial.println("Welcome to Led Pong. Press Key to start");
}

void loop() {
  // put your main code here, to run repeatedly:
    
  if (game_on == false){
    ledFading();  // LED_BLINK
    start();        // CONTROL_START
  }else{
    if (currentLed==LED_2){
      if (first_time==true){
        first_time=false;
        ts = millis();
        while ((ts+(TL*MILLI))>millis()){    
        }
      }else{// DelayLed();
          delayLed();
      }
      pressed=false; 
      moves();
    }else{   
      ts = micros();
      while(((ts+(rt*MICRO))>micros())&&(pressed==false)){
        if (currentLed==LED_1){
          if (digitalRead(T_1)==HIGH){
            delay(BOUNCING);
            pressed=true;
            countInc();
            moves();
          }else if(digitalRead(T_2)==HIGH) {
            delay(BOUNCING);
            pressed=true;
            button2_error=true;
          }
        }else if (currentLed==LED_3){
          if (digitalRead(T_2)==HIGH){
            delay(BOUNCING);
            pressed=true;
            countInc();
            moves();
          }else if(digitalRead(T_1)==HIGH) {
            delay(BOUNCING);
            pressed=true;
            button1_error=true;
          }
        }
      }
      if (pressed==false){
        if (currentLed==LED_1){
          player2_win();
        }else if (currentLed==LED_3){
          player1_win();
        }
      }
    }
    if(pressed==true){ 
      check_error();
      pressed=false;
      button2_error=false;
      button1_error=false;
    }
  }
}

// LED_FLASH
void ledFading(){
  analogWrite(LED_FLASH, currIntensity);
  currIntensity = currIntensity + fadeAmount;
  if (currIntensity == MIN_INTENSITY || currIntensity == MAX_INTENSITY){
    fadeAmount = -fadeAmount;
  }
  delay(FADING);
}

// BUTTON_3
void start(){
  int buttonState3 = digitalRead(T_3);
  if (buttonState3 == HIGH) {
    delay(BOUNCING);
    game_on = true;
    int randNumber = random(2);
    if (randNumber == 1){
      ledDirection = true;
    }else{
      ledDirection = false;
    }
    currentLed=LED_2;
    ledSpeed = map(analogRead(POT_PIN), 0, 1023, MIN_SPEED, MAX_SPEED); // Range between 1 and 3, during the game SPEED increment by 1 every shot 
    Serial.println("Go!");
    currIntensity=MIN_INTENSITY;
    digitalWrite(LED_FLASH, LOW); // if necessary
    digitalWrite(LED_2,HIGH);
    button1_error=false;
    button2_error=false;
    rt=TR;
    first_time=true;
  }
}

// COUNT_INCREMENT
void countInc(){
  count++;
  ledSpeed++;
  double old_rt=rt;
  rt=old_rt*(SEVEN/EIGHT);
}

// LIGHT
void moves(){
  digitalWrite(currentLed,LOW);
  if (ledDirection == false){
    switch(currentLed){
      case(LED_2):  currentLed=LED_1;
                    break;
      case(LED_1):  changeDirection();
                    currentLed=LED_2;
                    break;
    }
   }else{    
    switch(currentLed){
      case(LED_2):  currentLed=LED_3;
                    break;
      case(LED_3):  changeDirection();
                    currentLed=LED_2;
                    break;
    }
   }
   digitalWrite(currentLed,HIGH);
}

void Button_1(){  // Not used interrupt 
  if (game_on==true){
    if (currentLed==LED_1){
      moves();
    }else{  // lose
      finish(currentLed,LED_3);
    }
  }
}

void Button_2(){   // Not used interrupt 
  if (game_on=true){
    if (currentLed==LED_3){
      moves();
    }else{
      finish(currentLed,LED_1);
    }
  }
}

void finish(int led_lose,int led_win){
  
  digitalWrite(led_lose,LOW);
  digitalWrite(LED_2,LOW);
  ts=millis();
  int i=0;
  while (i<2){
    digitalWrite(led_win, HIGH);
    delay(BLINKING);             
    digitalWrite(led_win, LOW); 
    delay(BLINKING);
    i++;
  } 
  game_on=false;
}

void changeDirection(){
  ledDirection = !ledDirection;
}

void delayLed(){
  timeLed=(((double)TL)/((double)ledSpeed));
  ts = micros();
  while (((ts+(timeLed*MICRO))>micros()) && (pressed=true)){ 
    int button1=(digitalRead(T_1));
    int button2=(digitalRead(T_2));
    if ((button1==HIGH) || (button2==HIGH)){
      pressed=true;
      delay(BOUNCING);
      if (button1==HIGH){
        button1_error=true;
      }else if (button2==HIGH){
        button2_error=true;
      }
    }
  }
  pressed=false;
}

void check_error(){
  if (button1_error==true){
    player2_win(); 
  }else if (button2_error==true){
    player1_win(); 
  }
}

void player2_win(){
  Serial.print("Game Over - The Winner is Player 2 after ");
  Serial.print(count);
  Serial.println(" shots!");
  finish(currentLed,LED_3); 
}
void player1_win(){
  Serial.print("Game Over - The Winner is Player 1 after ");
  Serial.print(count);
  Serial.println(" shots!");
  finish(currentLed,LED_1);
}
