# Radar de Recul - Arduino Project

**Project Overview**

This Arduino project is a distance-measuring radar system designed to function as a reverse parking assistant. Using an ultrasonic sensor, it measures the distance between the car and nearby obstacles, providing real-time feedback that helps drivers park safely. This system can alert the driver when an object is too close, offering an enhanced parking experience.

**Key Features**

- **Ultrasonic Sensor (HC-SR04)**: Utilized to measure distances accurately.
- **Real-Time Feedback**: Provides alerts to the user based on distance measurements.
- **Buzzer Warning System**: Activates to warn when an obstacle is detected within a defined range.
- **Arduino Integration**: Simple code written to gather sensor data and trigger visual and audio alerts.

**Technical Details**

- **Hardware Used**:
- Arduino Uno
- Ultrasonic sensor (HC-SR04)
- Buzzer
- Breadboard and connecting wires
- **Code File**: [Radar_de_recul.ino](Radar_de_recul.ino)
- **Working Principle**: The ultrasonic sensor sends out a high-frequency sound pulse and listens for the echo. The Arduino calculates the time taken for the echo to return to determine the distance of the obstacle. The buzzer gives an alert if the distance falls below a preset threshold.

**Setup and Running Instructions**

1. Connect the ultrasonic sensor to the Arduino as follows:
- VCC to 5V
- GND to GND
- Trig to digital pin 9
- Echo to digital pin 8
2. Connect the buzzer to digital pin 12.
3. Upload the [Radar_de_recul.ino](Radar_de_recul.ino) file to the Arduino.
4. Observe the distance on the serial monitor and listen for the buzzer alerts.
