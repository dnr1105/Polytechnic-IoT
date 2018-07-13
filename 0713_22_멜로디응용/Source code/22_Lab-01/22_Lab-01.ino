const int PIN_LED = D1;

// 프로그램 시작시 초기화 작업
void setup()
{
  Serial.begin(115200);     // 시리얼 통신 초기화
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  digitalWrite(D1, HIGH);
  delay(1000);
  digitalWrite(D1, LOW);
  delay(1000);
}


