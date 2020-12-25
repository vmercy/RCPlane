/**
 * @file radio.h
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Declaration of radio class
 * @version 0.1
 * @date 2020-11-24
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef RADIO_HPP
#define RADIO_HPP

#include <RF24.h>
#include <SPI.h>
/* #include <nRF24L01.h>
#include <printf.h>
#include <RF24_config.h> */
#include "frame.h"

#define AUTHENTICATION_PIN 1234 //4 digit pin code used for remote authentication

/**
 * @class Radio
 * @brief Radio class responsible for communicating with the Radio Transmitter on the ground
 */
class Radio : private RF24
{
private:
  bool m_connected;
  TtoPDataFrame m_lastIncomingFrame;
  const uint8_t m_pipes[2];
  //PtoTDataFrame m_lastOutgoingFrame;
public:
  Radio(uint8_t CEpin_p, uint8_t CSpin_p);
  ~Radio();
  void init(uint8_t CEpin_p, uint8_t CSpin_p);
  /**
   * @brief wait until Transmitter handshake
   * @note blocking method with optional timeout
   * @param timeOut_p optional timeout in seconds
   * @return true if connection is established before timeout
   */
  bool waitForConnection(int timeOut_p);
  bool isConnected();
  /**
   * @brief validates an authentication frame
   * @return true if last frame is a valid authentication frame
   */
  bool authenticateRemote();
  bool dataAvailable();
  bool receiveData();
  bool sendAuthenticationAck();
  bool sendData();
  uint8_t getRoll();
  uint8_t getPitch();
  uint8_t getYaw();
  uint8_t getPower();
};
#endif