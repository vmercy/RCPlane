#include <SPI.h>
#include "RF24.h"

const byte CE = 7;
const byte CS = 8;

RF24 radio(CE,CS);

const byte channel = 120;
const byte pipe[] = {0x01, 0x02};

boolean state = 1;

typedef struct
{
  uint8_t first;
  uint8_t second;
  uint8_t third;
  uint8_t fourth;
} mess;

void setup() {
  radio.begin();
  radio.setChannel(channel);
  radio.openWritingPipe(pipe[1]);
  radio.setPALevel(RF24_PA_MIN);
}

void loop() {
  delay(5);
  mess myMess;
  myMess.first = 1;
  myMess.second = 2;
  myMess.third = 3;
  myMess.fourth = 4;
  radio.stopListening();
  radio.write(&myMess,sizeof(mess));
  delay(1000);
}
