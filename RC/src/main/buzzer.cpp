/**
 * @file buzzer.cpp
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Definition of Button class
 * @version 0.1
 * @date 2020-11-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "button.h"

Button::Button()
{
  
}

Button::~Button()
{

}

void Button::init(uint8_t pinout_p)
{
  m_pinout = pinout_p;
  pinMode(m_pinout, INPUT_PULLUP);
}

bool Button::isPressed()
{
  if((millis() - m_lastDebounceTime) < DEBOUNCE_DELAY)
    return false;
  if(digitalRead(m_pinout))
  {
    if((millis() - m_lastDebounceTime) > DEBOUNCE_DELAY)
    {
      m_lastDebounceTime = millis();
      return true;
    }
  }
}