/**
 * @file motor.h
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Declaration of motor class
 * @version 0.1
 * @date 2020-11-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef MOTOR_HPP
#define MOTOR_HPP

#include <stdint.h>

#define MAX_SPEED 180 //degrees

#ifndef SERVO_H
#define SERVO_H
#include <Servo.h>
#endif

/**
 * @class motor
 * @brief Representation of the brushless motor
 */
class Motor
{
private:
  Servo m_ESC;
  uint8_t m_speed;
  bool m_armed;

public:
  Motor();
  /**
   * @brief Initialize a new Motor object with given attach pin
   * @param dataPin_p the pin the ESC is attached to
   */
  void init(uint8_t dataPin_p);
  ~Motor(){};
  /**
   * @brief Arms the ESC
   * @note once the ESC is armed, the motor will react to any control signal and keep it
   */
  void arm();
  /**
   * @brief Set new speed
   * @param newSpeed_p new desired speed (in percent)
   */
  void setSpeed(uint8_t newSpeed_p);
  /**
 * @brief set motor speed to idle
 */
  void idle();
  /**
 * @brief Get the state of ESC arming
 * @return true if ESC is armed
 */
  bool isArmed();
  /**
   * @brief Runs a test of the motor starting from idle and accelerating to max speed
   * @param duration_p total duration of test (from idle to max speed)
   */
  void test(int duration_p);
};

#endif