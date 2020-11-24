/**
 * @file motor.cpp
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Definition of motor class
 * @version 0.1
 * @date 2020-11-23
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "motor.h"
#include <Arduino.h>

Motor::Motor()
{
    m_speed = 0;
    m_armed = false;
    m_ESC = Servo();
}

void Motor::init(uint8_t dataPin_p)
{
  m_ESC.attach(dataPin_p,1000,2000);
}

void Motor::arm()
{
    m_ESC.write(0);
    delay(1000);
    m_armed = true;
}

void Motor::setSpeed(uint8_t newSpeed_p)
{
  if (m_armed)
    {
      m_speed = map(newSpeed_p, 0, 255, 0, MAX_SPEED);
      m_ESC.write(m_speed);
    }
}

void Motor::idle()
{
  setSpeed(0);
}

bool Motor::isArmed()
{
  return m_armed;
}

void Motor::test(int duration_p)
{
  if (m_armed)
    {
      int del = duration_p / MAX_SPEED;
      idle();
      for (uint8_t i = 0; i < MAX_SPEED; i++)
      {
        setSpeed(i);
        delay(del);
      }
    }
}