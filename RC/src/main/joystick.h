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

#include <Arduino.h>

#define NB_SAMPLES_JOYSTICK 10 //number of readings (must be <=255)
#define SAMPLE_DELAY 1 //delay between two readings (in milliseconds)

#define X_IDLE_POSITION 125
#define Y_IDLE_POSITION 129
#define IDLE_TOLERANCE 2 //a joystick will be considered at idle position if its reading is IDLE_POSITION +/- IDLE_TOLERANCE

#include "button.h"
#include "mathFunctions.h"
#include <stdio.h>

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
  void print();
};


#endif