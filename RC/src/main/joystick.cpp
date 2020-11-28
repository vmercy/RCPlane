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
  pinMode(m_pinoutX, INPUT);
  pinMode(m_pinoutY, INPUT); 
  m_switch.init(pinoutSW_p);
}

uint8_t Joystick::readX(bool rectify_p = true) //TODO: rectify reading if rectify_p
{
  /* TODO: add samples as class attribute
  uint8_t samples[NB_SAMPLES_JOYSTICK];
  for (uint8_t i = 0; i <= NB_SAMPLES_JOYSTICK; i++)
  {
    samples[i] = map(analogRead(m_pinoutX), 0, 1023, 0, 255);
    delay(SAMPLE_DELAY);
  }
  return (uint8_t)mean<uint8_t, uint8_t, uint16_t>(samples, NB_SAMPLES_JOYSTICK); */
  return map(analogRead(m_pinoutX), 0, 1023, 0, 255);
}

uint8_t Joystick::readY(bool rectify_p = true)
{
  /* TODO: add samples as class attribute
  uint8_t samples[NB_SAMPLES_JOYSTICK];
  for (uint8_t i = 0; i <= NB_SAMPLES_JOYSTICK; i++)
  {
    samples[i] = map(analogRead(m_pinoutY), 0, 1023, 0, 255);
    delay(SAMPLE_DELAY);
  }
  return (uint8_t)mean<uint8_t, uint8_t, uint16_t>(samples, NB_SAMPLES_JOYSTICK);
  */ 
  return map(analogRead(m_pinoutY), 0, 1023, 0, 255);
  
}

bool Joystick::isPressed()
{
  return m_switch.isPressed();
}

bool Joystick::xIdle()
{
  uint8_t reading = readX();
  return (reading >= (m_xIdlePosition - IDLE_TOLERANCE) && reading <= (m_xIdlePosition + IDLE_TOLERANCE));
}

bool Joystick::yIdle()
{
  uint8_t reading = readY();
  return (reading >= (m_yIdlePosition - IDLE_TOLERANCE) && reading <= (m_yIdlePosition + IDLE_TOLERANCE));
}

bool Joystick::idle()
{
  return (xIdle() && yIdle());
}

void Joystick::print()
{
  Serial.print("X:");
  Serial.print(readX());
  Serial.print("|Y:");
  Serial.print(readY());
  Serial.print("|SW:");
  Serial.println(isPressed());
}

void Joystick::setIdlePositions(uint8_t xIdlePosition_p, uint8_t yIdlePosition_p)
{
  m_xIdlePosition = xIdlePosition_p;
  m_yIdlePosition = yIdlePosition_p;
}

void Joystick::calibrate()
{
  setIdlePositions(readX(false), readY(false));
  delay(100);
}

uint8_t Joystick::position()
{
  if(readX()==JOYSTICK_MAX_POSITION)
  {
    if(readY()==JOYSTICK_MAX_POSITION)
      return TOP_RIGHT;
    else if(readY()==JOYSTICK_MIN_POSITION)
      return BOTTOM_RIGHT;
  }
  else if(readX()==JOYSTICK_MIN_POSITION)
  {
    if(readY()==JOYSTICK_MAX_POSITION)
      return TOP_LEFT;
    else if(readY()==JOYSTICK_MIN_POSITION)
      return BOTTOM_LEFT;
  }
  
  return UNDEFINED_POSITION;
}