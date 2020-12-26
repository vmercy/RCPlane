/**
 * @file roll.h
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Declaration of Roll class
 * @version 0.1
 * @date 2020-12-09
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef ROLL_H
#define ROLL_H

#include <Arduino.h>
#include "aileron.h"

/**
 * @class Roll
 * @brief Roll class is responsible for 
 */
class Roll
{
private:
  Aileron m_leftAileron;
  Aileron m_rightAileron;
  bool m_reversed;
public:
  Roll();
  void init(Aileron leftAileron_p, Aileron rightAileron_p);
  /**
   * @brief Set the Roll object
   * 
   * @param newRoll_p 0 = full left,  UINT8_MAX = full right
   */
  void setRoll(uint8_t newRoll_p);
  void moveRight();
  void moveLeft();
  void idle();
  ~Roll();
};

#endif