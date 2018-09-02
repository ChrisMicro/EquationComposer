


#ifndef ModuleFeedbackNext_h
#define ModuleFeedbackNext_h

#include "Arduino.h"
#include "Module.h"

class ModuleFeedbackNext : public Module
{
  
  public:
    ModuleFeedbackNext();

    // Inputs
    Module *signal_next;
    Module *next1;
    Module *next2;
    Module *next3;
    Module *next4;
    
  private:
  
    // Functions
    uint16_t compute();  

    // Variables


};

#endif
