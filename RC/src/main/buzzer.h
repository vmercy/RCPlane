/**
 * @file buzzer.h
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Declaration of Buzzer class
 * @version 0.1
 * @date 2020-11-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>

class Buzzer
{
private:
  uint8_t m_pinout;
public:
  Buzzer();
  ~Buzzer();
  void init(uint8_t pinout_p);
  void error();
  void success();
  void warning();
};

#endif