/*
   P10_00_00-Main
   Project: P10_00_00 NotMildewPls
   Schematic: P10_00_00-Main.fzz
   Description: Arduino sketch for P10_00_00 NotMildewPls
*/

//Includes
#include <tinysnore.h>
#include <EEPROM.h>

//Variables
long TimeStart;    //Timer variable
long TimeOnMs;     //Amount of time to stay on
long TimeOffMs;    //Amount of time to stay off
int address = 0;   //Address for where to store PercentOn settings
int led = 2;       //Pin connected to the led
int button = 1;    //Pin connected to the button
int fan = 0;       //Pin connected to TIP120 base pin

//Settings
int Debounce = 200;         //Delay time to ignore button bounce
byte HoldTime = 2000;       //How long to hold to be counted as a long press
byte PercentOn = 25;        //Initial time on 25%
long StartupDelay = 60000;  //Amount of time to wait for modification of settings at startup
int Period = 3600;          //One period is 1 hr 


//Code that gets run during boot up
void setup() {
  //Set pin states
  pinMode(led, OUTPUT);
  pinMode(fan, OUTPUT);
  pinMode(button, INPUT);

  //Flash to indicate that boot sequence
  BlinkFast(2);
  delay(1000);
  BlinkFast(2);

  //Check for stored Settings
  if (EEPROM.read(address) == 255) //No settings saved
  {
    EEPROM.write(address, PercentOn);
    Blink(7);
  }
  else //Load the settings
  {
    PercentOn = EEPROM.read(address);
    Blink(4);
  }

  //Wait to search for a menu request
  long Start = millis();
  while((millis()-Start) < StartupDelay)
  {
    //Led on to indicate that it is available for programming
    digitalWrite(led,HIGH);
  
    //Check for Menu request (long press)
    if(PressType() == 2)
    {
    //Display programming request made
      digitalWrite(led,LOW);
      delay(1000);
    
    //Get, save, and display the new settings
      PercentOn  = SetTimeOn();
      EEPROM.write(address, PercentOn);
      BinkPercent();
      delay(1000);
    }
  }
  
  //Turn off led to indicate that settings cannot be written
  digitalWrite(led,LOW);
  delay(1000);
  
  //Calculate time on in ms
  TimeOnMs = 10L * Period * PercentOn;
  TimeOffMs = 1000L * Period - TimeOnMs;
  
}

//Main program loop
void loop() {
  //Turn on the fan and led
  digitalWrite(led,HIGH);
  digitalWrite(fan,HIGH);
  delay(TimeOnMs);
  //Turn off the fan and led
  digitalWrite(fan,LOW);
  digitalWrite(led,LOW);
  
  //Go to sleep until next cycle
  snore(TimeOffMs);
}

//Program that determines the type of input received 0=none 1=short 2=long 
int PressType()
{
  //Default 0 is button not pressed
  int Result = 0;
  
  //Check for button press
  if(digitalRead(button) == LOW)
  {
    Result = 1;
    TimeStart = millis();
    delay(Debounce);
    
  //Check for press and hold
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

//Menu interface for setting the percent on value
/*
 * Flashes quickly 3 times to indicate that it's ready to accept values
 * Each short press is counted as +1 for the tens value 
 * (max value is 9)
 * (10 second time out if no input given)
 * Long press will set the tens value
 * Will blink quickly 2 times to indicate that the tens value has been set
 * Each short press is counted as +1 for the ones value
 * (max value is 9)
 * (10 second time out if no input given)
 * Long press will set the ones value
 * Will blink quickly 2 times to indicate that the ones value has been set
 */
byte SetTimeOn()
{
  //Display now in set settings mode
  BlinkFast(3);

  //Set variables
  byte Tens = 0;
  byte Ones = 0;
  bool Set = false;
  byte Result = 0;
  long LastInput = millis();

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
  
    //Max count is 9 or break at long press
    if((Press == 2) || (Tens == 9))
    {
      Set = true;
    }
  
    //Check for no input
    if((millis() - LastInput) > 10000)
    {
      return PercentOn;
    }
  }
  //Indicate that the value has been set
  BlinkFast(2);
  
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
  
    //Max count is 9 or break at long press
    if((Press == 2) || (Ones == 9))
    {
      Set = true;
    }
  
    //Check for no input
    if((millis() - LastInput) > 10000)
    {
      return PercentOn;
    }
  }
  
  //Indicate that the value has been set
  BlinkFast(2);
  
  //Calculate and return the result
  Result = Tens*10 + Ones;
  return Result; 
}


//Bink quickly given number of times
void BlinkFast(int Ct)
{
  for (int i = 0; i < Ct; i++) 
  {
    digitalWrite(led,HIGH);
    delay(100);
    digitalWrite(led,LOW);
    delay(100);
  }
  delay(1000);
}


//Blink slowly a given number of times
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

//Blink out the PercentOn value (tens)(3x fast blink)(ones) 
void BinkPercent()
{
  byte Tens = PercentOn/10;
  byte Ones = PercentOn - Tens*10;
  Blink(Tens);
  BlinkFast(3);
  Blink(Ones);
}
