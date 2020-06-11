//Libraries

//Own headerfiles
#include <wifi.h>
//Variables 
const int mampPort = 8888; 

//Objects

//Methods setup

//Methods 
void writetoMAMP (float moistureValue) {
if (wifiClient.connect(server, mampPort)) {              
    wifiClient.print("GET /write_data.php?");       // We are making a GET request just like we would from our browser but now with live data from the sensor
    wifiClient.print("value=");                     //
    wifiClient.print(moistureValue);                  //
    wifiClient.println(" HTTP/1.1");                // Part of the GET request
    wifiClient.println("Host: 192.168.11.60");      // If you are using MAMP you will have to find out the IP address of your computer and put it here. Web page: (ie.Host: "www.yourwebpage.com"
    wifiClient.println("Connection: close");        // Part of the GET request telling the server that we are over transmitting the message
    wifiClient.println();                           // Empty line
    wifiClient.println();                           // Empty line
    wifiClient.stop();                              // Closing connection to server
  }
  else {
    Serial.println("Connection to MAMP failed\n");
  }
 
  delay(10000);  // ???????????????????????????????? echt nodig? Give the server some time to recieve the data and store it. I used 10 seconds here. Be advised when delaying. If u use a short delay, the server might not capture data because of Arduino transmitting new data too soon.
}