/**
 * @file switch.h
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Declaration of switch class
 * @version 0.1
 * @date 2020-11-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef SWITCH_H
#define SWITCH_H

#include "button.h"

class Switch : public Button
{
    public:
        /**
         * @brief read switch current state
         * @return true if the switch is on
         */
        bool state();
};


#endif