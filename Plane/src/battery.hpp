/**
 * @file battery.hpp
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief definition and declaration of battery class
 * @version 0.1
 * @date 2020-11-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef BATTERY_HPP
#define BATTERY_HPP

#define LIPO_LOWEST_VOLTAGE 3
#define LIPO_HIGHEST_VOLTAGE 4.2
#define ANALOG_REF 5
#define ANALOG_PRECISION 1023

/**
 * @class battery
 * @brief Represents the Lipo battery pack and implements methods to get its charge level
 */
class Battery
{
private:
  byte m_nbCells;
  /**
   * @brief values of resistors used in the voltage divider
   * @note set to 0 where there is no resistance
   */
  int **m_resistorValues;
  /**
   * @brief array containing voltage divider output pins
   */
  byte *m_pinout;
  /**
   * @brief individual voltages of battery cells in Volts
   */
  float *m_cellVoltages;
  /**
   * @brief individual levels of battery cells in percent
   */
  float *m_cellLevels;

public:
  Battery()
  {
    this->m_nbCells = 0;
    this->m_cellLevels NULL;
    this->m_cellVoltages = NULL;
    this->m_resistorValues = NULL;
    this->m_pinout = NULL;
  }
  Battery(byte NbCells_p)
  {
    Battery();
    if (NbCells_p)
    {
      m_nbCells = NbCells_p;
      this->m_resistorValues = new int *[this->m_nbCells];
      for (byte i = 0; i < m_nbCells; i++)
        this->m_resistorValues[i] = new int[2];
      this->m_pinout = new byte[];
      this->m_cellVoltages = new float[this->m_nbCells];
      this->m_cellLevels = new float[this->m_nbCells];
    }
  }

  ~Battery()
  {
    delete[] this->m_cellLevels;
    delete[] this->m_cellVoltages;
    for (byte i = 0; i < m_nbCells; i++)
      delete[] this->m_resistorValues[i];
    delete[] this->m_resistorValues;
    delete[] this->m_pinout;
  }

  void setResistorValues(const int resistorValues_p[][2])
  {
    for (byte i = 0; i < m_nbCells; i++)
      for (byte j = 0; j < 2; j++)
        m_resistorValues[i][j] = resistorValues_p[i][j];
  }

  void setPinout(const byte pinout_p[])
  {
    for (byte i = 0; i < m_nbCells; i++)
      m_pinout[i] = pinout_p[i];
  }

  /**
   * @brief refreshes all values
   */
  void refresh()
  {
    for (byte i = 0; i < m_nbCells; i++)
    {
      m_cellVoltages[i] = (float)ANALOG_REF * (float)analogRead(m_pinout[i]*(1+float(m_resistorValues[i][1])/m_resistorValues[i][0])))/ANALOG_PRECISION;
      m_cellLevels[i] = map(m_cellVoltages(LIPO_LOWEST_VOLTAGE,LIPO_HIGHEST_VOLTAGE,0,100));
    }
  }

  /**
   * @brief Get the individual voltage of a battery cell
   * @param cellSelect_p index of target cell
   * @return float 
   */
  float getCellVoltage(byte cellSelect_p)
  {
    return m_cellVoltages[cellSelect_p];
  }
  /**
   * @brief Get the individual level percentage of a battery cell
   * @param cellSelect_p index of target cell
   * @return float 
   */
  int getCellPercentage(byte cellSelect_p)
  {
    return m_cellLevels[cellSelect_p];
  }
  float getTotalVoltage()
  {
  }
};

#endif