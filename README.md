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
   The LCD display is used to provide visual feedback, such as sensor readings or status messages. It connects to the Arduino using digital pins for communication. The control includes RS, E, and data pins (D4-D7), with additional pins for contrast and backlight.

7. **Potentiometer**  
   The potentiometer is used to adjust the contrast of the LCD display. By rotating the knob, the user can control the voltage sent to the LCD’s contrast pin, ensuring optimal visibility of the displayed text.

8. **Speaker**  
   The Speaker is used to emit sound signals, acting as an alert mechanism or for providing audio feedback in the system.

9. **9V Batteries**  
   The 9V batteries supply power to the L293D motor driver module.

10. **1.5V Batteries**  
    The 1.5V batteries supply power to the system, including the L293D motor driver module and microcontroller.

11. **Servo Motors**  
    The servo motors are used for precise movement, controlled via PWM signals from the Arduino. They are ideal for applications requiring fine control.

## Hardware Design
### Bill of Materials (BoM)
| Component       | Quantity       | Description       | Datasheet    |
|----------------|----------------|----------------|----------------|
| Arduino Uno R3                     | 1 |   Microcontroller for controlling the system.     | [Link](https://docs.arduino.cc/resources/datasheets/A000066-datasheet.pdf)|
| DC Motor                           | 4 |   It helps the robot move.                        | [Link](https://www.contact-evolution.ch/files/DC_motors.pdf) |
| 10 kΩ Potentiometer                | 1 |   Used to adjust the contrast of the LCD display. | [Link](https://components101.com/sites/default/files/component_datasheet/potentiometer%20datasheet.pdf) |
| Ultrasonic Distance Sensor (4-pin) | 1 |   Measures distance by sending ultrasonic waves.  | [Link](https://docs.google.com/document/d/1Y-yZnNhMYy7rwhAgyL_pfa39RsB-x2qR4vP8saG73rE/edit?pli=1&tab=t.0) |
| LCD 16 x 2                         | 1 |   Is used to provide visual feedback.             | [Link](https://components101.com/sites/default/files/component_datasheet/16x2%20LCD%20Datasheet.pdf) |
| H-bridge Motor Driver              | 1 |   Allows the control of DC motors.                | [Link](https://www.ti.com/lit/ds/symlink/l293.pdf) |
| Positional Micro Servo             | 2 |   Are used for precise movement.                  | [Link](https://components101.com/sites/default/files/component_datasheet/SG90%20Servo%20Motor%20Datasheet.pdf) |
| Joystick                           | 1 |   Used to provide directional input.              | [Link](https://components101.com/sites/default/files/component_datasheet/Joystick%20Module.pdf) |
| 330 Ω Resistor                     | 1 |   For limiting current and voltage division.      | N/A |
| 9V Battery                         | 2 |   Provides power for the H-bridge Motor Driver.   | N/A |
| 1.5V Battery                       | 4 |   Provides power for the Arduino Uno.             | N/A |
| 4 x AA battery holder              | 1 |   Holds the batteries.                            | N/A |
| Speaker                            | 1 |   Used to emit sound signals.                     | N/A |
| Breadboard Small                   | 2 |   For circuit assembly and prototyping.           | N/A |
| Breadboard Mini                    | 2 |   For circuit assembly and prototyping.           | N/A |
| Cables                             | 50+ | For circuit assembly and prototyping.           | N/A |

### Circuit Schematic
![CircuitSchematic](https://github.com/StefanAdrian2003/Proiect-Robotica/blob/main/Images/Circuit%20-%20Tinkercad.png)

### Circuit Photos
![CircuitPhoto1](https://github.com/StefanAdrian2003/Proiect-Robotica/blob/main/Images/Circuit%20-%20photo1.jpg)
![CircuitPhoto1](https://github.com/StefanAdrian2003/Proiect-Robotica/blob/main/Images/Circuit%20-%20photo2.jpg)

### Hardware Setup
| Component      | Pin Name       | Connected to   |
|----------------|----------------|----------------|
|Ultrasonic Sensor |VCC            |5V              |
|                  |TRIG           |6 pin           |
|                  |ECHO           |5 pin           |
|                  |GND            |GND             |
|Servo Motor1      |PWM            |4 pin           |
|                  |+              |5V from Arduino |
|                  |-              |GND             |
|Servo Motor2      |PWM            |2 pin           |
|                  |+              |5V from Arduino |
|                  |-              |GND             |
|Speaker           |+              |3 pin           |
|                  |-              |GND             |
|L293D             |1,2EN          |5V from Arduino                      |
|                  |INPUT 1        |13 pin                               |
|                  |OUTPUT 1       |DC Motor(Front-left and Back-left)   |
|                  |GND1           |GND                                  |
|                  |GND2           |GND                                  |
|                  |OUTPUT 2       |DC Motor(Front-left and Back-left)   |
|                  |INPUT 2        |12 pin                               |
|                  |VCC2           |18V from batteries                   |
|                  |3,4EN          |5V from Arduino                      |
|                  |INPUT 3        |11 pin                               |
|                  |OUTPUT 3       |DC Motor(Front-right and Back-right) |
|                  |GND3           |GND                                  |
|                  |GND4           |GND                                  |
|                  |OUTPUT 4       |DC Motor(Front-right and Back-right) |
|                  |INPUT 4        |10 pin                               |
|                  |VCC1           |5V from Arduino                      |
|LCD Display       |VSS            |GND                  |
|                  |VDD            |5V from Arduino      |
|                  |V0             |Potentiometer        |
|                  |RS             |8 pin                |
|                  |RW             |GND                  |
|                  |E              |7 pin                |
|                  |D4             |A2 pin               |
|                  |D5             |A3 pin               |
|                  |D6             |A4 pin               |
|                  |D7             |A5 pin               |
|                  |A              |5V with 330 resistor |
|                  |K              |GND                  |
|Joystick          |GND            |GND                  |
|                  |+5V            |5V from Arduino      |
|                  |VAx            |A0 pin               |
|                  |VAy            |A1 pin               |
|                  |SW             |9 pin                |

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
