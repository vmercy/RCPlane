/**
 * @file joystick.cpp
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Definition of Joystick class
 * @version 0.1
 * @date 2020-11-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "joystick.h"

Joystick::Joystick()
{
}

Joystick::~Joystick()
{
}

void Joystick::init(uint8_t pinoutX_p, uint8_t pinoutY_p, uint8_t pinoutSW_p)
{
  m_pinoutX = pinoutX_p;
  m_pinoutY = pinoutY_p;
  m_switch.init(pinoutSW_p);
}

uint8_t Joystick::readX()
{
  uint8_t samples[NB_SAMPLES_JOYSTICK];
  for (uint i = 0; i <= NB_SAMPLES_JOYSTICK; i++)
  {
    samples[i] = map(analogRead(m_pinoutX), 0, 1023, 0, 255);
    delayMicroseconds(SAMPLE_DELAY);
  }

  return mean<uint8_t, uint8_t>(samples, NB_SAMPLES_JOYSTICK);
}

uint8_t Joystick::readY()
{
  uint8_t samples[NB_SAMPLES_JOYSTICK];
  for (uint i = 0; i <= NB_SAMPLES_JOYSTICK; i++)
  {
    samples[i] = map(analogRead(m_pinoutY), 0, 1023, 0, 255);
    delayMicroseconds(SAMPLE_DELAY);
  }

  return mean<uint8_t, uint8_t>(samples, NB_SAMPLES_JOYSTICK);
}

bool Joystick::isPressed()
{
  return m_switch.isPressed();
}

bool Joystick::xIdle()
{
  uint8_t reading = readX();
  return (reading >= (128 - IDLE_TOLERANCE) && reading <= (128 + IDLE_TOLERANCE));
}

bool Joystick::yIdle()
{
  uint8_t reading = readY();
  return (reading >= (128 - IDLE_TOLERANCE) && reading <= (128 + IDLE_TOLERANCE));
}

bool Joystick::idle()
{
  return xIdle() && yIdle();
}