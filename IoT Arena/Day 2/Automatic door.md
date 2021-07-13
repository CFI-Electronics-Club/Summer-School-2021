## Problem Statement

Making an automatic door using a ultrasonic distance sensor and a servo motor. The ultrasonic sensor detects the distance at which the object is from the door and the servo motor opens the door automatically when the object comes close to the door.

## Schematics

![image](https://user-images.githubusercontent.com/85028192/125417986-1666ddfe-0f92-47bc-be65-4bbd269cb204.png)

## Code
```
#include <Servo.h>

int trgpin=7;
int ecopin=6;
double distance,duration;
Servo servo;
int input=0;


void setup() 
{
  Serial.begin(9600);
  pinMode(trgpin,OUTPUT);
  pinMode(ecopin,INPUT);
  servo.attach(9);
  servo.write(input);  

}

void loop()
{ 
  digitalWrite(trgpin,0);
  delay(2);
  digitalWrite(trgpin,1);
  delayMicroseconds(20);
  digitalWrite(trgpin,0);
  duration= pulseIn(ecopin,1);
  distance= (duration/2.0);
  distance=distance/29.1;
  Serial.println(distance);
    
  if(distance<75){
    servo.write(90);
  }
  else{
    servo.write(0);
  }
 }
 ```
 ## Tinkercad link
 
 https://www.tinkercad.com/things/kL9oiTuBtnA
 
