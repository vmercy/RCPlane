#include "/home/valentin/Arduino/libraries/Servo/src/Servo.h"

#ifndef AILERON_HPP
#define AILERON_HPP

#ifndef SERVO_H
#define SERVO_H
#include "/home/valentin/Arduino/libraries/Servo/src/Servo.h"
#endif

/**
 * @class aileron
 * @brief Representation of the ailerons
 */
class aileron
{
private:
  byte m_dataPin;
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
  aileron()
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
  aileron(int min_p, int max_p, int pin_p)
  {
    m_servo = Servo();
    m_servo.attach(pin_p);
    m_minAngle = min_p;
    m_maxAngle = max_p;
  }
  ~aileron();
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
   * @param percent  
   */
  bool move(byte percent_p)
  {
    int targetAngle = 0;
    if (m_senseOfRotation)
      targetAngle = map(percent_p, 0, 100, targetAngle ? m_minAngle : m_maxAngle, targetAngle ? m_maxAngle : m_minAngle);
    m_servo.write(targetAngle);
    return (targetAngle == m_servo.read());
  }

  /**
   * @brief moves aileron upward
   * @return true if maximum angle is reached
   */
  bool moveUp()
  {
    move(100);
  }

  /**
   * @brief moves aileron downward
   * @return true if maximum angle is reached
   */
  bool moveDown()
  {
    move(0);
  }
};

#endif