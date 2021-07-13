# Colour Colour Which Colour!

## Problem Statement

Demonstrating I2C communication using 1 master and 1 slave device. In this project the user gives input to the Master Arduino which is communicated to Slave Arduino. The slave inturn switches on the LED depending upon the Master's command.

## Schematics

![image](https://user-images.githubusercontent.com/85028192/124589345-85ab4280-de77-11eb-996b-8c0c1d37783f.png)

## Code
Master Code:

```
#include <Wire.h>

String x;
char y;

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  Serial.println("COLOUR COLOUR WHICH COLOUR! xD");
  Serial.println("Options - \nRed\nGreen\nBlue\nPurple\nCyan\nYellow\nWhite");
  Serial.println("Type 'colour' to switch on that LED");
}

void loop()
{
  while (Serial.available())
  {
    delay(2);                                                               
    char c = Serial.read();                                                 
    x += c;                                                        
  }
  if (x == "Red" or x == "RED" or x == "red" or x == "R")
    y = 'R';
  else if (x == "Blue" or x == "BLUE" or x == "blue" or x == "B")
    y = 'B';
  else if (x == "Green" or x == "GREEN" or x == "green" or x == "G")
    y = 'G';
  else if(x == "Purple" or x == "PURPLE" or x == "purple" or x == "P")
    y = 'P';
  else if(x == "Yellow" or x == "YELLOW" or x == "yellow" or x == "Y")
    y = 'Y';
  else if(x == "Cyan" or x == "CYAN" or x == "cyan" or x == "C")
    y = 'C';
  else if(x == "White" or x == "WHITE" or x == "white" or x == "W")
    y = 'W';
  if (x.length() > 0)                                            
  {
    Serial.println(x);                                            
    x = "";                                                        
  }
  Wire.beginTransmission(1);                                                
  Wire.write(y);                                                    
  Wire.endTransmission();
}
```

Slave code:

```
#include <Wire.h>
char x;

int red = 9;
int blue = 8;
int green = 6;

void setup()
{
  pinMode(red , OUTPUT);
  pinMode(green , OUTPUT);
  pinMode(blue , OUTPUT);
  Wire.begin(1);
  Wire.onReceive(receiveEvent);
}
void receiveEvent(int bytes)
{
  x = Wire.read();
  if(x == 'R')
  {
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
  }
  if(x == 'G')
  {
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(blue, LOW);
  }
  if(x == 'B')
  {
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);
  }
  if(x == 'P')
  {
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);
  }
  if(x == 'Y')
  {
    digitalWrite(red, HIGH);
    digitalWrite(green, HIGH);
    digitalWrite(blue, LOW);
  }
  if(x == 'C')
  {
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(blue, HIGH);
  }
  if(x == 'W')
  {
    digitalWrite(red, HIGH);
    digitalWrite(green, HIGH);
    digitalWrite(blue, HIGH);
  }
}

void loop()
{
  delay(100);
}
```

## Code Explained!
Let's start with Master:
1. Including Wire library for I2C communication and defining a String to store user's input and a character which will be transmitted to slave via I2C.
```
#include <Wire.h>
String x;
char y;
```
2. We know start I2C and Serial Communication in void setup().
```
void setup()
{
  Wire.begin();
  Serial.begin(9600);
```
3. Now we have to check if the user has inserted anything in the serial monitor and read it. We store this information through char c variable letter by letter and move these characters inside the string 'x' which was defined at the beginning.
```
while (Serial.available())
  {
    delay(2);                                                               
    char c = Serial.read();                                                 
    x += c;                                                        
  }
```
4. Now we use if statements to find out what the user has inputted and converting it into a character 'y' which will be transmitted to Slave via I2C.
```
if (x == "Red" or x == "RED" or x == "red" or x == "R")
    y = 'R';
```
5. Now we write a if statement for displaying the users input on the Serial Monitor of the Master. If the string 'x' has any value display this value and empty the string.
```
if (x.length() > 0)                                            
  {
    Serial.println(x);                                            
    x = "";                                                        
  }
```
6. The transmission now begins! The number indicated in the paranthesis is the address of the slave (here it is '1'). We use Wire.write to transmit 'y' and then end the transmission.
```
  Wire.beginTransmission(1);                                                
  Wire.write(y);                                                    
  Wire.endTransmission();
```

It's slave's turn now!
1. Including Wire library and defining a character to store the transmitted value.
```
#include <Wire.h>
char x;
```
2. Now let's assign variables for various LED digital pins. Then, start the I2C communication by stating that address is 1. Then we have to call register an event, here called receiveEvent.
```
int red = 9;
int blue = 8;
int green = 6;
void setup()
{
  pinMode(red , OUTPUT);
  pinMode(green , OUTPUT);
  pinMode(blue , OUTPUT);
  Wire.begin(1);
  Wire.onReceive(receiveEvent);
}
```
3. We have to create function for the event called receiveEvent which outputs an integer 'bytes'. In the function, we read the data master has transmitted by Wire.read() and store it in 'x'.
```
void receiveEvent(int bytes)
{
  x = Wire.read();
```
4. Now we write an if statement to check the received character from master and based on that the respective LED colours are switched ON or switched OFF.
```
  if(x == 'R')
  {
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
  }
```
5. Finally void loop() where we place a small delay so that we don't "overwhelm" the Arduino.
```
void loop()
{
  delay(100);
}
```

## Tinkercad Simulation

Here you go:  https://www.tinkercad.com/things/62xR1mmUKzl 
