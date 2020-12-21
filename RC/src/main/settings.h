/**
 * @file settings.h
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Default settings and declaration of settings class
 * @version 0.1
 * @date 2020-12-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef SETTINGS_H
#define SETTINGS_H

/* Number of settings */
#define NB_BOOL_SETTINGS 3
#define NB_BYTE_SETTINGS 0
#define NB_INT_SETTINGS 0

/* Settings */
/* Boolean */
#define REVERT_POWER
#define REVERT_ROLL
#define REVERT_YAW
#define REVERT_PITCH

#define REDUCE_GROUND_SPEED

/* Bytes */

/* Integers */

/* Default settings values */

/**
 * @brief Settings class is responsible for 
 */
class Settings
{
private:
    bool m_boolSettings[NB_BOOL_SETTINGS];
    uint8_t m_byteSettings[NB_BYTE_SETTINGS];
    int m_intSettings[NB_INT_SETTINGS];
public:
    Settings();
    ~Settings();
    /**
     * @brief writes all settings into EEPROM persistent memory
     */
    void writeToMem();
    /**
     * @brief retrieves all settings from EEPROM persistent memory
     */
    void readFromMem();
    /**
     * @brief Set a bool Setting value
     * @param newValue_p new setting value
     */
    void setBoolSetting(bool newValue_p);
    /**
     * @brief Get the Setting object
     * @return U 
     */
    bool getBoolSetting();
};

Settings::Settings()
{
}

Settings::~Settings()
{
}


#endif