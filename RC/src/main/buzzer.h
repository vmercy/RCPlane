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

#include "rgbled.h"
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
  /**
   * @brief the buzzer signals can be synchronized with an RGB Led
   */
  RGBLed* m_p_synchronizedLed;
public:
  Buzzer();
  ~Buzzer(); 
  /**
   * @brief Initializes buzzer on the right Arduino pin
   * @param pinout_p the Arduino pin the buzzer is attached to
   * @param enable_p enable or disable the buzzer (optional)
   * @param p_synchronizedLed_p pointer to optional synchronized RGB Led
   */
  void init(uint8_t pinout_p, bool enable_p = true, RGBLed *p_synchronizedLed_p = NULL);
  /**
   * @brief play sound
   * @param frequency_p sound frequency
   * @param duration_p sound duration
   * @param pause_p pause after sound play (optional)
   * @param delayAnyway if true, the Arduino delay blocking function will be called even if the buzzer is disabled
   */
  void sound(unsigned int frequency_p, unsigned int duration_p, unsigned int pause_p = 0, bool delayAnyway = false);
  void error(bool enableLed = true);
  void success(bool enableLed = true);
  void warning(bool enableLed = true);
  /**
   * @brief enable / disable the buzzer
   * @param newState_p new desired buzzer activation state
   */
  void setEnable(bool newState_p);
};

#endif