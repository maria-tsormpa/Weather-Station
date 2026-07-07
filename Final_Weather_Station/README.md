# Final Weather Station

## Overview

This project is a complete Arduino-based weather station developed step by step as a learning project. It combines multiple environmental sensors with a 20×4 I2C LCD display to provide real-time weather and air quality information through a simple multi-page interface.

The project integrates analog and digital sensors, I2C communication, sensor calibration techniques and menu navigation using a push button.


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

### LM35

A linear correction was applied after comparing the analog sensor with the DHT11.

### DHT11

A correction equation was applied to reduce measurement error.

### BMP280

The sea-level pressure was automatically calibrated using the local altitude.

### MQ135

The sensor is automatically calibrated during startup by averaging 100 readings to establish a clean-air baseline.


## Images

### Circuit


### LCD Output



## Arduino Code

The Arduino sketch is available in the file **Final_Weather_Station.ino**.



## Schematic

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
