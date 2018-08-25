# Equation Composer
Arduino Synthesizer Library for 32 bit microcontrollers

This library is based on the EQUATION composer of [Microbe Modular how to](/doc/HowTo.md).

To create various synthesizers you can use the graphical user interface espnode86

[espnode86 GUI](https://esptiny86.github.io/espnode86/)

With this graphical user interface you can create a c-code file which you can compile together with your Arduino code. The result is the synthesizer.

To use this library you need to install the corresponding Arduino framework for the specific microcontroller.

Following Microcontrollers were tested:

ESP6266,STM32 ( BlackF407 with STM32Generic Framework )

[ ESP8266 Framework Installation ](http://esp8266.github.io/Arduino/versions/2.0.0/doc/installing.html)


# The workflow for the graphical synth is like follows:

1. use the GUI and create a sketch

2. press CTRL-L .The text editor opens with the c-code in it

3. in the text editor: CTRL-A to select all CTRL-C to copy and CTRL V to paste it into "synthtest.h" in the Arduino IDE

4. press compile and download.

Use graphical node creator from Budi Prakosa to create synth patches:
https://esptiny86.github.io/espnode86/

# Credits

* MicrobeModular Equation Composer - https://github.com/clone45/EquationComposer
* https://github.com/esptiny86/espsynth86

