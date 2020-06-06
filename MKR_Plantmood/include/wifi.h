//Libraries
#include <WiFi101.h>

//Own headerfiles 
#include <secrets.h>

//Variables  
int statusWifi = WL_IDLE_STATUS; 

//Objects 
IPAddress server(192,168,11,60);
WiFiClient wifiClient;

//Methods setup
void wifiSetup() {
  Serial.println("Attempting to connect to the network...");
  Serial.print("Network name: ");
  Serial.println(SECRET_SSID);

  statusWifi = WiFi.begin(SECRET_SSID, SECRET_PASS);
  if (statusWifi != WL_CONNECTED) { 
    Serial.println("Couldn't get a wifi connection");
    while(true);
  } 
  else {
    Serial.println("Connected to wifi");
  }
}
