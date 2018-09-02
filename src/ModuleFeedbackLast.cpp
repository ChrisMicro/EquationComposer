#include "Arduino.h"
#include "ModuleFeedbackLast.h"
#include "defines.h"

ModuleFeedbackLast::ModuleFeedbackLast()
{
  // Initialize all module inputs to NULL

  this->select = NULL;
  this->module_output_bit = OUTPUT_16BIT;
}

uint16_t ModuleFeedbackLast::compute()
{
  uint8_t index=this->readInput(select);
  uint16_t value;
  value=globvar[index];

  return value;
}
