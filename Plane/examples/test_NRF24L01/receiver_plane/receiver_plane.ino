#include <SPI.h>
#include "RF24.h"

const byte CE = 7;
const byte CS = 8;

RF24 radio(CE, CS);

const byte channel = 120;
const uint8_t pipe[] = {0x01, 0x02};

boolean state = 0;

typedef struct
{
  uint8_t first;
  uint8_t second;
  uint8_t third;
  uint8_t fourth;
} mess;

void setup()
{
  radio.begin();
  Serial.begin(9600);
  radio.setChannel(channel);
  radio.openReadingPipe(1, pipe[1]);
  radio.setPALevel(RF24_PA_MIN);
}

void loop()
{
  delay(100);
  mess myMess;
  radio.startListening();
  if (radio.available())
  {
    radio.read(&myMess, sizeof(mess));
    Serial.print("Message recu : ");
    Serial.print(myMess.first);
    Serial.print(", ");
    Serial.print(myMess.second);
    Serial.print(", ");
    Serial.print(myMess.third);
    Serial.print(", ");
    Serial.println(myMess.fourth);
    Serial.println(radio.testRPD());
  }
  else
  {
    Serial.println("Pas de message");
    //delay(1000);
  }
}
