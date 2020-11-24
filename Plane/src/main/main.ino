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

#include "aileron.h"
#include "motor.h"
#include "battery.h"

/* Pinout Declarations */
#define LEFT_SERVO_PIN 5 //Data pin of servomotor controlling left wing aileron
#define RIGHT_SERVO_PIN 6
#define ELEV_SERVO_PIN 9

#define ESC_PIN 3 //Brushless motor ESC

#define DT11_DATA_PIN 2 //Temperature and humidity sensor

#define NRF24L01_CE 7
#define NRF24L01_CSN 8

#define LIPO_MIDPOINT A0
#define LIPO_VCC A1

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

#define VOLTAGE_RECTIFIER_COEFF 0.9288

/* Arrays indexes */
#define LEFT_AILERON 0
#define RIGHT_AILERON 1
#define ELEV_AILERON 2

#define DOWN 0
#define UP 1

/* Others */
#define ENABLE_STARTUP 0
#define STARTUP_AILERONS_SPEED 10 //in percent
#define MOTOR_TEST_DURATION 10000  //in milliseconds

Aileron leftAileron;

Battery lipoPack;
Motor brushless;

Aileron rightAileron;
Aileron elevAileron;

/**
 * @brief startup script, checks all components are working well
 */

void start()
{
  leftAileron.moveSpeed(100, STARTUP_AILERONS_SPEED);
  rightAileron.moveSpeed(100, STARTUP_AILERONS_SPEED);
  elevAileron.moveSpeed(100, STARTUP_AILERONS_SPEED);
}

void setup()
{
  Serial.begin(9600);
  Serial.println("SETUP");

  leftAileron.init(LEFT_SERVO_PIN, LEFT_DOWN, LEFT_UP);
  rightAileron.init(RIGHT_SERVO_PIN, RIGHT_DOWN, RIGHT_UP);
  rightAileron.reverse();
  elevAileron.init(ELEV_SERVO_PIN, ELEV_DOWN, ELEV_UP);
  brushless.init(ESC_PIN);

  lipoPack.init(LIPO_2S, VOLTAGE_RECTIFIER_COEFF);
  
  const int lipoResistors[2][2] = {{0, 0}, {R2, R3}};
  lipoPack.setResistorValues(lipoResistors);
  const uint8_t lipoPinout[2] = {A0, A1};
  lipoPack.setPinout(lipoPinout);

  delay(1000);
  if (ENABLE_STARTUP)
    start();
  //brushless.arm();
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}

void loop()
{
  lipoPack.refresh();
  for(uint8_t i = 0; i<2;i++)
  {
    Serial.print("Tension cellule ");
    Serial.print(i);
    Serial.print(" : ");
    Serial.print(lipoPack.getCellVoltage(i),2);
    Serial.println("V");
  }
  Serial.print("Tension totale : ");
  Serial.print(lipoPack.getGlobalVoltage(),2);
  Serial.println("V");
  for(uint8_t i = 0; i<2;i++)
  {
    Serial.print("Niveau cellule ");
    Serial.print(i);
    Serial.print(" : ");
    Serial.print(lipoPack.getCellLevel(i),2);
    Serial.println("%");
  }
  Serial.print("Niveau total : ");
  Serial.print(lipoPack.getGlobalLevel(),2);
  Serial.println("%");
  Serial.println("********");
  delay(1000);
  Serial.println("********");
  delay(1000);
}
