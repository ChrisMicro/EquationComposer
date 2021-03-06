// preliminary: audio frequencies are wrong by about 30% ... why ?


/*
  I2S sine wave

  This example produces a digital sine wave on the I2S interface of the
  microcontroller.

  Hardware:
   microcontroller board: NUCLEO-F401RE (  512MB flash )


   amplifier:             Adafruit I2S amplifier with the MAX98357a chip
                          https://www.adafruit.com/product/3006

  Pin description

  sd  = DIN  // I2S data
  ws  = LRC  // left/right channel
  ck  = SCLK // serial data clock

  AUGUST 2018 ChrisMicro

*/


//#define DEBUGWAVE

#include "I2S.h"
#include "synthtest.h" // change this for other synth patch

// SPI2 pins are used for I2S.
// SPI2 is avalailable on the BalckF407VE and does not conflict with peripherals like SDIO
I2SClass I2S(SPI3, PC12 /*sd*/ , PA4 /*ws*/, PC10 /*ck*/, PC7/* MCK*/);

SynthTest mysynth;

#define SAMPLINGFREQUENCY 44100


void setup()
{
#ifdef DEBUGWAVE

  Serial.begin(115200);
#endif

  I2S.begin(I2S_PHILIPS_MODE, SAMPLINGFREQUENCY, 16);

  // synthesizer input parameters
  // usually connected to potis
  // range: 0..1024
  // this parameters can be set on the fly in the slow loop
  mysynth.param[0].setValue(440);
  mysynth.param[1].setValue(512);
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
  static int16_t cycle = 0;
  static uint16_t counter = 0;
  uint16_t dacValue;

  dacValue = mysynth.run(cycle++);
  //i2s_write_sample(dacValue - 0x8000);
  int16_t val = dacValue - 0x8000;

#ifdef DEBUGWAVE
  Serial.println(val);
  delay(10);
#else
  I2S.write(val); //left
  //I2S.write(val); //right
#endif
  counter++;

  if (counter > SAMPLINGFREQUENCY)
  {
    counter = 0;
    slowLoop();
  }

}
