/**
 * @file rudder.h
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Declaration of rudder class
 * @version 0.1
 * @date 2020-12-03
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef RUDDER_H
#define RUDDER_H

#include <Arduino.h>
#include <Servo.h>

/**
 * @brief Rudder class is responsible for moving rudder and tail wheel
 */
class Rudder : private Servo
{
private:
  uint8_t m_pinout;
  	/**
   * @brief minimum angle the servomotor can reach
   */
	uint8_t m_minAngle;
	/**
   * @brief maximum angle the servomotor can reach
   */
	uint8_t m_maxAngle;
	/**
   * @brief reverses the sense of rotation if set to true
   */
	bool m_reversed;
public:
  Rudder();
  void init(uint8_t pinout_p, uint8_t minAngle_p, uint8_t maxAngle_p);
  void moveTo(uint8_t poisition_p);
  void moveLeft();
  void moveRight();
  void test();
  void moveIdle();
  ~Rudder();
};

#endif