#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "XXXXXXXXXXXXx"
#define BLYNK_TEMPLATE_NAME "XXXXXXXXXXXXx"
#define BLYNK_AUTH_TOKEN "XXXXXXXXXXXXx"


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// WiFi credentials
char ssid[] = "Wokwi-GUEST";
char pass[] = "";


BlynkTimer timer;

void sendPotValue() {
  int potValue = analogRead(35);  // Read the potentiometer
  Blynk.virtualWrite(V2, potValue);  // Send pot value to Blynk on V2
}

void setup()
{
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(35, INPUT);
  timer.setInterval(500L, sendPotValue);
}

void loop()
{
  Blynk.run();
  timer.run(); 
}
