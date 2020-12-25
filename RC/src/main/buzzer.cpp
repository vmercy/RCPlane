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

void Buzzer::sound(unsigned int frequency_p, unsigned int duration_p, unsigned int pause_p = 0)
{
  if (m_enabled)
  {
    tone(m_pinout, frequency_p, duration_p);
    if (pause_p)
      delay(pause_p);
  }
}

void Buzzer::init(uint8_t pinout_p, bool enable_p = true)
{
  m_pinout = pinout_p;
  m_enabled = enable_p;
  pinMode(m_pinout, OUTPUT);
}

void Buzzer::error()
{
  sound(5000, 100, 200);
  sound(3000, 300);
}

void Buzzer::success()
{
  sound(4000, 100, 200);
  sound(5000, 100, 200);
  sound(7000, 300);
}

void Buzzer::warning()
{
  sound(4000, 100, 200);
  sound(4000, 300);
}