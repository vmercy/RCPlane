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
  m_p_leftJoy = NULL;
  m_p_rightJoy = NULL;
  m_p_encoder = NULL;
  m_p_buzzer = NULL;
  m_p_rgbLed = NULL;
  m_p_CTRL1 = NULL;
  m_p_CTRL2 = NULL;
  m_p_CTRL3 = NULL;
  m_p_CTRL4 = NULL;
  m_p_settings = NULL;
  m_mode = GROUND_MODE;
  m_autoThrustCursor = 0;
  m_enableYaw = true;
}

void Control::init(Joystick *p_leftJoy_p, Joystick *p_rightJoy_p, Encoder *p_encoder_p, Buzzer *p_buzzer_p, RGBLed *p_rgbLed_p, Switch *p_CTRL1_p, Switch *p_CTRL2_p, Button *p_CTRL3_p, Button *p_CTRL4_p, const Settings *p_settings_p)
{
  m_p_leftJoy = p_leftJoy_p;
  m_p_rightJoy = p_rightJoy_p;
  m_p_encoder = p_encoder_p;
  m_p_rgbLed = p_rgbLed_p;
  m_p_buzzer = p_buzzer_p;
  m_p_CTRL1 = p_CTRL1_p;
  m_p_CTRL2 = p_CTRL2_p;
  m_p_CTRL3 = p_CTRL3_p;
  m_p_CTRL4 = p_CTRL4_p;
  m_p_settings = p_settings_p;
}

Control::~Control()
{
}

void Control::setMode(bool newMode_p)
{
  m_mode = newMode_p;
  if (newMode_p == GROUND_MODE)
    m_p_rgbLed->displayColor(GROUND_MODE_COLOR);
  else
    m_p_rgbLed->displayColor(FLIGHT_MODE_COLOR);
}

void Control::updatePower()
{
  uint8_t reading = m_p_leftJoy->readY();
  if (m_mode == GROUND_MODE)
  {
    m_power = ((reading > CONTROL_IDLE) ? mathFunctions::map<uint8_t, uint8_t, uint8_t>(reading, 0, UINT8_MAX, CONTROL_IDLE, m_reduceGroundSpeed ? m_maxGroundPower : UINT8_MAX) : 0);
  }
  else
  {
    m_power = (m_autoThrustCursor + mathFunctions::map<uint8_t, uint8_t, uint8_t>(reading, CONTROL_IDLE, UINT8_MAX, m_autoThrustCursor, UINT8_MAX)); //TODO : test whether this complies with negative values
  }
}

void Control::updatePitch()
{
  if (m_mode == GROUND_MODE)
    m_pitch = CONTROL_IDLE;
  else
    m_pitch = m_p_rightJoy->readY();
}

void Control::updateYaw()
{
  if (m_enableYaw)
  {
    if (m_mode == GROUND_MODE)
      m_yaw = m_p_rightJoy->readX();
    else
      m_yaw = m_p_leftJoy->readX();
  }
  else
    m_yaw = CONTROL_IDLE;
}

void Control::updateRoll()
{
  if (m_mode == FLIGHT_MODE)
    m_roll = m_p_rightJoy->readX();
  else
    m_roll = CONTROL_IDLE;
}

void Control::updateControls()
{
  m_p_encoder->refresh();
  m_autoThrustCursor = m_p_encoder->getCount(); //TODO: update to take steps into account
  //TODO: display alerts on main screen
  //TODO: display current values on main screen
  if (m_p_CTRL1->state() != m_mode)
  {
    m_mode = m_p_CTRL1->state();
    if (m_mode)
      m_p_buzzer->success();
    else
      m_p_buzzer->warning();
  }
  if (m_p_CTRL2->state() != m_autoThrustEnable)
  {
    m_autoThrustEnable = m_p_CTRL2->state();
    if (m_autoThrustEnable)
      m_p_buzzer->success();
    else
      m_p_buzzer->warning();
  }
  if (m_p_CTRL3->isPressed())
  {
    m_autoThrustCursor = CONTROL_IDLE;
    m_p_buzzer->warning();
    while (m_p_CTRL3->isPressed())
      ;
  }
  if (m_p_CTRL4->isPressed())
  {
    m_enableYaw = !m_enableYaw;
    if (m_enableYaw)
      m_p_buzzer->success();
    else
      m_p_buzzer->warning();
    while (m_p_CTRL4->isPressed())
      ;
  }
  updatePitch();
  updatePower();
  updateRoll();
  updateYaw();
}

void Control::updateSettings()
{
  m_reduceGroundSpeed = m_p_settings->getSetting<bool>(REDUCE_GROUND_SPEED);
  m_maxGroundPower = m_p_settings->getSetting<uint8_t>(MAX_GROUND_POWER);
}

uint8_t Control::getPitch()
{
  return m_pitch;
}

uint8_t Control::getPower()
{
  return m_power;
}

uint8_t Control::getRoll()
{
  return m_roll;
}

uint8_t Control::getYaw()
{
  return m_yaw;
}

void Control::print()
{
  //TODO: update to show all controls including buttons, switch and auto-thrust
  Serial.println("******** CONTROL VALES : ********");
  Serial.print("PITCH : ");
  Serial.println(m_pitch);
  Serial.print("ROLL : ");
  Serial.println(m_roll);
  Serial.print("YAW : ");
  Serial.println(m_yaw);
  Serial.print("POWER : ");
  Serial.println(m_power);
  Serial.print("AUTO-THRUST CURSOR : ");
  Serial.println(m_autoThrustCursor);
}