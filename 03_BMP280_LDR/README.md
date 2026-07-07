# Step 3 – BMP280 Pressure Sensor and LDR Light Detection

## Objective

The objective of this step was to expand the weather station by adding atmospheric pressure, altitude estimation and ambient light detection. The BMP280 sensor was integrated to measure atmospheric pressure and estimate altitude, while an LDR sensor was added to determine the ambient lighting conditions (Day, Cloudy or Night). The push button menu was extended from two to four information pages.

## Components

- Arduino Uno
- 20×4 LCD Display (I2C Interface)
- LM35 Temperature Sensor
- DHT11 Temperature & Humidity Sensor
- BMP280 Pressure Sensor
- LDR (Light Dependent Resistor)
- 10 kΩ Resistor
- Push Button
- Breadboard
- 19 Male-to-Male Jumper Wires

---

## Pin Connections

| Arduino Pin | Component |
|-------------|-----------|
| A0 | LM35 Output |
| A1 | LDR Voltage Divider |
| D2 | DHT11 Data |
| D3 | Push Button |
| SDA | LCD I2C, BMP280 |
| SCL | LCD I2C, BMP280 |
| 5V | LCD, LM35, DHT11, LDR |
| 3.3V | BMP280 *(or 5V if using a module with voltage regulator)* |
| GND | LCD, LM35, DHT11, BMP280, LDR |


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

The Arduino sketch is available in the file **BMP280_LDR.ino**.


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
- Classifies atmospheric pressure as **Low**, **Normal**, or **High**.
- Four-page LCD menu.
- Push button navigation.
- I2C communication for the LCD and BMP280.


## Improvements from Step 2

- Added BMP280 pressure sensor.
- Added atmospheric pressure measurement.
- Added altitude estimation.
- Added LDR light sensor.
- Added ambient light detection.
- Added pressure classification (Low, Normal, High).
- Added light classification (Day, Cloudy, Night).
- Expanded the LCD menu from two to four pages.

