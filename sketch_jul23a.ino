#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>


char ssid[] = "########"; //WIFI_NAME
char pass[] = "#######"; //WIFI_PASSWORD

#define BLYNK_TEMPLATE_ID "TMPL6bLv_Oy_0"
#define BLYNK_TEMPLATE_NAME "w1"
#define BLYNK_AUTH_TOKEN "xn0YmeVc8PdgVFEM0SecTDjfPw28GKtk"

int LED = (27);

void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(LED, OUTPUT);
}

BLYNK_WRITE(V0)
{
  if(param.asInt()==1)
  {
    digitalWrite(LED, HIGH);
    Serial.print("LED ON");
  }
  else{
    digitalWrite(LED, LOW);
    Serial.print("LED OFF");
  }
}

void loop()
{
  Blynk.run();
}

