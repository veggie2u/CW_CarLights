/**********************************************************************
  CW_CarLights.h - Library for controlling car lights over I2C
  
	This library creates some constants to be used with both send
  and recieve code to keep the control codes consistant.

  Created by Chris Ward, Jan, 2017.
  MIT License. See included License file.
**********************************************************************/

#ifdef CW_CarLights_h
#define CW_CarLights_h
#include "Arduino.h"

class CW_CarLights
{
  public:
		static constexpr byte ALL_OFF = 0;
		static constexpr byte HEADLIGHTS_ON = 1;
		static constexpr byte HEADLIGHTS_OFF = 2;
		static constexpr byte BREAKS_ON = 3;
		static constexpr byte BREAKS_OFF = 4;
};
#endif