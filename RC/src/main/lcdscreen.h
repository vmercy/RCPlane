/**
 * @file lcdscreen.h
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Declaration of LCDScreen class
 * @version 0.1
 * @date 2020-11-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef LCDSCREEN_H
#define LCDSCREEN_H

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//#include "lcd_bitmaps.h"

#define LOGO_HEIGHT 64
#define LOGO_WIDTH 128

/**
 * @brief LCDScreen class is responsible for displaying informations on an SSD1306 I2C screen
 */
class LCDScreen : private Adafruit_SSD1306
{
private:
  
public:
  LCDScreen();
  ~LCDScreen();
  /**
   * @brief Initialize the I2C screen
   * @param displayI2cAddress_p the I2C address of the screen (can be found with examples/find_i2c_address/find_i2c_address.ino)
   */
  void init(uint8_t displayI2cAddress_p);
  /**
   * @brief prints startup screen
   */
  void startup();
  void test();
};

#endif