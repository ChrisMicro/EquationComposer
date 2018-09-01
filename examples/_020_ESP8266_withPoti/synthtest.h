

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


/* 

This is espnode86 stuff do not edit

--BEGINESPNODEPATCH--
djIuMS4xCm5ldHdvcmsvYWRkLXBhdGNoIHNhZDQgcm9vdApwYXRjaC9vcGVuIHNhZDQKcGF0Y2gvYWRkLW5vZGUgc2FkNCB1cGh2IGVzcG5vZGUvbm9kZWxpc3QgRXNwbm9kZSUyMFBhbGV0dGUKbm9kZS90dXJuLW9uIHVwaHYKcGF0Y2gvYWRkLW5vZGUgc2FkNCBs
N2VyIHNwZWNpYWwvQ29tcGFyYXRvciBhJTIwJTNFJTIwYiUyMApub2RlL3R1cm4tb24gbDdlcgpub2RlL2FkZC1pbmxldCBsN2VyIHFoZDAgZXNwbm9kZS9zdHJpbmcgYV9pbnB1dCBhX2lucHV0Cm5vZGUvYWRkLWlubGV0IGw3ZXIgd3BsNiBlc3Bub2RlL3N0cmlu
ZyBiX2lucHV0IGJfaW5wdXQKbm9kZS9hZGQtb3V0bGV0IGw3ZXIgbTJ3NyBlc3Bub2RlL3N0cmluZyBPdXQgT3V0CnBhdGNoL2FkZC1ub2RlIHNhZDQgNW9ocCBzcGVjaWFsL1J1bmdsZXIgUnVuZ2xlciUyMApub2RlL3R1cm4tb24gNW9ocApub2RlL2FkZC1pbmxl
dCA1b2hwIGVzdTYgZXNwbm9kZS9zdHJpbmcgY2xvY2tfaW5wdXQgY2xvY2tfaW5wdXQKbm9kZS9hZGQtaW5sZXQgNW9ocCB4bzFqIGVzcG5vZGUvc3RyaW5nIGRhdGFfaW5wdXQgZGF0YV9pbnB1dApub2RlL2FkZC1vdXRsZXQgNW9ocCB1bmZnIGVzcG5vZGUvc3Ry
aW5nIE91dCBPdXQKcGF0Y2gvYWRkLW5vZGUgc2FkNCB5dHpzIG91dHB1dC9kYWMgQXVkaW8lMjBEQUMKbm9kZS90dXJuLW9uIHl0enMKbm9kZS9hZGQtaW5sZXQgeXR6cyB4ZDByIGVzcG5vZGUvc3RyaW5nIGF1ZGlvX2lucHV0IGF1ZGlvX2lucHV0Cm5vZGUvbW92
ZSB1cGh2IDMwIDIwCm5vZGUvbW92ZSBsN2VyIDU2OSAxMjQKbm9kZS9tb3ZlIDVvaHAgNzY4IDE5Mwpub2RlL21vdmUgeXR6cyAxMDU1IDIxMgpvdXRsZXQvY29ubmVjdCBtMnc3IGVzdTYgeHZuYgpvdXRsZXQvY29ubmVjdCB1bmZnIHhkMHIgY3Qwcgpub2RlL3Vw
ZGF0ZS1pbmxldCB5dHpzIHhkMHIgYXVkaW9faW5wdXQgMA==
--ENDESPNODEPATCH--

*/
