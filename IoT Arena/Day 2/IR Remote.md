## Problem Statement

Using an IR Remote and display the button 1 to 9 on the LCD screen.

## Schematics

![image](https://user-images.githubusercontent.com/85028192/125418366-747f0415-5ffe-4f11-8747-6bc4121d0afc.png)

## Code

```
#include<IRremote.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,5,4,3,2);
int IRpin=8;
IRrecv irev(IRpin);
decode_results res;
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(IRpin,INPUT);
  Serial.begin(9600);
  irev.enableIRIn();
  lcd.begin(16,2);
  
}

void loop(){
  if(irev.decode(&res)){
    Serial.println(res.value);
    delay(1000);
    irev.resume();
    
    lcd.setCursor(0,1);
  }
  switch (res.value){
    case 16593103:
      lcd.setCursor(0,0);
      lcd.print("Zero");
      delay(1000);
      lcd.clear();
      break;
    
    
    case 16582903:
      lcd.setCursor(0,0);
      lcd.print("One");
      delay(1000);
      lcd.clear();
      break;
    case 16615543:
      lcd.setCursor(0,0);
      lcd.print("Two");
      delay(1000);
      lcd.clear();
      break;
    case 16599223:
      lcd.setCursor(0,0);
      lcd.print("Three");
      delay(1000);
      lcd.clear();
      break;
    case 16591063:
      lcd.setCursor(0,0);
      lcd.print("Four");
      delay(1000);
      lcd.clear();
      break;
    case 16623703:
      lcd.setCursor(0,0);
      lcd.print("Five");
      delay(1000);
      lcd.clear();
      break;
    case 16607383:
      lcd.setCursor(0,0);
      lcd.print("Six");
      delay(1000);
      lcd.clear();
      break;
    case 16586983:
      lcd.setCursor(0,0);
      lcd.print("Seven");
      delay(1000);
      lcd.clear();
      break;
    case 16619623:
      lcd.setCursor(0,0);
      lcd.print("Eight");
      delay(1000);
      lcd.clear();
      break;
    case 16603303:
      lcd.setCursor(0,0);
      lcd.print("Nine");
      delay(1000);
      lcd.clear();
      break;
   
  }
}
```

## Tinkercad link
https://www.tinkercad.com/things/kgE6umcH1fc
