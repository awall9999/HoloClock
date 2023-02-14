void DispOUT(){
  
      digitalWrite(Latch, LOW);
      for (int Register = 0; Register <= 3; Register++) {
           
           shiftOut(DataShift, ClockShift, MSBFIRST, DisplayData[Register]);
           
           
              
          }
      digitalWrite(Latch, HIGH); 
        
}

//void MicrosecDelay(int period){     // My Delay
//time_now = micros();
//do {

void ClearDisplay(){
  for (int i = 0; i <= 3; i++) {
 DisplayData[i] = 0;
 }
 DispOUT();
}
