void Text();

void setup() {
  Serial.begin(115200);
}

void loop() {
  Text();
  Text();
  Text();
  Serial.end();
}

void Text()
{
  Serial.println("Hello WeMos");
}

