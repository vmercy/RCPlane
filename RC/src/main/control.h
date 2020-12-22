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
#include "settings.h"

#define GROUND_MODE 0
#define FLIGHT_MODE 1

#define CONTROL_IDLE 128

/**
 * @brief Control class is responsible for translating Joystick, encoder and button inputs into power, pitch, yaw and roll values
 */
class Control
{
private:
    /**
     * @brief control mode (FLIGHT_MODE or GROUND_MODE)
     */
    bool m_mode;
    Joystick m_leftJoy;
    Joystick m_rightJoy;
    Encoder m_encoder;
    Buzzer m_buzzer;
    RGBLed m_rgbLed;
    const Settings* m_p_settings;
public:
    Control();
    /**
     * @brief Initializes control with given joysticks
     * @param leftJoy_p left joystick object
     * @param rightJoy_p right joystick object
     * @param encoder_p encoder objet
     * @param gearSwitch_p switch object controlling the gear
     * @param buzzer_p buzzer object
     * @param rgbLed_p RGBLed object
     * @param p_settings_p pointer to the settings
     * @note all objects must be initialized before
     */
    void init(Joystick leftJoy_p, Joystick rioghtJoy_p, Encoder encoder_p, Switch gearSwitch_p, Buzzer buzzer_p, RGBLed rgbLed_p, const Settings* p_settings_p);
    ~Control();
    /**
     * @brief Set the Mode
     * @param newMode_p new desired mode (GROUND_MODE or FLIGHT_MODE)
     */
    void setMode(bool newMode_p);
    uint8_t getPower();
    uint8_t getPitch();
    uint8_t getYaw();
    uint8_t getRoll();
};

Control::Control()
{
}

Control::~Control()
{
}


#endif