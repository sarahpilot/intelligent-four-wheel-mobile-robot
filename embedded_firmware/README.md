# Embedded Firmware

This directory contains the embedded software developed for the Intelligent Four-Wheel Mobile Robot.

The firmware is developed using C++ and the Arduino framework, with the ESP32 serving as the main embedded controller.

## Development Modules

### 1. Motor Testing
Programs for testing motor direction, forward and reverse operation, and motor driver functionality.

### 2. Encoder Testing
Programs for quadrature encoder integration, pulse counting and Counts Per Revolution (CPR) measurement.

### 3. Motor Characterisation
Programs for testing different PWM values and measuring the corresponding motor speeds in RPM.

### 4. Closed-Loop Speed Control
Implementation of four independent Proportional-Integral (PI) controllers for regulating the speed of individual wheels using encoder feedback.

## Hardware Platform

- ESP32 NodeMCU-32S
- Two L298N motor drivers
- Four DC geared motors
- Four quadrature encoders

## Development Status

The current focus is on individual motor characterisation, encoder feedback and four-wheel closed-loop speed regulation.

Future firmware modules will support communication with the ROS 2 robotics software framework.
