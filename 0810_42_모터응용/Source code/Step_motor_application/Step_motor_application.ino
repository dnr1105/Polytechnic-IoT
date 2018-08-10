#include <Stepper.h>
#include <DHT.h> //DHT 라이브러리 사용

#define DHTPIN 20 //Digital Sensor 핀번호 정의
#define DHTTYPE DHT11 // DHT 11

// 2048 : 360도 / 1024 : 180도 / 512 : 90도 / 256 : 45도
const int stepsPerRevolution = 512;

// 스텝수와 4개의 제어선 디지털핀 설정,
// 제어선 순서 : orange-pink-yellow-blue 순 (IN4, IN2, IN3, IN1)
int IN1 = 13; //blue
int IN2 = 12; //pink
int IN3 = 14; //yellow
int IN4 = 16; //orange

Stepper stepper(stepsPerRevolution, IN4, IN2, IN3, IN1); // 스텝모터 객체 생성
DHT dht(DHTPIN, DHTTYPE); //DHT sensor 객체 생성

int prev;
int curr;

void setup() {
  stepper.setSpeed(60); //스템모터 속도 RPM (분당 회전수)
  Serial.begin(115200);
  dht.begin(); //DHT 센서 시작, 초기화

  prev = 0;
  curr = 0;
}

void loop() {
  delay(2000); //온도 읽기 전 시간 대기

  float temp = dht.readTemperature(); //온도 읽기

  //  if (Serial.available()) {
  int val = (int)temp; //회전각 int형으로 읽기

  if ( prev != val )
  {
    int out = map( (val - prev), 0, 90, 0, 512 );
    prev = val;
    stepper.step(out);
    Serial.println(out);
    delay(10);
  }
//}
}
