# Encoder CPR Testing

This directory contains the firmware used to determine the Counts Per Revolution (CPR) of the quadrature encoders installed on the four DC geared motors.

## Objectives

- Implement quadrature encoder signal decoding.
- Measure encoder pulse counts during motor rotation.
- Determine the effective CPR of each motor.
- Verify encoder channel connections.
- Establish accurate encoder parameters for subsequent RPM measurement and closed-loop speed control.

## Encoder Configuration

| Motor | Encoder A | Encoder B | Measured CPR |
|---|---:|---:|---:|
| Front Right | GPIO 32 | GPIO 4 | 1440 |
| Front Left | GPIO 34 | GPIO 35 | 1440 |
| Rear Right | GPIO 5 | GPIO 15 | 2473 |
| Rear Left | GPIO 36 | GPIO 39 | 2476 |

## Measurement Method

The ESP32 reads the quadrature encoder signals using interrupt-based pulse counting.

The measured encoder counts are used to establish the effective counts per revolution for each motor.

## Development Status

CPR measurements have been obtained for all four motors. These values are used in the wheel-speed calculation within the motor control firmware.
