#include <tinysnore.h>
#include <EEPROM.h>

//Variables
long TimeOnMs;
long TimeOffMs;
int led = 2; 
int button = 1;
int fan = 0;

void setup() {
  //Set pin states
  pinMode(led, OUTPUT);
  pinMode(fan, OUTPUT);
  
  digitalWrite(led,HIGH);
  delay(1000);
  digitalWrite(led,LOW);
  delay(1000);
  digitalWrite(led,HIGH);
  delay(1000);
  digitalWrite(led,LOW);
  delay(1000);
  digitalWrite(led,HIGH);
  delay(1000);
  digitalWrite(led,LOW);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led,HIGH);
  digitalWrite(fan,HIGH);
  delay(10000);
  digitalWrite(fan,LOW);
  digitalWrite(led,LOW);
  delay(1000);
}
