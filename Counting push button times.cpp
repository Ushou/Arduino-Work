const int buttonPin = D5; //button pin
int previousButtonState = HIGH; //checking the state of a pushButton
int counter = 0;  // button push counter

void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(buttonPin); //read button stare
  if ((buttonState != previousButtonState)
      && (buttonState == HIGH)) {
    counter++;
    Serial.print("You pressed the button ");
    Serial.print(counter);
    Serial.println(" times.");
  }
  previousButtonState = buttonState;
}
