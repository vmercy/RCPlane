/**
 * @file rgbled.cpp
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Definition of RGBLed class
 * @version 0.1
 * @date 2020-11-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "rgbled.h"

RGBLed::RGBLed()
{
}

RGBLed::~RGBLed()
{
}

void RGBLed::init(bool ledType_p, uint8_t redPin_p, uint8_t greenPin_p, uint8_t bluePin_p)
{
  m_ledType = ledType_p;
  for (uint8_t i = 0; i < 3; i++)
    pinMode(m_pinout[i], OUTPUT);
  turnOff();
}

void RGBLed::writeColorPin(uint8_t color_p, bool newState_p)
{
  digitalWrite(m_pinout[color_p], m_ledType);
}

void RGBLed::turnOff()
{
  for (uint8_t i = 0; i < 3; i++)
    writeColorPin(i, OFF);
}

void RGBLed::displayColor(uint8_t color_p)
{
  turnOff();
  if (color_p >= RED && color_p <= BLUE)
    writeColorPin(color_p, ON);
  else
  {
    switch (color_p)
    {
    case CYAN:
    {
      writeColorPin(GREEN, ON);
      writeColorPin(BLUE, ON);
      break;
    }
    case MAGENTA:
    {
      writeColorPin(RED, ON);
      writeColorPin(BLUE, ON);
      break;
    }
    case YELLOW:
    {
      writeColorPin(RED, ON);
      writeColorPin(GREEN, ON);
      break;
    }
    default:
      turnOff();
      break;
    }
  }
}