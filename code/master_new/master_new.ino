// Include Arduino Wire library for I2C
#include <Wire.h>
#include <ESP8266WiFi.h> // ESP8266WiFi.h library
 
// Define Slave I2C Address
#define SLAVE_ADDR 9

const char* ssid     = "AndroidAPA7BC";// replace subscribe with your WiFi SSID(Name)
const char* password = "9913481501";//replace with Your Wifi Password name
const char* host = "api.thingspeak.com";
const char* writeAPIKey = "CTJZZYPK9PSWRPKZ"; //copy yout ThingSpeak channel API Key.
//const char* writeAPIKey2 = "IH7U8353D4FUVQ1V"; //copy yout ThingSpeak channel API Key. 

// Define counter to count bytes in response
int bcount;
 
// Define array for return data
int tankreading[13];
 
void setup()
{
  Wire.begin(D2, D1);
  Serial.begin(9600);
  Serial.println("Connecting to ");
       Serial.println(ssid);
//  Connect to WiFi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
   Serial.println("");
   Serial.println("WiFi connected");
}
 
int readI2C(int address) {
  // Define a variable to hold byte of data
  int16_t bval ;
  byte a,b;
  long entry = millis();
  // Read one byte at a time
  Wire.requestFrom(address,2); 
  // Wait 100 ms for data to stabilize
  while (Wire.available() == 0 && (millis() - entry) < 100)  Serial.print("Waiting");
  // Place data into byte
  if  (millis() - entry < 100) 
  a = Wire.read();
  b = Wire.read();
  bval = a;
  bval = bval << 8 | b;
  return bval;
}
 
void loop()
{
  
  while (readI2C(SLAVE_ADDR) < 255) {
  // Until first byte has been received print a waiting message
    Serial.print("Waiting"); 
  }
  for (bcount = 0; bcount < 13; bcount++) {
    tankreading[bcount] = readI2C(SLAVE_ADDR);
  }
  
  for (int i = 0; i < 13; i++) {
    Serial.print("tank");
    Serial.print(i+1);
    Serial.print(":");
    Serial.println(tankreading[i]);
    //Serial.print("\t");
  }
  Serial.println("Send to ThingSpeak.\n");
  // make TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    return;
  }

  String url = "/update?key=";
  url+=writeAPIKey;
  url+="&field1=";
  url+=String(tankreading[0]);
  url+="&field2=";
  url+=String(tankreading[1]);
  url+="&field3=";
  url+=String(tankreading[2]);
  url+="&field4=";
  url+=String(tankreading[3]);
  url+="&field5=";
  url+=String(tankreading[4]);
  url+="&field6=";
  url+=String(tankreading[5]);
  url+="&field7=";
  url+=String(tankreading[6]);
  url+="&field8=";
  url+=String(tankreading[7]);
  url+="\r\n";

  //String url2 = "/update?key=";
  //url2+=writeAPIKey2;
  //url2+="&field1=";
  //url2+=String(tankreading[8]);
  //url2+="&field2=";
  //url2+=String(tankreading[9]);
  //url2+="&field3=";
  //url2+=String(tankreading[10]);
  //url2+="&field4=";
  //url2+=String(tankreading[11]);
  //url2+="&field5=";
  //url2+=String(tankreading[12]);
  //url2+="\r\n";
  
  // Request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
  client.stop();
// Request to the server
 // client.print(String("GET ") + url2 + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
//client.stop();
  Serial.println("Wait for 10 min. to update next datapack in thingSpeak");
  delay(600000);
}
