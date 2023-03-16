Arduino Projects
This repository contains multiple Arduino projects, each with its own folder and set of files. Below is a brief description of each project:

Project 1:
	An arduino code that can be used to controlled the 2WD DC Motor with the Joystick

Files:
	PAZ_Arduino Based Joystick Controlled 2WD DC Motor.ino
	Schematic Diagram for Joystick with DC Motor.jpg

Dependencies:
	No libraries included

Project 2:
	An arduino code that is also attached with an On/Off Switch to measure inches and centimeter to be display in LCD Display I2C

Files:
	PAZ_Distance_Measurement_using_Ultrasonic_Sensor_with_LCD_Display_I2C.
	Schematic Diagram for Distance Measurement.jpg

Dependencies:
	#include <ezButton.h>
	#include <Wire.h>
	#include <LiquidCrystal_I2C.h>

Project 3:
	This project can detect fire and gas and then the buzzer activates. There is a text to be display in LCD when there is a fire or gas 	detected.

Files:
	PAZ_Fire and Gas Alarm System.ino
	Schematic Diagram for Fire and Gas Alarm System.jpg

Dependencies:
	#include <LiquidCrystal_I2C.h>
	#include <ezButton.h>

Project 4:
	An arduino code that can detect water in a certain level, and will display the level of water in LCD Display. And also the lights will on 	depending to the level of the water being detected.

Files:
	PAZ_Arduino-Based Water Level Monitoring to be a wireless communication for flashfloods warning system.ino
	Schematic Diagram for Water Level Indicator.jpg

Dependencies:
	#include <LiquidCrystal_I2C.h>
	#include <Wire.h>

Project 5:
	This project display the text "BS COMPUTER ENGINEERING" using an 8x8 Matrix LED

Files:
	PAZ_Arduino-Based 8x8 Matrix LED.ino
	Schematic Diagram for 8x8 LED Matrix.png

Dependencies:
	#include <LedControl.h>

Project 6:
	This project is using an RFID card to unlocked the door and prints text on LCD Display

Files:
	PAZ_Arduino-Based RFID Door Locked System.ino
	Schematic Diagram for RFID Door Locked System.gif

Dependencies:
	#include <SPI.h>
	#include <MFRC522.h>
	#include <Servo.h>
	#include <Wire.h>
	#include <LiquidCrystal_I2C.h>

Project 7:
	An arduino code that can be used to display tect in LCD Display

Files:
	PAZ_Arduino-Based LCD Display.ino
	Schematic Diagram for LCD Display.jpg

Dependencies:
	#include <Wire.h> 
	#include <LiquidCrystal_I2C.h>


Contributing:
	If you would like to contribute to any of these projects, you can do the following: 
	Forking the repository, Creating an issue, Submitting a pull request,or Contributing to documentation.

Contact:
	If you have any questions or concerns about this repository, please contact me to my gmail account: afpaz@gbox.adnu.edu.ph
