void func_by()
{
  by[0] = u.b[0]; by[1] = u.b[1]; by[2] = u.b[2]; by[3] = u.b[3];
}

void func_send()
{  
  /*if (millis() - previousSEND >= 50) {
    previousSEND = millis();
    switch (y) {
    case 0:
      u.fval = strum[1];
      func_by(); by[4] = 0; by[5] = 1;
      radio.write(by, 6);
    break;
    case 1:
      u.fval = strum[2];
      func_by(); by[4] = 0; by[5] = 2;
      radio.write(by, 6);
    break;
    case 2:
      u.fval = strum[3];
      func_by(); by[4] = 0; by[5] = 3;
      radio.write(by, 6);
    break;
    case 3:
      u.fval = strum[4];
      func_by(); by[4] = 0; by[5] = 4;
      radio.write(by, 6);
    break;
    case 4:
      u.fval = rpm[1];
      func_by(); by[4] = 0; by[5] = 5;
      radio.write(by, 6);
    break;
    case 5:
      u.fval = rpm[2];
      func_by(); by[4] = 0; by[5] = 6;
      radio.write(by, 6);
    break;
    case 6:
      u.fval = 366;//rpm[3];
      func_by(); by[4] = 0; by[5] = 7;
      radio.write(by, 6);
    break;
    case 7:
      u.fval = rpm[4];
      func_by(); by[4] = 0; by[5] = 8;
      radio.write(by, 6);
    break;
    case 8:
      u.fval = temper[1];
      func_by(); by[4] = 0; by[5] = 9;
      radio.write(by, 6);
    break;
    case 9:
      u.fval = temper[2];
      func_by(); by[4] = 0; by[5] = 10;
      radio.write(by, 6);
    break;
    case 10:
      u.fval = temper[3];
      func_by(); by[4] = 0; by[5] = 11;
      radio.write(by, 6);
    break;
    case 11:
      u.fval = temper[4];
      func_by(); by[4] = 0; by[5] = 12;
      radio.write(by, 6);
    break;
    case 12:
      u.fval = speedl;
      func_by(); by[4] = 0; by[5] = 13;
      radio.write(by, 6);
    break;
    case 13:
      u.fval = speedl;
      func_by(); by[4] = 0; by[5] = 14;
      radio.write(by, 6);
    break;
    case 14:
      u.fval = speedr;
      func_by(); by[4] = 0; by[5] = 15;
      radio.write(by, 6);
    break;
    case 15:
      u.fval = speedr;
      func_by(); by[4] = 1; by[5] = 0;
      radio.write(by, 6);
     break;
    }
    y++;
    if (y>15) y=0;
  }
*/
}  
