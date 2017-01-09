/**********************************************************************
  CW_CarLights.cpp - Library for controlling car lights over I2C
  
	This library creates some constants to be used with both send
  and recieve libraries.

  Created by Chris Ward, Jan, 2017.
  MIT License. See included License file.
**********************************************************************/

#include "CW_CarLights.h"

static byte CW_CarLights::ALL_OFF = 0;
static byte CW_CarLights::HEADLIGHTS_ON = 1;
static byte CW_CarLights::HEADLIGHTS_OFF = 2;
static byte CW_CarLights::BREAKS_ON = 3;
static byte CW_CarLights::BREAKS_OFF = 4;
