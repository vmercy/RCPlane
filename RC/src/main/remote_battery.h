/**
 * @file remote_battery.h
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Declaration of RemoteBattery class
 * @version 0.1
 * @date 2020-12-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef REMOTE_BATTERY_H
#define REMOTE_BATTERY_H

#include <Arduino.h>
#include "battery.h"
#include "math_functions.h"

#define LIPO_CELL_MINIMUM_VOLTAGE 2.5
#define LIPO_CELL_MAXIMUM_VOLTAGE 4.5

/**
 * @class RemoteBattery
 * @brief RemoteBattery class is responsible for managing the battery level of the plane
 */

class RemoteBattery : private Battery
{
private:
  
public:
  RemoteBattery();
  ~RemoteBattery();
  static uint8_t toByte(float input_p);
};

#endif