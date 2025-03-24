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

    dht.begin();
    pinMode(POTENTIOMETER_PIN, INPUT);
    pinMode(TRIGGER_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

void loop() {

    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();
    int vibration = analogRead(POTENTIOMETER_PIN);
    float fissure = readDistance();

    // Conversion et affichage
    Serial.print("Température: "); Serial.println(temperature);
    Serial.print("Humidité: "); Serial.println(humidity);
    Serial.print("Vibrations: "); Serial.println(vibration);
    Serial.print("Taille fissure: "); Serial.println(fissure);

    delay(5000);
}