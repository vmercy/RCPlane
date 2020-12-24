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

void Control::init(Joystick leftJoy_p, Joystick rioghtJoy_p, Encoder encoder_p, Switch gearSwitch_p, Buzzer buzzer_p, RGBLed rgbLed_p, const Settings* p_settings_p)
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
}

uint8_t Control::getPower()
{
    if((m_mode==GROUND_MODE)&&(m_p_settings->getSetting<bool>(REDUCE_GROUND_SPEED)))
    {
        return m_leftJoy.readY();
    }
    else
    {
      
    }
    
}

uint8_t Control::getPitch()
{
  if(m_mode==GROUND_MODE)
    return CONTROL_IDLE;
}

uint8_t Control::getYaw()
{
    if(m_mode==GROUND_MODE)
        return m_rightJoy.readX();
    else
        return m_leftJoy.readX();
}

uint8_t Control::getRoll()
{
    if(m_mode==FLIGHT_MODE)
        return m_rightJoy.readX();
    else
        return CONTROL_IDLE;
    
}
