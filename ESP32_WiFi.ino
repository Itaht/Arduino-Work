#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL6q_qt0FCb"
#define BLYNK_TEMPLATE_NAME "LED"
#define BLYNK_AUTH_TOKEN "Y_BcONFZqP4jQVM6KWAGFBvmv95hGbDb"


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>

char ssid[] = "WIFI_NAME"; //wifi_name
char pass[] = "WIFI_PASSWORD"; //wifi_password

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

BLYNK_WRITE(V0){
  if(param.asInt()==1){
    digitalWrite(ledPin, HIGH);
  }else{
    digitalWrite(ledPin, LOW);
  }
}

void loop()
{
  Blynk.run();
}

