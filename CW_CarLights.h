/**********************************************************************
  CW_CarLights.h - Library for controlling car lights over I2C
  
	This library creates some constants to be used with both send
  and recieve libraries.

  Created by Chris Ward, Jan, 2017.
  MIT License. See included License file.
**********************************************************************/

#ifndef CW_CarLights_h
#define CW_CarLights_h
#include "Arduino.h"

class CW_CarLights
{
  public:
		static byte ALL_OFF;
		static byte HEADLIGHTS_ON;
		static byte HEADLIGHTS_OFF;
		static byte BREAKS_ON;
		static byte BREAKS_OFF;
};
#endif