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

//TODO: add const keyword everywhere in the code
//TODO: add doxygen comment above each class declaration

#include "battery.h"
#include "button.h"
#include "buzzer.h"
#include "encoder.h"
#include "joystick.h"
//#include "lcdscreen.h"
#include "led.h"
#include "radio.h"
#include "rgbled.h"
#include "plane_battery_display.h"
#include "switch.h"

#include "settings.h"
#include "control.h"

#include "header.h"

#define ENABLE_START false           //TODO: set to true
#define ENABLE_BUZZER_DEFAULT false //TODO: set to true
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
//Radio transmitter(NRF24L01_CE, NRF24L01_CS);
Joystick leftJoy;
Joystick rightJoy;
Encoder enc;
Buzzer buzz;
BatteryDisplaySet planeBatteryDisplay;
//LCDScreen mainScreen;

Settings config;
Control control;

RF24 radio(7, 8);
const byte channel = 120;
const uint8_t pipe[] = {0x01, 0x02};

void start() //ligth all LEDS and screens
{
  //mainScreen.startup();
  //buzz.success();
  while (!leftJoy.idle() || !rightJoy.idle()) //startup security
    buzz.warning();
  gearLed.test(1);
  escLed.blink(100, 3);
  planeBatteryDisplay.testDisplays();
  armEsc();
}

void armEsc()
{
  while (!((leftJoy.position() == BOTTOM_RIGHT) && (rightJoy.position() == BOTTOM_LEFT)))
    escLed.blink(1);
  buzz.success();
  escLed.turnOn();
}

void setup()
{
  Serial.begin(9600);
  //mainScreen.init(SSD1306_I2C_ADDRESS);
  leftJoy.init(LEFT_JOY_X, LEFT_JOY_Y, LEFT_JOY_SW);
  rightJoy.init(RIGHT_JOY_X, RIGHT_JOY_Y, RIGHT_JOY_SW);
  leftJoy.setIdlePositions(LEFT_JOY_X_IDLE_POSITION, LEFT_JOY_Y_IDLE_POSITION);
  rightJoy.setIdlePositions(RIGHT_JOY_X_IDLE_POSITION, RIGHT_JOY_Y_IDLE_POSITION);
  menuBtn.init(MENU_BTN);
  gearLed.init(RGB_COMMON_ANODE, RGB_RED, RGB_GREEN, RGB_BLUE);
  escLed.init(ESC_ARM_LED);
  escLed.turnOff();
  enc.init(ENCODER_A, ENCODER_B, ENCODER_SW);
  buzz.init(BUZZER, ENABLE_BUZZER_DEFAULT, &gearLed); //TODO: update to set enable_p to getSetting<bool>...
  rcLipo.init(LIPO_2S, VOLTAGE_RECTIFIER_COEFF);

  CTRL1.init(CTRL1_SWITCH);
  CTRL2.init(CTRL2_SWITCH);
  CTRL3.init(CTRL3_BTN);
  CTRL4.init(CTRL4_BTN);

  control.init(&leftJoy, &rightJoy, &enc, &buzz, &gearLed, &CTRL1, &CTRL2, &CTRL3, &CTRL4, &config);

  //TODO: config.readFromMem();

  const uint8_t cellIndicatorsPinout[] = {CELL0_LED, CELL1_LED, CELL2_LED, CELLALL_LED};
  const uint8_t sevSegDigitsPinout[] = {SEVSEG_DIG1, SEVSEG_DIG2, SEVSEG_DIG3, SEVSEG_DIG4};
  const uint8_t sevSegSegmentsPinout[] = {SEVSEG_A, SEVSEG_B, SEVSEG_C, SEVSEG_D, SEVSEG_E, SEVSEG_F, SEVSEG_G, SEVSEG_DP};
  planeBatteryDisplay.init(LIPO_2S, cellIndicatorsPinout, COMMON_CATHODE, SEVSEG_NB_DIGITS, sevSegDigitsPinout, sevSegSegmentsPinout, &config);
  //planeBatteryDisplay.setBrightness(SEVSEG_DEFAULT_BRIGHTNESS);
  const int lipoResistors[][2] = {{0, 0}, {R2, R3}};
  rcLipo.setResistorValues(lipoResistors);
  const uint8_t lipoPinout[] = {A0, A1};
  rcLipo.setPinout(lipoPinout);
  //transmitter.init(NRF24L01_CE, NRF24L01_CS);

  radio.begin();
  radio.setChannel(channel);
  radio.openWritingPipe(pipe[1]);
  //radio.setPALevel(RF24_PA_MIN);

  radio.stopListening();

  /*   
  radio.enableDynamicAck();
  radio.enableDynamicPayloads(); */

  if (ENABLE_START)
    start();

  Serial.println("SETUP FINISHED");
}

TtoPDataFrame signal;

void loop()
{

  //control.updateControls();  TODO: slow down all loop
  //control.updateSettings();

  signal.pitch = control.getPitch();
  signal.roll = control.getRoll();
  signal.yaw = control.getYaw();
  signal.power = control.getPower();


  //radio.write(&signal, sizeof(TtoPDataFrame));

  //control.print(); TODO: slow down all loop

  //delay(50);

  planeBatteryDisplay.BatteryDisplaySet::refreshDisplay();
}