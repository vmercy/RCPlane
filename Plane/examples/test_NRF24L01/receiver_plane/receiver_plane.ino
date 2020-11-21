#include <SPI.h>
#include "RF24.h"

const byte CE = 7;
const byte CS = 8;

RF24 radio(CE,CS);

const byte channel = 120;
const byte pipe[] = {0x01, 0x02};

boolean state = 0;

void setup() {
  radio.begin();
  Serial.begin(9600);
  radio.openReadingPipe(1,pipe[1]);
  radio.setPALevel(RF24_PA_MIN);
}

void loop() {
  delay(100);
  radio.startListening();
  if(radio.available()){
    radio.read(&state,sizeof(state)); 
    Serial.print("Message recu : ");
    if(state){
      Serial.println("HIGH");
    }
    else{
      Serial.println("LOW");
    }
  }  
  else{
    Serial.println("Pas de message");
    //delay(1000);
  }
  
}
