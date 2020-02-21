# Room-Monitoring-System-with-Atmel-XMega-A1

This repository contains code written for a Temperature monitoring System as part of the Embedded System Design course.


## Hardware Used:
- Atmel XMega A1

## Python Libraries used:
- pyqt4 (for GUI development)
- pyserial (to read the serial data)

## Project Structure:
1) Embedded Codes Folder: This folder contains the embedded code written for XMega.
2) Python Scripts: This folder contains the code of GUI and data collector (using pyserial).


## Usage:
1) Upload attemp1 code on the development board. It will start sending data the _temperature_ and _light sensor_ data serially.
2) To store the data in a CSV file run the ```save_data.py``` script from the python scripts folder. 
3) To observe the data in a GUI run ```my_qt.py```.