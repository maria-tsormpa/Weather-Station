# Step 2 – LCD I2C Display, DHT11 Sensor and Push Button Menu

## Objective

The objective of this step was to upgrade the weather station by replacing the parallel LCD with a 20×4 I2C LCD display, reducing the required wiring. A DHT11 sensor was added to measure temperature and humidity, while a push button was used to switch between different information pages displayed on the LCD.



## Components

- Arduino Uno
- 20×4 LCD Display (I2C Interface)
- DHT11 Temperature & Humidity Sensor
- LM35 Temperature Sensor
- 10 kΩ resistor
- Push Button
- Breadboard
- 14 Male-To-Male Jumper Wires 


## Pin Connections

| Arduino Uno | Component |
|--------------|-----------|
| A0 | LM35 OUT |
| D2 | DHT11 DATA |
| D3 | Push Button |
| A4 (SDA) | LCD I2C SDA |
| A5 (SCL) | LCD I2C SCL |
| 5V | LCD, DHT11, LM35 |
| GND | LCD, DHT11, LM35 |



## Required Libraries

```cpp
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
```


## Images

### Circuit


### LCD Output

## Arduino Code

The Arduino sketch is available in the file `LCD_I2C_DHT11_Button.ino`.


## Schematic

## Features

- Parallel LCD replaced with an I2C LCD.
- Displays LM35 temperature.
- Displays DHT11 temperature.
- Displays DHT11 humidity.
- Two-page LCD menu.
- Push button navigation.

