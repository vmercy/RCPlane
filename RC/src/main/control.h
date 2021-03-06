/**
 * @file control.h
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Declaration of control class
 * @version 0.1
 * @date 2020-12-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef CONTROL_H
#define CONTROL_H

#include "joystick.h"
#include "encoder.h"
#include "buzzer.h"
#include "rgbled.h"
#include "switch.h"
#include "lcdscreen.h"
#include "settings.h"
#include "math_functions.h"

#define GROUND_MODE 0
#define FLIGHT_MODE 1

#define GROUND_MODE_COLOR RED
#define FLIGHT_MODE_COLOR GREEN

#define CONTROL_IDLE 128

/**
 * @class Control
 * @brief Control class is responsible for translating Joystick, encoder and button inputs into power, pitch, yaw and roll values
 * @note Description of controls :
 *  - CTRL1 : mode selector : Ground (off) / Flight (on))
 *  - CTRL2 : auto-thrust activation : Disable (off) / Enable (on)
 *  - CTRL3 : set auto-thrust to neutral (halfway)
 *  - CTRL4 : yaw activation : toggle (default : On)
 *  - Encoder :
 *    - CW : auto-thrust cursor += getSetting(AUTOTHRUST_CURSOR_STEP)
 *    - CCW : auto-thrust cursor -= getSetting(AUTOTHRUST_CURSOR_STEP)
 *    - Switch (button) : reset auto-thrust to 0 (this is equivalent to temporarily disable auto-thrust)
 * @note Description of control modes :
 *  - Ground mode : 
 *    - Left joystick :
 *      - X axis : nothing
 *      - Y axis : power (eventually reduced to map(power,0,UINT8_MAX,0,getSetting(MAX_GROUND_POWER)) if getSetting(REDUCE_GROUND_SPEED) == true)
 *    - Right joystick :
 *      - X axis : roll + yaw
 *      - Y axis : pitch
 *  - Flight mode :
 *    - Left joystick :
 *      - X axis : yaw
 *      - Y axis : power
 *    - Right joystick :
 *      - X axis : roll
 *      - Y axis : pitch
 * @note Description of auto-thrust :
 * - General case : power = cursor + map(joystick, min, max, halfway, max) //TODO: check
 * @example
 * - Particular cases :
 *  - When m_autoThrustCursor = 0 : power = map(joystick, min, max, halfway, max)
 *  - When m_autoThrustCursor = 128 (halfway) : power = joystick
 *  - When m_autoThrustCursor = UINT8_MAX (max) : power = max
 */
class Control
{
private:
  uint8_t m_pitch;
  uint8_t m_roll;
  uint8_t m_yaw;
  uint8_t m_power;
  /**
     * @brief control mode (FLIGHT_MODE or GROUND_MODE)
     */
  bool m_mode;
  /**
     * @brief the auto-thrust cursor value
     */
  uint8_t m_autoThrustCursor;
  uint8_t m_maxGroundPower;
  bool m_autoThrustEnable;
  bool m_reduceGroundSpeed;
  bool m_enableYaw;

  Joystick *m_p_leftJoy;
  Joystick *m_p_rightJoy;
  Encoder *m_p_encoder;
  Buzzer *m_p_buzzer;
  RGBLed *m_p_rgbLed;
  /**
     * @brief mode selector
     */
  Switch *m_p_CTRL1;
  /**
     * @brief auto-thrust 
     */
  Switch *m_p_CTRL2;
  Button *m_p_CTRL3;
  Button *m_p_CTRL4;
  //TODO: LCDScreen* m_p_screen;
  const Settings *m_p_settings;
public:
  Control();
  /**
     * @brief Initializes control with given joysticks
     * @param p_leftJoy_p pointer to left joystick object
     * @param p_rightJoy_p pointer to right joystick object
     * @param p_encoder_p pointer to encoder objet
     * @param p_buzzer_p pointer to buzzer object
     * @param p_rgbLed_p pointer to RGBLed object
     * @param p_CTRL1_p pointer to CTRL1 switch object
     * @param p_CTRL2_p pointer to CTRL2 switch object
     * @param p_CTRL3_p pointer to CTRL3 button object
     * @param p_CTRL4_p pointer to CTRL4 button object
     * @param p_settings_p  pointer to the settings
     */
  void Control::init(Joystick *p_leftJoy_p, Joystick *p_rightJoy_p, Encoder *p_encoder_p, Buzzer *p_buzzer_p, RGBLed *p_rgbLed_p, Switch *p_CTRL1_p, Switch *p_CTRL2_p, Button *p_CTRL3_p, Button *p_CTRL4_p, const Settings *p_settings_p);
  ~Control();
  /**
     * @brief Set the Mode
     * @param newMode_p new desired mode (GROUND_MODE or FLIGHT_MODE)
     */
  void setMode(bool newMode_p);
  void updateSettings();
  void updatePower();
  void updatePitch();
  void updateYaw();
  void updateRoll();
  /**
   * @brief Get the Power value
   * 
   * @return uint8_t m_power
   */
  uint8_t getPower();
  /**
   * @brief Get the Pitch value
   * 
   * @return uint8_t m_pitch
   */
  uint8_t getPitch();
  /**
   * @brief Get the Yaw value
   * 
   * @return uint8_t m_yaw
   */
  uint8_t getYaw();
  /**
   * @brief Get the Roll value
   * 
   * @return uint8_t m_roll
   */
  uint8_t getRoll();
  /**
     * @brief reads button and switches inputs and updates control modes
     * @note must be called in a while loop
     */
  void updateControls();
  /**
   * @brief print all controls states
   */
  void print();
};

#endif