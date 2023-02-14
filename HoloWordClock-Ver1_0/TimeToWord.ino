void TimeToWord()
{
byte TextDots=0;
byte TextMinutes=0;
byte TextHours=0;
int HourCheck=0;

ClearDisplay(); // First call the cleardisplay variable

//24 Hour to 12
if (Hour > 12) Hour=Hour-12;
if (Hour == 0) Hour=12;


// Get the Minute 1 to 4
int minuteten = (Minute/10); // get the power of ten
int minuteonefour = (Minute-(minuteten * 10)); // get the minutes 0-9

if (minuteonefour > 4) minuteonefour=minuteonefour-5;

//Dot Value
for (int i = 0; i <= 3; i++) {
  //Dot Value
  
  if (minuteonefour==1) TextDots = DotOne[i];
  if (minuteonefour==2) TextDots =(DotOne[i]+DotTwo[i]);
  if (minuteonefour==3) TextDots=(DotOne[i]+DotTwo[i]+DotThree[i]);
  if (minuteonefour==4) TextDots=(DotOne[i]+DotTwo[i]+DotThree[i]+DotFour[i]);
  
  //Minute Value
  
  if (Minute < 5) TextMinutes=(Oclock[i]);
  if (Minute > 4 && Minute < 10) TextMinutes=(five[i]+minutes[i]+past[i]);
  if (Minute > 9 && Minute < 15) TextMinutes=(ten[i]+minutes[i]+past[i]);
  if (Minute > 14 && Minute < 20) TextMinutes=(quarter[i]+past[i]);
  if (Minute > 19 && Minute < 25) TextMinutes=(twenty[i]+minutes[i]+past[i]);
  if (Minute > 24 && Minute < 30) TextMinutes=(twenty[i]+five[i]+minutes[i]+past[i]);
  if (Minute > 29 && Minute < 35) TextMinutes=(half[i]+past[i]);
  if (Minute > 34 && Minute < 40) TextMinutes=(twenty[i]+five[i]+minutes[i]+to[i]);
  if (Minute > 39 && Minute < 45) TextMinutes=(twenty[i]+minutes[i]+to[i]);
  if (Minute > 44 && Minute < 50) TextMinutes=(quarter[i]+to[i]);
  if (Minute > 49 && Minute < 55) TextMinutes=(ten[i]+minutes[i]+to[i]);
  if (Minute > 54) TextMinutes=(five[i]+minutes[i]+to[i]);

  // check if past or to
  HourCheck=0;
  HourCheck=Hour;
  if (Minute > 34) HourCheck=HourCheck+1; 
  if (HourCheck > 12) HourCheck=1;

  //Hours Value
  
  if (HourCheck == 1) TextHours=One[i];
  if (HourCheck == 2) TextHours=Two[i];
  if (HourCheck == 3) TextHours=Three[i];
  if (HourCheck == 4) TextHours=Four[i];
  if (HourCheck == 5) TextHours=Five[i];
  if (HourCheck == 6) TextHours=Six[i];
  if (HourCheck == 7) TextHours=Seven[i];
  if (HourCheck == 8) TextHours=Eight[i];
  if (HourCheck == 9) TextHours=Nine[i];
  if (HourCheck == 10) TextHours=Ten[i];
  if (HourCheck == 11) TextHours=Eleven[i];
  if (HourCheck == 12) TextHours=Twelwe[i];
  
  if (SetMode==1){TextHours=0;} // If Mode 1 display just Minutes
  if (SetMode==2){TextDots=0;TextMinutes=0;} /// If Mode 2 display just Hours
  
  
  DisplayData[i] = DisplayData[i] + it[i] + is[i] + TextDots + TextMinutes + TextHours; // Creates the Variable with all the 4 Clock Bytes
  
}
DispOUT();
  if (Minute==0 && SetMode==0) {Blink(10);} // Blink 10 Times every full hour
  if (Minute==15 && SetMode==0 || Minute==30 && SetMode==0 || Minute==45 && SetMode==0) {Blink(5);} // Blink 5 Times every 15 minutes



}



  
