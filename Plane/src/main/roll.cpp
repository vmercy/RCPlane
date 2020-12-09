/**
 * @file roll.cpp
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Definition of Roll class
 * @version 0.1
 * @date 2020-12-09
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "roll.h"

Roll::Roll()
{

}

Roll::~Roll()
{

}

void Roll::init(Aileron leftAileron_p, Aileron rightAileron_p)
{
  m_leftAileron = leftAileron_p;
  m_rightAileron = rightAileron_p;
}

void Roll::setRoll(uint8_t newRoll_p)
{
  m_leftAileron.moveTo(newRoll_p);
  m_rightAileron.moveTo(255-newRoll_p);
}

void Roll::idle()
{
  m_leftAileron.moveIdle();
  m_rightAileron.moveIdle();
}