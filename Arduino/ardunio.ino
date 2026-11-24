#include <DHT.h>
#include <WiFiS3.h>
#include <ArduinoHttpClient.h>

// WIFI-INSTELLINGEN
// Vul hier je eigen wifi-gegevens in voordat je de code uploadt.
const char ssid[] = "VUL_HIER_JE_WIFI_NAAM_IN";
const char password[] = "VUL_HIER_JE_WIFI_WACHTWOORD_IN";

// WEB SERVER VOOR POMPCOMMANDO'S
WiFiServer server(8000);

const int motorA_DIR = 12;
const int motorA_PWM = 3;
const int motorA_BRAKE = 9;

// HOME ASSISTANT
const char homeServer[] = "192.168.2.12";
const int port = 80;
const char webhook[] = "/api/webhook/arduino_uno_r4";

// SENSOREN
const int sensorPin = A0;
String pomp = "uit";

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// WIFI EN HTTP
WiFiClient wifi;
HttpClient client(wifi, homeServer, port);

// POMP FUNCTIES
void pompAan() {
  digitalWrite(motorA_DIR, HIGH);
  digitalWrite(motorA_BRAKE, LOW);
  analogWrite(motorA_PWM, 255);
  pomp = "aan";
}

void pompUit() {
  analogWrite(motorA_PWM, 0);
  digitalWrite(motorA_BRAKE, HIGH);
  pomp = "uit";
}

void setup() {
  pinMode(motorA_DIR, OUTPUT);
  pinMode(motorA_PWM, OUTPUT);
  pinMode(motorA_BRAKE, OUTPUT);

  Serial.begin(9600);
  dht.begin();

  Serial.println("Arduino starten...");
  Serial.println("Verbinden met wifi...");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Wifi verbonden!");

  Serial.print("IP-adres Arduino: ");
  Serial.println(WiFi.localIP());

  server.begin();
  Serial.println("Webserver gestart!");
}

void loop() {
  // Sensorwaarden uitlezen
  float temperatuur = dht.readTemperature();
  float luchtvochtigheid = dht.readHumidity();
  int grondvochtigheid = analogRead(sensorPin);

  Serial.print("IP-adres Arduino: ");
  Serial.println(WiFi.localIP());

  // JSON maken voor Home Assistant
  String json = "{";

  json += "\"apparaat\":\"Arduino UNO R4\",";
  json += "\"grondvochtigheid\":" + String(grondvochtigheid) + ",";

  json += "\"temperatuur\":";
  json += isnan(temperatuur) ? "null" : String(temperatuur, 1);
  json += ",";

  json += "\"pompstatus\":\"";
  json += pomp;
  json += "\",";

  json += "\"luchtvochtigheid\":";
  json += isnan(luchtvochtigheid) ? "null" : String(luchtvochtigheid, 1);

  json += "}";

  Serial.println("Sensorwaarden:");
  Serial.println(json);

  send(json);

  // Webserver controleren op pompcommando's
  // Let op: tijdens deze wachttijd kan de Arduino geen nieuw GET-commando verwerken.
  delay(5000);

  WiFiClient webClient = server.available();

  if (webClient) {
    Serial.println("Nieuwe verbinding!");

    String request = webClient.readStringUntil('\r');
    Serial.println(request);

    // HTTP-headers uitlezen
    while (webClient.connected()) {
      String header = webClient.readStringUntil('\n');
      if (header == "\r" || header.length() == 0) {
        break;
      }
    }

    String response = "Onbekende opdracht";

    if (request.indexOf("GET /pomp/aan ") >= 0) {
      pompAan();
      response = "Waterpomp staat AAN";
      Serial.println(response);
    } else if (request.indexOf("GET /pomp/uit ") >= 0) {
      pompUit();
      response = "Waterpomp staat UIT";
      Serial.println(response);
    }

    // Antwoord terugsturen
    webClient.println("HTTP/1.1 200 OK");
    webClient.println("Content-Type: text/plain");
    webClient.println("Connection: close");
    webClient.println();
    webClient.println(response);

    delay(10);
    webClient.stop();

    Serial.println("Verbinding gesloten");
  }
}

void send(String json) {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Wifi niet verbonden!");
    return;
  }

  Serial.println("Versturen naar Home Assistant...");

  client.beginRequest();
  client.post(webhook);
  client.sendHeader("Content-Type", "application/json");
  client.sendHeader("Content-Length", json.length());

  client.beginBody();
  client.print(json);
  client.endRequest();

  int statusCode = client.responseStatusCode();

  Serial.print("HTTP status: ");
  Serial.println(statusCode);

  String response = client.responseBody();

  Serial.println("Antwoord:");
  Serial.println(response);

  client.stop();
}
