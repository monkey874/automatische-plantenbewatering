# Automatisch plantenbewateringssysteem
Voor het keuzedeel Microcontrollers ben ik van plan om een automatisch plantenbewateringssysteem te bouwen. Ik heb namelijk regelmatig na mijn vakantie gemerkt dat mijn planten zijn gestorven. Ik hoop dat ik met dit systeem ervoor kan zorgen dat mijn planten tijdens mijn afwezigheid voldoende water krijgen.

- **Gemaakt door:** Rick Salden
- **Onderwerp:** Voorbereidingsdocument
- **Datum:** 12-11-2026

---

# Inhoudsopgave

- [Onderzoek hardware](#onderzoek-hardware)
    - [Lijst met hardware](#lijst-met-hardware)
    - [Gekozen hardware](#gekozen-hardware)
- [Benodigde software](#benodigde-software)
- [Benodigde documenten en componenten](#benodigde-documenten-en-componenten)
- [Ontwikkelmethode](#ontwikkelmethode)
- [Planning](#planning)

---

# Onderzoek hardware
Omdat ik van plan ben om een plantenbewateringssysteem te bouwen, heb ik verschillende onderdelen nodig. Ik heb onderdelen nodig om de temperatuur en luchtvochtigheid te meten, maar ook apparatuur om de grondvochtigheid te meten. Daarnaast heb ik een pomp nodig die water kan verplaatsen. Als laatste heb ik een besturingsbord nodig waarop ik alles kan aansluiten en samen kan laten werken. Hieronder heb ik een lijst gemaakt van onderdelen die hiervoor geschikt zijn.

## Lijst met hardware

### 1. Temperatuur en luchtvochtigheid
- DHT11-sensor
- DHT22-sensor
- BME280-sensor
- SHT31-sensor

| **Sensor**   | **Temperatuur** | **Luchtvochtigheid** | **Extra** | **Pinnen** | **Kosten** |
|--------------|-----------------|----------------------|-----------|------------|------------|
| DHT11-sensor | X               | X                    | _         | 3          | €2 - €3    |
| DHT22-sensor | X               | X                    | _         | 3          | €3 - €6    |
| BME280-sensor| X               | X                    | X         | 4          | €4,50 - €7 |
| SHT31-sensor | X               | X                    | _         | 4          | €10 - €23  |

#### DHT11-sensor
De DHT11-sensor is een goedkope sensor waarmee je de temperatuur en luchtvochtigheid kunt meten. Het is geen supernauwkeurige sensor. Het temperatuurbereik ligt tussen de 0 en 50 graden Celsius. De luchtvochtigheidssensor heeft een bereik van 20 tot 80%. Voor kleine tests is dit meer dan genoeg.Sommige DHT11-sensoren hebben vier pinnetjes, maar er zijn ook uitvoeringen met drie pinnen. Deze hebben meestal een ingebouwde weerstand die bij een losse sensor met vier pinnen mogelijk apart nodig is.

Een DHT11-sensor met drie pinnen heeft een GND-, VCC- en DATA-pin:
- **GND:** De aardingspin.
- **VCC:** De voedingsspanning.
- **DATA:** De datapin voor het versturen van gegevens.

Een DHT11-sensor met vier pinnen heeft een GND-, VCC-, DATA- en NC-pin:
- **GND:** De aardingspin.
- **VCC:** De voedingsspanning.
- **DATA:** De datapin voor het versturen van gegevens.
- **NC:** Een ongebruikte aansluiting. Deze sluit je niet aan.

#### DHT22-sensor
De DHT22-sensor is ook een relatief goedkope sensor, maar het is een verbeterde versie van de DHT11-sensor. Deze sensor kan zowel hogere als lagere temperaturen meten en is een stuk nauwkeuriger. Het temperatuurbereik ligt tussen de -40 en 80 graden Celsius. Ook heeft de luchtvochtigheidssensor een breder bereik. In plaats van het bereik van de DHT11 kan deze sensor van 0 tot 100% meten. Sommige DHT22-sensoren hebben vier pinnetjes, maar er zijn ook uitvoeringen met drie pinnen. Deze hebben meestal een ingebouwde weerstand die bij een losse sensor met vier pinnen mogelijk apart nodig is.

Een DHT22-sensor met drie pinnen heeft een GND-, VCC- en DATA-pin:
- **GND:** De aardingspin.
- **VCC:** De voedingsspanning.
- **DATA:** De datapin voor het versturen van gegevens.

Een DHT22-sensor met vier pinnen heeft een GND-, VCC-, DATA- en NC-pin:
- **GND:** De aardingspin.
- **VCC:** De voedingsspanning.
- **DATA:** De datapin voor het versturen van gegevens.
- **NC:** Een ongebruikte aansluiting. Deze sluit je niet aan.

#### BME280-sensor
De BME280-sensor kan net iets meer dan de DHT11 en DHT22, maar is daardoor ook iets duurder. Deze sensor kan niet alleen de temperatuur en luchtvochtigheid meten, maar ook de luchtdruk. De BME280 communiceert meestal via I2C of SPI. Bij I2C worden de meetgegevens tussen de sensor en de Arduino verstuurd. De SCL-pin zorgt voor het kloksignaal waarmee de gegevensoverdracht wordt geregeld.

Dit is de pinindeling van een BME280:
- **VCC:** Voedingsspanning van de sensor.
- **GND:** Massa (aardingspin).
- **SCL:** Kloksignaal voor I2C-communicatie.
- **SDA:** Verstuurt gegevens via I2C.
- **SDO:** Bepaalt het I2C-adres of wordt gebruikt bij SPI.
- **CSB:** Selecteert de sensor bij SPI en helpt de communicatievorm bepalen.

#### SHT31-sensor
De SHT31 is een nauwkeurige sensor waarmee je de temperatuur en luchtvochtigheid kunt meten. De sensor is nauwkeuriger dan de DHT11-sensor en werkt via I2C. Ondanks dat dit een goede sensor is, vind ik hem aan de prijzige kant. Ik denk dat een DHT22-sensor qua kwaliteit en precisie redelijk dicht in de buurt komt.

Dit is de pinindeling van een SHT31-sensor:
- **VIN:** Voedingsspanning.
- **GND:** Massa (aardingspin).
- **SCL:** Kloksignaal voor I2C.
- **SDA:** Verstuurt meetgegevens via I2C.

---

### 2. Grondvochtigheid
- Keyestudio-grondvochtigheidssensor
- Capacitieve grondvochtigheidssensor
- Waterdichte capacitieve grondvochtigheidssensor

| **Sensor**                                      | **Grondvochtigheid meten** | **Pinnen** | **Kosten** |
|-------------------------------------------------|----------------------------|------------|------------|
| Keyestudio-grondvochtigheidssensor              | X                          | 3          | €2 - €5    |
| Capacitieve grondvochtigheidssensor             | X                          | 3          | €2 - €6    |
| Waterdichte capacitieve grondvochtigheidssensor | X                          | 3          | €5 - €12 |


#### Keyestudio-grondvochtigheidssensor
De Keyestudio-grondvochtigheidssensor is een sensor waarmee je kunt meten hoeveel vocht er in de grond aanwezig is. De sensor maakt gebruik van twee metalen meetpinnen die in de aarde worden geplaatst. Door de elektrische weerstand tussen deze pinnen te meten, kan de sensor bepalen hoe vochtig de grond is. Een voordeel voor mij is dat hij goedkoop en eenvoudig aan te sluiten is.

Keyestudio-grondvochtigheidssensor met 3-pinsindeling:
- **S:** Signaalpin voor het versturen van meetgegevens.
- **VCC:** Voedingsspanning.
- **GND:** Massa (aardingspin).


#### Capacitieve grondvochtigheidssensor
De capacitieve grondvochtigheidssensor is ook een sensor die het vochtgehalte in de grond kan meten. Het verschil met de Keyestudio-sensor is dat deze sensor gebruikmaakt van elektrische capaciteit in plaats van elektrische weerstand. Het is een iets duurdere sensor, maar ook heel interessant. Beide sensoren doen hetzelfde, maar de manier waarop ze meten verschilt. Deze module heeft dezelfde pinindeling als de Keyestudio-sensor.

Capacitieve grondvochtigheidssensor met 3-pinsindeling:
- **AOUT:** Signaalpin voor het versturen van meetgegevens.
- **VCC:** Voedingsspanning.
- **GND:** Massa (aardingspin).


#### Waterdichte capacitieve grondvochtigheidssensor
De waterdichte capacitieve grondvochtigheidssensor werkt technisch gezien hetzelfde als een gewone capacitieve grondvochtigheidssensor. Het enige verschil is dat deze uitvoering een aparte meetprobe heeft die met een kabel aan de elektronica is verbonden. Hierdoor kan de meetprobe in de grond worden geplaatst, terwijl de elektronica beter beschermd blijft tegen vocht. Dit maakt de sensor handiger voor langdurig gebruik. Daar staat wel tegenover dat deze sensor duurder is dan de bovenstaande sensoren.

Waterdichte capacitieve grondvochtigheidssensor met 3-pinsindeling:
- **VCC:** Voedingsspanning.
- **GND:** Massa (aardingspin).
- **AOUT:** Analoge uitgang voor het versturen van meetgegevens.

---

### 3. Pompjes
- Dompelpompje
- Gesloten waterpompje

| **Pomp**              | **Pinnen** | **Kosten** |
|-----------------------|------------|------------|
| Dompelpompje          | 2          | €2 - €5    |
| Gesloten waterpompje  | 2          | €5 - €10   |


#### Dompelpompje
Een dompelpompje is een waterpompje dat volledig of gedeeltelijk in het water wordt geplaatst. De pomp zuigt het water aan en via een slang brengt hij het naar de plant toe. Een voordeel is dat je geen aparte slang nodig hebt om het water aan te zuigen. Uiteindelijk vind ik het wel een groot nadeel dat water en elektriciteit dicht bij elkaar zitten. Daarnaast moet de pomp onder water blijven om goed te werken.

Dit is de pinindeling:
- **Plus (+):** Positieve voedingsaansluiting.
- **Min (-):** Negatieve voedingsaansluiting.


#### Gesloten waterpompje
Een gesloten waterpompje heeft een gesloten behuizing waarin het pompmechanisme zit. Een voordeel is dat het water niet direct in contact komt met de elektrische onderdelen. De werking is als volgt: de pomp staat buiten het water en zuigt het water via een slang aan. Vervolgens pompt hij het water via een tweede slang naar de plant.


De pinindeling is hetzelfde als die van een dompelpomp.
- **Plus (+):** Positieve voedingsaansluiting.
- **Min (-):** Negatieve voedingsaansluiting.

---

### 4. Besturingsbord
- Arduino UNO R4 WiFi
- Keyestudio Motor Driver Shield

#### Arduino UNO R4 WiFi en Motor Driver Shield
Toen ik begon met het maken van dit project, ben ik zonder plan met de Arduino aan de slag gegaan. In eerste instantie had ik geen specifieke reden waarom ik hiervoor koos, maar later was ik hier blij mee. De Arduino is namelijk een kleine computer waarop je sensoren kunt aansluiten.Nadat ik de Arduino had gekozen, kreeg ik bij mijn bestelling van het waterpompje ook een Keyestudio Motor Driver Shield.

| **Onderdeel**                 | **Kosten** |
|-------------------------------|------------|
| Arduino UNO R4 WiFi           | €29,00     |
| Keyestudio Motor Driver Shield| €10,00     |

---

## Gekozen hardware
Uiteindelijk heb ik voor de volgende onderdelen gekozen:
Voor de temperatuur- en luchtvochtigheidssensor heb ik de DHT11-sensor gekozen, omdat deze goedkoop is en we er een overvloed aan hebben op school. Voor de grondvochtigheidsmeter heb ik de Keyestudio-grondvochtigheidssensor gekozen, omdat ik deze ook op school kon vinden. Daarnaast had ik een pompje nodig. Dat heb ik samen met meneer Richard in overleg laten bestellen. Uiteindelijk heb ik meer gekregen dan alleen een waterpompje: een dompelpompje, een gesloten waterpompje en een Motor Driver Shield voor de Arduino. Met deze onderdelen ben ik gaan bouwen, samen met wat draadjes.

---

# Benodigde software
Voor het programmeren van de Arduino maak ik gebruik van verschillende softwareprogramma's en bibliotheken.

**Arduino IDE**
Dit is het belangrijkste programma, omdat ik hierin mijn code schrijf. Natuurlijk zijn er ook code-editors zoals VS Code die dit kunnen, als je de juiste uitbreidingen toevoegt. Ik vond het fijner om het originele programma te gebruiken, zodat ik zeker wist dat het werkte.

**Arduino UNO R4 Board Package**
Dit pakket zorgt ervoor dat de Arduino IDE geschikt is voor de Arduino UNO R4 WiFi en de juiste instellingen gebruikt.

**Arduino-bibliotheken**
Voor sommige sensoren, zoals de DHT11-sensor, had ik een externe bibliotheek nodig, zoals de DHT-sensorbibliotheek. Ook had ik voor het verbinden met wifi en het versturen van HTTP-verzoeken de bibliotheken WiFiS3 en ArduinoHttpClient nodig.

**Home Assistant**
Dit programma gebruik ik om de meetgegevens van de Arduino te ontvangen en te verwerken. Ook maak ik hierin automatiseringen waarmee de waterpomp automatisch kan worden aangestuurd. Ik heb later besloten om Home Assistant toe te voegen. Omdat ik toen nog geen manier had om de gegevens die de Arduino binnenkreeg goed weer te geven.

---

# Benodigde documenten en componenten
Voor de realisatie van mijn plantenbewateringssysteem verzamel ik verschillende bronnen om het systeem werkend te maken. Dit zijn zowel online bronnen als voorbeelden en sjablonen die tot mijn beschikking staan in de Arduino IDE. Hierdoor kan ik snel componenten testen. Daarnaast heb ik voor het instellen van Home Assistant gebruikgemaakt van ChatGPT.

## Gebruikte componenten:
- **Arduino UNO R4 WiFi:** Het hoofdboard dat de gegevens verwerkt en via wifi communiceert met Home Assistant.
- **DHT11-sensor:** Meet de temperatuur en luchtvochtigheid.
- **Bodemvochtigheidssensor:** Meet hoeveel vocht er in de potgrond aanwezig is.
- **Motor Driver Shield:** Stuurt de waterpomp aan.
- **Waterpomp:** Pompt water naar de plant wanneer de grond te droog is.
- **Voeding:** Voorziet de schakeling en de pomp van stroom.
- **Home Assistant:** Ontvangt de meetgegevens en voert automatiseringen uit.

---

# Ontwikkelmethode
Voor het realiseren van mijn plantenbewateringssysteem ga ik gebruikmaken van een stapsgewijs stappenplan. Zo bouw ik het systeem langzaam op.

### Ik werk in de volgende stappen

1. **Documentatie:** Het schrijven van de documentatie.
2. **Hardware opbouwen:** De Arduino aansluiten en kijken wat ik ermee kan.
3. **Sensoren testen:** De verschillende sensoren aansluiten en de Arduino programmeren, zodat ik ze kan uitlezen via de Arduino-console.
4. **Waterpomp aansturen:** De waterpomp samen met de Motor Driver Shield aansluiten, zodat ik de pomp kan programmeren en aanzetten met de geschreven code.
5. **HTTP-verzoeken:** Kijken of ik GET- en POST-verzoeken kan versturen vanaf en naar de Arduino, zodat ik gegevens kan versturen en opvragen.
6. **Home Assistant koppelen:** Ervoor zorgen dat ik gegevens zoals temperatuur, luchtvochtigheid en grondvochtigheid naar Home Assistant kan sturen.
7. **Home Assistant-automatiseringen maken:** Automatiseringen toevoegen, zodat Home Assistant ook GET-verzoeken naar de Arduino kan sturen.
8. **Eindtest uitvoeren:** Het complete systeem testen om te controleren of alle onderdelen goed samenwerken.
9. **Documentatie:** De documentatie aanpassen.
10. **Project inleveren:** Alles inleveren met behulp van een zipbestand.
11. **Presenteren:** Het project presenteren.

# Planning

Hieronder heb ik een globale planning gemaakt voor de uitvoering van dit project. Natuurlijk kan het voorkomen dat ik hiervan afwijk, maar dit is de basisplanning die we hebben gemaakt.

| **Datum**  | **Werkzaamheden**                                                                                                                               |
|------------|-------------------------------------------------------------------------------------------------------------------------------------------------|
| 08-09-2026 | Documentatie: Het schrijven van documentatie.                                                                                                   |  
| 15-09-2026 | Hardware opbouwen: De Arduino aansluiten en kijken wat ik ermee kan.                                                                            |
| 22-09-2026 | Hardware opbouwen: De Arduino aansluiten en kijken wat ik ermee kan.                                                                            |
| 29-09-2026 | Sensoren testen: De verschillende sensoren aansluiten en de Arduino programmeren, zodat ik ze kan uitlezen via de Arduino-console.              |
| 06-10-2026 | Sensoren testen: De verschillende sensoren aansluiten en de Arduino programmeren, zodat ik ze kan uitlezen via de Arduino-console.              |
| 13-10-2026 | Waterpomp aansturen: De waterpomp samen met de Motor Driver Shield aansluiten, programmeren en testen.                                          |
| 20-10-2026 | HTTP-verzoeken: Kijken of ik GET- en POST-verzoeken kan versturen vanaf en naar de Arduino, zodat ik gegevens kan versturen en opvragen.        |
| 27-10-2026 | Home Assistant koppelen: Ervoor zorgen dat ik gegevens zoals temperatuur, luchtvochtigheid en grondvochtigheid naar Home Assistant kan sturen.  |
| 03-11-2026 | Home Assistant koppelen: Verder werken aan het versturen van meetgegevens naar Home Assistant.                                                  |
| 10-11-2026 | Home Assistant-automatiseringen maken: Automatiseringen toevoegen, zodat Home Assistant ook GET-verzoeken naar de Arduino kan sturen.           |
| 17-11-2026 | Eindtest uitvoeren: Het complete systeem testen om te controleren of alle onderdelen goed samenwerken.                                          |
| 24-11-2026 | Documentatie: De documentatie aanpassen.                                                                                                        |
| 01-12-2026 | Project inleveren: Alles inleveren met behulp van een zipbestand.                                                                               |
| 10-12-2026 | Presenteren.                                                                                                                                    |