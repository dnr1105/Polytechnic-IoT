const int buzzer = D0; // 부저의 ⊕극

void setup() {
  pinMode(buzzer, OUTPUT);
}

void lood() {
  tone(buzzer, 262, 500);
  delay(500);
  tone(buzzer, 294, 500);
  delay(500);
  tone(buzzer, 330, 500);
  delay(500);
  tone(buzzer, 349, 500);
  delay(500);
  tone(buzzer, 392, 500);
  delay(500);
  tone(buzzer, 440, 500);
  delay(500);
  tone(buzzer, 494, 500);
  delay(500);
  tone(buzzer, 523, 500);
  delay(500);
}
