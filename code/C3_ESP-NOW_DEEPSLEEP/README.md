# ESP32C3 - Deepsleep

- ESP32C3 geht in den Deepsleep, solange keine Daten des DHT11 ausgelesen werden

## Verwendete Hardware Technologien

- ESP32C3 (Sender)
- ESPNOW (Senden)


### Schnellstart

- ESP32C3 flashen und die Verbindung mit dem ESP32 als Empfänger testen

#### To-Do

- Der ESP32C3 soll erst aus dem Deepsleep geholt werden, wenn die Messwerte des DHT11 sich ändern
- Ergänzung weiterer Sensoren
(- Empfangen und Verarbeiten von Nachrichten (C3 als Empfänger und Sender))
