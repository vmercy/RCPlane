/* Pinout Declarations */
#define LEFT_SERVO_PIN 5 //Data pin of servomotor controlling left wing aileron
#define RIGHT_SERVO_PIN 6
#define ELEV_SERVO_PIN 9
#define RUDDER_SERVO_PIN 10

#define ESC_PIN 3 //Brushless motor ESC

#define DT11_DATA_PIN 2 //Temperature and humidity sensor

#define NRF24L01_CE 7
#define NRF24L01_CS 8

#define LIPO_MIDPOINT A0
#define LIPO_VCC A1

/* Servo Limit Angles */
#define LEFT_UP 25
#define LEFT_DOWN 175
#define RIGHT_UP 0
#define RIGHT_DOWN 150
#define ELEV_UP 50
#define ELEV_DOWN 180
#define RUDDER_LEFT 40
#define RUDDER_RIGHT 140

/* Lipo Voltage Divider Resistor Values */
#define R2 1000 //ohms
#define R3 1000 //ohms

#define VOLTAGE_RECTIFIER_COEFF 0.9288

/* Others */
#define ENABLE_STARTUP 1
#define STARTUP_AILERONS_SPEED 90 //in percent
#define MOTOR_TEST_DURATION 10000 //in milliseconds
#define CONNECTION_TIMEOUT 60     //in seconds