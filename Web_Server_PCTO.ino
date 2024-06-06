#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include "index.h" 
#include <string.h>

#if ARDUINO_USB_CDC_ON_BOOT
#define UART0 Serial0
#else
#define UART0 Serial
#endif

String uart_buffer = "";
const uint32_t communicationTimeout_ms = 500;
SemaphoreHandle_t uart_buffer_Mutex = NULL;
uint32_t counter = 0;
char *spazio = " ";
char *acce_char;
char *magn_char;
String acces;
String magns;

const char* ssid = "FORZAFERRARI";
const char* password = "noverstappen";

AsyncWebServer server(80);

int test;

void UART0_RX_CB() 
{
  if (xSemaphoreTake(uart_buffer_Mutex, portMAX_DELAY)) 
  {
    uint32_t now = millis();  
    while ((millis() - now) < communicationTimeout_ms) 
    {
      if (UART0.available()) 
      {
        uart_buffer += (char)UART0.read();
        now = millis();  
      }
    }
    xSemaphoreGive(uart_buffer_Mutex);
  }
}

void setup() 
{
  UART0.begin(9600);
  uart_buffer_Mutex = xSemaphoreCreateMutex();
  UART0.onReceive(UART0_RX_CB); 

  WiFi.mode(WIFI_AP); 
  WiFi.softAP(ssid, password);    

  Serial.println(WiFi.softAPIP());  

  server.on("/", HTTP_GET, [](AsyncWebServerRequest* request) 
  {
    request->send(200, "text/html", webpage);
  });

  server.on("/acces", HTTP_GET, [](AsyncWebServerRequest* request) 
  { 
    request->send(1000, "text/plain", acces);
  });

  server.on("/magns", HTTP_GET, [](AsyncWebServerRequest* request) 
  { 
    request->send(1000, "text/plain", magns);
  });

  server.begin();
}

void loop() 
{
  if (uart_buffer.length() > 0) 
  {
    if (xSemaphoreTake(uart_buffer_Mutex, portMAX_DELAY)) 
    {
      UART0.print(uart_buffer);
      char myString[16];
      uart_buffer.toCharArray(myString, 16);
      acce_char = strtok(myString, spazio);
      magn_char = strtok(NULL, spazio);
      acces = String(acce_char);
      magns = String(magn_char);
      xSemaphoreGive(uart_buffer_Mutex);
      uart_buffer = "";
    }
  }  
}