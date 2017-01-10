/**********************************************************************
  CW_CarLights_Receive.ino - Sketch for controlling car lights over I2C
  
	This sketch should be installed on the Arduino that is directly
  connected to the NeoPixels. In my case it was an Adafruit Pro Trinket.
  This is a sketch, not a library as I am assuming it is the only code
  on the receiver.

	You simply need power to the trinket, power to the NeoPixels, and a
  single pin from the Arduino to the NeoPixels. You also need to
  connect the SDA and SCL pins from the sender to this receiver. Also,
  make sure there is a shared ground between them.

  This setup is a bit flixible. It was meant to control a pair of head
  lights, and a pair of tail lights. I used the Adafruit Jewel for the
  headlights, and a pair of NeoPixel Mini PCB's for the tail lights.

  The NeoPixels are numbered beginning with the first in the chain. You
  can set the start/end of each light in the sketch if you use
  different amounts of NeoPixels in your design.
	
  Created by Chris Ward, Jan, 2017.
  MIT License. See included License file.
**********************************************************************/

#include <Wire.h>
#include <Adafruit_NeoPixel.h>
#include <CW_CarLights.h>

#ifdef __AVR__
  #include <avr/power.h>
#endif

//The I2C device number. Must use same number in sender
const byte DEVICE_NO =         12;

// Control pin for the NeoPixels
const byte NEOPIXEL_PIN =       6;
// Status pin - a led - onboard is 13 - pulses for each command
const byte STATUS_PIN =        13;
// How many NeoPixels?
const byte NUMPIXELS =         18;
// Position in the string of the pixels
const byte LIGHT_LEFT_FIRST =   0;
const byte LIGHT_LEFT_LAST =    6;
const byte LIGHT_RIGHT_FIRST =  7;
const byte LIGHT_RIGHT_LAST =  13;
const byte BREAK_FIRST =       14;
const byte BREAK_LAST =        17;


// Initialize the NeoPixels
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

// Setup the I2C interface
void setup() {
	// set up the pixels
  pixels.begin();
  digitalWrite(STATUS_PIN, HIGH);
	// set our device number to be listening for
  Wire.begin(DEVICE_NO);
	// when an I2C event happens, process it
  Wire.onReceive(handleEvent);
	// on startup we run a pixel test
  test();
	digitalWrite(STATUS_PIN, LOW);
}

void loop() {
  delay(20);
}

// every time we hear an I2C event for our device, handle it here
void handleEvent(int howMany) {
  digitalWrite(STATUS_PIN, HIGH);
  while(Wire.available()) {
    byte command = Wire.read();
		// we have predefined commands that both send and receive understand
    switch(command) {
      case CW_CarLights::ALL_OFF:
        turnOff();
        break;
      case CW_CarLights::HEADLIGHTS_ON:
        headlightsOn();
        break;
      case CW_CarLights::HEADLIGHTS_OFF:
        headlightsOff();
        break;
      case CW_CarLights::BREAKS_ON:
        breaksOn();
        break;
      case CW_CarLights::BREAKS_OFF:
        breaksOff();
        break;
    }
  }
  digitalWrite(STATUS_PIN, LOW);
}

// used at startup to test all the pixels
void test() {
  for(int i=0;i<NUMPIXELS;i++) {
    pixels.setPixelColor(i, pixels.Color(0,50,0));
    pixels.show();
    delay(100);
  }
  turnOff();
}

// turns off all the neopixels
void turnOff() {
  for(int i=0;i<NUMPIXELS;i++) {
    pixels.setPixelColor(i, 0);
  }
  pixels.show();
}

// turns on the 'breaks' neo pixels (RED)
void breaksOn() {
  for (int i = BREAK_FIRST; i <= BREAK_LAST; i++) {
    pixels.setPixelColor(i, pixels.Color(150,0,0));
  }
  pixels.show();
}

// turns off the 'breaks' neo pixels
void breaksOff() {
  for (int i = BREAK_FIRST; i <= BREAK_LAST; i++) {
    pixels.setPixelColor(i, 0);
  }
  pixels.show();
}

// turns the left headlight on (WHITE)
void leftLightOn() {
  for (int i = LIGHT_LEFT_FIRST; i <= LIGHT_LEFT_LAST; i++) {
    pixels.setPixelColor(i, pixels.Color(50,50,50));
  }
  pixels.show();
}

// turns off the left headlight
void leftLightOff() {
  for (int i = LIGHT_LEFT_FIRST; i <= LIGHT_LEFT_LAST; i++) {
    pixels.setPixelColor(i, 0);
  }
  pixels.show();
}

// turns the right headlight on (WHITE)
void rightLightOn() {
  for (int i = LIGHT_RIGHT_FIRST; i <= LIGHT_RIGHT_LAST; i++) {
    pixels.setPixelColor(i, pixels.Color(50,50,50));
  }
  pixels.show();
}

// turns the right headlight off
void rightLightOff() {
  for (int i = LIGHT_RIGHT_FIRST; i <= LIGHT_RIGHT_LAST; i++) {
    pixels.setPixelColor(i, 0);
  }
  pixels.show();
}

// turns both left and right headlights on
void headlightsOn() {
  leftLightOn();
  rightLightOn();
}

// turns both left and right headlights off
void headlightsOff() {
  leftLightOff();
  rightLightOff();
}
