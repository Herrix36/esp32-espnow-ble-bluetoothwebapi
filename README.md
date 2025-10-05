# DHT11/ESP32-C3 -> ESPNOW -> ESP32 -> BLE -> Web Bluetooth API

Dieses Projekt demonstriert, wie Sensordaten des DHT11 über ESPNOW zu einem zweiten ESP32 übertragen und anschließend per Bluetooth (BLE) an eine Web Bluetooth API weitergegeben werden.

## Verwendete Hardware und Technologien

- DHT11 (Sensor)
- Seeed XIAO ESP32-C3 (Sender)
- ESP32 Dev-Kit (Empfänger)
- ESPNOW (Protokoll zur Kommunikation zwischen ESPs)
- Bluetooth Low Energy (BLE - Protokoll zur Kommunikation zwischen ESP32 und der Web Bluetooth API)
- Google Chrome Web Bluetooth API (JavaScript)

### Projektstruktur

- `assets/`                     : 
- `code/esp32_c3/`              : ESP32-C3 Code zum Auslesen des des DHT11 und Versenden der Messwerte über ESPNOW
- `code/esp32/`                 : ESP32 Code zum Empfangen der Daten des C3 über ESPNOW und Weiterleiten der Daten über BLE
- `code/web-bluetooth-api/`     : html-Webseite zur Anzeige der Sensordaten via Web Bluetooth
- `docs/`                       : Vollständige technische Ausarbeitung als pdf, Kurzfassung als markdown

## Schnellstart
1. Kompilieren / flashen der jeweiligen Module in `code/`.
2. Browser öffnen `web/index.html` und mit BLE verbinden.

#### Sonstiges

Das Projekt ist noch in Arbeit und wird erweitert, sobald ich wieder Zugang zu einem ESP32 Dev-Kit habe.




