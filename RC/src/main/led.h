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
  void init();
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
};

#endif