# Step 3 – BMP280 Pressure Sensor and LDR Light Detection

## Objective

The objective of this step was to expand the weather station by adding atmospheric pressure, altitude estimation and ambient light detection. The BMP280 sensor was integrated to measure atmospheric pressure and estimate altitude, while an LDR sensor was added to determine the ambient lighting conditions (Day, Cloudy or Night). The push button menu was extended from two to four information pages.

## Design Improvements

The LCD menu was expanded from two to four pages.

The BMP280 and LCD share the same I2C bus, allowing multiple devices to communicate over the SDA and SCL lines.

## Components

- Arduino Uno
- 20×4 LCD Display (I2C Interface)
- LM35 Temperature Sensor
- 100 nF Ceramic Capacitor (for LM35)
- DHT11 Temperature & Humidity Sensor
- BMP280 Pressure Sensor
- LDR (Light Dependent Resistor)
- 10 kΩ Resistor (for LDR)
- Push Button
- Breadboard
- 17 Male-to-Male Jumper Wires
- 4 Male-to-Female Jumper Wires


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
| 3.3V | BMP280 |
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
<img width="1920" height="1280" alt="Circuit" src="https://github.com/user-attachments/assets/5737fb90-b06f-433e-83a7-192d768cf6ce" />

### LCD Output
# Page 1
<img width="1920" height="1280" alt="Page 1" src="https://github.com/user-attachments/assets/722d6828-d69f-4a75-911f-b9979cfb95f5" />

# Page 2
<img width="1920" height="1280" alt="Page 2" src="https://github.com/user-attachments/assets/c2a52e87-678f-4a9a-8013-1b6de13f262c" />

# Page 3
<img width="1920" height="1280" alt="Page 3" src="https://github.com/user-attachments/assets/1d96b358-42d5-461b-bdbb-23f75bbf7ee4" />

# Page 4
<img width="1920" height="1280" alt="Page 4" src="https://github.com/user-attachments/assets/dec5b398-7fe6-48d6-a164-0ba0877f7ce5" />

## Arduino Code

The Arduino sketch is available in the file **BMP280_LDR.ino**.

## Push Button Improvement

The initial implementation used an external pull-down resistor.

For improved stability and simpler wiring, the push button was redesigned using the Arduino internal INPUT_PULLUP resistor.

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
- Uses the Arduino INPUT_PULLUP configuration for reliable button detection.
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
- Improved button stability and reduced false triggering.

