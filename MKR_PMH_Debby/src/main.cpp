/*
Documentation from 25th of March because I switched from IDE
VERSIE   DATUM      AANPASSINGEN 
0.1      03.25.20   Basic pub communication, lcd, moistureSensor, music, secrets, waterpump, wifi
0.2      04.06.20   Callback function, sub topic, update music library
0.3      04.07.20   Subcribe probleem na verbinding opgelost, submessage() weggehaald
0.4      04.08.20   Callback hele string vergelijking ipv alleen eerste letter

Comments
httpRequest library was used to write through an php script into the database 

Ideeen 
Bij opnieuw laden code kijken of je een pin standaard uit kan zetten 

Debby 
*/

//Libraries 
#include <Arduino.h>
#include <SPI.h>

//Own headerfiles
#include <communication.h> 

//Variables

//Objects

void setup() {
  Serial.begin(115200);
  while (!Serial);
  waterpumpSetup();
  wifiSetup();
  commSetup();
  connToMqttBroker();
  musicSetup();
  lcdSetup();
  mqttClient.setCallback(callback);
}

void loop() {
  // 1. Check verbinding met mqtt server
  if(!mqttClient.connected()) {
    connToMqttBroker();
  }

  //2. Publish message iedere 20000 milliseconden
  pubMessage();

  //3. Loop om messages te chekken bij de mqtt server
  mqttClient.loop();

  
}