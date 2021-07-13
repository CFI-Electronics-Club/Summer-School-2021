## Problem Statement

In this project we will make an external LED blink using an Arduino.

## Schematics

## Code

```
void setup()
{
  pinMode(10, OUTPUT);
}
void loop()
{
  digitalWrite(10, HIGH);
  delay(1000); // Wait for 1 second
  digitalWrite(10, LOW);
  delay(1000); // Wait for 1 second
}
```

## Tinkercad link

  
