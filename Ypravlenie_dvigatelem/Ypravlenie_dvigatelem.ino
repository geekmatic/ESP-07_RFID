#include "EmonLib.h"           // Include Emon Library
#include "Wire.h"

//PID
float PIDOUT = 0;
float error, errSum, output, derror;
float Kp, Ki;
int OUTMIN=0, OUTMAX=255, MANOUT, PIDon;
float T1, SP1;
//PID

unsigned long previousMillis = 0;
unsigned long previous_termo;
unsigned long previous_read;
unsigned long currentMillis;

float temper;

float strum;
EnergyMonitor emonl;

#define PIN_DO 2 // Установка контакта используемого в Arduino
volatile unsigned int pulses;
float rpm;
unsigned long timeOld;
#define HOLES_DISC 8

int com=0;
int swich =0;
int swich1 = 9;
int swich2 = 10;
int swich3 = 11;
int swich4 = 12;
int koncevik1 = 6;
int koncevik2 = 7;
int koncevik3 = 8;

#define TO_MASTER_SIZE 3
#define TO_SLAVE_SIZE 4
#define NODE_READ_DELAY 200

byte messageToMaster[TO_MASTER_SIZE];
byte nodeReceive[TO_SLAVE_SIZE];

void setup() {
  Serial.begin(9600); 

  pinMode(PIN_DO, INPUT);
  pulses = 0;
  timeOld = 0;
  attachInterrupt(digitalPinToInterrupt(PIN_DO), counter, FALLING);

  pinMode(swich1, INPUT_PULLUP);
  pinMode(swich2, INPUT_PULLUP);
  pinMode(swich3, INPUT_PULLUP);
  pinMode(swich4, INPUT_PULLUP);
  pinMode(koncevik1, INPUT_PULLUP);
  pinMode(koncevik2, INPUT_PULLUP);
  pinMode(koncevik3, INPUT_PULLUP);
  
  swich = swich | digitalRead(swich1);
  swich = swich << 1;
  swich = swich | digitalRead(swich2);
  swich = swich << 1;
  swich = swich | digitalRead(swich3);
  swich = swich << 1;
  swich = swich | digitalRead(swich4);
  
  Wire.begin(swich);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
  
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  emonl.current(1, 20/2.5); 
}

// the loop function runs over and over again forever
void loop() {
  func_termo();
  
  func_encoder();
  
  //func_read_write();
  
  func_outs();
  delay(1);
}
