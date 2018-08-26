/*
 *  +----------------------+
 *  | ModuleComparator            |
 *  |----------------------|
 *  > frequency_input      |
 *  > wavetable_input      |
 *  |                      |
 *  |               output >
 *  +----------------------+
 */
// =============================================================================
// 
// ModuleComparator compares the two inputs 
//
// Example usage:


#ifndef ModuleCOMPARATOR_h
#define ModuleCOMPARATOR_h

#include "Arduino.h"
#include "Module.h"

class ModuleComparator : public Module
{
  
  public:
    ModuleComparator();

    // Inputs
    Module *a_input;
    Module *b_input;
    
  private:
  
    // Functions
    uint16_t compute();  

    // Variables


};

#endif
