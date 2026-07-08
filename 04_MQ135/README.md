# Step 4 – MQ135 Air Quality Sensor

## Objective

The objective of this step was to extend the weather station by adding an MQ135 gas sensor for basic air quality monitoring. The sensor was used to classify the surrounding air quality as **Good**, **Moderate**, or **Bad**, while keeping all the previous weather measurements and the four-page LCD menu.

## Analog Reference

The Arduino analog reference was changed from INTERNAL (1.1 V) to DEFAULT (5 V).

This change was required because all analog inputs share the same ADC reference voltage, allowing the LM35, LDR and MQ135 sensors to operate correctly together.

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
- 20 Male-to-Male Jumper Wires
- 4 Male-to-Female Jumper Wires


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
<img width="1920" height="1280" alt="Circuit" src="https://github.com/user-attachments/assets/ba8727c3-601f-441d-ae2f-65bd329b2e52" />

### LCD Output
# Page 1
<img width="1920" height="1280" alt="Page 1" src="https://github.com/user-attachments/assets/40c746f9-cbcb-47c2-8d13-f7fd2068b6d3" />

# Page 2
<img width="1920" height="1280" alt="Page 2" src="https://github.com/user-attachments/assets/ed0e3bf9-b93d-40e8-be9d-c25f09c88533" />

# Page 3
<img width="1920" height="1280" alt="Page 3" src="https://github.com/user-attachments/assets/abbc308a-7be4-49d1-bc5e-38407cd4b562" />

# Page 4
<img width="1920" height="1280" alt="Page 4" src="https://github.com/user-attachments/assets/ce7f2f7e-6824-417e-b5b2-0a543bfbad6c" />



## Arduino Code

The Arduino sketch is available in the file **MQ135.ino**.

## MQ135 Calibration

The MQ135 sensor was stabilized by averaging multiple analog readings before classifying the air quality.

This approach reduced measurement noise and provided more consistent results.

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
- Uses the Arduino DEFAULT analog reference.
- Reduces MQ135 measurement noise using averaged analog readings.


## Improvements from Step 3

- Added MQ135 air quality sensor.
- Added air quality monitoring.
- Added air quality classification (Good, Moderate, Bad).
- Reduced sensor noise by averaging multiple analog readings.
- Expanded the weather station with environmental monitoring.

