#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "XXXXXXXXXX"
#define BLYNK_TEMPLATE_NAME "XXXXXXXX"
#define BLYNK_AUTH_TOKEN "XXXXXXXXXXXXX"


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// WiFi credentials
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

// This function will be called every time device receives command from Blynk App
BLYNK_WRITE(V0) {
  int pinValue = param.asInt(); 
  digitalWrite(22, pinValue); 
}

void setup()
{
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(22, OUTPUT); 
}

void loop()
{
  Blynk.run();
}
