/**********************************************************************
  CW_CarLights_Send.cpp - Library for controlling car lights over I2C
  
	This library sends commands to display car lights like head and tail
	lights to a different receiver Arduino. The commands are in a common
  library called CW_CarLights shared with this library and the 
  CW_CarLights_Receive.ino sketch in the examples folder.

  Created by Chris Ward, Jan, 2017.
  MIT License. See included License file.
**********************************************************************/

#include "CW_CarLights_Send.h"
#include "Wire.h"

CW_CarLightsSend::CW_CarLightsSend(byte device)
{
  device_no = device;
	Wire.begin(); // join i2c bus
}

void CW_CarLightsSend::sendCommand(byte command)
{
	Wire.beginTransmission(device_no); 
	Wire.write(command);  
	Wire.endTransmission();
}

void CW_CarLightsSend::turnOnHeadlights()
{
	sendCommand(CW_CarLights::HEADLIGHTS_ON);
}

void CW_CarLightsSend::turnOffHeadlights()
{
	sendCommand(CW_CarLights::HEADLIGHTS_OFF);
}

void CW_CarLightsSend::turnOnBreaks()
{
	sendCommand(CW_CarLights::BREAKS_ON);
}

void CW_CarLightsSend::turnOffBreaks()
{
	sendCommand(CW_CarLights::BREAKS_OFF);
}

