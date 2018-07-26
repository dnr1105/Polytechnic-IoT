void sum(int a, int b);

void setup() {
  Serial.begin(115200);
}

void loop() {
  sum(1, 10);
  sum(2, 7);
  
}

void sum(int a, int b)
{
  int total;
  total = a + b;
  Serial.println(total);
}

