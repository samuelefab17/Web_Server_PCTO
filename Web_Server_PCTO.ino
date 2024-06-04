#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include "index.h" 

const char* ssid = "FORZAFERRARI";
const char* password = "noverstappen";

AsyncWebServer server(80);

int test;

void setup() 
{
  Serial.begin(115200);

  WiFi.mode(WIFI_AP); 
  WiFi.softAP(ssid, password);    

  Serial.println(WiFi.softAPIP());  

  server.on("/", HTTP_GET, [](AsyncWebServerRequest* request) 
  {
    request->send(200, "text/html", webpage);
  });

  server.on("/Rad", HTTP_GET, [](AsyncWebServerRequest* request) 
  {
    float Rad = test;
    String RadStr = String(Rad);
    request->send(1000, "text/plain", RadStr);
  });
  server.begin();
}

void loop() 
{
  test = random(999);
  char stringa[20];
  while (Serial.available() == false) 
  {
    Serial.readBytes(stringa, 20);
    Serial.println(stringa);
  }
  delay(1000);
}