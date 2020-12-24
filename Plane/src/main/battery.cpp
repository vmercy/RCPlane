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
  this->m_resistorRatios = NULL;
  this->m_pinout = NULL;
}

void Battery::init(uint8_t NbCells_p, float rectifierCoefficient_p = 1.0)
{
  if (NbCells_p)
  {
    m_nbCells = NbCells_p;
    this->m_resistorRatios = new float[this->m_nbCells];
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
  delete[] this->m_resistorRatios;
  delete[] this->m_pinout;
}

void Battery::setResistorValues(const int resistorValues_p[][2])
{
  for (uint8_t i = 0; i < m_nbCells; i++)
  {
    if (resistorValues_p[i][0]) //avoid division by zero
      m_resistorRatios[i] = (float)resistorValues_p[i][1] / resistorValues_p[i][0];
    else
      m_resistorRatios[i] = 0.0;
  }
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
    uint16_t samples[NB_SAMPLES_BATTERY];
    for (uint8_t j = 0; j < NB_SAMPLES_BATTERY; j++)
    {
      samples[j] = analogRead(m_pinout[i]);
      delayMicroseconds(DELAY_SAMPLES_BATTERY);
    }
    m_cellVoltages[i] = m_rectifierCoefficient * (float)ANALOG_REF * (float)mean<float, uint16_t>(samples,NB_SAMPLES_BATTERY) * (1 + m_resistorRatios[i]) / ANALOG_PRECISION; //cumulated voltages
  }
  m_globalVoltage = m_cellVoltages[m_nbCells - 1];
  m_globalLevel = homeMap<float>(m_globalVoltage, m_nbCells * LIPO_LOWEST_VOLTAGE, m_nbCells * LIPO_HIGHEST_VOLTAGE, 0.0, 100.0);
  for (i = (m_nbCells - 1); i > 0; i--)
    m_cellVoltages[i] -= m_cellVoltages[i - 1]; //individual cell voltages
  for (i = 0; i < m_nbCells; i++)
    m_cellLevels[i] = homeMap<float>(m_cellVoltages[i], LIPO_LOWEST_VOLTAGE, LIPO_HIGHEST_VOLTAGE, 0.0, 100.0);
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

void Battery::print()
{
  Serial.println("******** BATTERY REPORT : ********");
  for (uint8_t i = 0; i < m_nbCells; i++)
  {
    Serial.print("Cell n°");
    Serial.print(i);
    Serial.print(" voltage: ");
    Serial.print(getCellVoltage(i), 2);
    Serial.println("V");
  }
  Serial.print("Total voltage : ");
  Serial.print(getGlobalVoltage(), 2);
  Serial.println("V");
  for (uint8_t i = 0; i < m_nbCells; i++)
  {
    Serial.print("Cell n°");
    Serial.print(i);
    Serial.print(" level: ");
    Serial.print(getCellLevel(i), 2);
    Serial.println("%");
  }
  Serial.print("Global level : ");
  Serial.print(getGlobalLevel(), 2);
  Serial.println("%");
  Serial.println("********");
}