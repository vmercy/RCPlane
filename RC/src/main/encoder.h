/**
 * @file encoder.h
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Declaration of Encoder class
 * @version 0.1
 * @date 2020-11-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef ENCODER_H
#define ENCODER_H

#include <Arduino.h>
#include "button.h"

/**
 * @brief Encoder class is responsible for reading rotary encoder input
 */
class Encoder
{
private:
  uint8_t m_pinoutA;
  uint8_t m_pinoutB;
  int8_t m_count;
  Button m_switch;
  bool m_lastStateA;
public:
  Encoder();
  /**
   * @brief Initialize encoder pinout on Arduino board
   * @param pinoutA_p Arduino pin the A channel of the encoder is attached to
   * @param pinoutB_p Arduino pin the B channel of the encoder is attached to
   * @param pinoutSW_p Arduino pin the switch input of the encoder is attached to
   */
  void init(uint8_t pinoutA_p, uint8_t pinoutB_p, uint8_t pinoutSW_p = -1);
  /**
   * @brief updates encoder count after rotation
   * @return true if the encoder has been rotated
   */
  bool refresh();
  /**
   * @brief Get the current count
   * @return int8_t current count
   */
  int8_t getCount();
  /**
   * @brief Get the current state of encoder button
   * @return true if the rotary encoder is clicked
   */
  bool isPressed();
  ~Encoder();
};

#endif
