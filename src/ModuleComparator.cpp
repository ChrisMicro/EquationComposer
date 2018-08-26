#include "Arduino.h"
#include "ModuleComparator.h"
#include "defines.h"

ModuleComparator::ModuleComparator()
{

  // Initialize all module inputs to NULL
  this->a_input = NULL;  
  this->b_input = NULL;
  this->module_output_bit = OUTPUT_16BIT;
}

uint16_t ModuleComparator::compute()
{
  if( this->readInput(a_input) > this->readInput(b_input)) return 0xFFFF;
  else return 0;
  
}
