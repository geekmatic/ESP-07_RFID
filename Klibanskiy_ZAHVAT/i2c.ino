void requestEvent() 
{
  union u_tag {
   byte b[4];
   float fval;
  } u;
  
  u.fval = temper;
  
  Wire.write(u.b[0]);
  Wire.write(u.b[1]);
  Wire.write(u.b[2]);
  Wire.write(u.b[3]);
  u.fval = rpm;
  
  Wire.write(u.b[0]);
  Wire.write(u.b[1]);
  Wire.write(u.b[2]);
  Wire.write(u.b[3]);
  u.fval = strum;
  
  Wire.write(u.b[0]);
  Wire.write(u.b[1]);
  Wire.write(u.b[2]);
  Wire.write(u.b[3]);
}

void receiveEvent(int bytes)
{
  int i=0;
  
  while (Wire.available()) { // slave may send less than requested
    byte c = Wire.read(); // receive a byte as character
    
    if (i==0) com = ((c & 0xff) << 8); else com = com | c;
    i++;
  }
  
  //Serial.print("com ");
  //Serial.println(com);
}
