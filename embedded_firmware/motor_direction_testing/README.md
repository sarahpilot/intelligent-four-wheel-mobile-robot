# Motor Direction Testing

This directory contains the initial firmware developed to test the operation and direction of the four DC geared motors.

## Objectives

- Verify motor driver connections.
- Test forward and reverse motor rotation.
- Confirm correct motor-to-driver channel assignments.
- Verify PWM enable functionality.
- Identify any motor direction inconsistencies before implementing closed-loop control.

## Hardware

- ESP32 NodeMCU-32S
- Two L298N motor drivers
- Four DC geared motors

## Testing Procedure

Each motor is tested individually by applying appropriate logic signals to the motor driver's direction inputs and enabling the motor through its PWM input.

## Development Status

Initial motor direction and driver functionality testing completed.
