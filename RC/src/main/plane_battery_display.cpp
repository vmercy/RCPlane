/**
 * @file battery_display.cpp
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Definition of PlaneBatteryDisplay class
 * @version 0.1
 * @date 2020-11-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "plane_battery_display.h"

PlaneBatteryDisplay::PlaneBatteryDisplay()
{
  m_activeCell = 0;
  m_settings = NULL;
}

PlaneBatteryDisplay::~PlaneBatteryDisplay()
{
}

void PlaneBatteryDisplay::printCell(uint8_t cellSelect_p)
{
  printCellVoltage(cellSelect_p);
  //delay(m_settings->getSetting<uint16_t>(BATTERY_DISPLAY_DELAY)); //TODO: replace by non-blocking delay
  delay(1000);
  printCellLevel(cellSelect_p);
  //delay(m_settings->getSetting<uint16_t>(BATTERY_DISPLAY_DELAY)); //TODO: replace by non-blocking delay
  delay(1000);
}

void PlaneBatteryDisplay::printCellVoltage(uint8_t cellSelect_p)
{
  setNumber(352,2);
  refreshDisplay();
}

void PlaneBatteryDisplay::printCellLevel(uint8_t cellSelect_p)
{
  
}

void PlaneBatteryDisplay::refreshDisplay()
{
  SevsegScreen::refreshDisplay();
}

void PlaneBatteryDisplay::printNextCell()
{
  m_activeCell = (m_activeCell + 1) % m_nbCells;
  printCell(m_activeCell);
}

void PlaneBatteryDisplay::init(const uint8_t nbCells_p, const uint8_t cellIndicatorsPinout_p[NB_CELLS_TOTAL + 1], bool displayType_p, uint8_t nbDigits_p, const uint8_t *sevSegDigitsPinout_p, const uint8_t *sevSegSegmentsPinout_p, const Settings* p_settings_p)
{

  for (uint8_t i = 0; i < (NB_CELLS_TOTAL + 1); i++)
    m_displayedCellIndicators[i].init(cellIndicatorsPinout_p[i]);
  SevsegScreen::init(displayType_p, nbDigits_p, sevSegDigitsPinout_p, sevSegSegmentsPinout_p);
  m_settings = p_settings_p;

}

void PlaneBatteryDisplay::testDisplays()
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