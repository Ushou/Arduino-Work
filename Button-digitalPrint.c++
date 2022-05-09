const int keyboard1 = D3; //set botton pin
const int keyboard2 = D5; //set botton pin
void setup() {
  pinMode(keyboard1,INPUT_PULLUP);
  pinMode(keyboard2,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(keyboard1) == LOW){
    Serial.print("z");  //print out"z"
    delay(200);
  }
  else if(digitalRead(keyboard2) == LOW){
    Serial.print("x");  //print out"x"
    delay(200);
  }
}
