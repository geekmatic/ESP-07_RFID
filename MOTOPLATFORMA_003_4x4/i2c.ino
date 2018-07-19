void func_i2c()
{
  byte high[2];
  byte error;

//YLTRAZVUK  
  Wire.beginTransmission(15);
  error = Wire.endTransmission();
  if (error == 0)
  {
       Wire.requestFrom(15, 1, 1); // adr, bytes, 1-stop connection
       while (Wire.available()) {
         u1 = Wire.read();
         avarstop = bitRead(u1, 0);
         avarstop = avarstop | bitRead(u1, 2);
         avarstop = avarstop | bitRead(u1, 4);
         if (avarstop and !avarstop_old){
           comd[1] = 0;
           comd[3] = 0;
           comd[2] = 0;
           comd[4] = 0;
           speedl = 0;
           speedr = 0;
         }  
       }
  }
//YLTRAZVUK

//ZAHVAT    
    Wire.beginTransmission(50);
    error = Wire.endTransmission();
    if (error == 0)
    {
      Wire.beginTransmission(50);  
      high[0] = (comd[i] >> 8);
      high[1] = (comd[i] & 0xff); 
      Wire.write(high[0]);   
      Wire.write(high[1]); 
      high[0] = (comd[i] >> 8);
      high[1] = (comd[i] & 0xff);  
      Wire.write(high[0]);   
      Wire.write(high[1]); 
      high[0] = (comd[i] >> 8);
      high[1] = (comd[i] & 0xff); 
      Wire.write(high[0]);   
      Wire.write(high[1]);           
      Wire.endTransmission(); 
    }
//ZAHVAT 
  
  for(int i=1; i<8; i++){
    high[0] = (comd[i] >> 8);
    high[1] = (comd[i] & 0xff);
    Wire.beginTransmission(i);
    error = Wire.endTransmission();
    if (error == 0)
    {
      Wire.beginTransmission(i);   
      Wire.write(high[0]);   
      Wire.write(high[1]);              
      Wire.endTransmission();   
      
      Wire.requestFrom(i, 12, 1); // adr, bytes, 1-stop connection

      int j=0, m=1;
      while (Wire.available()) {
        byte c = Wire.read();
        u.b[j]=c;
    
        j++;
        if (j>3) {
          j=0; 
          if(m==1) temper[i] = u.fval;
          if(m==2) rpm[i] = u.fval;
          if(m==3) strum[i] = u.fval;
          m++;
        }
  
      }
    }
    
  }
  avarstop_old = avarstop;

}
