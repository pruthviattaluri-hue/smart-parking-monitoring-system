#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

WebServer server(80);

int slot1 = 0;
int slot2 = 0;

void handleRoot() {
  String html = "<html><head><title>Smart Parking</title></head><body>";
  html += "<h1>Smart Parking Monitoring System</h1>";

  html += "<p>Slot 1: ";
  html += (slot1 == 1) ? "Occupied</p>" : "Vacant</p>";

  html += "<p>Slot 2: ";
  html += (slot2 == 1) ? "Occupied</p>" : "Vacant</p>";

  html += "</body></html>";
  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(9600);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  server.on("/", handleRoot);
  server.begin();
}

void loop() {
  server.handleClient();

  if (Serial.available()) {
    String data = Serial.readStringUntil('\n');
    int commaIndex = data.indexOf(',');

    if (commaIndex > 0) {
      slot1 = data.substring(0, commaIndex).toInt();
      slot2 = data.substring(commaIndex + 1).toInt();
    }
  }
}
