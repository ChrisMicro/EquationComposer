/*
  Rungler

  A mathematical chaos circuit invented by Rob Hordijk;
  it is at the heart of his Benjolin aleatoric instrument. 
  The circuit consists of a shift register and a basic 3-bit D/A converter. 
  An external VCO is fed as the input to the shift register 
  (the input is taken to be a '1' or a '0' bit depending on if the VCO output is positive or negative),
  and a second external VCO is used to clock the shift register. 
  Three bits output by the shift register are fed to the A/D converter, 
  which produces an 8-level control voltage signal which is fed back to   
  the VCOs. This causes the VCOs to exhibit behavior which seems 
  to have a pattern but never repeats exactly. 
  Hordijk calls the circuit "bent by design", a reference to circuit bending. 

  (http://electronicmusic.wikia.com/wiki/Rungler)
  
  AUGUST 2018 by ChrisMicro

*/
#include "Arduino.h"
#include "ModuleRungler.h"
#include "defines.h"

ModuleRungler::ModuleRungler()
{
  // Initialize all module inputs to NULL
  this->clock_input       = NULL;
  this->data_input        = NULL;
  this->module_output_bit = OUTPUT_16BIT;
  oldClock = 0;
}

uint16_t ModuleRungler::compute()
{
  uint16_t feedback;
  uint16_t data  = this->readInput(data_input);
  uint16_t clock = this->readInput(clock_input);

  // we have an analog clock input
  // and the highst bit indicates zero crossing.
  clock &= 0x8000;
  // for clock detection we are only interested in the rising edge
  if (clock != oldClock && oldClock==0)
  {
    feedback       = shiftRegister >> 9; // use bit 9 for feedback
    feedback      ^= data > 8000;        // if data bit =1 invert feedback
    shiftRegister  = shiftRegister << 1; // shift left the shiftRegister by 1
    shiftRegister |= feedback & 1;       // add feedback bit
  }
  oldClock = clock;                      // store clock for next edge detect
return shiftRegister&0x3FF;
  //return (shiftRegister<<6) & 0x7000;    // use only the uppermost 3 bits as output

}


