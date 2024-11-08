# Surveillance Radar - Arduino Project

**Date :** 03/2024

**Project Overview**

This project is an ultrasonic surveillance radar that uses an Arduino microcontroller and an ultrasonic sensor to detect objects within a specific area. This prototype demonstrates how ultrasonic technology can be used to monitor a region, acting as a basic security or alert system.

**Key Features**

- **360° Scanning Capability**: Uses a rotating platform with an ultrasonic sensor to scan the environment continuously.
- **Object Detection and Distance Measurement**: Identifies obstacles and calculates the distance between the radar and the detected object.
- **Interactive Display**: Visualizes the scanning data on a graphical user interface (GUI) using the `Radar.pde` sketch.

**Technical Details**

- **Hardware Used**:
  - Arduino Uno
  - Ultrasonic sensor (HC-SR04)
  - Servo motor for rotating the sensor
  - Breadboard and connecting wires
- **Code Files**: [RadarUltraSon_surveillance.ino](RadarUltraSon_surveillance/RadarUltraSon_surveillance.ino) (controls the sensor and motor); [Radar.pde](Radar/Radar.pde) (the interface for visualization).
- **Working Principle**: The servo motor continuously rotates the ultrasonic sensor, which measures distances at each angle. Data is transmitted to the PC, where the `Radar.pde` Processing sketch visualizes the detected objects.

**Setup and Running Instructions**

1. Connect the ultrasonic sensor to the Arduino as follows:
   - VCC to 5V
   - GND to GND
   - Trig to digital pin 9
   - Echo to digital pin 8
2. Connect the servo motor to digital pin 10.
3. Upload the [RadarUltraSon_surveillance.ino](RadarUltraSon_surveillance/RadarUltraSon_surveillance.ino) file to the Arduino.
4. Launch the [Radar.pde](Radar/Radar.pde) using the Processing IDE to visualize the radar scan data.

**Demo**
1. **Video**
  (demonstration.mp4)


2. **Photo**
  ![photo](photo.png)

