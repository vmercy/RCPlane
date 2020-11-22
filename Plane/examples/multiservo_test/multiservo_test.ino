#include <Servo.h>

#define LEFTM 0
#define RIGHTM 1
#define ELEVM 2
#define DOWN 0
#define UP 1

const byte left = 5, right = 6, elev = 9, esc = 3;
const int del = 10;
Servo LEF;
Servo RIG;
Servo ELE;

Servo ESC;

const byte limits[3][2] = {{25, 175}, {0, 150}, {40, 180}};

void setup()
{
  Serial.begin(9600);
  LEF.attach(left);
  RIG.attach(right);
  ELE.attach(elev);
  ESC.attach(esc, 1000, 2000);
}

void loop()
{
  ESC.write(0);
  int i;
  for (i = limits[LEFT_AILERON_PIN][DOWN]; i < limits[LEFT_AILERON_PIN][UP]; i++)
  {
    LEF.write(i);
    delay(del);
  }
  delay(1000);
  for (i = limits[RIGHT_AILERON_PIN][DOWN]; i < limits[RIGHT_AILERON_PIN][UP]; i++)
  {
    RIG.write(i);
    delay(del);
  }
  delay(1000);
  for (i = limits[ELEV_AILERON_PIN][DOWN]; i < limits[ELEV_AILERON_PIN][UP]; i++)
  {
    ELE.write(i);
    delay(del);
  }
  delay(1000);

  ESC.write(2);
  for (i = 0; i < 10; i++)
  {
    ESC.write(i * i);
    delay(500);
  }
  ESC.write(180);
  delay(1000);

  Serial.println("Pret...");
  int vit = 0;
  while (vit >= 0)
  {
    if (Serial.available() > 0)
    {
      vit = Serial.parseInt();
      if (vit > 0)
      {
        Serial.print("Nouvelle vitesse : ");
        Serial.println(vit, DEC);
        ESC.write(vit);
      }
      1
    }
  }

  Serial.println("STOP");
  ESC.write(0);
}
