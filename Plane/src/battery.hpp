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

/**
 * @class battery
 * @brief Represents the battery and implements methods to get its charge level
 */
class battery
{
private:
  byte m_nbCells;
  int* m_resistorValues;
  float m_temperature;
  float m_humidity;
  float* m_cellVoltages;
  /**
   * @brief 
   * 
   */
  float* m_cellLevels;
  
public:
  battery();
  ~battery();
  /**
   * @brief refreshes all values
   */
  void refresh();

  float getTemp(){return m_temperature;}
  float getHumidity(){return m_humidity;}

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
    for(byte i = 0; i<)
  }
};
