void func_gprs() {

    tone(buzz, 1000);
    delay(100);
    noTone(buzz);

    str1 = "1.php/";
    str1 += "a=";
    str1 += str;
    str1 += ";";

/*
        u8g.firstPage();  
        do {
          draw(9);
        } while( u8g.nextPage() );
        tone(buzz, 200);
        delay(600);
        noTone(buzz);
        delay(3000);
        return;*/

    signal_level_str = "";

//    parse_dani(signal_level_str);
}
  
void parse_dani(String &outstr)
{
  if (outstr.indexOf("a=")>-1){
    outstr = outstr.substring(outstr.indexOf("a=")+2, outstr.length());
  
    a2 = outstr.toInt();
      u8g.firstPage();  
  do {
    draw(a2);
  } while( u8g.nextPage() );
  if (a2==1){
    tone(buzz, 1000);
    delay(500);
    tone(buzz, 2000);
    delay(400);
    noTone(buzz);
  }else{
    tone(buzz, 200);
    delay(600);
    noTone(buzz);
    delay(2000);
  }
    u8g.firstPage();  
  do {
    draw(0);
  } while( u8g.nextPage() );
//    Serial.print("a2=");
//    Serial.println(a2);
/*    u8g.firstPage();  
  do {
    draw(a2);
  } while( u8g.nextPage() );*/
  }
}

