const int btn1 = D1;
const int btn2 = D2;

void setup() {
  Serial.begin(115200);

  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
}

void loop() {
  Serial.print("Button1 : ");
  Serial.println(digitalRead(btn1));
  Serial.print("Button2 : ");
  Serial.println(digitalRead(btn2));
  Serial.println("--------------------------------");
  delay(500);
}

