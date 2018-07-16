const int PIN_LED_BLUE = D1;
const int PIN_LED_GREEN = D2;
const int PIN_LED_RED = D3;

int count;
int i;

// 프로그램 시작시 초기화 작업
void setup()
{
  Serial.begin(115200);     // 시리얼 통신 초기화
  pinMode(PIN_LED_BLUE, OUTPUT);
  pinMode(PIN_LED_GREEN, OUTPUT);
  pinMode(PIN_LED_RED, OUTPUT);

  count = 0;
}

void loop() {
  count++;
  if ( count == 1 )
  {
    for (i = 1; i <= 3; i++) {
      digitalWrite(PIN_LED_BLUE, HIGH);
      delay(200);
      digitalWrite(PIN_LED_BLUE, LOW);
      delay(200);
    }
  } else if ( count == 2 ) {
    for (i = 1; i <= 3; i++) {
      digitalWrite(PIN_LED_GREEN, HIGH);
      delay(200);
      digitalWrite(PIN_LED_GREEN, LOW);
      delay(200);
    }
  } else if ( count == 3 ) {
    for (i = 1; i <= 3; i++) {
      digitalWrite(PIN_LED_RED, HIGH);
      delay(200);
      digitalWrite(PIN_LED_RED, LOW);
      delay(200);
    }
    count = 0;
  }
}
