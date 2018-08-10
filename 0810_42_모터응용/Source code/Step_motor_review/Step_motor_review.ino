//90도씩 시계방향, 반시계방향으로 회전
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

void setup() {
  stepper.setSpeed(60); //스템모터 속도 RPM (분당 회전수)
  Serial.begin(115200);
}

void loop() {
  Serial.println("clockwise");
  stepper.step(stepsPerRevolution);
  delay(500);
  
  Serial.println("counterclockwise");
  stepper.step(-stepsPerRevolution);
  delay(500);
}
