const int button = D3;  //button pin
const int led = D5; //LED pin
int buttonState = 0;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}
void loop() {
  buttonState = digitalRead(button);
  if(buttonState == LOW){
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }
}
