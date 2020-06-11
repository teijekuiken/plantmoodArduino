//Libraries 

//Own Headerfiles

//Variables 
#define sensorPin A1              // Analoge pin 
float moistureValue;

//Objects

//Methods setupX

//Methods 
float moistureMeassurement () {
  for (int i = 0; i <= 100; i++)                        // Meet 100 keer en deelt door 100 om 1 waarde te berekenen 
  {                                                     //
   moistureValue = moistureValue + analogRead(sensorPin);   // ????????????????????????????????????????????????????????????????? er stond sensorValue = sensorValue + analogRead(SensorPin);
   delay(1);                                            //
  }                                                     //
  moistureValue = moistureValue/100.0;                      //
    return moistureValue;
} 