## Problem Statement

Playing a Buzzer using Arduino.

## Schematics

![image](https://user-images.githubusercontent.com/85028192/124811819-85e33500-df80-11eb-8083-90c30a452fff.png)

## Code

1. Using pinMode() configure pin number 12 to OUTPUT.
```
void setup()
{
  pinMode(12, OUTPUT);
}
```
2. tone() function : This is a special function used for buzzers. It generates a square wave of the specified frequency with 50% duty cycle on a pin.

Syntax : `tone(pin, frequency, duration)`

The pin is the pin number to which the buzzer is connected, frequency is the frequency of the noise generated and the duration can be specified for how long it has to keep playing.
```
void loop()
{
  tone(12, 440, 300);
  delay(500);
  tone(12, 400, 300);
  delay(500);
}
```
Using proper frequencies and delays we can create a music of our own :)

## Tinkercad Simulation

 https://www.tinkercad.com/things/klu2nwW2ECx 
 
## Bonus!

We made a sweet musical tone for you :)

https://www.tinkercad.com/things/aCdzaGuDBFn-surprising-wolt/editel?sharecode=3mvCt6RvR4lXgA7MfX3tNNN0kaaPEJFPlHW2NfrZ5ns Go to Tinkercad with this link, copy and paste the code in Arduino IDE and enjoy!
