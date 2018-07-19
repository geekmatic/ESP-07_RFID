void func_sendether()
{
  union u_tag {
    byte b[4];
    float fval;
  } u;
  com = 0;
  if (currentMillis - previousSEND >= 1000) {
    uint16_t XYleft_val = analogRead(XYleft);
    uint16_t XYright_val = analogRead(XYright);
    previousSEND = currentMillis;
    
    
    if ((XYleft_val<100)) {com = 10000; }
    else if ((XYleft_val>3500)) {com = 20000; } 
    //if ((XYleft_val>500)&&(XYleft_val<3500)) XYleft_old =0;
    if ((XYright_val<100)) {com += 1000; }
    else if ((XYright_val>3500)) {com += 2000; }
    //if ((XYright_val>500)&&(XYright_val<3500)) XYright_old =0;
  }
  
    if (analogRead(XY1)<100) com += 100;
    else if (analogRead(XY1)>3500) com += 200; else com += 300;
    if (analogRead(XY2)<100) com += 10; 
    else if (analogRead(XY2)>3500) com += 20; else com += 30;
    if (analogRead(XY3)<100) com += 1; 
    else if (analogRead(XY3)>3500) com += 2; else com += 3;
//    Serial.print("XY3");
//    Serial.println(analogRead(XY3));
//    up = digitalRead(uppin);
//    down = digitalRead(downpin);
//    left = digitalRead(leftpin);
//    right = digitalRead(rightpin);
    
//    if ((!left)&&(left_old==true)) com = 100; 

//    if ((!right)&&(right_old==true)) com = 200;

//    if ((!down)&&(down_old==true)) com = 300;

//    if ((!up)&&(up_old==true)) com = 400;
 
    if (!digitalRead(stoppin)) com = 500;
    

  
     //check for new udp-packet:
  int packetSize = Udp.parsePacket();
  //Serial.print("parse size");
  //Serial.println(packetSize);
  if(packetSize){
    
//    do
//      {
        //char* msg = (char*)malloc(size+1);
        //int len = 
        Udp.read(packetBuffer,UDP_TX_PACKET_MAX_SIZE);
        //msg[len]=0;
//        Serial.print("packetBuffer=");
//        Serial.println(packetBuffer);
       
                
        
        char * strtokIndx; // это используется функцией strtok() как индекс

        strtokIndx = strtok(packetBuffer,"=");      // получаем значение первой переменной - строку
        strcpy(messageFromPC, strtokIndx); //записываем её в переменную messageFromPC
        

        strtokIndx = strtok(NULL, ";");
        floatFromPC = atof(strtokIndx);     // преобразовываем этот кусок текста в float
        String st = String(messageFromPC);
     if (st=="t1") {temper[1]=floatFromPC;// Serial.println(messageFromPC);Serial.println(floatFromPC);
     }
     if (st=="t2") temper[2]=floatFromPC;
     if (st=="t3") temper[3]=floatFromPC;
     if (st=="t4") temper[4]=floatFromPC;

     if (st=="i1") strum[1]=floatFromPC;
     if (st=="i2") strum[2]=floatFromPC;
     if (st=="i3") strum[3]=floatFromPC;
     if (st=="i4") strum[4]=floatFromPC;

     if (st=="s1") rpm[1]=floatFromPC;
     if (st=="s2") rpm[2]=floatFromPC;
     if (st=="s3") rpm[3]=floatFromPC;
     if (st=="s4") rpm[4]=floatFromPC;

     if (st=="z1") zadan[1]=floatFromPC;
     if (st=="z2") zadan[2]=floatFromPC;
     if (st=="z3") zadan[3]=floatFromPC;
     if (st=="z4") zadan[4]=floatFromPC;
     if (st=="u1") {
        u1 = atoi(strtokIndx);
        Wire.beginTransmission(0x38);
        Wire.write(~u1);
        Wire.endTransmission();
     }

//        free(packetBuffer);
//      }
    //while ((size = udp.available())>0);
    //finish reading this packet:
//    udp.flush();
    
    int success;
    
  currentMillis = millis();

  String str;

      str = "com=";
      str += com;
      str += "";
      Serial.println(str); 
      char text[10];
      str.toCharArray(text, 10);

      do
      {
        success = Udp.beginPacket(Udp.remoteIP(),Udp.remotePort());
        //Serial.println(success ? "beginPacket success" : "beginPacket failed");
      }
    while (!success);

      success = Udp.println(str);

    success = Udp.endPacket();

    comold = com;
    com = 0;
  

//    udp.stop();

 //   Serial.println (udp.begin(localPort) ? "success" : "failed");
  }
  
}

