/**
 * @file joystick.h
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Declaration of Joystick class
 * @version 0.1
 * @date 2020-11-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef JOYSTICK_H
#define JOYSTICK_H

#define NB_SAMPLES_JOYSTICK 10 //number of readings (must be <=255)
#define SAMPLE_DELAY 500 //delay between two readings (in microseconds)
#define IDLE_TOLERANCE 3 //a joystick will be considered at idle position if its reading is 128 +/- IDLE_TOLERANCE

#include "button.h"
#include "mathFunctions.h"

class Joystick
{
private:
  Button m_switch;
  uint8_t m_pinoutX;
  uint8_t m_pinoutY;
public:
  Joystick();
  ~Joystick();
  void init(uint8_t pinoutX_p, uint8_t pinoutY_p, uint8_t pinoutSW_p);
  uint8_t readX();
  uint8_t readY();
  bool isPressed();
  bool xIdle();
  bool yIdle();
  bool idle();
};


#endif