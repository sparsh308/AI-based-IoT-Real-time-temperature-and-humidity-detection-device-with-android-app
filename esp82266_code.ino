
#include <ArduinoJson.h>
#include <FirebaseArduino.h>
#include <DHT.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
// Set these to run example.
#define FIREBASE_HOST "HOST_NAME"
#define WIFI_SSID "*****"
#define WIFI_PASSWORD "******"


const int DHTPIN = D3;

#define DHTTYPE DHT22

DHT dht(DHTPIN,DHTTYPE);

void setup() {
  Serial.begin(9600);
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
 dht.begin();
 Serial.print("");
  Serial.print("WIFI_connected: ");
 Firebase.begin(FIREBASE_HOST);
 WiFi.softAPdisconnect (true);

}
void loop() {
 float h=dht.readHumidity();//to read humidity from sensor
 float t=dht.readTemperature();// to read temperature from sensor
 Firebase.setFloat("TEMP",t);
 Firebase.setFloat("Temp",t);
 Firebase.setFloat("HUMIDITY",h);
 Firebase.setFloat("Humidity",h);
 Serial.print(t); 
 Serial.print(h);
}
