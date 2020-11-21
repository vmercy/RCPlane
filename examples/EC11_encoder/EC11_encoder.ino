int SW = 3, B = 8, A = 9; 

boolean State = false, LastState = false;
int count = 0;

void setup() {
  pinMode(SW, INPUT);
  pinMode(B, INPUT);
  pinMode(A, INPUT);
  Serial.begin(9600);
}

void printpos(){
  Serial.print("Position : ");
      Serial.println(count);
}

void loop() {
  if(!digitalRead(SW)){
    count=0;
    printpos();
    while(!digitalRead(SW));
  }
  State = digitalRead(A);
  if(State!=LastState){
    if(digitalRead(B)!=State)
      count++;
     else
      count--;
      printpos();
      LastState = State;
  }

}
