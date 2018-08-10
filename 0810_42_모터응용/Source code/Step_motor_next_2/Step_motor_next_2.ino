#include <Stepper.h>

// 2048 : 360도 / 1024 : 180도 / 512 : 90도 / 256 : 45도
const int stepsPerRevolution = 512;

int IN1 = 13; //blue
int IN2 = 12; //pink
int IN3 = 14; //yellow
int IN4 = 16; //orange

Stepper stepper(stepsPerRevolution, IN4, IN2, IN3, IN1); // 스텝모터 객체 생성
// 스텝수와 4개의 제어선 디지털핀 설정,
//제어선 순서 : orange-pink-yellow-blue 순 (IN4, IN2, IN3, IN1)

int prev;
int curr;

void setup() {
  stepper.setSpeed(60); //스템모터 속도 RPM (분당 회전수)
  Serial.begin(115200);

  prev = 0;
  curr = 0;
}

void loop() {
  if (Serial.available()) {
    int val = Serial.parseInt(); //회전각 int형으로 읽기

    if ( prev != val )
    {
      int out = map( (val - prev), 0, 90, 0, 512 );
      prev = val;
      stepper.step(out);
      Serial.println(out);
      delay(10);
    }
  }
}
