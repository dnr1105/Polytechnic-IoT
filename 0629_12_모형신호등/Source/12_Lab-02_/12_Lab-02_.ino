const int PIN_LED_GREEN = D1;
const int PIN_LED_YELLOW = D2;
const int PIN_LED_RED = D3;
int i;

// 프로그램 시작시 초기화 작업
void setup()
{
  Serial.begin(115200);     // 시리얼 통신 초기화
  pinMode(PIN_LED_GREEN, OUTPUT);
  pinMode(PIN_LED_YELLOW, OUTPUT);
  pinMode(PIN_LED_RED, OUTPUT);

  i = 0;
}

void loop() {
  i++;
  if ( i == 1 )
  {
    digitalWrite(PIN_LED_GREEN, HIGH);
    digitalWrite(PIN_LED_YELLOW, LOW);
    digitalWrite(PIN_LED_RED, LOW);
    delay(2000);
  }
  else if ( i == 2 )
  {
    digitalWrite(PIN_LED_GREEN, LOW);
    digitalWrite(PIN_LED_YELLOW, HIGH);
    digitalWrite(PIN_LED_RED, LOW);
    delay(2000);
  }
  else if ( i == 3 )
  {
    digitalWrite(PIN_LED_GREEN, LOW);
    digitalWrite(PIN_LED_YELLOW, LOW);
    digitalWrite(PIN_LED_RED, HIGH);
    delay(2000);
    i = 0;
  }
}
