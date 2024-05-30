#include <WiFi.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.

const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* mqtt_server = "test.mosquitto.org";

WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE  (50)
char msg[MSG_BUFFER_SIZE];
int value = 0;

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(String topic, byte* payload, unsigned int length) {
  String fullpayload;
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
    fullpayload += (char)payload[i];
  }
  Serial.println();
  if (topic == "khairled1")
  {
    if(fullpayload == "on")
    {
      digitalWrite(22,HIGH);
    }
    if(fullpayload == "off")
    {
      digitalWrite(22,LOW);
    }
  }
    if (topic == "khairled2")
  {
    if(fullpayload == "on")
    {
      digitalWrite(21,HIGH);
    }
    if(fullpayload == "off")
    {
      digitalWrite(21,LOW);
    }
  }
    if (topic == "khairled3")
  {
    if(fullpayload == "on")
    {
      digitalWrite(23,HIGH);
    }
    if(fullpayload == "off")
    {
      digitalWrite(23,LOW);
    }
  }
    if (topic == "khairled4")
  {
    if(fullpayload == "on")
    {
      digitalWrite(19,HIGH);
    }
    if(fullpayload == "off")
    {
      digitalWrite(19,LOW);
    }
  }
    if (topic == "khairled5")
  {
    if(fullpayload == "on")
    {
      digitalWrite(18,HIGH);
    }
    if(fullpayload == "off")
    {
      digitalWrite(18,LOW);
    }
  }
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("outTopic", "hello world");
      // ... and resubscribe
      client.subscribe("khairled1");
      client.subscribe("khairled2");
      client.subscribe("khairled3");
      client.subscribe("khairled4");
      client.subscribe("khairled5");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  pinMode(22,OUTPUT);
  pinMode(23,OUTPUT);
  pinMode(21,OUTPUT);
  pinMode(19,OUTPUT);
  pinMode(18,OUTPUT);
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  unsigned long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;
    ++value;
  }
}

