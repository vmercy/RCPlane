/**
 * @file battery_display.cpp
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Definition of BatteryDisplaySet class
 * @version 0.1
 * @date 2020-11-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "plane_battery_display.h"

BatteryDisplaySet::BatteryDisplaySet()
{
  m_activeCell = 0;
  m_settings = NULL;
}

BatteryDisplaySet::~BatteryDisplaySet()
{
}

void BatteryDisplaySet::init(const uint8_t nbCells_p, const uint8_t cellIndicatorsPinout_p[NB_CELLS_TOTAL + 1], bool displayType_p, uint8_t nbDigits_p, const uint8_t *sevSegDigitsPinout_p, const uint8_t *sevSegSegmentsPinout_p, const Settings *p_settings_p)
{
  m_nbCells = nbCells_p;
  if(nbCells_p)
    m_activeCell = nbCells_p - 1;
  for (uint8_t i = 0; i < (NB_CELLS_TOTAL + 1); i++)
    m_displayedCellIndicators[i].init(cellIndicatorsPinout_p[i]);
  SevsegScreen::init(displayType_p, nbDigits_p, sevSegDigitsPinout_p, sevSegSegmentsPinout_p);
  m_settings = p_settings_p;
  m_displayTime = m_settings->getSetting<uint16_t>(BATTERY_DISPLAY_DELAY);
  m_lastChange = millis();
  m_displayedContent = false;
}

void BatteryDisplaySet::printCell(uint8_t cellSelect_p)
{
  if ((millis() - m_lastChange) >= m_displayTime)
  {
    m_lastChange = millis();
    m_displayedContent = !m_displayedContent;
    if (m_displayedContent)
    {
      printCellVoltage(cellSelect_p);
    }
    else
    {
      printCellLevel(cellSelect_p);
    }
  }
}

void BatteryDisplaySet::printCellVoltage(uint8_t cellSelect_p)
{
  m_displayedCellIndicators[m_activeCell].turnOff();
  m_activeCell = (m_activeCell + 1) % m_nbCells;
  m_displayedCellIndicators[m_activeCell].turnOn();
  setNumber(352, 2); //TODO add suffix letter "U" for "voltage"
}

void BatteryDisplaySet::printCellLevel(uint8_t cellSelect_p)
{
  setNumber(39, 0); //TODO add suffix letter "P" for "percent"
}

void BatteryDisplaySet::refreshDisplay()
{
  SevsegScreen::refreshDisplay();
  printCell(m_activeCell);
}

void BatteryDisplaySet::testDisplays()
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