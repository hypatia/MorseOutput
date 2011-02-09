/*
  MorseOutput.cpp - Library for flashing Morse code.
  Created by Leigh Honeywell, 8 Feb 2011.
  Inspired by David A. Mellis's tutorial at 
  http://www.arduino.cc/en/Hacking/LibraryTutorial
  BSD-Licensed (see LICENSE).
*/

#include "WProgram.h"
#include "MorseOutput.h"

// We'll calculate the dotting speed according to the PARIS spec:
// http://en.wikipedia.org/wiki/Morse_code
// which is basically (1.2 seconds) / WPM
// Dashes are 3 * speed
// Further details of inter-character spacing are here:
// http://en.wikipedia.org/wiki/Morse_code#Representation.2C_timing_and_speeds
int speed;

MorseOutput::MorseOutput(int pin, int wpm)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
  _wpm = wpm;
  speed = 1200/_wpm;
}

void MorseOutput::dot()
{
  digitalWrite(_pin, HIGH);
  delay(speed);
  digitalWrite(_pin, LOW);
  delay(speed);  
}

void MorseOutput::dash()
{
  digitalWrite(_pin, HIGH);
  delay(speed*3);
  digitalWrite(_pin, LOW);
  delay(speed);
}

void MorseOutput::space()
{
  delay(speed*4);
}

void MorseOutput::encode(char letter)
{
  //some code is gonna go here to map letters to dot/dash patterns!
  dot();
  dash();
  //delay at the end of a letter
  delay(speed*2);
}
