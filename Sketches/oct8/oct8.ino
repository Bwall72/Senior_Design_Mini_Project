#include <OBD2UART.h>
#include <WiFiClient.h>
#include <HTTPClient.h>
#include "network.h"
#include "param.h"

void
setup()
{
  Serial.begin(115200);

  WiFi_connect();

   for ( ;; ) {
    delay(1000);
    byte version = obd.begin();

    if (version > 0) {
      Serial.println("Connected");
      break;
    }
    else {
      Serial.println("Adapter not connected");
      delay(2000);
    }
   }
}

void 
loop()
{
  if (take_reading() == 0) {
    Serial.println("Making post");
    HTTP_post();
  } 
}

