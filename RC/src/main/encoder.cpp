/**
 * @file encoder.cpp
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Definition of Encoder class
 * @version 0.1
 * @date 2020-11-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "encoder.h"

Encoder::Encoder()
{
  m_count = 0;
}

Encoder::~Encoder()
{
}

void Encoder::init(uint8_t pinoutA_p, uint8_t pinoutB_p, uint8_t pinoutSW_p = -1)
{
  m_pinoutA = pinoutA_p;
  m_pinoutB = pinoutB_p;
  pinMode(m_pinoutA, INPUT);
  pinMode(m_pinoutB, INPUT);
  m_lastStateA = digitalRead(m_pinoutA);
  if(pinoutSW_p!=-1)
    m_switch.init(pinoutSW_p);
}

bool Encoder::refresh()
{
  bool stateA = digitalRead(m_pinoutA);
  bool stateB = digitalRead(m_pinoutB);
  if(stateA!=m_lastStateA)
  {
    if(stateB!=stateA)
      m_count++;
    else
      m_count--;

    m_lastStateA = stateA;
    return true;
  }
  else
    return false;  
}

int8_t Encoder::getCount()
{
  return m_count;
}

bool Encoder::isPressed()
{
  return m_switch.isPressed();
}