void func_termo()
{
  
  if (millis() - previous_termo >= 1100) {
    previous_termo = millis();
    
//    strum = emonl.calcIrms(1480);  // Calculate Irms only
//    temper = float(Thermister(analogRead(A0)));
  }
}

float Thermister(int RawADC) {
  float Temp;
  Temp = log(((10240000/RawADC) - 10000));
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
  Temp = Temp - 273.15;   // Kelvin to Celcius
  
  return Temp;
}
