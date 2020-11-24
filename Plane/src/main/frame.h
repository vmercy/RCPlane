/**
 * @file frame.h
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Declaration of frame types and incomingFrame class
 * @version 0.1
 * @date 2020-11-24
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef FRAME_H
#define FRAME_H

#include <stdint.h>

#define AUTH_PITCH 1
#define AUTH_ROLL 2
#define AUTH_POWER 3

/**
 * @brief Struct composed with all data contained in a frame sent from the Transmitter to the Plane
 */
typedef struct{
  uint8_t roll;
  uint8_t pitch;
  uint8_t power;
}TtoPDataFrame;

/**
 * @brief Struct composed with all data contained in a frame sent from the Plane to the Transmitter
 */
typedef struct
{
  float cell0Voltage;
  float cell1Voltage;
  float temp;
  float hum;

}PtoTDataFrame;

class incomingFrame
{
private:
  TtoPDataFrame m_frame;
public:
  incomingFrame();
  incomingFrame(const TtoPDataFrame newFrame_p);
  ~incomingFrame();
  bool isAuthentificationFrame();
};

#endif