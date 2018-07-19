#include <SPI.h>         // needed for Arduino versions later than 0018
#include <Ethernet_STM.h>
#include <EthernetUdp.h>         // UDP library from: bjoern@cs.stanford.edu 12/30/2008
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
#if defined(WIZ550io_WITH_MACADDRESS) // Use assigned MAC address of WIZ550io
;
#else
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
#endif  
IPAddress ip(192, 168, 5, 5);

unsigned int localPort = 5000;      // local port to listen on

// buffers for receiving and sending data
char packetBuffer[UDP_TX_PACKET_MAX_SIZE]; //buffer to hold incoming packet,
char  ReplyBuffer[] = "acknowledged";       // a string to send back

// An EthernetUDP instance to let us send and receive packets over UDP
EthernetUDP Udp;

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 20, 4);



unsigned long previousMillis = 0;
unsigned long previousSEND;
unsigned long currentMillis;
byte u1;
union u_tag2 {
   char b[4];
   float fval;
  } u2;

int comspeedl, comspeedr;
//float ileft, iright, tleft, tright;
unsigned int com; //stop vpered nazad

uint8_t XYleft_old, XYright_old;
//const int uppin = 6;
//const int downpin = 8;
//const int leftpin = 7;
//const int rightpin = 5;
const int stoppin = PA8;
const int XYleft = PA0;
const int XY1 = PB0;
const int XY2 = PA3;
const int XY3 = PA2;
const int XYright = PA1;


int comold;
byte by[6];
byte degree[8] = {B00110, B01001, B01001, B00110, B00000, B00000, B00000};//символ градуса С

//read serial
const byte numChars = 16;
char receivedChars[numChars];
char tempChars[numChars];    // временный массив используется во время парсинга
      // переменные для хранения полученных данных
char messageFromPC[numChars] = {0}; //текстовые данные
int integerFromPC = 0; //целочисленные данные
float floatFromPC = 0.0;  //вещественные данные
//float floatFromPC2 = 0.0;  //вещественные данные
//float floatFromPC3 = 0.0;  //вещественные данные
//float floatFromPC4 = 0.0;  //вещественные данные
float strum[7], rpm[7], temper[7];
int zadan[7];
boolean newData = false;

int led[6] = {};

void setup(void) {
  Serial.begin(9600);
  
  #if defined(WIZ550io_WITH_MACADDRESS)
  Ethernet.begin(ip);
#else
  Ethernet.begin(mac,ip);
#endif  
  Udp.begin(localPort);
  

//  pinMode(uppin, INPUT_PULLUP);
//  pinMode(downpin, INPUT_PULLUP);
//  pinMode(leftpin, INPUT_PULLUP);
//  pinMode(rightpin, INPUT_PULLUP);
  pinMode(stoppin, INPUT_PULLUP);
 
  lcd.begin();
  lcd.createChar(2, degree);
  Serial.println("SETUP");
}

void loop(void) {
  func_menu();
  func_sendether();
/*
   // if there's data available, read a packet
  int packetSize = Udp.parsePacket();
  if(packetSize)
  {
    Serial.print("Received packet of size ");
    Serial.println(packetSize);
    Serial.print("From ");
    IPAddress remote = Udp.remoteIP();
    for (int i =0; i < 4; i++)
    {
      Serial.print(remote[i], DEC);
      if (i < 3)
      {
        Serial.print(".");
      }
    }
    Serial.print(", port ");
    Serial.println(Udp.remotePort());

    // read the packet into packetBufffer
    Udp.read(packetBuffer,UDP_TX_PACKET_MAX_SIZE);
    Serial.println("Contents:");
    Serial.println(packetBuffer);
  }
  delay(10);
*/
  
  delay(1);
}
