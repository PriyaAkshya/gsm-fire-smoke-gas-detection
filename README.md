# GSM-Based Fire, Smoke and Gas Leakage Detection System

## Overview

This project is a real-time safety monitoring system developed to detect gas leakage, smoke, and fire. The system continuously monitors environmental conditions using multiple sensors and provides immediate alerts when a hazardous condition is detected.

An Arduino Uno is used as the main controller to process sensor data. The SIM800L GSM module sends SMS alert notifications to a registered mobile number during emergency conditions.

This project was developed as part of my Diploma in Electronics and Communication Engineering.

## Features

- Real-time gas leakage detection
- Smoke and air quality monitoring
- Flame detection
- SMS alert notifications using GSM
- Audible warning using a buzzer
- Real-time system status display
- Continuous environmental monitoring
- Sensor calibration for reliable detection

## Hardware Components

| Component | Model / Specification | Purpose |
|---|---|---|
| Microcontroller | Arduino Uno (ATmega328P) | Main system controller |
| GSM Module | SIM800L | Sends SMS alert notifications |
| Gas Sensor | MQ-2 | Detects combustible gases and gas leakage |
| Smoke Sensor | MQ-135 | Detects smoke and air contaminants |
| Flame Sensor | IR Flame Sensor | Detects the presence of flame |
| Display | 16x2 LCD | Displays system and alert status |
| Alert | Buzzer | Provides an audible warning |
| Power Supply | DC Power Supply | Powers the system |

## System Working

1. The Arduino Uno continuously reads data from the MQ-2 gas sensor, MQ-135 smoke sensor, and IR flame sensor.

2. The sensor readings are monitored and compared with predefined threshold levels.

3. When gas leakage, smoke, or flame is detected, the Arduino identifies the hazardous condition.

4. The buzzer is activated to provide an immediate audible warning.

5. The alert condition is displayed on the 16x2 LCD.

6. The SIM800L GSM module sends an SMS alert to the registered mobile number.

7. The system continues monitoring the surrounding environment for hazardous conditions.

## Technologies Used

- Embedded C / Arduino Programming
- Arduino Uno
- Sensor Interfacing
- GSM Communication
- Embedded Systems
- Hardware Integration

## Applications

- Home safety monitoring
- Industrial safety systems
- Gas leakage detection
- Fire detection systems
- Laboratories
- Storage facilities

  ## Source Code Note

The original source code developed during the diploma project was unavailable. The current implementation has been reconstructed based on the original system architecture, hardware components, and intended functionality.

The reconstructed code follows the same core functionality of gas, smoke, and flame detection with GSM-based SMS alerts.

## My Contribution

- Interfaced MQ-2, MQ-135, and IR flame sensors with Arduino Uno
- Integrated the SIM800L GSM module for SMS alert notifications
- Implemented sensor monitoring and alert control logic
- Integrated the 16x2 LCD for system status display
- Implemented buzzer-based emergency alerts
- Performed sensor calibration and system testing
- Debugged hardware and communication issues

## Project Status

Completed as a Diploma Final-Year Project.

## Author

**B. Akshya Priya**

Electronics and Communication Engineering
