#include <SevSeg.h>

SevSeg aff;
void setup() {
  byte numDigits = 4;
  byte digitPins[] = {7,8,9,10};
  byte segmentPins[] = {13,11,3,5,6,12,2,4};

  aff.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);

}

void loop() {
  for(int i =0;i<1;i++){
    aff.setNumber(i);  
    unsigned long dep = millis();
    while(millis()-dep<200)
    aff.refreshDisplay();      
  }
}
