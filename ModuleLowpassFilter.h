/*
 *  +----------------------+
 *  | ModuleLowpassFilter  |
 *  |----------------------|
 *  > audio_input          |
 *  > cutoff_input         |
 *  > resonance_input      |
 *  |                      |
 *  |               output >
 *  +----------------------+
 */
 
#ifndef ModuleLowpassFilter_h
#define ModuleLowpassFilter_h

#include "Arduino.h"
#include "Module.h"
#include "LowPassFilter_test.h"

class ModuleLowpassFilter : public Module
{
  
  public:
    
    // Methods
    ModuleLowpassFilter();
    uint16_t compute();
    
    // Inputs
    Module *audio_input; 
    Module *cutoff_input;
    Module *resonance_input;

    // A low pass filter object from LowPassFilter.h, not to beconfused with the ModuleLowpassFilter type.
    LowPassFilter lpf;    
                    
    // MoogVCF1
    /* long q,p,f;
  long b0,b1,b2,b3,b4,t1,t2;*/
  
  // MoogVCF2
    // long y1,y2,y3,y4,oldx,oldy1,oldy2,oldy3;                     
};

#endif
