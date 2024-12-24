# Romică
## Table of Contents
[1. Introduction](#introduction)\
[2. Overview](#overview)\
[3. Hardware Design](#hardware-design)\
[4. Software Design](#software-design)\
[5. Final Results](#final-results)\
[6. Conclusions](#conclusions)\
[7. Journal](#journal)\
[8. Source Code](#source-code)\
[9. Resources](#resources)

## Introduction
Parking can often be a challenging task, especially in tight or unfamiliar spaces. To address this, we aim to create Romică, a robot designed to assist users in parking vehicles safely and efficiently. Equipped with a distance sensor, Romică will help drivers determine their proximity to obstacles by providing real-time feedback. When a vehicle gets closer to an obstacle, Romică will signal the user to stop. Conversely, if the obstacle is far enough, it will indicate that the user can move forward.

This project combines hardware and software design to develop an accessible and user-friendly solution to enhance parking safety and convenience.

## Overview
Block Diagram

![Block Diagram](https://github.com/StefanAdrian2003/Proiect-Robotica/blob/main/Images/Block_Diagram.png)

### Detailed Description of Hardware Functionality

1. **Microcontroller - Arduino Uno**  
   The Arduino Uno is a microcontroller board based on the ATmega328P. It features 14 digital input/output pins, 6 analog inputs, a 16 MHz quartz crystal, and USB connectivity. It is the core of the project, coordinating all inputs and outputs.

2. **L293D Motor Driver Module**  
    The L293D motor driver module is an H-bridge-based driver that allows the control of DC motors in both forward and reverse directions. It enables the Arduino to manage the high current and voltage requirements of the motors safely. The module supports two DC motors or one stepper motor and includes built-in diodes for protection.

3. **DC Motors**  
   The DC motors are used to drive the robotic mechanism. They are controlled via the Arduino through an H-bridge motor driver, enabling forward and reverse motion.

4. **Joystick**  
   The joystick is used to provide directional input. It works by reading analog values from its X and Y axes, allowing the user to control movement or navigation.

5. **Ultrasonic Sensor**  
   The ultrasonic sensor measures distance by sending ultrasonic waves and detecting their reflection. It is used for obstacle detection and navigation.

6. **LCD Display**  
   The LCD display is used to provide visual feedback, such as sensor readings or status messages. It connects to the Arduino and communicates via I2C for simplified wiring.

7. **Speaker**  
   The Speaker is used to emit sound signals, acting as an alert mechanism or for providing audio feedback in the system.

8. **9V Batteries**  
   The 9V batteries supply power to the L293D motor driver module.

9. **1.5V Batteries**
   The 1.5V batteries supply power to the system, including the L293D motor driver module and microcontroller.

11. **Servo Motors**  
   The servo motors are used for precise movement, controlled via PWM signals from the Arduino. They are ideal for applications requiring fine control.

## Hardware Design
TBD - This section will contain data about the components used in creating the project.
  
## Software Design
The software design for Romică is centered around efficient, reliable communication between the robot's hardware components and the end user. The project is developed using PlatformIO on Visual Studio Code, a robust and feature-rich environment for embedded systems development.

## Final Results
TBD - This section will document the robot's performance, including its speed, responsiveness, and user feedback.

## Conclusions
TBD - The conclusions will reflect on the challenges faced, solutions implemented, and potential improvements.

## Source Code
TBD

## Resources
TBD
