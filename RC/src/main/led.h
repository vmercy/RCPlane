/**
 * @file led.h
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Declaration of Led class
 * @version 0.1
 * @date 2020-11-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef LED_H
#define LED_H

#include <Arduino.h>

#ifndef LED_STATES
#define LED_STATES
#define ON 1
#define OFF 0
#endif

class Led
{
private:
  uint8_t m_pinout;
  bool m_ledState;

public:
  Led();
  ~Led();
  /**
   * @brief Initialize the LED pinout
   * @param pinout_p the Arduino pin the LED is attached to
   */
  void init(uint8_t pinout_p);
  /**
   * @brief Set the State
   * @param newState_p
   */
  void setState(bool newState_p);
  /**
   * @brief Get the current state of the LED
   * @return m_ledState
   */
  bool getState();
  /**
   * @brief turns the LED on
   */
  void turnOn();
  /**
   * @brief turns the LED off
   */
  void turnOff();
  /**
   * @brief blinks the LED
   * @note blocking method
   * @param period_p blink period (in milliseconds)
   * @param duration_p number of blinks
   */
  void blink(int period_p, int duration_p = 1);
};

#endif