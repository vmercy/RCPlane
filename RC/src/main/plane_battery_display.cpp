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
  if(cellSelect_p>=NB_CELLS)
    return;
}

void PlaneBatteryBisplay::printNextCell()
{
  m_activeCell = (m_activeCell+1)%NB_CELLS;
  printCell(m_activeCell);
}