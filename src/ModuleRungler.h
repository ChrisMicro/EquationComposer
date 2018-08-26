/*
 *  +----------------------+
 *  | ModuleRungler            |
 *  |----------------------|
 *  > frequency_input      |
 *  > wavetable_input      |
 *  |                      |
 *  |               output >
 *  +----------------------+
 */
// =============================================================================
// 
// ModuleRungler compares the two inputs 
//
// Example usage:


#ifndef ModuleRungler_h
#define ModuleRungler_h

#include "Arduino.h"
#include "Module.h"

class ModuleRungler : public Module
{
  
  public:
    ModuleRungler();

    // Inputs
    Module *clock_input;
    Module *data_input;
    
  private:
  
    // Functions
    uint16_t compute();  

    // Variables
    uint16_t oldClock;
    uint16_t shiftRegister;


};

#endif
