/*
  poti test

  read potis and send them to the serial interface.
  You may want to use the serial plotter in the Arduino IDE to visuallize the poti values.

  Due to the fact that the ESP8266 has only one ADC a external 
  multiplexer ( CD4051 ) is used to get more ADC channels.
  The multiplexer selection channels are connected to the ESP-Pins.
  Pinout see definitions below in the code.

  
  ************************************************************************
  This sketch is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
  ********************* list of outhors **********************************

  v0.1   25.August.2018  ChrisMicro  initial version

  It is mandatory to keep the list of authors in this code.
  Please add your name if you improve/extend something

*/

#include <Arduino.h>
#include "ESP8266WiFi.h" // wifi header only needed to turn it off


// multipexer select pins
#define MULTIPLEXERPIN0 D0
#define MULTIPLEXERPIN1 D1
#define MULTIPLEXERPIN2 D2

void setup()
{
  Serial.begin(115200);
  WiFi.forceSleepBegin(); // turn of wifi to reduce power consumption
  delay(1);
  system_update_cpu_freq(160); // run MCU core with full speed

  pinMode(MULTIPLEXERPIN0, OUTPUT);
  pinMode(MULTIPLEXERPIN1, OUTPUT);
  pinMode(MULTIPLEXERPIN2, OUTPUT);

}

void selectMultiplexer(uint8_t channel)
{
  digitalWrite(MULTIPLEXERPIN0, channel & 1);
  digitalWrite(MULTIPLEXERPIN1, (channel & 2) != 0);
  digitalWrite(MULTIPLEXERPIN2, (channel & 4) != 0);
}

void loop()
{
  static uint16_t count;
  uint16_t value=analogRead(A0);
  Serial.print(value);Serial.print(" ");
  delay(1);

  selectMultiplexer(count);
  count++;
  if(count>7) 
  {
    Serial.println("");
    count=0;
  }

}




