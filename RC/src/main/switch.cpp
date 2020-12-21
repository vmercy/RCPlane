 /*
 * @file switch.cpp
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Definition of switch class
 * @version 0.1
 * @date 2020-12-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "switch.h"

bool Switch::state()
{
    return this->isPressed();
}