/**
 * @file radio.cpp
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Definition of radio class
 * @version 0.1
 * @date 2020-11-24
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <Arduino.h>
#include "radio.h"

/* Radio::Radio() {}

Radio::~Radio() {} */

void Radio::init(uint8_t CEpin_p, uint8_t CSpin_p)
{
  m_module = RF24(CEpin_p, CSpin_p);
}

bool Radio::waitForConnection(int timeOut_p)
{
  unsigned long timeOut = millis() + 1000 * timeOut_p;
  TtoPDataFrame attempt;
  while (millis() < timeOut)
  {
    if (m_module.available())
    {

      m_module.read(&attempt, sizeof(TtoPDataFrame));
      incomingFrame attemptFrame(attempt);
      if (attemptFrame.isAuthentificationFrame())
        return true;
    }
  }
  return false;
}

bool Radio::isConnected()
{
  return m_module.testRPD();
}
