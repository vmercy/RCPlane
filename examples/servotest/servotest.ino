#include <Servo.h>

Servo servo;

void setup() {
  servo.attach(10);
  for(int i = 0;i<180;i++){
    servo.write(i);
    delay(10);  
  }
  
}

void loop() {
  delay(1000);
  servo.write(0);
  delay(1000);
  servo.write(150);

}
