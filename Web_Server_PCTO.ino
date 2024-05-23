#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include "index.h" 

const char* ssid = "FORZAFERRARISEMPREE";
const char* password = "vesrtappenamuroesigode";

int test;

AsyncWebServer server(80);

void setup() {
   Serial.begin(115200);

   WiFi.mode(WIFI_AP); 
   WiFi.softAP(ssid, password);    

   Serial.println(WiFi.softAPIP());  

   // Serve the HTML page from the file
   server.on("/", HTTP_GET, [](AsyncWebServerRequest* request) {

     request->send(200, "text/html", webpage);

  });

  // Define a route to get the temperature data
  server.on("/Rad", HTTP_GET, [](AsyncWebServerRequest* request) {

     float Rad = test;
     String RadStr = String(Rad);
     request->send(1000, "text/plain", RadStr);

  });

   server.begin();

}

void loop() {

   test = random(999);;
   delay(1000);

}
