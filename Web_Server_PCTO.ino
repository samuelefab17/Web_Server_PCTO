#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include "index.h"

int rad;

WebServer server(80);

void handleRoot() {
  rad = random(9999);
  String html = main_html;
  server.send(500, "text/html", html);
}

void setup(void) {
  Serial.begin(115200);

  const char* ssid = "FORZAFERRARISEMPREE";
  const char* password = "vesrtappenamuroesigode";

 WiFi.mode(WIFI_AP); 
  WiFi.softAP(ssid, password); 
  IPAddress ip = WiFi.softAPIP();
  Serial.print("IP address: ");
  Serial.println(ip);

  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
  delay(1000);
}