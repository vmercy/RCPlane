int buzz = 3;

void setup() {
  pinMode(buzz, OUTPUT);

}

void loop() {
  tone(buzz, 7000, 1000);
  delay(200);
  noTone(buzz);
  delay(200);

}
