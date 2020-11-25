/**
 * @file led.cpp
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Definition of Led class
 * @version 0.1
 * @date 2020-11-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "led.h"

Led::Led()
{
}

void Led::init()
{
  pinMode(m_pinout, OUTPUT);
  turnOff();
}

void Led::setState(bool newState_p)
{
  digitalWrite(m_pinout, newState_p);
}

bool Led::getState()
{
  return m_ledState;
}

void Led::turnOn()
{
  setState(ON);
}

void Led::turnOff()
{
  setState(OFF);
}

Led::~Led()
{
}
