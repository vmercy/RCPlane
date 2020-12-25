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

#define IDLE_TOLERANCE 1 //a joystick will be considered at idle position if its reading is IDLE_POSITION +/- IDLE_TOLERANCE

#define JOYSTICK_MIN_POSITION 0
#define JOYSTICK_MAX_POSITION 255

#define UNDEFINED_POSITION 0
#define BOTTOM_LEFT 1
#define BOTTOM_RIGHT 2
#define TOP_LEFT 3
#define TOP_RIGHT 4

#include "button.h"
#include "math_functions.h"
#include <stdio.h>

/**
 * @class Joystick
 * @brief Joystick class is responsible for reading joystick inputs on both axis and embedded switch
 */
class Joystick
{
private:
  Button m_switch;
  uint8_t m_pinoutX;
  uint8_t m_pinoutY;
  uint8_t m_xIdlePosition;
  uint8_t m_yIdlePosition;
public:
  Joystick();
  ~Joystick();
  void init(uint8_t pinoutX_p, uint8_t pinoutY_p, uint8_t pinoutSW_p);
  /**
   * @brief Set joystick new idle positions
   * @param xIdlePosition_p x axis idle position
   * @param yIdlePosition_p y axis idle position
   */
  void setIdlePositions(uint8_t xIdlePosition_p, uint8_t m_yIdlePosition_p);
  /**
   * @brief Automatically set idle positions
   * @note joystick must be released during the calibration process
   */
  void calibrate();
  uint8_t readX(bool rectify_p = true); //TODO: add rectifying feature
  uint8_t readY(bool rectify_p = true); //TODO: add rectifying feature
  bool isPressed();
  bool xIdle();
  bool yIdle();
  uint8_t position();
  bool idle();
  void print();
};


#endif