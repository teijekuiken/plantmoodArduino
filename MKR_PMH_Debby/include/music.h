//Libraries 
#include <AudioZero.h>
#include <SD.h>

//Own Headerfiles

//Variables
File file;
String wetSong = "hands.wav";
String happySong = "rob.wav";
String drySong = "moon.wav";

int limitWet = 900;
int limitDry = 400;

String wetText = "Ik verdrink! Geef mij geen water meer :(";
String happyText = "Ik ben happy :)";
String dryText = "Zet die waterpomp eens aan, ik heb dorst!";

String wetTextSong = "Je luistert naar Slow Hands";
String happyTextSong = "Je luistert naar De Mol";
String dryTextSong = "Je luistert naar Shup up and Dance with Me";
String endText = "Einde van het liedje";

//Objects

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

void playHappySong() {
  AudioZero.begin(16000); 
  Serial.println (happyText);
  file = SD.open(happySong);
  Serial.println(happyTextSong);
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