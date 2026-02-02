# smart-parking-monitoring-system
dual MCU smart parking monitoring system using arduino and ESP32
<br>
# Smart Parking Monitoring System

A dual-MCU embedded system that monitors parking slot availability using ultrasonic sensors and displays real-time status using Wi-Fi.

## Hardware Used
- Arduino
- ESP32
- HC-SR04 Ultrasonic Sensors
- Power Supply

## Software Used
- Arduino IDE
- Embedded C/C++
- ESP32 Wi-Fi Libraries

## System Working
1. Arduino reads ultrasonic sensors to detect vehicle presence.
2. Slot occupancy is decided using threshold logic.
3. Data is sent to ESP32 via UART.
4. ESP32 hosts a web server displaying parking availability.

## Applications
- Smart cities
- Shopping malls
- Office parking systems
