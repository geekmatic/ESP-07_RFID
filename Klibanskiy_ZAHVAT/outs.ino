void func_outs()
{
  int pwm;
  if ((!digitalRead(SW11_pin))&&(com>0)) com = 0;
  if ((!digitalRead(SW12_pin))&&(com<0)) com = 0;
  digitalWrite(4, com!=0);
  digitalWrite(5, com<0);
  pwm = map(abs(com), 0, 255, 0, 255);
  pwm = 255 - pwm;
  analogWrite(3, pwm);
}
