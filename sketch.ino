#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

// Définition des broches
#define DHTPIN 4
#define DHTTYPE DHT22
#define POTENTIOMETER_PIN 34
#define TRIGGER_PIN 26
#define ECHO_PIN 27

// Wi-Fi credentials
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// MQTT Broker
const char* mqtt_server = "broker.emqx.io";
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(115200);
  }

void loop() {
    delay(5000);
}