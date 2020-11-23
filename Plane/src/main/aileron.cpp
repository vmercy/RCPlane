/**
 * @file aileron.cpp
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Definition of aileron class
 * @version 0.1
 * @date 2020-11-23
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "aileron.h"
#include <Arduino.h>

Aileron::Aileron()
{
  m_senseOfRotation = false;
}

Aileron::~Aileron() {}

void Aileron::init(int pin_p, int min_p, int max_p)
{
  m_servoPin = pin_p;
  m_servo.attach(pin_p);
  if (min_p <= max_p)
  {
    m_minAngle = min_p;
    m_maxAngle = max_p;
  }
  else
  {
    m_minAngle = max_p;
    m_maxAngle = min_p;
  }
}

void Aileron::reverse()
{
  m_senseOfRotation = !m_senseOfRotation;
}

void Aileron::moveTo(uint8_t percent_p)
{
  int targetAngle = 0;
  targetAngle = map(percent_p, 0, 100, m_senseOfRotation ? m_maxAngle : m_minAngle, m_senseOfRotation ? m_minAngle : m_maxAngle);
  m_servo.write(targetAngle);
}

void Aileron::moveSpeed(uint8_t final_p, uint8_t speed_p = 100, int start_p = -1)
{
  uint8_t firstStep = 0;
  if (start_p != -1)
  {
    firstStep = start_p;
    moveTo(start_p);
  }
  int stepDelay = map(speed_p, 0, 100, SLOWEST_MOVEMENT_DELAY, 0);
  for (uint8_t i = firstStep; i <= 100; i++)
  {
    moveTo(i);
    delay(stepDelay);
  }
}

void Aileron::moveUp()
{
	moveTo(100);
}

void Aileron::moveDown()
{
  moveTo(0);
}

uint8_t Aileron::getPosition()
{
  return m_servo.read();
}
