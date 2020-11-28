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

#include <SevSeg.h>

/**
 * @brief SevsegScreen class is responsible for displaying content on a 7-segment display
 */
class SevsegScreen : public SevSeg
{
private:
  
public:
  SevsegScreen();
  ~SevsegScreen();
  /**
   * @brief test the display with a simple chronometer
   * @note this function must be called in a while(true) loop
   */
  void test();
};

#endif