# Welcome to the Arduino Projects repository!

This repository contains various Arduino projects that you can explore and replicate. Each project comes with detailed instructions, circuit diagrams, required components, and more.

---

## Project 1: Traffic Lights System with Pedestrian Crossing

**Overview**

Welcome to the Traffic Lights System project repository! This project simulates a traffic light system for cars and pedestrians using Arduino Uno.

**Overview**

This project replicates a standard traffic lights system with additional pedestrian crossing signals. It includes LEDs for car traffic lights (green, yellow, red), pedestrian traffic lights (green, red), and a push button to control pedestrian signals.

**Components Needed**

- Arduino Uno
- 3 x LEDs (Red, Yellow, Green) for car traffic lights
- 2 x LEDs (Red, Green) for pedestrian traffic lights
- 1 x Pushbutton for pedestrian control
- Resistors
- Breadboard
- Jumper wires

**Simulation Link**

[Link to Wokwi Simulation](https://wokwi.com/projects/401846567697532929)

**Instructions**

### Setting Up the Circuit:
1. **Connect Components:**
   - Connect the LEDs and pushbutton to the Arduino as per the circuit diagram.
   
2. **Upload Arduino Sketch:**
   - Upload the provided Arduino sketch to control the traffic lights and pedestrian signals.

### How It Works:
- **Car Traffic Lights:**
  - Green LED: Allows cars to proceed.
  - Yellow LED: Warns cars to prepare to stop.
  - Red LED: Stops cars from moving.
  
- **Pedestrian Traffic Lights:**
  - Green LED: Allows pedestrians to cross.
  - Red LED: Signals pedestrians to stop.
  
- **Pushbutton:**
  - Mimics a pedestrian request button.
  - Pressing the button activates the pedestrian green light after the car green light turns red.
  ---




## Project 2: LED Brightness on a 16x2 LCD

**Overview**

The simplest and inexpensive way to display information is with an LCD (liquid crystal display). These are found in everyday electronic devices such as vending machines, calculators, parking meters, printers, etc. They are ideal for displaying text or small icons.
This LCD has 2 rows, and each row can display 16 characters. It also has an LED backlight to adjust the contrast between the characters and the background.

**Parts Required**

For this project, you will need the following parts:
- Arduino UNO
- 1x Breadboard
- 1x LCD 16×2
- 2x 10k Ohm Potentiometers
- 1x 5mm LED
- 1x 220 Ohm Resistor
- Jumper wires

**Simulation Link**

[Link to Wokwi Simulation](https://wokwi.com/projects/402207724433192961)

**Instructions**

### Setting Up the Circuit:
1. **Connect Components:**
   - Connect the LCD, potentiometers, LED, resistor, and Arduino as per the circuit diagram.
   
2. **Upload Arduino Sketch:**
   - Upload the provided Arduino sketch to control the LCD display and adjust LED brightness.

### How It Works:
- **LCD Display:**
  - Utilize the 16x2 LCD to display information such as brightness levels.
  
- **LED Brightness:**
  - Adjust the brightness of the LED using a potentiometer connected to the Arduino.

---

 
## Project 3: Ultrasonic Sensor HC-SR04 with Arduino

Welcome to the Ultrasonic Sensor HC-SR04 project repository! This project demonstrates how to use the HC-SR04 ultrasonic sensor with Arduino Uno to measure distances and control an LED based on the distance threshold.

## Overview

This project utilizes the HC-SR04 ultrasonic sensor to accurately measure distances using sonar technology. It displays the measured distance on the Serial Monitor and lights up an LED when the distance is less than 100 cm.

## Description

The HC-SR04 ultrasonic sensor is designed for non-contact distance measurement. It operates by emitting ultrasonic pulses and calculating the time it takes for the pulses to bounce back from an object. This time interval helps determine the distance based on the speed of sound.

### Features

- **Power Supply:** +5V DC
- **Quiescent Current:** <2mA
- **Working Current:** 15mA
- **Ranging Distance:** 2cm – 400cm / 1″ – 13ft
- **Resolution:** 0.3 cm
- **Measuring Angle:** 30 degrees
- **Trigger Input Pulse Width:** 10uS

## Components Needed

- Arduino UNO
- HC-SR04 Ultrasonic Sensor
- 1 x LED (connected to Pin 5 for indication)
- 220Ω Resistor (for the LED)
- Breadboard
- Jumper wires

## How Does it Work?

1. **Triggering**: The Arduino sends a short pulse to the trigger pin (Trig).
2. **Echo Reception**: The sensor listens for the echo signal (Echo) reflected from an object.
3. **Distance Calculation**: The Arduino calculates the distance based on the time difference between sending and receiving signals.

### LED Control

- **Distance Threshold**: If the measured distance is less than 100 cm, the LED connected to Pin 5 lights up to indicate proximity.

## Simulation Link

[Link to Wokwi Simulation](https://wokwi.com/projects/402284504252972033)

---


## Project: Parking Sensor (Distance-Based Alarm System with LED Display)

**Overview**

Welcome to the Distance-Based Alarm System project repository! This project uses an ultrasonic sensor, a piezo buzzer, and a shift register to create an alarm system that provides both auditory and visual feedback based on the proximity of an object. The closer the object, the higher the frequency of the beep and the more LEDs light up.

**Components Needed**

- ESP32 or Arduino
- HC-SR04 Ultrasonic Sensor
- Piezo Buzzer
- 74HC595 Shift Register
- 8 LEDs
- Resistors (220Ω)
- Breadboard
- Jumper Wires

**Simulation Link**

[Link to Wokwi Simulation](https://wokwi.com/projects/402469953305490433)

**Instructions**

### Setting Up the Circuit:
1. **Connect Components:**
   - Connect the HC-SR04 ultrasonic sensor to the specified pins on the ESP32 or Arduino.
   - Connect the piezo buzzer to the designated pin.
   - Connect the LEDs to the shift register and then connect the shift register to the specified pins on the ESP32 or Arduino.

2. **Upload Arduino Sketch:**
   - Upload the provided Arduino sketch to control the distance measurement, sound generation, and LED patterns.

### How It Works:
- **Distance Measurement:**
  - The ultrasonic sensor sends out a pulse and measures the time it takes for the echo to return, calculating the distance to an object.
  - This distance is printed to the serial monitor.

- **Proximity Mapping:**
  - The measured distance is mapped to a proximity level (0 to 8). This mapping uses the `map()` function, which scales the distance to fit within the desired range of proximity levels.

- **Auditory Feedback:**
  - The proximity level determines the frequency of the beep from the piezo buzzer.
  - Higher frequencies indicate closer objects, providing a shrill and anxious tone as the object approaches.

- **Visual Feedback:**
  - The proximity level determines the pattern displayed on the LEDs using a shift register.
  - More LEDs light up as the object gets closer, providing a visual indication of proximity.

- **Shift Register:**
  - The shift register is used to control multiple LEDs efficiently, reducing the number of pins needed on the microcontroller.
  - Each bit in the binary number represents the state (on/off) of an LED.

---


## License

This repository is licensed under the MIT License. See the LICENSE file for more information.
