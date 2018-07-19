void func_rg()
{
  g[2] = u2.b[0]; g[3] = u2.b[1]; g[4] = u2.b[2]; g[5] = u2.b[3];
}

void Ether() {
  int success;
  String str;
  
  if (((signed long)(millis()-next))>0)
    {
      do
        {
          success = udp.beginPacket(IPAddress(192,168,5,5),5000);
//          Serial.print("beginPacket: ");
//         Serial.println(success ? "success" : "failed");
        }
      while (!success && ((signed long)(millis()-next))<0);
      if (!success )
        goto stop;
    switch (y) {
    case 0:
      str = "i1="; str += strum[1]; str += ";";
    break;
    case 1:
      str = "i2=";
      str += strum[2];str += ";";
    break;
    case 2:
      str = "i3=";
      str += strum[3];str += ";";
    break;
    case 3:
      str = "i4=";
      str += strum[4];str += ";";
    break;
    case 4:
      str = "s1=";
      str += rpm[1];str += ";";
    break;
    case 5:
      str = "s2=";
      str += rpm[2];str += ";";
    break;
    case 6:
      str = "s3=";
      str += rpm[3];str += ";";
    break;
    case 7:
      str = "s4=";
      str += rpm[4];str += ";";
    break;
    case 8:
      str = "t1=";
      str += temper[1];str += ";";
    break;
    case 9:
      str = "t2=";
      str += temper[2];str += ";";
    break;
    case 10:
      str = "t3=";
      str += temper[3];str += ";";
    break;
    case 11:
      str = "t4=";
      str += temper[4];str += ";";
    break;
    case 12:
      str = "z1=";
      str += speedl;str += ";";
    break;
    case 13:
      str = "z2=";
      str += speedr;str += ";";
    break;
    case 14:
      str = "z3=";
      str += speedl;str += ";";
    break;
    case 15:
      str = "z4=";
      str += speedr;str += ";";
     break;
     case 16:
      str = "u1=";
      str += u1;str += ";";
     break;
    }
    y++;
    if (y>16) y=0;
  
      
//      Serial.println(str);
      char text[20];
      str.toCharArray(text, str.length()+1);
      //Serial.println(text);
      success = udp.write(text);
//  Serial.println(success ? "write success" : "write failed");
      /*
      char text[50];
      str.toCharArray(text, str.length()+1);
      Serial.println(text);
      success = udp.write(text);
*/
     // Serial.println(success);
      success = udp.endPacket();

      do
        {
          //check for new udp-packet:
          success = udp.parsePacket();
        }
      while (!success && ((signed long)(millis()-next))<0);
     // Serial.println(success ? "parse success" : "parse failed");
      if (!success )
        goto stop;

      do
        {
          char* msg = (char*)malloc(success+1);
          int len = udp.read(msg,success+1);
          msg[len]=0;
          char * strtokIndx; // это используется функцией strtok() как индекс
//Serial.println(msg);
          strtokIndx = strtok(msg,"=");      // получаем значение первой переменной - строку
          strcpy(messageFromPC, strtokIndx); //записываем её в переменную messageFromPC
        
          strtokIndx = strtok(NULL, "="); // продолжаем с последнего индекса
          integerFromPC = atoi(strtokIndx);     // конвертируем эту составляющую в integer
          showParsedData();   
          free(msg);      
        }
      while ((success = udp.available())>0);
      //Serial.print(len);
      //Serial.println(" bytes");
      //finish reading this packet:
      udp.flush();

      stop:
      udp.stop();
      next = millis()+50;
      
      udp.begin(5000);
    }

}    
