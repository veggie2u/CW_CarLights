/****************************************************************************************
  CW_CarLights_Send.ino - Sketch using the CW_CarLights_Send library for controlling car
  lights over I2C.

  This example shows how to use the library. This library would be on the main Arduino that
  is your robot brain. It is assumed that this Arduino has more going on and you would want
  a simple way to send commands to your lighting Arduino.
	
  Created by Chris Ward, Jan, 2017.
  MIT License. See included License file.
****************************************************************************************/

#include <CW_CarLights_Send.h>
#include <Arduino.h>

#ifdef __AVR__
  #include <avr/power.h>
#endif

// I2C device number you are sending to
const byte device_no = 15;

CW_CarLightsSend lights = CW_CarLightsSend(device_no);

void setup() {
	// nothing to do
}

void loop() {
	lights.turnOnHeadlights();
	delay(500);
	lights.turnOffHeadlights();
	delay(500);
	lights.turnOnBreaks();
	delay(500);
	lights.turnOffBreaks();
	delay(500);
}