/**********************************************************************
  CW_CarLights_Send.h - Library for controlling car lights over I2C
  
	This library sends commands to display car lights like head and tail
	lights to a different receiver Arduino.

  Created by Chris Ward, Jan, 2017.
  MIT License. See included License file.
**********************************************************************/

#ifndef CW_CarLights_Send_h
#define CW_CarLights_Send_h
#include "CW_CarLights.h"
#include "Arduino.h"

class CW_CarLightsSend
{
  public:
		CW_CarLightsSend(byte device);
		void turnOnHeadlights();
		void turnOffHeadlights();
		void turnOnBreaks();
		void turnOffBreaks();
	
	private:
		void sendCommand(byte command);
		byte device_no;
};
#endif