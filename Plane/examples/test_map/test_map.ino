#include <Serial.h>

void setup()
{
  Serial.begin(9600);
  int i = 49;
  Serial.println(map(i,0,50,50,0));
}

void loop()
{
}