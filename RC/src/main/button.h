/**
 * @file button.h
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Declaration of Button class
 * @version 0.1
 * @date 2020-11-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

#define DEBOUNCE_DELAY 2 // the debounce time (in milliseconds) to increase if the output flickers

/**
 * @class Button
 * @brief Button class is responsible for reading a pushbutton state with debounce feature
 */

class Button
{
private:
  uint8_t m_pinout;
  bool m_state;
  unsigned long m_lastDebounceTime = 0; // the last time the output pin was toggled
public:
  Button();
  ~Button();
  /**
   * @brief Initializes the button object with given pinout
   * @param pinout_p the Arduino pin the button is attached to
   */
  void init(uint8_t pinout_p);
  bool isPressed(bool waitUntilReleased = true);
};

#endif