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

Radio::Radio(uint8_t CEpin_p, uint8_t CSpin_p) : //TODO: delete args
                                                 m_pipes({0x01, 0x02})
{
}

Radio::~Radio() {}

void Radio::init(uint8_t CEpin_p, uint8_t CSpin_p)
{
  m_connected = false;
  m_lastOutgoingFrame.pitch = 0;
  m_lastOutgoingFrame.power = 0;
  m_lastOutgoingFrame.roll = 0;
  m_lastOutgoingFrame.yaw = 0;
  RF24::RF24((uint16_t)CEpin_p, (uint16_t)CSpin_p);
  begin();
  setPALevel(RF24_PA_MIN);
  setChannel(120); //TODO: define channel on macro
/*   setDataRate(RF24_1MBPS);
  setRetries(15, 15);
  printDetails(); */
  openWritingPipe(m_pipes[1]);
  //openReadingPipe(1, m_pipes[1]);
  stopListening();
}

bool Radio::authenticateRemote()
{
  TtoPDataFrame authenticationFrame;
  authenticationFrame.pitch = extractDigit(AUTHENTICATION_PIN, 0);
  authenticationFrame.power = extractDigit(AUTHENTICATION_PIN, 1);
  authenticationFrame.roll = extractDigit(AUTHENTICATION_PIN, 2);
  authenticationFrame.yaw = extractDigit(AUTHENTICATION_PIN, 3);
  return true; //TODO
  //return ((m_lastFrame.pitch == authenticationFrame.pitch) && (m_lastFrame.power == authenticationFrame.power) && (m_lastFrame.roll = authenticationFrame.roll) && (m_lastFrame.yaw == authenticationFrame.yaw));
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
  return testRPD();
}

bool Radio::dataAvailable()
{
  return available();
}

bool Radio::receiveData()
{
  /* if (dataAvailable())
  {
    read(&m_lastIncomingFrame, sizeof(TtoPDataFrame));
    return true;
  }
  return false; */
}

uint8_t Radio::setPitch(uint8_t newPitch_p)
{
  m_lastOutgoingFrame.pitch = newPitch_p;
}

uint8_t Radio::setRoll(uint8_t newRoll_p)
{
  m_lastOutgoingFrame.roll = newRoll_p;
}

uint8_t Radio::setYaw(uint8_t newYaw_p)
{
  m_lastOutgoingFrame.yaw = newYaw_p;
}

uint8_t Radio::setPower(uint8_t newPower_p)
{
  m_lastOutgoingFrame.power = newPower_p;
}

bool Radio::sendData()
{
  TtoPDataFrame frameToSend;
  frameToSend.pitch = m_lastOutgoingFrame.pitch;
  frameToSend.yaw = m_lastOutgoingFrame.yaw;
  frameToSend.power = m_lastOutgoingFrame.power;
  frameToSend.roll = m_lastOutgoingFrame.roll;
  return write(&frameToSend, sizeof(TtoPDataFrame));
}