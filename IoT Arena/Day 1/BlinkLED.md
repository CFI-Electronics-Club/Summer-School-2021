## Problem Statement

Blinking an external LED using Arduino.

## Schematics

![image](https://user-images.githubusercontent.com/85028192/124805786-96dc7800-df79-11eb-86a4-c55f351caa7e.png)

## Code

![image](https://user-images.githubusercontent.com/85028192/124804514-0487a480-df78-11eb-9076-7723c8c8d46c.png)

1. Using pinMode function to configure pin number 9 as OUTPUT in the void setup() function.
```
void setup()
{
  pinMode(9, OUTPUT)
}
```

2. Using digitalWrite() function we set pin number 9 to HIGH or logic 1. Then using the delay() function, we wait for 5 seconds. After the delay, we set the pin to LOW and again wait for 5 seconds. This will be a part of the void loop() functions so it runs in an endless loop till we switch the power OFF.
```
void loop()
{
  digitalWrite(9, HIGH);
  delay(5000); // Wait for 5 seconds
  digitalWrite(9, LOW);
  delay(5000); // Wait for 5 seconds
}
```

## Tinkercad simulation

 https://www.tinkercad.com/things/3mr0w1MXYY7 
