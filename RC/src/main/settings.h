/**
 * @file settings.h
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Default settings and declaration of settings class
 * @version 0.1
 * @date 2020-12-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef SETTINGS_H
#define SETTINGS_H

#include "remote_battery.h"
#include <Arduino.h>

/* Number of settings */
#define NB_BOOL_SETTINGS 6
#define NB_BYTE_SETTINGS 4
#define NB_INT_SETTINGS 1
#define NB_SETTINGS (NB_BOOL_SETTINGS + NB_BYTE_SETTINGS + NB_INT_SETTINGS)

/* Settings */
/* Boolean */
#define REVERT_POWER 0
#define REVERT_ROLL 1
#define REVERT_YAW 2
#define REVERT_PITCH 3
#define ENABLE_BUZZER 4
#define REDUCE_GROUND_SPEED 5
/* Bytes */
#define MAX_GROUND_POWER 6
#define BATTERY_CELL_ALERT_VOLTAGE 7
#define BATTERY_CELL_CRITICAL_VOLTAGE 8
#define AUTOTHRUST_CURSOR_STEP 9
/* Integers */
#define BATTERY_DISPLAY_DELAY 10 //in milliseconds

/* Default settings values */
#define DEFAULT_REVERT_POWER false
#define DEFAULT_REVERT_ROLL false
#define DEFAULT_REVERT_YAW true
#define DEFAULT_REVERT_PITCH false
#define DEFAULT_ENABLE_BUZZER true
#define DEFAULT_REDUCE_GROUND_SPEED true
#define DEFAULT_BATTERY_CELL_ALERT_VOLTAGE_BYTE RemoteBattery::toByte(BATTERY_CELL_ALERT_VOLTAGE_FLOAT)
#define DEFAULT_BATTERY_CELL_CRITICAL_VOLTAGE_BYTE RemoteBattery::toByte(BATTERY_CELL_CRITICAL_VOLTAGE_FLOAT)
#define DEFAULT_MAX_GROUND_POWER 50
#define DEFAULT_AUTOTHRUST_CURSOR_STEP 2
#define DEFAULT_BATTERY_DISPLAY_DELAY 1000

/**
 * @class Settings
 * @brief Settings class is responsible for 
 */
class Settings
{
private:
  bool m_boolSettings[NB_BOOL_SETTINGS];
  uint8_t m_byteSettings[NB_BYTE_SETTINGS];
  int m_intSettings[NB_INT_SETTINGS];
  /**
   * @brief evaluates whether a setting is up to date in EEPROM persistent memory or not
   * @param index_p 
   * @return true if setting value in EEPROM is equal to setting value in class
   */
  bool upToDate(uint8_t index_p);
public:
  Settings();
  ~Settings();
  /**
     * @brief write setting(s) into EEPROM persistent memory
     * @param index_p index of setting to write
     * @note if index_p is undefined, all settings will be written in EEPROM
     * @note since each byte of arduino EEPROM is limited to approx. 100000 writings, limit usage of this method to the strict minimum
     * @return true if write operation was necessary
     */
  bool writeToMem(uint16_t index_p = -1);
  /**
   * @brief reads data from EEPROM persistent memory
   * @tparam T type of data to read
   * @param index_p (optional)
   * @param updateSettings_p set to true to update class member 
   * @note if no index_p is passed, the method will read all settings and return the first one
   * @return T 
   */
  template <typename T>
  T readFromMem(uint16_t index_p = -1, bool updateSettings_p = true)
  {
    //TODO
  }
  /**
     * @brief Set a bool Setting value
     * @tparam T type of setting value
     * @param index_p index of setting
     * @param newValue_p new setting value
     * @param writeToMem_p true to immediately update value in EEPROM persistent memory (if necessary)
     */
  template <typename T>
  void setSetting(uint8_t index_p, T newValue_p, bool writeToMem_p = false)
  {
    if (index_p < NB_BOOL_SETTINGS)
      m_boolSettings[index_p] = newValue_p;
    else if (index_p < (NB_BOOL_SETTINGS + NB_BYTE_SETTINGS))
      m_byteSettings[index_p] = newValue_p;
    else if (index_p < NB_SETTINGS)
      m_intSettings[index_p] = newValue_p;
  }
  /**
     * @brief Get the Setting value
     * @tparam T type of setting
     * @param index_p index of setting
     * @return 
     */
  template <typename T>
  const T getSetting(uint8_t index_p) const
  {
    if (index_p < NB_BOOL_SETTINGS)
      return m_boolSettings[index_p];
    else if (index_p < (NB_BOOL_SETTINGS + NB_BYTE_SETTINGS))
      return m_byteSettings[index_p];
    else if (index_p < NB_SETTINGS)
      return m_intSettings[index_p];
  }
};

#endif