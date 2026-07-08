# Step 2 – LCD I2C Display, DHT11 Sensor and Push Button Menu

## Objective

The objective of this step was to upgrade the weather station by replacing the parallel LCD with a 20×4 I2C LCD display, reducing the required wiring. A DHT11 sensor was added to measure temperature and humidity, while the existing LM35 analog temperature sensor was retained in order to compare the readings of an analog and a digital temperature sensor. A push button was also implemented to switch between multiple information pages displayed on the LCD.

## Design Improvements

The parallel LCD was replaced by an I2C LCD, significantly reducing the required wiring.
The DHT11 sensor was introduced not only to measure humidity but also to compare its temperature readings with the analog LM35 sensor.

## Components

- Arduino Uno
- 20×4 LCD Display (I2C Interface)
- DHT11 Temperature & Humidity Sensor
- LM35 Temperature Sensor
- 100 nF Ceramic Capacitor (for LM35)
- 10 kΩ resistor (for Push Button)
- Push Button
- Breadboard
- 12 Male-To-Male Jumper Wires
- 4 Male-To-Female Jumper Wires


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
<img width="1920" height="1280" alt="Circuit" src="https://github.com/user-attachments/assets/4a1737af-671a-4d6a-873c-5e84b7b4fc4c" />

### LCD Output
Page 1
<img width="1920" height="1280" alt="Page 1" src="https://github.com/user-attachments/assets/60481045-e04b-4d56-9842-606de03d585e" />

# Page 2
<img width="1920" height="1280" alt="Page 2" src="https://github.com/user-attachments/assets/678d926c-be3c-4ad3-9e90-98ef0277cff1" />

## Arduino Code

The Arduino sketch is available in the file `LCD_I2C_DHT11_Button.ino`.


## Schematic

## Features

- Parallel LCD replaced with an I2C LCD.
- Displays LM35 temperature.
- Displays DHT11 temperature.
- Compares analog (LM35) and digital (DHT11) temperature sensors.
- Displays DHT11 humidity.
- Two-page LCD menu.
- Push button navigation.

## Improvments from Step 1

- Replaced the parallel LCD with an I2C LCD.
- Added a DHT11 sensor.
- Added push button navigation.
- Introduced multiple LCD pages.
