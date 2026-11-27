# Aanpassingsdocument

## Inleiding
Tijdens het testen van het automatisch plantbewateringsysteem zijn er een aantal verbeterpunten naar voren gekomen. Deze verbeterpunten zijn genoteerd in het testrapport. In dit document beschrijf ik welke aanpassingen ik heb doorgevoerd om het systeem betrouwbaarder te maken 

## 1. Wifi-verbinding herstellen
**Probleem:** Tijdens het testsen bleek dat de arduino vastloopt wanneer de wifi-verbinding wegvalt. Het programma blijft proberen verbinding te maken en crasht uiteindelijk.

**Aanpassing:** De wifi-verbinding word aangepast zodat de arduino op een veilige manier kan verbinden en geeft een gepaste error wanneer hij vastloopt.


## 2. Uitval home Assistant
**Probleem:** Wanneer de home Assistant niet beschikbaar is of uitvalt, ontvangt de arduino statuscode- 3


**Aanpassing:** De foutafhandeling van een niet bereikbare home assistant word verbeterd, en moet ervoor zorgen dat je nu een gepaste error melding krijgt inplaats van status code -3. En moet geduring blijven controlleren als hij kan verbinden met de homeAssitant als hij eruit ligt.


## 3. ongeldige sensorwaarden controlleren
**Probleem:** Wanneer er een sensor word losgekoppeld controlleerd het programma niet op ongeldige of ontbrekende meetwaarden. Deze waarden worden dan alsnog naar de home Assistant gestuurd.

**Aanpassing:** Er word een controlle toegevoegd om te bepalen als de meetwaarde ongeldig is. En ongeldige waarden worden dan niet naar de home assistant verstuurd.


## Conclusie 
Na het verhelpen van de problemmen worden die tests opnieuw uitgevoerd. En op bassis van de resultaten word gecontrolleerd als de gevonden problemen nu zijn opgelost en of het systeem nu veilig/betrouwbaar werkt. 