#include "Arduino.h"
#include "Button.h"

Button::Button(int pin){
  pinMode(pin, INPUT);
  _pin = pin;
  lastDebounceTime = 0;
  debounceDelay = 50;
  currentButtonState = LOW;
  lastButtonState = LOW;
}

void Button::checkButton(Solenoid *solenoid, int delayTime){
	int reading = digitalRead(_pin);
 
	if(reading != lastButtonState){
		lastDebounceTime = millis();
	}
  
	if((millis() - lastDebounceTime)> debounceDelay){
		if (reading != currentButtonState){
			
			currentButtonState = reading;
        
			if (currentButtonState == HIGH){
				solenoid->toggleSolenoid();
				solenoid->fireSolenoid(delayTime);
			}
    		}
  	}
    
 	// solenoid.fireSolenoid();

  	lastButtonState = reading;
  
}
