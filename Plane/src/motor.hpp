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
class motor
{
private:
  Servo m_ESC;
public:
  motor(/* args */);
  ~motor();
};

#endif