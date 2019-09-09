//Senses Platform with DHT
#include <DHT.h>
#include "Senses_wifi.h"

//Change here if use others pin / dht model
#define DHTPIN 5
#define DHTTYPE DHT22

#define SEND_DELAY 10000

DHT dht(DHTPIN, DHTTYPE);

//Change these setting before upload to board
const char *ssid = "your-wifi-network-name";
const char *passw = "your-wifi-password";
const char *userid = "your-senses-user-id";
const char *key = "your-device-key";
int slot = 1;

String response;
Senses_wifi myiot;

void setup(){
  Serial.begin(9600);
  Serial.println(F("SENSES Platform with DHT"));
  dht.begin();
  
  response = myiot.connect(ssid, passw, userid, key);
  Serial.println(response);
}

void loop(){
  myiot.send(slot, dht.readTemperature());
  //Uncommment to do something fun
  //myiot.send(2, dht.readHumidity());
  Serial.println(F("Send data to SENSES Platform"));
  delay(SEND_DELAY);
}
