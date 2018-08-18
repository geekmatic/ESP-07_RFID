void func_uart()
{
  
  byte error;

  
  if (outSerial.available()){

    ind[j] = outSerial.read();
    
    USE_SERIAL.print(j);
    USE_SERIAL.print("=");
    USE_SERIAL.print(ind[j]);
    USE_SERIAL.print(" ");
    if (ind[j] == ':') j=0; else if(j<9)j++;
    
  }
  //USE_SERIAL.println(ind[8]);
  if (ind[8] == ';') {func_http(); USE_SERIAL.println(); j = 0;}
  ind[8] = 0;
/*      if (send_a_to_uno==1){
        Wire.beginTransmission(15);   
        Wire.write(a2); 
        Wire.endTransmission();  
        send_a_to_uno = 0; 
      }    */ 
 /*

      int j=0;
      while (Wire.available()) {
        ind[j] = Wire.read();
        if (ind[0]!=0) USE_SERIAL.print(ind[j], HEX);
        if(j<7)j++;
      }
      if (ind[0]!=0) {USE_SERIAL.println(""); func_http(); }
    }
    */
}
