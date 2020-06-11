
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