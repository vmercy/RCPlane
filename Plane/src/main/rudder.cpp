/**
 * @file rudder.cpp
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Definition of Rudder class
 * @version 0.1
 * @date 2020-12-03
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "rudder.h"

Rudder::Rudder()
{
}

Rudder::~Rudder()
{
}

void Rudder::init(uint8_t pinout_p,  uint8_t minAngle_p, uint8_t maxAngle_p)
{
  attach(pinout_p);
  m_minAngle = minAngle_p:
  m_maxAngle = maxAngle_p;
}

void Rudder::moveTo(uint8_t position_p)
{
  uint8_t targetAngle = map(position_p, 0, 255, m_reversed ? m_maxAngle : m_minAngle, m_reversed ? m_minAngle : m_maxAngle);
  write(targetAngle);
}

void Rudder::moveLeft()
{
  write(m_minAngle);
}

void Rudder::moveRight()
{
  write(m_maxAngle);
}

void Rudder::moveIdle()
{
  write((m_minAngle + m_maxAngle) / 2);
}

void Rudder::test()
{
  write(m_minAngle);
  delay(500);
  write(m_maxAngle);
  delay(500);
}