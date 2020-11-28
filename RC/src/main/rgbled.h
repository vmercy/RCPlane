/**
 * @file rgbled.h
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Declaration of RGBLed class
 * @version 0.1
 * @date 2020-11-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef RGBLED_H
#define RGBLED_H

#include <Arduino.h>

#define RGB_COMMON_CATHODE 0
#define RGB_COMMON_ANODE 1

#define RED 0
#define GREEN 1
#define BLUE 2

#define CYAN 3
#define MAGENTA 4
#define YELLOW 5
#define WHITE 6

#ifndef LED_STATES
#define LED_STATES
#define ON 1
#define OFF 0
#endif

/**
 * @brief RGBLed class is responsible for displaying colors on an RGB Led
 */
class RGBLed
{
private:
  /**
   * @brief led type, can be either RGB_COMMON_ANODE or RGB_COMMON_CATHODE
   */
  bool m_ledType;
  uint8_t m_pinout[3];
public:
  RGBLed();
  ~RGBLed();
  /**
   * @brief initializes led type and pinout
   * @param ledType_p can be either RGB_COMMON_ANODE or RGB_COMMON_CATHODE
   * @param redPin_p the arduino pin the led red pin is connected to
   * @param greenPin_p the arduino pin the led green pin is connected to
   * @param bluePin_p the arduino pin the led blue pin is connected to
   */
  void init(bool ledType_p, uint8_t redPin_p, uint8_t greenPin_p, uint8_t bluePin_p);
  /**
   * @brief 
   * @param colorPin_p color selector, can be RED, GREEN or BLUE
   * @param newState_p new state, can be 
   */
  void writeColorPin(uint8_t colorPin_p, bool newState_p);
  /**
   * @brief displays a specific color
   * @param color_p
   */
  void displayColor(uint8_t color_p);
  void turnOff();
  /**
   * @brief displays all possible colors
   * @param duration_p duration of test (in seconds)
   */
  void test(int duration_p);
};



#endif