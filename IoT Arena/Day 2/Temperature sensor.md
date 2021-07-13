## Problem Statement

Getting the values from the temperature sensor and printing it on the Serial monitor.

## Schematics

![image](https://user-images.githubusercontent.com/85028192/125415868-d6497754-3c55-4635-a45f-12defad92930.png)

## Code

```
int tempread = 0;

int temp = 0;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);

}

void loop()
{
  tempread = analogRead(A0);
  temp = (((tempread-20)*165/338) - 40);
  Serial.println(temp);

  
  delay(10); // Delay a little bit to improve simulation performance
}
```

## Tinkercad link

https://www.tinkercad.com/things/8unslJe31dU
