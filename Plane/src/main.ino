/**
 * @file main.ino
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief main program
 * @version 0.1
 * @date 2020-11-22
 * 
 * @copyright Copyright (c) 2020
 * 
 */

//#include "/home/valentin/Dropbox/AVION_RC/Prog/Plane/src/aileron.hpp"
//#include "/home/valentin/Dropbox/AVION_RC/Prog/Plane/src/motor.hpp"
//#include "/home/valentin/Dropbox/AVION_RC/Prog/Plane/src/battery.hpp"

#include "aileron.hpp"
#include "motor.hpp"
#include "battery.hpp"

/* Pinout Declarations */
#define LEFT_SERVO 5 //Data pin of servomotor controlling left wing aileron
#define RIGHT_SERVO 6
#define ELEV_SERVO 9

#define ESC 3 //Brushless motor ESC

#define DT11_DATA 2 //Temperature and humidity sensor

#define NRF24L01_CE 7
#define NRF24L01_CSN 8

#define LIPO_MIDPOINT A0

#define LIPO_2S 2

/* Servo Limit Angles */
#define LEFT_UP 25
#define LEFT_DOWN 175
#define RIGHT_UP 0
#define RIGHT_DOWN 150
#define ELEV_UP 40
#define ELEV_DOWN 180

/* Lipo Voltage Divider Resistor Values */
#define R2 1000 //ohms
#define R3 1000 //ohms

/* Arrays indexes */
#define LEFT_AILERON 0
#define RIGHT_AILERON 1
#define ELEV_AILERON 2

#define DOWN 0
#define UP 1

/* Others */
#define STARTUP_AILERONS_SPEED 10 //in percent

Battery lipo(2);
Motor brushless(LIPO_2S);

Aileron leftAileron(LEFT_AILERON, LEFT_UP, LEFT_DOWN);
Aileron rightAileron(RIGHT_AILERON, RIGHT_UP, RIGHT_DOWN);
Aileron elevAileron(ELEV_AILERON, ELEV_UP, ELEV_DOWN);

/**
 * @brief startup script, checks all components are working well
 */
void start()
{
leftAileron.moveSpeed(100,STARTUP_AILERONS_SPEED);
  rightAileron.moveSpeed(100,STARTUP_AILERONS_SPEED);
  elevAileron.moveSpeed(100,STARTUP_AILERONS_SPEED);
  brushless.arm();
}

void setup()
{
  Serial.begin(9600);
  /* const int lipoResistors[2][2] = {{0, 0}, {R2, R3}};
  lipo.setResistorValues(lipoResistors); */
  


}

void loop()
{
}