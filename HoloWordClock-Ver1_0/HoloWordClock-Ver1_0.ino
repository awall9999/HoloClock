#include <Wire.h>
#define RTC_ADDRESS 0x68

byte decToBcd(byte val)
{
  return ( (val / 10 * 16) + (val % 10) );
}
// Convert binary coded decimal to normal decimal numbers
byte bcdToDec(byte val)
{
  return ( (val / 16 * 10) + (val % 16) );
}

byte Second, Minute, Hour;
byte OldMinute = 60;
// Shiftregister Setup
int DataShift = 4;
int OE = 7;
int Latch = 6;
int ClockShift = 5;

// Define the Words-Position
const byte it[]= {0,0,0,1};
const byte is[]= {0,0,0,2};
const byte half[]= {0,0,0,4};
const byte ten[]= {0,0,0,8};
const byte quarter[]= {0,0,0,16};
const byte twenty[]= {0,0,0,32};
const byte five[]= {0,0,0,64};
const byte minutes[]= {0,0,0,128};

const byte to[]= {0,0,1,0};
const byte past[]= {0,0,2,0};
const byte One[]= {0,0,4,0};
const byte Three[]= {0,0,8,0};
const byte Two[]= {0,0,16,0};
const byte Four[]= {0,0,32,0};
const byte Five[]= {0,0,64,0};
const byte Six[]= {0,0,128,0};

const byte Seven[]= {0,1,0,0};
const byte Eight[]= {0,2,0,0};
const byte Nine[]= {0,4,0,0};
const byte Ten[]= {0,8,0,0};
const byte Eleven[]= {0,16,0,0};
const byte Twelwe[]= {0,32,0,0};
const byte Oclock[]= {0,64,0,0};
const byte DotOne[]= {0,128,0,0};

const byte DotTwo[]= {1,0,0,0};
const byte DotThree[]= {2,0,0,0};
const byte DotFour[]= {4,0,0,0};

byte DisplayData[] = {0,0,0,0};

// The Inputs
const int Set = A0;
const int Select = A1;
/*
 * It Is One O'clock
 * It Is five minutes past One 
 * It Is ten minutes past One 
 * It Is quarter past One 
 * It Is twenty miniutes past One 
 * It Is twenty five miniutes past One 
 * It Is half past One 
 * It Is twenty five miniutes to Two
 * It Is twenty minutes to Two
 * It Is quarter to Two
 * It Is ten minutes to Two 
 * It Is five minutes to Two 
 */

long int Timer = 0;
int PushButtonTime = 0;
int BlockButtonSet = 0;
int SetMode = 0;
int DotMinute;
void setup() {
  Serial.begin(9600);
  pinMode (DataShift,OUTPUT);  pinMode (OE,OUTPUT);  pinMode (Latch,OUTPUT);  pinMode (ClockShift,OUTPUT);
  pinMode (Set,INPUT);  pinMode (Select,INPUT); 
  digitalWrite(OE,LOW);
  
  Serial.println("Test V1.0");
  Random(30);
  
  
}

void loop() {
  Timer=millis();
  do{
  
  ReadRTC();
  
  if (Minute != OldMinute) {OldMinute=Minute;TimeToWord();} // Check of Minute different from OldMinute. If yes update Clock Display
  
  if (digitalRead(Set) == 1 && BlockButtonSet == 0){BlockButtonSet = 1;PushButtonTime++;} // let pass one impulse of the Set button, then block Set button and count the pushcounter up
  if (digitalRead(Set) == 0){BlockButtonSet = 0;PushButtonTime=0;} // when Set Button released, reset all
  
  }while((unsigned long)(millis() - Timer) < 1000); // check time and button every second
BlockButtonSet = 0;  // Unblock Set Button
  if (PushButtonTime >= 3){SetTime();} // when Set button pushed for x sec, enter Set mode
}
