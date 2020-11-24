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

#include <RF24.h>
#include "frame.h"

#ifndef RADIO_HPP
#define RADIO_HPP

/**
 * @brief Radio class responsible for communicating with the Radio Transmitter on the ground
 */
class Radio
{
private:
  bool m_connected;
  TtoPDataFrame m_lastFrame;
  RF24 m_module;
public:
  Radio();
  ~Radio();
  void init(uint8_t CEpin_p, uint8_t CSpin_p);
  /**
   * @brief wait until Transmitter handshake
   * @note blocking method with timeout
   * @param timeOut_p timeout in seconds
   * @return true if connection is established before timeout
   */
  bool waitForConnection(int timeOut_p);
  bool isConnected();
  bool receiveData();
  uint8_t getRoll();
  uint8_t getPitch();
};
#endif