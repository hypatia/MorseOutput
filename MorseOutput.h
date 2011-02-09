/*
  MorseOutput.h - Library for flashing Morse code.
  Created by Leigh Honeywell, 8 Feb 2011.
  Inspired by David A. Mellis's tutorial at 
  http://www.arduino.cc/en/Hacking/LibraryTutorial
  BSD-Licensed (see LICENSE).
*/

#ifndef MorseOutput_h
#define MorseOutput_h

#include "WProgram.h"

class MorseOutput
{
  public:
    MorseOutput(int pin, int wpm);
    void encode(char letter);
  private:
    void dot();
    void dash();
    void space();
    int _pin;
    int _wpm;
};

#endif
