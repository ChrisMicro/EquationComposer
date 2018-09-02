


#ifndef ModuleFeedbackLast_h
#define ModuleFeedbackLast_h

#include "Arduino.h"
#include "Module.h"

class ModuleFeedbackLast : public Module
{
  public:
    ModuleFeedbackLast();

    // Inputs
    Module *select;

  private:
    // Functions
    uint16_t compute();  

    // Variables

};

#endif
