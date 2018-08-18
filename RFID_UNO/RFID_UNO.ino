#include <SPI.h>
#include <MFRC522.h>
#include "U8glib.h"

#define buzz 6
//RFID
#define RST_PIN    5
#define SS_PIN    3
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

U8GLIB_ST7920_128X64_1X u8g(9, 8, 7); //SCK = en = 18, MOSI = rw = 16, CS = di = 17
const char *menu_strings[10] = { "  ОЖИДАНИЕ", "  ПРОХОДИTE", " 3AПPEЩEHO", " ТРИ", " ЧЕТЫРЕ", " ПЯТЬ", " ШЕСТЬ", "СЕМЬ", "  ПPOBEPKA", " ОШИБКА" };
//const char *menu_strings[9] = { "  O\266\270\264AH\270E", "  \277POXO\264\270TE", " 3A\277PEЙEHO", "\260\261\262\263\264\265\266\267\270\271\272\273\274", "eegbbrtn", "rtntymyilui,b", "weteryrtyrt", "w34ryrtyrt", "  \277POBEPKA" };
// \260
// \261
// \262
// \263
// \264
// \265
// \266
// \267
// \270
// \271
// \272
// \273
// \274

#define OK 1
#define NOTOK 2
#define TIMEOUT 3

byte index[10];
char end_c[2];
int dosend=0;
int a2;

String str, str1;
String signal_level_str;

void setup() {
  Serial.begin(9600);

  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init();
  
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
    u8g.setColorIndex(255);     // white
  }
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g.setColorIndex(3);         // max intensity
  }
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1);         // pixel on
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255,255,255);
  }
  
  rfidtimer();
  u8g.firstPage();  
  do {
    draw(0);
  } while( u8g.nextPage() );
    pinMode(buzz, OUTPUT);
    tone(buzz, 1000);
    delay(100);
    noTone(buzz);

//  attachInterrupt(digitalPinToInterrupt(7), func_start, FALLING);
}

void loop() {
    delay(50);
    
    if (dosend==1) {func_gprs();}
    func_uart();
    dosend=0;
}

