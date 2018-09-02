

#ifndef SYNTHTEST_H
#define SYNTHTEST_H
#include "Synth.h"
#include "Modules.h"


class SynthTest : public Synth
{
    public:
    ModuleConstant param[8];

    SynthTest()
    {
    
        //Define Node Objects
  ModuleComparator *moduleComparator_1 = new ModuleComparator();
  ModuleRungler *moduleRungler_1 = new ModuleRungler();

  moduleRungler_1->clock_input=moduleComparator_1;


  this->last_module = moduleRungler_1;
        
    }
};
#endif // SYNTHTEST_H    


