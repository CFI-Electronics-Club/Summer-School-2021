## Problem Statement

Playing the buzzer whenever the room goes dark using the LDR or photoresistor

## Schematics

![image](https://user-images.githubusercontent.com/85028192/125415157-7b274358-accd-4723-b867-548b57bb93ec.png)

## Code

```
int lightread = 0;
void setup()
{
  pinMode(12, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop()
{
  lightread = analogRead(A0);
  Serial.println(lightread);
  if (lightread<=6)
  {
  	tone(12,440,300);
  	delay(500);
  	tone(12,400,300);
  	delay(500);
  }
}
```

## Tinkercad link

https://www.tinkercad.com/things/dpIH6ylzDn7
