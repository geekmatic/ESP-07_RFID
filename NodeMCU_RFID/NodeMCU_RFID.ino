#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiServer.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <SoftwareSerial.h>

String str;
int j=0;
SoftwareSerial outSerial(4, 5); // RX, TX
#define USE_SERIAL Serial

ESP8266WiFiMulti WiFiMulti;

char ind[10];
byte a2;
int8_t send_a_to_uno;

void setup() {
   
    USE_SERIAL.begin(9600);
    outSerial.begin(9600);

    for(uint8_t t = 4; t > 0; t--) {

        USE_SERIAL.printf("[SETUP] WAIT %d...\n", t);

        USE_SERIAL.flush();

        delay(1000);

    }

    WiFiMulti.addAP("strike1", "0683609382");
    delay(5000);

}

void loop() {

 /*   

  */
  func_uart();
  delay(1);

}
