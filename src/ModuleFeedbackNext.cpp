#include "Arduino.h"
#include "ModuleFeedbackNext.h"
#include "defines.h"

ModuleFeedbackNext::ModuleFeedbackNext()
{

  // Initialize all module inputs to NULL
    this->signal_next= NULL;  
    this->next1= NULL;  
    this->next2= NULL;  
    this->next3= NULL;  
    this->next4= NULL;  

    this->module_output_bit = OUTPUT_16BIT;
}

uint16_t ModuleFeedbackNext::compute()
{

    globvar[0]=this->readInput(signal_next);  
    globvar[1]=this->readInput(next1);  
    globvar[2]=this->readInput(next2); 
    globvar[3]=this->readInput(next3);  
    globvar[4]=this->readInput(next4);  

    return globvar[0];
}
