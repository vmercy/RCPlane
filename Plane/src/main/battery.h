/**
 * @file battery.h
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief declaration of battery class
 * @version 0.1
 * @date 2020-11-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef BATTERY_HPP
#define BATTERY_HPP

#define LIPO_1S 1
#define LIPO_2S 2
#define LIPO_3S 3
#define LIPO_4S 4
#define LIPO_5S 5
#define LIPO_6S 6

#include <Arduino.h>
#include "mathFunctions.h"

#define LIPO_LOWEST_VOLTAGE 3.3 //voltage of a normally discharged lipo cell
#define LIPO_HIGHEST_VOLTAGE 4.2 //voltage of a fully charged lipo cell
#define ANALOG_REF 5.0
#define ANALOG_PRECISION 1023

#define NB_SAMPLES_BATTERY 10 //number of readings
#define DELAY_SAMPLES_BATTERY 500 //delay between two readings (in microseconds)

/**
 * @class battery
 * @brief Represents the Lipo battery pack and implements methods to get its charge level
 */
class Battery
{
private:
  uint8_t m_nbCells;
  /**
   * @brief values of resistors ratios used in voltage dividers
   */
  float *m_resistorRatios;
  /**
   * @brief array containing voltage divider output pins
   */
  uint8_t *m_pinout;
  /**
   * @brief individual voltages of battery cells in Volts
   */
  float *m_cellVoltages;
  /**
   * @brief individual levels of battery cells in percent
   */
  float *m_cellLevels;
  /**
   * @brief global voltage of battery pack
   */
  float m_globalVoltage;
  /**
   * @brief global level of battery pack
   */
  float m_globalLevel;
  /**
   * @brief a coefficient to ajust voltge measurement according to multimiter one
   */
  float m_rectifierCoefficient;

public:
  Battery();
  /**
   * @brief Destroy the Battery object
   */
  ~Battery();
    /**
   * @brief Initialize a Battery object with a specified number of cells
   * @param NbCells_p number of cells of the battery pack
   * @param rectifierCoefficient_p the rectifier coefficient to apply on voltage measurements
   */
  void init(uint8_t NbCells_p, float rectifierCoefficient_p);
  /**
   * @brief set all resistor values used in voltage divider
   * @param resistorValues_p[][2] array containing all resistor values in the format {{R1, R2},{R3, R4}} (see README.md)
   * @note the size of resistorValues_p must be equal to the number of cells m_nbCells
   * @note set resistorValues_p[i] to {0,0} if there is no voltage divider to measure i-th cell voltage
   */
  void setResistorValues(const int resistorValues_p[][2]);
  /**
   * @brief Set the Pinout of the voltage divider in the format {}
   * @note the size of pinout_p must be equal to the number of cells m_nbCells
   * @param pinout_p 
   */
  void setPinout(const uint8_t pinout_p[]);
  /**
   * @brief refreshes voltage and level of all battery cells and global voltage and level
   */
  void refresh();
  /**
   * @brief Get the individual voltage of a battery cell
   * @param cellSelect_p index of target cell (must be < nbCells)
   * @return float selected cell voltage in volts
   */
  float getCellVoltage(uint8_t cellSelect_p);
  /**
   * @brief Get the individual level percentage of a battery cell
   * @param cellSelect_p index of target cell (must be < nbCells)
   * @return float selected cell level in percents
   */
  float getCellLevel(uint8_t cellSelect_p);
  /**
   * @brief Get the Total Voltage of the lipo pack
   * @return float total voltage in volts
   */
  float getGlobalVoltage();
  /**
   * @brief Get the Global Level of the lipo pack calculated from global voltage
   * @return float total level in percents
   */
  float getGlobalLevel();
  /**
   * @brief prints all battery data to Serial monitor
   * @note use for debugging purposes
   */
  void print();
};

#endif