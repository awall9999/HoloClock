void DispOUT(){
  
      digitalWrite(Latch, LOW);
      for (int Register = 0; Register <= 3; Register++) {
           
           shiftOut(DataShift, ClockShift, MSBFIRST, DisplayData[Register]); // Write the Data in the 4 ShiftRegisters
           
           
              
          }
      digitalWrite(Latch, HIGH); 
        
}



void ClearDisplay(){ // Self explaining :)
  for (int i = 0; i <= 3; i++) {
 DisplayData[i] = 0;
 }
 DispOUT();
}
