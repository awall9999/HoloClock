void SetTime()
{
int IdleTime = 0;
int DisplayOnOff=1;
int BlockButtonSelect = 0;
Timer = millis();
SetMode=1;
PushButtonTime = 0;
TimeToWord();
do{


if (digitalRead(Set) == 1 && BlockButtonSet == 0){BlockButtonSet = 1;PushButtonTime++;IdleTime=0;} // let pass one impulse of the Set button, then block Set button and count the pushcounter up

if (digitalRead(Set) == 0){BlockButtonSet = 0;PushButtonTime=0;} // when Set Button released, reset all Block Button and Pushcounter

if (digitalRead(Select) == 1 && BlockButtonSelect == 0){                      //let pass one impulse of the Select button,
                                                        
                                                        BlockButtonSelect = 1;
                                                        IdleTime=0;
                                                        DisplayOnOff=0;
                                                        if (SetMode==1) {     //if Mode 1 change Minutes
                                                                          
                                                                          Minute++;
                                                                          if (Minute > 59) {Minute=0;}
                                                                          }
                                                        if (SetMode==2) {     ////if Mode 1 change Hours
                                                                          
                                                                          Hour++;
                                                                          if (Hour > 12) {Hour=1;}
                                                                          }
                                                        
                                                        TimeToWord();
                                                       }
if (digitalRead(Select) == 0 ){BlockButtonSelect = 0;} // If Select Button is released, reset the BlockButton


if ((unsigned long)(millis() - Timer) > 500)   {
                                                IdleTime++;Timer = millis();
                                                BlockButtonSet = 0;
                                                digitalWrite(OE,DisplayOnOff); DisplayOnOff=!DisplayOnOff;
                                                if (PushButtonTime == 5) {
                                                                           PushButtonTime = 0;
                                                                           SetMode++;          // Enter next Set Mode
                                                                           Serial.println(SetMode);
                                                                           TimeToWord();
                                                                           if (SetMode > 2) {SetMode=0;IdleTime=99;SetRTC();} // If setmode 3 Reset all and write new Time to RTC
                                                                           
                                                                         }
                                                }
}while (IdleTime < 60); // If IdleTime reached, go back to normal, without writing the Time to the RTC
digitalWrite(OE,LOW);
SetMode=0;
TimeToWord();





  
}
