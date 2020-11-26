/**
 * @file battery_display.h
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Declaration of BatteryDisplay class
 * @version 0.1
 * @date 2020-11-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "led.h"
#include "sevsegscreen.h"

#define NB_CELLS 2

class PlaneBatteryBisplay
{
private:
  Led m_displayedCellIndicators[NB_CELLS];
  SevsegScreen m_valueIndicator;
  uint8_t m_activeCell;
public:
  PlaneBatteryBisplay();
  ~PlaneBatteryBisplay();
  void printCell(uint8_t cellSelect_p);
  void printNextCell();
};
