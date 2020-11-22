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
  //int **m_resistorValues;
  float *m_cellVoltages;
  /**
   * @brief individual levels of battery cells in percent
   */
  float *m_cellLevels;

public:
  Battery();
  Battery(byte NbCells_p)
  {
    if (NbCells_p)
    {
      m_nbCells = NbCells_p;
      /* this->m_resistorValues = new int *[this->m_nbCells];
      for (byte i = 0; i < m_nbCells; i++)
        this->m_resistorValues[i] = new int[2]; */
      this->m_cellVoltages = new float[this->m_nbCells];
      this->m_cellLevels = new float[this->m_nbCells];
    }
  }

  ~Battery()
  {
    delete[] this->m_cellLevels;
    delete[] this->m_cellVoltages;
    //delete[] this->m_resistorValues;
  }

/*   void setResistorValues(const int resistorValues_p[][2])
  {
    for (byte i = 0; i < m_nbCells; i++)
      for (byte j = 0; j < 2; j++)
        m_resistorValues[i][j] = resistorValues_p[i][j];
  } */

  /**
   * @brief refreshes all values
   */
  void refresh()
  {
    for (byte i = 0; i < m_nbCells; i++)
    {
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