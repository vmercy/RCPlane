/**
 * @file sevsegscreen.cpp
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Definition of SevsegScreen class
 * @version 0.1
 * @date 2020-11-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "sevsegscreen.h"

SevsegScreen::SevsegScreen()
{

}



SevsegScreen::~SevsegScreen()
{
}

void SevsegScreen::test()
{
  static unsigned long timer = millis();
  static int deciSeconds = 0;
  
  if (millis() - timer >= 100) {
    timer += 100;
    deciSeconds++; // 100 milliSeconds is equal to 1 deciSecond
    
    if (deciSeconds == 10000) { // Reset to 0 after counting for 1000 seconds.
      deciSeconds=0;
    }
    setNumber(deciSeconds, 1);
  }

  refreshDisplay(); // Must run repeatedly
}