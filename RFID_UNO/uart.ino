void func_uart() 
{  
  if (Serial.available()){

    a2 = Serial.read() - '0';
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

  }
}
