/*
  STM32F4 Discovery basic Equation Composer with
  audio codec setup example

  This example sets up the CS43L22 and generates a sine wave sound
  at the audio jack output using the Equation Composer synthesizer library.

  October 2018, ChrisMicro

  Special thanks to Daniel Fekete for his gread STM32GENERIC support

*/

// The CS43L22 is a Low Power, Stereo DAC w/Headphone & Speaker Amps
//
// related links:
// data sheet CS43L22: https://d3uzseaevmutz1.cloudfront.net/pubs/proDatasheet/CS43L22_F2.pdf
// https://github.com/abhishek-kakkar/STM32F4Player/blob/master/STM32F4_Discovery_demo/codec_CS43L22.c
// https://www.mikrocontroller.net/topic/413574#4814689


#include <Wire.h>
#include "I2S.h"
#include "synthtest.h" // change this for other synth patch

SynthTest mysynth;
I2SClass I2S(SPI3, PC12 /*sd*/ , PA4 /*ws*/, PC10 /*ck*/, PC7/* MCK*/); // setup for STM32F4 Discovery, check your board schematic

#define SAMPLINGFREQUENCY 44100

#define AUDIOCODEC_CS PD4

#define CODEC_ADDR 0x4A // i2c address ( 2*0x4A=0x94)

void codec_writeReg(unsigned char reg, unsigned char data)
{
  uint8_t error;
  Wire.beginTransmission(CODEC_ADDR);
  Wire.write(reg);
  Wire.write(data);
  error = Wire.endTransmission();
}

// codec setup from
// https://github.com/mubase/STM32F4-Arduino-core/blob/master/cores/maple/libmaple/stm32f4codec/codec.h
// TBD: to be refactured
void codec_reg_setup(void)
{
  Wire.begin();

  codec_writeReg(0x02, 0x01); // power save registers -> all on
  codec_writeReg(0x00, 0x99);
  codec_writeReg(0x47, 0x80); //inits
  codec_writeReg(0xd, 0x3); // playback ctrl
  codec_writeReg(0x32, (1 << 7)); // vol
  codec_writeReg(0x32, (0 << 7)); // vol
  codec_writeReg(0x00, 0x00); // inits
  codec_writeReg(0x04, 0xaf); // power ctrl
  codec_writeReg(0x0d, 0x70);
  codec_writeReg(0x05, 0x81); // clocking
  codec_writeReg(0x06, 0x07);
  codec_writeReg(0x0a, 0x00);
  codec_writeReg(0x27, 0x00);
  codec_writeReg(0x80, 0x0a); // both channels on
  codec_writeReg(0x1f, 0x0f);
  codec_writeReg(0x02, 0x9e);

}

void setup()
{
  pinMode(USER_BTN,      INPUT); //user button for sound stop, mandatory for STM MCUs if you want to use the button
  pinMode(AUDIOCODEC_CS, OUTPUT); // the chip select pin of the codec needs to be enabled

  //digitalWrite(AUDIOCODEC_CS, HIGH);
  // start I2S
  // I2S will also produce MCK for the codec of aroung 12Mhz
  // without MCK the CS43L22 is not working
  I2S.begin(I2S_PHILIPS_MODE, SAMPLINGFREQUENCY, 16);

  digitalWrite(AUDIOCODEC_CS, HIGH); // enable codec

  Wire.begin(); // start the I2C driver for codec register setup
  codec_reg_setup();

  // synthesizer input parameters
  // usually connected to potis
  // range: 0..1024
  // this parameters can be set on the fly in the slow loop
  mysynth.param[0].setValue(440); // set frequency
  mysynth.param[1].setValue(3 << 8); // set waveform
  mysynth.param[2].setValue(512);
  mysynth.param[3].setValue(512);
  mysynth.param[4].setValue(512);
  mysynth.param[5].setValue(512);
  mysynth.param[6].setValue(512);
  mysynth.param[7].setValue(512);
}
void slowLoop()
{
  static uint16_t value = 440;

  mysynth.param[0].setValue(value);
  mysynth.param[1].setValue((value & 3) << 8);

  value++;
}
void loop()
{
 
  if  ( digitalRead( USER_BTN ) ) // sound on/off when button pressed
  {
    while(1);
  }
  static int16_t cycle = 0;
  static uint16_t counter = 0;
  uint16_t dacValue;

  dacValue = mysynth.run(cycle++);
  //i2s_write_sample(dacValue - 0x8000);
  int16_t val = (dacValue - 0x8000)/4;

#ifdef DEBUGWAVE
  mySerialPort.println(val);
  delay(10);
#else
  I2S.write(val); //left
  //I2S.write(val); //right
#endif
  counter++;

  if (counter > SAMPLINGFREQUENCY)
  {
    counter = 0;
    //slowLoop();
  }
}
