/*
  I2S sine wave
  This example produces a digital sine wave on the I2S interface of the
  microcontroller.
  Hardware:
   microcontroller board: ESP8266 Node MCU AMICA @ 160MHz
   amplifier:             Adafruit I2S amplifier with the MAX98357a chip
                          https://www.adafruit.com/product/3006
  Pin description
  Node MCU AMICA
  D4: L/R
  D8: CLK
  RX: I2S-data
  
  AUGUST 2018 ChrisMicro
*/

#include <Arduino.h>
//#include "ESP8266WiFi.h"
#include <i2s.h>
#include <i2s_reg.h>

#define SAMPLINGFREQUENCY 44100
#define NUMBEROFSAMPLES   SAMPLINGFREQUENCY * 1 // 1 seconds

#define DAC_MAX_AMPLITUDE 0x2000 // experimental maximum on my speakers without distortion

void setup()
{
  //WiFi.forceSleepBegin(); // turn of wifi to reduce power consumption             
  //delay(1);     
  //system_update_cpu_freq(160); // run MCU core with full speed

  i2s_begin();
  i2s_set_rate(SAMPLINGFREQUENCY);
}

void loop()
{
  int16_t val;
  int16_t left,right;
  uint32_t leftRightCombined;
  const float   frequency = 440*2;
  const float   amplitude = DAC_MAX_AMPLITUDE;
      
  for (int n = 0; n < NUMBEROFSAMPLES; n++)
  {
    int16_t val = ( sin( 2 * PI * frequency / SAMPLINGFREQUENCY * n )) * amplitude;

    left=val;
    right=val;
    // the driver needs the two channels in the lower and upper 16 bit of the int32_t
    leftRightCombined=((uint32_t)left<<16)+(uint32_t)right;

    // blocking I2S write if buffer full
    // I2S buffer size is 512 samples
    // write two times because the sine wave calculation is so slow
    i2s_write_sample(leftRightCombined); 
    i2s_write_sample(leftRightCombined); 
  }
  
}
