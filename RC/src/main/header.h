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

#define SEVSEG_NB_DIGITS 4
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
#define RGB_GREEN 48
#define RGB_BLUE 47

#define BUZZER 45

#define ESC_ARM_LED 41

#define ENCODER_A 33
#define ENCODER_B 32
#define ENCODER_SW 35 //TODO: review schematic to allow this feature by hardware

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
#define LEFT_JOY_X_IDLE_POSITION 125
#define LEFT_JOY_Y_IDLE_POSITION 129
#define RIGHT_JOY_X_IDLE_POSITION 130
#define RIGHT_JOY_Y_IDLE_POSITION 126

#define SSD1306_I2C_ADDRESS 0x3C
#define SEVSEG_DEFAULT_BRIGHTNESS 90

#define ENABLE_START false //TODO: set to true
#define ENABLE_BUZZER_DEFAULT false //let true except for development purposes
#define VOLTAGE_RECTIFIER_COEFF 1.0132