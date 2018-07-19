

//============

void parseData() {      // разделение данных на составляющие части
/*
    char * strtokIndx; // это используется функцией strtok() как индекс

    strtokIndx = strtok(tempChars,"=");      // получаем значение первой переменной - строку
    strcpy(messageFromPC, strtokIndx); //записываем её в переменную messageFromPC
 
    strtokIndx = strtok(NULL, "="); // продолжаем с последнего индекса
    integerFromPC = atoi(strtokIndx);     // конвертируем эту составляющую в integer

    //strtokIndx = strtok(NULL, "=");
    //floatFromPC = atof(strtokIndx);     // преобразовываем этот кусок текста в float
*/
}

//============

void showParsedData() {
    String strm;
    strm = String(messageFromPC);
    if (strm=="com") {com = integerFromPC; }
    if ((com/10000)==1) speedl += 20;
    if ((com/10000)==2) speedl -= 20;
    if ((com % 10000)/1000==1) speedr += 20;
    if ((com % 10000)/1000==2) speedr -= 20;
    
    if (speedl<-255) speedl = -255;
    if (speedl>255) speedl = 255;
    if (speedr<-255) speedr = -255;
    if (speedr>255) speedr = 255;
/*
    switch (com) {
    case 100:
      if (speedl==0){
        if (speedr < 0) {speedr = speedr - 20; if (speedr<-255) speedr = -255;}
        if (speedr >= 0) {speedr = speedr + 20; if (speedr>255) speedr = 255;}
      }
      if (speedl>0){if ((speedl > 0)and(speedl < 21)) {speedl = 0;} else {speedl = speedl - 20; if (speedl<-255) speedl = -255; } }
      if (speedl<0){if (speedl > -21) {speedl = 0;} else {speedl = speedl + 20; } }
      break;
    case 200:
      if (speedr==0){
        if (speedl < 0) {speedl = speedl - 20; if (speedl<-255) speedl = -255;}
        if (speedl >= 0) {speedl = speedl + 20; if (speedl>255) speedl = 255;}
      }
      if (speedr>0){if ((speedr > 0)and(speedr < 21)) {speedr = 0;} else {speedr = speedr - 20; if (speedr<-255) speedr = -255; } }
      if (speedr<0){if (speedr > -21) {speedr = 0;} else {speedr = speedr + 20; } }
      break;
    case 300:
      if ((speedl > 0)and(speedl < 21)) {speedl = 0;} else {speedl = speedl - 20; if (speedl<-255) speedl = -255; } 
      if ((speedr > 0)and(speedr < 21)) {speedr = 0;} else {speedr = speedr - 20; if (speedr<-255) speedr = -255; } 
      break;
    case 400:
      if ((speedl < 0)and(speedl > -19)) {speedl = 0;} else {speedl = speedl + 20; if (speedl>255) speedl = 255; } 
      if ((speedr < 0)and(speedr > -19)) {speedr = 0;} else {speedr = speedr + 20; if (speedr>255) speedr = 255; }
      break;  
    case 500:
      istep = 0; speedl = 0; speedr = 0; revers = 0;//stop
      break;  
    }
*/
    if(com == 500){
      istep = 0; speedl = 0; speedr = 0; comd[5] = 0;comd[6] = 0;comd[7] = 0; revers = 0;
    }else{
      if ((com % 10000 % 1000)/100==1) comd[5] = 40;
      if ((com % 10000 % 1000)/100==2) comd[5] = -40;
      if ((com % 10000 % 1000)/100==3) comd[5] = 0;

      if ((com % 10000 % 1000 % 100)/10==1) comd[6] = 100;
      if ((com % 10000 % 1000 % 100)/10==2) comd[6] = -100;
      if ((com % 10000 % 1000 % 100)/10==3) comd[6] = 0;

      if ((com % 10000 % 1000 % 100 % 10)==1) comd[7] = 80;
      if ((com % 10000 % 1000 % 100 % 10)==2) comd[7] = -80;
      if ((com % 10000 % 1000 % 100 % 10)==3) comd[7] = 0;

      if (com>0) {Serial.print("comd7: ");
         Serial.println(comd[7]);}
    }
    
    comold = com;
    com = 0;
    if ((speedl==0)and(speedr==0)) istep=0;
    comd[1] = speedl;
    comd[3] = speedl;
    comd[2] = speedr;
    comd[4] = speedr;
    
    
    strcpy(messageFromPC, ""); strm = "";
}
