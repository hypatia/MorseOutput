/*
  MorseOutput.cpp - Library for flashing Morse code.
  Created by Leigh Honeywell, 8 Feb 2011.
  Inspired by David A. Mellis's tutorial at 
  http://www.arduino.cc/en/Hacking/LibraryTutorial
  BSD-Licensed (see LICENSE).
*/

#include "WProgram.h"
#include "MorseOutput.h"

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
  delay(speed*4);
  digitalWrite(_pin, LOW);
  delay(speed);
}

void MorseOutput::encode(char letter)
{
  //some code is gonna go here to map letters to dot/dash patterns!
  digitalWrite(_pin, HIGH);
  delay(4*speed);
  digitalWrite(_pin, LOW);
  delay(speed);
}
