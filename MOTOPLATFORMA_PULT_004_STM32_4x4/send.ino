void func_send()
{
  
  currentMillis = millis();

  String str;
  
  if (currentMillis - previousSEND >= 50) {
    previousSEND = currentMillis;

//    up = digitalRead(uppin);
//    down = digitalRead(downpin);
//    left = digitalRead(leftpin);
//    right = digitalRead(rightpin);
 

    com = 1;
/*    
    if ((!left)&&(left_old==true)) com = 100; 

    if ((!right)&&(right_old==true)) com = 200;

    if ((!down)&&(down_old==true)) com = 300;

    if ((!up)&&(up_old==true)) com = 400;

    if (!digitalRead(stoppin)) com = 500;
*/
    if (comold!=com){
      str = "com=";
      str += com;
      str += "";
      Serial.println(str); 
      char text[10];
      str.toCharArray(text, 10);
      
//      radio.write(&text, sizeof(text));
      
    }
    comold = com;

  }
  
}  
