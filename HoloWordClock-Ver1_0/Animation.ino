void Random(int Repeat)
{
 for (int i=0; i<=Repeat ; i++) {
                                  Timer=millis();
                                  Hour=random(12);
                                  Minute=random(59);
                                  TimeToWord();  
                                  while((unsigned long)(millis() - Timer) < 50);
                                }



ReadRTC();
TimeToWord();  
}

void Blink(int Repeat)
{
 int DisplayOnOff=0;
 for (int i=0; i<=Repeat ; i++) {
                                  Timer=millis();
                                  digitalWrite(OE,DisplayOnOff); DisplayOnOff=!DisplayOnOff;
                                  while((unsigned long)(millis() - Timer) < 100);
                                }
 digitalWrite(OE,0);
}
