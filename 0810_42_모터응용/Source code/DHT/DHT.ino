4
//�ø��� ����ͷ� �µ�, ���� Ȯ��
#include <DHT.h> //DHT ���̺귯�� ���
#define DHTPIN 14 //Digital Sensor �ɹ�ȣ ����
#define DHTTYPE DHT11 // DHT 11
DHT dht(DHTPIN, DHTTYPE); //DHT sensor ��ü ����
void setup() {
Serial.begin(115200);
Serial.println("DHT11 test!");
dht.begin(); //DHT ���� ����, �ʱ�ȭ
}
void loop() {
delay(2000); //�µ� �б� �� �ð� ���
float h = dht.readHumidity(); //���� �б�
float t = dht.readTemperature(); //�µ� �б�
Serial.print("Humidity: "); //�ø��� ����Ϳ� ���
Serial.print(h);
Serial.print(" %\t");
Serial.print("Temperature: ");
Serial.print(t);
Serial.println(" *C ");
}