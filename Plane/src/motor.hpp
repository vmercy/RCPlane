/**
 * @file motor.hpp
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Definition and declaration of motor class
 * @version 0.1
 * @date 2020-11-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef MOTOR_HPP
#define MOTOR_HPP

#ifndef SERVO_H
#define SERVO_H
#include "/home/valentin/Arduino/libraries/Servo/src/Servo.h"
#endif

/**
 * @class motor
 * @brief Representation of the brushless motor
 * 
 */
class Motor
{
private:
  Servo m_ESC;
  byte m_speed;
  bool m_armed;

public:
  Motor()
  {
    m_speed = 0;
    m_armed = false;
    m_ESC = Servo();
  }

  /**
   * @brief Construct a new Motor object with given attach pin
   * @param dataPin_p the pin the ESC is attached to
   */
  Motor(int dataPin_p)
  {
    Motor();
    m_ESC.attach(dataPin_p);
  }
  ~Motor();

  /**
   * @brief Arms the ESC
   * @note once the ESC is armed, the motor will react to any control signal and keep it
   */
  void arm()
  {
    m_ESC.write(0);
    delay(1000);
    m_armed = true;
  }

  /**
   * @brief Set new speed
   * @param newSpeed_p new desired speed (in percent)
   */
  bool setSpeed(byte newSpeed_p)
  {
    if (m_armed)
    {
      m_speed = map(newSpeed_p, 0, 100, 0, 255);
      m_ESC.write(m_speed);
    }
  }

  /**
 * @brief Get the state of ESC arming
 * @return true if ESC is armed
 */
  bool isArmed() { return m_armed; }

  void test()
  {
  }
};

#endif