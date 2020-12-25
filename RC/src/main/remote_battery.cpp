/**
 * @file remote_battery.cpp
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief 
 * @version 0.1
 * @date 2020-12-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "remote_battery.h"

RemoteBattery::RemoteBattery()
{

}

RemoteBattery::~RemoteBattery()
{
  
}

uint8_t RemoteBattery::toByte(float input_p)
{
  return mathFunctions::map<float, uint8_t, uint8_t>(input_p, LIPO_CELL_MINIMUM_VOLTAGE, LIPO_CELL_MAXIMUM_VOLTAGE, 0, UINT8_MAX);
}