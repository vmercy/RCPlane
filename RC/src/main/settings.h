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

/* Number of settings */
#define NB_BOOL_SETTINGS 6
#define NB_BYTE_SETTINGS 1
#define NB_INT_SETTINGS 0

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

/* Integers */

/* Default settings values */
#define DEFAULT_REVERT_POWER false
#define DEFAULT_REVERT_ROLL false
#define DEFAULT_REVERT_YAW true
#define DEFAULT_REVERT_PITCH false
#define DEFAULT_ENABLE_BUZZER true
#define DEFAULT_REDUCE_GROUND_SPEED true

#define DEFAULT_MAX_GROUND_POWER 50

/**
 * @brief Settings class is responsible for 
 */
class Settings
{
private:
  bool m_boolSettings[NB_BOOL_SETTINGS];
  uint8_t m_byteSettings[NB_BYTE_SETTINGS];
  int m_intSettings[NB_INT_SETTINGS];

public:
  Settings();
  ~Settings();
  /**
     * @brief writes all settings into EEPROM persistent memory
     */
  void writeToMem();
  /**
     * @brief retrieves all settings from EEPROM persistent memory
     */
  void readFromMem();
  /**
     * @brief Set a bool Setting value
     * @tparam T type of setting
     * @param index_p index of setting
     * @param newValue_p new setting value
     */
  template <typename T>
  void setSetting(uint8_t index_p, T newValue_p)
  {
    if (index_p < NB_BOOL_SETTINGS)
      m_boolSettings[index_p] = newValue_p;
    else if (index_p < (NB_BOOL_SETTINGS + NB_BYTE_SETTINGS))
      m_byteSettings[index_p] = newValue_p;
    else if (index_p < (NB_BOOL_SETTINGS + NB_BYTE_SETTINGS + NB_INT_SETTINGS))
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
    else if (index_p < (NB_BOOL_SETTINGS + NB_BYTE_SETTINGS + NB_INT_SETTINGS))
      return m_intSettings[index_p];
  }
};

#endif