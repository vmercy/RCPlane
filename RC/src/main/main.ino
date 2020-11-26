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
#define SEVSEG_DEG1 12
#define SEVSEG_DEG2 15
#define SEVSEG_DEG3 16
#define SEVSEG_DEG4 6

#define MENU_BTN 36
#define CTRL1_SWITCH 30
#define CTRL2_SWITCH 31
#define CTRL3_BTN 29
#define CTRL4_BTN 27

#define RGB_RED 49
#define RGB_GREEN 48
#define RGB_BLUE 47

#define BUZZER 45

#define ESC_ARM_LED 41

#define ENCODER_A 33
#define ENCODER_B 32

#define LEFT_JOY_X A4
#define LEFT_JOY_Y A5
#define LEFT_JOY_SW 34

#define RIGHT_JOY_X A2
#define RIGHT_JOY_Y A3
#define RIGHT_JOY_SW 18

#define CELL0_LED 5
#define CELL1_LED 4
#define CELL2_LED 3
#define CELLALL_LED 2 

#define NRF24L01_CE 7
#define NRF24L01_CS 8

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
Radio transmitter;
Joystick leftJoy;
Joystick rightJoy;
Encoder enc;
Buzzer buzz;
Lcdscreen mainScreen;

void setup()
{
}

void loop()
{

}