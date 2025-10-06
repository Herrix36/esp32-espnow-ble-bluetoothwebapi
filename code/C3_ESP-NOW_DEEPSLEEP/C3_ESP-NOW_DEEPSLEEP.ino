#include <DHT.h>
#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>
#include <esp_sleep.h>

#define DHTPIN 5
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// Struktur für Sensordaten
typedef struct struct_message {
  float temperature;
  float humidity;
} struct_message;

struct_message dhtData;

// MAC-Adresse des Empfängers
uint8_t broadcastAddress[] = {0x24, 0x6F, 0x28, 0x0A, 0xFD, 0x5C};

// Callback, wenn Daten gesendet wurden
void OnDataSent(const wifi_tx_info_t *mac_addr, esp_now_send_status_t status) {
  // optional: Serial Debug
  // Serial.print("Sendestatus: ");
  // Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Erfolgreich" : "Fehlgeschlagen");
}

void setup() {
  // Optional für Debug
  Serial.begin(115200);
  delay(100);

  dht.begin();

  // WLAN + Kanal für ESP-NOW
  WiFi.mode(WIFI_STA);
  esp_wifi_set_channel(1, WIFI_SECOND_CHAN_NONE);

  // ESP-NOW initialisieren
  if (esp_now_init() != ESP_OK) {
    esp_deep_sleep_start(); // sofort schlafen, wenn init fehlschlägt
  }

  esp_now_register_send_cb(OnDataSent);

  // Empfänger hinzufügen
  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 1;
  peerInfo.encrypt = false;
  esp_now_add_peer(&peerInfo);

  // Messwerte auslesen
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  // In die Struktur packen
  dhtData.temperature = t;
  dhtData.humidity = h;

  // Senden
  esp_now_send(broadcastAddress, (uint8_t*)&dhtData, sizeof(dhtData));

  // Optional Serial Debug
  Serial.print("📡 Gesendet: ");
  Serial.print(t); Serial.print(" °C, ");
  Serial.print(h); Serial.println(" %");

  delay(100); // kurz warten für Serial

  // Deep-Sleep für 10 Sekunden
  esp_sleep_enable_timer_wakeup(10 * 1000000);
  esp_deep_sleep_start();
}

void loop() {
  // bleibt leer, alles passiert in setup()
}