# Aanpassingsdocument
Tijdens het testen van het automatische plantenbewateringssysteem zijn er een aantal verbeterpunten naar voren gekomen. Deze verbeterpunten zijn genoteerd in het testrapport. In dit document beschrijf ik welke aanpassingen ik heb doorgevoerd om het systeem betrouwbaarder te maken.

- **Gemaakt door:** Rick Salden
- **Onderwerp:** Aanpassingsdocument
- **Datum:** 15-11-2026

---

## 1. Wifi-verbinding herstellen

**Probleem:** Tijdens het testen bleek dat de Arduino vastloopt wanneer de wifi-verbinding wegvalt. Het programma blijft proberen verbinding te maken en crasht uiteindelijk.

**Aanpassing:** De wifi-verbinding wordt aangepast, zodat de Arduino op een veilige manier opnieuw verbinding probeert te maken. Wanneer dit niet lukt, geeft het programma een passende foutmelding.

**Resultaat:** [Na het aanpassen en testen invullen.]

## 2. Uitval van Home Assistant

**Probleem:** Wanneer Home Assistant niet beschikbaar is of uitvalt, ontvangt de Arduino statuscode -3.

**Aanpassing:** De foutafhandeling bij een onbereikbare Home Assistant wordt verbeterd. Het programma geeft een passende foutmelding in plaats van alleen statuscode -3. Daarnaast blijft de Arduino controleren of er opnieuw verbinding gemaakt kan worden met Home Assistant.

**Resultaat:** [Na het aanpassen en testen invullen.]

## 3. Ongeldige sensorwaarden controleren

**Probleem:** Wanneer een sensor wordt losgekoppeld, controleert het programma niet op ongeldige of ontbrekende meetwaarden. Deze waarden worden daardoor alsnog naar Home Assistant verstuurd.

**Aanpassing:** Er wordt een controle toegevoegd om te bepalen of de meetwaarden geldig zijn. Ongeldige waarden worden niet naar Home Assistant verstuurd.

**Resultaat:** [Na het aanpassen en testen invullen.]

## Conclusie
Na het doorvoeren van de aanpassingen worden de tests opnieuw uitgevoerd. Op basis van de resultaten wordt gecontroleerd of de gevonden problemen zijn opgelost en of het systeem betrouwbaarder werkt.