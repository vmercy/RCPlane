/**
 * @file aileron.hpp
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Definition and declaration of aileron class
 * @version 0.1
 * @date 2020-11-22
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef AILERON_HPP
#define AILERON_HPP

/**
 * @brief the delay between two steps (1°) for a the slowest movement available
 * @note inversely proportionnal to the speed of the slowest movement
 */
#define SLOWEST_MOVEMENT_DELAY 100

#ifndef SERVO_H
#define SERVO_H
//#include "/home/valentin/Arduino/libraries/Servo/src/Servo.h"
#include <Servo.h>
#endif

/**
 * @class aileron
 * @brief Representation of the ailerons
 */
class Aileron
{
private:
	/**
   * @brief minimum angle the servomotor can reach
   */
	byte m_minAngle;
	/**
   * @brief maximum angle the servomotor can reach
   */
	byte m_maxAngle;
	/**
   * @brief reverses the sense of rotation if set to true
   */
	bool m_senseOfRotation;
	Servo m_servo;

public:
	Aileron()
	{
		m_servo = Servo();
		m_senseOfRotation = false;
	}
	/**
   * @brief Construct a new aileron object with given limit angles
   * @note limit angles will be recorded so that m_minAngle <= m_maxAngle regardless of the parameters order. See
   * @param min_p minimum angle the servomotor can reach
   * @param max_p maximum angle the servomotor can reach
   * @param pin_p the pin the servomotor is attached to
   */
	Aileron(int pin_p, int min_p, int max_p)
	{
		m_servo = Servo();
		m_servo.attach(pin_p);
		m_minAngle = min_p;
		m_maxAngle = max_p;
	}
	~Aileron();
	/**
   * @brief reverses the current sense of rotation of the servomotor
   */
	void reverse()
	{
		m_senseOfRotation = !m_senseOfRotation;
	}
	/**
   * @brief moves aileron with a given angle
   * @return true if target angle is reached
   * @param percent_p final position in percent  
   */
	bool moveTo(byte percent_p)
	{
		int targetAngle = 0;
		if (m_senseOfRotation)
			targetAngle = map(percent_p, 0, 100, targetAngle ? m_minAngle : m_maxAngle, targetAngle ? m_maxAngle : m_minAngle);
		m_servo.write(targetAngle);
		return (targetAngle == m_servo.read());
	}

	/**
   * @brief moves aileron at specified speed
   * @param percent_p final position in percent
   * @param speed_p movement speed (in percent, optional)
   * @param start_p start position (in percent, optional)
   * @return true if target angle is reached
   */
	bool moveSpeed(byte final_p, byte speed_p = 100, int start_p = -1)
	{
		byte firstStep = 0;
		if (start_p != -1)
		{
			firstStep = start_p;
			moveTo(start_p);
		}
		int stepDelay = map(speed_p, 0, 100, SLOWEST_MOVEMENT_DELAY, 0);
		for (byte i = firstStep; i <= 100; i++)
		{
			moveTo(i);
			delay(stepDelay);
		}
	}

	/**
   * @brief moves aileron upward at max speed
   * @return true if maximum angle is reached
   */
	bool moveUp()
	{
		return moveTo(100);
	}

	/**
   * @brief moves aileron downward at max speed
   * @return true if maximum angle is reached
   */
	bool moveDown()
	{
		return moveTo(0);
	}

	byte getPosition()
	{
		return m_servo.read();
	}
};

#endif