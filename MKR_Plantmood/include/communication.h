//Libraries
#include <PubSubClient.h>

//Own headerfiles 
#include <wifi.h>
#include <moistureSensor.h>
#include <music.h>
#include <lcd.h>
#include <waterpump.h>

//Variables 
const char* arduinoSn = "TestArduino"; 
const int defaultportMosquitto = 1883; 

const char* pubTopic = "Plantmood/AllPlantMoods/Data";
String subTopic = String("Plantmood/"+String(arduinoSn)+"/Mood");

long currentTime, lastTime;

int currentMoistureValue;

char newMessage[30];                                          

//Objects 
PubSubClient mqttClient(wifiClient); 

//Methods setup
void commSetup() {
  mqttClient.setServer(server, defaultportMosquitto);    
}  

//Methods 
void connToMqttBroker() {
    while (!mqttClient.connected()) {
    Serial.println("Connecting to MQTT server...");
    if (mqttClient.connect(arduinoSn)) {
      Serial.println("Connected to MQTT server");
      mqttClient.subscribe(subTopic.c_str());
      Serial.println("Subscribed to topic " + subTopic);
    } else {
      Serial.print("failed with state: ");
      Serial.print(mqttClient.state());
      delay(2000); }
    }
}

void pubMessage() {
  currentTime = millis();

  if(currentTime - lastTime > 20000){
    //1. Sensorwaarde berekenen
    currentMoistureValue = moistureMeassurement();
    Serial.print("Sensorwaarde is: ");                    
    Serial.println(currentMoistureValue);
    mqttClient.publish(pubTopic, String(String (arduinoSn) +"," +String(currentMoistureValue)).c_str());
    Serial.println("Message published");
    lastTime = millis();
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);

  for (int i = 0; i<length; i++) {
    newMessage[i] = (char)payload[i];                           
  }
  newMessage[length] = '\0';
   
  Serial.print("Message: ");
  Serial.println (newMessage);
  
  //2. Vul de bar graph (CurrentMoistureValue in percantage omgezet)
  drawBarGraph(currentMoistureValue);

  //3. Liedje afspelen aan de hand van de STATUS en eventueel water geven 
  if (strcmp(newMessage, "WET") == 0) {
      playWetSong();
    } else if (strcmp(newMessage, "ALIVE") == 0) {
      playAliveSong();
    } else if (strcmp(newMessage, "DRY") == 0) {
      waterpumpOnAndOff();
      playDrySong();
    } else {
      Serial.println("Ik kan niks met dit bericht");
    }
}