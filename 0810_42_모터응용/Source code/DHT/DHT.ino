4
//시리얼 모니터로 온도, 습도 확인
#include <DHT.h> //DHT 라이브러리 사용
#define DHTPIN 14 //Digital Sensor 핀번호 정의
#define DHTTYPE DHT11 // DHT 11
DHT dht(DHTPIN, DHTTYPE); //DHT sensor 객체 생성
void setup() {
Serial.begin(115200);
Serial.println("DHT11 test!");
dht.begin(); //DHT 센서 시작, 초기화
}
void loop() {
delay(2000); //온도 읽기 전 시간 대기
float h = dht.readHumidity(); //습도 읽기
float t = dht.readTemperature(); //온도 읽기
Serial.print("Humidity: "); //시리얼 모니터에 출력
Serial.print(h);
Serial.print(" %\t");
Serial.print("Temperature: ");
Serial.print(t);
Serial.println(" *C ");
}