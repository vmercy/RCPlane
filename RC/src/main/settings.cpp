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
}

Settings::~Settings()
{
}