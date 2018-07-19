void func_read_write()
{
  
  if (millis() - previous_read >= NODE_READ_DELAY) {
    previous_read = millis();;
    Serial.print("Sensor value1 ");
    if (Wire.available()){// == TO_SLAVE_SIZE){
      Serial.print("Sensor value2 ");
      readFromMaster();
      sendToMaster();
    }
  }
}

void readFromMaster() {
  for(int i = 0; i < TO_SLAVE_SIZE; i ++){
    nodeReceive[i] = Wire.read();
  }
  Serial.print("Master says ");
  for(int i = 0; i < TO_SLAVE_SIZE; i ++){
    Serial.print(nodeReceive[i]);  
  }
  Serial.println();
}

void sendToMaster() {
  int x = analogRead(A0);
  messageToMaster[0] = 1;
  messageToMaster[1] = (x>>8) & 0xff;  // the top byte of x
  messageToMaster[2] = (x   ) & 0xff;  // the bottom byte of x
  Wire.write(messageToMaster, TO_MASTER_SIZE);  

  Serial.print("Sensor value: ");
  Serial.println(x);
}
