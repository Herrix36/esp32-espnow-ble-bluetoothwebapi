# Ablauf Skizze

Übersicht über die einzelnen verwendeten Komponente und Technoligien und Protokolle

## Ablauf

[DHT11 Sensor]
     │
     ▼
[ESP32-C3]
(GPIO 5)
     │  (liest Temperatur & Feuchtigkeit)
     ▼
(ESPNOW)
     │
     ▼
[ESP32]
     │  (empfängt Daten via ESPNOW, versendet Daten via BLE)
     ▼
(BLE)
     │  
     ▼
[Bluetooth Web API / App] (empfängt Daten via BLE, stellt Daten in Weboberfläche dar)


### Schaltplan (DHT11 -> C3)

 +-----------+
       |   DHT11   |
       |           |
       |  VCC  ───┐
       |  GND  ──┐│
       |  DATA ──┘│
       +-----------+
            │
            │ DATA
            │
           GPIO5
            │
       +-----------+
       |  ESP32-C3 |
       |           |
       |   GND     ────── GND
       |   3.3V    ────── VCC DHT11
       +-----------+


#### Steckbrett

- in `/assets` befindet sich ein Bild des verwendetet Steckbretts und den Verkabelungen
