/**
 * @file main.ino
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief main program of Plane Arduino Nano board
 * @version 0.1
 * @date 2020-11-22
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "aileron.h"
#include "motor.h"
#include "battery.h"
#include "rudder.h"
#include "radio.h"
#include "roll.h"

#include "header.h"

Aileron leftAileron;
Aileron rightAileron;
Roll roll;
Aileron elevAileron;

Battery lipoPack;
Motor brushless;
Rudder rudder;
Radio radio(NRF24L01_CE, NRF24L01_CS);

/**
 * @brief startup script, checks all components are working well
 */
void start()
{
  Serial.println("START");
  leftAileron.moveSpeed(100, STARTUP_AILERONS_SPEED);
  rightAileron.moveSpeed(100, STARTUP_AILERONS_SPEED);
  elevAileron.moveSpeed(100, STARTUP_AILERONS_SPEED);
  rudder.test();
  leftAileron.moveIdle();
  rightAileron.moveIdle();
  elevAileron.moveIdle();
  rudder.moveIdle();
}

void setup()
{
  Serial.begin(9600);
  Serial.println("SETUP");

  leftAileron.init(LEFT_SERVO_PIN, LEFT_DOWN, LEFT_UP);
  rightAileron.init(RIGHT_SERVO_PIN, RIGHT_DOWN, RIGHT_UP);
  rightAileron.reverse();
  roll.init(leftAileron, rightAileron);
  elevAileron.init(ELEV_SERVO_PIN, ELEV_DOWN, ELEV_UP);
  brushless.init(ESC_PIN);

  rudder.init(RUDDER_SERVO_PIN, RUDDER_LEFT, RUDDER_RIGHT);

  lipoPack.init(LIPO_2S, VOLTAGE_RECTIFIER_COEFF);

  radio.init(NRF24L01_CE, NRF24L01_CS);

  const int lipoResistors[][2] = {{0, 0}, {R2, R3}};
  lipoPack.setResistorValues(lipoResistors);
  const uint8_t lipoPinout[] = {A0, A1};
  lipoPack.setPinout(lipoPinout);

  delay(1000);
  if (ENABLE_STARTUP)
    start();

  if (radio.waitForConnection(CONNECTION_TIMEOUT))
    brushless.arm();
  else
    brushless.idle();
}

void loop()
{
  /* Receive incoming frame */
  radio.receiveData();

  /* Update flight parameters */
  brushless.setSpeed(radio.getPower());
  roll.setRoll(radio.getRoll());
  elevAileron.moveTo(radio.getPitch());
  rudder.moveTo(radio.getYaw());

  /* Send outgoing frame */
}
