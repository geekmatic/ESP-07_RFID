void func_menu()
{
  String str;
   currentMillis = millis();
  
  if (currentMillis - previousMillis >= 400) {
      previousMillis = currentMillis;
//Serial.println("ya zhivoy");
      
      lcd.setCursor(0, 0);
      str = map(zadan[1], -255, 255, -100, 100);
      str += " ";
      str += map(zadan[3], -255, 255, -100, 100);
      str += "%";
      while (str.length()<9){str += " ";}
      lcd.print(str);
      lcd.setCursor(10, 0);
      str = map(zadan[2], -255, 255, -100, 100);
      str += " ";
      str += map(zadan[4], -255, 255, -100, 100);
      str += "%";
      while (str.length()<9){str += " ";}
      lcd.print(str);

      lcd.setCursor(0, 1);
      str = int(rpm[1]);
      str += " "; 
      str += int(rpm[3]);
      str += "/m"; 
      
      while (str.length()<9){str += " ";}
      lcd.print(str);
      lcd.setCursor(10, 1);
      str = int(rpm[2]);
      str += " "; 
      str += int(rpm[4]);
      str += "/m";
      while (str.length()<9){str += " ";}
      lcd.print(str);
      
      lcd.setCursor(0, 2);
      str = String(strum[1], 1);
      str += " ";
      str += String(strum[3], 1);
      str += "A";
      while (str.length()<9){str += " ";}
      lcd.print(str);
      lcd.setCursor(10, 2);
      str = String(strum[2], 1);
      str += " ";
      str += String(strum[4], 1);
      str += "A";
      while (str.length()<9){str += " ";}
      lcd.print(str);
      
      lcd.setCursor(0, 3);
      str = int(temper[1]);
      str += " "; 
      str += int(temper[3]);
      str += "\2C"; 
      while (str.length()<9){str += " ";}
      lcd.print(str);
      lcd.setCursor(10, 3);
      str = int(temper[2]);
      str += " "; 
      str += int(temper[4]);
      str += "\2C";
      while (str.length()<9){str += " ";} 
      lcd.print(str);
  }
}
