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

#define ENABLE_START true //TODO: set to true
#define ENABLE_BUZZER_DEFAULT false //let true except for development purposes
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

RF24 radio(7,8);
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
  enc.init(ENCODER_A, ENCODER_B, ENCODER_SW);
  buzz.init(BUZZER, ENABLE_BUZZER_DEFAULT);
  rcLipo.init(LIPO_2S, VOLTAGE_RECTIFIER_COEFF);
  
  CTRL1.init(CTRL1_SWITCH);
  CTRL2.init(CTRL2_SWITCH);
  CTRL3.init(CTRL3_BTN);
  CTRL4.init(CTRL4_BTN);

  //TODO: config.readFromMem();

  //control.init(leftJoy, rightJoy, enc, CTRL1, buzz, gearLed, &config);

  const uint8_t cellIndicatorsPinout[] = {CELL0_LED, CELL1_LED, CELL2_LED, CELLALL_LED};
  const uint8_t sevSegDigitsPinout[] = {SEVSEG_DIG1, SEVSEG_DIG2, SEVSEG_DIG3, SEVSEG_DIG4};
  const uint8_t sevSegSegmentsPinout[] = {SEVSEG_A, SEVSEG_B, SEVSEG_C, SEVSEG_D, SEVSEG_E, SEVSEG_F, SEVSEG_G, SEVSEG_DP};
  planeBatteryDisplay.init(3, cellIndicatorsPinout, COMMON_CATHODE, SEVSEG_NB_DIGITS, sevSegDigitsPinout, sevSegSegmentsPinout, &config);
  //planeBatteryDisplay.setBrightness(SEVSEG_DEFAULT_BRIGHTNESS);
  const int lipoResistors[][2] = {{0, 0}, {R2, R3}};
  rcLipo.setResistorValues(lipoResistors);
  const uint8_t lipoPinout[] = {A0, A1};
  rcLipo.setPinout(lipoPinout);
  //transmitter.init(NRF24L01_CE, NRF24L01_CS);

  radio.begin();
  radio.setChannel(channel);
  radio.openWritingPipe(pipe[1]);
  radio.setPALevel(RF24_PA_MIN);

  /*   
  radio.enableDynamicAck();
  radio.enableDynamicPayloads(); */

  if (ENABLE_START)
    start();

  Serial.println("SETUP FINISHED");
}

void loop()
{
/*   if(CTRL1.state())
  {
    
  } */
  /* transmitter.setRoll(rightJoy.readX());
  transmitter.setPower(leftJoy.readY());
  transmitter.setPitch(rightJoy.readY());
  transmitter.setYaw(leftJoy.readX());

  transmitter.sendData(); */

/*   if(enc.isPressed())
  {
    gearLed.displayColor(WHITE);
    Serial.println("Pressed");
  } */

  TtoPDataFrame frame;
  if(leftJoy.readY()>LEFT_JOY_Y_IDLE_POSITION)
    frame.power = map(leftJoy.readY(),LEFT_JOY_Y_IDLE_POSITION,255,0,255);
  else
    frame.power = 0;

  frame.roll = rightJoy.readX();
  frame.pitch = rightJoy.readY();
  frame.yaw = 255-rightJoy.readX();
  /* leftJoy.print();
  rightJoy.print(); */

  radio.stopListening();
  radio.write(&frame, sizeof(TtoPDataFrame));

  //delay(50);

  planeBatteryDisplay.refreshDisplay();


}