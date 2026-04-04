#Traffic light

## Description
Introductory Arduino project demostrating a traffic light for cars using basic digital output control. 

## Components
- Arduino UNO
- 3 x LEDs (Red , Blue , Green) <! -- Blue used instead of Yellow (lack of material)-->
- 3 x 220Ω Resistors
- Breadboard & Jumper wires

## Concepts
-Digital output
-delay() function for timing
-pinMode() for configuring pins
-Conditional statements (if)
-digitalRead() for reading pins

## Circuit Schematic View
[Traffic_Light_For_Cars_Schematics.pdf](https://github.com/user-attachments/files/26480821/Traffic_Light_For_Cars_Schematics.pdf)

## Real Setup

## Code
```cpp
const int Red_Led_Pin = 7;
const int Blue_Led_Pin = 10;
const int Green_Led_Pin = 12;

void setup()
{
pinMode(Red_Led_Pin,OUTPUT);
pinMode(Blue_Led_Pin,OUTPUT);
pinMode(Green_Led_Pin,OUTPUT);
}

void loop()
{
  if(digitalRead(Green_Led_Pin)==LOW)
  {
digitalWrite(Green_Led_Pin,HIGH);
delay(8000);
digitalWrite(Green_Led_Pin,LOW);
digitalWrite(Blue_Led_Pin,HIGH);
delay(2000);
digitalWrite(Blue_Led_Pin,LOW);
digitalWrite(Red_Led_Pin,HIGH);
delay(4000);
digitalWrite(Red_Led_Pin,LOW);
}
}
```
## Demo
