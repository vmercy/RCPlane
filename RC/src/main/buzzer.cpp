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

void Buzzer::init(uint8_t pinout_p, bool enable_p = true)
{
  m_pinout = pinout_p;
  m_enabled = enable_p;
  pinMode(m_pinout, OUTPUT);
}

void Buzzer::error()
{
  tone(m_pinout, 5000, 100);
  delay(200);
  tone(m_pinout, 3000, 300);
}

void Buzzer::success()
{
  tone(m_pinout, 4000, 100);
  delay(200);
  tone(m_pinout, 5000, 100);
  delay(200);
  tone(m_pinout, 7000, 300);
}

void Buzzer::warning()
{
  tone(m_pinout, 4000, 100);
  delay(200);
  tone(m_pinout, 4000, 300);
}