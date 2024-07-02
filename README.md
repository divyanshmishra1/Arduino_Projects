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

## License

This repository is licensed under the MIT License. See the LICENSE file for more information.
