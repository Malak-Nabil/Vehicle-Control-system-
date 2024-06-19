

# Vehicle Control System
This repository contains a Vehicle Control System implemented in C. The system allows the user to control the vehicle's engine, traffic light, room temperature, and engine temperature through a console-based menu. The system simulates sensor readings and updates the vehicle's state based on user input.

## Introduction
The Vehicle Control System is a console-based application that allows users to:

• Turn on/off the vehicle engine

• Set the traffic light color

• Set the room temperature

• Set the engine temperature

The system updates and displays the vehicle's state based on these inputs, simulating a vehicle's behavior in response to different sensor readings.

## Configuration
The user interacts with the system through a series of menus:

#### 1.Main Menu

    a.Turn on the vehicle engine
    b.Turn off the vehicle engine
    c.Quit the system

#### 2.Sensors Set Menu (when engine is ON):

    a.Turn off the engine
    b.Set the traffic light color
    c.Set the room temperature
    d.Set the engine temperature
## The vehicle's state is updated based on the following logic:
---
__Traffic Light Data:__

• 'G' (Green): Set vehicle speed to 100 km/hr

• 'O' (Orange): Set vehicle speed to 30 km/hr

• 'R' (Red): Set vehicle speed to 0 km/hr


--- 
__Engine Temperature Data:__

• < 100: Turn "Engine Temperature Controller" ON and set temperature to 125

• 150: Turn "Engine Temperature Controller" ON and set temperature to 125

• Otherwise: Turn "Engine Temperature Controller" OFF

---
__Additional Conditions:__

If vehicle speed is 30 km/hr:
 
  • Turn ON AC if it was OFF and set room temperature to: current_temperature * (5/4) + 1


• Turn ON "Engine Temperature Controller" if it was OFF and set engine temperature to: current_temperature * (5/4) + 1

## Display the Current Vehicle State
    Engine state: ON/OFF
    AC: ON/OFF
    Vehicle Speed
    Room Temperature
    Engine Temperature Controller State (if enabled)
    Engine Temperature




