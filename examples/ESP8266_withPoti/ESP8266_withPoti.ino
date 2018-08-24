/*
  synthesizer with potis

  Due to the fact that the ESP8266 has only one ADC a external 
  multiplexer ( CD4051 ) is used to get more ADC channels.
  The multiplexer selection channels are connected to the ESP-Pins.
  Pinout see definitions below in the code.

  This sketch uses the Eqation composer files originally from
  Microbe modular
  http://www.microbemodular.com/products/equation-composer
  
  ************************************************************************
  This sketch is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
  ********************* list of outhors **********************************

  v0.1   24.August.2018  ChrisMicro  initial version

  It is mandatory to keep the list of authors in this code.
  Please add your name if you improve/extend something

*/

#include <Arduino.h>
#include "ESP8266WiFi.h" // wifi header only needed to turn it off
#include <i2s.h>
#include <i2s_reg.h>
#include "synthtest.h" // change this for other synth patch


#define SAMPLINGFREQUENCY 44100

SynthTest mysynth;

// multipexer select pins
#define MULTIPLEXERPIN0 D0
#define MULTIPLEXERPIN1 D1
#define MULTIPLEXERPIN2 D2

void setup()
{
  WiFi.forceSleepBegin(); // turn of wifi to reduce power consumption
  delay(1);
  system_update_cpu_freq(160); // run MCU core with full speed

  Serial.begin(115200);

  i2s_begin();
  i2s_set_rate(SAMPLINGFREQUENCY);

  pinMode(MULTIPLEXERPIN0, OUTPUT);
  pinMode(MULTIPLEXERPIN1, OUTPUT);
  pinMode(MULTIPLEXERPIN2, OUTPUT);

  // synthesizer input parameters
  // usually connected to potis
  // range: 0..1024
  // this parameters can be set on the fly in the slow loop
  mysynth.param[0].setValue(440);
  mysynth.param[1].setValue(0);
  mysynth.param[2].setValue(512);
  mysynth.param[3].setValue(512);
  mysynth.param[4].setValue(512);
  mysynth.param[5].setValue(512);
  mysynth.param[6].setValue(512);
  mysynth.param[7].setValue(512);
}

void selectMultiplexer(uint8_t channel)
{
  digitalWrite(MULTIPLEXERPIN0, channel & 1);
  digitalWrite(MULTIPLEXERPIN1, (channel & 2) != 0);
  digitalWrite(MULTIPLEXERPIN2, (channel & 4) != 0);
}

void slowLoop()
{
  static uint16_t count=0;
  uint16_t value;
  value=analogRead(A0);
  if(count==0)  mysynth.param[0].setValue(value);
  if(count==1)  mysynth.param[1].setValue(value);
  if(count==2)  mysynth.param[2].setValue(value);
  if(count==3)  mysynth.param[3].setValue(value);

  //mysynth.param[1].setValue((value&3) << 8);
  Serial.println(value);
  selectMultiplexer(count);
  count++;
  if(count>3) count=0;
}


void loop()
{
  static int16_t cycle = 0;
  static uint16_t counter = 0;
  uint16_t dacValue;

  dacValue = mysynth.run(cycle++);
  i2s_write_sample(dacValue - 0x8000);

  counter++;


  if (counter > SAMPLINGFREQUENCY/250)
  {
    counter = 0;
    slowLoop();
  }

}




