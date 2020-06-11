//Variables 
#define sensorPin A1              
float moistureRead;
int moistureValue;

//Methods 
int moistureMeassurement () {
  for (int i = 0; i <= 100; i++)                        
  {                                                     
   moistureRead = moistureRead + analogRead(sensorPin);   
   delay(1);                                            
  }                                                     
  moistureRead = moistureRead/100.0;  
  nearbyint (moistureValue);                //
  moistureValue = static_cast<int>(moistureRead);
    return moistureValue;
} 
