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

#ifndef PLANE_BATTERY_DISPLAY_H
#define PLANE_BATTERY_DISPLAY_H

#include "remote_battery.h"
#include "led.h"
#include "sevsegscreen.h"
#include "settings.h"

#define NB_CELLS_TOTAL 3 //used and unsued
#define TEST_DELAY 100 //TODO: delete

/**
 * @class PlaneBatteryDisplay
 * @brief Responsible for displaying battery informations on the battery display set (1x 4 digits 7 segments display + NB_CELLS_TOTAL x cell indicator LEDs + 1x "all cells" indicator LED)
 */
class PlaneBatteryDisplay : public SevsegScreen
{
private:
  uint8_t m_nbCells;
  uint8_t m_activeCell;
  const Settings* m_settings;
  Led m_displayedCellIndicators[NB_CELLS_TOTAL+1]; //cell0 ... cellN + all
public:
  PlaneBatteryDisplay();
  ~PlaneBatteryDisplay();
  /**
   * @brief Initializes the display set
   * @param nbCells_p number of used cells
   * @param cellIndicatorsPinout_p 
   * @param displayType_p 
   * @param nbDigits_p 
   * @param sevSegDigitsPinout_p 
   * @param sevSegSegmentsPinout_p 
   * @param p_settings_p
   */
  void init(const uint8_t nbCells_p, const uint8_t cellIndicatorsPinout_p[NB_CELLS_TOTAL+1], bool displayType_p, uint8_t nbDigits_p, const uint8_t* sevSegDigitsPinout_p, const uint8_t* sevSegSegmentsPinout_p, const Settings* p_settings_p);
  /**
   * @brief prints cell voltage and level
   * @param cellSelect_p battery cell selector
   */
  void printCell(uint8_t cellSelect_p);
  /**
   * @brief prints cell voltage
   * @param cellSelect_p battery cell selector
   */
  void printCellVoltage(uint8_t cellSelect_p);
  /**
   * @brief prints cell voltage
   * @param cellSelect_p battery cell selector
   */
  void printCellLevel(uint8_t cellSelect_p);
  void printNextCell();
  void testDisplays();
};

#endif