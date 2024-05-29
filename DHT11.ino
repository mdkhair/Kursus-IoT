#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "XXXXXXXXXXXx"
#define BLYNK_TEMPLATE_NAME "XXXXXXXXXXXx"
#define BLYNK_AUTH_TOKEN "XXXXXXXXXXXx"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// WiFi credentials
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

BlynkTimer timer;

// This function sends Arduino's up time every second to Virtual Pin (V5) and (V6).
void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Push data to Blynk app on virtual pins
  Blynk.virtualWrite(V5, t);
  Blynk.virtualWrite(V6, h);
}

void setup()
{
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  dht.begin();

  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
}
