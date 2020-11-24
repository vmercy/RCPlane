/**
 * @file battery.cpp
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief definition of battery class
 * @version 0.1
 * @date 2020-11-23
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "battery.h"
#include <Arduino.h>

Battery::Battery()
{
  this->m_nbCells = 0;
  this->m_rectifierCoefficient = 1.0;
  this->m_cellLevels = NULL;
  this->m_cellVoltages = NULL;
  this->m_resistorValues = NULL;
  this->m_pinout = NULL;
}

void Battery::init(uint8_t NbCells_p, float rectifierCoefficient_p = 1.0)
{
  if (NbCells_p)
  {
    m_nbCells = NbCells_p;
    this->m_resistorValues = new int *[this->m_nbCells];
    for (uint8_t i = 0; i < m_nbCells; i++)
      this->m_resistorValues[i] = new int[2];
    this->m_pinout = new uint8_t[this->m_nbCells];
    this->m_cellVoltages = new float[this->m_nbCells];
    this->m_cellLevels = new float[this->m_nbCells];
    m_rectifierCoefficient = rectifierCoefficient_p;
  }
}

Battery::~Battery()
{
  delete[] this->m_cellLevels;
  delete[] this->m_cellVoltages;
  for (uint8_t i = 0; i < m_nbCells; i++)
    delete[] this->m_resistorValues[i];
  delete[] this->m_resistorValues;
  delete[] this->m_pinout;
}
void Battery::setResistorValues(const int resistorValues_p[][2])
{
  for (uint8_t i = 0; i < m_nbCells; i++)
    for (uint8_t j = 0; j < 2; j++)
      m_resistorValues[i][j] = resistorValues_p[i][j];
}

void Battery::setPinout(const uint8_t pinout_p[])
{
  for (uint8_t i = 0; i < m_nbCells; i++)
    m_pinout[i] = pinout_p[i];
}

void Battery::refresh()
{
  uint8_t i;
  for (i = 0; i < m_nbCells; i++)
  {
    float resistorRatio = 0.0;
    if(m_resistorValues[i][0]) //avoid division by zero
      resistorRatio = (float)m_resistorValues[i][1]/m_resistorValues[i][0];
    m_cellVoltages[i] = m_rectifierCoefficient*(float)ANALOG_REF * (float)analogRead(m_pinout[i]) * (1 + resistorRatio) / ANALOG_PRECISION; //cumulated voltages
  }
  m_globalVoltage = m_cellVoltages[m_nbCells-1];
  m_globalLevel = map(m_globalVoltage, LIPO_LOWEST_VOLTAGE, LIPO_HIGHEST_VOLTAGE, 0, 100);
  for (i = (m_nbCells - 1); i > 0 ; i--)
    m_cellVoltages[i] -= m_cellVoltages[i - 1]; //individual cell voltages
  for (i = 0; i < m_nbCells; i++)
    m_cellLevels[i] = map(m_cellVoltages[i], LIPO_LOWEST_VOLTAGE, LIPO_HIGHEST_VOLTAGE, 0, 100);
}

float Battery::getCellVoltage(uint8_t cellSelect_p)
{
  return m_cellVoltages[cellSelect_p];
}

float Battery::getCellLevel(uint8_t cellSelect_p)
{
  return m_cellLevels[cellSelect_p];
}

float Battery::getGlobalVoltage()
{
  return m_globalVoltage;
}

float Battery::getGlobalLevel()
{
  return m_globalLevel;
}