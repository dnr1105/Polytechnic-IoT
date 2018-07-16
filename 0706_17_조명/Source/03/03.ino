const int D5buttonPin = 14;
const int D0ledPin = 16;

int buttonState = 0;

void setup() {
  pinMode(D0ledPin, OUTPUT);
  pinMode(D5buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(D5buttonPin);

  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(D0ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(D0ledPin, LOW);
  }
}

