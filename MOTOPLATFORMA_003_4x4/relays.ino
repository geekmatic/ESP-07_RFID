void func_relays()
{/*
  if (speedl == 0){ //stop
    digitalWrite(pink1, HIGH);
    digitalWrite(pink2, HIGH);
    digitalWrite(pink5, HIGH);
  }

  if (speedr == 0){ //stop
    digitalWrite(pink3, HIGH);
    digitalWrite(pink4, HIGH);
    digitalWrite(pink6, HIGH);
  }

  if (speedl>0){ //up
    digitalWrite(pink1, HIGH);
    digitalWrite(pink2, HIGH);
    digitalWrite(pink5, LOW);
  }

  if (speedl<0){ //up
    digitalWrite(pink1, LOW);
    digitalWrite(pink2, LOW);
    digitalWrite(pink5, LOW);
  }

  if (speedr>0){ //back
    digitalWrite(pink3, HIGH);
    digitalWrite(pink4, HIGH);
    digitalWrite(pink6, LOW);
  }

  if (speedr<0){ //up
    digitalWrite(pink3, LOW);
    digitalWrite(pink4, LOW);
    digitalWrite(pink6, LOW);
  }

//  dacleft.setVoltage(abs(speedl), false);
//  dacright.setVoltage(abs(speedr), false);
  
  pwm1 = map(abs(speedl), 0, 255, 0, 255);
  pwm1 = 255 - pwm1;
  analogWrite(5, pwm1);

  pwmr = map(abs(speedr), 0, 255, 0, 255);
  pwmr = 255 - pwmr;
  analogWrite(6, pwmr);
  */
}

