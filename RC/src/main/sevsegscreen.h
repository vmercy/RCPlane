/**
 * @file sevsegscreen.h
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Declaration of SevsegScreen class
 * @version 0.1
 * @date 2020-11-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef SEVSEGSCREEN_H
#define SEVSEGSCREEN_H

#define SEVSEG_TEST_DELAY 200 //delay in milliseconds in the segments test animation (see void testDisplay)

#include <SevSeg.h>

/**
 * @class SevsegScreen
 * @brief SevsegScreen class is responsible for displaying content on a 7-segment display
 */
class SevsegScreen : public SevSeg
{
private:
  uint8_t m_nbDigits;
public:
  SevsegScreen();
  ~SevsegScreen();
  /**
   * @brief Initializes display pinout
   * @param displayType_p type of display, can be either COMMON_ANDOE or COMMON_CATHODE
   * @param nbDigits_p numbre of digits of the display
   * @param sevSegDigitsPinout_p pinout of display segments in the order {A,B,C,D,E,F,G,DP}
   * @param sevSegSegmentsPinout_p pinout of the display digits
   */
  void SevsegScreen::init(bool displayType_p, uint8_t nbDigits_p, const uint8_t* sevSegDigitsPinout_p, const uint8_t* sevSegSegmentsPinout_p);
  /**
   * @brief test the display with a simple chronometer
   * @note this function must be called in a while(true) loop
   */
  void chrono();
  /**
   * @brief test display by printing rotating pattern on all digits
   * @note blocking method
   */
  void testDisplay();
};

#endif