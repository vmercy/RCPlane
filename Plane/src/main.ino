#include "/home/valentin/Dropbox/AVION_RC/Prog/Plane/src/aileron.hpp"

/* Pinout Declarations */
#define LEFT_SERVO 5 //Data pin of servomotor controlling left wing aileron
#define RIGHT_SERVO 6
#define ELEV_SERVO 9

#define ESC 3 //Brushless motor ESC

/* Servo Limit Angles */
#define LEFT_UP 20
#define LEFT_DOWN 180
#define RIGHT_UP 0
#define RIGHT_DOWN 150 
#define ELEV_UP 40
#define ELEV_DOWN 180


/* Arrays indexes */
#define LEFT_AILERON 0
#define RIGHT_AILERON 1
#define ELEV_AILERON 2

#define DOWN 0
#define UP 1

/*
void setup() {
  Serial.begin(9600);
  LEF.attach(LEFT_SERVO);
  RIG.attach(right);
  ELE.attach(elev);
  ESC.attach(esc,1000,2000);
}

void loop() {
  ESC.write(0);
  int i;
  for(i = limits[LEFT_AILERON][DOWN]; i<limits[LEFT_AILERON][UP];i++)
  {
    LEF.write(i);
    delay(del);
  }
  delay(1000);
  for(i = limits[RIGHT_AILERON][DOWN]; i<limits[RIGHT_AILERON][UP];i++)
  {
    RIG.write(i);
    delay(del);
  }
  delay(1000);
  for(i = limits[ELEV_AILERON][DOWN]; i<limits[ELEV_AILERON][UP];i++)
  {
    ELE.write(i);
    delay(del);
  }
  delay(1000);


 ESC.write(2);
 for(i=0;i<10;i++){
  ESC.write(i*i);
  delay(500);
 }
  ESC.write(180);
 delay(1000); 

Serial.println("Pret...");
int vit = 0;
while(vit>=0){
  if(Serial.available()>0){
    vit = Serial.parseInt();
    if(vit>0){
    Serial.print("Nouvelle vitesse : ");
    Serial.println(vit,DEC);  
    ESC.write(vit);    
    }
        
  }
}

 Serial.println("STOP");
 ESC.write(0);

}
*/