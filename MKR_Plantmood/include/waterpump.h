//Libraries 
#include <SPI.h>

//Variables 
int waterPin = 12; 
int onTimeWaterpump = 5000;
const String textWaterpump = "Finally i'm getting a drink!";

//Methods setup
void waterpumpSetup() {
  pinMode(12, OUTPUT); 
  digitalWrite(12, LOW);
}

//Methods 
void waterpumpOnAndOff() {
    Serial.println(textWaterpump);
      digitalWrite(12, HIGH);
      delay(onTimeWaterpump);                
      digitalWrite (12, LOW); 
}