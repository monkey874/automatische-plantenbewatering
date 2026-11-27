# Testplan - automatis plantbewateringsysteem

## Inleiding
In dit testplan word het automatis plantbewateringsysteem. Dit is een systeem waarmee je planten kan bewateren zonder het zelf te doen. Tijdens het testen worden verschillende onderdelen van het systeem gecontrolleerd. Denk hierbij aan het testen van sensoren, Het controleren van de http-requets van/naar de homeAssistant.

De Applicatie word gestest door mijzelf en doorzich zelf. Ik zal het systeem voor een paar nachten aan laten staan zodat ik zeker weet dat alles vlekkeloos werkt. Voor meer informatie iver het poject verwijs ik naar het voorbereidings 


## Rappotage
Na het uivoeren van de tests zullen de resultaten in het testrapport genoteerd worden. Dit geeft dan een duidelijk overzicht wat wel en niet goed werkt, en kan ik bewijzen dat de volgende onderdelen getest zijn.


## organisatie
In dit hoofdstuk beschrijf ik wie wat gaat testen en zoals uit de inleiding al wat bleek test ik de applicatie in eersten stantie zelf, wanneer ik dit test zal ik allegemaakte functionaliteiten testen. Omdat ik ook gewoon maar een mens ben wil ik het systeem ook zichzelf laten testen zodat ik zeker kan zijn dat het systeem na de gewenste situwatie reageerd.

## tests
Hieronder zijn de belangrijkste tests uitgewerkt om te kijken als het systeem goed werkt. Sommige tests zullen mischien overbodig klinken maar zijn wel van belang.

- DHT11 uitlezen
    - **Doel:** Controleren of de DHT11-sensor goed werkt en meetgegevens naar de Arduino verstuurt.
    - **Benodigdheden:** Laptop met Arduino IDE, Arduino UNO R4 WiFi, DHT11-sensor en USB-C-kabel.
    - **Stappen:**
        - Verbind de Arduino met de laptop via een USB-C-kabel.
        - Sluit de DHT11-sensor aan op de Arduino.
            - GND → GND
            - VCC → 5V
            - S → digitale pin 2 (D2)
            - Vraag hulp bij het aansluiten als dit lastig is.
        - Upload de code naar de Arduino via de Arduino IDE.
        - Open de Serial Monitor in de Arduino IDE.
        - Controleer of de sensor meetgegevens doorgeeft.
    - **Verwacht resultaat:** Er verschijnt een JSON-bericht met de gemeten temperatuur en luchtvochtigheid in de Serial Monitor.
    
- Grondvochtigheid uitlezen
    - **Doel:** Controleren of de grondvochtigheidssensor werkt en meetgegevens naar de Arduino stuurt.
    - **Benodigdheden:** Laptop met Arduino IDE, Arduino, USB-C-kabel en grondvochtigheidssensor.
    - **Stappen:**
        - Verbind de Arduino met de laptop via een USB-C-kabel.
        - Verbind de grondvochtigheidssensor met de Arduino.
            - VCC naar 3.3V.
            - GND naar GND.
            - AO naar analoge pin A0.
        - Upload de code naar de Arduino via de Arduino IDE.
        - Open de Serial Monitor.
        - Houd de sensor eerst in droge en daarna in vochtige grond.
        - Vergelijk de meetwaarden.
    - **Verwacht resultaat:** De Arduino geeft meetwaarden weer. Deze veranderen wanneer de sensor in drogere of vochtigere grond wordt geplaatst.

- HTTP GET-verzoek ontvangen
    - **Doel:** Controleren of de Arduino HTTP GET-verzoeken kan ontvangen en verwerken.
    - **Benodigdheden:** Laptop, Arduino, USB-C-kabel, wifi-netwerk en webbrowser.
    - **Stappen:**
        - Verbind de Arduino met de laptop.
        - Upload het programma naar de Arduino.
        - Controleer in de Serial Monitor welk IP-adres de Arduino heeft gekregen.
        - Zorg dat de laptop en Arduino met hetzelfde wifi-netwerk verbonden zijn.
        - Open een webbrowser.
        - Vul het IP-adres van de Arduino in, gevolgd door `:8000/pomp/aan`.
        - Controleer of de Arduino het verzoek ontvangt.
        - Herhaal dit met `:8000/pomp/uit`.
    - **Verwacht resultaat:** De Arduino ontvangt de GET-verzoeken en voert het bijbehorende commando uit.

- HTTP POST-verzoek versturen
    - **Doel:** Controleren of de Arduino gegevens via een HTTP POST-verzoek kan versturen.
    - **Benodigdheden:** Laptop met Arduino IDE, Arduino, USB-C-kabel, wifi-netwerk en Home Assistant.
    - **Stappen:**
        - Verbind de Arduino met de laptop.
        - Controleer of de Arduino verbinding heeft met wifi.
        - Upload het programma naar de Arduino.
        - Open de Serial Monitor.
        - Laat de Arduino meetgegevens verzamelen.
        - Controleer of de Arduino een POST-verzoek verstuurt.
        - Controleer of het verzoek succesvol wordt verstuurd.
    - **Verwacht resultaat:** De Arduino verstuurt een POST-verzoek met de meetgegevens naar de ingestelde webhook van Home Assistant.

- Home Assistant ontvangt gegevens
    - **Doel:** Controleren of Home Assistant de gegevens van de Arduino ontvangt en verwerkt.
    - **Benodigdheden:** Arduino, laptop, wifi-netwerk en Home Assistant.
    - **Stappen:**
        - Start Home Assistant.
        - Controleer of de webhook-automatisering actief is.
        - Start de Arduino.
        - Laat de Arduino meetgegevens versturen.
        - Open Home Assistant.
        - Controleer de temperatuur, luchtvochtigheid en grondvochtigheid.
        - Controleer of de waarden overeenkomen met de gegevens uit de Arduino.
    - **Verwacht resultaat:** Home Assistant ontvangt de meetgegevens en werkt de bijbehorende waarden bij.

- Pomp handmatig bedienen via Home Assistant
    - **Doel:** Controleren of de waterpomp handmatig via Home Assistant kan worden aangestuurd.
    - **Benodigdheden:** Arduino, Motor Driver Shield, waterpomp, voeding, laptop en Home Assistant.
    - **Stappen:**
        - Sluit de waterpomp aan op de Motor Driver Shield.
        - Controleer of de pomp een geschikte voedingsspanning krijgt. Gebruik maximaal 6V voor de pomp.
        - Start de Arduino en Home Assistant.
        - Controleer of beide apparaten verbonden zijn met hetzelfde netwerk.
        - Open Home Assistant.
        - Geef het commando om de pomp aan te zetten.
        - Controleer of de pomp begint te draaien.
        - Geef daarna het commando om de pomp uit te zetten.
        - Controleer of de pomp stopt.
    - **Verwacht resultaat:** De waterpomp gaat aan en uit wanneer deze via Home Assistant wordt aangestuurd.

- Pomp automatisch inschakelen
    - **Doel:** Controleren of de waterpomp automatisch aangaat wanneer de grond te droog is.
    - **Benodigdheden:** Arduino, grondvochtigheidssensor, Motor Driver Shield, waterpomp, voeding en Home Assistant.
    - **Stappen:**
        - Start de Arduino en Home Assistant.
        - Controleer of de grondvochtigheidssensor meetwaarden doorgeeft.
        - Zorg dat de automatisering actief is.
        - Maak de grond droger of gebruik een meetwaarde die onder de ingestelde grenswaarde ligt.
        - Controleer de meetwaarde in Home Assistant.
        - Controleer of Home Assistant een commando naar de Arduino stuurt.
        - Controleer of de waterpomp aangaat.
    - **Verwacht resultaat:** De waterpomp wordt automatisch ingeschakeld wanneer de grondvochtigheid onder de ingestelde grenswaarde komt.

- Pomp automatisch uitschakelen
    - **Doel:** Controleren of de waterpomp automatisch uitschakelt wanneer de grond voldoende vochtig is.
    - **Benodigdheden:** Arduino, grondvochtigheidssensor, Motor Driver Shield, waterpomp, voeding en Home Assistant.
    - **Stappen:**
        - Start de Arduino en Home Assistant.
        - Controleer of de waterpomp aanstaat.
        - Maak de grond vochtiger of gebruik een meetwaarde die boven de ingestelde uitschakelgrens ligt.
        - Controleer de meetwaarde in Home Assistant.
        - Controleer of Home Assistant een uitschakelcommando naar de Arduino stuurt.
        - Controleer of de waterpomp stopt.
    - **Verwacht resultaat:** De waterpomp wordt automatisch uitgeschakeld wanneer de ingestelde uitschakelgrens wordt bereikt.

- Test bij uitval van Home Assistant
    - **Doel:** Controleren wat er gebeurt wanneer Home Assistant tijdelijk niet beschikbaar is.
    - **Benodigdheden:** Arduino, waterpomp, Motor Driver Shield, laptop en Home Assistant.
    - **Stappen:**
        - Start de Arduino en Home Assistant.
        - Controleer of de communicatie werkt.
        - Schakel Home Assistant tijdelijk uit.
        - Probeer de pomp via Home Assistant aan te sturen.
        - Controleer of de Arduino nog meetgegevens verzamelt.
        - Start Home Assistant opnieuw.
        - Controleer of de communicatie weer werkt.
    - **Verwacht resultaat:** Home Assistant kan tijdens de storing geen nieuwe commando's versturen. Na het opnieuw opstarten controleer ik of de communicatie wordt hersteld.

- Wifi verbinden
    - **Doel:** Controleren of de Arduino verbinding kan maken met het wifi-netwerk.
    - **Benodigdheden:** Arduino, laptop, USB-C-kabel en een wifi-netwerk.
    - **Stappen:**
        - Verbind de Arduino met de laptop.
        - Controleer of de juiste wifi-instellingen in het programma staan.
        - Upload het programma naar de Arduino.
        - Open de Serial Monitor.
        - Start de Arduino opnieuw op.
        - Controleer of de Arduino verbinding maakt met het wifi-netwerk.
        - Controleer of de Arduino een IP-adres ontvangt.
    - **Verwacht resultaat:** De Arduino maakt verbinding met wifi en ontvangt een geldig IP-adres.

- Wifi valt weg
    - **Doel:** Controleren wat er gebeurt wanneer de wifi-verbinding van de Arduino wegvalt.
    - **Benodigdheden:** Arduino, laptop, USB-C-kabel en wifi-netwerk.
    - **Stappen:**
        - Start de Arduino en controleer of deze verbonden is met wifi.
        - Open de Serial Monitor.
        - Schakel tijdelijk de wifi-router uit of verbreek de wifi-verbinding.
        - Controleer wat er in de Serial Monitor gebeurt.
        - Schakel de wifi-router weer in.
        - Controleer of de Arduino opnieuw verbinding maakt.
        - Controleer of de communicatie met Home Assistant weer werkt.
    - **Verwacht resultaat:** De wifi-verbinding valt weg wanneer het netwerk wordt uitgeschakeld. Na herstel van het netwerk controleer ik of de Arduino opnieuw verbinding maakt.

- Langdurige test
    - **Doel:** Controleren of het complete systeem gedurende langere tijd goed blijft werken.
    - **Benodigdheden:** Complete plantenbewateringssysteem, Arduino, sensoren, waterpomp, voeding en Home Assistant.
    - **Stappen:**
        - Sluit alle onderdelen aan.
        - Start de Arduino en Home Assistant.
        - Controleer of alle sensoren meetwaarden doorgeven.
        - Laat het systeem meerdere uren draaien.
        - Controleer regelmatig of de meetwaarden worden bijgewerkt.
        - Controleer of de waterpomp correct wordt aangestuurd.
        - Controleer of er geen onverwachte storingen optreden.
    - **Verwacht resultaat:** Het systeem blijft gedurende de testperiode werken zonder onverwachte storingen.

- Sensor loskoppelen
    - **Doel:** Controleren wat er gebeurt wanneer een sensor niet meer aangesloten is.
    - **Benodigdheden:** Arduino, laptop, USB-C-kabel, DHT11 en grondvochtigheidssensor.
    - **Stappen:**
        - Sluit de sensoren aan op de Arduino.
        - Upload het programma.
        - Open de Serial Monitor.
        - Controleer of beide sensoren meetwaarden doorgeven.
        - Koppel één sensor los terwijl de Arduino via USB gevoed wordt.
        - Controleer wat er in de Serial Monitor gebeurt.
        - Sluit de sensor opnieuw aan.
        - Controleer of de sensor weer meetwaarden doorgeeft.
        - Herhaal dit eventueel met de andere sensor.
    - **Verwacht resultaat:** De Arduino merkt dat de meetgegevens van de losgekoppelde sensor ontbreken of ongeldig zijn. Na opnieuw aansluiten controleer ik of de sensor weer werkt.