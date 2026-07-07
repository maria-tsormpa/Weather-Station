# Step 1 – Temperature Measurement using LM35 and LCD

## Objective

The objective of this step was to display the ambient temperature measured by an LM35 temperature sensor on a 16×2 LCD display using an Arduino Uno.

## Components

- Arduino Uno
- 16×2 LCD Display (Parallel Interface)
- LM35 Temperature Sensor
- 10 kΩ Potentiometer
- 100 nF Ceramic Capacitor
- Breadboard
- 18 Male-to-Male Jumper Wires

## Pin Connections

| Arduino Uno | Component |
|--------------|-----------|
| 5V | LCD VCC, LM35 VCC|
| GND | LCD GND, LM35 GND |
| D2 | LCD RS |
| D3 | LCD EN |
| D4 | LCD D4 |
| D5 | LCD D5 |
| D6 | LCD D6 |
| D7 | LCD D7 |
| A0 | LM35 OUT |
| 1.1V Internal Reference | Used for improved LM35 measurement accuracy |


## Required Library

```cpp
#include <LiquidCrystal.h>
```

## Images

### Circuit
<img width="1920" height="1280" alt="Circuit" src="https://github.com/user-attachments/assets/6e29d338-780c-43bf-9eb2-5602327effcc" />

### LCD Output
<img width="1920" height="1280" alt="Display" src="https://github.com/user-attachments/assets/5b20c6af-b47e-4e6a-b0a9-68f3c9527c56" />

## Arduino Code

The Arduino sketch is available in the file `LM35_LCD.ino`.


## Schematic

## Features

- Reads ambient temperature using the LM35 analog temperature sensor.
- Displays temperature on a 16×2 parallel LCD.
- Uses the Arduino internal 1.1 V reference for improved measurement accuracy.
- Updates the temperature reading every second.
