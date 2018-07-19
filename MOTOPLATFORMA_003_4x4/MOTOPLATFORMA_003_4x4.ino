#include <Wire.h>
#include <avr/wdt.h>//watchdog

#include <UIPEthernet.h>
#include <UIPServer.h>
#include <UIPClient.h>
EthernetUDP udp;
String strj;
unsigned long next;
const byte numChars = 10;
char messageFromPC[numChars] = {0}; //текстовые данные
union u_tag {
   byte b[4];
   float fval;
  } u;

union u_tag2 {
   char b[4];
   float fval;
  } u2;

float hh;

bool avarstop, avarstop_old;
int comd[8], comold, i;
byte by[6];
char g[6];

bool left, right, up, down, cstop, revers;
int com;
int y, w;
float v;
float rpm[8], temper[8], strum[8];

//read serial
int justread;

byte u1; //ultrazvuk avar and reglam

int integerFromPC = 0; //целочисленные данные
int floatFromPC = 0;  //вещественные данные
boolean newData = false;
//read serial

unsigned long previousMillis = 0;
unsigned long previousSEND;
unsigned long previous_termo;
unsigned long currentMillis;

//const int pina2 = 16;

int speedl;
int speedr, istep;

void setup(void) {
  //pinMode(pina2, INPUT_PULLUP);
  
    Serial.begin(9600);
    uint8_t mac[6] = {0x00,0x04,0x06,0x03,0x04,0x05};
    Ethernet.begin(mac,IPAddress(192,168,5,6));
    
    next = millis()+10;
  
 
  pinMode(5, OUTPUT);


  Wire.begin();
}

void loop(void) {
//  wdt_enable(WDTO_1S);//watchdog
  func_i2c();
  
  Ether();
  //func_relays();
//  wdt_reset(); //watchdog
}
