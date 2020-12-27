/**
 * @file buzzer.cpp
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Definition of buzzer class
 * @version 0.1
 * @date 2020-11-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "buzzer.h"

Buzzer::Buzzer()
{
}

Buzzer::~Buzzer()
{
}

void Buzzer::sound(unsigned int frequency_p, unsigned int duration_p, unsigned int pause_p = 0, bool delayAnyway = false)
{
  if (m_enabled)
    tone(m_pinout, frequency_p, duration_p);
  if (m_enabled || delayAnyway)
  {
    delay(duration_p);
    if (pause_p)
      delay(pause_p);
  }
}

void Buzzer::init(uint8_t pinout_p, bool enable_p = true, RGBLed *p_synchronizedLed_p = NULL)
{
  m_pinout = pinout_p;
  m_enabled = enable_p;
  if (p_synchronizedLed_p)
    m_p_synchronizedLed = p_synchronizedLed_p;
  pinMode(m_pinout, OUTPUT);
}

void Buzzer::error(bool enableLed = true)
{
  if (enableLed)
    m_p_synchronizedLed->displayColor(RED);
  sound(5000, 100, 100, enableLed);
  sound(3000, 300, 0, enableLed);
  if (enableLed)
    m_p_synchronizedLed->turnOff();
}

void Buzzer::success(bool enableLed = true)
{
  if (enableLed)
    m_p_synchronizedLed->displayColor(GREEN);
  sound(4000, 100, 100, enableLed);
  sound(5000, 100, 100, enableLed);
  sound(7000, 300);
  if (enableLed)
    m_p_synchronizedLed->turnOff();
}

void Buzzer::warning(bool enableLed = true)
{
  if (enableLed)
    m_p_synchronizedLed->displayColor(YELLOW);
  sound(4000, 100, 100, enableLed);
  sound(4000, 300, 0, enableLed);
  if (enableLed)
    m_p_synchronizedLed->turnOff();
}

void Buzzer::setEnable(bool newState_p)
{
  m_enabled = newState_p;
}