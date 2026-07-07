# Step 4 – MQ135 Air Quality Sensor

## Objective

The objective of this step was to extend the weather station by adding an MQ135 gas sensor for basic air quality monitoring. The sensor was used to classify the surrounding air quality as **Good**, **Moderate**, or **Bad**, while keeping all the previous weather measurements and the four-page LCD menu.

## Components

- Arduino Uno
- 20×4 LCD Display (I2C Interface)
- LM35 Temperature Sensor
- 100nF ceramic capasitor (for LM35)
- DHT11 Temperature & Humidity Sensor
- BMP280 Pressure Sensor
- LDR (Light Dependent Resistor)
- 10 kΩ (for LDR)
- MQ135 Air Quality Sensor
- Push Button
- Breadboard
- Mini breadboard
- 23 Male-to-Male Jumper Wires


## Pin Connections

| Arduino Pin | Component |
|-------------|-----------|
| A0 | LM35 Output |
| A1 | LDR Voltage Divider |
| A3 | MQ135 Analog Output |
| D2 | DHT11 Data |
| D3 | Push Button |
| SDA | LCD I2C, BMP280 |
| SCL | LCD I2C, BMP280 |
| 5V | LCD, LM35, DHT11, MQ135 |
| 3.3V | BMP280 |
| GND | LCD, LM35, DHT11, BMP280, LDR, MQ135 |


## Required Libraries

```cpp
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_BMP280.h>
```


## Images

### Circuit


### LCD Output



## Arduino Code

The Arduino sketch is available in the file **MQ135.ino**.


## Schematic


## Features

- Displays LM35 temperature.
- Displays DHT11 temperature.
- Compares analog (LM35) and digital (DHT11) temperature sensors.
- Displays DHT11 humidity.
- Measures atmospheric pressure using the BMP280.
- Estimates altitude using the BMP280.
- Detects ambient light using an LDR.
- Classifies ambient light as **Day**, **Cloudy**, or **Night**.
- Measures air quality using the MQ135 sensor.
- Classifies air quality as **Good**, **Moderate**, or **Bad**.
- Four-page LCD menu.
- Push button navigation.
- I2C communication for the LCD and BMP280.


## Improvements from Step 3

- Added MQ135 air quality sensor.
- Added air quality monitoring.
- Added air quality classification (Good, Moderate, Bad).
- Reduced sensor noise by averaging multiple analog readings.
- Expanded the weather station with environmental monitoring.

