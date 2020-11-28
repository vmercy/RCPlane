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
  m_nbDigits = 0;
}

SevsegScreen::~SevsegScreen()
{
}

void SevsegScreen::init(bool displayType_p, uint8_t nbDigits_p, uint8_t *sevSegDigitsPinout_p, uint8_t *sevSegSegmentsPinout_p)
{
  m_nbDigits = nbDigits_p;
  begin(displayType_p, nbDigits_p, sevSegDigitsPinout_p, sevSegSegmentsPinout_p, true);
}

void SevsegScreen::testDisplay()
{
  uint8_t segments[m_nbDigits];
  unsigned long timer = millis();
  for (uint8_t i = 0; i < m_nbDigits; i++)
    segments[i] = 1;
  for (uint8_t i = 0; i < 9; i++)
  {
    setSegments(segments);
    timer = millis();
    while ((millis() - timer) < SEVSEG_TEST_DELAY)
      refreshDisplay();
    for (uint8_t j = 0; j < 4; j++)
      segments[j] *= 2;
  }
}

void SevsegScreen::chrono()
{
  static unsigned long timer = millis();
  static int deciSeconds = 0;

  if (millis() - timer >= 100)
  {
    timer += 100;
    deciSeconds++; // 100 milliSeconds is equal to 1 deciSecond

    if (deciSeconds == 10000)
    { // Reset to 0 after counting for 1000 seconds.
      deciSeconds = 0;
    }
    setNumber(deciSeconds, 1);
  }

  refreshDisplay(); // Must run repeatedly
}