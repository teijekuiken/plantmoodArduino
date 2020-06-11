//Libraries 
#include <LiquidCrystal.h>
#include <LcdBarGraph.h>
#include <Wire.h>

//Variables 
byte lcdCollums = 16;
String headerLcd = "PlantMood level:";

//Objects
LiquidCrystal lcd(7, 6, 0, 1, 3, 5);
LcdBarGraph lbg(&lcd, lcdCollums, 0, 1);

//Methods setup
void lcdSetup() {
  lcd.begin(lcdCollums, 2);
  lcd.setCursor(0, 0);
  lcd.print(headerLcd); 
  delay(1000);
}

//Methods 
void drawBarGraph (int moistureValue) {
  lcd.setCursor(0, 1);
  lbg.drawValue(moistureValue, 1023);
}