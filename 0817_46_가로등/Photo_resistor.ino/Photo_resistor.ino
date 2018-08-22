int pin = A0; // INPUT PIN

// 프로그램 시작 - 초기화 작업
void setup()
{
  Serial.begin(115200); // 시리얼 통신 초기화
  pinMode(pin, INPUT);
}
int adcvalue = 0;
void loop()
{
  adcvalue = analogRead(pin);
  Serial.print("Data =");
  Serial.println(adcvalue, DEC);
  delay(100);
}

