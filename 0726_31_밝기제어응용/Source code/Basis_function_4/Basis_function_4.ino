int func4();

void setup() {
  Serial.begin(115200);
}

void loop() {
  int returnValue;
  returnValue = func4();
  Serial.println(returnValue);
}

int func4()
{
  int i = 10;
  return i;
}

