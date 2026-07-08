# Final Weather Station

## Overview

This project is a complete Arduino-based weather station developed step by step as a learning project. It combines multiple environmental sensors with a 20×4 I2C LCD display to provide real-time weather and air quality information through a simple multi-page interface.

The project integrates analog and digital sensors, I2C communication, sensor calibration techniques and menu navigation using a push button.

## Development Process

The weather station was developed incrementally through four major stages.

Each stage introduced new hardware while preserving the functionality of the previous version, resulting in a progressively more capable environmental monitoring system.


## Features

- Measures ambient temperature using an LM35 analog sensor.
- Measures ambient temperature using a DHT11 digital sensor.
- Compares analog and digital temperature measurements.
- Measures relative humidity.
- Measures atmospheric pressure.
- Estimates altitude using the BMP280.
- Detects ambient light conditions.
- Measures air quality using the MQ135 sensor.
- Four-page LCD menu.
- Push button navigation.
- Sensor calibration.
- I2C communication.
- Uses INPUT_PULLUP for reliable push button operation.
- Dedicated CheckButton() function for menu navigation.
- Automatic MQ135 startup calibration.
- Sea-level pressure calibration for the BMP280.
- Temperature sensor recalibration using linear regression.
- Optimized LCD refresh to avoid unnecessary screen clearing.


## Components

- Arduino Uno
- 20×4 LCD Display (I2C Interface)
- LM35 Temperature Sensor
- 100nF Ceramic Capasitor (for LM35)
- DHT11 Temperature & Humidity Sensor
- BMP280 Pressure Sensor
- LDR (Light Dependent Resistor)
- 10 kΩ (for LDR)
- MQ135 Air Quality Sensor
- Push Button
- Breadboard
- Mini breadboard
- 20 Male-To-Male Jumper Wires
- 4 Male-To-Female Jumper Wires


## Pin Connections

| Arduino Pin | Component |
|-------------|-----------|
| A0 | LM35 Output |
| A1 | LDR |
| A3 | MQ135 Analog Output |
| D2 | DHT11 Data |
| D3 | Push Button |
| SDA | LCD I2C, BMP280 |
| SCL | LCD I2C, BMP280 |
| 5V | LCD, LM35, DHT11, MQ135 |
| 3.3V | BMP280 |
| GND | All components |

## Required Libraries

```cpp
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <DHT.h>
#include <Adafruit_BMP280.h>
```

## LCD Pages

### Page 1

- LM35 Temperature
- DHT11 Temperature

### Page 2

- Humidity
- Ambient Light Status
  - Day
  - Cloudy
  - Night

### Page 3

- Atmospheric Pressure
- Pressure Classification
  - Low
  - Normal
  - High


### Page 4

- Altitude
- Air Quality
  - Good
  - Moderate
  - Poor

## Sensor Calibration

Several calibration techniques were implemented to improve measurement accuracy.
For LM35 and DHT11: Calibration data were collected experimentally and processed using Python. Linear regression was applied to obtain correction equations, which were then implemented directly in the Arduino firmware.

### LM35

A linear correction was applied after comparing the analog sensor with a trustworthy thermometre.

### DHT11

A correction equation was applied to reduce measurement error, using a trustworthy thermometre.

### BMP280

The sea-level reference pressure is automatically calculated using the local installation altitude to improve altitude estimation.

### MQ135

The sensor performs an automatic startup calibration by averaging 100 analog readings to establish a clean-air baseline before normal operation.

## Images

### Circuit


### LCD Output

# Page 1

# Page 2

# Page 3

# Page 4



## Arduino Code

The Arduino sketch is available in the file **Final_Weather_Station.ino**.



## Schematic
<img width="2931" height="2073" alt="Schematic_Final_Weather_Station" src="https://github.com/user-attachments/assets/d849edea-721f-4b38-8ae9-9383a2a906ee" />

## Future Improvements

- Replace the DHT11 with a BME280 or DHT22.
- Display weather trend icons.
- Store sensor data on an SD card.
- Add a Real-Time Clock (RTC).
- Add Wi-Fi connectivity using ESP32 or ESP8266.
- Upload data to an IoT platform.
- Create a web dashboard.
- Add battery power support.
- Design a 3D printed enclosure.
