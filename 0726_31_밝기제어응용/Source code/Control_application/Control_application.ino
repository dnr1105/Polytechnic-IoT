// 함수 정의
// int nextLED(int);
void callGreen();
void callYellow();
void callRed();

const int SWITCH = D4;
const int LED_GREEN = D1;
const int LED_YELLOW = D2;
const int LED_RED = D3;

int count;

void setup()
{
  Serial.begin(115200);

  pinMode(SWITCH, INPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);

  count = 0;
}

void loop()
{
  count++;
  switch (count)
  {
    case 1:
      callGreen();
      break;
    case 2:
      callYellow();
      break;
    case 3:
      callRed();
      count = 0;
      break;
  }
  delay(500);
}

void callGreen()
{
  for (int i = 0; i < 10; i++)
  {
    digitalWrite(LED_GREEN, HIGH);
    delay(100);
    digitalWrite(LED_GREEN, LOW);
    delay(100);
  }
}

void callYellow()
{
  for (int i = 0; i < 10; i++)
  {
    digitalWrite(LED_YELLOW, HIGH);
    delay(100);
    digitalWrite(LED_YELLOW, LOW);
    delay(100);
  }
}

void callRed()
{
  for (int i = 0; i < 10; i++)
  {
    digitalWrite(LED_RED, HIGH);
    delay(100);
    digitalWrite(LED_RED, LOW);
    delay(100);
  }
}

