## Problem Statement

Demonstrating the use of multiple slaves with one master connected by I2C. Imagine you arrive at a dark place and you are not able to see anything. There's an LED bulb, but you can't find the switch. But what if the LED gets switched ON by itself! Sounds cool right. This project uses PIR and LDR sensors to switching a LED whenever someone arrives there. We'll be using I2C communication to connect all the devices.

## Schematics

![image](https://user-images.githubusercontent.com/85028192/125013520-96330700-e089-11eb-9af3-b42d3a4c7851.png)

## Master Code

```
#include <Wire.h>

int LED = 11;
bool presence;
int light;

void setup()
{
  pinMode(LED, OUTPUT);
  Wire.begin();
}

void loop()
{
  Wire.requestFrom(1, 1);

  if (Wire.available())
  {
    if(Wire.read() == 1)
      presence = true; 
    else
      presence = false;
  }
  
  Wire.requestFrom(2, 1);

  if (Wire.available())
  {
    light = Wire.read();
  }
  
  if ( presence && light < 60 ) 
  {
    digitalWrite(LED, HIGH);
    delay(5000);
  }
  
  digitalWrite(LED, LOW);
  
  delay(50);
}
```
## Slave 1 code

```
#include <Wire.h>

int pir;

void setup()
{
  Wire.begin(1);
  Wire.onRequest(reqEvt); 
}

void loop()
{
  if(digitalRead(10) == HIGH)
    pir = 1;
  else
    pir = 0;
  delay(1);
}
void reqEvt()
{
  Wire.write(pir); 
}
```
## Slave 2 Code

```
#include <Wire.h>

int ldr;

void setup()
{ 
  Serial.begin(9600);
  Wire.begin(2);
  Wire.onRequest(reqEvt); 
}

void loop()
{
  ldr = map(analogRead(A0), 0, 1023, 0, 255);
  Serial.println(ldr);
  delay(10);
}
void reqEvt()
{
  Wire.write(ldr); 
}
```
## Tinkercad Simulation

Here you go : https://www.tinkercad.com/things/6hgoay3AC3L 
