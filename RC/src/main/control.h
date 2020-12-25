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

#define GROUND_MODE 0
#define FLIGHT_MODE 1

#define CONTROL_IDLE 128

/**
 * @class Control
 * @brief Control class is responsible for translating Joystick, encoder and button inputs into power, pitch, yaw and roll values
 * @note Description of controls :
 *  - CTRL1 : mode selector : Ground (off) / Flight (on))
 *  - CTRL2 : auto-thrust activation : Disable (off) / Enable (on)
 *  - CTRL3 : set auto-thrust to neutral (halfway)
 *  - CTRL4 : yaw activation : Disable (off) / Enable (on)
 *  - Encoder :
 *    - CW : auto-thrust cursor += getSetting(AUTOTHRUST_CURSOR_STEP)
 *    - CCW : auto-thrust cursor -= getSetting(AUTOTHRUST_CURSOR_STEP)
 *    - Switch (button) : reset auto-thrust to 0 (this is equivalent to temporarily disable auto-thrust)
 * @note Description of control modes :
 *  - Ground mode : 
 *    - Left joystick :
 *      - X axis : nothing
 *      - Y axis : power (eventually reduced to map(power,0,255,0,getSetting(MAX_GROUND_POWER)) if getSetting(REDUCE_GROUND_SPEED) == true)
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
 *  - When m_autoThrustCursor = 255 (max) : power = max
 */
class Control
{
private:
    /**
     * @brief control mode (FLIGHT_MODE or GROUND_MODE)
     */
    bool m_mode;
    /**
     * @brief the auto-thrust cursor value
     */
    uint8_t m_autoThrustCursor;

    Joystick m_leftJoy;
    Joystick m_rightJoy;
    Encoder m_encoder;
    Buzzer m_buzzer;
    RGBLed m_rgbLed;
    /**
     * @brief mode selector
     */
    Switch m_CTRL1;
    /**
     * @brief auto-thrust 
     */
    Switch m_CTRL2;
    Button m_CTRL3;
    Button m_CTRL4;
    //TODO: LCDScreen m_screen;
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

#endif