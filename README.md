# Arduino Powered RC Plane # <!-- omit in toc -->
* Author: Valentin Mercy
* Date: 21/11/2020
* Type: Arduino Project
* Languages: C/C++ Object Oriented

- [Software](#software)
  - [UML Diagram](#uml-diagram)
  - [Dependencies](#dependencies)
- [Electronics](#electronics)
  - [The Plane](#the-plane)
    - [Lipo back voltage measurement](#lipo-back-voltage-measurement)
  - [Remote Controller](#remote-controller)

## Software ##
### UML Diagram ###
### Dependencies ###
Some external Arduino librairies are used in this project. All of them can be installed from the Arduino IDE library manager.
* Adafruit_GFX
* SPI
* Wire
* Adafruit_SSD1306


## Electronics ##
Instead of using a ready-made RC kit with a standard controller, I decided to make my own electronics based on Arduino shields (Arduino Nano for the plane and Arduino Mega 2560 Pro Embed for the Radio Controller) communicating with NRF24L01 2.4 GHz long-range modules. As the space available for electronic stuff was very limited in my plane, I could not make a proper PCB. As to the RC controller, I designed a custom PCB with Autodesk Eagle software before ordering it on [JLCPCB](https://jlcpcb.com/).

### The Plane ###
#### Lipo back voltage measurement ####

### Remote Controller ###