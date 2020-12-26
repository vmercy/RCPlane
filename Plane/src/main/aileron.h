/**
 * @file aileron.h
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Declaration of aileron class
 * @version 0.1
 * @date 2020-11-22
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef AILERON_HPP
#define AILERON_HPP

#include <Arduino.h>

/**
 * @brief the delay between two steps (1°) for a the slowest movement available
 * @note inversely proportionnal to the speed of the slowest movement
 */
#define SLOWEST_MOVEMENT_DELAY 100

#ifndef SERVO_H
#define SERVO_H
//#include "/home/valentin/Arduino/libraries/Servo/src/Servo.h"
#include "Servo.h"
#endif

/**
 * @class Aileron
 * @brief Representation of the ailerons
 */
class Aileron
{
private:
  Servo m_servo;
  uint8_t m_servoPin;
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
	Aileron();
	/**
   * @brief Initialize the servomotor associated with the aileron
   * @note limit angles will be recorded so that m_minAngle <= m_maxAngle regardless of the parameters order. See
   * @param min_p minimum angle the servomotor can reach
   * @param max_p maximum angle the servomotor can reach
   * @param pin_p the pin the servomotor is attached to
   */
	void init(int pin_p, int min_p, int max_p);
	~Aileron();
	/**
   * @brief reverses the current sense of rotation of the servomotor
   */
	void reverse();
	/**
   * @brief moves aileron with a given angle
   * @param position_p final position in range 0-UINT8_MAX
   * @note position_p = 0 moves the aileron down, position_p = UINT8_MAX moves the aileron up
   */
	void moveTo(uint8_t position_p);

	/**
   * @brief moves aileron at specified speed
   * @param position_p final position in range 0-UINT8_MAX
   * @param speed_p movement speed (in percent, optional)
   * @param start_p start position (in percent, optional)
   */
	void moveSpeed(uint8_t position_p, uint8_t speed_p = 100, int start_p = -1);

	/**
   * @brief moves aileron upward at max speed
   */
	void moveUp();

	/**
   * @brief moves aileron downward at max speed
   */
	void moveDown();

  /**
   * @brief moves aileron to idle position
   */
  void moveIdle();

	uint8_t getPosition();
};

#endif