# CW_CarLights
An Arduino library to send and receive commands to control lights on an RC car/robot via I2C. This library was written for the main robot 'brain' so send commands to the 'light controller'. In my case the main brain was a an Arduino Uno, and the light controller was a small Trinket Pro.

This library has both a send and a receive part.

## CW_Carlights_Receive
CW_CarLights_Receive.ino - Sketch for controlling car lights over I2C
  
This sketch should be installed on the Arduino that is directly connected to the NeoPixels. In my case it was an Adafruit Pro Trinket. This is a sketch, not a library as I am assuming it is the only code on the receiver.

You simply need power to the trinket, power to the NeoPixels, and a single pin from the Arduino to the NeoPixels. You also need to connect the SDA and SCL pins from the sender to this receiver. Also, make sure there is a shared ground between them.

This setup is a bit flixible. It was meant to control a pair of head lights, and a pair of tail lights. I used the Adafruit Jewel for the headlights, and a pair of NeoPixel Mini PCB's for the tail lights.

The NeoPixels are numbered beginning with the first in the chain. You can set the start/end of each light in the sketch if you use different amounts of NeoPixels in your design.

## CW_Carlights_Send
CW_CarLights_Send.ino - Sketch using the CW_CarLights_Send library for controlling car
lights over I2C.

The example shows how to use the library. This library would be on the main Arduino that
is your robot brain. It is assumed that this Arduino has more going on and you would want
a simple way to send commands to your lighting Arduino, so the send code is a library.
