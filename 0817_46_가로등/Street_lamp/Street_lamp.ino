const int pin = A0; // INPUT PIN
const int motion = D1; // 적외선 센서 핀번호 선언
const int light = D2; // 13번 고정 LED 핀번호 선언
const int light2 = D3; // 13번 고정 LED 핀번호 선언

void setup() {
  Serial.begin(115200);
  pinMode(pin, INPUT);
  pinMode(motion, INPUT); // 적외선센서의 핀을 INPUT모드로 선언
  pinMode(light, OUTPUT); // LED센서의 핀을 OUTPUT모드로 선언
  pinMode(light2, OUTPUT); // LED센서의 핀을 OUTPUT모드로 선언

  digitalWrite(light, LOW);
  digitalWrite(light2, LOW);
}

int adcvalue = 0;
int sensor = 0;
void loop() {
  adcvalue = analogRead(pin);

  if ( adcvalue < 1000 )
  {
    digitalWrite(light, HIGH);
  }
  else
  {
    digitalWrite(light, LOW);
  }
  delay(500);

  // 적외선 인체감지 센서에서 값을 읽는다
  sensor = digitalRead(motion);
  // 센서값을 시리얼 모니터에 출력
  Serial.print("motion == ");
  Serial.println(sensor);

  // 센서값이 HIGH(1)일 경우 LED를 한번 깜빡인다
  if (sensor == HIGH) {
    digitalWrite(light, HIGH);
    delay(500);
    digitalWrite(light, LOW);
    delay(500);
  }
}
