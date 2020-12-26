/**
 * @file control.cpp
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Definition of control class
 * @version 0.1
 * @date 2020-12-21
 * @copyright Copyright (c) 2020
 * 
 */

#include "control.h"

Control::Control()
{
  m_p_settings = NULL;
  m_autoThrustCursor = 0;
}

void Control::init(Joystick leftJoy_p, Joystick rioghtJoy_p, Encoder encoder_p, Switch gearSwitch_p, Buzzer buzzer_p, RGBLed rgbLed_p, const Settings *p_settings_p)
{
  m_leftJoy = leftJoy_p;
  m_rightJoy = rioghtJoy_p;
  m_encoder = encoder_p;
  m_rgbLed = rgbLed_p;
  m_buzzer = buzzer_p;
  m_p_settings = p_settings_p;
}

Control::~Control()
{
}

void Control::setMode(bool newMode_p)
{
  m_mode = newMode_p;
  if (newMode_p == GROUND_MODE)
    m_rgbLed.displayColor(GROUND_MODE_COLOR);
  else
    m_rgbLed.displayColor(FLIGHT_MODE_COLOR);
}

uint8_t Control::getPower()
{
  uint8_t reading = m_leftJoy.readY();
  if (m_mode == GROUND_MODE)
  {
    return ((reading > CONTROL_IDLE) ? mathFunctions::map<uint8_t, uint8_t, uint8_t>(reading, 0, UINT8_MAX, CONTROL_IDLE, m_reduceGroundSpeed ? m_maxGroundPower : UINT8_MAX) : 0);
  }
  else
  {
    return (m_autoThrustCursor + mathFunctions::map<uint8_t, uint8_t, uint8_t>(reading, CONTROL_IDLE, UINT8_MAX, m_autoThrustCursor, UINT8_MAX)); //TODO : test whether this complies with negative values
  }
}

uint8_t Control::getPitch()
{
  if (m_mode == GROUND_MODE)
    return CONTROL_IDLE;
}

uint8_t Control::getYaw()
{
  if (m_mode == GROUND_MODE)
    return m_rightJoy.readX();
  else
    return m_leftJoy.readX();
}

uint8_t Control::getRoll()
{
  if (m_mode == FLIGHT_MODE)
    return m_rightJoy.readX();
  else
    return CONTROL_IDLE;
}

void Control::updateSettings()
{
  m_reduceGroundSpeed = m_p_settings->getSetting<bool>(REDUCE_GROUND_SPEED);
  m_maxGroundPower = m_p_settings->getSetting<uint8_t>(MAX_GROUND_POWER);
}