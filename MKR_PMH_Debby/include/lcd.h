//Libraries 
#include <LiquidCrystal.h>
#include <LcdBarGraph.h>
#include <Wire.h>

//Own Headerfiles

//Variables 
byte lcdCollums = 16;
String headerLcd = "PlantMood level:";

//Objects
LiquidCrystal lcd(7, 6, 0, 1, 3, 5);   //lcd object: rs/e/db4/db5/db6/db7
LcdBarGraph lbg(&lcd, lcdCollums, 0, 1);   //Bar object: lcd/lengte bar/begin bar/second line (aanmaken met verschillende variabelen mogelijk)

//Methods setup
void lcdSetup() {
  lcd.begin(lcdCollums, 2);                               // Grootte scherm aangeven: breedte/hoogte
  lcd.setCursor(0, 0);
  lcd.print(headerLcd); 
  delay(1000);                                        // Do some delay: some time I've got broken visualization
}

//Methods 
void drawBarGraph (float moistureValue) {
  lcd.setCursor(0, 1);                                  // Plek cursor/kolom
  lbg.drawValue(moistureValue, 1023);                     // Waarde die getekend moet worden/100%


}