#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include "index.h" 

#if ARDUINO_USB_CDC_ON_BOOT
#define UART0 Serial0
#else
#define UART0 Serial
#endif

String uart_buffer = "";
const uint32_t communicationTimeout_ms = 500;
SemaphoreHandle_t uart_buffer_Mutex = NULL;
uint32_t counter = 0;

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

  server.on("/Rad", HTTP_GET, [](AsyncWebServerRequest* request) 
  { 
    int Rad = random(999);;
    String RadStr = String(Rad);
    Serial.println(RadStr);
    request->send(1000, "text/plain", uart_buffer);
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
      uart_buffer = ""; 
      xSemaphoreGive(uart_buffer_Mutex);
      delay(1000);
    }
  }  
}