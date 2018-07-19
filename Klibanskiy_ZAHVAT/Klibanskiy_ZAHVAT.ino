#include "EmonLib.h"           // Include Emon Library
#include "Wire.h"

//PID
float PIDOUT = 0;
float error, errSum, output, derror;
float Kp, Ki;
int OUTMIN=0, OUTMAX=255, MANOUT, PIDon;
float T1, SP1;
//PID

#define SW11_pin A1
#define SW12_pin A2
#define INA1_pin 2
#define INB1_pin 3 
#define PWM1_pin 9
#define Strum1_pin A7

#define SW21_pin 7
#define SW22_pin 8
#define INA2_pin 4
#define INB2_pin 5 
#define PWM2_pin 10
#define Strum2_pin A6

#define SW31_pin A0
#define SW32_pin 12
#define INA3_pin 6
#define INB3_pin 13 
#define PWM3_pin 11
#define Strum3_pin A3

unsigned long previousMillis = 0;
unsigned long previous_termo;
unsigned long previous_read;
unsigned long currentMillis;

float temper;

float strum;
//EnergyMonitor emonl;

#define PIN_DO 2 // Установка контакта используемого в Arduino
volatile unsigned int pulses;
float rpm;
unsigned long timeOld;
#define HOLES_DISC 8

int com=0;

#define TO_MASTER_SIZE 3
#define TO_SLAVE_SIZE 4
#define NODE_READ_DELAY 200

byte messageToMaster[TO_MASTER_SIZE];
byte nodeReceive[TO_SLAVE_SIZE];



String inputString = "";         // переменная типа string для сохранения входных данных
boolean stringComplete = false;




void setup() {
  Serial.begin(9600); 

  //pinMode(PIN_DO, INPUT);
  pulses = 0;
  timeOld = 0;
  //attachInterrupt(digitalPinToInterrupt(PIN_DO), counter, FALLING);

  pinMode(SW11_pin, INPUT_PULLUP);
  pinMode(SW12_pin, INPUT_PULLUP);
  pinMode(INA1_pin, OUTPUT);
  pinMode(INB1_pin, OUTPUT);
  pinMode(PWM1_pin, OUTPUT);

  pinMode(SW21_pin, INPUT_PULLUP);
  pinMode(SW22_pin, INPUT_PULLUP);
  pinMode(INA2_pin, OUTPUT);
  pinMode(INB2_pin, OUTPUT);
  pinMode(PWM2_pin, OUTPUT);

  pinMode(SW31_pin, INPUT_PULLUP);
  pinMode(SW32_pin, INPUT_PULLUP);
  pinMode(INA3_pin, OUTPUT);
  pinMode(INB3_pin, OUTPUT);
  pinMode(PWM3_pin, OUTPUT);
  
  Wire.begin(50);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
  
  //emonl.current(1, 20/2.5); 
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(INA3_pin, HIGH);
  digitalWrite(INB3_pin, LOW);
  analogWrite(PWM3_pin, 210);
  delay(5000);
  analogWrite(PWM3_pin, 0);
  digitalWrite(INA3_pin, LOW);
  digitalWrite(INB3_pin, LOW);
  delay(5000);
  digitalWrite(INB3_pin, HIGH);
  digitalWrite(INA3_pin, LOW);
  analogWrite(PWM3_pin, 210);
  delay(5000);
  analogWrite(PWM3_pin, 0);
  delay(5000);
  //func_termo();
  
//  func_encoder();
  
  //func_read_write();
  
//  func_outs();
  delay(1);

  serialEvent(); //вызов нашей коммуникационной функции


  // печатаем ответ в COM-порт и поворачиваем серво на заданный угол:
  if (stringComplete) {
    Serial.println(inputString);
    
    analogWrite(PWM3_pin, inputString.toInt());

    // обнуляем строковую переменную:
    inputString = "";
    stringComplete = false;
  }
}

void serialEvent() {
  while (Serial.available()) {
    // получить новый байт данных:
    char inChar = (char)Serial.read();


    // добавить новый байт к строковой переменной inputString:
    inputString += inChar;


    // если входной символ является новой строкой, взвести флаг
    // что бы основной цикл обработал принятую команду:
    if (inChar == '\n') {
      stringComplete = true;
    }


  }
}
