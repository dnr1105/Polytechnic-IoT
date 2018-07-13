const int button = D2;
const int LED = D1;

int buttonState = 0;

void setup() {
  Serial.begin(115200);

  pinMode(button, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  buttonState = digitalRead(button);

  if (buttonState == HIGH) { // turn LED on:
    digitalWrite(LED, HIGH);
    Serial.print("HIGH");
    Serial.println();
  } else { // turn LED off:
    digitalWrite(LED, LOW);
    Serial.print("LOW");
    Serial.println();
  }

  delay(500);
}

