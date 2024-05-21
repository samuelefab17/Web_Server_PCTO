#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>

#include "index.h" 

WebServer server(80);

const char* ssid = "FORZAFERRARISEMPREE";
const char* password = "vesrtappenamuroesigode";

void handleRoot() {
 String html = main_html; 
 server.send(200, "text/html", html); 
}

void setup(void){
  Serial.begin(115200);
  Serial.println();
  Serial.println("Booting Sketch...");

  WiFi.mode(WIFI_AP); 
  WiFi.softAP(ssid, password);    

  Serial.println(WiFi.localIP());  
 
  server.on("/", handleRoot);     
 
  server.begin();                 
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();
  delay(1);
}
