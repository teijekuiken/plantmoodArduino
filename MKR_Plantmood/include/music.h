//Libraries 
#include <AudioZero.h>
#include <SD.h>

//Variables
String wetSong = "wet.wav";
String aliveSong = "alive.wav";
String drySong = "dry.wav";

String wetText = "I'm drowning :(";
String aliveText = "I'm alive :)";
String dryText = "I'm thirsty!";

String wetTextSong = "You're listening to the wet song";
String aliveTextSong = "You're listening to the alive song";
String dryTextSong = "You're listening to the dry song";
String endText = "End of the song";

//Objects
File file;

//Methods setup
void musicSetup() {
    Serial.println("Initializing SD card...");
  if (!SD.begin(4)) {
    Serial.println("SD card failed!");
    while(true);
  }
  Serial.println("SD card is ok");
}

//Methods 
void playWetSong() {
  AudioZero.begin(16000); 
  Serial.println(wetText);
  file = SD.open(wetSong); 
  Serial.println(wetTextSong);
  AudioZero.play(file);
  AudioZero.end(); 
  Serial.println(endText);  
}

void playAliveSong() {
  AudioZero.begin(16000); 
  Serial.println (aliveText);
  file = SD.open(aliveSong);
  Serial.println(aliveTextSong);
  AudioZero.play(file);
  AudioZero.end(); 
  Serial.println(endText);
}

void playDrySong() {
  AudioZero.begin(16000); 
  Serial.println(dryText);
  file = SD.open(drySong);
  Serial.println(dryTextSong);
  AudioZero.play(file);
  AudioZero.end(); 
  Serial.println(endText);
}