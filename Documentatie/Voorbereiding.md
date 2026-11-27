
# Automatisch plant bewatering systeem
Voor het kuezedeel mirocontrollers ben ik van plan om een Automatisch plant bewatering systeem te bouwen, omdat ik altijd na mijn vakantie zit dat mijn planten zijn gestorven, Ik hoop dat ik met dit systeem ervoor zorf dat mijn planten geduurig mijn afwezigheid overlven



- Gemaakt door: Rick Salden
- onderwerp: voorberijdingsdocuemnt 
- datum: 12-11-2026  


# InhoudsOpgave
- [onderzoek hardware](#onderzoek-hardware)
    -[lijst met hardware](#lijst-met-hardware)
    -[Gekozen Hardware](#gekozen-hardware)
- [Benodigde Software](#benodige-software)
- [benodige documenten & componetes](#benodigde-documenten-en-componenten)
- [ontwikkelmethode](#ontwikkelmethode)
- [planning](#planning)

# onderzoek hardware
Omdat ik van plan ben om een plantbewateringsysteem te bouwen, Heb ik verschillende onderdelen nodig. Onderdelen om de tempratuur/luchtvoetigheid te meten maar ook appratuur om de grondvochtighied te meten. Daarnaast heb ik pomp nodig die water kan pompen en als laatst een main bordje waarop ik alles kan aansluiten en laat samen komen. Hieronder heb ik een lijst gemaakt van onderdelen die dit kunnen.

## Lijst met hardware 

1. Tempratuur en luchtvoctighied
    - DHT11 sensor
    - DHT22 sensor
    - BME280 sensor
    - SHT31 sensor



| **Sensor**    | **Tempratuur** | **Luchtvoetigheid** | **Extra** | **Pins** | **Kosten** |
|---------------|----------------|---------------------|-----------|----------|------------|
| DHT11 sensor  |       X        |          X          |     _     |     3    |   €2 - €3  |
| DHT22 sensor  |       X        |          X          |     _     |     3    |   €3 - €6  |    
| BME280 sensor |       X        |          X          |     X     |     4    | €4,50 – €7 |        
| SHT31 sensor  |       X        |          X          |     _     |     4    |  €10 – €23 |        



**DHT11 sensor**
De DHT11 sensor is een goedkope sensor waarmee je de tempratuur en de luchtvoetigheid kan meten, het is geen supernouwkeurige sensor. Het tempratuurgebruik zit tussen de 0 tot en met 50 celsius. En de luchtvoetigheidsmeter heeft een bereik vab 20 tot 80%, Voor kleine tests is dit meer dan genoeg. Sommige DHT11 sensors hebben 4 pinnetjes, maar er zijn ook 3 pins uitvoeringen deze hebben al een ingebouwde weerstand die een vier pin niet heeft.     

DHT11 sensor 3-pins heeft een GND, VCC en een data pin, 
- De gnd vertegenwoordigd de grond pin 
- De vcc is de spanning
- De datapin is voor de gegevens

DHT11 sensor 4-pins heeft een GND, VCC, Data-pin en een NC
- De gnd vertegenwoordigd de grond pin 
- De vcc is de spanning
- De datapin is voor de gegevens
- de NC-pin is alleen aanwezig als ongebruikte aansluiting. Je sluit hem niet aan.



**DHT22 sensor**
De DHT22 sensor is ook nog een goedkope sensor, maar is een verbeterde versie van de DHT11 sensor. Deze sensor kan zowel hoge als lage tempraturen meten en is een stuk nouwkeuriger. Het tempratuurbereik zit tussen de -40 to 80 celsius, ook de luchtvoetigheidsmeter heeft een breder bereik inplaats van de DHT11 sensor kan deze van 0 tot 100% meten. Sommige DHT22 sensors hebben 4 pinnetjes, maar er zijn ook 3 pins uitvoeringen deze hebben al een ingebouwde weerstand die een vier pin niet heeft.     

DHT22 sensor 3-pins heeft een GND, VCC en een data pin, 
- De gnd vertegenwoordigd de grond pin 
- De vcc is de spanning
- De datapin is voor de gegevens

DHT22 sensor 4-pins heeft een GND, VCC, Data-pin en een NC
- De gnd vertegenwoordigd de grond pin 
- De vcc is de spanning
- De datapin is voor de gegevens
- de NC-pin is alleen aanwezig als ongebruikte aansluiting. Je sluit hem niet aan.



**BME280 sensor**
De BME280 sensor kan net iets meer dan de DHT11 en DHT22, maar is daardoor ook iets duurder. Deze sensor kan niet alleen de tempratuur en de luchtvoetigheid meten, maar ook de luchtdruk. De BME280 communiceert meestal via een I2C of een SPI. De I2C verstuurt de meetgegevens tussen de sensor en Arduino. En de SCL zorgt voor het kloksignaal waarmee de gegevensoverdracht wordt geregeld. Dit is de pinlayout van een BME280

BME280 sensor 6-pins layout
- VCC oedingsspanning van de sensor
- GND	Massa (grondpin)
- SCL	Kloksignaal voor I2C-communicatie
- SDA	Verstuurt gegevens via I2C
- SDO	Bepaalt het I2C-adres of wordt gebruikt bij SPI
- CSB	Selecteert de sensor bij SPI en helpt de communicatievorm bepalen



**SHT31 sensor**
De SHT32 is een nauwkerige sensor waarmee je alleen de tempratuur en de luchtvoeticheid kan meten. De sensor is nauwkeriger dan de DHT11 senesor en werkt via I2C, ondanks dat dit een goede sensor is vind ik hem aan de prijzige kant en denk ik dat een DHT22 sensor vrij dicht bij hem in de buurt zit betreft kwaliteit en pressie. Dit is de pinlayout van een SHT31 sensor


SHT31 sensor 4 pins layout
- VIN = Voedingsspanning
- GND =	Massa (grondpin)
- SCL =	Kloksignaal voor I2C
- SDA = Versturen van meetgegevens via I2C


2. Grondvochtigheid
    - Keystudio grondvochtighiedssnensor
    - Capacitieve grondvochtigheidssensor
    - Waterdichte capacitieve grondvochtigheidssensor



| **Sensor**                                     | **grondvochtighied** | **Pins** | **Kosten** |
|------------------------------------------------|----------------------|----------|----------- |
| Keystudio grondvochtighiedssnensor             |       X              |     3    |  €2 – €5   |
| Capacitieve grondvochtigheidssensor            |       X              |     3    |  €2 – €6   |    
| Waterdichte capacitieve grondvochtigheidssensor|       X              |     3    |  €5 – €12  |        



**Keystudio grondvochtighiedssnensor**
De Keystudio-grondvochtighiedssensor is een sensor waarmee je kunt meten hoeveel vocht er in de grond aanwezig is. De sensor maakt gebruik van twee metalen meetpinnen die in de aarde worden geplaatst. Door de elektrische weerstand tussen deze pinnen te meten, kan de sensor bepalen hoe vochtig de grond is. Een voordeel voor mij is dat hij goedkoop is en hij eenvoedig is aantelsuiten omdat hij de volgende 3pinnen gebruikt.

- Keyestudio grondvochtigheidssensor 3 pins layout:
- S = Signaalpin voor het versturen van meetgegevens
- VCC = Voedingsspanning
- GND = Massa (grondpin)



**Capacitieve grondvochtigheidssensor**
De capactiieve grondvochtigheidsensor is ook een sensor die het vochtgehalte in de grond kan meten. Het verschil met de Keystudio-sensor is dat deze snesor gebruikt maakt van elektrische capiteit inplaats van elecktrische weerstand zoals bij de Keystudio-sensor. Het is een iets duurderdere sensor maar is ook heel intersant want beide doen zehetzelfde maar hoe ze het doen verschilt dan weer. Deze module heeft de zelfde layout als de keystudio sensor.

- Keyestudio grondvochtigheidssensor 3 pins layout:
- AOUT = Signaalpin voor het versturen van meetgegevens
- VCC = Voedingsspanning
- GND = Massa (grondpin)



**Waterdichte capacitieve grondvochtigheidssensor**
De waterdichte capaciteive grondvochtighiedssensor werkt technische gezien hetzelfde als een gewonne Capacitieve grondvochtigheidssensor. het eninge verschil is dat deze uitvoering een aparte meetprobe heeft die met een kabel aan de elektronica is verbonden. Hierdoor kan de meetprobe in de grond worden geplaatst terwijl de elektronica beter beschermd blijft tegen vocht. Dit maakt de sensor handiger voor langduurig gebruik daarover staat wel dat deze sensor wel duuder is dan bovenstaande senors tesamen. Dit is de pinlayout:

Waterdichte capacitieve grondvochtigheidssensor 3 pins layout
- VCC = Voedingsspanning
- GND = Massa (grondpin)
- AOUT = Analoge uitgang voor het versturen van meetgegevens

3. pompjes
    - Dompelpompje
    - Gesloten waterpompje



| **Sensor**                                     | **Pins** | **Kosten** |
|------------------------------------------------|----------|----------- |
| Dompelpompje                                   |     2    |  €2 – €5   |
| Gesloten waterpompje                           |     2    |  €5 – €10  |



**Dompelpompje**
Een dompelpompje is een waterpompje dat vollidig of gedeeltelijk in het water word geplaatst. De pomp zuigt het water aan en via een slang brengt hij het naar de plant toe, een voordeel is dan ook dat je geen apparte slang nodig hebt om het water aantezuigen. Uiteindelijk vind ik het wel een groot nadeel omdat water en electra wel heel dict bij elkaar zitten, daarnaast is het ook zo dat de pomp onder water moet blijven om goed te werken. Dit is de pinlayout:



Dompelpompje aansluitingen
- Plus (+) = Positieve voedingsaansluiting.
- Min (-) = Negatieve voedingsaansluiting.



**Gesloten waterpompje**
Een gesloten waterpompje heeft een gesloten beuizing waarin het pompmechanise zit. Een voordeel is dan ook dat het water niet direct contact heeft met de elktra staat, de werking is als volgt de pomp staat buiten het water en zuigt het water via een slang aan. Vervolgens pompt hij het water via een tweede slang naar de plant. De pinlayout is hetzelfde van een dompelpomp.



Dompelpompje aansluitingen
- Plus (+) = Positieve voedingsaansluiting.
- Min (-) = Negatieve voedingsaansluiting.


4. Main bord 
    - ardunio uno R4 wifi
    - Keyestudio Motor Driver Shield



**ardunio uno R4 wifi & Motor Driver Shield**
Toen ik ben begonnen met het maken van dit project ben ik zonder plan bezig gegaan met de arduino, ineerstenstatie had ik geen reden waarom ik hiervoor koos, maar later was ik hier blij mee omdat het eigenlijke een kleine computer is waar je sensoren aan kan plakken. Nadat ik gekozen heb ik een keystudio moter driver shield gekregen bij mijn bestelling van het waterpompje 


| **Sensor**                                     | **Kosten** |
|------------------------------------------------|----------- |
| ardunio uno R4 wifi                            |  €29.00    |
| Keyestudio Motor Driver Shield                 |  €10.00    |


## Gekozen hardware
Uiteindelijk heb ik voor de volgende onderdelen gekozen: 

voor de tempratuur en liuchtvoetigheid sensor heb ik de DHT11 sensor gekozen, omdat het een goedkope sensors is en omdat we er een overvloed aan hebben op school. Voor de grondvochtighiedsmeter heb ik de keystudio grondvochtighiedssnensor gekozen omdat ik deze ook op school kon vinden. Daarnaast had ik een pompje nodig Die heb ik samen met meneer richard inoverleg laten bestellen uiteindelijk heb ik weer kegregen dan alleen een waterpompje maar een dompel pomp een geslotenwaterpompje en een Motor Driver Shield voor de arduino met deze spullen ben ik gaan bouwen samen met wat draadjes. 


# Benodige software 
Voor het programmeren van de Arduino maak ik gebruik van verschillende softwareprogrammas en bibiotheken.

Arduino IDe: Dit is het belangrijkste programma omdat dit het programma is waarin ik mijn code moet gaan schrijven, natuurlijk zijn er ook code editors zoals vs-code die het ook kunnnen doen als je een externe bibiotheek eraan toevoegd. Maar ik vond het fijner om het orignele programma ervoor te gebruiken zodat ik zeker was dat het werkte.

Arduino UNO R4 Board Package: Dit pakket zorgt ervoor dat de Arduino IDE geschikt is voor de Arduino UNO R4 WiFi en de juiste instellingen gebruikt.

Arduino bibiotheken: Voor sommige sensoren zoals de DHT11 sensor had ik een externe bibiotheek nodig zolas DHT sensor maar ook voor het kunne verbinden met wifi en het sturen van HTTP-requesten had ik deze twee packages nodig WiFiS3 en ArduinoHttpClient.

Home Assistant: Dit programma gebruik ik om de meetgegevens van de Arduino te ontvangen en te verwerken. Ook maak ik hierin automatiseringen waarmee de waterpomp automatisch kan worden aangestuurd. Ik heb dit later besloten om dit toetevoegen en dit kwam als resultaat uit mijn TestRapport omdat ik toen nog geen manier had om gegevens te kunnen laten zien die de arduino binnen kreeg.

# Benodigde documenten en componenten
Voor de realisatie van mijn plantbewateringssyteem verzamel ik verschillende bronnen om dit werkend te maken zowel als online bronnen als templates die tot mijn beschiking waren in de arduino IDE editot zodat ik ook snel componenten kon testen, Daarnaast heb ik voor het instellen van de homeassistant gebruik gemaakt van Chatgpt.


**Gebruikte componenten:**

- Arduino UNO R4 WiFi: het hoofdboard dat de gegevens verwerkt en via wifi communiceert met Home Assistant.
- DHT11-sensor: meet de temperatuur en luchtvochtigheid.
- Bodemvochtigheidssensor: meet hoeveel vocht er in de potgrond aanwezig is.
- Motor Driver Shield: stuurt de waterpomp aan.
- Waterpomp: pompt water naar de plant wanneer de grond te droog is.
- Voeding: voorziet de schakeling en de pomp van stroom.
- Home Assistant: ontvangt de meetgegevens en voert automatiseringen uit.


# Ontwikkelmethode
Voor het realiseren van mijn plantbewateringssyeem ga ik gebruik maken van stapsgewijz stappenplan, en bouw zo langzaam het systeem op:

**Ik werk in de volgende stappen**
1. documentatie: Het schrijven van documentatie
1. Hardware opbouwen: Arduino aansluiten en kijken wat ik er mee kan.
2. Sensors testen: Ik sluit de verschillende sensors aan en programmeer de arduino dat ik ze kan uitlezen via de arduino-console
3. Waterpomp aansturen: Ik sluit de waterpomp samen met de moter driver aan, zodat ik ze kan programmeeren en de pomp kan aanzetten via de geschreven hardcode code
4. Http requests: Kijken als ik get & post request kan sturen vanaf/naar de arduino, zodat ik gegevens kan toesturen en kan opvragen 
5. Home Assistant koppelen: Ik zorg ervoor dat ik gegevens zoals tempratuur en luchtvoetigheid en grondvochtigheid kan sturen naar de homeAssitant 
6. Homeassistant automatiseringen maken: Het toevoegen van automatisering zodat de homeAssitant ook Get request kan maken naar de arduino
7. Eindtest uitvoeren: Ik test het complete systeem om te controleren of alle onderdelen goed samenwerken.
8. documentatie: Het aanpassen van de documentatie.
9. Inleveren project: Alles inleveren met behulp van een zip-bestand
10. Presenteren.

# Planning
Hieronder heb ik een globale planning gemaakt hoe ik dit project ga uitvoeren, natuurlijk kan het voorkomen dat ik ervan afwijk maar dit is de bassis die we hebben gemaakt.

| Datum      |Werkzaamheden                                                                                                                                                                |   
|------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 08-09-2026 | documentatie: Het schrijven van documentatie                                                                                                                                |
| 15-09-2026 | Hardware opbouwen: Arduino aansluiten en kijken wat ik er mee kan                                                                                                           |             
| 22-09-2026 | Hardware opbouwen: Arduino aansluiten en kijken wat ik er mee kan                                                                                                           | 
| 29-09-2026 | Sensors testen: Ik sluit de verschillende sensors aan en programmeer de arduino dat ik ze kan uitlezen via de arduino-console                                               |
| 06-10-2026 | Sensors testen: Ik sluit de verschillende sensors aan en programmeer de arduino dat ik ze kan uitlezen via de arduino-console                                               |
| 13-10-2026 | Waterpomp aansturen: Ik sluit de waterpomp samen met de moter driver aan, zodat ik ze kan programmeeren en de pomp kan aanzetten via de geschreven hardcode code, en testen.|
| 20-10-2026 | Http requests: Kijken als ik get & post request kan sturen vanaf/naar de arduino, zodat ik gegevens kan toesturen en kan opvragen                                           |         
| 27-10-2026 | Home Assistant koppelen: Ik zorg ervoor dat ik gegevens zoals tempratuur en luchtvoetigheid en grondvochtigheid kan sturen naar de homeAssitant                             | 
| 03-11-2026 | Home Assistant koppelen: Ik zorg ervoor dat ik gegevens zoals tempratuur en luchtvoetigheid en grondvochtigheid kan sturen naar de homeAssitant                             |
| 10-11-2026 | Homeassistant automatiseringen maken: Het toevoegen van automatisering zodat de homeAssitant ook Get request kan maken naar de arduino                                      |
| 17-11-2026 | Eindtest uitvoeren: Ik test het complete systeem om te controleren of alle onderdelen goed samenwerken.                                                                     |
| 24-11-2026 | documentatie: Het aanpassen van de documentatie.                                                                                                                            |
| 01-12-2026 | Inleveren project: Alles inleveren met behulp van een zip-bestand                                                                                                           |
| 10-12-2026 | Presenteren                                                                                                                                                                 |