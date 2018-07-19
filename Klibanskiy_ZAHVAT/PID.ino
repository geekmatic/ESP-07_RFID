void func_pid()
{  
  if (Kp>=0.0) error = SP1 - T1; else error = T1 - SP1;
  errSum += error;
  //if (Ki *errSum/100.0>OUTMAX) errSum=OUTMAX*100.0/Ki;
  //if (Ki *errSum/100.0<-OUTMAX) errSum=-OUTMAX*100.0/Ki;
  output = abs(Kp) * error + Ki * errSum/1000.0;
  if ((output > OUTMAX)||(output < OUTMIN)) errSum = ((PIDOUT - (abs(Kp) * error))/Ki) * 1000.0;
  
  PIDOUT = output;
  if (PIDOUT>OUTMAX) PIDOUT=OUTMAX;
  if (PIDOUT<OUTMIN) PIDOUT=OUTMIN;
}
