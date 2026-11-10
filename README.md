# Intelligent Four-Wheel Mobile Robot

**Design and Development of an Intelligent Four-Wheel Mobile Robotic Platform**

## 1. Project Overview

This project focuses on the design and development of a modular four-wheel mobile robotic platform, combining mechanical systems, embedded electronics, control engineering and robotics software.

The platform is being developed progressively, beginning with individual motor characterisation and closed-loop wheel-speed regulation, with plans to integrate ROS 2, LiDAR-based perception, SLAM, mapping and autonomous navigation.

The long-term objective is to develop a flexible robotic platform capable of interacting with its environment and supporting autonomous mobile robot applications.

## 2. Project Objectives

- Design and develop a four-wheel mobile robotic platform.
- Implement independent motor control and wheel-speed regulation.
- Integrate quadrature encoders for real-time speed feedback.
- Develop and evaluate individual PI controllers.
- Establish communication between embedded hardware and robotics software.
- Integrate LiDAR sensors for environmental perception.
- Implement SLAM and mapping.
- Explore autonomous navigation using ROS 2.

## 3. Current Hardware

| Component | Description |
|---|---|
| Microcontroller | ESP32 NodeMCU-32S |
| Motor drivers | 2 × L298N |
| Motors | 4 × DC geared motors |
| Feedback sensors | 4 × Quadrature encoders |
| Motor control | PWM |
| Control algorithm | Independent PI controllers |

## 4. Development Progress

### Phase 1: Embedded Motor Control

- Motor direction testing.
- Encoder integration and CPR measurement.
- Individual motor speed characterisation.
- PWM-to-RPM calibration.
- Independent PI controller implementation.
- Four-wheel speed-control integration.

### Future Development

- ROS 2 integration.
- Robot description and software-hardware communication.
- LiDAR sensor integration.
- SLAM and environment mapping.
- Autonomous navigation.
- System-level testing and performance evaluation.

## 5. Technologies

- C++
- Arduino IDE
- ESP32
- PWM motor control
- Quadrature encoder feedback
- Proportional-Integral (PI) control
- ROS 2 (planned)
- LiDAR (planned)

## 6. Repository Structure

The repository will be organised into hardware design, embedded firmware, calibration, documentation, robotics software and experimental results.

## 7. Project Status

**Current focus:** Embedded motor control and four-wheel speed regulation.

This repository will be updated as the robot progresses through its development stages.

## 8. Author

Developed as a Mechatronics Engineering project.

---

*This is an evolving engineering project. Hardware, firmware, control algorithms and software capabilities will be documented as development progresses.*
