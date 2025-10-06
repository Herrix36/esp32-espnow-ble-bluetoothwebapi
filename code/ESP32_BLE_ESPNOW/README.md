# BLE und ESPNOW auf dem ESP32
- ESP32 empfängt Daten über ESPNOW, speichert diese zwischen und verschickt sie über Bluetooth an einen Client
- ESPNOW sendet nurnoch auf einem Kanal und BLE hat alle 37 Kanäle zum Versenden von Daten zur Verfügung, damit Koliisionen und Verbindungsprobleme vermieden werden. Das Scheduling der ESP32 Firmware regelt den Zugriff auf den Kanal.

## Verwendete Hardware und Technologien
- ESP32
- ESP32C3 und Bluetooth-Empfänger zum Testen
- BLE
- ESPNOW

### Schnellstart 
- ESP32 flashen und starten (ESP32C3 als Sender und Web Bluetooth API als Empfänger)


