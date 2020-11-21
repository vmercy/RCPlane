#include <SPI.h>
#include "RF24.h"

const byte CE = 7;
const byte CS = 8;

RF24 radio(CE,CS);

const byte channel = 120;
const byte pipe[] = {0x01, 0x02};

boolean state = 1;

void setup() {
  radio.begin();
  radio.openWritingPipe(pipe[1]);
  radio.setPALevel(RF24_PA_MIN);
}

void loop() {
  delay(5);
  state = !state;
  radio.stopListening();
  radio.write(&state,sizeof(state));
  delay(1000);
}
