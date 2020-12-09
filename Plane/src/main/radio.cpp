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
#include "mathFunctions.h"

Radio::Radio() {}

Radio::~Radio() {}

void Radio::init(uint8_t CEpin_p, uint8_t CSpin_p)
{
  m_module = RF24(CEpin_p, CSpin_p);
}

bool Radio::waitForConnection(int timeOut_p = -1)
{
  unsigned long timeOut = timeOut_p != (-1) ? (millis() + 1000 * timeOut_p) : 0;
  while (timeOut_p == 0 || millis() < timeOut)
  {
    receiveData();
    if (authenticateRemote())
      return true;
  }
  return false;
}

bool Radio::isConnected()
{
  return m_module.testRPD();
}

bool Radio::dataAvailable()
{
  return m_module.available();
}

bool Radio::receiveData()
{
  if (dataAvailable())
  {
    m_module.read(&m_lastFrame, sizeof(TtoPDataFrame));
    return true;
  }
  return false;
}

bool Radio::authenticateRemote()
{
  TtoPDataFrame authenticationFrame;
  authenticationFrame.pitch = extractDigit(AUTHENTICATION_PIN, 0);
  authenticationFrame.power = extractDigit(AUTHENTICATION_PIN, 1);
  authenticationFrame.roll = extractDigit(AUTHENTICATION_PIN, 2);
  authenticationFrame.yaw = extractDigit(AUTHENTICATION_PIN, 3);
  return (m_lastFrame == authenticateFrame);
}

uint8_t Radio::getPitch()
{
  return m_lastFrame.pitch;
}

uint8_t Radio::getRoll()
{
  return m_lastFrame.roll;
}

uint8_t Radio::getYaw()
{
  return m_lastFrame.yaw;
}

uint8_t Radio::getPower()
{
  return m_lastFrame.power;
}