void func_encoder()
{

  if (millis() - timeOld >= 1000)
  {
    detachInterrupt(digitalPinToInterrupt(PIN_DO));
    rpm = (pulses * 60) / 16;
 
    timeOld = millis();
    pulses = 0;
    attachInterrupt(digitalPinToInterrupt(PIN_DO), counter, FALLING);
    
  }
}

void counter()
{
 pulses++;
}
