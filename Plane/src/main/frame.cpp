/**
 * @file frame.cpp
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Definition of incomingFrame class
 * @version 0.1
 * @date 2020-11-24
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "frame.h"

incomingFrame::incomingFrame()
{
}

incomingFrame::incomingFrame(const TtoPDataFrame newFrame_p)
{
  m_frame = newFrame_p;
}

incomingFrame::~incomingFrame(){}

bool incomingFrame::isAuthentificationFrame()
{
  return m_frame.pitch == AUTH_PITCH && m_frame.roll == AUTH_ROLL && m_frame.power == AUTH_POWER;
}