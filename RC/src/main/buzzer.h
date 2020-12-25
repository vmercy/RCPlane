/**
 * @file buzzer.h
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Declaration of Buzzer class
 * @version 0.1
 * @date 2020-11-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>

/**
 * @class Buzzer
 * @brief Buzzer class is responsible for sound outputs
 */
class Buzzer
{
private:
  uint8_t m_pinout;
  bool m_enabled;

public:
  Buzzer();
  ~Buzzer(); 
  /**
   * @brief Initializes buzzer on the right Arduino pin
   * @param pinout_p the Arduino pin the buzzer is attached to
   * @param enable_p enable or disable the buzzer (optional)
   */
  void init(uint8_t pinout_p, bool enable_p = true);
  /**
   * @brief play sound
   * @param frequency_p sound frequency
   * @param duration_p sound duration
   * @param pause_p pause after sound play (optional)
   */
  void sound(unsigned int frequency_p, unsigned int duration_p, unsigned int pause_p = 0);
  void error();
  void success();
  void warning();
};

#endif