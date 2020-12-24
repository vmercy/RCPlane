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
#include "math_functions.h"

Radio::Radio(uint8_t CEpin_p, uint8_t CSpin_p) : //TODO: delete args
m_pipes({0x01, 0x02})
{
  
}

Radio::~Radio() {}

void Radio::init(uint8_t CEpin_p, uint8_t CSpin_p)
{
  m_connected = false;
  m_lastIncomingFrame.pitch = 0;
  m_lastIncomingFrame.power = 0;
  m_lastIncomingFrame.roll = 0;
  m_lastIncomingFrame.yaw = 0;
  RF24::RF24((uint16_t)CEpin_p, (uint16_t)CSpin_p);
  begin();
  setChannel(120); //TODO: define channel on macro
  openReadingPipe(1, m_pipes[1]);
  setPALevel(RF24_PA_MIN);
/*   setDataRate(RF24_1MBPS);
  setRetries(15, 15);
  printDetails(); */
  //openWritingPipe(m_pipes[1]);
  //Serial.println(m_pipes[1],HEX);
}

bool Radio::authenticateRemote()
{
  TtoPDataFrame authenticationFrame;
  authenticationFrame.pitch = mathFunctions::extractDigit(AUTHENTICATION_PIN, 0);
  authenticationFrame.power = mathFunctions::extractDigit(AUTHENTICATION_PIN, 1);
  authenticationFrame.roll = mathFunctions::extractDigit(AUTHENTICATION_PIN, 2);
  authenticationFrame.yaw = mathFunctions::extractDigit(AUTHENTICATION_PIN, 3);
  return true; //TODO
  //return ((m_lastFrame.pitch == authenticationFrame.pitch) && (m_lastFrame.power == authenticationFrame.power) && (m_lastFrame.roll = authenticationFrame.roll) && (m_lastFrame.yaw == authenticationFrame.yaw));
}

bool Radio::waitForConnection(int timeOut_p = -1)
{
  unsigned long timeOut = timeOut_p != (-1) ? (millis() + 1000 * timeOut_p) : 0;
  while ((timeOut_p == 0) || (millis() < timeOut))
  {
    receiveData();
    if (authenticateRemote())
      return true;
  }
  return false;
}

bool Radio::isConnected()
{
  return testRPD();
}

bool Radio::dataAvailable()
{
  return available();
}

bool Radio::receiveData()
{
  startListening();
  if (available())
  {
    TtoPDataFrame frame;
    read(&frame, sizeof(TtoPDataFrame));
    m_lastIncomingFrame.pitch = frame.pitch;
    m_lastIncomingFrame.yaw = frame.yaw;
    m_lastIncomingFrame.roll = frame.roll;
    m_lastIncomingFrame.power = frame.power;

    Serial.println(m_lastIncomingFrame.roll);
    return true;
  }
  return false;
}

bool Radio::sendData()
{
  stopListening();
}

uint8_t Radio::getPitch()
{
  return m_lastIncomingFrame.pitch;
}

uint8_t Radio::getRoll()
{
  return m_lastIncomingFrame.roll;
}

uint8_t Radio::getYaw()
{
  return m_lastIncomingFrame.yaw;
}

uint8_t Radio::getPower()
{
  return m_lastIncomingFrame.power;
}