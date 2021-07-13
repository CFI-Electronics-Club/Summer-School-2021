## Problem Statement

Playing a buzzer using Arduino

## Schematics

## Code

```
void setup()
{
  pinMode(12, OUTPUT);
}
void loop()
{
  tone(12, 440, 300);
  delay(500);
  tone(12, 400, 300);
  delay(500);
}
```

## Tinkercad link
