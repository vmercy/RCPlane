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

#include <stdint.h>

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
 * @class aileron
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
	bool m_senseOfRotation;

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
   * @return true if target angle is reached
   * @param percent_p final position in percent  
   */
	void moveTo(uint8_t percent_p);

	/**
   * @brief moves aileron at specified speed
   * @param percent_p final position in percent
   * @param speed_p movement speed (in percent, optional)
   * @param start_p start position (in percent, optional)
   */
	void moveSpeed(uint8_t final_p, uint8_t speed_p = 100, int start_p = -1);

	/**
   * @brief moves aileron upward at max speed
   * @return true if maximum angle is reached
   */
	void moveUp();

	/**
   * @brief moves aileron downward at max speed
   * @return true if maximum angle is reached
   */
	void moveDown();

	uint8_t getPosition();
};

#endif