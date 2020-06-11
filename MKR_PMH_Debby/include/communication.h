//Libraries
#include <PubSubClient.h>

//Own headerfiles 
#include <wifi.h>
#include <moistureSensor.h>
#include <music.h>
#include <lcd.h>
#include <waterpump.h>

//Variables 
const char* plantMood_ID = "PMH_Debby"; 
const int defaultportMosquitto = 1883; 

const char* pubTopic = "PlantMood/PMDebby/PubTopicArduino";
const char* subTopic = "PlantMoodDebby/SubTopicArduino";

long currentTime, lastTime;

float currentMoistureValue; 
                                                              //0. payload omzetten naar een string -lijst van chars- om strings te kunnen vergelijken voor het afspelen van een liedje
char newMessage[30];                                          //1. char array met max 30 slots 

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
    if (mqttClient.connect(plantMood_ID)) {
      Serial.println("Connected to MQTT server");
      mqttClient.subscribe(subTopic);
      Serial.println("Subscribed to topic");
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
    mqttClient.publish(pubTopic, String(String (plantMood_ID) +", " +String(currentMoistureValue)).c_str());
    Serial.println("Message published");
    lastTime = millis();
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);

  for (int i = 0; i<length; i++) {
    newMessage[i] = (char)payload[i];                            //2. Kopieer ieder slot van de payload in newMessage
  }
  newMessage[length] = '\0';                                     //3. Laatste element moet dit zijn zodat bekend wordt dat alles ervoor een string moet worden
   
  Serial.print("Message: ");
  Serial.println (newMessage);
  
  //2. Vul de bar graph (CurrentMoistureValue in percantage omgezet)
  drawBarGraph(currentMoistureValue);

  //3. Liedje afspelen aan de hand van de STATUS en eventueel water geven 
  if (strcmp(newMessage, "Nat") == 0) {                               //4. Manier om 2 strings met elkaar te vergelijken. argumenten zijn const char* en const char*. Als ze gelijk zijn geeft de methode 0 terug
      playWetSong();
    } else if (strcmp(newMessage, "Happy") == 0) {
      playHappySong();
    } else if (strcmp(newMessage, "Droog") == 0) {
      waterpumpOnAndOff();
      playDrySong();
    } else {
      Serial.println("Ik kan niks met dit bericht");
    }
}