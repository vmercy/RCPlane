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

void RGBLed::init(bool ledType_p, Led redLed_p, Led greenLed_p, Led blueLed_p)
{
  m_ledType = ledType_p;
  m_primaryColorsLeds[RED] = redLed_p;
  m_primaryColorsLeds[GREEN] = greenLed_p;
  m_primaryColorsLeds[BLUE] = blueLed_p;
  turnOff();
}

void RGBLed::init(bool ledType_p, const uint8_t redPin_p, const uint8_t greenPin_p, const uint8_t bluePin_p)
{
  m_ledType = ledType_p;
  m_primaryColorsLeds[RED].init(redPin_p);
  m_primaryColorsLeds[GREEN].init(greenPin_p);
  m_primaryColorsLeds[BLUE].init(bluePin_p);
  turnOff();
}

void RGBLed::writePrimaryColor(uint8_t color_p, bool newState_p)
{
  m_primaryColorsLeds[color_p].setState(m_ledType != newState_p);
}

void RGBLed::turnOff()
{
  for (uint8_t i = 0; i < 3; i++)
    writePrimaryColor(i, OFF);
}

void RGBLed::displayColor(uint8_t color_p)
{
  turnOff();
  if (color_p >= RED && color_p <= BLUE)
    writePrimaryColor(color_p, ON);
  else
  {
    switch (color_p)
    {
    case CYAN:
    {
      writePrimaryColor(GREEN, ON);
      writePrimaryColor(BLUE, ON);
      break;
    }
    case MAGENTA:
    {
      writePrimaryColor(RED, ON);
      writePrimaryColor(BLUE, ON);
      break;
    }
    case YELLOW:
    {
      writePrimaryColor(RED, ON);
      writePrimaryColor(GREEN, ON);
      break;
    }
    case WHITE:
    {
      writePrimaryColor(RED, ON);
      writePrimaryColor(GREEN, ON);
      writePrimaryColor(BLUE, ON);
      break;
    }
    default:
      turnOff();
      break;
    }
  }
}

void RGBLed::test(int duration_p)
{
  int del = 1000*duration_p/7;
  for(uint8_t i = RED; i<=WHITE; i++)
  {
    displayColor(i);
    delay(del);
  }
  turnOff();
}