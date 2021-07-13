## Problem Statement

Controlling the LED using a push button

## Schematics

![image](https://user-images.githubusercontent.com/85028192/125415464-6e9ea525-c6b7-4f26-8835-3bb4760f6e55.png)

## Code

```
int buttonRead = 0;
void setup()
{
  pinMode(10, OUTPUT);
  pinMode(4, INPUT);
}

void loop()
{
  buttonRead = digitalRead(4);
  if (buttonRead == HIGH)
  {
  	digitalWrite(10, HIGH);
  	delay(500); // Wait for 500 millisecond(s)
  	digitalWrite(10, LOW);
  	delay(500); // Wait for 500 millisecond(s)
  }
}
```

## Tinkercad Link

https://www.tinkercad.com/things/dpIH6ylzDn7
