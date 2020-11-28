/**
 * @file lcdscreen.cpp
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Definition of LCDScreen class
 * @version 0.1
 * @date 2020-11-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "lcdscreen.h"

LCDScreen::LCDScreen()
{
  Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
}

LCDScreen::~LCDScreen()
{
}

void LCDScreen::init(uint8_t displayI2cAddress_p)
{
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!begin(SSD1306_SWITCHCAPVCC, displayI2cAddress_p))
  { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ; // Don't proceed, loop forever
  }
}

void LCDScreen::test()
{
  clearDisplay();
  setTextSize(1);              // Normal 1:1 pixel scale
  setTextColor(SSD1306_WHITE); // Draw white text
  setCursor(0, 0);             // Start at top-left corner
  println(F("SIG 96% - REM.BAT 96%"));
  println(F("BATT. TEMP : 45°C"));
  println(F("THR : |======-|-----|"));
  println(F("<--- | ===>  | +100"));
  display();
}