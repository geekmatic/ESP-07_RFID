
//============

void parseData() {      // разделение данных на составляющие части
/*
    char * strtokIndx; // это используется функцией strtok() как индекс

    strtokIndx = strtok(tempChars,"=");      // получаем значение первой переменной - строку
    strcpy(messageFromPC, strtokIndx); //записываем её в переменную messageFromPC
 
    //strtokIndx = strtok(NULL, "="); // продолжаем с последнего индекса
    //integerFromPC = atoi(strtokIndx);     // конвертируем эту составляющую в integer

    strtokIndx = strtok(NULL, "=");
    floatFromPC = atof(strtokIndx);     // преобразовываем этот кусок текста в float

*/
}

//============

void showParsedData() {
  union u_tag {
    byte b[4];
    float fval;
  } u;
/*
  u.b[0] = by[0]; u.b[1] = by[1]; u.b[2] = by[2]; u.b[3] = by[3];
    if ((by[4]==0)&&(by[5]==1)) strum[1] = u.fval;
    if ((by[4]==0)&&(by[5]==2)) strum[2] = u.fval;
    if ((by[4]==0)&&(by[5]==3)) strum[3] = u.fval;
    if ((by[4]==0)&&(by[5]==4)) strum[4] = u.fval;

    if ((by[4]==0)&&(by[5]==5)) rpm[1] = u.fval;
    if ((by[4]==0)&&(by[5]==6)) rpm[2] = u.fval;
    if ((by[4]==0)&&(by[5]==7)) rpm[3] = u.fval;
    if ((by[4]==0)&&(by[5]==8)) rpm[4] = u.fval;
    
    if ((by[4]==0)&&(by[5]==9)) temper[1] = u.fval;
    if ((by[4]==0)&&(by[5]==10)) temper[2] = u.fval;
    if ((by[4]==0)&&(by[5]==11)) temper[3] = u.fval;
    if ((by[4]==0)&&(by[5]==12)) temper[4] = u.fval;

    if ((by[4]==0)&&(by[5]==13)) zadan[1] = u.fval;  
    if ((by[4]==0)&&(by[5]==14)) zadan[2] = u.fval; 
    if ((by[4]==0)&&(by[5]==15)) zadan[3] = u.fval; 
    if ((by[4]==1)&&(by[5]==0)) zadan[4] = u.fval;   
    */
}
