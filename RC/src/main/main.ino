/**
 * @file main.ino
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief main program of Radio Controller Arduino Mega Pro 2560 Embed board
 * @version 0.1
 * @date 2020-11-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "battery.h"
#include "button.h"
#include "buzzer.h"
#include "encoder.h"
#include "joystick.h"
#include "lcdscreen.h"
#include "led.h"
//#include "radio.h"
#include "rgbled.h"
#include "sevsegscreen.h"
#include "switch.h"

/* Pinout Declarations */

#define LIPO_MIDPOINT A0
#define LIPO_VCC A1

#define SEVSEG_A 13
#define SEVSEG_B 17
#define SEVSEG_C 22
#define SEVSEG_D 10
#define SEVSEG_E 11
#define SEVSEG_F 14
#define SEVSEG_G 19
#define SEVSEG_DP 9
#define SEVSEG_DIG1 12
#define SEVSEG_DIG2 15
#define SEVSEG_DIG3 16
#define SEVSEG_DIG4 6

#define MENU_BTN 36
#define CTRL1_SWITCH 30
#define CTRL2_SWITCH 31
#define CTRL3_BTN 29
#define CTRL4_BTN 27

#define RGB_RED 49
#define RGB_GREEN 48 //TODO: check hardware issue on this pin
#define RGB_BLUE 47

#define BUZZER 45

#define ESC_ARM_LED 41 //TODO: resolder this (reversed pinout)

#define ENCODER_A 33
#define ENCODER_B 32
//#define ENCODER_SWITCH -1 //TODO: review schematic to allow this feature by hardware

#define LEFT_JOY_X A5
#define LEFT_JOY_Y A4
#define LEFT_JOY_SW 34

#define RIGHT_JOY_X A3
#define RIGHT_JOY_Y A2
#define RIGHT_JOY_SW 18

#define CELL0_LED 5
#define CELL1_LED 4
#define CELL2_LED 3
#define CELLALL_LED 2

#define NRF24L01_CE 7
#define NRF24L01_CS 8

/* Lipo Voltage Divider Resistor Values */
#define R2 1000 //ohms
#define R3 1000 //ohms

/* Others */
#define SSD1306_I2C_ADDRESS 0x3C
#define SEVSEG_DEFAULT_BRIGHTNESS 90
#define ENABLE_START 0
#define VOLTAGE_RECTIFIER_COEFF 1.0132

/* Objects Declarations */
Battery rcLipo;
Button menuBtn;
Switch CTRL1;
Switch CTRL2;
Button CTRL3;
Button CTRL4;
Button menu;
Led escLed;
RGBLed gearLed;
//Radio transmitter;
Joystick leftJoy;
Joystick rightJoy;
Encoder enc;
Buzzer buzz;
SevsegScreen planeBatteryDisplay;
//Lcdscreen mainScreen;

//Led cell0;

void start()
{
}

void setup()
{
  Serial.begin(9600);

  leftJoy.init(LEFT_JOY_X, LEFT_JOY_Y, LEFT_JOY_SW);

  menuBtn.init(MENU_BTN);

  gearLed.init(RGB_COMMON_ANODE, RGB_RED, RGB_GREEN, RGB_BLUE);

  escLed.init(ESC_ARM_LED);

  enc.init(ENCODER_A, ENCODER_B);

  buzz.init(BUZZER);

  rcLipo.init(LIPO_2S, VOLTAGE_RECTIFIER_COEFF);

  const uint8_t sevSegDigitsPinout[] = {SEVSEG_DIG1, SEVSEG_DIG2, SEVSEG_DIG3, SEVSEG_DIG4};
  const uint8_t sevSegSegmentsPinout[] = {SEVSEG_A, SEVSEG_B, SEVSEG_C, SEVSEG_D, SEVSEG_E, SEVSEG_F, SEVSEG_G, SEVSEG_DP};

  planeBatteryDisplay.begin(COMMON_CATHODE, 4, sevSegDigitsPinout, sevSegSegmentsPinout, true);

  planeBatteryDisplay.setBrightness(SEVSEG_DEFAULT_BRIGHTNESS);

  const int lipoResistors[][2] = {{0, 0}, {R2, R3}};
  rcLipo.setResistorValues(lipoResistors);
  const uint8_t lipoPinout[] = {A0, A1};
  rcLipo.setPinout(lipoPinout);

  if (ENABLE_START)
    start();
  Serial.println("SETUP");

  //TODO: beep on buzzer until both joystick are released at idle position
}

void loop()
{
  planeBatteryDisplay.test();
}