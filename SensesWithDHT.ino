#include <DHT.h>
#include "Senses_wifi.h"

#define DHTPIN 5
#define DHTTYPE DHT22

#define SEND_DELAY 10000

DHT dht(DHTPIN, DHTTYPE);

const char *ssid = "your-wifi-network-name";
const char *passw = "your-wifi-password";
const char *userid = "your-senses-user-id";
const char *key = "your-device-key";

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
  myiot.send(1, dht.readTemperature());
  myiot.send(2, dht.readHumidity());
  Serial.println(F("Send data to SENSES Platform"));
  delay(SEND_DELAY);
}
