#include <tinysnore.h>
#include <EEPROM.h>

//Variables
long TimeStart;
long TimeOnMs;
long TimeOffMs;
int address = 0; //Address for where to store PercentOn settings
int led = 2;
int button = 1;
int fan = 0;

//Settings
int Debounce = 200;
byte HoldTime = 2000;
byte PercentOn = 50;
long StartupDelay = 600000;
int Period = 3600; //In seconds


// the setup function runs once when you press reset or power the board
void setup() {
  //Serial.begin(9600);
  FlashSetShort();
  delay(1000);
  FlashSetShort();
  //Check for stored PercentOn
  if (EEPROM.read(address) == 255)
  {
    EEPROM.write(address, PercentOn);
    Blink(7);
  }
  //Set pin states
  pinMode(led, OUTPUT);
  pinMode(fan, OUTPUT);
  
  //Wait 10 min to search for a menu request
  long Start = millis();
  while((millis()-Start) < StartupDelay)
  {
  //Led on to indicate that it is availible for programming
  digitalWrite(led,HIGH);
  
    //Check for Menu request
    if(PressType() == 2)
    {
    digitalWrite(led,LOW);
    delay(1000);
      PercentOn  = SetTimeOn();
      //Serial.println("TimeSet");
      //Serial.print("PercentOn: ");
      //Serial.println(PercentOn);
      //Serial.print("TimeOnMs: ");
      //Serial.println(TimeOnMs);
    EEPROM.write(address, PercentOn);
    }
  }
  digitalWrite(led,LOW);
  
  //Calculate time on in ms
  TimeOnMs = Period * 10L * PercentOn;
  TimeOffMs = Period * 1000L - TimeOnMs;
  //Serial.print("Settings: ");
  //Serial.print(TimeOnMs);
  //Serial.print(",");
  //Serial.print(TimeOffMs);
  
}

// the loop function runs over and over again forever
void loop() {
  //Serial.println("On");
  digitalWrite(fan,HIGH);
  delay(TimeOnMs);
  //Serial.println("On");
  digitalWrite(fan,LOW);
  //delay(TimeOffMs);
  snore(TimeOffMs);
}
void FlashSet()
{
  for (int i = 0; i <= 3; i++) 
  {
    digitalWrite(led,HIGH);
    delay(100);
    digitalWrite(led,LOW);
    delay(100);
  }
  delay(1000);
}
void FlashSetShort()
{
  for (int i = 0; i <= 2; i++) 
  {
    digitalWrite(led,HIGH);
    delay(100);
    digitalWrite(led,LOW);
    delay(100);
  }
  delay(1000);
}
int PressType()
{
  int Result = 0;
  //Check for button press
  if(digitalRead(button) == LOW)
  {
    Result = 1;
    TimeStart = millis();
    delay(Debounce);
    while(digitalRead(button) == LOW)
    {
      long Delta = millis() - TimeStart;
      if (Delta > HoldTime)
      {
        Result = 2;
        break;
      }
    }
  }
  return Result;
}
void Blink(int Ct)
{
  for (int i = 0; i < Ct; i++) 
  {
    digitalWrite(led,HIGH);
    delay(500);
    digitalWrite(led,LOW);
    delay(500);
  }
}
byte SetTimeOn()
{
  byte Result = 0;
  long LastInput = millis();
 
  //Display now in set flash mode
  FlashSet();

  //Set variables
  byte Tens = 0;
  byte Ones = 0;
  bool Set = false;

  //Get the 10X factor
  while(!Set)
  {
    //Get button press
    int Press = PressType();
    //Short press increase the count
    if(Press == 1)
    {
      LastInput = millis();
      Tens += 1;
    }
    //Max count is 9 or brreak at long press
    if((Press == 2) || (Tens == 9))
    {
      Set = true;
    }
    //Check for no input
    if((millis() - LastInput) > 10000)
    {
      return PercentOn;
    }
  //Serial.print("Tens: ");
    //Serial.println(Tens);
  }
  //Indicate that the value has been set
  FlashSetShort();
  //Get the 1X factor
  Set = false;
  LastInput = millis();
  while(!Set)
  {
    //Get button press
    int Press = PressType();
    //Short press increase the count
    if(Press == 1)
    {
      LastInput = millis();
      Ones += 1;
    }
    //Max count is 9 or brreak at long press
    if((Press == 2) || (Ones == 9))
    {
      Set = true;
    }
    //Check for no input
    if((millis() - LastInput) > 10000)
    {
      return PercentOn;
    }
  //Serial.print("Ones: ");
    //Serial.println(Ones);
  }
  //Indicate that the value has been set
  FlashSetShort();
  //Display the 10X factor and the 1X factor
  Blink(Tens);
  FlashSetShort();
  Blink(Ones);
  Result = Tens*10 + Ones;
  //Serial.print("Result: ");
  //Serial.println(Result);
  return Result;
  
}
