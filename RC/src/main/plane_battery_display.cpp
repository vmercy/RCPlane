/**
 * @file battery_display.cpp
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Definition of PlaneBatteryBisplay class
 * @version 0.1
 * @date 2020-11-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "plane_battery_display.h"

PlaneBatteryBisplay::PlaneBatteryBisplay()
{
  m_activeCell = 0;
}

PlaneBatteryBisplay::~PlaneBatteryBisplay()
{
}

void PlaneBatteryBisplay::printCell(uint8_t cellSelect_p)
{
  if (cellSelect_p >= m_nbCells)
    return;
}

void PlaneBatteryBisplay::printNextCell()
{
  m_activeCell = (m_activeCell + 1) % m_nbCells;
  printCell(m_activeCell);
}

void PlaneBatteryBisplay::init(uint8_t nbCells_p, uint8_t cellIndicatorsPinout_p[NB_CELLS_TOTAL + 1], bool displayType_p, uint8_t nbDigits_p, uint8_t *sevSegDigitsPinout_p, uint8_t *sevSegSegmentsPinout_p)
{

  for (uint8_t i = 0; i < (NB_CELLS_TOTAL + 1); i++)
    m_displayedCellIndicators[i].init(cellIndicatorsPinout_p[i]);
  SevsegScreen::init(displayType_p, nbDigits_p, sevSegDigitsPinout_p, sevSegSegmentsPinout_p);
}

void PlaneBatteryBisplay::testDisplays()
{
  testDisplay();
  for (uint8_t i = 0; i < NB_CELLS_TOTAL + 1; i++)
  {
    m_displayedCellIndicators[i].turnOn();
    delay(TEST_DELAY);
  }
  for (uint8_t i = 0; i < NB_CELLS_TOTAL + 1; i++)
  {
    m_displayedCellIndicators[i].turnOff();
    delay(TEST_DELAY);
  }
}