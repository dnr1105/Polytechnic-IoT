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
  Serial.println("Start");
}

void loop() {
  char getChar;
  if (Serial.available())
  {
    getChar = Serial.read();
    Serial.print("Readed data = ");
    Serial.println(getChar);

    if ( getChar == '1' ) {
      for (i = 1; i <= 10; i++) {
        digitalWrite(PIN_LED_BLUE, HIGH);
        delay(100);
        digitalWrite(PIN_LED_BLUE, LOW);
        delay(100);
      }
    } else if ( getChar == '2' ) {
      for (i = 1; i <= 10; i++) {
        digitalWrite(PIN_LED_GREEN, HIGH);
        delay(100);
        digitalWrite(PIN_LED_GREEN, LOW);
        delay(100);
      }
    } else if ( getChar == '3' ) {
      for (i = 1; i <= 10; i++) {
        digitalWrite(PIN_LED_RED, HIGH);
        delay(100);
        digitalWrite(PIN_LED_RED, LOW);
        delay(100);
      }
      count = 0;
    }
  }
}
