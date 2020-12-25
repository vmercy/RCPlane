/**
 * @file settings.cpp
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Definition of settings class
 * @version 0.1
 * @date 2020-12-22
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "settings.h"

Settings::Settings()
{
  setSetting(REVERT_POWER, DEFAULT_REVERT_POWER);
  setSetting(REVERT_ROLL, DEFAULT_REVERT_ROLL);
  setSetting(REVERT_YAW, DEFAULT_REVERT_YAW);
  setSetting(REVERT_PITCH, DEFAULT_REVERT_PITCH);
  setSetting(ENABLE_BUZZER, DEFAULT_ENABLE_BUZZER);
  setSetting(REDUCE_GROUND_SPEED, DEFAULT_REDUCE_GROUND_SPEED);
  setSetting(MAX_GROUND_POWER, DEFAULT_MAX_GROUND_POWER);
  //TODO: update with new settings
}

bool Settings::upToDate(uint8_t index_p)
{
  if (index_p < NB_BOOL_SETTINGS)
    return (readFromMem<bool>(index_p, false) == m_boolSettings[index_p]);
  else if (index_p < (NB_BOOL_SETTINGS + NB_BYTE_SETTINGS))
    return (readFromMem<uint8_t>(index_p, false) == m_byteSettings[index_p]);
  else if (index_p < NB_SETTINGS)
    return (readFromMem<int>(index_p, false) == m_intSettings[index_p]);
}

Settings::~Settings()
{
}

bool Settings::writeToMem(uint16_t index_p = -1)
{
  if (index_p != (uint8_t)index_p) //passed index_p is out of range
  {
    return false;
  }
  bool writeOperated = false;
  if (index_p == (-1)) //write all settings to memory
  {
    for (uint8_t i = 0; i < NB_SETTINGS; i++)
    {
      if (!upToDate(i))
      {
        //TODO
        writeOperated = true;
      }
    }
  }
  else if((index_p < NB_SETTINGS)&& !upToDate(index_p))
  {
    //TODO
    writeOperated = true;
  }
  return writeOperated;
}