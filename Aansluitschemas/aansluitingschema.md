# Aansluitschema – Automatische plantenbewatering

## 1. Gebruikte onderdelen

- Arduino UNO R4 WiFi
- Keyestudio motordriver-shield
- DHT11 temperatuur- en luchtvochtigheidssensor
- Bodemvochtigheidssensor (moisture sensor)
- Waterpomp
- Batterij of externe voeding
- Verbindingsdraden

## 2. Aansluitingen van de sensoren

| Onderdeel     | Aansluiting | Arduino        |
|---------------|-------------|----------------|
| DHT11         | VCC         | 5V             |
| DHT11         | DATA        | Digitale pin 2 |
| DHT11         | GND         | GND            |



| Onderdeel               | Aansluiting          | Arduino        |
|-------------------------|----------------------|----------------|
| Bodemvochtigheidssensor | VCC                  | 3.3V           |
| Bodemvochtigheidssensor | Analoge uitgang (AO) | A0             |
| Bodemvochtigheidssensor | GND                  | GND            |


Beide sensoren zijn aangesloten op GND van de Arduino.

## 3. Aansluitingen van de motordriver

De Keyestudio motordriver-shield is boven op de Arduino UNO R4 WiFi geplaatst.

| Functie | Arduino-aansluiting |
|---------|---------------------|
| DIR     | Digitale pin 12     |
| PWM     | Digitale pin 3      |
| BRAKE   | Digitale pin 9      |


## 4. Aansluiting van de waterpomp

De waterpomp is aangesloten op de motoraansluitingen van het drivershield.

| Aansluiting | Waterpomp |
|-------------|-----------|
| A1          | Plus (+)  |
| A2          | Min (-)   |


## 5. Voeding van de motordriver en waterpomp

Het motordrivershield wordt gevoed via een batterij. Er kan ook een externe voeding worden gebruikt.

**Belangrijke veiligheidsregel:**
- Het motordrivershield kan geen hogere input hebben dan 18V

## 6. Werking van het systeem

De DHT11 meet de temperatuur en luchtvochtigheid van de omgeving. De bodemvochtigheidssensor meet hoeveel vocht er in de potgrond aanwezig is.

De Arduino UNO R4 WiFi leest de sensoren uit en verstuurt de meetgegevens via wifi naar Home Assistant.

Home Assistant controleert de bodemvochtigheid. Wanneer de grond te droog is, stuurt Home Assistant een opdracht naar de Arduino om de waterpomp in te schakelen.

Wanneer de grond voldoende vochtig is, wordt de waterpomp weer uitgeschakeld.

De motordriver zorgt ervoor dat de Arduino de waterpomp kan aansturen.