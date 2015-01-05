/*
  Button.h - Library for button to control a solenoid.
  Created by Johann Diedrick, December 31, 2014.
  Released into the public domain.
*/

#ifndef Button_h
#define Button_h

#include "Arduino.h"
#include <Solenoid.h>

class Button
{
  public:
  Button(int pin);
  void checkButton(Solenoid *solenoid, int delayTime);

  private:
  int _pin;
  
  int currentButtonState;
  int lastButtonState;
  
  long lastDebounceTime;
  long debounceDelay;
};

#endif
