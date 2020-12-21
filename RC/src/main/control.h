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

#define GROUND_MODE 0
#define FLIGHT_MODE 1

#define CONTROL_IDLE 128

/**
 * @brief Control class is responsible for translating Joystick inputs into power, pitch, yaw and roll values
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
public:
    Control();
    /**
     * @brief Construct a new Control object with given joysticks
     * @param leftJoy_p left joystick object
     * @param rioghtJoy_p right joystick object
     * @note both joysticks must be initialized
     */
    Control(Joystick leftJoy_p, Joystick rioghtJoy_p);
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